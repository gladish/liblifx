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
  if (kLifxLogLevelDebug < lifx->Config.LogLevel)
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
  LIFX_ASSERT(result < INT32_MAX);
  return (int) result;
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
