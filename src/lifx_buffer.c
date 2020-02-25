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
#include "lifx.h"
#include "lifx_private.h"

#include <stdlib.h>
#include <string.h>

#define LIFX_NULLCHECK(X) if ((X) == NULL) return kLifxStatusInvalidArgument

lifxStatus_t lifxBuffer_Init(lifxBuffer_t* buff, int n)
{
  LIFX_NULLCHECK(buff);

  if (n == 0)
  {
    buff->Data = NULL;
    buff->Size = 0;
  }
  else
  {
    buff->Data = malloc(n);
    if (!buff->Data)
      return kLifxStatusNotEnoughMemory;
    memset(buff->Data, 0, n);
    buff->Size = n;
  }

  buff->Position = 0;
  return 0;
}

lifxStatus_t lifxBuffer_Destroy(lifxBuffer_t* buff)
{
  LIFX_NULLCHECK(buff);

  if (buff->Data)
    free(buff->Data);
  buff->Data = NULL;
  buff->Size = 0;
  buff->Position = 0;
  return kLifxStatusOk;
}

lifxStatus_t lifxBuffer_Seek(lifxBuffer_t* buff, int offset, lifxBufferWhence whence)
{
  LIFX_NULLCHECK(buff);

  int const max_index = buff->Size - 1;
  int const min_index = 0;
  int new_index = 0;

  switch (whence)
  {
    case kLifxBufferWhenceCurrent:
    new_index = buff->Position + offset;
    break;

    case kLifxBufferWhenceEnd:
    new_index = max_index + offset;
    break;

    case kLifxBufferWhenceSet:
    new_index = offset;
    break;
  }

  if ((new_index < min_index) || (new_index > max_index))
    return kLifxStatusInvalidArgument;

  buff->Position = new_index;
  return kLifxStatusOk;
}

lifxStatus_t lifxBuffer_Write(lifxBuffer_t* buff, void const* data, int n)
{
  LIFX_NULLCHECK(buff);
  memcpy(&buff->Data[buff->Position], data, n);
  buff->Position += n;
  return kLifxStatusOk;
}

lifxStatus_t lifxBuffer_WriteInt8(lifxBuffer_t* buff, int8_t n)
{
  return lifxBuffer_Write(buff, &n, 1);
}

lifxStatus_t lifxBuffer_WriteUInt8(lifxBuffer_t* buff, uint8_t n)
{
  return lifxBuffer_Write(buff, &n, 1);
}

lifxStatus_t lifxBuffer_WriteInt16(lifxBuffer_t* buff, int16_t n)
{
  int16_t temp = lifxHostToLittleInt16(n);
  return lifxBuffer_Write(buff, &temp, 2);
}

lifxStatus_t lifxBuffer_WriteUInt16(lifxBuffer_t* buff, uint16_t n)
{
  uint16_t temp = lifxHostToLittleInt16(n);
  return lifxBuffer_Write(buff, &temp, 2);
}

lifxStatus_t lifxBuffer_WriteInt32(lifxBuffer_t* buff, int32_t n)
{
  int32_t temp = lifxHostToLittleInt32(n);
  return lifxBuffer_Write(buff, &temp, 4);
}

lifxStatus_t lifxBuffer_WriteUInt32(lifxBuffer_t* buff, uint32_t n)
{
  uint32_t temp = lifxHostToLittleInt32(n);
  return lifxBuffer_Write(buff, &temp, 4);
}

lifxStatus_t lifxBuffer_WriteUInt64(lifxBuffer_t* buff, uint64_t n)
{
  uint64_t temp = lifxHostToLittleInt64(n);
  return lifxBuffer_Write(buff, &temp, 8);
}

lifxStatus_t lifxBuffer_WriteFloat(lifxBuffer_t* buff, float n)
{
  uint32_t temp = lifxHostToLittleInt32((uint32_t)n);
  return lifxBuffer_Write(buff, &temp, 4);
}

lifxStatus_t lifxBuffer_WriteBool(lifxBuffer_t* buff, bool b)
{
  uint8_t n = (b == true ? 1 : 0);
  return lifxBuffer_WriteUInt8(buff, n);
}

lifxStatus_t lifxBuffer_Read(lifxBuffer_t* buff, void* data, int n)
{
  LIFX_NULLCHECK(buff);
  LIFX_NULLCHECK(data);
  memcpy(data, &buff->Data[buff->Position], n);
  buff->Position += n;
  return 0;
}

lifxStatus_t lifxBuffer_ReadFloat(lifxBuffer_t* buff, float* f)
{
  LIFX_NULLCHECK(f);

  uint32_t temp;
  lifxStatus_t status = lifxBuffer_Read(buff, &temp, sizeof(uint32_t));
  if (status == 0)
    *f = (float) lifxLittleToHostInt32(temp);
  return status;
}

lifxStatus_t lifxBuffer_ReadUInt64(lifxBuffer_t* buff, uint64_t* n)
{
  lifxStatus_t status = lifxBuffer_Read(buff, n, sizeof(uint64_t));
  if (status == kLifxStatusOk)
    *n = lifxLittleToHostInt64(*n);
  return status;
}

lifxStatus_t lifxBuffer_ReadUInt32(lifxBuffer_t* buff, uint32_t* n)
{
  lifxStatus_t status = lifxBuffer_Read(buff, n, sizeof(uint32_t));
  if (status == kLifxStatusOk)
    *n = lifxLittleToHostInt32(*n);
  return status;
}

lifxStatus_t lifxBuffer_ReadInt16(lifxBuffer_t* buff, int16_t* n)
{
  lifxStatus_t status = lifxBuffer_Read(buff, n, sizeof(int16_t));
  if (status == kLifxStatusOk)
    *n = lifxLittleToHostInt16(*n);
  return status;
}

lifxStatus_t lifxBuffer_ReadUInt16(lifxBuffer_t* buff, uint16_t* n)
{
  lifxStatus_t status = lifxBuffer_Read(buff, n, sizeof(uint16_t));
  if (status == kLifxStatusOk)
    *n = lifxLittleToHostInt16(*n);
  return status;
}

lifxStatus_t lifxBuffer_ReadUInt8(lifxBuffer_t* buff, uint8_t* n)
{
  return lifxBuffer_Read(buff, n, sizeof(uint8_t));
}

lifxStatus_t lifxBuffer_ReadBool(lifxBuffer_t* buff, bool* b)
{
  uint8_t n;
  lifxStatus_t status = lifxBuffer_ReadUInt8(buff, &n);
  if (status == kLifxStatusOk)
    *b = (n != 0 ? true : false);
  return status;
}
