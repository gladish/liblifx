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

struct lifxHandle
{
  int       socfd;
};

int
lifxLibInit(lifxHandle_t** handle)
{
  int           ret;
  int           flag;
  lifxHandle_t* temp_handle;

  temp_handle = malloc(sizeof(lifxHandle_t));
  if (!temp_handle)
    return ENOMEM;

  temp_handle->socfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (temp_handle->socfd == -1)
  {
    free(temp_handle);
    return temp_handle->socfd;
  }

  flag = 1;
  ret = setsockopt(temp_handle->socfd, SOL_SOCKET, SO_BROADCAST, &flag, sizeof(flag));
  if (ret == -1)
  {
    // TODO:
    return errno;
  }

  *handle = temp_handle;
  return 0;
}

int
lifxLibShutdown(lifxHandle_t* handle)
{
  if (!handle)
    return EINVAL;

  if (handle)
  {
    if (handle->socfd != -1)
      close(handle->socfd);
    free(handle);
  }

  return 0;
}

// This will actually send out a GetService (payload size is zero!)
#if 0
  int flag;
  int soc;
  lifxProtocolHeader_t header;
  struct sockaddr_in dest;
  uint8_t* buff;

  flag = 1;
  soc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  setsockopt(soc, SOL_SOCKET, SO_BROADCAST, &flag, sizeof(flag));

  memset(&header, 0, sizeof(lifxProtocolHeader_t));
  memset(&dest, 0, sizeof(struct sockaddr_in));

  header.size = sizeof(lifxProtocolHeader_t);
  header.protocol = 1024;
  header.addressable = 1;
  header.tagged = 1;
  header.origin = 0;
  header.source = 0xdeadbeef;
  header.target[0] = 0;
  header.target[1] = 0;
  header.target[2] = 0;
  header.target[3] = 0;
  header.target[4] = 0;
  header.target[5] = 0;
  header.target[6] = 0;
  header.target[7] = 0;
  header.res_required = 0;
  header.ack_required = 0;
  header.sequence = 2;
  header.type = kLifxPacketTypeDeviceGetService;

  buff = malloc(1024);

  printf("size:%d\n", (int) sizeof(lifxDeviceGetService_t));
  return 0;


  while (1)
  {
    int i;
    int n;
    fd_set fds;
    struct timeval timeout;
    uint8_t* p;

    FD_ZERO(&fds);
    FD_SET(soc, &fds);

    memset(&dest, 0, sizeof(struct sockaddr_in));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(56700);
    dest.sin_addr.s_addr = htonl(INADDR_BROADCAST);

    printf("sending:\n");
    lifxDumpBuffer((uint8_t *)&header, (int) sizeof(lifxProtocolHeader_t));
    printf("\n\n");

    n = sendto(soc, &header, sizeof(lifxProtocolHeader_t), 0, (struct sockaddr *)&dest,
      sizeof(struct sockaddr_in));

    timeout.tv_sec = 2;
    timeout.tv_usec = 0;
    select(soc + 1, &fds, NULL, NULL, &timeout);

    if (FD_ISSET(soc, &fds))
    {
      // data to read
      struct sockaddr_storage source;
      socklen_t source_size;
      n = recvfrom(soc, buff, 1024, 0, (struct sockaddr *)&source, &source_size);

      printf("receive:\n");
      lifxDumpBuffer(buff, n);
      printf("\n\n");
    }
    else
    {
      printf("timeout\n");
    }
  }
#endif
