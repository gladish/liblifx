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
#ifndef LIFX_PLATFORM_MACOSX_H
#define LIFX_PLATFORM_MACOSX_H
#endif

#define LIFX_PRINTF_FORMAT(IDX, FIRST) __attribute__ ((format (printf, IDX, FIRST)))

typedef int lifxAtomic_t;
#define lifxInterlockedIncrement(n) __atomic_fetch_add(n, 1, __ATOMIC_SEQ_CST)
#define lifxInterlockedDecrement(n) __atomic_fetch_sub(n, 1, __ATOMIC_SEQ_CST)
typedef int lifxSystemError_t; 
typedef pthread_t lifxThread_t;
typedef pthread_mutex_t lifxMutex_t;
typedef pthread_cond_t lifxCond_t;
typedef void* (lifxThreadFunc_t)(void*);

#include <libkern/OSByteOrder.h>

#define lifxHostToLittleInt16(n) OSSwapHostToLittleInt16(n)
#define lifxLittleToHostInt16(n) OSSwapHostToLittleInt16(n)
#define lifxHostToLittleInt32(n) OSSwapHostToLittleInt32(n)
#define lifxLittleToHostInt32(n) OSSwapHostToLittleInt32(n)
#define lifxHostToLittleInt64(n) OSSwapHostToLittleInt64(n)
#define lifxLittleToHostInt64(n) OSSwapHostToLittleInt64(n)
