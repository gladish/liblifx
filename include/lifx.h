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
#ifndef LIFX_H
#define LIFX_H

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

typedef struct
{
  uint32_t        ProductId;
  char const*     Name;
  struct {
    bool          Color;
    bool          Infrared;
    bool          Matrix;
    bool          Multizone;
    struct {
      uint16_t    Minimum;
      uint16_t    Maximum;
    } TemperatureRange;
    bool          Chain;
  } Features;
} lifxProductInformation_t;

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
} LIFX_PUBLIC lifxLogLevel_t;

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
  bool                          AutoResolveDevices;
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
} LIFX_PUBLIC lifxBufferWhence;

/**
 *
 */
LIFX_PUBLIC char const* lifx_Version();

/**
 *
 */
LIFX_PUBLIC lifxStatus_t lifxSessionConfig_Init(
  lifxSessionConfig_t*        conf);

/**
 *
 */
LIFX_PUBLIC lifxStatus_t lifxSessionConfig_InitWithDefaults(
  lifxSessionConfig_t*        conf);

/**
 *
 */
LIFX_PUBLIC lifxSession_t* lifxSession_Open(
  lifxSessionConfig_t const*  conf);

/**
 *
 */
LIFX_PUBLIC lifxStatus_t lifxSession_Close(
  lifxSession_t*        lifx);

/**
 *
 */
LIFX_PUBLIC lifxStatus_t lifxSession_StartDiscovery(
  lifxSession_t*        lifx);

/**
 *
 */
LIFX_PUBLIC lifxStatus_t lifxSession_StopDiscovery(
  lifxSession_t*        lifx);

/**
 *
 */
LIFX_PUBLIC lifxStatus_t lifxSession_SendTo(
  lifxSession_t*        lifx,
  lifxDeviceId_t        deviceId,
  void*                 packet,
  lifxPacketType_t      packetType);

/**
 */
LIFX_PUBLIC lifxStatus_t lifxSession_RecvFrom(
  lifxSession_t*        lifx,
  lifxMessage_t*        message,
  lifxTimeSpan_t        timeout);

/**
 *
 */
LIFX_PUBLIC lifxFuture_t* lifxSession_BeginSendRequest(
  lifxSession_t*        lifx,
  lifxDeviceId_t        deviceId,
  void const*           packet,
  lifxPacketType_t      packetType);

/**
 *
 */
LIFX_PUBLIC lifxStatus_t lifxSession_SendRequest(
  lifxSession_t*        lifx,
  lifxDeviceId_t        deviceId,
  void const*           request,
  lifxPacketType_t      packetType,
  lifxPacket_t*         response,
  lifxTimeSpan_t        timeout);

/**
 *
 */
LIFX_PUBLIC lifxStatus_t lifxSession_Dispatch(
  lifxSession_t*        lifx,
  lifxTimeSpan_t        timeout);

/**
 *
 */
LIFX_PUBLIC lifxStatus_t lifxSession_GetLastError(
  lifxSession_t*        lifx,
  char*                 buff,
  int                   n);

/**
 *
 */
LIFX_PUBLIC int lifxDeviceId_Compare(
  lifxDeviceId_t const* deviceId1,
  lifxDeviceId_t const* deviceId2);

/**
 *
 */
LIFX_PUBLIC lifxStatus_t lifxDeviceId_ToString(
  lifxDeviceId_t const* deviceId,
  char*                 buff,
  int                   n);

/**
 *
 */
LIFX_PUBLIC lifxStatus_t lifxDeviceId_FromString(
  lifxDeviceId_t*       deviceId,
  char const*           buff);

/**
 *
 */
LIFX_PUBLIC lifxStatus_t lifxFuture_Retain(
  lifxFuture_t*         future);

/**
 *
 */
LIFX_PUBLIC lifxStatus_t lifxFuture_Release(
  lifxFuture_t*         future);

/**
 *
 */
LIFX_PUBLIC lifxStatus_t lifxFuture_Wait(
  lifxFuture_t*         future,
  lifxTimeSpan_t        timeout);

/**
 *
 */
LIFX_PUBLIC lifxStatus_t lifxFuture_Get(
  lifxFuture_t*         future,
  lifxPacket_t*         packet,
  lifxTimeSpan_t        timeout);

/**
 *
 */
LIFX_PUBLIC lifxTimeSpan_t lifxTimeSpan_FromMilliseconds(uint64_t millis);

/**
 *
 */
LIFX_PUBLIC lifxTimeSpan_t lifxTimeSpan_FromSeconds(uint64_t seconds);

/**
 *
 */
LIFX_PUBLIC lifxDateTime_t lifxDateTime_Now();

/**
 *
 */
LIFX_PUBLIC lifxDateTime_t lifxDateTime_Add(
  lifxDateTime_t date_time,
  lifxTimeSpan_t time_span);

/**
 *
 */
LIFX_PUBLIC lifxTimeSpan_t lifxDateTime_Subtract(
  lifxDateTime_t now,
  lifxDateTime_t then);

#ifdef __cplusplus
}
#endif
#endif
