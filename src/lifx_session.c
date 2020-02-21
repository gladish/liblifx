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
#include "lifx_private.h"
#include "lifx_encoders.h"

#include <arpa/inet.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

static uint16_t const kLifxProtocolNumber = 0x400; // 1024

static void* lifxSession_Dispatcher(void* argp)
{
  int ret;
  bool done;
  struct lifxSession* lifx = (struct lifxSession *) argp;

  done = false;
  while (!done)
  {
    ret = lifxSession_Dispatch(lifx, 1);
    if ((ret != 0) && (ret != ETIMEDOUT))
    {
      lxLog_Error(lifx, "lifxSession_Dispatch:%d", ret);
      done = true;
    }
  }

  return NULL;
}

lifxDevice_t* lifxSession_FindDevice(lifxSession_t* lifx, lifxDeviceId_t deviceId)
{
  int i;
  if (lifx == NULL)
    return NULL;

  for (i = 0; i < kLifxMaxDevices; ++i)
  {
    if (lifx->DeviceDatabase[i] != NULL)
    {
      if (lifxDeviceId_Compare(&deviceId, &lifx->DeviceDatabase[i]->DeviceId) == 0)
        return lifx->DeviceDatabase[i];
    }
  }

  return NULL;
}

lifxDevice_t* lifxSession_CreateDevice(
  lifxSession_t*                  lifx,
  lifxMessage_t const*            message,
  struct sockaddr_storage* const  source)
{
  int i;
  lifxDevice_t* new_device;

  new_device = NULL;

  for (i = 0; i < kLifxMaxDevices; ++i)
  {
    if (lifx->DeviceDatabase[i] == NULL)
    {
      new_device = malloc(sizeof(lifxDevice_t));
      memcpy(new_device->DeviceId.Octets, message->Header.Target, 6);
      memcpy(&new_device->Endpoint, source, sizeof(struct sockaddr_storage));
      lifx->DeviceDatabase[i] = new_device;

      // XXX: always assumes ipv4
      {
        struct sockaddr_in* v4 = (struct sockaddr_in *) &new_device->Endpoint;
        v4->sin_port = htons(message->Packet.DeviceStateService.Port);
      }

      {
        uint16_t port;
        char buff[256];
        lifxSockaddr_ToString(source, buff, sizeof(buff), &port);
        lxLog_Info(lifx, "adding new device %s:%d [%02x:%02x:%02x:%02x:%02x:%02x] to database",
          buff,
          port,
          lifx->DeviceDatabase[i]->DeviceId.Octets[0],
          lifx->DeviceDatabase[i]->DeviceId.Octets[1],
          lifx->DeviceDatabase[i]->DeviceId.Octets[2],
          lifx->DeviceDatabase[i]->DeviceId.Octets[3],
          lifx->DeviceDatabase[i]->DeviceId.Octets[4],
          lifx->DeviceDatabase[i]->DeviceId.Octets[5]);
      }

      break;
    }
  }

  return new_device;
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

  pthread_mutex_init(&lifx->SessionLock, NULL);

  // set this as early as possible to avoid uninitialized reads
  lifx->Config.LogLevel = kLifxLogLevelInfo;
  if (conf)
  {
    lifxSessionConfig_Copy(&lifx->Config, conf);
  }
  else
  {
    // TODO: set default config
  }

  memset(lifx->LastErrorMessage, 0, kLifxErrorMessageMax);
  lifx->LastError = kLifxStatusOk;

  lxLog_Info(lifx, "liblifx %s", lifx_Version());

  lifx->Socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (lifx->Socket == -1)
  {
    free(lifx);
    return NULL;
  }

  for (n = 0; n < kLifxMaxDevices; ++n)
    lifx->DeviceDatabase[n] = NULL;

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

  if (lifx->Config.BindInterface)
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
      lifxSystemError_t sys_error = lifxError_GetSystemError();
      lxLog_Warn(lifx, "bind:%s", lifxError_ToString(sys_error));
    }
  }

  if (lifx->Config.UseBackgroundDispatchThread)
  {
    lxLog_Info(lifx, "creating background dispatch thread");
    pthread_create(&lifx->BackgroundDispatchThread, NULL, lifxSession_Dispatcher, lifx);
  }

  return lifx;
}

lifxStatus_t lifxSession_Close(lifxSession_t* lifx)
{
  int i;

  if (!lifx)
    return kLifxStatusInvalidArgument;

  if (lifx->Socket != -1)
    close(lifx->Socket);

  if (lifx->Config.BindInterface)
    free(lifx->Config.BindInterface);

  lifxBuffer_Destroy(&lifx->ReadBuffer);
  lifxBuffer_Destroy(&lifx->WriteBuffer);
  free(lifx);

  // TODO: stop background dispatcher thread
  // create a pipe()
  // dispatcher selects() on socket and pipe
  // shutdown write on pipe
  // thread exits
  // this thread joins/waits for disptacher thread to exit

  for (i = 0; i < kLifxMaxDevices; ++i)
  {
    if (lifx->DeviceDatabase[i] != NULL)
      free(lifx->DeviceDatabase[i]);
  }

  return kLifxStatusOk;
}

bool lifxSession_IsDiscoveryEnabled(lifxSession_t* lifx)
{
  bool enabled = false;
  pthread_mutex_lock(&lifx->SessionLock);
  enabled = lifx->RunDiscovery;
  pthread_mutex_unlock(&lifx->SessionLock);
  return enabled;
}

lifxStatus_t lifxSession_StartDiscovery(lifxSession_t* lifx)
{
  pthread_mutex_lock(&lifx->SessionLock);
  lifx->RunDiscovery = true;
  pthread_mutex_unlock(&lifx->SessionLock);
  return lifxSession_SetLastError(lifx, kLifxStatusOk, NULL);
}

lifxStatus_t lifxSession_StopDiscovery(lifxSession_t* lifx)
{
  pthread_mutex_lock(&lifx->SessionLock);
  lifx->RunDiscovery = false;
  pthread_mutex_unlock(&lifx->SessionLock);
  return lifxSession_SetLastError(lifx, kLifxStatusOk, NULL);
}

lifxStatus_t lifxSession_Dispatch(
  lifxSession_t*      lifx,
  int                 timeout)
{
  bool                    done;
  struct timeval          begin;
  struct timeval          last_discovery_sent;
  struct timeval          elapsed;
  lifxMessage_t           message;
  lifxStatus_t            status;
  struct sockaddr_storage source_addr;
  
  done = false;
  timerclear(&begin);
  timerclear(&last_discovery_sent);
  timerclear(&elapsed);
  memset(&message, 0, sizeof(lifxMessage_t));
  memset(&source_addr, 0, sizeof(struct sockaddr_storage));
  status = kLifxStatusOk;
  lifxSession_SetLastError(lifx, kLifxStatusOk, NULL);

  while (!done)
  {
    struct timeval now;
    gettimeofday(&now, NULL);
    if (!timerisset(&begin))
      begin = now;

    if (lifxSession_IsDiscoveryEnabled(lifx))
    {
      timersub(&now, &last_discovery_sent, &elapsed);
      if (elapsed.tv_sec > 1)
      {
        lifxDeviceGetService_t get_service;
        lifxSession_SendTo(lifx, kLifxDeviceAll, &get_service, kLifxPacketTypeDeviceGetService);
        last_discovery_sent = now;
      }
    }

    memset(&message, 0, sizeof(lifxMessage_t));
    status = lifxSession_RecvFromInternal(lifx, &message, &source_addr, 1000);
    if (status != kLifxStatusOk)
    {
      if (status != kLifxStatusOperationTimedout)
        done = true;
      else
        continue;
    }

    gettimeofday(&now, NULL);
    timersub(&now, &begin, &elapsed);

    if (status == kLifxStatusOk)
    {
      lifxDeviceId_t deviceId;
      memcpy(deviceId.Octets, message.Header.Target, 6);


      // response to a device disovery, cache the device in db
      if (message.Header.Type == kLifxPacketTypeDeviceStateService)
      {
        lifxDevice_t* device;
        if ((device = lifxSession_FindDevice(lifx, deviceId)) == NULL)
        {
          device = lifxSession_CreateDevice(lifx, &message, &source_addr);
          if (lifx->Config.DeviceDiscovered)
          {
            memcpy(&deviceId.Octets, &message.Header.Target, 6);
            lifx->Config.DeviceDiscovered(lifx, deviceId);
          }
        }
      }
      else
      {
        // is this response. do we have future waiting
        int i;
        lifxFuture_t* future;

        pthread_mutex_lock(&lifx->SessionLock);
        for (i = 0; i < kLifxRequestsMax; ++i)
        {
          future = lifx->OutstandingRequests[i];
          if ((future != NULL) && (future->SequenceNumber == message.Header.Sequence))
          {
            lifxFuture_SetComplete(future, 0, &message.Packet);
            lifxFuture_Release(future);
            lifx->OutstandingRequests[i] = NULL;
            pthread_mutex_unlock(&lifx->SessionLock);
            return lifxSession_SetLastError(lifx, kLifxStatusOk, NULL);
          }
        }
        pthread_mutex_unlock(&lifx->SessionLock);
      }
    }

    if ((timeout != kLifxWaitForever) && (elapsed.tv_sec >= timeout))
      done = true;
  }

  return status;
}

lifxStatus_t lifxSession_SendTo(
  lifxSession_t*    lifx,
  lifxDeviceId_t    deviceId,
  void*             packet,
  lifxPacketType_t  packetType)
{
  uint8_t seqno = lifxInterlockedIncrement(&lifx->SequenceNumber);
  return lifxSession_SendToInternal(lifx, deviceId, packet, packetType, seqno);
}

lifxStatus_t lifxSession_SendToInternal(
  lifxSession_t*    lifx,
  lifxDeviceId_t    deviceId,
  void*             packet,
  lifxPacketType_t  packetType,
  uint8_t           seqno)
{
  lifxProtocolHeader_t header;
  struct sockaddr_storage dest;
  int n;

  memset(&header, 0, kLifxSizeofHeader);
  // TODO: we could utilize the lifxBuffer for this. currently the lifxBuffer_Write
  // functions return zero on ok. they could return the bytes written which 
  // would then also be returned from the lifxEncoder_EncodePacket(). this would
  // allow us to avoid switch'ing on the packet_type twice.
  header.Size = kLifxSizeofHeader + lifxEncoder_GetEncodedSize(packetType);
  header.Protocol = kLifxProtocolNumber;
  header.Addressable = 1;
  header.Tagged = 1;
  header.Origin = 0;
  header.Source = 0xdeadbeef;
  header.ResRequired = 0;
  header.AckRequired = 0;
  header.Sequence = seqno;
  header.Type = packetType;

  if (lifxDeviceId_Compare(&deviceId, &kLifxDeviceAll) == 0)
  {
    struct sockaddr_in* v4 = (struct sockaddr_in *) &dest;
    memset(&dest, 0, sizeof(struct sockaddr_in));
    v4->sin_family = AF_INET;
    v4->sin_port = htons(kLifxDefaultBroadcastPort);
    v4->sin_addr.s_addr = htonl(INADDR_BROADCAST);
  }
  else
  {
    lifxDevice_t* entry = lifxSession_FindDevice(lifx, deviceId);
    if (entry)
    {
      header.ResRequired = 1;
      header.Addressable = 1;
      header.Tagged = 0;
      header.Target[0] = entry->DeviceId.Octets[0];
      header.Target[1] = entry->DeviceId.Octets[1];
      header.Target[2] = entry->DeviceId.Octets[2];
      header.Target[3] = entry->DeviceId.Octets[3];
      header.Target[4] = entry->DeviceId.Octets[4];
      header.Target[5] = entry->DeviceId.Octets[5];
      header.Target[6] = 0;
      header.Target[7] = 0;
      memcpy(&dest, &entry->Endpoint, sizeof(struct sockaddr_storage));
    }
    else
    {
      lxLog_Warn(lifx, "can't find device in database to send");
      return kLifxStatusUnknownDevice;
    }
  }

  // copy header to write buffer
  // memcpy(lifx->WriteBuffer.Data, &header, kLifxSizeofHeader);
  // lifxBuffer_Seek(&lifx->WriteBuffer, kLifxSizeofHeader, kLifxBufferWhenceSet);
  lifxBuffer_Seek(&lifx->WriteBuffer, 0, kLifxBufferWhenceSet);
  lifxBuffer_Write(&lifx->WriteBuffer, &header, kLifxSizeofHeader);
  lifxEncoder_EncodePacket(&lifx->WriteBuffer, packetType, packet);

  {
    char addr[64];
    struct sockaddr_in* v4 = (struct sockaddr_in *) &dest;
    inet_ntop(AF_INET, &v4->sin_addr, addr, sizeof(addr));
    lxLog_Info(lifx, ">>> message >>> (%s:%u) -- type:%d size:%d",
      addr, ntohs(v4->sin_port), header.Type, header.Size);
    lifxDumpBuffer(lifx, lifx->WriteBuffer.Data, header.Size);
  }

  n = sendto(lifx->Socket, lifx->WriteBuffer.Data, header.Size, 0,
    (struct sockaddr *)&dest, sizeof(struct sockaddr_in));

  if (n == -1)
  {
    lifxSystemError_t sys_error = lifxError_GetSystemError();
    return lifxSession_SetLastError(lifx, kLifxStatusFailed, "sendto failed. %s",
      lifxError_ToString(sys_error));
  }

  return kLifxStatusFailed;
}

lifxStatus_t lifxSession_RecvFrom(
  lifxSession_t*  lifx,
  lifxMessage_t*  message,
  int             timeout)
{
  struct sockaddr_storage source_addr;
  return lifxSession_RecvFromInternal(lifx, message, &source_addr, timeout);
}

lifxStatus_t lifxSession_RecvFromInternal(
  lifxSession_t*              lifx,
  lifxMessage_t*              message,
  struct sockaddr_storage*    source,
  int                         timeout)
{
  int             n;
  fd_set          fds;
  struct timeval  wait_time;
  lifxStatus_t    status;

  n = 0;
  wait_time.tv_sec = timeout / 1000;
  wait_time.tv_usec = (timeout % 1000) * 1000;
  memset(message, 0, sizeof(lifxMessage_t));
  lifxBuffer_Seek(&lifx->ReadBuffer, 0, kLifxBufferWhenceSet);
  lifxSession_SetLastError(lifx, kLifxStatusOk, NULL);

  FD_ZERO(&fds);
  FD_SET(lifx->Socket, &fds);

  n = select(lifx->Socket  + 1, &fds, NULL, NULL, &wait_time);
  if (n == -1)
  {
    lifxSystemError_t sys_error = lifxError_GetSystemError();
    return lifxSession_SetLastError(lifx, kLifxStatusFailed, 
      "select failed. %s", lifxError_ToString(sys_error));
  }

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

    if (n == -1)
    {
      lifxSystemError_t sys_error = lifxError_GetSystemError();
      status = lifxSession_SetLastError(lifx, kLifxStatusFailed,
        "recvfrom failed. %s", lifxError_ToString(sys_error));
      return status;
    }

    memcpy(&message->Header, lifx->ReadBuffer.Data, sizeof(lifxProtocolHeader_t));
    lifxBuffer_Seek(&lifx->ReadBuffer, sizeof(lifxProtocolHeader_t), kLifxBufferWhenceCurrent);
    lifxDecoder_DecodePacket(&lifx->ReadBuffer, message->Header.Type, &message->Packet);

    {
      uint16_t port;
      char buff[256];
      lifxSockaddr_ToString(source, buff, sizeof(buff), &port);
      lxLog_Info(lifx, "<<< message <<< (%s:%u) -- type:%d size:%d",
        buff, port, message->Header.Type, n);
      lifxDumpBuffer(lifx, lifx->ReadBuffer.Data, n);
    }
  }
  else
  {
    status = kLifxStatusOperationTimedout;
  }

  return status;
}

int lifxDeviceId_Compare(
  lifxDeviceId_t const* deviceId1,
  lifxDeviceId_t const* deviceId2)
{
  return memcmp(deviceId1->Octets, deviceId2->Octets, 6);
}

lifxStatus_t lifxDeviceId_ToString(
  lifxDeviceId_t const* deviceId,
  char*                 buff,
  int                   n)
{
  if (!deviceId)
    return kLifxStatusInvalidArgument;
  if (!buff)
    return kLifxStatusInvalidArgument;
  if (n < 30)
    return kLifxStatusNotEnoughMemory;

  memset(buff, 0, n);
  snprintf(buff, n, "lifx_id://mac/%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx", 
    deviceId->Octets[0],
    deviceId->Octets[1],
    deviceId->Octets[2],
    deviceId->Octets[3],
    deviceId->Octets[4],
    deviceId->Octets[5]);

  return kLifxStatusOk;
}

lifxStatus_t lifxDeviceId_FromString(
  lifxDeviceId_t*       deviceId,
  char const*           buff)
{
  if (!deviceId)
    return kLifxStatusInvalidArgument;
  if (!buff)
    return kLifxStatusInvalidArgument;

  sscanf(buff, "lifx_id://mac/%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx",
    &deviceId->Octets[0],
    &deviceId->Octets[1],
    &deviceId->Octets[2],
    &deviceId->Octets[3],
    &deviceId->Octets[4],
    &deviceId->Octets[5]);

  return kLifxStatusOk;
}

int lifxSessionConfig_Copy(lifxSessionConfig_t* dest, lifxSessionConfig_t const* src)
{
  if (!dest)
    return EINVAL;
  if (!src)
    return EINVAL;

  memcpy(dest, src, sizeof(lifxSessionConfig_t));

  if (src->BindInterface)
    dest->BindInterface = strdup(src->BindInterface);
  else
    dest->BindInterface = NULL;

  return 0;
}

lifxStatus_t lifxSessionConfig_Init(lifxSessionConfig_t* conf)
{
  if (!conf)
    return kLifxStatusInvalidArgument;
  memset(conf, 0, sizeof(lifxSessionConfig_t));
  return kLifxStatusOk;
}

lifxStatus_t lifxSession_RegisterRequest(
  lifxSession_t*      lifx,
  lifxFuture_t*       future)
{
  int i;

  lxLog_Info(lifx, "registering:%d", future->SequenceNumber);

  pthread_mutex_lock(&lifx->SessionLock);
  for (i = 0; i < kLifxRequestsMax; ++i)
  {
    if (lifx->OutstandingRequests[i] == NULL)
    {
      lifxFuture_Retain(future);
      lifx->OutstandingRequests[i] = future;
      pthread_mutex_unlock(&lifx->SessionLock);
      return lifxSession_SetLastError(lifx, kLifxStatusOk, NULL);
    }
  }
  pthread_mutex_unlock(&lifx->SessionLock);
  return lifxSession_SetLastError(lifx, kLifxStatusFailed, 
    "failed to find open slot for request");
}

lifxFuture_t* lifxSession_BeginSendRequest(
  lifxSession_t*    lifx,
  lifxDeviceId_t    deviceId,
  void*             packet,
  lifxPacketType_t  packetType)
{
  int             ret;
  lifxFuture_t*   future;

  future = lifxFuture_Create(lifxInterlockedIncrement(&lifx->SequenceNumber));
  ret = lifxSession_RegisterRequest(lifx, future);
  if (ret != 0)
  {
    lxLog_Warn(lifx, "failed to register future:%d", ret);
  }

  ret = lifxSession_SendToInternal(lifx, deviceId, packet, packetType, future->SequenceNumber);
  if (ret != 0)
  {
    lxLog_Warn(lifx, "failed to send message:%d", ret);
  }

  return future;
}

lifxStatus_t lifxSession_SendRequest(
  lifxSession_t*    lifx,
  lifxDeviceId_t    deviceId,
  void*             request,
  lifxPacketType_t  packetType,
  lifxPacket_t*     response,
  int               millis)
{
  lifxStatus_t status = kLifxStatusOk;
  lifxFuture_t* future = lifxSession_BeginSendRequest(lifx, deviceId, request, packetType);
  lifxSession_SetLastError(lifx, kLifxStatusOk, NULL);

  status = lifxFuture_Wait(future, millis);
  if (status == kLifxStatusOk)
    status = lifxFuture_Get(future, response, 2000);
  lifxFuture_Release(future);

  return status;
}

lifxStatus_t lifxSession_SetLastError(
  lifxSession_t*                  lifx,
  lifxStatus_t                    status,
  char const*                     format, ...)
{
  if (lifx)
  {
    if (format)
    {
      va_list argp;
      va_start(argp, format);
      memset(lifx->LastErrorMessage, 0, kLifxErrorMessageMax);
      vsnprintf(lifx->LastErrorMessage, (kLifxErrorMessageMax - 1), format, argp);
      va_end(argp);
    }
    else
    {
      lifx->LastErrorMessage[0] = '\0';
    }

    lifx->LastError = status;
  }

  return status;
}

lifxStatus_t lifxSession_GetLastError(
  lifxSession_t*                  lifx,
  char*                           buff,
  int                             n)
{
  lifxStatus_t status = 0;
  if (lifx)
  {
    status = lifx->LastError;
    if (buff)
    {
      size_t len = strlen(lifx->LastErrorMessage);
      if (len > (size_t) (n - 1))
        len = (n - 1);
      memset(buff, 0, n);
      strncpy(buff, lifx->LastErrorMessage, len);
    }
  }
  return status;
}

