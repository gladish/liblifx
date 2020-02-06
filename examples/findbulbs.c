#include <lifx.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>

void lifxDumpBuffer(uint8_t* p, int n)
{
  int i;
  for (i = 0; i < n; ++i)
  {
    printf("0x%02x", p[i]);
    if ((i > 0) && (i % 16 == 0))
      printf("\n");
  }
}

int main(int argc, char* argv[])
{
  // TODO: not sure I'm crazy about the handle and lifxLibInit.
  lifxHandle_t* lifx;
  lifxLibInit(&lifx);

  printf("size:%d\n", (int) sizeof(lifxLightSetWaveformOptional_t));
  printf("size:%d\n", (int) sizeof(lifxLightHsbk_t));
  printf("off :%d\n", (int) offsetof(lifxLightSetWaveformOptional_t, Color));
  printf("off :%d\n", (int) offsetof(lifxLightSetWaveformOptional_t, Period));

  // TODO: You could take an approach where we have a single
  // lifxSendPacket(lifxHandle_t* h, lifxPacketType_t type, void* pkt);
  // probably needs a destination mac also, but after you discover the 
  // devices using GetService, you probably want to target specific IP 
  // addresses.
  return 0;
}

