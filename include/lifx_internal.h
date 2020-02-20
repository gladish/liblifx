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

#define LIFX_IMPORT __attribute__ ((visibility ("internal")))

#ifdef __APPLE__
#include <libkern/OSByteOrder.h>
#define lifxHostToLittleInt16(n) OSSwapHostToLittleInt16(n)
#define lifxLittleToHostInt16(n) OSSwapHostToLittleInt16(x)
#define lifxHostToLittleInt32(n) OSSwapHostToLittleInt32(n)
#define lifxLittleToHostInt32(n) OSSwapHostToLittleInt32(x)
#define lifxHostToLittleInt64(n) OSSwapHostToLittleInt64(n)
#define lifxLittleToHostInt64(n) OSSwapHostToLittleInt64(x)
#else
#include <endian.h>
#define lifxHostToLittleInt16(n) htole16(n)
#define lifxLittleToHostInt16(n) le16toh(n)
#define lifxHostToLittleInt32(n) htole32(n)
#define lifxLittleToHostInt32(n) le32toh(n)
#define lifxHostToLittleInt64(n) htole64(n)
#define lifxLittleToHostInt64(n) le64toh(n)
#endif

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
#define kLifxRequestsMax (16)
#define kLifxMaxDevices (256)
#define kLifxSizeofHeader (sizeof(lifxProtocolHeader_t))


LIFX_IMPORT struct lifxDevice
{
  lifxDeviceId_t          DeviceId; 
  struct sockaddr_storage Endpoint;
};

typedef uint8_t lifxSequence_t;
typedef struct lifxDevice lifxDevice_t;

LIFX_IMPORT struct lifxFuture
{
  pthread_mutex_t         Mutex;
  pthread_cond_t          Cond;
  lifxPacket_t            Result;
  int                     ErrorCode;
  int                     ReferenceCount;
  bool                    Complete;
  lifxSequence_t          SequenceNumber;
};


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
  lifxFuture_t*           OutstandingRequests[kLifxRequestsMax];
};

/**
 *
 */
LIFX_IMPORT int lifxSessionConfig_Copy(
  lifxSessionConfig_t* dest,
  lifxSessionConfig_t const* src);

/**
 *
 */
LIFX_IMPORT char const* lifxError_ToString(int errnum);

/**
 *
 */
LIFX_IMPORT int lifxSession_RegisterRequest(
  lifxSession_t*  lifx,
  lifxFuture_t*   future);

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

/**
 *
 */
LIFX_IMPORT int lifxSession_RecvFromInternal(
  lifxSession_t*              lifx,
  lifxMessage_t*              message,
  struct sockaddr_storage*    source,
  int                         timeout);

/**
 *
 */
LIFX_IMPORT int lifxSession_SendToInternal(
  lifxSession_t*              lifx,
  lifxDeviceId_t              deviceId,
  void*                       packet,
  lifxPacketType_t            packetType,
  uint8_t                     seqno);

LIFX_IMPORT lifxFuture_t* lifxFuture_Create(lifxSequence_t seqno);
LIFX_IMPORT int lifxFuture_SetComplete(lifxFuture_t* f, int error, lifxPacket_t* p);
LIFX_IMPORT void lifxDumpBuffer(lifxSession_t* lifx, uint8_t* p, int n);
LIFX_IMPORT void lifxSockaddr_ToString(struct sockaddr_storage* ss, char* buff, int n, uint16_t* port);

LIFX_IMPORT int lifxBuffer_Init(lifxBuffer_t* buff, int n);
LIFX_IMPORT int lifxBuffer_Destroy(lifxBuffer_t* buff);
LIFX_IMPORT int lifxBuffer_Seek(lifxBuffer_t* buff, int offset, lifxBufferWhence whence);
LIFX_IMPORT int lifxBuffer_Write(lifxBuffer_t* buff, void const* data, int n);
LIFX_IMPORT int lifxBuffer_WriteUInt8(lifxBuffer_t* buff, uint8_t n);
LIFX_IMPORT int lifxBuffer_WriteBool(lifxBuffer_t* buff, bool b);
LIFX_IMPORT int lifxBuffer_WriteInt16(lifxBuffer_t* buff, int16_t n);
LIFX_IMPORT int lifxBuffer_WriteUInt16(lifxBuffer_t* buff, uint16_t n);
LIFX_IMPORT int lifxBuffer_WriteInt32(lifxBuffer_t* buff, int32_t n);
LIFX_IMPORT int lifxBuffer_WriteUInt32(lifxBuffer_t* buff, uint32_t n);
LIFX_IMPORT int lifxBuffer_WriteUInt64(lifxBuffer_t* buff, uint64_t n);
LIFX_IMPORT int lifxBuffer_WriteFloat(lifxBuffer_t* buff, float n);
LIFX_IMPORT int lifxBuffer_Read(lifxBuffer_t* buff, void* data, int n);
LIFX_IMPORT int lifxBuffer_ReadUInt8(lifxBuffer_t* buff, uint8_t* n);
LIFX_IMPORT int lifxBuffer_ReadInt16(lifxBuffer_t* buff, int16_t* n);
LIFX_IMPORT int lifxBuffer_ReadUInt16(lifxBuffer_t* buff, uint16_t* n);
LIFX_IMPORT int lifxBuffer_ReadInt32(lifxBuffer_t* buff, int32_t* n);
LIFX_IMPORT int lifxBuffer_ReadUInt32(lifxBuffer_t* buff, uint32_t* n);
LIFX_IMPORT int lifxBuffer_ReadUInt64(lifxBuffer_t* buff, uint64_t* n);
LIFX_IMPORT int lifxBuffer_ReadFloat(lifxBuffer_t* buff, float* f);
LIFX_IMPORT int lifxBuffer_ReadBool(lifxBuffer_t* buff, bool* b);

/**
 *
 */
LIFX_IMPORT void lxLog_Printf(
  lifxSession_t*  lifx,
  lifxLogLevel_t  level,
  const char*     format, ...) LIFX_PRINTF_FORMAT(3, 4);

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
