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
  lifxDeviceId_t device_id;
  lifxLightSetPower_t set_power;
  lifxFuture_t* future;

  (void) argc;
  (void) argv;

  lifx = lifxSession_Open(NULL);

  // not setting the duration causes random values
  // to be used, which has really confusing results
  set_power.Level = kLifxLightPowerLevelOn;
  set_power.Duration = 0;

  // not longer need to first discover the device. if the device endpoint
  // is not known, then a broadcast is sent along with a device discovery
  // once the device is discovered, the ip/port is used w/ unicast
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
      printf("status:%d\n", status);
      sleep(1);
    }
  }

  return 0;
}
