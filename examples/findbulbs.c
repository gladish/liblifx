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

void discovery_callback(lifxSession_t const* lifx, lifxDeviceId_t deviceId)
{
  char mac[64];

  (void) lifx;
  lifxDeviceId_ToString(&deviceId, mac, sizeof(mac));
  printf("new device:%s\n", mac);
}

int main(int argc, char* argv[])
{
  lifxSession_t* lifx;
  lifxSessionConfig_t config;

  (void)argc;
  (void)argv;

  lifxSessionConfig_InitWithDefaults(&config);
  config.LogLevel = kLifxLogLevelDebug;
  // config.SourceId = 0xdeadbeef;
  // config.BindInterface = "10.0.0.252";
  config.DeviceDiscovered = discovery_callback;

  lifx = lifxSession_Open(&config);
  lifxSession_StartDiscovery(lifx);
  lifxSleep(20000);
  lifxSession_StopDiscovery(lifx);
  lifxSession_Close(lifx);

  return 0;
}
