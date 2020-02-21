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

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// JUST PROTOTYPING API 
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

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
  int ret;

  lifxSession_t* lifx;
  lifxSessionConfig_t conf;
  lifxDeviceId_t deviceId;
  lifxDeviceStateLabel_t label;

  (void) argc;
  (void) argv;

  lifxSessionConfig_Init(&conf);
  conf.UseBackgroundDispatchThread = true;
  conf.LogLevel = kLifxLogLevelInfo;

  lifx = lifxSession_Open(&conf);
  lifxSession_StartDiscovery(lifx);
  sleep(2);

  lifxDeviceId_FromString(&deviceId, "lifx_id://mac/d0:73:d5:40:4d:61");

  // XXX: fails right now if we haven't first discovered this device
  ret = lifxDevice_GetLabel(lifx, deviceId, &label);
  if (ret == 0)
    printf("label:%s\n", label.Label);

  if (ret == 0)
  {
    lifxLightState_t lightState;
    ret = lifxLight_Get(lifx, deviceId, &lightState);
    if (ret == 0)
    {
      printf("Light State\n");
      printf("\tColor {Hue:%d Saturation:%d Brightness:%d Kelvin:%d}\n",
        lightState.Color.Hue,
        lightState.Color.Saturation,
        lightState.Color.Brightness,
        lightState.Color.Kelvin);
      printf("\tLabel:%s\n", lightState.Label);
    }
  }

  lifxSession_Close(lifx);

  return 0;
}
