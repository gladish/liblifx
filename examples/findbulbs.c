#include <lifx.h>

#include <stdio.h>
// #include <stddef.h>


int main(int argc, char* argv[])
{
  lifxDevice_t* device;
  lifxLightSetColor_t set_color;
  lifxDeviceGetService_t get_service;

  // TODO: trying out different style API
  lifxSession_t* lifx = lifxSession_Create(NULL);
  lifxSession_SendTo(lifx, NULL, &get_service, kLifxPacketTypeDeviceGetService);

  //printf("size:%d\n", (int) sizeof(lifxLightSetWaveformOptional_t));
  //printf("size:%d\n", (int) sizeof(lifxLightHsbk_t));
  //printf("off :%d\n", (int) offsetof(lifxLightSetWaveformOptional_t, Color));
  //printf("off :%d\n", (int) offsetof(lifxLightSetWaveformOptional_t, Period));

  // TODO: You could take an approach where we have a single
  // lifxSendPacket(lifxHandle_t* h, lifxPacketType_t type, void* pkt);
  // probably needs a destination mac also, but after you discover the 
  // devices using GetService, you probably want to target specific IP 
  // addresses.

  set_color.Color.Hue = 0x00aa;
  set_color.Color.Saturation = 0xffff;
  set_color.Color.Brightness = 0xbbbb;
  set_color.Color.Kelvin = 0xabcd;

  // lifxSession_SendTo(lifx, device, &set_color, kLifxPacketTypeLightSetColor);
  return 0;
}

