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

static uint8_t const kLifxProtocolNumber = (uint8_t) 1024u;

struct lifxSession
{
  int       Socket;
  uint32_t  SourceId;
  uint8_t   SequenceNumber;
  uint8_t*  ReceiveBuffer;
  int32_t   ReceiveBufferLength;
};

struct lifxDevice
{
  struct sockaddr_storage Endpoint;
};

struct lifxMessage
{
  lifxProtocolHeader_t  Header;
  lifxPacket_t          Packet;
  lifxDevice_t          Sender;
  int32_t               RefCount;
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

  lifx->Socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (lifx->Socket == -1)
  {
    free(lifx);
    return NULL;
  }

  lifx->ReceiveBufferLength = (int32_t) sizeof(lifxMessage_t);
  lifx->ReceiveBuffer = malloc(lifx->ReceiveBufferLength);
  if (!lifx->ReceiveBuffer)
  {
    free(lifx);
    return NULL;
  }

  lifx->SourceId = getpid();
  lifx->SequenceNumber = 0;

  flag = 1;
  ret = setsockopt(lifx->Socket, SOL_SOCKET, SO_BROADCAST, &flag, sizeof(flag));
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

  if (lifx->Socket != -1)
    close(lifx->Socket);
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
  int n;

  memset(&header, 0, sizeof(lifxProtocolHeader_t));
  memset(&dest, 0, sizeof(struct sockaddr_in));

  header.Size = sizeof(lifxProtocolHeader_t);
  header.Protocol = kLifxProtocolNumber;
  header.Addressable = 1;
  header.Tagged = 1;
  header.Origin = 0;
  header.Source = 0xdeadbeef;
  if (device)
  {
    header.Target[0] = 0;
    header.Target[1] = 0;
    header.Target[2] = 0;
    header.Target[3] = 0;
    header.Target[4] = 0;
    header.Target[5] = 0;
    header.Target[6] = 0;
    header.Target[7] = 0;
  }
  header.ResRequired = 0;
  header.AckRequired = 0;
  header.Sequence = lifxInterlockedIncrement(&lifx->SequenceNumber);
  header.Type = kLifxPacketTypeDeviceGetService;

  // TODO: This should come from the lifxDevice
  memset(&dest, 0, sizeof(struct sockaddr_in));
  dest.sin_family = AF_INET;
  dest.sin_port = htons(56700);
  dest.sin_addr.s_addr = htonl(INADDR_BROADCAST);

  printf("sending:\n");
  lifxDumpBuffer((uint8_t *)&header, (int) sizeof(lifxProtocolHeader_t));
  printf("\n\n");

  n = sendto(lifx->Socket, &header, sizeof(lifxProtocolHeader_t), 0, (struct sockaddr *)&dest,
      sizeof(struct sockaddr_in));

  if (n == -1)
    return errno;

  return 0;
}

int
lifxSession_RecvFrom(lifxSession_t*   lifx,
                     lifxMessage_t**  message,
                     int              timeout)
{
  int             n;
  fd_set          fds;
  struct timeval  wait_time;
  lifxMessage_t*  incoming_message;

  n = 0;
  FD_ZERO(&fds);
  wait_time.tv_sec = timeout;
  wait_time.tv_usec = 0;

  n = select(lifx->Socket  + 1, &fds, NULL, NULL, &wait_time);
  if (n == -1)
    return errno;

  if (FD_ISSET(lifx->Socket, &fds))
  {
    socklen_t source_size;
    struct sockaddr_storage source;

    #ifdef LIFX_DEBUG
    memset(lifx->ReceiveBuffer, 0, lifx->ReceiverBufferLength);
    #endif

    n = recvfrom(lifx->Socket, lifx->ReceiveBuffer, lifx->ReceiveBufferLength, 0,
      (struct sockaddr *)&source, &source_size);

    if (n == -1)
      return errno;

    incoming_message = malloc(sizeof(lifxMessage_t));
    if (!incoming_message)
    {
      // TODO:
    }

    memcpy(&incoming_message->Header, lifx->ReceiveBuffer, sizeof(lifxProtocolHeader_t));

    // TODO: auto-generate this function
    // lifxDecoder_DecodePacket(m->Header.Type, buff + sizeof(lifxProtocolHeader_t), &m->Packet);

    memcpy(&incoming_message->Sender.Endpoint, &source, source_size);
  }

  return 0;
}

int
lifxMessage_Retain(lifxMessage_t* m)
{
  if (!m)
    return EINVAL;
  lifxInterlockedIncrement(&m->RefCount);
  return 0;
}

int
lifxMessage_Release(lifxMessage_t* m)
{
  int32_t count;
  if (!m)
    return EINVAL;

  count = lifxInterlockedIncrement(&m->RefCount);
  if (count == 0)
    free(m);

  return 0;
}
