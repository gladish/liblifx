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
#include <unistd.h>

// lifx.h -- lifx.c
// won't need this
int lifxStringCopy(char* dest, int destLength, uint8_t const* source, int sourceLength)
{
  int n = (destLength - 1);
  if (sourceLength < n)
    n = sourceLength;
  memcpy(dest, source, n);
  dest[n] = '\0';
  return 0;
}

int main(int argc, char* argv[])
{
  int i;
  lifxStatus_t status;
  lifxSession_t* lifx;
  lifxSessionConfig_t conf;
  lifxDeviceId_t device_id;
  lifxLightSetPower_t set_power;
  lifxFuture_t* future;

  (void) argc;
  (void) argv;

  lifxSessionConfig_Init(&conf);
  conf.UseBackgroundDispatchThread = true;
  conf.LogLevel = kLifxLogLevelInfo;

  lifx = lifxSession_Open(&conf);
  lifxSession_StartDiscovery(lifx);
  set_power.Level = kLifxLightPowerLevelOff;
  sleep(3);
//  lifxSession_StopDiscovery(lifx);

  lifxDeviceId_FromString(&device_id, "lifx_id://mac/d0:73:d5:40:4d:61");

  for (i = 0; i < 5; ++i)
  {
    if (set_power.Level == kLifxLightPowerLevelOff)
      set_power.Level = kLifxLightPowerLevelOn;
    else
      set_power.Level = kLifxLightPowerLevelOff;

    printf("setting light power:%d\n", set_power.Level);

    future = lifxSession_BeginSendRequest(lifx, device_id, &set_power,
      kLifxPacketTypeLightSetPower);
    status = lifxFuture_Wait(future, 5000);
    lifxFuture_Release(future);

    if (status != kLifxStatusOk)
    {
      printf("failed:%d\n", status);
      break;
    }
    else
    {
      sleep(1);
    }

    printf("status:%d\n", status);
  }

  return 0;
}