//
// DO NOT EDIT - AUTO-GENERATE:2020-02-24 19:30:34.196492
//
#include "lifx.h"

lifxStatus_t lifxDevice_GetService(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateService_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxDeviceGetService_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetService, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.DeviceStateService;
  }
  return status;
}

lifxStatus_t lifxDevice_GetHostInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateHostInfo_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxDeviceGetHostInfo_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetHostInfo, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.DeviceStateHostInfo;
  }
  return status;
}

lifxStatus_t lifxDevice_GetHostFirmware(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateHostFirmware_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxDeviceGetHostFirmware_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetHostFirmware, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.DeviceStateHostFirmware;
  }
  return status;
}

lifxStatus_t lifxDevice_GetWifiInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateWifiInfo_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxDeviceGetWifiInfo_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetWifiInfo, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.DeviceStateWifiInfo;
  }
  return status;
}

lifxStatus_t lifxDevice_GetWifiFirmware(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateWifiFirmware_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxDeviceGetWifiFirmware_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetWifiFirmware, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.DeviceStateWifiFirmware;
  }
  return status;
}

lifxStatus_t lifxDevice_GetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStatePower_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxDeviceGetPower_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetPower, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.DeviceStatePower;
  }
  return status;
}

lifxStatus_t lifxDevice_GetLabel(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateLabel_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxDeviceGetLabel_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetLabel, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.DeviceStateLabel;
  }
  return status;
}

lifxStatus_t lifxDevice_GetVersion(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateVersion_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxDeviceGetVersion_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetVersion, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.DeviceStateVersion;
  }
  return status;
}

lifxStatus_t lifxDevice_GetInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateInfo_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxDeviceGetInfo_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetInfo, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.DeviceStateInfo;
  }
  return status;
}

lifxStatus_t lifxDevice_GetLocation(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateLocation_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxDeviceGetLocation_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetLocation, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.DeviceStateLocation;
  }
  return status;
}

lifxStatus_t lifxDevice_GetGroup(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateGroup_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxDeviceGetGroup_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetGroup, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.DeviceStateGroup;
  }
  return status;
}

lifxStatus_t lifxLight_Get(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightState_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxLightGet_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeLightGet, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.LightState;
  }
  return status;
}

lifxStatus_t lifxLight_GetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightStatePower_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxLightGetPower_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeLightGetPower, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.LightStatePower;
  }
  return status;
}

lifxStatus_t lifxLight_GetInfrared(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightStateInfrared_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxLightGetInfrared_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeLightGetInfrared, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.LightStateInfrared;
  }
  return status;
}

lifxStatus_t lifxTile_GetDeviceChain(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileStateDeviceChain_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxTileGetDeviceChain_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeTileGetDeviceChain, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.TileStateDeviceChain;
  }
  return status;
}

lifxStatus_t lifxTile_Get64(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileState64_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxTileGet64_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeTileGet64, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.TileState64;
  }
  return status;
}

lifxStatus_t lifxTile_GetEffect(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileStateEffect_t* response)
{
  lifxStatus_t status;
  int timeout_millis;
  lifxPacket_t packet;
  lifxTileGetEffect_t request;
  
  timeout_millis = 2000;
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeTileGetEffect, &packet, timeout_millis);
  if (status == 0)
  {
    *response = packet.TileStateEffect;
  }
  return status;
}

lifxStatus_t lifxDevice_SetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceSetPower_t const* value)
{
  int timeout_millis;
  lifxPacket_t packet;
  timeout_millis = 2000;
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeDeviceSetPower, &packet, timeout_millis);
}

lifxStatus_t lifxDevice_SetLabel(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceSetLabel_t const* value)
{
  int timeout_millis;
  lifxPacket_t packet;
  timeout_millis = 2000;
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeDeviceSetLabel, &packet, timeout_millis);
}

lifxStatus_t lifxDevice_SetLocation(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceSetLocation_t const* value)
{
  int timeout_millis;
  lifxPacket_t packet;
  timeout_millis = 2000;
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeDeviceSetLocation, &packet, timeout_millis);
}

lifxStatus_t lifxDevice_SetGroup(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceSetGroup_t const* value)
{
  int timeout_millis;
  lifxPacket_t packet;
  timeout_millis = 2000;
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeDeviceSetGroup, &packet, timeout_millis);
}

lifxStatus_t lifxLight_SetColor(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightSetColor_t const* value)
{
  int timeout_millis;
  lifxPacket_t packet;
  timeout_millis = 2000;
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeLightSetColor, &packet, timeout_millis);
}

lifxStatus_t lifxLight_SetWaveformOptional(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightSetWaveformOptional_t const* value)
{
  int timeout_millis;
  lifxPacket_t packet;
  timeout_millis = 2000;
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeLightSetWaveformOptional, &packet, timeout_millis);
}

lifxStatus_t lifxLight_SetWaveform(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightSetWaveform_t const* value)
{
  int timeout_millis;
  lifxPacket_t packet;
  timeout_millis = 2000;
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeLightSetWaveform, &packet, timeout_millis);
}

lifxStatus_t lifxLight_SetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightSetPower_t const* value)
{
  int timeout_millis;
  lifxPacket_t packet;
  timeout_millis = 2000;
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeLightSetPower, &packet, timeout_millis);
}

lifxStatus_t lifxLight_SetInfrared(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightSetInfrared_t const* value)
{
  int timeout_millis;
  lifxPacket_t packet;
  timeout_millis = 2000;
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeLightSetInfrared, &packet, timeout_millis);
}

lifxStatus_t lifxTile_SetUserPosition(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileSetUserPosition_t const* value)
{
  int timeout_millis;
  lifxPacket_t packet;
  timeout_millis = 2000;
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeTileSetUserPosition, &packet, timeout_millis);
}

lifxStatus_t lifxTile_Set64(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileSet64_t const* value)
{
  int timeout_millis;
  lifxPacket_t packet;
  timeout_millis = 2000;
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeTileSet64, &packet, timeout_millis);
}

lifxStatus_t lifxTile_SetEffect(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileSetEffect_t const* value)
{
  int timeout_millis;
  lifxPacket_t packet;
  timeout_millis = 2000;
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeTileSetEffect, &packet, timeout_millis);
}

