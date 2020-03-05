//
// DO NOT EDIT - AUTO-GENERATE:2020-03-05 16:03:34.534996
//
#include "lifx.h"

lifxStatus_t lifxDevice_GetService(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateService_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxDeviceGetService_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetService, &packet, timeout);
  if (status == 0)
  {
    *response = packet.DeviceStateService;
  }
  return status;
}

lifxStatus_t lifxDevice_GetHostInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateHostInfo_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxDeviceGetHostInfo_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetHostInfo, &packet, timeout);
  if (status == 0)
  {
    *response = packet.DeviceStateHostInfo;
  }
  return status;
}

lifxStatus_t lifxDevice_GetHostFirmware(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateHostFirmware_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxDeviceGetHostFirmware_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetHostFirmware, &packet, timeout);
  if (status == 0)
  {
    *response = packet.DeviceStateHostFirmware;
  }
  return status;
}

lifxStatus_t lifxDevice_GetWifiInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateWifiInfo_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxDeviceGetWifiInfo_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetWifiInfo, &packet, timeout);
  if (status == 0)
  {
    *response = packet.DeviceStateWifiInfo;
  }
  return status;
}

lifxStatus_t lifxDevice_GetWifiFirmware(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateWifiFirmware_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxDeviceGetWifiFirmware_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetWifiFirmware, &packet, timeout);
  if (status == 0)
  {
    *response = packet.DeviceStateWifiFirmware;
  }
  return status;
}

lifxStatus_t lifxDevice_GetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStatePower_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxDeviceGetPower_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetPower, &packet, timeout);
  if (status == 0)
  {
    *response = packet.DeviceStatePower;
  }
  return status;
}

lifxStatus_t lifxDevice_GetLabel(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateLabel_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxDeviceGetLabel_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetLabel, &packet, timeout);
  if (status == 0)
  {
    *response = packet.DeviceStateLabel;
  }
  return status;
}

lifxStatus_t lifxDevice_GetVersion(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateVersion_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxDeviceGetVersion_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetVersion, &packet, timeout);
  if (status == 0)
  {
    *response = packet.DeviceStateVersion;
  }
  return status;
}

lifxStatus_t lifxDevice_GetInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateInfo_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxDeviceGetInfo_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetInfo, &packet, timeout);
  if (status == 0)
  {
    *response = packet.DeviceStateInfo;
  }
  return status;
}

lifxStatus_t lifxDevice_GetLocation(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateLocation_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxDeviceGetLocation_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetLocation, &packet, timeout);
  if (status == 0)
  {
    *response = packet.DeviceStateLocation;
  }
  return status;
}

lifxStatus_t lifxDevice_GetGroup(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateGroup_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxDeviceGetGroup_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeDeviceGetGroup, &packet, timeout);
  if (status == 0)
  {
    *response = packet.DeviceStateGroup;
  }
  return status;
}

lifxStatus_t lifxLight_Get(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightState_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxLightGet_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeLightGet, &packet, timeout);
  if (status == 0)
  {
    *response = packet.LightState;
  }
  return status;
}

lifxStatus_t lifxLight_GetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightStatePower_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxLightGetPower_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeLightGetPower, &packet, timeout);
  if (status == 0)
  {
    *response = packet.LightStatePower;
  }
  return status;
}

lifxStatus_t lifxLight_GetInfrared(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightStateInfrared_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxLightGetInfrared_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeLightGetInfrared, &packet, timeout);
  if (status == 0)
  {
    *response = packet.LightStateInfrared;
  }
  return status;
}

lifxStatus_t lifxTile_GetDeviceChain(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileStateDeviceChain_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxTileGetDeviceChain_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeTileGetDeviceChain, &packet, timeout);
  if (status == 0)
  {
    *response = packet.TileStateDeviceChain;
  }
  return status;
}

lifxStatus_t lifxTile_Get64(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileState64_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxTileGet64_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeTileGet64, &packet, timeout);
  if (status == 0)
  {
    *response = packet.TileState64;
  }
  return status;
}

lifxStatus_t lifxTile_GetEffect(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileStateEffect_t* response)
{
  lifxStatus_t status;
  lifxPacket_t packet;
  lifxTimeSpan_t timeout;
  lifxTileGetEffect_t request;
  
  timeout = lifxTimeSpan_FromMilliseconds(2000);
  status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketTypeTileGetEffect, &packet, timeout);
  if (status == 0)
  {
    *response = packet.TileStateEffect;
  }
  return status;
}

lifxStatus_t lifxDevice_SetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceSetPower_t const* value)
{
  lifxPacket_t packet;
  lifxTimeSpan_t timeout = lifxTimeSpan_FromMilliseconds(2000);
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeDeviceSetPower, &packet, timeout);
}

lifxStatus_t lifxDevice_SetLabel(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceSetLabel_t const* value)
{
  lifxPacket_t packet;
  lifxTimeSpan_t timeout = lifxTimeSpan_FromMilliseconds(2000);
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeDeviceSetLabel, &packet, timeout);
}

lifxStatus_t lifxDevice_SetLocation(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceSetLocation_t const* value)
{
  lifxPacket_t packet;
  lifxTimeSpan_t timeout = lifxTimeSpan_FromMilliseconds(2000);
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeDeviceSetLocation, &packet, timeout);
}

lifxStatus_t lifxDevice_SetGroup(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceSetGroup_t const* value)
{
  lifxPacket_t packet;
  lifxTimeSpan_t timeout = lifxTimeSpan_FromMilliseconds(2000);
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeDeviceSetGroup, &packet, timeout);
}

lifxStatus_t lifxLight_SetColor(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightSetColor_t const* value)
{
  lifxPacket_t packet;
  lifxTimeSpan_t timeout = lifxTimeSpan_FromMilliseconds(2000);
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeLightSetColor, &packet, timeout);
}

lifxStatus_t lifxLight_SetWaveformOptional(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightSetWaveformOptional_t const* value)
{
  lifxPacket_t packet;
  lifxTimeSpan_t timeout = lifxTimeSpan_FromMilliseconds(2000);
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeLightSetWaveformOptional, &packet, timeout);
}

lifxStatus_t lifxLight_SetWaveform(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightSetWaveform_t const* value)
{
  lifxPacket_t packet;
  lifxTimeSpan_t timeout = lifxTimeSpan_FromMilliseconds(2000);
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeLightSetWaveform, &packet, timeout);
}

lifxStatus_t lifxLight_SetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightSetPower_t const* value)
{
  lifxPacket_t packet;
  lifxTimeSpan_t timeout = lifxTimeSpan_FromMilliseconds(2000);
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeLightSetPower, &packet, timeout);
}

lifxStatus_t lifxLight_SetInfrared(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightSetInfrared_t const* value)
{
  lifxPacket_t packet;
  lifxTimeSpan_t timeout = lifxTimeSpan_FromMilliseconds(2000);
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeLightSetInfrared, &packet, timeout);
}

lifxStatus_t lifxTile_SetUserPosition(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileSetUserPosition_t const* value)
{
  lifxPacket_t packet;
  lifxTimeSpan_t timeout = lifxTimeSpan_FromMilliseconds(2000);
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeTileSetUserPosition, &packet, timeout);
}

lifxStatus_t lifxTile_Set64(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileSet64_t const* value)
{
  lifxPacket_t packet;
  lifxTimeSpan_t timeout = lifxTimeSpan_FromMilliseconds(2000);
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeTileSet64, &packet, timeout);
}

lifxStatus_t lifxTile_SetEffect(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileSetEffect_t const* value)
{
  lifxPacket_t packet;
  lifxTimeSpan_t timeout = lifxTimeSpan_FromMilliseconds(2000);
  return lifxSession_SendRequest(lifx, deviceId, value, kLifxPacketTypeTileSetEffect, &packet, timeout);
}

