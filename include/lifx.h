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
#define lifxLittleToHostInt16(n) letoh16(n)
#define lifxHostToLittleInt32(n) htole32(n)
#define lifxLittleToHostInt32(n) le32toh(n)
#define lifxHostToLittleInt64(n) htole64(n)
#define lifxLittleToHostInt64(n) le64toh(n)
#endif

struct lifxDevice;
struct lifxSession;

typedef struct lifxDevice lifxDevice_t;
typedef struct lifxSession lifxSession_t;

typedef struct
{
} lifxSessionConfig_t;

lifxSession_t* lifxSession_Create(lifxSessionConfig_t const* conf);

void lifxSession_Delete(lifxSession_t* lifx);

int  lifxSession_SendTo(
  lifxSession_t*    lifx,
  lifxDevice_t*     device,
  void*             packet,
  lifxPacketType_t  packet_type);


typedef struct
{
  uint8_t*  data;
  int       size;
  int       pos;
} lifxBuffer_t;

typedef enum
{
  kLifxBufferWhenceCurrent,
  kLifxBufferWhenceEnd,
  kLifxBufferWhenceSet
} lifxBufferWhence;

int lifxBufferInit(lifxBuffer_t* buff, int n);
int lifxBufferDestroy(lifxBuffer_t* buff);
int lifxBufferSeek(lifxBuffer_t* buff, int offset, lifxBufferWhence whence);
int lifxBufferWrite(lifxBuffer_t* buff, uint8_t const* data, int len);
int lifxBufferWriteUInt8(lifxBuffer_t* buff, uint8_t n);
int lifxBufferWriteInt16(lifxBuffer_t* buff, int16_t n);
int lifxBufferWriteUInt16(lifxBuffer_t* buff, uint16_t n);
int lifxBufferWriteInt32(lifxBuffer_t* buff, int32_t n);
int lifxBufferWriteUInt32(lifxBuffer_t* buff, uint32_t n);
int lifxBufferWriteUInt64(lifxBuffer_t* buff, uint64_t n);
int lifxBufferWriteFloat(lifxBuffer_t* buff, float n);



#ifdef __cplusplus
}
#endif

#endif
