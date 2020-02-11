#include <lifx.h>

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
  int i;
  lifxDevice_t* device;
  lifxMessage_t message;
  lifxDeviceGetService_t get_service;
  lifxSessionConfig_t conf;

  // TODO: would be convenient to be able to supply interface
  // name here
  conf.BindInterface = NULL; // "10.26.52.112";
  lifxSession_t* lifx = lifxSession_Open(&conf);

  for (i = 0; i < 5; ++i)
  {
    lifxSession_SendTo(lifx, NULL, &get_service, kLifxPacketTypeDeviceGetService);
    lifxSession_RecvFrom(lifx, &message, 200);
  }

  lifxSession_Close(lifx);

  return 0;
}

