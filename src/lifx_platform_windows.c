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
#include <stdio.h>

// static pthread_once_t error_once = PTHREAD_ONCE_INIT;
// static pthread_key_t  error_key;

lifxSystemError_t lifxError_GetSystemError()
{
  return 0;
}

void lifxMutex_Init(lifxMutex_t* mutex)
{
  InitializeCriticalSection(mutex);
}

void lifxMutex_Destroy(lifxMutex_t* mutex)
{
  DeleteCriticalSection(mutex); 
}

void lifxMutex_Lock(lifxMutex_t* mutex)
{
  EnterCriticalSection(mutex);
}

void lifxMutex_Unlock(lifxMutex_t* mutex)
{
  LeaveCriticalSection(mutex);
}

void lifxCond_Init(lifxCond_t* cond)
{
  InitializeConditionVariable(cond);
}

void lifxCond_Destroy(lifxCond_t* cond)
{
  (void) cond;
}

void lifxCond_NotifyAll(lifxCond_t* cond)
{
  WakeAllConditionVariable(cond); 
}

lifxStatus_t lifxCond_TimedWait(
  lifxCond_t*             cond,
  lifxMutex_t*            mutex,
  lifxTimeSpan_t          timeout)
{
  BOOL b;
  DWORD dwMilliseconds;
  DWORD dwError;
  lifxStatus_t status;

  b = FALSE;
  dwMilliseconds = lifxTimeSpan_ToMilliseconds(timeout);

  b = SleepConditionVariableCS(cond, mutex, dwMilliseconds);
  if (!b)
  {
    dwError = GetLastError();
    switch (dwError)
    {
      case ERROR_TIMEOUT:
        status = kLifxStatusOperationTimedout;
      break;
      default:
        status = kLifxStatusFailed;
        break;
    }
  }
  else
  {
    dwError = 0;
    status = kLifxStatusOk;
  }

  return status;
}

void lifxThread_Create(lifxThread_t* thread, lifxThreadFunc_t start_routine, void* argp)
{
  *thread = CreateThread(
    NULL,
    0,
    start_routine,
    argp,
    0,
    NULL);
}

#if 0
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
#endif

char const* lifxError_ToString(lifxSystemError_t system_error)
{
#if 0
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
#endif
  return "";
}

lifxDateTime_t lifxDateTime_Now()
{
  lifxDateTime_t now;
  FILETIME file_time;
  LARGE_INTEGER large_int;

  int64_t const kUnixStartTime = 116444736000000000;
  int64_t const kTicksPerMicrosecond= 10;

  GetSystemTimeAsFileTime(&file_time);
  large_int.LowPart = file_time.dwLowDateTime;
  large_int.HighPart = file_time.dwHighDateTime;
  now = (large_int.QuadPart - kUnixStartTime) / kTicksPerMicrosecond;

  return now;
}

void lifxSleep(uint32_t milliseconds)
{
  Sleep(milliseconds);
}

void lifxWSAStartup()
{
  WORD wVersionRequested;
  WSADATA wsaData;
  int err;

  wVersionRequested = MAKEWORD(2, 2);
  err = WSAStartup(wVersionRequested, &wsaData);
  if (err != 0)
  {
    printf("WSAStartup failed with error:%d\n", err);
    ExitProcess(1);
  }
}

void lifsWSAShutdown()
{
  WSACleanup();
}
