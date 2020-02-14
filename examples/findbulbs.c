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
#include <pthread.h>

static lifxDevice_t dev = kLifxDeviceInvalid;
static bool device_found = false;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void message_handler(lifxSession_t const* lifx, lifxMessage_t const* const message,
  lifxDevice_t device)
{
  printf("message_type:%d\n", message->Header.Type);
  if ((dev == kLifxDeviceInvalid) && (message->Header.Type == kLifxPacketTypeDeviceStateService))
  {
    dev = device;
    printf("device found:%d\n", dev);

    pthread_mutex_lock(&mutex);
    device_found = true;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
  }
  if (message->Header.Type == kLifxPacketTypeDeviceStateLabel)
  {
    printf("Label:%s\n", message->Packet.DeviceStateLabel.Label);
  }
}

int main(int argc, char* argv[])
{
  lifxSessionConfig_t conf;

  // TODO: would be convenient to be able to supply interface
  // name here
  conf.BindInterface = NULL; // "10.26.52.112";
  conf.UseBackgroundDispatchThread = true;
  conf.MessageHandler = &message_handler;
  conf.LogLevel = kLifxLogLevelDebug;
  conf.ReportDuplicateDevices = false;
  lifxSession_t* lifx = lifxSession_Open(&conf);

  printf("version:%s\n", lifx_Version());

  while (!device_found)
  {

    lifxDeviceGetService_t get_service;
    lifxSession_SendTo(lifx, kLifxDeviceAll, &get_service, kLifxPacketTypeDeviceGetService);

    pthread_mutex_lock(&mutex);
    while (!device_found) {
      struct timespec wait_time;
      clock_gettime(CLOCK_REALTIME, &wait_time);
      wait_time.tv_sec += 1;
      printf("waiting for device to be found\n");
      pthread_cond_timedwait(&cond, &mutex, &wait_time);
    }
    pthread_mutex_unlock(&mutex);
  }

  // not required, but let the smoke clear
  sleep(1);

  if (device_found)
  {
    lifxDeviceGetLabel_t get_label;
    lifxSession_SendTo(lifx, dev, &get_label, kLifxPacketTypeDeviceGetLabel);
  }

  while (true)
  {
    sleep(1);
  }


  lifxSession_Close(lifx);
  return 0;
}

