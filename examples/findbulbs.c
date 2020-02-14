#include <lifx.h>

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

void message_handler(lifxSession_t const* lifx, lifxMessage_t const* const message,
  lifxDevice_t device)
{
  if (message->Header.Type == kLifxPacketTypeDeviceStateService)
  {
    // TODO: lifxDevice api needs work
    printf("device discoverd!\n");
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
  conf.LogLevel = kLifxLogLevelInfo;
  lifxSession_t* lifx = lifxSession_Open(&conf);

  printf("version:%s\n", lifx_Version());

  while (true)
  {
    lifxDeviceGetService_t get_service;
    lifxSession_SendTo(lifx, kLifxDeviceAll, &get_service, kLifxPacketTypeDeviceGetService);
    sleep(5);
  }

  lifxSession_Close(lifx);
  return 0;
}

