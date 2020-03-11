//
// DO NOT EDIT - AUTO-GENERATE:2020-03-09 23:14:54.589988
//
#include "lifx.h"
#include "lifx_private.h"

lifxStatus_t lifxDevice_GetService(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxDeviceStateService_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxDeviceGetService_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeDeviceGetService, response,
    sizeof(lifxDeviceStateService_t), &packet, &packet.DeviceStateService, opts);
}

lifxStatus_t lifxDevice_GetHostInfo(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxDeviceStateHostInfo_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxDeviceGetHostInfo_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeDeviceGetHostInfo, response,
    sizeof(lifxDeviceStateHostInfo_t), &packet, &packet.DeviceStateHostInfo, opts);
}

lifxStatus_t lifxDevice_GetHostFirmware(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxDeviceStateHostFirmware_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxDeviceGetHostFirmware_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeDeviceGetHostFirmware, response,
    sizeof(lifxDeviceStateHostFirmware_t), &packet, &packet.DeviceStateHostFirmware, opts);
}

lifxStatus_t lifxDevice_GetWifiInfo(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxDeviceStateWifiInfo_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxDeviceGetWifiInfo_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeDeviceGetWifiInfo, response,
    sizeof(lifxDeviceStateWifiInfo_t), &packet, &packet.DeviceStateWifiInfo, opts);
}

lifxStatus_t lifxDevice_GetWifiFirmware(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxDeviceStateWifiFirmware_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxDeviceGetWifiFirmware_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeDeviceGetWifiFirmware, response,
    sizeof(lifxDeviceStateWifiFirmware_t), &packet, &packet.DeviceStateWifiFirmware, opts);
}

lifxStatus_t lifxDevice_GetPower(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxDeviceStatePower_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxDeviceGetPower_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeDeviceGetPower, response,
    sizeof(lifxDeviceStatePower_t), &packet, &packet.DeviceStatePower, opts);
}

lifxStatus_t lifxDevice_GetLabel(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxDeviceStateLabel_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxDeviceGetLabel_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeDeviceGetLabel, response,
    sizeof(lifxDeviceStateLabel_t), &packet, &packet.DeviceStateLabel, opts);
}

lifxStatus_t lifxDevice_GetVersion(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxDeviceStateVersion_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxDeviceGetVersion_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeDeviceGetVersion, response,
    sizeof(lifxDeviceStateVersion_t), &packet, &packet.DeviceStateVersion, opts);
}

lifxStatus_t lifxDevice_GetInfo(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxDeviceStateInfo_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxDeviceGetInfo_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeDeviceGetInfo, response,
    sizeof(lifxDeviceStateInfo_t), &packet, &packet.DeviceStateInfo, opts);
}

lifxStatus_t lifxDevice_GetLocation(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxDeviceStateLocation_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxDeviceGetLocation_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeDeviceGetLocation, response,
    sizeof(lifxDeviceStateLocation_t), &packet, &packet.DeviceStateLocation, opts);
}

lifxStatus_t lifxDevice_GetGroup(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxDeviceStateGroup_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxDeviceGetGroup_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeDeviceGetGroup, response,
    sizeof(lifxDeviceStateGroup_t), &packet, &packet.DeviceStateGroup, opts);
}

lifxStatus_t lifxLight_Get(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxLightState_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxLightGet_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeLightGet, response,
    sizeof(lifxLightState_t), &packet, &packet.LightState, opts);
}

lifxStatus_t lifxLight_GetPower(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxLightStatePower_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxLightGetPower_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeLightGetPower, response,
    sizeof(lifxLightStatePower_t), &packet, &packet.LightStatePower, opts);
}

lifxStatus_t lifxLight_GetInfrared(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxLightStateInfrared_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxLightGetInfrared_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeLightGetInfrared, response,
    sizeof(lifxLightStateInfrared_t), &packet, &packet.LightStateInfrared, opts);
}

lifxStatus_t lifxTile_GetDeviceChain(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxTileStateDeviceChain_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxTileGetDeviceChain_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeTileGetDeviceChain, response,
    sizeof(lifxTileStateDeviceChain_t), &packet, &packet.TileStateDeviceChain, opts);
}

lifxStatus_t lifxTile_Get64(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxTileState64_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxTileGet64_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeTileGet64, response,
    sizeof(lifxTileState64_t), &packet, &packet.TileState64, opts);
}

lifxStatus_t lifxTile_GetEffect(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxTileStateEffect_t* response, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  lifxTileGetEffect_t request;
  return lifxSession_SendWithOptions(lifx, device_id, &request, kLifxPacketTypeTileGetEffect, response,
    sizeof(lifxTileStateEffect_t), &packet, &packet.TileStateEffect, opts);
}

lifxStatus_t lifxDevice_SetPower(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxDeviceSetPower_t const* value, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  return lifxSession_SendWithOptions(lifx, device_id, value, kLifxPacketTypeDeviceSetPower,
    NULL, 0, &packet, NULL, opts);
}

lifxStatus_t lifxDevice_SetLabel(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxDeviceSetLabel_t const* value, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  return lifxSession_SendWithOptions(lifx, device_id, value, kLifxPacketTypeDeviceSetLabel,
    NULL, 0, &packet, NULL, opts);
}

lifxStatus_t lifxDevice_SetLocation(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxDeviceSetLocation_t const* value, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  return lifxSession_SendWithOptions(lifx, device_id, value, kLifxPacketTypeDeviceSetLocation,
    NULL, 0, &packet, NULL, opts);
}

lifxStatus_t lifxDevice_SetGroup(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxDeviceSetGroup_t const* value, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  return lifxSession_SendWithOptions(lifx, device_id, value, kLifxPacketTypeDeviceSetGroup,
    NULL, 0, &packet, NULL, opts);
}

lifxStatus_t lifxLight_SetColor(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxLightSetColor_t const* value, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  return lifxSession_SendWithOptions(lifx, device_id, value, kLifxPacketTypeLightSetColor,
    NULL, 0, &packet, NULL, opts);
}

lifxStatus_t lifxLight_SetWaveformOptional(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxLightSetWaveformOptional_t const* value, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  return lifxSession_SendWithOptions(lifx, device_id, value, kLifxPacketTypeLightSetWaveformOptional,
    NULL, 0, &packet, NULL, opts);
}

lifxStatus_t lifxLight_SetWaveform(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxLightSetWaveform_t const* value, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  return lifxSession_SendWithOptions(lifx, device_id, value, kLifxPacketTypeLightSetWaveform,
    NULL, 0, &packet, NULL, opts);
}

lifxStatus_t lifxLight_SetPower(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxLightSetPower_t const* value, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  return lifxSession_SendWithOptions(lifx, device_id, value, kLifxPacketTypeLightSetPower,
    NULL, 0, &packet, NULL, opts);
}

lifxStatus_t lifxLight_SetInfrared(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxLightSetInfrared_t const* value, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  return lifxSession_SendWithOptions(lifx, device_id, value, kLifxPacketTypeLightSetInfrared,
    NULL, 0, &packet, NULL, opts);
}

lifxStatus_t lifxTile_SetUserPosition(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxTileSetUserPosition_t const* value, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  return lifxSession_SendWithOptions(lifx, device_id, value, kLifxPacketTypeTileSetUserPosition,
    NULL, 0, &packet, NULL, opts);
}

lifxStatus_t lifxTile_Set64(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxTileSet64_t const* value, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  return lifxSession_SendWithOptions(lifx, device_id, value, kLifxPacketTypeTileSet64,
    NULL, 0, &packet, NULL, opts);
}

lifxStatus_t lifxTile_SetEffect(lifxSession_t* lifx, lifxDeviceId_t device_id, lifxTileSetEffect_t const* value, lifxRequestOptions_t const* opts)
{
  lifxPacket_t packet;
  return lifxSession_SendWithOptions(lifx, device_id, value, kLifxPacketTypeTileSetEffect,
    NULL, 0, &packet, NULL, opts);
}

