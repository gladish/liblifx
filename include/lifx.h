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
#ifndef __LIFX_H__
#define __LIFX_H__

#include <lifx_enums.h>
#include <lifx_fields.h>
#include <lifx_packets.h>

#ifdef __cplusplus
extern "C" {
#endif

#define LIFX_IMPORT __attribute__ ((visibility ("internal")))
#define LIFX_EXPORT __attribute__ ((visibility ("default")))

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

#ifdef __GNUC__
#define lifxInterlockedIncrement(X) __atomic_fetch_add((X), 1, __ATOMIC_SEQ_CST)
#define lifxInterlockedDecrement(X) __atomic_fetch_sub((X), 1, __ATOMIC_SEQ_CST)
#else
#error "Implement me!"
#endif

#define kLifxDefaultBroadcastPort (56700)
#define kLifxWaitForever (-1)
#define kLifxDeviceIdSize (6)
#define kLifxDeviceAllInitializer {{0, 0, 0, 0, 0, 0}}
#define kLifxDeviceInvalidInitializer {{0xff, 0xff, 0xff, 0xff, 0xff, 0xff}}

struct lifxSession;
typedef struct lifxSession lifxSession_t;

typedef struct
{
  uint8_t Octets[kLifxDeviceIdSize];
} lifxDeviceId_t;

static lifxDeviceId_t const kLifxDeviceAll = kLifxDeviceAllInitializer;
static lifxDeviceId_t const kLifxDeviceInvalid = kLifxDeviceInvalidInitializer;

int lifxDeviceId_Compare(lifxDeviceId_t const* a, lifxDeviceId_t const* b);

#pragma pack(push, 1)
typedef struct
{
  // frame
  uint16_t  Size;
  uint16_t  Protocol:12;
  uint8_t   Addressable:1;
  uint8_t   Tagged:1;
  uint8_t   Origin:2;
  uint32_t  Source;

  // frame address
  uint8_t   Target[8];
  uint8_t   Reserved[6];
  uint8_t   ResRequired:1;
  uint8_t   AckRequired:1;
  uint8_t   :6;
  uint8_t   Sequence;

  // protocol header
  uint64_t  :64;
  uint16_t  Type;
  uint16_t  :16;
} LIFX_EXPORT lifxProtocolHeader_t;
#pragma pack(pop)

/**
 *
 */
typedef enum
{
  kLifxLogLevelDebug = 0,
  kLifxLogLevelInfo = 1,
  kLifxLogLevelWarn = 2,
  kLifxLogLevelError = 3,
  kLifxLogLevelFatal = 4
} LIFX_EXPORT lifxLogLevel_t;

/**
 *
 */
LIFX_EXPORT char const* lifx_Version();

/**
 *
 */
typedef struct
{
  lifxProtocolHeader_t  Header;
  lifxPacket_t          Packet;
} LIFX_EXPORT lifxMessage_t;

/**
 *
 */
typedef void (*lifxLogHandler_t)(
  lifxSession_t const*  lifx,
  lifxLogLevel_t level,
  char const* message);

typedef void (*lifxMessageHandler_t)(
  lifxSession_t const* lifx,
  lifxMessage_t const* const message,
  lifxDeviceId_t device);

/**
 *
 */
typedef struct
{
  char*                 BindInterface;
  lifxLogHandler_t      LogCallback;
  lifxLogLevel_t        LogLevel;
  bool                  UseBackgroundDispatchThread;
  lifxMessageHandler_t  MessageHandler;
  bool                  ReportDuplicateDevices;
} LIFX_EXPORT lifxSessionConfig_t;

/**
 *
 */
typedef struct
{
  uint8_t*  Data;
  int       Size;
  int       Position;
} LIFX_EXPORT lifxBuffer_t;

/**
 *
 */
typedef enum
{
  kLifxBufferWhenceCurrent,
  kLifxBufferWhenceEnd,
  kLifxBufferWhenceSet
} LIFX_EXPORT lifxBufferWhence;

/**
 *
 */
LIFX_EXPORT lifxSession_t* lifxSession_Open(lifxSessionConfig_t const* conf);

/**
 *
 */
LIFX_EXPORT int lifxSession_Close(lifxSession_t* lifx);

/**
 *
 */
LIFX_EXPORT int lifxSession_SendTo(
  lifxSession_t*     lifx,
  lifxDeviceId_t     device,
  void*              packet,
  lifxPacketType_t   packet_type);

/**
 */
LIFX_EXPORT int lifxSession_RecvFrom(
  lifxSession_t*   lifx,
  lifxMessage_t*   message,
  int              timeout);

/**
 *
 */
LIFX_EXPORT int lifxSession_Dispatch(
  lifxSession_t* lifx,
  int timeout);

LIFX_EXPORT int lifxBuffer_Init(lifxBuffer_t* buff, int n);
LIFX_EXPORT int lifxBuffer_Destroy(lifxBuffer_t* buff);
LIFX_EXPORT int lifxBuffer_Seek(lifxBuffer_t* buff, int offset, lifxBufferWhence whence);
LIFX_EXPORT int lifxBuffer_Write(lifxBuffer_t* buff, void const* data, int len);
LIFX_EXPORT int lifxBuffer_WriteUInt8(lifxBuffer_t* buff, uint8_t n);
LIFX_EXPORT int lifxBuffer_WriteBool(lifxBuffer_t* buff, bool b);
LIFX_EXPORT int lifxBuffer_WriteInt16(lifxBuffer_t* buff, int16_t n);
LIFX_EXPORT int lifxBuffer_WriteUInt16(lifxBuffer_t* buff, uint16_t n);
LIFX_EXPORT int lifxBuffer_WriteInt32(lifxBuffer_t* buff, int32_t n);
LIFX_EXPORT int lifxBuffer_WriteUInt32(lifxBuffer_t* buff, uint32_t n);
LIFX_EXPORT int lifxBuffer_WriteUInt64(lifxBuffer_t* buff, uint64_t n);
LIFX_EXPORT int lifxBuffer_WriteFloat(lifxBuffer_t* buff, float n);
LIFX_EXPORT int lifxBuffer_Read(lifxBuffer_t* buff, void* data, int len);
LIFX_EXPORT int lifxBuffer_ReadUInt8(lifxBuffer_t* buff, uint8_t* n);
LIFX_EXPORT int lifxBuffer_ReadInt16(lifxBuffer_t* buff, int16_t* n);
LIFX_EXPORT int lifxBuffer_ReadUInt16(lifxBuffer_t* buff, uint16_t* n);
LIFX_EXPORT int lifxBuffer_ReadInt32(lifxBuffer_t* buff, int32_t* n);
LIFX_EXPORT int lifxBuffer_ReadUInt32(lifxBuffer_t* buff, uint32_t* n);
LIFX_EXPORT int lifxBuffer_ReadUInt64(lifxBuffer_t* buff, uint64_t* n);
LIFX_EXPORT int lifxBuffer_ReadFloat(lifxBuffer_t* buff, float* f);
LIFX_EXPORT int lifxBuffer_ReadBool(lifxBuffer_t* buff, bool* b);

#ifdef __cplusplus
}
#endif

#endif
