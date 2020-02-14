//
// Copyright [2020] [name of copyright owner]
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#include "lifx.h"
#include "lifx_version.h"
#include "lifx_encoders.h"
#include "lifx_internal.h"

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

static uint16_t const kLifxProtocolNumber = 0x400; // 1024
static pthread_once_t error_once = PTHREAD_ONCE_INIT;
static pthread_key_t  error_key;

typedef struct
{
  int  LastError;
  char LastErrorMessage[kLifxErrorMessageMaxLength];
} lifxErrorThreadSpecific_t;

static void lifxErrorInitThreadSpecificKey()
{
  pthread_key_create(&error_key, NULL);
}

lifxErrorThreadSpecific_t*
lifxError_GetThreadSpecific()
{
  lifxErrorThreadSpecific_t* specific;
  pthread_once(&error_once, lifxErrorInitThreadSpecificKey);

  specific = (lifxErrorThreadSpecific_t *) pthread_getspecific(error_key);
  if (!specific)
  {
    specific = (lifxErrorThreadSpecific_t *) malloc(sizeof(lifxErrorThreadSpecific_t));
    specific->LastError = 0;
    specific->LastErrorMessage[0] = '\0';
    pthread_setspecific(error_key, specific);
  }

  return specific;
}

static void lifxDumpBuffer(lifxSession_t* lifx, uint8_t* p, int n)
{
  if (kLifxLogLevelDebug < lifx->LogLevel)
    return;

  int i;
  printf("\t");
  for (i = 0; i < n; ++i)
  {
    if ((i > 0) && (i % 16) == 0)
      printf("\n\t");
    printf("0x%02x ", p[i]);
  }
  printf("\n");
}

static void lifxSockaddr_ToString(struct sockaddr_storage* ss, char* buff, int n, uint16_t* port)
{
  if (ss->ss_family == AF_INET)
  {
    struct sockaddr_in* v4 = (struct sockaddr_in *) ss;
    inet_ntop(ss->ss_family, &v4->sin_addr, buff, n);
    if (port)
      *port = ntohs(v4->sin_port);
  }
}

char const*
lifx_Version()
{
  return "v" LIFX_PROJECT_VER;
}

void*
lifxSession_Dispatcher(void* argp)
{
  int ret;
  struct lifxSession* lifx = (struct lifxSession *) argp;

  while (true)
  {
    ret = lifxSession_Dispatch(lifx, 1);
    lxLog_Info(lifx, "lifxSession_Dispatch:%d", ret);
  }
  return NULL;
}

lifxDevice_t lifxSession_FindDevice(lifxSession_t* lifx, lifxProtocolHeader_t const* header)
{
  int i;
  for (i = 0; i < kLifxMaxDevices; ++i)
  {
    if (lifx->DeviceDatabase[i])
    {
      if (memcmp(header->Target, lifx->DeviceDatabase[i]->HardwareAddress, 6) == 0)
        return (lifxDevice_t) i;
    }
  }

  return kLifxDeviceInvalid;
}

lifxDevice_t lifxSession_CreateDevice(
  lifxSession_t*                  lifx,
  lifxMessage_t const*            message,
  struct sockaddr_storage* const  source)
{
  int i;
  lifxDevice_t dev = kLifxDeviceInvalid;

  for (i = 0; i < kLifxMaxDevices; ++i)
  {
    if (!lifx->DeviceDatabase[i])
    {
      struct lifxDevice* new_device = malloc(sizeof(struct lifxDevice));
      memcpy(new_device->HardwareAddress, message->Header.Target, 6);
      memcpy(&new_device->Endpoint, source, sizeof(struct sockaddr_storage));
      lifx->DeviceDatabase[i] = new_device;

      // always assumes ipv4
      {
        struct sockaddr_in* v4 = (struct sockaddr_in *) &new_device->Endpoint;
        v4->sin_port = htons(message->Packet.DeviceStateService.Port);
      }

      dev = i;

      {
        uint16_t port;
        char buff[256];
        lifxSockaddr_ToString(source, buff, sizeof(buff), &port);
        lxLog_Info(lifx, "adding new device %s:%d to database", buff, port);
        lxLog_Info(lifx, "mac:%02x%02x%02x%02x%02x%02x",
          lifx->DeviceDatabase[i]->HardwareAddress[0],
          lifx->DeviceDatabase[i]->HardwareAddress[1],
          lifx->DeviceDatabase[i]->HardwareAddress[2],
          lifx->DeviceDatabase[i]->HardwareAddress[3],
          lifx->DeviceDatabase[i]->HardwareAddress[4],
          lifx->DeviceDatabase[i]->HardwareAddress[5]);
      }

      break;
    }
  }
  return dev;
}

lifxSession_t*
lifxSession_Open(lifxSessionConfig_t const* conf)
{
  int                 n;
  int                 ret;
  int                 flag;
  struct lifxSession* lifx;

  lifx = malloc(sizeof(struct lifxSession));
  if (!lifx)
    return NULL;

  memset(lifx, 0, sizeof(struct lifxSession));

  // set this as early as possible to avoid uninitialized reads
  lifx->LogLevel = kLifxLogLevelInfo;
  if (conf)
    lifx->LogLevel = conf->LogLevel;
  lifx->Socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (lifx->Socket == -1)
  {
    free(lifx);
    return NULL;
  }

  n = (int) (sizeof(lifxProtocolHeader_t) + sizeof(lifxPacket_t));
  lxLog_Info(lifx, "allocated %d bytes for read buffer", n);

  lifxBuffer_Init(&lifx->ReadBuffer, n);
  lifx->SourceId = getpid();
  lifx->SequenceNumber = 0;

  flag = 1;
  ret = setsockopt(lifx->Socket, SOL_SOCKET, SO_BROADCAST, &flag, sizeof(flag));
  if (ret == -1)
  {
    free(lifx);
    return NULL;
  }

  if (conf)
  {
    if (conf->BindInterface)
    {
      struct sockaddr_in bind_addr;
      socklen_t bind_addr_length;

      bind_addr_length = sizeof(struct sockaddr_in);
      memset(&bind_addr, 0, sizeof(struct sockaddr_in));
      inet_pton(AF_INET, conf->BindInterface, &bind_addr);

      lxLog_Info(lifx, "binding to %s", conf->BindInterface);

      ret = bind(lifx->Socket, (struct sockaddr *) &bind_addr, bind_addr_length);
      if (ret != 0)
      {
        int err = errno;
        lxLog_Warn(lifx, "bind:%s", lifxError_ToString(err));
      }
    }

    if (conf->UseBackgroundDispatchThread)
    {
      lifx->MessageHandler = conf->MessageHandler;
      pthread_create(&lifx->BackgroundDispatchThread, NULL, lifxSession_Dispatcher, lifx);
    }
  }

  return lifx;
}

char const*
lifxError_ToString(int errnum)
{
  int n;
  char const* buff;
  lifxErrorThreadSpecific_t* specific;
  
  buff = NULL;
  specific = lifxError_GetThreadSpecific();

  if (specific)
  {
    #ifdef __linux__
    n = strerror_r(errnum, specific->LastErrorMessage, kLifxErrorMessageMaxLength - 1);
    if (!n)
      buff = specific->LastErrorMessage;
    #else
    buff = strerror(errnum);
    #endif
    specific->LastError = errnum;
  }

  return buff;
}

int
lifxSession_Close(lifxSession_t* lifx)
{
  if (!lifx)
    return EINVAL;

  if (lifx->Socket != -1)
    close(lifx->Socket);

  lifxBuffer_Destroy(&lifx->ReadBuffer);

  free(lifx);

  return 0;
}

int
lifxSession_Dispatch(
  lifxSession_t*    lifx,
  int               timeout)
{
  int                     ret;
  int                     elapsed;
  struct timeval          time;
  bool                    done;
  lifxMessage_t           message;
  lifxDevice_t            dev;
  struct sockaddr_storage source_addr;

  ret = 0;
  elapsed = 0;
  gettimeofday(&time, NULL);
  done = false;

  while (!done)
  {
    dev = kLifxDeviceInvalid;
    memset(&message, 0, sizeof(lifxMessage_t));

    ret = lifxSession_RecvFromInternal(lifx, &message, &source_addr, 1000);
    if (ret != 0)
      done = true;

    if ((timeout != kLifxWaitForever) && (elapsed >= timeout))
      done = true;

    if (!done && (ret == 0))
    {
      if (message.Header.Type == kLifxPacketTypeDeviceStateService)
      {
        lifxDevice_t dev = lifxSession_FindDevice(lifx, &message.Header);
        if (dev == kLifxDeviceInvalid)
          dev = lifxSession_CreateDevice(lifx, &message, &source_addr);
      }

      lifx->MessageHandler(lifx, &message, dev);
    }
  }

  return ret;
}

int
lifxSession_SendTo(
  lifxSession_t*    lifx,
  lifxDevice_t      dev,
  void*             packet,
  lifxPacketType_t  packet_type)
{
  lifxProtocolHeader_t header;
  struct sockaddr_in dest;
  int n;

  memset(&header, 0, sizeof(lifxProtocolHeader_t));
  memset(&dest, 0, sizeof(struct sockaddr_in));

  header.Size = sizeof(lifxProtocolHeader_t);
  header.Protocol = kLifxProtocolNumber;
  header.Addressable = 1;
  header.Tagged = 1;
  header.Origin = 0;
  header.Source = 0xdeadbeef;
  header.ResRequired = 0;
  header.AckRequired = 0;
  header.Sequence = lifxInterlockedIncrement(&lifx->SequenceNumber);
  header.Type = kLifxPacketTypeDeviceGetService;

  // TODO: This should come from the lifxDevice
  if (dev == kLifxDeviceAll)
  {
    dest.sin_family = AF_INET;
    dest.sin_port = htons(kLifxDefaultBroadcastPort);
    dest.sin_addr.s_addr = htonl(INADDR_BROADCAST);
  }
  else
  {
    // TODO
    header.Target[0] = 0;
    header.Target[1] = 0;
    header.Target[2] = 0;
    header.Target[3] = 0;
    header.Target[4] = 0;
    header.Target[5] = 0;
    header.Target[6] = 0;
    header.Target[7] = 0;
  }

  {
    char addr[64];
    inet_ntop(AF_INET, &dest.sin_addr, addr, sizeof(addr));
    lxLog_Info(lifx, "send:%s:%d", addr, ntohs(dest.sin_port));
  }

  lxLog_Debug(lifx, "sending message");
  lifxDumpBuffer(lifx, (uint8_t *)&header, (int) sizeof(lifxProtocolHeader_t));

  n = sendto(lifx->Socket, &header, sizeof(lifxProtocolHeader_t), 0, (struct sockaddr *)&dest,
      sizeof(struct sockaddr_in));

  if (n == -1)
  {
    int err = errno;
    lxLog_Warn(lifx, "sendto:%s", lifxError_ToString(err));
    return err;
  }

  return 0;
}

int lifxSession_RecvFrom(
  lifxSession_t*  lifx,
  lifxMessage_t*  message,
  int             timeout)
{
  struct sockaddr_storage source_addr;
  return lifxSession_RecvFromInternal(lifx, message, &source_addr, timeout);
}


int lifxSession_RecvFromInternal(
  lifxSession_t*              lifx,
  lifxMessage_t*              message,
  struct sockaddr_storage*    source,
  int                         timeout)
{
  int             n;
  fd_set          fds;
  struct timeval  wait_time;

  n = 0;
  wait_time.tv_sec = timeout / 1000;
  wait_time.tv_usec = (timeout % 1000) * 1000;
  memset(message, 0, sizeof(lifxMessage_t));
  lifxBuffer_Seek(&lifx->ReadBuffer, 0, kLifxBufferWhenceSet);

  FD_ZERO(&fds);
  FD_SET(lifx->Socket, &fds);

  n = select(lifx->Socket  + 1, &fds, NULL, NULL, &wait_time);
  if (n == -1)
    return errno;

  if (FD_ISSET(lifx->Socket, &fds))
  {
    socklen_t source_size;

    #ifdef LIFX_DEBUG
    memset(lifx->ReadBuffer.Data, 0, lifx->ReadBuffer.Size);
    #endif

    source_size = sizeof(struct sockaddr_storage);
    memset(source, 0, sizeof(struct sockaddr_storage));

    n = recvfrom(lifx->Socket, lifx->ReadBuffer.Data, lifx->ReadBuffer.Size, 0,
      (struct sockaddr *)source, &source_size);

    {
      uint16_t port;
      char buff[256];
      lifxSockaddr_ToString(source, buff, sizeof(buff), &port);
      lxLog_Debug(lifx, "recvfrom:%s:%u", buff, port);
      lxLog_Debug(lifx, "receive:%d", n);
      lifxDumpBuffer(lifx, lifx->ReadBuffer.Data, n);
    }


    if (n == -1)
    {
      int err = errno;
      lxLog_Warn(lifx, "recvfrom:%s", lifxError_ToString(err));
      return err;
    }

    memcpy(&message->Header, lifx->ReadBuffer.Data, sizeof(lifxProtocolHeader_t));
    lifxBuffer_Seek(&lifx->ReadBuffer, sizeof(lifxProtocolHeader_t), kLifxBufferWhenceCurrent);

    // XXX: leaked, still working out what API should look like
    // message->Sender = malloc(sizeof(struct lifxDevice));
    //  memset(message->Sender, 0, sizeof(struct lifxDevice));

    lifxDecoder_DecodePacket(message->Header.Type, &message->Packet, &lifx->ReadBuffer);
    // memcpy(&message->Sender->Endpoint, &source, source_size);
  }
  else
  {
    lxLog_Debug(lifx, "lifxSession_RecvFrom timeout");
  }

  return 0;
}
