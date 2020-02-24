//
// DO NOT EDIT - AUTO-GENERATE:2020-02-24 16:44:03.998248
//
#ifndef LIFX_REQUESTS_H
#define LIFX_REQUESTS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <lifx_common.h>
#include <lifx_packets.h>

LIFX_EXPORT lifxStatus_t lifxDevice_GetService(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateService_t* response);
LIFX_EXPORT lifxStatus_t lifxDevice_GetHostInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateHostInfo_t* response);
LIFX_EXPORT lifxStatus_t lifxDevice_GetHostFirmware(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateHostFirmware_t* response);
LIFX_EXPORT lifxStatus_t lifxDevice_GetWifiInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateWifiInfo_t* response);
LIFX_EXPORT lifxStatus_t lifxDevice_GetWifiFirmware(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateWifiFirmware_t* response);
LIFX_EXPORT lifxStatus_t lifxDevice_GetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStatePower_t* response);
LIFX_EXPORT lifxStatus_t lifxDevice_GetLabel(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateLabel_t* response);
LIFX_EXPORT lifxStatus_t lifxDevice_GetVersion(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateVersion_t* response);
LIFX_EXPORT lifxStatus_t lifxDevice_GetInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateInfo_t* response);
LIFX_EXPORT lifxStatus_t lifxDevice_GetLocation(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateLocation_t* response);
LIFX_EXPORT lifxStatus_t lifxDevice_GetGroup(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateGroup_t* response);
LIFX_EXPORT lifxStatus_t lifxLight_Get(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightState_t* response);
LIFX_EXPORT lifxStatus_t lifxLight_GetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightStatePower_t* response);
LIFX_EXPORT lifxStatus_t lifxLight_GetInfrared(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightStateInfrared_t* response);
LIFX_EXPORT lifxStatus_t lifxTileGetDeviceChain(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileStateDeviceChain_t* response);
LIFX_EXPORT lifxStatus_t lifxTileGet64(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileState64_t* response);
LIFX_EXPORT lifxStatus_t lifxTileGetEffect(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileStateEffect_t* response);

#ifdef __cplusplus
}
#endif
#endif
