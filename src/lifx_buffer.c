
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
lifxBufferInit(lifxBuffer_t* buff, int n)
{
  if (!buff)
    return EINVAL;

  if (n == 0)
  {
    buff->data = NULL;
    buff->size = 0;
  }
  else
  {
    buff->data = malloc(n * sizeof(uint8_t));
    if (!buff->data)
      return ENOMEM;
    buff->size = n;
  }

  buff->pos = 0;
  return 0;
}

int
lifxBufferDestroy(lifxBuffer_t* buff)
{
  if (!buff)
    return EINVAL;
  if (buff->data)
    free(buff->data);
  buff->data = NULL;
  buff->size = 0;
  buff->pos = 0;
  return 0;
}

int
lifxBufferSeek(lifxBuffer_t* buff, int offset, lifxBufferWhence whence)
{
  // TODO: finish this
  switch (whence)
  {
    case kLifxBufferWhenceCurrent:
    buff->pos += offset;
    break;

    case kLifxBufferWhenceEnd:
    break;

    case kLifxBufferWhenceSet:
    break;
  }

  return 0;
}

int
lifxBufferWrite(lifxBuffer_t* buff, uint8_t const* data, int len)
{
  int i;
  for (i = 0; i < len; ++i)
  {
    buff->data[buff->pos++] = data[i];
  }
  return 0;
}

int
lifxBufferWriteInt8(lifxBuffer_t* buff, int8_t n)
{
  buff->data[buff->pos++] = n;
  return 0;
}

int
lifxBufferWriteUInt8(lifxBuffer_t* buff, uint8_t n)
{
  buff->data[buff->pos++] = n;
  return 0;
}

int
lifxBufferWriteInt16(lifxBuffer_t* buff, int16_t n)
{
  n = lifxHostToLittleInt16(n);
  memcpy(&(buff->data[buff->pos]), &n, 2);
  buff->pos += 2;
  return 0;
}

int
lifxBufferWriteUInt16(lifxBuffer_t* buff, uint16_t n)
{
  n = lifxHostToLittleInt16(n);
  memcpy(&(buff->data[buff->pos]), &n, 2);
  buff->pos += 2;
  return 0;
}

int
lifxBufferWriteInt32(lifxBuffer_t* buff, int32_t n)
{
  n = lifxHostToLittleInt32(n);
  memcpy(&(buff->data[buff->pos]), &n, 4);
  buff->pos += 4;
  return 0;
}

int
lifxBufferWriteUInt32(lifxBuffer_t* buff, uint32_t n)
{
  n = lifxHostToLittleInt32(n);
  memcpy(&(buff->data[buff->pos]), &n, 4);
  buff->pos += 4;
  return 0;
}

int
lifxBufferWriteUInt64(lifxBuffer_t* buff, uint64_t n)
{
  n = lifxHostToLittleInt64(n);
  memcpy(&(buff->data[buff->pos]), &n, 8);
  buff->pos += 8;
  return 0;
}

int
lifxBufferWriteFloat(lifxBuffer_t* buff, float n)
{
  // TODO: do you byte-swap floats?
  n = lifxHostToLittleInt32(n);
  memcpy(&(buff->data[buff->pos]), &n, 4);
  buff->pos += 4;
  return 0;
}

int
lifxBufferReadUInt16(lifxBuffer_t* buff, uint16_t* n)
{
  return 0;
}

int
lifxBufferReadFloat(lifxBuffer_t* buff, float* f)
{
  return 0;
}

int
lifxBufferRead(lifxBuffer_t* buff, uint8_t* data, int n)
{
  return 0;
}

int
lifxBufferWriteBool(lifxBuffer_t* buff, bool b)
{
  return 0;
}

int
lifxBufferReadUInt64(lifxBuffer_t* buff, uint64_t* n)
{
  return 0;
}

int
lifxBufferReadUInt32(lifxBuffer_t* buff, uint32_t* n)
{
  return 0;
}

int
lifxBufferReadInt16(lifxBuffer_t* buff, int16_t* n)
{
  return 0;
}

int
lifxBufferReadUInt8(lifxBuffer_t* buff, uint8_t* n)
{
  return 0;
}

int
lifxBufferReadBool(lifxBuffer_t* buff, bool* b)
{
  return 0;
}
