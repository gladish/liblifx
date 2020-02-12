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

#include <stdarg.h>
#include <stdio.h>
#include <sys/time.h>

#ifdef __linux__
#include <unistd.h>
#include <sys/syscall.h>
#endif

#ifdef __APPLE__
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
#ifdef __APPLE__
  uint64_t threadId = 0;
  pthread_threadid_np(NULL, &threadId);
  return threadId;
#elif WIN32
  return GetCurrentThreadId();
#else
  return syscall(__NR_gettid);
#endif
}

void
lxLog_Printf(lifxSession_t* lifx, lifxLogLevel_t level, char const* format, ...)
{
  va_list argp;

  if (level < lifx->LogLevel)
    return;

  va_start(argp, format);

  if (lifx->LogCallback)
  {
    char buff[512];
    vsnprintf(buff, sizeof(buff), format, argp);
    lifx->LogCallback(lifx, level, buff);
  }
  else
  {
    struct timeval now;
    gettimeofday(&now, NULL);

    printf("%ld.%06ld %5s -- Thread-%" LIFX_THREADID_FMT ": ", now.tv_sec, now.tv_usec,
        lifxLogLevelToString(level), lifxThreadGetCurrentId());
    vprintf(format, argp);
    printf("\n");
  }

  va_end(argp);
}
