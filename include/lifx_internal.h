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
#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __GNUC__
#define LIFX_PRINTF_FORMAT(IDX, FIRST) __attribute__ ((format (printf, IDX, FIRST)))
#define lifxInterlockedIncrement(X) __atomic_fetch_add((X), 1, __ATOMIC_SEQ_CST)
#define lifxInterlockedDecrement(X) __atomic_fetch_sub((X), 1, __ATOMIC_SEQ_CST)
#else
#define LIFX_PRINTF_FORMAT(IDX, FIRST)
#error "Not supported"
#endif

#define kLifxErrorMessageMaxLength (256)
#define kLifxMaxDevices (256)
#define kLifxSizeofHeader (sizeof(lifxProtocolHeader_t))

typedef struct
{
  lifxDeviceId_t          DeviceId; 
  struct sockaddr_storage Endpoint;
} LIFX_IMPORT lifxDevice_t;

LIFX_IMPORT struct lifxSession
{
  int                     Socket;
  uint32_t                SourceId;
  uint8_t                 SequenceNumber;
  lifxBuffer_t            ReadBuffer;
  lifxBuffer_t            WriteBuffer;
  pthread_t               BackgroundDispatchThread;
  pthread_mutex_t         SessionLock;
  lifxDevice_t*           DeviceDatabase[kLifxMaxDevices];
  lifxSessionConfig_t     Config;
  bool                    RunDiscovery;
};

LIFX_IMPORT int lifxSessionConfig_Copy(lifxSessionConfig_t* dest, lifxSessionConfig_t const* src);


/**
 *
 */
LIFX_IMPORT char const* lifxError_ToString(int errnum);

/**
 *
 */
LIFX_IMPORT lifxDevice_t* lifxSession_FindDevice(
  lifxSession_t*  lifx,
  lifxDeviceId_t  deviceId);

/**
 *
 */
LIFX_IMPORT lifxDevice_t* lifxSession_CreateDevice(
  lifxSession_t*                  lifx,
  lifxMessage_t const*            message,
  struct sockaddr_storage* const  source);

LIFX_IMPORT int lifxSession_RecvFromInternal(
  lifxSession_t*              lifx,
  lifxMessage_t*              message,
  struct sockaddr_storage*    source,
  int                         timeout);

LIFX_IMPORT void lxLog_Printf(
  lifxSession_t*  lifx,
  lifxLogLevel_t  level,
  const char*     format, ...) LIFX_PRINTF_FORMAT(3, 4);

LIFX_IMPORT void lifxDumpBuffer(lifxSession_t* lifx, uint8_t* p, int n);
LIFX_IMPORT void lifxSockaddr_ToString(struct sockaddr_storage* ss, char* buff, int n, uint16_t* port);

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
