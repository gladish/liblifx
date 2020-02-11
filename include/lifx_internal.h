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
#ifndef __LIFX_INTERNAL_H__
#define __LIFX_INTERNAL_H__

#include "lifx.h"
#include <netinet/in.h>
#include <sys/socket.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __GNUC__
#define LIFX_PRINTF_FORMAT(IDX, FIRST) __attribute__ ((format (printf, IDX, FIRST)))
#else
#define LIFX_PRINTF_FORMAT(IDX, FIRST)
#endif

typedef enum
{
  kLifxLogLevelDebug = 0,
  kLifxLogLevelInfo = 1,
  kLifxLogLevelWarn = 2,
  kLifxLogLevelError = 3,
  kLifxLogLevelFatal = 4
} lifxLogLevel_t;

struct lifxSession
{
  int             Socket;
  uint32_t        SourceId;
  uint8_t         SequenceNumber;
  lifxBuffer_t    ReadBuffer;
  lifxLogLevel_t  LogLevel;
};

struct lifxDevice
{
  struct sockaddr_storage Endpoint;
};

void lxLog_Printf(lifxSession_t* lifx, lifxLogLevel_t level, const char* format, ...) LIFX_PRINTF_FORMAT(3, 4);
#define lxLog_Print(SESS, LEVEL, FORMAT, ...) do { lxLog_Printf(SESS, LEVEL, FORMAT, ## __VA_ARGS__); } while (0)

#define lxLog_Debug(SESS, FORMAT, ...) lxLog_Print(SESS, kLifxLogLevelDebug, FORMAT, ## __VA_ARGS__)
#define lxLog_Info(SESS, FORMAT, ...) lxLog_Print(SESS, kLifxLogLevelInfo, FORMAT, ## __VA_ARGS__)
#define lxLog_Warn(SESS, FORMAT, ...) lxLog_Print(SESS, kLifxLogLevelWarn, FORMAT, ## __VA_ARGS__)
#define lxLog_Error(SESS, FORMAT, ...) lxLog_Print(SESS, kLifxLogLevelError, FORMAT, ## __VA_ARGS__)
#define lxLog_Fatal(SESS, FORMAT, ...) lxLog_Print(SESS, kLifxLogLevelFatal, FORMAT, ## __VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif
