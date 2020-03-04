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

#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>

#ifndef LIFX_PLATFORM_WINDOWS
#include <sys/time.h>
#endif

#if defined(LIFX_PLATFORM_LINUX)
#include <sys/syscall.h>
#include <unistd.h>
#endif

#ifdef LIFX_PLATFORM_MACOSX
typedef uint64_t lifxThreadId_t;
#define LIFX_THREADID_FMT PRIu64
#elif defined WIN32
typedef unsigned long lifxThreadId_t;
#define LIFX_THREADID_FMT "l"
#else
typedef int32_t lifxThreadId_t;
#define LIFX_THREADID_FMT "d"
#endif

static char const* lifxLogLevelToString(lifxLogLevel_t level)
{
  switch (level)
  {
    case kLifxLogLevelDebug: return "DEBUG"; break;
    case kLifxLogLevelInfo: return "INFO"; break;
    case kLifxLogLevelWarn: return "WARN"; break;
    case kLifxLogLevelError: return "ERROR"; break;
    case kLifxLogLevelFatal: return "FATAL"; break;
  }
  return "";
}

lifxThreadId_t lifxThreadGetCurrentId()
{
#ifdef LIFX_PLATFORM_MACOSX
  uint64_t threadId = 0;
  pthread_threadid_np(NULL, &threadId);
  return threadId;
#elif WIN32
  return GetCurrentThreadId();
#else
  return syscall(__NR_gettid);
#endif
}

void lxLog_Printf(lifxSession_t* lifx, lifxLogLevel_t level, char const* format, ...)
{
  va_list argp;

  if (level < lifx->Config.LogLevel)
    return;

  va_start(argp, format);

  if (lifx->Config.LogCallback)
  {
    char buff[512];
    vsnprintf(buff, sizeof(buff), format, argp);
    lifx->Config.LogCallback(lifx, level, buff);
  }
  else
  {
    struct timeval now;

    #if defined (LIFX_PLATFORM_WINDOWS)
    lifxDateTime_t date_time = lifxDateTime_Now();
    now.tv_sec = (long) (date_time / 1000000);
    date_time -= (date_time / 1000000) * 1000000;
    now.tv_usec = (long) date_time;
    #endif

    lifxMutex_Lock(&lifx->LogMutex);

    #if defined (LIFX_PLATFORM_LINUX) || defined (LIFX_PLATFORM_MACOSX)
    gettimeofday(&now, NULL);
    #ifdef LIFX_PLATFORM_MACOSX
    printf("%ld.%06d %5s -- Thread-%" LIFX_THREADID_FMT ": ", now.tv_sec, now.tv_usec,
        lifxLogLevelToString(level), lifxThreadGetCurrentId());
    #else
    printf("%ld.%06ld %5s -- Thread-%" LIFX_THREADID_FMT ": ", now.tv_sec, now.tv_usec,
        lifxLogLevelToString(level), lifxThreadGetCurrentId());
    #endif
    #endif

    vprintf(format, argp);
    printf("\n");
    lifxMutex_Unlock(&lifx->LogMutex);
  }

  va_end(argp);
}
