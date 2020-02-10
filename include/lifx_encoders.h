//
// DO NOT EDIT - AUTO-GENERATE:2020-02-09 20:04:33.280642
//
#ifndef __LIFX_ENCODERS_H__
#define __LIFX_ENCODERS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <lifx.h>
#include <lifx_fields.h>
#include <lifx_packets.h>

int lifxEncoder_EncodeDeviceGetService(lifxDeviceGetService_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceStateService(lifxDeviceStateService_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceGetHostInfo(lifxDeviceGetHostInfo_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceStateHostInfo(lifxDeviceStateHostInfo_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceGetHostFirmware(lifxDeviceGetHostFirmware_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceStateHostFirmware(lifxDeviceStateHostFirmware_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceGetWifiInfo(lifxDeviceGetWifiInfo_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceStateWifiInfo(lifxDeviceStateWifiInfo_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceGetWifiFirmware(lifxDeviceGetWifiFirmware_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceStateWifiFirmware(lifxDeviceStateWifiFirmware_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceGetPower(lifxDeviceGetPower_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceSetPower(lifxDeviceSetPower_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceStatePower(lifxDeviceStatePower_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceGetLabel(lifxDeviceGetLabel_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceSetLabel(lifxDeviceSetLabel_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceStateLabel(lifxDeviceStateLabel_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceGetVersion(lifxDeviceGetVersion_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceStateVersion(lifxDeviceStateVersion_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceGetInfo(lifxDeviceGetInfo_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceStateInfo(lifxDeviceStateInfo_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceAcknowledgement(lifxDeviceAcknowledgement_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceGetLocation(lifxDeviceGetLocation_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceSetLocation(lifxDeviceSetLocation_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceStateLocation(lifxDeviceStateLocation_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceGetGroup(lifxDeviceGetGroup_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceSetGroup(lifxDeviceSetGroup_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceStateGroup(lifxDeviceStateGroup_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceEchoRequest(lifxDeviceEchoRequest_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeDeviceEchoResponse(lifxDeviceEchoResponse_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeLightGet(lifxLightGet_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeLightSetColor(lifxLightSetColor_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeLightSetWaveformOptional(lifxLightSetWaveformOptional_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeLightSetWaveform(lifxLightSetWaveform_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeLightGetPower(lifxLightGetPower_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeLightSetPower(lifxLightSetPower_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeLightStatePower(lifxLightStatePower_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeLightState(lifxLightState_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeLightGetInfrared(lifxLightGetInfrared_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeLightStateInfrared(lifxLightStateInfrared_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeLightSetInfrared(lifxLightSetInfrared_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeTileGetDeviceChain(lifxTileGetDeviceChain_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeTileStateDeviceChain(lifxTileStateDeviceChain_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeTileSetUserPosition(lifxTileSetUserPosition_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeTileGet64(lifxTileGet64_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeTileState64(lifxTileState64_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeTileSet64(lifxTileSet64_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeTileGetEffect(lifxTileGetEffect_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeTileSetEffect(lifxTileSetEffect_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeTileStateEffect(lifxTileStateEffect_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeMultiZoneSetColorZones(lifxMultiZoneSetColorZones_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeMultiZoneGetColorZones(lifxMultiZoneGetColorZones_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeMultiZoneStateZone(lifxMultiZoneStateZone_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeMultiZoneStateMultiZone(lifxMultiZoneStateMultiZone_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeMultiZoneGetEffect(lifxMultiZoneGetEffect_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeMultiZoneSetEffect(lifxMultiZoneSetEffect_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeMultiZoneStateEffect(lifxMultiZoneStateEffect_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeMultiZoneExtendedSetColorZones(lifxMultiZoneExtendedSetColorZones_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeMultiZoneExtendedGetColorZones(lifxMultiZoneExtendedGetColorZones_t const* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeMultiZoneExtendedStateMultiZone(lifxMultiZoneExtendedStateMultiZone_t const* pkt, lifxBuffer_t* buff);

int lifxDecoder_DecodeDeviceGetService(lifxDeviceGetService_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceStateService(lifxDeviceStateService_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceGetHostInfo(lifxDeviceGetHostInfo_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceStateHostInfo(lifxDeviceStateHostInfo_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceGetHostFirmware(lifxDeviceGetHostFirmware_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceStateHostFirmware(lifxDeviceStateHostFirmware_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceGetWifiInfo(lifxDeviceGetWifiInfo_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceStateWifiInfo(lifxDeviceStateWifiInfo_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceGetWifiFirmware(lifxDeviceGetWifiFirmware_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceStateWifiFirmware(lifxDeviceStateWifiFirmware_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceGetPower(lifxDeviceGetPower_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceSetPower(lifxDeviceSetPower_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceStatePower(lifxDeviceStatePower_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceGetLabel(lifxDeviceGetLabel_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceSetLabel(lifxDeviceSetLabel_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceStateLabel(lifxDeviceStateLabel_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceGetVersion(lifxDeviceGetVersion_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceStateVersion(lifxDeviceStateVersion_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceGetInfo(lifxDeviceGetInfo_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceStateInfo(lifxDeviceStateInfo_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceAcknowledgement(lifxDeviceAcknowledgement_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceGetLocation(lifxDeviceGetLocation_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceSetLocation(lifxDeviceSetLocation_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceStateLocation(lifxDeviceStateLocation_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceGetGroup(lifxDeviceGetGroup_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceSetGroup(lifxDeviceSetGroup_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceStateGroup(lifxDeviceStateGroup_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceEchoRequest(lifxDeviceEchoRequest_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeDeviceEchoResponse(lifxDeviceEchoResponse_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeLightGet(lifxLightGet_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeLightSetColor(lifxLightSetColor_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeLightSetWaveformOptional(lifxLightSetWaveformOptional_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeLightSetWaveform(lifxLightSetWaveform_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeLightGetPower(lifxLightGetPower_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeLightSetPower(lifxLightSetPower_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeLightStatePower(lifxLightStatePower_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeLightState(lifxLightState_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeLightGetInfrared(lifxLightGetInfrared_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeLightStateInfrared(lifxLightStateInfrared_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeLightSetInfrared(lifxLightSetInfrared_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeTileGetDeviceChain(lifxTileGetDeviceChain_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeTileStateDeviceChain(lifxTileStateDeviceChain_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeTileSetUserPosition(lifxTileSetUserPosition_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeTileGet64(lifxTileGet64_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeTileState64(lifxTileState64_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeTileSet64(lifxTileSet64_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeTileGetEffect(lifxTileGetEffect_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeTileSetEffect(lifxTileSetEffect_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeTileStateEffect(lifxTileStateEffect_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeMultiZoneSetColorZones(lifxMultiZoneSetColorZones_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeMultiZoneGetColorZones(lifxMultiZoneGetColorZones_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeMultiZoneStateZone(lifxMultiZoneStateZone_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeMultiZoneStateMultiZone(lifxMultiZoneStateMultiZone_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeMultiZoneGetEffect(lifxMultiZoneGetEffect_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeMultiZoneSetEffect(lifxMultiZoneSetEffect_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeMultiZoneStateEffect(lifxMultiZoneStateEffect_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeMultiZoneExtendedSetColorZones(lifxMultiZoneExtendedSetColorZones_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeMultiZoneExtendedGetColorZones(lifxMultiZoneExtendedGetColorZones_t* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeMultiZoneExtendedStateMultiZone(lifxMultiZoneExtendedStateMultiZone_t* pkt, lifxBuffer_t* buff);

int lifxEncoder_EncodeLightHsbk(lifxLightHsbk_t const* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeLightHsbk(lifxLightHsbk_t* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeMultiZoneEffectParameter(lifxMultiZoneEffectParameter_t const* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeMultiZoneEffectParameter(lifxMultiZoneEffectParameter_t* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeMultiZoneEffectSettings(lifxMultiZoneEffectSettings_t const* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeMultiZoneEffectSettings(lifxMultiZoneEffectSettings_t* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeTileAccelMeas(lifxTileAccelMeas_t const* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeTileAccelMeas(lifxTileAccelMeas_t* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeTileStateDevice(lifxTileStateDevice_t const* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeTileStateDevice(lifxTileStateDevice_t* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeTileBufferRect(lifxTileBufferRect_t const* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeTileBufferRect(lifxTileBufferRect_t* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeTileEffectParameter(lifxTileEffectParameter_t const* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeTileEffectParameter(lifxTileEffectParameter_t* pkt, lifxBuffer_t* buff);
int lifxEncoder_EncodeTileEffectSettings(lifxTileEffectSettings_t const* pkt, lifxBuffer_t* buff);
int lifxDecoder_DecodeTileEffectSettings(lifxTileEffectSettings_t* pkt, lifxBuffer_t* buff);

#ifdef __cplusplus
}
#endif
#endif
