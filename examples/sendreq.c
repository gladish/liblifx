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
#include <lifx.h>
#include <stdio.h>
#include <string.h>

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// JUST PROTOTYPING API 
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// lifx.h -- lifx.c
typedef struct
{
} lifxFuture_t;

// lifx.h -- lifx.c
int lifxFuture_Get(lifxFuture_t* future, lifxPacket_t* packet)
{
  return 0;
}

// lifx.h -- lifx.c
int lifxFuture_WaitUntil(lifxFuture_t* future, int millis)
{
  return 0;
}

// lifx.h -- lifx.c
int lifxFuture_Retain(lifxFuture_t* future)
{
  return 0;
}

// lifx.h -- lifx.c
int lifxFuture_Release(lifxFuture_t* future)
{
  return 0;
}

// lifx.h -- lifx.c
int lifxStringCopy(char* dest, int destLength, uint8_t const* source, int sourceLength)
{
  int n = (destLength - 1);
  if (sourceLength < n)
    n = sourceLength;
  memcpy(dest, source, n);
  dest[n] = '\0';
  return 0;
}


// lifx.h -- lifx_session.c
lifxFuture_t* lifxSession_SendRequest(lifxSession_t* lifx, lifxDeviceId_t deviceId, void* request, lifxPacketType_t packet_type)
{
  lifxFuture_t* future = NULL;

  // queue up future

  // call sendto

  // lifxSession_Dispatch() will dispatch waiter based on sequence number from header

  return future;
}

// lifx.h -- lifx_session.c
int lifxSession_SendRequestAndWait(
  lifxSession_t*    lifx,
  lifxDeviceId_t    deviceId,
  void*             request,
  lifxPacketType_t  packetType,
  lifxPacket_t*     response,
  int               millis)
{
  int ret;
  lifxFuture_t* future = lifxSession_SendRequest(lifx, deviceId, request, packetType);
  ret = lifxFuture_WaitUntil(future, millis);
  if (ret == 0)
  {
    lifxFuture_Get(future, response);
  }
  lifxFuture_Release(future);
  return ret;
}

// application layer foo. trying to make this as short as possible
// is it possible that the protocol.yml is consistent enough where we can 
// match up all the reqeust/response messages?
// maybe keep a table in the lxcodegen.py? "DeviceGetLabel" => "DeviceStateLabel"
// or possible just return an out param as lifxDeviceStateLabel_t
int lifxDevice_GetLabel(lifxSession_t* lifx, lifxDeviceId_t deviceId, char* buff, int n)
{
  int ret;

  lifxPacket_t response;
  lifxDeviceGetLabel_t getLabel;

  ret = lifxSession_SendRequestAndWait(lifx, deviceId, &getLabel, kLifxPacketTypeDeviceGetLabel,
    &response, 1000);
  if (ret == 0)
  {
    lifxStringCopy(buff, n, response.DeviceStateLabel.Label, sizeof(response.DeviceStateLabel.Label));
  }
  return ret;
}


int main(int argc, char* argv[])
{
  int ret;
  char buff[64];

  lifxSession_t* lifx;
  lifxSessionConfig_t conf;
  lifxDeviceId_t deviceId;

  lifxSessionConfig_Init(&conf);
  conf.UseBackgroundDispatchThread = true;
  conf.LogLevel = kLifxLogLevelInfo;

  lifxDeviceId_FromString(&deviceId, "lifx_id://mac/d0:73:d5:40:4d:61");

  lifx = lifxSession_Open(&conf);
  ret = lifxDevice_GetLabel(lifx, deviceId, buff, sizeof(buff));
  if (ret == 0)
  {
    printf("label:%s\n", buff);
  }

  lifxSession_Close(lifx);

  return 0;
}
