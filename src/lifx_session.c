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
#include "lifx_internal.h"
#include "lifx_encoders.h"

#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

static uint16_t const kLifxProtocolNumber = 0x400; // 1024

static void* lifxSession_Dispatcher(void* argp)
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

struct lifxDevice* lifxSession_GetDeviceEntry(lifxSession_t* lifx, lifxDevice_t dev)
{
  if (dev < 0 || dev >= kLifxMaxDevices)
    return NULL;
  return lifx->DeviceDatabase[dev];
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

      // XXX: always assumes ipv4
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

lifxSession_t* lifxSession_Open(lifxSessionConfig_t const* conf)
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

  n = (int) (kLifxSizeofHeader + sizeof(lifxPacket_t));
  lifxBuffer_Init(&lifx->ReadBuffer, n);
  lifxBuffer_Init(&lifx->WriteBuffer, n);
  lxLog_Info(lifx, "allocated %d bytes for read/write buffers", n);

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

int lifxSession_Close(lifxSession_t* lifx)
{
  if (!lifx)
    return EINVAL;

  if (lifx->Socket != -1)
    close(lifx->Socket);

  lifxBuffer_Destroy(&lifx->ReadBuffer);
  lifxBuffer_Destroy(&lifx->WriteBuffer);
  free(lifx);

  return 0;
}

int
lifxSession_Dispatch(lifxSession_t* lifx, int timeout)
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
    if ((ret != 0) && (ret != ETIMEDOUT))
      done = true;


    if ((timeout != kLifxWaitForever) && (elapsed >= timeout))
      done = true;

    if (!done && (ret == 0))
    {
      if (message.Header.Type == kLifxPacketTypeDeviceStateService)
      {
        dev = lifxSession_FindDevice(lifx, &message.Header);
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
  struct sockaddr_storage dest;
  int n;

  memset(&header, 0, kLifxSizeofHeader);
  // TODO: we could utilize the lifxBuffer for this. currently the lifxBuffer_Write
  // functions return zero on ok. they could return the bytes written which 
  // would then also be returned from the lifxEncoder_EncodePacket(). this would
  // allow us to avoid switch'ing on the packet_type twice.
  header.Size = kLifxSizeofHeader + lifxEncoder_GetEncodedSize(packet_type);
  header.Protocol = kLifxProtocolNumber;
  header.Addressable = 1;
  header.Tagged = 1;
  header.Origin = 0;
  header.Source = 0xdeadbeef;
  header.ResRequired = 0;
  header.AckRequired = 0;
  header.Sequence = lifxInterlockedIncrement(&lifx->SequenceNumber);
  header.Type = packet_type;

  if (dev == kLifxDeviceAll)
  {
    struct sockaddr_in* v4 = (struct sockaddr_in *) &dest;
    memset(&dest, 0, sizeof(struct sockaddr_in));
    v4->sin_family = AF_INET;
    v4->sin_port = htons(kLifxDefaultBroadcastPort);
    v4->sin_addr.s_addr = htonl(INADDR_BROADCAST);
  }
  else
  {
    struct lifxDevice* entry = lifxSession_GetDeviceEntry(lifx, dev);
    if (entry)
    {
      header.ResRequired = 1;
      header.Addressable = 1;
      header.Tagged = 0;
      header.Target[0] = entry->HardwareAddress[0];
      header.Target[1] = entry->HardwareAddress[1];
      header.Target[2] = entry->HardwareAddress[2];
      header.Target[3] = entry->HardwareAddress[3];
      header.Target[4] = entry->HardwareAddress[4];
      header.Target[5] = entry->HardwareAddress[5];
      header.Target[6] = 0;
      header.Target[7] = 0;
      memcpy(&dest, &entry->Endpoint, sizeof(struct sockaddr_storage));
    }
  }

  // copy header to write buffer
  // memcpy(lifx->WriteBuffer.Data, &header, kLifxSizeofHeader);
  // lifxBuffer_Seek(&lifx->WriteBuffer, kLifxSizeofHeader, kLifxBufferWhenceSet);
  lifxBuffer_Seek(&lifx->WriteBuffer, 0, kLifxBufferWhenceSet);
  lifxBuffer_Write(&lifx->WriteBuffer, &header, kLifxSizeofHeader);
  lifxEncoder_EncodePacket(&lifx->WriteBuffer, packet_type, packet);

  {
    char addr[64];
    struct sockaddr_in* v4 = (struct sockaddr_in *) &dest;
    inet_ntop(AF_INET, &v4->sin_addr, addr, sizeof(addr));
    lxLog_Info(lifx, "sendto:%s:%d", addr, ntohs(v4->sin_port));
  }

  lxLog_Debug(lifx, "sending message:%d type:%d", header.Size, header.Type);
  lifxDumpBuffer(lifx, lifx->WriteBuffer.Data, header.Size);
  lxLog_Debug(lifx, "that was payload");

  n = sendto(lifx->Socket, lifx->WriteBuffer.Data, header.Size, 0,
    (struct sockaddr *)&dest, sizeof(struct sockaddr_in));

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

    lifxDecoder_DecodePacket(&lifx->ReadBuffer, message->Header.Type, &message->Packet);
    // memcpy(&message->Sender->Endpoint, &source, source_size);
  }
  else
  {
    return ETIMEDOUT;
  }

  return 0;
}
