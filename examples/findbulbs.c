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
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

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
  lifxSessionConfig_t conf;

  (void) argc;
  (void) argv;

  memset(&conf, 0, sizeof(lifxSessionConfig_t));
  conf.UseBackgroundDispatchThread = true;
  conf.LogLevel = kLifxLogLevelInfo;
  conf.DeviceDiscovered = discovery_callback;

  lifx = lifxSession_Open(&conf);
  lifxSession_StartDiscovery(lifx);
  sleep(20);
  lifxSession_StopDiscovery(lifx);
  lifxSession_Close(lifx);

  return 0;
}
