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
#include "lifx_encoders.h"
#include "lifx_private.h"
#include "lifx_version.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

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

char const* lifxError_ToString(lifxSystemError_t system_error)
{
  char const* buff;
  lifxErrorThreadSpecific_t* specific;
  
  buff = NULL;
  specific = lifxError_GetThreadSpecific();

  if (specific)
  {
    #ifdef __linux__
    int n = strerror_r(system_error, specific->LastErrorMessage, kLifxErrorMessageMaxLength - 1);
    if (!n)
      buff = specific->LastErrorMessage;
    #else
    buff = strerror(system_error);
    #endif
    specific->LastError = system_error;
  }

  return buff;
}


lifxFuture_t* lifxFuture_Create(lifxSequence_t sequence_number)
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
  int n = lifxInterlockedDecrement(&future->ReferenceCount);
  if (n == 1)
  {
    // TODO(jacobgladish@yahoo.com): signal any waiters
    lifxMutex_Destroy(&future->Mutex);
    lifxCond_Destroy(&future->Cond);
    free(future);
  }
  return kLifxStatusOk;
}

lifxStatus_t lifxFuture_Wait(struct lifxFuture* future, int millis)
{
  lifxStatus_t status = kLifxStatusOk;
  lifxMutex_Lock(&future->Mutex);
  while (!future->Complete)
  {
    status = lifxCond_TimedWait(&future->Cond, &future->Mutex, millis);
    future->Complete = true;
    future->Status = status;
  }
  lifxMutex_Unlock(&future->Mutex);
  return future->Status;
}

lifxStatus_t lifxFuture_Get(lifxFuture_t* future, lifxPacket_t* packet, int millis)
{
  lifxStatus_t status = lifxFuture_Wait(future, millis);
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
  future->Status = status;
  future->Complete = true;
  lifxMutex_Unlock(&future->Mutex);
  lifxCond_NotifyAll(&future->Cond);
  return kLifxStatusOk;
}

// thread stuff
void lifxMutex_Init(lifxMutex_t* mutex)
{
  pthread_mutex_init(mutex, NULL);
}

void lifxMutex_Destroy(lifxMutex_t* mutex)
{
  pthread_mutex_destroy(mutex);
}

void lifxMutex_Lock(lifxMutex_t* mutex)
{
  pthread_mutex_lock(mutex);
}

void lifxMutex_Unlock(lifxMutex_t* mutex)
{
  pthread_mutex_unlock(mutex);
}

void lifxCond_Init(lifxCond_t* cond)
{
  pthread_cond_init(cond, NULL);
}

void lifxCond_Destroy(lifxCond_t* cond)
{
  pthread_cond_destroy(cond);
}

void lifxCond_NotifyAll(lifxCond_t* cond)
{
  pthread_cond_broadcast(cond);
}

lifxStatus_t lifxCond_TimedWait(
  lifxCond_t*             cond,
  lifxMutex_t*            mutex,
  int                     timeout_millis)
{
  int ret;
  struct timespec timeout;
  lifxStatus_t status;

  // TODO(jacobgladish@yahoo.com): proper timeout handling
  clock_gettime(CLOCK_REALTIME, &timeout);
  timeout.tv_sec += (timeout_millis / 1000);

  ret = pthread_cond_timedwait(cond, mutex, &timeout);
  if (ret == 0)
    status = kLifxStatusOk;
  else if (ret == ETIMEDOUT)
    status = kLifxStatusOperationTimedout;
  else if (ret == EINVAL)
    status = kLifxStatusInvalidArgument;
  else if (ret == EPERM)
    status = kLifxStatusPermissionDenied;
  else
    status = kLifxStatusFailed;

  return status;
}

void lifxThread_Create(lifxThread_t* thread, lifxThreadFunc_t startRoutine, void* argp)
{
  pthread_create(thread, NULL, startRoutine, argp);
}
