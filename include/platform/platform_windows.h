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
#ifndef LIFX_PLATFORM_WINDOWS_H
#define LIFX_PLATFORM_WINDOWS_H

#include <Winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h>

// Can use _Printf_format_string_ for this
#define LIFX_PRINTF_FORMAT(IDX, FIRST)

// TODO(jacobgladish@yahoo.com): could just write a small pthread
// compatiblity layer for windows and get rid of all the lifxMutex stuff
// for Linux and Mac
typedef LONG                    lifxAtomic_t;
typedef DWORD                   lifxSystemError_t;
typedef CRITICAL_SECTION        lifxMutex_t;
typedef CONDITION_VARIABLE      lifxCond_t;
typedef HANDLE                  lifxThread_t;
typedef PTHREAD_START_ROUTINE   lifxThreadFunc_t;

// types aren't compatible between windows/linux
typedef int                     socklen_t;

#define lifxInterlockedIncrement(n) InterlockedIncrement(n)
#define lifxInterlockedDecrement(n) InterlockedDecrement(n)

#if BYTE_ORDER == BIG_ENDIAN
#define lifxHostToLittleInt16(n) _byteswap_ushort(n)
#define lifxLittleToHostInt16(n) _byteswap_ushort(n)
#define lifxHostToLittleInt32(n) _byteswap_ulong(n)
#define lifxLittleToHostInt32(n) _byteswap_ulong(n)
#define lifxHostToLittleInt64(n) _byteswap_uint64(n)
#define lifxLittleToHostInt64(n) _byteswap_uint64(n)
#else
#define lifxHostToLittleInt16(n)
#define lifxLittleToHostInt16(n)
#define lifxHostToLittleInt32(n)
#define lifxLittleToHostInt32(n)
#define lifxHostToLittleInt64(n)
#define lifxLittleToHostInt64(n)
#endif

#endif
