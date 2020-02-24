//
// DO NOT EDIT - AUTO-GENERATE:2020-02-24 16:44:03.992889
//
#ifndef LIFX_ENCODERS_H
#define LIFX_ENCODERS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <lifx.h>
#include <lifx_fields.h>
#include <lifx_packets.h>

lifxStatus_t lifxDecoder_DecodePacket(lifxBuffer_t* buff, lifxPacketType_t type, lifxPacket_t* pkt);
lifxStatus_t lifxEncoder_EncodePacket(lifxBuffer_t* buff, lifxPacketType_t type, lifxPacket_t const* pkt);
int lifxEncoder_GetEncodedSize(lifxPacketType_t type);

lifxStatus_t lifxEncoder_EncodeDeviceGetService(lifxBuffer_t* buff, lifxDeviceGetService_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceStateService(lifxBuffer_t* buff, lifxDeviceStateService_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceGetHostInfo(lifxBuffer_t* buff, lifxDeviceGetHostInfo_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceStateHostInfo(lifxBuffer_t* buff, lifxDeviceStateHostInfo_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceGetHostFirmware(lifxBuffer_t* buff, lifxDeviceGetHostFirmware_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceStateHostFirmware(lifxBuffer_t* buff, lifxDeviceStateHostFirmware_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceGetWifiInfo(lifxBuffer_t* buff, lifxDeviceGetWifiInfo_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceStateWifiInfo(lifxBuffer_t* buff, lifxDeviceStateWifiInfo_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceGetWifiFirmware(lifxBuffer_t* buff, lifxDeviceGetWifiFirmware_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceStateWifiFirmware(lifxBuffer_t* buff, lifxDeviceStateWifiFirmware_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceGetPower(lifxBuffer_t* buff, lifxDeviceGetPower_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceSetPower(lifxBuffer_t* buff, lifxDeviceSetPower_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceStatePower(lifxBuffer_t* buff, lifxDeviceStatePower_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceGetLabel(lifxBuffer_t* buff, lifxDeviceGetLabel_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceSetLabel(lifxBuffer_t* buff, lifxDeviceSetLabel_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceStateLabel(lifxBuffer_t* buff, lifxDeviceStateLabel_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceGetVersion(lifxBuffer_t* buff, lifxDeviceGetVersion_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceStateVersion(lifxBuffer_t* buff, lifxDeviceStateVersion_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceGetInfo(lifxBuffer_t* buff, lifxDeviceGetInfo_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceStateInfo(lifxBuffer_t* buff, lifxDeviceStateInfo_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceAcknowledgement(lifxBuffer_t* buff, lifxDeviceAcknowledgement_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceGetLocation(lifxBuffer_t* buff, lifxDeviceGetLocation_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceSetLocation(lifxBuffer_t* buff, lifxDeviceSetLocation_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceStateLocation(lifxBuffer_t* buff, lifxDeviceStateLocation_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceGetGroup(lifxBuffer_t* buff, lifxDeviceGetGroup_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceSetGroup(lifxBuffer_t* buff, lifxDeviceSetGroup_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceStateGroup(lifxBuffer_t* buff, lifxDeviceStateGroup_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceEchoRequest(lifxBuffer_t* buff, lifxDeviceEchoRequest_t const* pkt);
lifxStatus_t lifxEncoder_EncodeDeviceEchoResponse(lifxBuffer_t* buff, lifxDeviceEchoResponse_t const* pkt);
lifxStatus_t lifxEncoder_EncodeLightGet(lifxBuffer_t* buff, lifxLightGet_t const* pkt);
lifxStatus_t lifxEncoder_EncodeLightSetColor(lifxBuffer_t* buff, lifxLightSetColor_t const* pkt);
lifxStatus_t lifxEncoder_EncodeLightSetWaveformOptional(lifxBuffer_t* buff, lifxLightSetWaveformOptional_t const* pkt);
lifxStatus_t lifxEncoder_EncodeLightSetWaveform(lifxBuffer_t* buff, lifxLightSetWaveform_t const* pkt);
lifxStatus_t lifxEncoder_EncodeLightGetPower(lifxBuffer_t* buff, lifxLightGetPower_t const* pkt);
lifxStatus_t lifxEncoder_EncodeLightSetPower(lifxBuffer_t* buff, lifxLightSetPower_t const* pkt);
lifxStatus_t lifxEncoder_EncodeLightStatePower(lifxBuffer_t* buff, lifxLightStatePower_t const* pkt);
lifxStatus_t lifxEncoder_EncodeLightState(lifxBuffer_t* buff, lifxLightState_t const* pkt);
lifxStatus_t lifxEncoder_EncodeLightGetInfrared(lifxBuffer_t* buff, lifxLightGetInfrared_t const* pkt);
lifxStatus_t lifxEncoder_EncodeLightStateInfrared(lifxBuffer_t* buff, lifxLightStateInfrared_t const* pkt);
lifxStatus_t lifxEncoder_EncodeLightSetInfrared(lifxBuffer_t* buff, lifxLightSetInfrared_t const* pkt);
lifxStatus_t lifxEncoder_EncodeTileGetDeviceChain(lifxBuffer_t* buff, lifxTileGetDeviceChain_t const* pkt);
lifxStatus_t lifxEncoder_EncodeTileStateDeviceChain(lifxBuffer_t* buff, lifxTileStateDeviceChain_t const* pkt);
lifxStatus_t lifxEncoder_EncodeTileSetUserPosition(lifxBuffer_t* buff, lifxTileSetUserPosition_t const* pkt);
lifxStatus_t lifxEncoder_EncodeTileGet64(lifxBuffer_t* buff, lifxTileGet64_t const* pkt);
lifxStatus_t lifxEncoder_EncodeTileState64(lifxBuffer_t* buff, lifxTileState64_t const* pkt);
lifxStatus_t lifxEncoder_EncodeTileSet64(lifxBuffer_t* buff, lifxTileSet64_t const* pkt);
lifxStatus_t lifxEncoder_EncodeTileGetEffect(lifxBuffer_t* buff, lifxTileGetEffect_t const* pkt);
lifxStatus_t lifxEncoder_EncodeTileSetEffect(lifxBuffer_t* buff, lifxTileSetEffect_t const* pkt);
lifxStatus_t lifxEncoder_EncodeTileStateEffect(lifxBuffer_t* buff, lifxTileStateEffect_t const* pkt);
lifxStatus_t lifxEncoder_EncodeMultiZoneSetColorZones(lifxBuffer_t* buff, lifxMultiZoneSetColorZones_t const* pkt);
lifxStatus_t lifxEncoder_EncodeMultiZoneGetColorZones(lifxBuffer_t* buff, lifxMultiZoneGetColorZones_t const* pkt);
lifxStatus_t lifxEncoder_EncodeMultiZoneStateZone(lifxBuffer_t* buff, lifxMultiZoneStateZone_t const* pkt);
lifxStatus_t lifxEncoder_EncodeMultiZoneStateMultiZone(lifxBuffer_t* buff, lifxMultiZoneStateMultiZone_t const* pkt);
lifxStatus_t lifxEncoder_EncodeMultiZoneGetEffect(lifxBuffer_t* buff, lifxMultiZoneGetEffect_t const* pkt);
lifxStatus_t lifxEncoder_EncodeMultiZoneSetEffect(lifxBuffer_t* buff, lifxMultiZoneSetEffect_t const* pkt);
lifxStatus_t lifxEncoder_EncodeMultiZoneStateEffect(lifxBuffer_t* buff, lifxMultiZoneStateEffect_t const* pkt);
lifxStatus_t lifxEncoder_EncodeMultiZoneExtendedSetColorZones(lifxBuffer_t* buff, lifxMultiZoneExtendedSetColorZones_t const* pkt);
lifxStatus_t lifxEncoder_EncodeMultiZoneExtendedGetColorZones(lifxBuffer_t* buff, lifxMultiZoneExtendedGetColorZones_t const* pkt);
lifxStatus_t lifxEncoder_EncodeMultiZoneExtendedStateMultiZone(lifxBuffer_t* buff, lifxMultiZoneExtendedStateMultiZone_t const* pkt);

lifxStatus_t lifxDecoder_DecodeDeviceGetService(lifxBuffer_t* buff, lifxDeviceGetService_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceStateService(lifxBuffer_t* buff, lifxDeviceStateService_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceGetHostInfo(lifxBuffer_t* buff, lifxDeviceGetHostInfo_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceStateHostInfo(lifxBuffer_t* buff, lifxDeviceStateHostInfo_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceGetHostFirmware(lifxBuffer_t* buff, lifxDeviceGetHostFirmware_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceStateHostFirmware(lifxBuffer_t* buff, lifxDeviceStateHostFirmware_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceGetWifiInfo(lifxBuffer_t* buff, lifxDeviceGetWifiInfo_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceStateWifiInfo(lifxBuffer_t* buff, lifxDeviceStateWifiInfo_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceGetWifiFirmware(lifxBuffer_t* buff, lifxDeviceGetWifiFirmware_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceStateWifiFirmware(lifxBuffer_t* buff, lifxDeviceStateWifiFirmware_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceGetPower(lifxBuffer_t* buff, lifxDeviceGetPower_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceSetPower(lifxBuffer_t* buff, lifxDeviceSetPower_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceStatePower(lifxBuffer_t* buff, lifxDeviceStatePower_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceGetLabel(lifxBuffer_t* buff, lifxDeviceGetLabel_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceSetLabel(lifxBuffer_t* buff, lifxDeviceSetLabel_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceStateLabel(lifxBuffer_t* buff, lifxDeviceStateLabel_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceGetVersion(lifxBuffer_t* buff, lifxDeviceGetVersion_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceStateVersion(lifxBuffer_t* buff, lifxDeviceStateVersion_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceGetInfo(lifxBuffer_t* buff, lifxDeviceGetInfo_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceStateInfo(lifxBuffer_t* buff, lifxDeviceStateInfo_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceAcknowledgement(lifxBuffer_t* buff, lifxDeviceAcknowledgement_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceGetLocation(lifxBuffer_t* buff, lifxDeviceGetLocation_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceSetLocation(lifxBuffer_t* buff, lifxDeviceSetLocation_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceStateLocation(lifxBuffer_t* buff, lifxDeviceStateLocation_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceGetGroup(lifxBuffer_t* buff, lifxDeviceGetGroup_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceSetGroup(lifxBuffer_t* buff, lifxDeviceSetGroup_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceStateGroup(lifxBuffer_t* buff, lifxDeviceStateGroup_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceEchoRequest(lifxBuffer_t* buff, lifxDeviceEchoRequest_t* pkt);
lifxStatus_t lifxDecoder_DecodeDeviceEchoResponse(lifxBuffer_t* buff, lifxDeviceEchoResponse_t* pkt);
lifxStatus_t lifxDecoder_DecodeLightGet(lifxBuffer_t* buff, lifxLightGet_t* pkt);
lifxStatus_t lifxDecoder_DecodeLightSetColor(lifxBuffer_t* buff, lifxLightSetColor_t* pkt);
lifxStatus_t lifxDecoder_DecodeLightSetWaveformOptional(lifxBuffer_t* buff, lifxLightSetWaveformOptional_t* pkt);
lifxStatus_t lifxDecoder_DecodeLightSetWaveform(lifxBuffer_t* buff, lifxLightSetWaveform_t* pkt);
lifxStatus_t lifxDecoder_DecodeLightGetPower(lifxBuffer_t* buff, lifxLightGetPower_t* pkt);
lifxStatus_t lifxDecoder_DecodeLightSetPower(lifxBuffer_t* buff, lifxLightSetPower_t* pkt);
lifxStatus_t lifxDecoder_DecodeLightStatePower(lifxBuffer_t* buff, lifxLightStatePower_t* pkt);
lifxStatus_t lifxDecoder_DecodeLightState(lifxBuffer_t* buff, lifxLightState_t* pkt);
lifxStatus_t lifxDecoder_DecodeLightGetInfrared(lifxBuffer_t* buff, lifxLightGetInfrared_t* pkt);
lifxStatus_t lifxDecoder_DecodeLightStateInfrared(lifxBuffer_t* buff, lifxLightStateInfrared_t* pkt);
lifxStatus_t lifxDecoder_DecodeLightSetInfrared(lifxBuffer_t* buff, lifxLightSetInfrared_t* pkt);
lifxStatus_t lifxDecoder_DecodeTileGetDeviceChain(lifxBuffer_t* buff, lifxTileGetDeviceChain_t* pkt);
lifxStatus_t lifxDecoder_DecodeTileStateDeviceChain(lifxBuffer_t* buff, lifxTileStateDeviceChain_t* pkt);
lifxStatus_t lifxDecoder_DecodeTileSetUserPosition(lifxBuffer_t* buff, lifxTileSetUserPosition_t* pkt);
lifxStatus_t lifxDecoder_DecodeTileGet64(lifxBuffer_t* buff, lifxTileGet64_t* pkt);
lifxStatus_t lifxDecoder_DecodeTileState64(lifxBuffer_t* buff, lifxTileState64_t* pkt);
lifxStatus_t lifxDecoder_DecodeTileSet64(lifxBuffer_t* buff, lifxTileSet64_t* pkt);
lifxStatus_t lifxDecoder_DecodeTileGetEffect(lifxBuffer_t* buff, lifxTileGetEffect_t* pkt);
lifxStatus_t lifxDecoder_DecodeTileSetEffect(lifxBuffer_t* buff, lifxTileSetEffect_t* pkt);
lifxStatus_t lifxDecoder_DecodeTileStateEffect(lifxBuffer_t* buff, lifxTileStateEffect_t* pkt);
lifxStatus_t lifxDecoder_DecodeMultiZoneSetColorZones(lifxBuffer_t* buff, lifxMultiZoneSetColorZones_t* pkt);
lifxStatus_t lifxDecoder_DecodeMultiZoneGetColorZones(lifxBuffer_t* buff, lifxMultiZoneGetColorZones_t* pkt);
lifxStatus_t lifxDecoder_DecodeMultiZoneStateZone(lifxBuffer_t* buff, lifxMultiZoneStateZone_t* pkt);
lifxStatus_t lifxDecoder_DecodeMultiZoneStateMultiZone(lifxBuffer_t* buff, lifxMultiZoneStateMultiZone_t* pkt);
lifxStatus_t lifxDecoder_DecodeMultiZoneGetEffect(lifxBuffer_t* buff, lifxMultiZoneGetEffect_t* pkt);
lifxStatus_t lifxDecoder_DecodeMultiZoneSetEffect(lifxBuffer_t* buff, lifxMultiZoneSetEffect_t* pkt);
lifxStatus_t lifxDecoder_DecodeMultiZoneStateEffect(lifxBuffer_t* buff, lifxMultiZoneStateEffect_t* pkt);
lifxStatus_t lifxDecoder_DecodeMultiZoneExtendedSetColorZones(lifxBuffer_t* buff, lifxMultiZoneExtendedSetColorZones_t* pkt);
lifxStatus_t lifxDecoder_DecodeMultiZoneExtendedGetColorZones(lifxBuffer_t* buff, lifxMultiZoneExtendedGetColorZones_t* pkt);
lifxStatus_t lifxDecoder_DecodeMultiZoneExtendedStateMultiZone(lifxBuffer_t* buff, lifxMultiZoneExtendedStateMultiZone_t* pkt);

lifxStatus_t lifxEncoder_EncodeLightHsbk(lifxBuffer_t* buff, lifxLightHsbk_t const* pkt);
lifxStatus_t lifxDecoder_DecodeLightHsbk(lifxBuffer_t* buff, lifxLightHsbk_t* pkt);
lifxStatus_t lifxEncoder_EncodeMultiZoneEffectParameter(lifxBuffer_t* buff, lifxMultiZoneEffectParameter_t const* pkt);
lifxStatus_t lifxDecoder_DecodeMultiZoneEffectParameter(lifxBuffer_t* buff, lifxMultiZoneEffectParameter_t* pkt);
lifxStatus_t lifxEncoder_EncodeMultiZoneEffectSettings(lifxBuffer_t* buff, lifxMultiZoneEffectSettings_t const* pkt);
lifxStatus_t lifxDecoder_DecodeMultiZoneEffectSettings(lifxBuffer_t* buff, lifxMultiZoneEffectSettings_t* pkt);
lifxStatus_t lifxEncoder_EncodeTileAccelMeas(lifxBuffer_t* buff, lifxTileAccelMeas_t const* pkt);
lifxStatus_t lifxDecoder_DecodeTileAccelMeas(lifxBuffer_t* buff, lifxTileAccelMeas_t* pkt);
lifxStatus_t lifxEncoder_EncodeTileStateDevice(lifxBuffer_t* buff, lifxTileStateDevice_t const* pkt);
lifxStatus_t lifxDecoder_DecodeTileStateDevice(lifxBuffer_t* buff, lifxTileStateDevice_t* pkt);
lifxStatus_t lifxEncoder_EncodeTileBufferRect(lifxBuffer_t* buff, lifxTileBufferRect_t const* pkt);
lifxStatus_t lifxDecoder_DecodeTileBufferRect(lifxBuffer_t* buff, lifxTileBufferRect_t* pkt);
lifxStatus_t lifxEncoder_EncodeTileEffectParameter(lifxBuffer_t* buff, lifxTileEffectParameter_t const* pkt);
lifxStatus_t lifxDecoder_DecodeTileEffectParameter(lifxBuffer_t* buff, lifxTileEffectParameter_t* pkt);
lifxStatus_t lifxEncoder_EncodeTileEffectSettings(lifxBuffer_t* buff, lifxTileEffectSettings_t const* pkt);
lifxStatus_t lifxDecoder_DecodeTileEffectSettings(lifxBuffer_t* buff, lifxTileEffectSettings_t* pkt);

#ifdef __cplusplus
}
#endif
#endif
