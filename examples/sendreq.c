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
  lifxStatus_t status;
  lifxSession_t* lifx;
  lifxSessionConfig_t conf;
  lifxDeviceId_t device_id;
  lifxDeviceStateLabel_t label;

  (void) argc;
  (void) argv;

  lifxSessionConfig_Init(&conf);
  conf.UseBackgroundDispatchThread = true;
  conf.LogLevel = kLifxLogLevelInfo;

  lifx = lifxSession_Open(&conf);
  lifxSession_StartDiscovery(lifx);
  sleep(3);

  lifxDeviceId_FromString(&device_id, "lifx_id://mac/d0:73:d5:40:4d:61");

  // XXX: fails right now if we haven't first discovered this device
  status = lifxDevice_GetLabel(lifx, device_id, &label);
  if (status == kLifxStatusOk)
    printf("label:%s\n", label.Label);

  if (status == kLifxStatusOk)
  {
    lifxLightState_t light_state;
    status = lifxLight_Get(lifx, device_id, &light_state);
    if (status == kLifxStatusOk)
    {
      printf("Light State\n");
      printf("\tColor {Hue:%d Saturation:%d Brightness:%d Kelvin:%d}\n",
        light_state.Color.Hue,
        light_state.Color.Saturation,
        light_state.Color.Brightness,
        light_state.Color.Kelvin);
      printf("\tLabel:%s\n", light_state.Label);
    }
  }

  if (status == kLifxStatusOk)
  {
    lifxLightSetPower_t set_power;
    set_power.Level = 65535;
    status = lifxLight_SetPower(lifx, device_id, &set_power);
  }

  lifxSession_Close(lifx);

  return 0;
}
