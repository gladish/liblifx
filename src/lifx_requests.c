//
// DO NOT EDIT - AUTO-GENERATE:2020-02-21 13:45:06.412789
//
#include "lifx.h"

int lifxDevice_GetService(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateService_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxDeviceGetService_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetService, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.DeviceStateService;
  }
  return status;
}

int lifxDevice_GetHostInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateHostInfo_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxDeviceGetHostInfo_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetHostInfo, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.DeviceStateHostInfo;
  }
  return status;
}

int lifxDevice_GetHostFirmware(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateHostFirmware_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxDeviceGetHostFirmware_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetHostFirmware, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.DeviceStateHostFirmware;
  }
  return status;
}

int lifxDevice_GetWifiInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateWifiInfo_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxDeviceGetWifiInfo_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetWifiInfo, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.DeviceStateWifiInfo;
  }
  return status;
}

int lifxDevice_GetWifiFirmware(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateWifiFirmware_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxDeviceGetWifiFirmware_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetWifiFirmware, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.DeviceStateWifiFirmware;
  }
  return status;
}

int lifxDevice_GetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStatePower_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxDeviceGetPower_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetPower, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.DeviceStatePower;
  }
  return status;
}

int lifxDevice_GetLabel(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateLabel_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxDeviceGetLabel_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetLabel, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.DeviceStateLabel;
  }
  return status;
}

int lifxDevice_GetVersion(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateVersion_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxDeviceGetVersion_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetVersion, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.DeviceStateVersion;
  }
  return status;
}

int lifxDevice_GetInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateInfo_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxDeviceGetInfo_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetInfo, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.DeviceStateInfo;
  }
  return status;
}

int lifxDevice_GetLocation(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateLocation_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxDeviceGetLocation_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetLocation, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.DeviceStateLocation;
  }
  return status;
}

int lifxDevice_GetGroup(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateGroup_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxDeviceGetGroup_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetGroup, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.DeviceStateGroup;
  }
  return status;
}

int lifxLight_Get(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightState_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxLightGet_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeLightGet, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.LightState;
  }
  return status;
}

int lifxLight_GetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightStatePower_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxLightGetPower_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeLightGetPower, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.LightStatePower;
  }
  return status;
}

int lifxLight_GetInfrared(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightStateInfrared_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxLightGetInfrared_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeLightGetInfrared, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.LightStateInfrared;
  }
  return status;
}

int lifxTileGetDeviceChain(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileStateDeviceChain_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxTileGetDeviceChain_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeTileGetDeviceChain, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.TileStateDeviceChain;
  }
  return status;
}

int lifxTileGet64(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileState64_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxTileGet64_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeTileGet64, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.TileState64;
  }
  return status;
}

int lifxTileGetEffect(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileStateEffect_t* response)
{
  int status;
  int timeoutMillis;
  lifxPacket_t res;
  lifxTileGetEffect_t request;
  
  timeoutMillis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeTileGetEffect, &res, timeoutMillis);
  if (status == 0)
  {
    *response = res.TileStateEffect;
  }
  return status;
}

