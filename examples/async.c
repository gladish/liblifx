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
#include <lifx.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
  lifxStatus_t status;
  lifxSession_t* lifx;
  lifxDeviceId_t device_id;
  lifxLightSetPower_t set_power;
  lifxFuture_t* future;
  lifxSessionConfig_t config;

  (void) argc;
  (void) argv;

  lifxSessionConfig_InitWithDefaults(&config);
  //config.LogLevel = kLifxLogLevelDebug;
  //config.BindInterface = "10.0.0.252";
  //lifxWSAStartup();

  lifx = lifxSession_Open(&config);

  // not setting the duration causes random values
  // to be used, which has really confusing results
  set_power.Level = kLifxLightPowerLevelOff;
  set_power.Duration = 0;

  // not longer need to first discover the device. if the device endpoint
  // is not known, then a broadcast is sent along with a device discovery
  // once the device is discovered, the ip/port is used w/ unicast
  lifxDeviceId_FromString(&device_id, "lifx_id://mac/d0:73:d5:40:4d:61");

  while (true)
  {
    if (set_power.Level == kLifxLightPowerLevelOff)
      set_power.Level = kLifxLightPowerLevelOn;
    else
      set_power.Level = kLifxLightPowerLevelOff;

    do
    {
      printf("setting light power:%d\n", set_power.Level);
      future = lifxSession_BeginSendRequest(lifx, device_id, &set_power,
          kLifxPacketTypeLightSetPower);
      status = lifxFuture_Wait(future, lifxTimeSpan_FromMilliseconds(500));
      lifxFuture_Release(future);
    }
    while (status == kLifxStatusOperationTimedout);

    if (status != kLifxStatusOk)
    {
      printf("failed:%d\n", status);
      break;
    }
    else
    {
      printf("status:%d waiting one second\n", status);
      lifxSleep(1000);
    }
  }

  return 0;
}
