//
// DO NOT EDIT - AUTO-GENERATE:2020-03-09 23:14:54.588841
//
#ifndef LIFX_REQUESTS_H
#define LIFX_REQUESTS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <lifx_common.h>
#include <lifx_packets.h>

// ---BEGIN GETTERS---
LIFX_PUBLIC lifxStatus_t lifxDevice_GetService(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateService_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxDevice_GetHostInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateHostInfo_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxDevice_GetHostFirmware(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateHostFirmware_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxDevice_GetWifiInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateWifiInfo_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxDevice_GetWifiFirmware(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateWifiFirmware_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxDevice_GetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStatePower_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxDevice_GetLabel(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateLabel_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxDevice_GetVersion(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateVersion_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxDevice_GetInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateInfo_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxDevice_GetLocation(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateLocation_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxDevice_GetGroup(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateGroup_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxLight_Get(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightState_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxLight_GetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightStatePower_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxLight_GetInfrared(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightStateInfrared_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxTile_GetDeviceChain(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileStateDeviceChain_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxTile_Get64(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileState64_t* response, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxTile_GetEffect(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileStateEffect_t* response, lifxRequestOptions_t const* opts);
// ---END GETTERS---

// ---BEGIN SETTERS---
LIFX_PUBLIC lifxStatus_t lifxDevice_SetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceSetPower_t const* value, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxDevice_SetLabel(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceSetLabel_t const* value, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxDevice_SetLocation(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceSetLocation_t const* value, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxDevice_SetGroup(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceSetGroup_t const* value, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxLight_SetColor(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightSetColor_t const* value, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxLight_SetWaveformOptional(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightSetWaveformOptional_t const* value, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxLight_SetWaveform(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightSetWaveform_t const* value, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxLight_SetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightSetPower_t const* value, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxLight_SetInfrared(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightSetInfrared_t const* value, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxTile_SetUserPosition(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileSetUserPosition_t const* value, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxTile_Set64(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileSet64_t const* value, lifxRequestOptions_t const* opts);
LIFX_PUBLIC lifxStatus_t lifxTile_SetEffect(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileSetEffect_t const* value, lifxRequestOptions_t const* opts);

#ifdef __cplusplus
}
#endif
#endif
