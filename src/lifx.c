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
#include "lifx_version.h"
#include "lifx_encoders.h"
#include "lifx_internal.h"

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

static pthread_once_t error_once = PTHREAD_ONCE_INIT;
static pthread_key_t  error_key;

typedef struct
{
  int  LastError;
  char LastErrorMessage[kLifxErrorMessageMaxLength];
} lifxErrorThreadSpecific_t;

static void lifxErrorInitThreadSpecificKey()
{
  pthread_key_create(&error_key, NULL);
}

lifxErrorThreadSpecific_t*
lifxError_GetThreadSpecific()
{
  lifxErrorThreadSpecific_t* specific;
  pthread_once(&error_once, lifxErrorInitThreadSpecificKey);

  specific = (lifxErrorThreadSpecific_t *) pthread_getspecific(error_key);
  if (!specific)
  {
    specific = (lifxErrorThreadSpecific_t *) malloc(sizeof(lifxErrorThreadSpecific_t));
    specific->LastError = 0;
    specific->LastErrorMessage[0] = '\0';
    pthread_setspecific(error_key, specific);
  }

  return specific;
}

void lifxDumpBuffer(lifxSession_t* lifx, uint8_t* p, int n)
{
  if (kLifxLogLevelDebug < lifx->Config.LogLevel)
    return;

  int i;
  printf("\t");
  for (i = 0; i < n; ++i)
  {
    if ((i > 0) && (i % 16) == 0)
      printf("\n\t");
    printf("0x%02x ", p[i]);
  }
  printf("\n");
}

void lifxSockaddr_ToString(struct sockaddr_storage* ss, char* buff, int n, uint16_t* port)
{
  if (ss->ss_family == AF_INET)
  {
    struct sockaddr_in* v4 = (struct sockaddr_in *) ss;
    inet_ntop(ss->ss_family, &v4->sin_addr, buff, n);
    if (port)
      *port = ntohs(v4->sin_port);
  }
}

char const*
lifx_Version()
{
  return "v" LIFX_PROJECT_VER;
}

char const* lifxError_ToString(int errnum)
{
  int n;
  char const* buff;
  lifxErrorThreadSpecific_t* specific;
  
  buff = NULL;
  specific = lifxError_GetThreadSpecific();

  if (specific)
  {
    #ifdef __linux__
    n = strerror_r(errnum, specific->LastErrorMessage, kLifxErrorMessageMaxLength - 1);
    if (!n)
      buff = specific->LastErrorMessage;
    #else
    buff = strerror(errnum);
    #endif
    specific->LastError = errnum;
  }

  return buff;
}
