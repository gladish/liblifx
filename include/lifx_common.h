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
#ifndef __LIFX_DEFINES_H__
#define __LIFX_DEFINES_H__

#include <stdint.h>

#define LIFX_EXPORT __attribute__ ((visibility ("default")))
#define LIFX_IMPORT __attribute__ ((visibility ("hidden")))

#define kLifxDefaultBroadcastPort (56700)
#define kLifxWaitForever (-1)
#define kLifxDeviceIdSize (6)
#define kLifxDeviceAllInitializer {{0, 0, 0, 0, 0, 0}}
#define kLifxDeviceInvalidInitializer {{0xff, 0xff, 0xff, 0xff, 0xff, 0xff}}
#define kLifxErrorMessageMaxLength (256)
#define kLifxRequestsMax (16)
#define kLifxMaxDevices (256)
#define kLifxSizeofHeader (sizeof(lifxProtocolHeader_t))
#define kLifxErrorMessageMax (256)

#ifdef __GNUC__
#define LIFX_PRINTF_FORMAT(IDX, FIRST) __attribute__ ((format (printf, IDX, FIRST)))
#define lifxInterlockedIncrement(X) __atomic_fetch_add((X), 1, __ATOMIC_SEQ_CST)
#define lifxInterlockedDecrement(X) __atomic_fetch_sub((X), 1, __ATOMIC_SEQ_CST)
#else
#define LIFX_PRINTF_FORMAT(IDX, FIRST)
#error "Not supported"
#endif

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


struct lifxSession;
struct lifxFuture;

typedef struct lifxSession lifxSession_t;
typedef struct lifxFuture lifxFuture_t;

typedef struct
{
  uint8_t Octets[kLifxDeviceIdSize];
} lifxDeviceId_t;

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
#endif
