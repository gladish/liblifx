//
// DO NOT EDIT - AUTO-GENERATE:2020-02-21 13:45:06.412240
//
#ifndef __LIFX_REQUESTS_H__
#define __LIFX_REQUESTS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <lifx_common.h>
#include <lifx_packets.h>

LIFX_EXPORT int lifxDevice_GetService(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateService_t* response);
LIFX_EXPORT int lifxDevice_GetHostInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateHostInfo_t* response);
LIFX_EXPORT int lifxDevice_GetHostFirmware(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateHostFirmware_t* response);
LIFX_EXPORT int lifxDevice_GetWifiInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateWifiInfo_t* response);
LIFX_EXPORT int lifxDevice_GetWifiFirmware(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateWifiFirmware_t* response);
LIFX_EXPORT int lifxDevice_GetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStatePower_t* response);
LIFX_EXPORT int lifxDevice_GetLabel(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateLabel_t* response);
LIFX_EXPORT int lifxDevice_GetVersion(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateVersion_t* response);
LIFX_EXPORT int lifxDevice_GetInfo(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateInfo_t* response);
LIFX_EXPORT int lifxDevice_GetLocation(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateLocation_t* response);
LIFX_EXPORT int lifxDevice_GetGroup(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxDeviceStateGroup_t* response);
LIFX_EXPORT int lifxLight_Get(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightState_t* response);
LIFX_EXPORT int lifxLight_GetPower(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightStatePower_t* response);
LIFX_EXPORT int lifxLight_GetInfrared(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxLightStateInfrared_t* response);
LIFX_EXPORT int lifxTileGetDeviceChain(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileStateDeviceChain_t* response);
LIFX_EXPORT int lifxTileGet64(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileState64_t* response);
LIFX_EXPORT int lifxTileGetEffect(lifxSession_t* lifx, lifxDeviceId_t deviceId, lifxTileStateEffect_t* response);

#ifdef __cplusplus
}
#endif
#endif
