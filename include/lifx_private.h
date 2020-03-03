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
#ifndef LIFX_PRIVATE_H
#define LIFX_PRIVATE_H

#include "lifx.h"

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

#if defined(LIFX_PLATFORM_LINUX) || defined(LIFX_PLATFORM_MACOSX)
#include <assert.h>
#include <errno.h>
#include <netinet/in.h>
#include <pthread.h>
#include <sys/socket.h>
// errno
typedef int lifxSystemError_t; 
typedef pthread_t lifxThread_t;
typedef pthread_mutex_t lifxMutex_t;
typedef pthread_cond_t lifxCond_t;
typedef void* (lifxThreadFunc_t)(void*);
#define LIFX_ASSERT(X) assert((X))
#else
#error "Not implemented"
#endif

#ifdef LIFX_PLATFORM_MACOSX
#include <libkern/OSByteOrder.h>
#define lifxHostToLittleInt16(n) OSSwapHostToLittleInt16(n)
#define lifxLittleToHostInt16(n) OSSwapHostToLittleInt16(n)
#define lifxHostToLittleInt32(n) OSSwapHostToLittleInt32(n)
#define lifxLittleToHostInt32(n) OSSwapHostToLittleInt32(n)
#define lifxHostToLittleInt64(n) OSSwapHostToLittleInt64(n)
#define lifxLittleToHostInt64(n) OSSwapHostToLittleInt64(n)
#elif LIFX_PLATFORM_LINUX
#include <endian.h>
#define lifxHostToLittleInt16(n) htole16(n)
#define lifxLittleToHostInt16(n) le16toh(n)
#define lifxHostToLittleInt32(n) htole32(n)
#define lifxLittleToHostInt32(n) le32toh(n)
#define lifxHostToLittleInt64(n) htole64(n)
#define lifxLittleToHostInt64(n) le64toh(n)
#else
#error "Not implemented"
#endif

/**
 *
 */
LIFX_PRIVATE lifxSystemError_t lifxError_GetSystemError();

/**
 *
 */
LIFX_PRIVATE void lifxThread_Create(
  lifxThread_t*           thread,
  lifxThreadFunc_t        startRoutine,
  void*                   argp);

/**
 *
 */
LIFX_PRIVATE void lifxMutex_Init(
  lifxMutex_t*            mutex);

/**
 *
 */
LIFX_PRIVATE void lifxMutex_Destroy(
  lifxMutex_t*            mutex);

/**
 *
 */
LIFX_PRIVATE void lifxMutex_Lock(
  lifxMutex_t*            mutex);

/**
 *
 */
LIFX_PRIVATE void lifxMutex_Unlock(
  lifxMutex_t*            mutex);

/**
 *
 */
LIFX_PRIVATE void lifxCond_Init(
  lifxCond_t*             cond);

/**
 *
 */
LIFX_PRIVATE void lifxCond_Destroy(
  lifxCond_t*             cond);

/**
 *
 */
LIFX_PRIVATE void lifxCond_NotifyAll(
  lifxCond_t*             cond);
  

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxCond_TimedWait(
  lifxCond_t*             cond,
  lifxMutex_t*            mutex,
  lifxTimeSpan_t          timeout);

/**
 *
 */
struct lifxDevice
{
  lifxDeviceId_t          DeviceId; 
  struct sockaddr_storage Endpoint;
};

typedef uint8_t lifxSequence_t;
typedef struct lifxDevice lifxDevice_t;

struct lifxFuture
{
  lifxMutex_t             Mutex;
  lifxCond_t              Cond;
  lifxPacket_t            Result;
  lifxStatus_t            Status;
  int                     ReferenceCount;
  bool                    Complete;
  lifxSequence_t          SequenceNumber;
};

typedef struct
{
  lifxProductInformation_t** LifxPrecompiledDB;
} lifxProductInfoDB_t;

struct lifxSession
{
  int                     Socket;
  uint32_t                SourceId;
  uint8_t                 SequenceNumber;
  lifxBuffer_t            ReadBuffer;
  lifxBuffer_t            WriteBuffer;
  lifxThread_t            BackgroundDispatchThread;
  lifxMutex_t             SessionLock;
  lifxDevice_t*           DeviceDatabase[kLifxMaxDevices];
  lifxSessionConfig_t     Config;
  bool                    RunDiscovery;
  lifxFuture_t*           OutstandingRequests[kLifxRequestsMax];
  lifxStatus_t            LastError;
  char                    LastErrorMessage[256];
  lifxProductInfoDB_t     ProductInfoDB;
};

/**
 *
 */
LIFX_PRIVATE int lifxSessionConfig_Copy(
  lifxSessionConfig_t* dest,
  lifxSessionConfig_t const* src);

/**
 *
 */
LIFX_PRIVATE char const* lifxError_ToString(
  lifxSystemError_t               system_error);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxSession_SetLastError(
  lifxSession_t*                  lifx,
  lifxStatus_t                    status,
  char const*                     format, ...) LIFX_PRINTF_FORMAT(3, 4);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxSession_RegisterRequest(
  lifxSession_t*                  lifx,
  lifxFuture_t*                   future);

/**
 *
 */
LIFX_PRIVATE lifxDevice_t* lifxSession_FindDevice(
  lifxSession_t*                  lifx,
  lifxDeviceId_t                  deviceId);

/**
 *
 */
LIFX_PRIVATE lifxDevice_t* lifxSession_CreateDevice(
  lifxSession_t*                  lifx,
  lifxMessage_t const*            message,
  struct sockaddr_storage const*  source_address);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxSession_RecvFromInternal(
  lifxSession_t*                  lifx,
  lifxMessage_t*                  message,
  struct sockaddr_storage*        source,
  lifxTimeSpan_t                  timeout);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxSession_SendToInternal(
  lifxSession_t*                  lifx,
  lifxDeviceId_t                  deviceId,
  void const*                     packet,
  lifxPacketType_t                packetType,
  uint8_t                         seqno);

/**
 *
 */
LIFX_PRIVATE lifxFuture_t* lifxFuture_Create(
  lifxSequence_t                  sequence_number);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxFuture_SetComplete(
  lifxFuture_t*                   future,
  lifxStatus_t                    status,
  lifxPacket_t*                   packet);

/**
 *
 */
LIFX_PRIVATE void lifxDumpBuffer(
  lifxSession_t*                  lifx,
  uint8_t*                        p,
  int                             n);

/**
 *
 */
LIFX_PRIVATE void lifxSockaddr_ToString(
  struct sockaddr_storage const*  socket_address,
  char*                           buff,
  int                             n,
  uint16_t*                       port);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_Init(
  lifxBuffer_t*                   buff,
  int                             n);


/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_Destroy(
  lifxBuffer_t*                   buff);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_Seek(
  lifxBuffer_t*                   buff,
  int                             offset,
  lifxBufferWhence                whence);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_Write(
  lifxBuffer_t*                   buff,
  void const*                     data,
  int                             n);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_WriteUInt8(
  lifxBuffer_t*                   buff,
  uint8_t                         n);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_WriteBool(
  lifxBuffer_t*                   buff,
  bool                            b);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_WriteInt16(
  lifxBuffer_t*                   buff,
  int16_t                         n);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_WriteUInt16(
  lifxBuffer_t*                   buff,
  uint16_t                        n);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_WriteInt32(
  lifxBuffer_t*                   buff,
  int32_t                         n);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_WriteUInt32(
  lifxBuffer_t*                   buff,
  uint32_t                        n);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_WriteUInt64(
  lifxBuffer_t*                   buff,
  uint64_t                        n);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_WriteFloat(
  lifxBuffer_t*                   buff, 
  float                           n);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_Read(
  lifxBuffer_t*                   buff,
  void*                           data,
  int                             n);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_ReadUInt8(
  lifxBuffer_t*                   buff,
  uint8_t*                        n);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_ReadInt16(
  lifxBuffer_t*                   buff,
  int16_t*                        n);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_ReadUInt16(
  lifxBuffer_t*                   buff,
  uint16_t*                       n);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_ReadInt32(
  lifxBuffer_t*                   buff,
  int32_t*                        n);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_ReadUInt32(
  lifxBuffer_t*                   buff,
  uint32_t*                       n);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_ReadUInt64(
  lifxBuffer_t*                   buff,
  uint64_t*                       n);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_ReadFloat(
  lifxBuffer_t*                   buff,
  float*                          f);

/**
 *
 */
LIFX_PRIVATE lifxStatus_t lifxBuffer_ReadBool(
  lifxBuffer_t*                   buff,
  bool*                           b);

/**
 *
 */
LIFX_PRIVATE void lxLog_Printf(
  lifxSession_t*                  lifx,
  lifxLogLevel_t                  level,
  const char*                     format, ...) LIFX_PRINTF_FORMAT(3, 4);

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
