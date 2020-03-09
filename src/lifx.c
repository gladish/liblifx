//
// Copyright [2020] jacobgladish@yahoo.com,thomaslea@gmail.com
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
#include "lifx_encoders.h"
#include "lifx_private.h"
#include "lifx_version.h"

#ifndef LIFX_PLATFORM_WINDOWS
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lifxDumpBuffer(lifxSession_t* lifx, uint8_t* p, int n)
{
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

void lifxSockaddr_ToString(
  struct sockaddr_storage const*  socket_address,
  char*                           buff,
  int                             n,
  uint16_t*                       port)
{
  // TODO(jacobgladish@yahoo.com): ipv6 support
  if (socket_address->ss_family == AF_INET)
  {
    struct sockaddr_in* v4 = (struct sockaddr_in *) socket_address;
    inet_ntop(socket_address->ss_family, &v4->sin_addr, buff, n);
    if (port)
      *port = ntohs(v4->sin_port);
  }
}

char const* lifx_Version()
{
  return "v" LIFX_PROJECT_VER;
}

lifxFuture_t* lifxFuture_Create(lifxAtomic_t sequence_number)
{
  lifxFuture_t* f = malloc(sizeof(struct lifxFuture));
  if (f == NULL)
    return NULL;
  lifxMutex_Init(&f->Mutex);
  lifxCond_Init(&f->Cond);
  memset(&f->Result, 0, sizeof(lifxPacket_t));
  f->Status = kLifxStatusOk;
  f->ReferenceCount = 1;
  f->Complete = false;
  f->SequenceNumber = sequence_number;
  return f;
}

lifxStatus_t lifxFuture_Retain(struct lifxFuture* future)
{
  lifxInterlockedIncrement(&future->ReferenceCount);
  return kLifxStatusOk;
}

lifxStatus_t lifxFuture_Release(struct lifxFuture* future)
{
  lifxAtomic_t n = lifxInterlockedDecrement(&future->ReferenceCount);
  if (n == 0)
  {
    // TODO(jacobgladish@yahoo.com): signal any waiters
    lifxMutex_Destroy(&future->Mutex);
    lifxCond_Destroy(&future->Cond);
    free(future);
  }
  return kLifxStatusOk;
}

lifxStatus_t lifxFuture_Wait(struct lifxFuture* future, lifxTimeSpan_t timeout)
{
  lifxStatus_t status = kLifxStatusOk;
  lifxMutex_Lock(&future->Mutex);
  while (!future->Complete)
  {
    status = lifxCond_TimedWait(&future->Cond, &future->Mutex, timeout);
    future->Complete = true;
    future->Status = status;
  }
  lifxMutex_Unlock(&future->Mutex);
  return future->Status;
}

lifxStatus_t lifxFuture_Get(lifxFuture_t* future, lifxPacket_t* packet, lifxTimeSpan_t timeout)
{
  lifxStatus_t status = lifxFuture_Wait(future, timeout);
  if (status == kLifxStatusOk)
    *packet = future->Result;
  return status;
}

lifxStatus_t lifxFuture_SetComplete(
  lifxFuture_t*       future, 
  lifxStatus_t        status, 
  lifxPacket_t*       packet)
{
  lifxMutex_Lock(&future->Mutex);
  if (packet)
    future->Result = *packet;
  else
    memset(&future->Result, 0, sizeof(future->Result));
  future->Status = status;
  future->Complete = true;
  lifxMutex_Unlock(&future->Mutex);
  lifxCond_NotifyAll(&future->Cond);
  return kLifxStatusOk;
}

lifxTimeSpan_t lifxTimeSpan_FromMilliseconds(uint64_t millis)
{
  lifxTimeSpan_t time_span;
  time_span._ticks = (millis * 1000);
  return time_span;
}

lifxTimeSpan_t lifxTimeSpan_FromSeconds(uint64_t seconds)
{
  lifxTimeSpan_t time_span;
  time_span._ticks = (seconds * 1000 * 1000);
  return time_span;
}

lifxTimeSpan_t lifxDateTime_Subtract(
  lifxDateTime_t  now,
  lifxDateTime_t  then)
{
  lifxTimeSpan_t time_span;
  time_span._ticks = (now - then);
  return time_span;
}

uint64_t lifxTimeSpan_ToMilliseconds(
  lifxTimeSpan_t  time_span)
{
  return time_span._ticks / 1000;
}

uint64_t lifxTimeSpan_ToMicroseconds(
  lifxTimeSpan_t  time_span)
{
  return time_span._ticks;
}

int lifxTimeSpan_Compare(
  lifxTimeSpan_t time_span1,
  lifxTimeSpan_t time_span2)
{
  int64_t result = time_span1._ticks - time_span2._ticks;
  if (result > 0)
    return 1;
  if (result < 0)
    return -1;
  return 0;
}

lifxTimeSpan_t lifxTimeSpan_Zero()
{
  lifxTimeSpan_t time_span;
  time_span._ticks = 0;
  return time_span;
}

lifxTimeSpan_t lifxTimeSpan_Forever()
{
  lifxTimeSpan_t time_span;
  time_span._ticks = UINT64_MAX;
  return time_span;
}


void lifxEncoder_EncodeHeader(
  lifxBuffer_t*               buff,
  lifxProtocolHeader_t const* header)
{
  // https://lan.developer.lifx.com/v2.0/docs/header-description#frame
  uint8_t  temp_u8;
  uint16_t temp_u16;
  uint8_t  zeros[16];

  memset(zeros, 0, sizeof(zeros));
  lifxBuffer_WriteUInt16(buff, header->Size);
  temp_u16 = header->Protocol;
  if (header->Addressable)
    temp_u16 |= (1 << 12);
  if (header->Tagged)
    temp_u16 |= (1 << 13);
  lifxBuffer_WriteUInt16(buff, temp_u16);
  lifxBuffer_WriteUInt32(buff, header->Source);
  lifxBuffer_Write(buff, header->Target, 8);
  lifxBuffer_Write(buff, zeros, 6);
  temp_u8 = 0;
  if (header->ResRequired)
    temp_u8 |= 1;
  if (header->AckRequired)
    temp_u8 |= (1 << 1);
  lifxBuffer_WriteUInt8(buff, temp_u8);
  lifxBuffer_WriteUInt8(buff, header->Sequence);
  lifxBuffer_Write(buff, zeros, 8);
  lifxBuffer_WriteUInt16(buff, header->Type);
  lifxBuffer_Write(buff, zeros, 2);
}

void lifxDecoder_DecodeHeader(
  lifxBuffer_t*               buff,
  lifxProtocolHeader_t*       header)
{
  uint8_t  temp_u8;
  uint16_t temp_u16;
  uint8_t  zeros[16];

  memset(header, 0, sizeof(lifxProtocolHeader_t));
  memset(zeros, 0, sizeof(zeros));

  lifxBuffer_ReadUInt16(buff, &header->Size);
  lifxBuffer_ReadUInt16(buff, &temp_u16);
  header->Protocol = temp_u16 & 0x0fff;
  header->Addressable = temp_u16 & 0x1000;
  header->Tagged = temp_u16 & 0x2000;
  header->Origin = 0;
  lifxBuffer_ReadUInt32(buff, &header->Source);
  lifxBuffer_Read(buff, header->Target, 8);
  lifxBuffer_Read(buff, zeros, 6);
  lifxBuffer_ReadUInt8(buff, &temp_u8);
  header->ResRequired = temp_u8 & 0x0001;
  header->AckRequired = temp_u8 & 0x0002;
  lifxBuffer_ReadUInt8(buff, &header->Sequence);
  lifxBuffer_Read(buff, zeros, 8);
  lifxBuffer_ReadUInt16(buff, &header->Type);
  lifxBuffer_Read(buff, zeros, 2);
}
