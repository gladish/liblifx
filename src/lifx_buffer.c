
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

#include <errno.h>
#include <stdlib.h>
#include <string.h>

int
lifxBuffer_Init(lifxBuffer_t* buff, int n)
{
  if (!buff)
    return EINVAL;

  if (n == 0)
  {
    buff->Data = NULL;
    buff->Size = 0;
  }
  else
  {
    buff->Data = malloc(n * sizeof(uint8_t));
    if (!buff->Data)
      return ENOMEM;
    buff->Size = n;
  }

  buff->Position = 0;
  return 0;
}

int
lifxBuffer_Destroy(lifxBuffer_t* buff)
{
  if (!buff)
    return EINVAL;
  if (buff->Data)
    free(buff->Data);
  buff->Data = NULL;
  buff->Size = 0;
  buff->Position = 0;
  return 0;
}

int
lifxBuffer_Seek(lifxBuffer_t* buff, int offset, lifxBufferWhence whence)
{
  // TODO: finish this
  switch (whence)
  {
    case kLifxBufferWhenceCurrent:
    buff->Position += offset;
    break;

    case kLifxBufferWhenceEnd:
    break;

    case kLifxBufferWhenceSet:
    break;
  }

  return 0;
}

int
lifxBuffer_Write(lifxBuffer_t* buff, uint8_t const* data, int len)
{
  int i;
  for (i = 0; i < len; ++i)
  {
    buff->Data[buff->Position++] = data[i];
  }
  return 0;
}

int
lifxBuffer_WriteInt8(lifxBuffer_t* buff, int8_t n)
{
  buff->Data[buff->Position++] = n;
  return 0;
}

int
lifxBuffer_WriteUInt8(lifxBuffer_t* buff, uint8_t n)
{
  buff->Data[buff->Position++] = n;
  return 0;
}

int
lifxBuffer_WriteInt16(lifxBuffer_t* buff, int16_t n)
{
  n = lifxHostToLittleInt16(n);
  memcpy(&(buff->Data[buff->Position]), &n, 2);
  buff->Position += 2;
  return 0;
}

int
lifxBuffer_WriteUInt16(lifxBuffer_t* buff, uint16_t n)
{
  n = lifxHostToLittleInt16(n);
  memcpy(&(buff->Data[buff->Position]), &n, 2);
  buff->Position += 2;
  return 0;
}

int
lifxBuffer_WriteInt32(lifxBuffer_t* buff, int32_t n)
{
  n = lifxHostToLittleInt32(n);
  memcpy(&(buff->Data[buff->Position]), &n, 4);
  buff->Position += 4;
  return 0;
}

int
lifxBuffer_WriteUInt32(lifxBuffer_t* buff, uint32_t n)
{
  n = lifxHostToLittleInt32(n);
  memcpy(&(buff->Data[buff->Position]), &n, 4);
  buff->Position += 4;
  return 0;
}

int
lifxBuffer_WriteUInt64(lifxBuffer_t* buff, uint64_t n)
{
  n = lifxHostToLittleInt64(n);
  memcpy(&(buff->Data[buff->Position]), &n, 8);
  buff->Position += 8;
  return 0;
}

int
lifxBuffer_WriteFloat(lifxBuffer_t* buff, float n)
{
  // TODO: do you byte-swap floats?
  n = lifxHostToLittleInt32(n);
  memcpy(&(buff->Data[buff->Position]), &n, 4);
  buff->Position += 4;
  return 0;
}

int
lifxBuffer_ReadUInt16(lifxBuffer_t* buff, uint16_t* n)
{
  return 0;
}

int
lifxBuffer_ReadFloat(lifxBuffer_t* buff, float* f)
{
  return 0;
}

int
lifxBuffer_Read(lifxBuffer_t* buff, uint8_t* data, int n)
{
  return 0;
}

int
lifxBuffer_WriteBool(lifxBuffer_t* buff, bool b)
{
  return 0;
}

int
lifxBuffer_ReadUInt64(lifxBuffer_t* buff, uint64_t* n)
{
  return 0;
}

int
lifxBuffer_ReadUInt32(lifxBuffer_t* buff, uint32_t* n)
{
  return 0;
}

int
lifxBuffer_ReadInt16(lifxBuffer_t* buff, int16_t* n)
{
  return 0;
}

int
lifxBuffer_ReadUInt8(lifxBuffer_t* buff, uint8_t* n)
{
  return 0;
}

int
lifxBuffer_ReadBool(lifxBuffer_t* buff, bool* b)
{
  return 0;
}
