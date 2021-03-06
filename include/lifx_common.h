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
#ifndef LIFX_COMMON_H
#define LIFX_COMMON_H

#include <stdint.h>

#if defined(LIFX_PLATFORM_WINDOWS)
#ifdef LIFX_BUILDING_SHARED_LIBRARY
#define LIFX_PUBLIC   __declspec(dllexport)
#define LIFX_PRIVATE
#else
#define LIFX_PUBLIC   __declspec(dllimport)
#define LIFX_PRIVATE "Error --"
#endif
#else
#define LIFX_PUBLIC   __attribute__ ((visibility ("default")))
#define LIFX_PRIVATE  __attribute__ ((visibility ("hidden")))
#endif

#define kLifxDefaultBroadcastPort (56700)
#define kLifxDeviceIdSize (6)
#define kLifxDeviceAllInitializer {{0, 0, 0, 0, 0, 0}}
#define kLifxDeviceInvalidInitializer {{0xff, 0xff, 0xff, 0xff, 0xff, 0xff}}
#define kLifxErrorMessageMaxLength (256)
#define kLifxRequestsMax (16)
#define kLifxMaxDevices (256)
#define kLifxSizeofHeader (36)
#define kLifxErrorMessageMax (256)
#define kLifxDeviceDatabaseBucketCount (1)

#define kLifxLightPowerLevelOn 65535
#define kLifxLightPowerLevelOff 0

struct lifxSession;
struct lifxFuture;

typedef struct lifxSession lifxSession_t;
typedef struct lifxFuture lifxFuture_t;

/**
 *
 */
typedef struct
{
  uint8_t Octets[kLifxDeviceIdSize];
} lifxDeviceId_t;

/**
 * Relative time in microseconds
 */
typedef struct
{
  uint64_t _ticks;
} lifxTimeSpan_t;

/**
 * Time since epoch in microseconds
 */
typedef uint64_t lifxDateTime_t;

/**
 *
 */
typedef struct
{
  lifxTimeSpan_t  Timeout;
  int             RetryCount;
} lifxRequestOptions_t;

/**
 *
 */
typedef enum
{
  kLifxStatusOk = 0,
  kLifxStatusOperationTimedout,
  kLifxStatusInvalidArgument,
  kLifxStatusPermissionDenied,
  kLifxStatusUnknownDevice,
  kLifxStatusNotEnoughMemory,
  kLifxStatusFailed
} lifxStatus_t;

#endif
