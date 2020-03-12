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
#include "lifx_private.h"

#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

static pthread_once_t error_once = PTHREAD_ONCE_INIT;
static pthread_key_t  error_key;

lifxSystemError_t lifxError_GetSystemError(lifxSubSystem_t sub_system)
{
  (void) sub_system;
  return errno;
}

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
  lifxTimeSpan_t          timeout)
{
  int ret;
  struct timespec time_spec;
  uint64_t micros;
  lifxStatus_t status;

  // printf("timeout:%ld\n", timeout);

  clock_gettime(CLOCK_REALTIME, &time_spec);

  // printf("time_spec.tv_sec:%ld\n", time_spec.tv_sec);
  // printf("time_spec.tv_nsec:%ld\n", time_spec.tv_nsec);
  micros = lifxTimeSpan_ToMicroseconds(timeout);
  time_spec.tv_sec += (micros / 1000000);
  micros -= ((micros / 1000000) * 1000000);
  time_spec.tv_nsec += micros * 1000;

  // need to account for rollover
  if (time_spec.tv_nsec > 1000000000)
  {
    time_spec.tv_sec += 1;
    time_spec.tv_nsec -= 1000000000;
  }

  // printf("time_spec.tv_sec:%ld\n", time_spec.tv_sec);
  // printf("time_spec.tv_nsec:%ld\n", time_spec.tv_nsec);

  ret = pthread_cond_timedwait(cond, mutex, &time_spec);
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

lifxDateTime_t lifxDateTime_Now()
{
  lifxDateTime_t now;

  struct timeval tv;
  gettimeofday(&tv, NULL);

  now = (tv.tv_sec * 1000 * 1000);
  now += tv.tv_usec;

  return now;
}

void lifxSleep(uint32_t milliseconds)
{
  usleep(milliseconds * 1000);
}
