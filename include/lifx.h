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

#include <lifx_common.h>
#include <lifx_enums.h>
#include <lifx_fields.h>
#include <lifx_packets.h>
#include <lifx_requests.h>

#ifdef __cplusplus
extern "C" {
#endif

static lifxDeviceId_t const kLifxDeviceAll = kLifxDeviceAllInitializer;
static lifxDeviceId_t const kLifxDeviceInvalid = kLifxDeviceInvalidInitializer;

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
} lifxProtocolHeader_t;
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
typedef struct
{
  lifxProtocolHeader_t  Header;
  lifxPacket_t          Packet;
} lifxMessage_t;

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

typedef void (*lifxDeviceDiscoveryHandler_t)(
  lifxSession_t const* lifx,
  lifxDeviceId_t deviceId);

/**
 *
 */
typedef struct
{
  char*                         BindInterface;
  lifxLogHandler_t              LogCallback;
  lifxLogLevel_t                LogLevel;
  bool                          UseBackgroundDispatchThread;
  lifxMessageHandler_t          MessageHandler;
  lifxDeviceDiscoveryHandler_t  DeviceDiscovered;
  bool                          ReportDuplicateDevices;
} lifxSessionConfig_t;


/**
 *
 */
typedef struct
{
  uint8_t*  Data;
  int       Size;
  int       Position;
} lifxBuffer_t;

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
LIFX_EXPORT char const* lifx_Version();

/**
 *
 */
LIFX_EXPORT lifxStatus_t lifxSessionConfig_Init(
  lifxSessionConfig_t*  conf);

/**
 *
 */
LIFX_EXPORT lifxSession_t* lifxSession_Open(
  lifxSessionConfig_t const*  conf);

/**
 *
 */
LIFX_EXPORT lifxStatus_t lifxSession_Close(
  lifxSession_t*        lifx);

/**
 *
 */
LIFX_EXPORT lifxStatus_t lifxSession_StartDiscovery(
  lifxSession_t*        lifx);

/**
 *
 */
LIFX_EXPORT lifxStatus_t lifxSession_StopDiscovery(
  lifxSession_t*        lifx);

/**
 *
 */
LIFX_EXPORT lifxStatus_t lifxSession_SendTo(
  lifxSession_t*        lifx,
  lifxDeviceId_t        device,
  void*                 packet,
  lifxPacketType_t      packetType);

/**
 */
LIFX_EXPORT lifxStatus_t lifxSession_RecvFrom(
  lifxSession_t*        lifx,
  lifxMessage_t*        message,
  int                   timeout);

/**
 *
 */
LIFX_EXPORT lifxFuture_t* lifxSession_BeginSendRequest(
  lifxSession_t*        lifx,
  lifxDeviceId_t        deviceId,
  void*                 request,
  lifxPacketType_t      packetType);

/**
 *
 */
LIFX_EXPORT lifxStatus_t lifxSession_SendRequest(
  lifxSession_t*        lifx,
  lifxDeviceId_t        deviceId,
  void*                 request,
  lifxPacketType_t      packetType,
  lifxPacket_t*         response,
  int                   millis);

/**
 *
 */
LIFX_EXPORT lifxStatus_t lifxSession_Dispatch(
  lifxSession_t*        lifx,
  int                   timeout);

/**
 *
 */
LIFX_EXPORT lifxStatus_t lifxSession_GetLastError(
  lifxSession_t*        lifx,
  char*                 buff,
  int                   n);

/**
 *
 */
LIFX_EXPORT int lifxDeviceId_Compare(
  lifxDeviceId_t const* deviceId1,
  lifxDeviceId_t const* deviceId2);

/**
 *
 */
LIFX_EXPORT lifxStatus_t lifxDeviceId_ToString(
  lifxDeviceId_t const* deviceId,
  char*                 buff,
  int                   n);

/**
 *
 */
LIFX_EXPORT lifxStatus_t lifxDeviceId_FromString(
  lifxDeviceId_t*       deviceId,
  char const*           buff);

/**
 *
 */
LIFX_EXPORT lifxStatus_t lifxFuture_Retain(
  lifxFuture_t*         future);

/**
 *
 */
LIFX_EXPORT lifxStatus_t lifxFuture_Release(
  lifxFuture_t*         future);

/**
 *
 */
LIFX_EXPORT lifxStatus_t lifxFuture_Wait(
  lifxFuture_t*         future,
  int                   millis);

/**
 *
 */
LIFX_EXPORT lifxStatus_t lifxFuture_Get(
  lifxFuture_t*         future,
  lifxPacket_t*         packet,
  int                   millis);

#ifdef __cplusplus
}
#endif
#endif
