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

static void set_color(lifxSession_t* lifx, lifxDeviceId_t device_id,
  uint8_t red, uint8_t green, uint8_t blue)
{
  lifxLightSetColor_t light_color  = {
    .Color = light_color.Color = lifxColor_FromRGB(red, green, blue),
    .Duration = 0
  };

  lifxStatus_t status = lifxLight_SetColor(lifx, device_id, &light_color, NULL);
  if (status != kLifxStatusOk)
  {
    printf("failed to set light color to [%u,%u.%u]\n",
      red, green, blue);
  }
  else
  {
    lifxSleep(600);
  }
}

int main(int argc, char* argv[])
{
  lifxStatus_t status;
  lifxSession_t* lifx;
  lifxDeviceId_t device_id;
  lifxLightState_t initial_light_state;
  lifxLightSetColor_t light_color;

  (void) argc;
  (void) argv;

  lifx = lifxSession_Open(NULL);

  lifxDeviceId_FromString(&device_id, "lifx_id://mac/d0:73:d5:40:4d:61");
  status = lifxLight_Get(lifx, device_id, &initial_light_state, NULL);

  if (status == kLifxStatusOk)
  {
    // roygbiv
    set_color(lifx, device_id, 255, 0, 0);
    set_color(lifx, device_id, 255, 127, 0);
    set_color(lifx, device_id, 255, 255, 0);
    set_color(lifx, device_id, 0, 255, 0);
    set_color(lifx, device_id, 0, 0, 255);
    set_color(lifx, device_id, 75, 0, 130);
    set_color(lifx, device_id, 148, 0, 211);

    light_color.Color = lifxColor_FromKelvin(9000);
    light_color.Duration = 0;
    lifxLight_SetColor(lifx, device_id, &light_color, NULL);
    lifxSleep(2000);

    light_color.Color = lifxColor_FromKelvin(5000);
    light_color.Duration = 0;
    lifxLight_SetColor(lifx, device_id, &light_color, NULL);
    lifxSleep(2000);

    light_color.Color = lifxColor_FromKelvin(2500);
    light_color.Duration = 0;
    lifxLight_SetColor(lifx, device_id, &light_color, NULL);
    lifxSleep(2000);

    light_color.Color = initial_light_state.Color;
    light_color.Duration = 0;
    status = lifxLight_SetColor(lifx, device_id, &light_color, NULL);
  }

  return 0;
}
