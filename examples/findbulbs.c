#include <lifx.h>

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
  lifxDevice_t* device;
  lifxMessage_t message;
  lifxDeviceGetService_t get_service;

  lifxSession_t* lifx = lifxSession_Create(NULL);

  while (true)
  {
    lifxSession_SendTo(lifx, NULL, &get_service, kLifxPacketTypeDeviceGetService);
    lifxSession_RecvFrom(lifx, &message, 1);
    sleep(1);
  }

  return 0;
}

