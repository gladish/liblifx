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

#ifdef __GNUC__
#define lifxInterlockedIncrement(X) __atomic_fetch_add((X), 1, __ATOMIC_SEQ_CST)
#define lifxInterlockedDecrement(X) __atomic_fetch_sub((X), 1, __ATOMIC_SEQ_CST)
#else
#error "Implement me!"
#endif

struct lifxDevice;
struct lifxSession;
struct lifxMessage;
struct lifxDevice;

typedef struct lifxDevice lifxDevice_t;
typedef struct lifxSession lifxSession_t;
typedef struct lifxMessage lifxMessage_t;
typedef struct lifxDevice lifxDevice_t;

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
} lifxSessionConfig_t;

typedef struct
{
  uint8_t*  Data;
  int       Size;
  int       Position;
} lifxBuffer_t;

typedef enum
{
  kLifxBufferWhenceCurrent,
  kLifxBufferWhenceEnd,
  kLifxBufferWhenceSet
} lifxBufferWhence;

/**
 *
 */
int
lifxMessage_Retain(lifxMessage_t* m);

/**
 *
 */
int
lifxMessage_Release(lifxMessage_t* m);

/**
 *
 */
lifxProtocolHeader_t const* const
lifxMessage_GetHeader(lifxMessage_t const* m);

/**
 *
 */
lifxPacket_t const* const
lifxMessage_GetPacket(lifxMessage_t const* m);

/**
 *
 */
lifxDevice_t const* const
lifxMessage_GetDevice(lifxMessage_t const* m);

/**
 *
 */
lifxSession_t*
lifxSession_Create(lifxSessionConfig_t const* conf);

/**
 *
 */
void
lifxSession_Delete(lifxSession_t* lifx);

/**
 *
 */
int
lifxSession_SendTo(lifxSession_t*     lifx,
                   lifxDevice_t*      device,
                   void*              packet,
                   lifxPacketType_t   packet_type);

int
lifxSession_RecvFrom(lifxSession_t*   lifx,
                     lifxMessage_t**  message,
                     int              timeout);

int lifxBuffer_Init(lifxBuffer_t* buff, int n);
int lifxBuffer_Destroy(lifxBuffer_t* buff);
int lifxBuffer_Seek(lifxBuffer_t* buff, int offset, lifxBufferWhence whence);
int lifxBuffer_Write(lifxBuffer_t* buff, uint8_t const* data, int len);
int lifxBuffer_WriteUInt8(lifxBuffer_t* buff, uint8_t n);
int lifxBuffer_WriteBool(lifxBuffer_t* buff, bool b);
int lifxBuffer_WriteInt16(lifxBuffer_t* buff, int16_t n);
int lifxBuffer_WriteUInt16(lifxBuffer_t* buff, uint16_t n);
int lifxBuffer_WriteInt32(lifxBuffer_t* buff, int32_t n);
int lifxBuffer_WriteUInt32(lifxBuffer_t* buff, uint32_t n);
int lifxBuffer_WriteUInt64(lifxBuffer_t* buff, uint64_t n);
int lifxBuffer_WriteFloat(lifxBuffer_t* buff, float n);
int lifxBuffer_Read(lifxBuffer_t* buff, uint8_t* data, int len);
int lifxBuffer_ReadUInt8(lifxBuffer_t* buff, uint8_t* n);
int lifxBuffer_ReadInt16(lifxBuffer_t* buff, int16_t* n);
int lifxBuffer_ReadUInt16(lifxBuffer_t* buff, uint16_t* n);
int lifxBuffer_ReadInt32(lifxBuffer_t* buff, int32_t* n);
int lifxBuffer_ReadUInt32(lifxBuffer_t* buff, uint32_t* n);
int lifxBuffer_ReadUInt64(lifxBuffer_t* buff, uint64_t* n);
int lifxBuffer_ReadFloat(lifxBuffer_t* buff, float* f);
int lifxBuffer_ReadBool(lifxBuffer_t* buff, bool* b);

#ifdef __cplusplus
}
#endif

#endif
