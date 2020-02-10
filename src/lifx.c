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
#include "lifx.h"

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#pragma pack(push, 1)
typedef struct
{
  // frame
  uint16_t  size;
  uint16_t  protocol:12;
  uint8_t   addressable:1;
  uint8_t   tagged:1;
  uint8_t   origin:2;
  uint32_t  source;

  // frame address
  uint8_t   target[8];
  uint8_t   reserved[6];
  uint8_t   res_required:1;
  uint8_t   ack_required:1;
  uint8_t   :6;
  uint8_t   sequence;

  // protocol header
  uint64_t  :64;
  uint16_t  type;
  uint16_t  :16;
} lifxProtocolHeader_t;
#pragma pack(pop)

struct lifxSession
{
  int       udpsoc;
  uint32_t  source_id;
};

static void lifxDumpBuffer(uint8_t* p, int n)
{
  int i;
  for (i = 0; i < n; ++i)
  {
    if ((i > 0) && (i % 8) == 0)
      printf("\n");
    printf("0x%02x ", p[i]);
  }
}

lifxSession_t*
lifxSession_Create(lifxSessionConfig_t const* conf)
{
  int           ret;
  int           flag;
  struct lifxSession* lifx;

  (void) conf;

  lifx = malloc(sizeof(struct lifxSession));
  if (!lifx)
    return NULL;

  lifx->udpsoc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (lifx->udpsoc == -1)
  {
    free(lifx);
    return NULL;
  }

  lifx->source_id = getpid();

  flag = 1;
  ret = setsockopt(lifx->udpsoc, SOL_SOCKET, SO_BROADCAST, &flag, sizeof(flag));
  if (ret == -1)
  {
    free(lifx);
    return NULL;
  }

  return lifx;
}

int
lifxSession_Close(lifxSession_t* session)
{
  struct lifxSession* lifx = (struct lifxSession *) session;

  if (!lifx)
    return EINVAL;

  if (lifx->udpsoc != -1)
    close(lifx->udpsoc);
  free(lifx);

  return 0;
}

int
lifxSession_SendTo(
  lifxSession_t*    lifx,
  lifxDevice_t*     device,
  void*             packet,
  lifxPacketType_t  packet_type)
{
  lifxProtocolHeader_t header;
  struct sockaddr_in dest;
  uint8_t* buff;

  memset(&header, 0, sizeof(lifxProtocolHeader_t));
  memset(&dest, 0, sizeof(struct sockaddr_in));

  header.size = sizeof(lifxProtocolHeader_t);
  header.protocol = 1024;
  header.addressable = 1;
  header.tagged = 1;
  header.origin = 0;
  header.source = 0xdeadbeef;
  if (device)
  {
    header.target[0] = 0;
    header.target[1] = 0;
    header.target[2] = 0;
    header.target[3] = 0;
    header.target[4] = 0;
    header.target[5] = 0;
    header.target[6] = 0;
    header.target[7] = 0;
  }
  header.res_required = 0;
  header.ack_required = 0;
  header.sequence = 2;
  header.type = kLifxPacketTypeDeviceGetService;

  buff = malloc(1024);

  while (1)
  {
    int n;
    fd_set fds;
    struct timeval timeout;

    FD_ZERO(&fds);
    FD_SET(lifx->udpsoc, &fds);

    memset(&dest, 0, sizeof(struct sockaddr_in));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(56700);
    dest.sin_addr.s_addr = htonl(INADDR_BROADCAST);

    printf("sending:\n");
    lifxDumpBuffer((uint8_t *)&header, (int) sizeof(lifxProtocolHeader_t));
    printf("\n\n");

    n = sendto(lifx->udpsoc, &header, sizeof(lifxProtocolHeader_t), 0, (struct sockaddr *)&dest,
      sizeof(struct sockaddr_in));

    timeout.tv_sec = 2;
    timeout.tv_usec = 0;
    select(lifx->udpsoc  + 1, &fds, NULL, NULL, &timeout);

    if (FD_ISSET(lifx->udpsoc, &fds))
    {
      // data to read
      struct sockaddr_storage source;
      socklen_t source_size;
      n = recvfrom(lifx->udpsoc, buff, 1024, 0, (struct sockaddr *)&source, &source_size);

      memset(&header, 0, sizeof(header));
      memcpy(&header, buff, sizeof(header));

      printf("receive:\n");
      lifxDumpBuffer(buff, n);
      printf("\n\n");
    }
    else
    {
      printf("timeout\n");
    }
  }

  return 0;
}
