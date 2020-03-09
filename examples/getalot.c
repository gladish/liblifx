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

int main(int argc, char* argv[])
{
  lifxStatus_t status;
  lifxSession_t* lifx;
  lifxDeviceId_t device_id;

  (void) argc;
  (void) argv;

  lifx = lifxSession_Open(NULL);

  lifxDeviceId_FromString(&device_id, "lifx_id://mac/d0:73:d5:40:4d:61");

  // GetHostInfo
  {
    lifxDeviceStateHostInfo_t res;
    status = lifxDevice_GetHostInfo(lifx, device_id, &res);
    if (status == kLifxStatusOk)
    {
      printf("\"DeviceStateHostInfo\": {");
      printf("\"Signal\":%f", res.Signal);
      printf(" \"Tx\":%u", res.Tx);
      printf(" \"Rx\":%u", res.Rx);
      printf("}\n");
    }
  }

  lifxSleep(250);

  // GetHostFirmware
  {
    lifxDeviceStateHostFirmware_t res;
    status = lifxDevice_GetHostFirmware(lifx, device_id, &res);
    if (status == kLifxStatusOk)
    {
      printf("\"DeviceStateHostFirmware\": {");
      printf("\"Build\":%lu", res.Build);
      printf(" \"VersionMajor\":%u", res.VersionMajor);
      printf(" \"VersionMinor\":%u", res.VersionMinor);
      printf("}\n");
    }
  }

  return 0;
}
