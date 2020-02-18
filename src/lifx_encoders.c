//
// DO NOT EDIT - AUTO-GENERATE:2020-02-17 21:03:16.981975
//
#include "lifx.h"
#include "lifx_encoders.h"

int lifxDecoder_DecodePacket(lifxBuffer_t* buff, lifxPacketType_t type, lifxPacket_t* pkt)
{
  int ret = 0;
  switch (type)
  {
    case kLifxPacketTypeDeviceGetService:
    ret = lifxDecoder_DecodeDeviceGetService(buff, &pkt->DeviceGetService);
    break;
    case kLifxPacketTypeDeviceStateService:
    ret = lifxDecoder_DecodeDeviceStateService(buff, &pkt->DeviceStateService);
    break;
    case kLifxPacketTypeDeviceGetHostInfo:
    ret = lifxDecoder_DecodeDeviceGetHostInfo(buff, &pkt->DeviceGetHostInfo);
    break;
    case kLifxPacketTypeDeviceStateHostInfo:
    ret = lifxDecoder_DecodeDeviceStateHostInfo(buff, &pkt->DeviceStateHostInfo);
    break;
    case kLifxPacketTypeDeviceGetHostFirmware:
    ret = lifxDecoder_DecodeDeviceGetHostFirmware(buff, &pkt->DeviceGetHostFirmware);
    break;
    case kLifxPacketTypeDeviceStateHostFirmware:
    ret = lifxDecoder_DecodeDeviceStateHostFirmware(buff, &pkt->DeviceStateHostFirmware);
    break;
    case kLifxPacketTypeDeviceGetWifiInfo:
    ret = lifxDecoder_DecodeDeviceGetWifiInfo(buff, &pkt->DeviceGetWifiInfo);
    break;
    case kLifxPacketTypeDeviceStateWifiInfo:
    ret = lifxDecoder_DecodeDeviceStateWifiInfo(buff, &pkt->DeviceStateWifiInfo);
    break;
    case kLifxPacketTypeDeviceGetWifiFirmware:
    ret = lifxDecoder_DecodeDeviceGetWifiFirmware(buff, &pkt->DeviceGetWifiFirmware);
    break;
    case kLifxPacketTypeDeviceStateWifiFirmware:
    ret = lifxDecoder_DecodeDeviceStateWifiFirmware(buff, &pkt->DeviceStateWifiFirmware);
    break;
    case kLifxPacketTypeDeviceGetPower:
    ret = lifxDecoder_DecodeDeviceGetPower(buff, &pkt->DeviceGetPower);
    break;
    case kLifxPacketTypeDeviceSetPower:
    ret = lifxDecoder_DecodeDeviceSetPower(buff, &pkt->DeviceSetPower);
    break;
    case kLifxPacketTypeDeviceStatePower:
    ret = lifxDecoder_DecodeDeviceStatePower(buff, &pkt->DeviceStatePower);
    break;
    case kLifxPacketTypeDeviceGetLabel:
    ret = lifxDecoder_DecodeDeviceGetLabel(buff, &pkt->DeviceGetLabel);
    break;
    case kLifxPacketTypeDeviceSetLabel:
    ret = lifxDecoder_DecodeDeviceSetLabel(buff, &pkt->DeviceSetLabel);
    break;
    case kLifxPacketTypeDeviceStateLabel:
    ret = lifxDecoder_DecodeDeviceStateLabel(buff, &pkt->DeviceStateLabel);
    break;
    case kLifxPacketTypeDeviceGetVersion:
    ret = lifxDecoder_DecodeDeviceGetVersion(buff, &pkt->DeviceGetVersion);
    break;
    case kLifxPacketTypeDeviceStateVersion:
    ret = lifxDecoder_DecodeDeviceStateVersion(buff, &pkt->DeviceStateVersion);
    break;
    case kLifxPacketTypeDeviceGetInfo:
    ret = lifxDecoder_DecodeDeviceGetInfo(buff, &pkt->DeviceGetInfo);
    break;
    case kLifxPacketTypeDeviceStateInfo:
    ret = lifxDecoder_DecodeDeviceStateInfo(buff, &pkt->DeviceStateInfo);
    break;
    case kLifxPacketTypeDeviceAcknowledgement:
    ret = lifxDecoder_DecodeDeviceAcknowledgement(buff, &pkt->DeviceAcknowledgement);
    break;
    case kLifxPacketTypeDeviceGetLocation:
    ret = lifxDecoder_DecodeDeviceGetLocation(buff, &pkt->DeviceGetLocation);
    break;
    case kLifxPacketTypeDeviceSetLocation:
    ret = lifxDecoder_DecodeDeviceSetLocation(buff, &pkt->DeviceSetLocation);
    break;
    case kLifxPacketTypeDeviceStateLocation:
    ret = lifxDecoder_DecodeDeviceStateLocation(buff, &pkt->DeviceStateLocation);
    break;
    case kLifxPacketTypeDeviceGetGroup:
    ret = lifxDecoder_DecodeDeviceGetGroup(buff, &pkt->DeviceGetGroup);
    break;
    case kLifxPacketTypeDeviceSetGroup:
    ret = lifxDecoder_DecodeDeviceSetGroup(buff, &pkt->DeviceSetGroup);
    break;
    case kLifxPacketTypeDeviceStateGroup:
    ret = lifxDecoder_DecodeDeviceStateGroup(buff, &pkt->DeviceStateGroup);
    break;
    case kLifxPacketTypeDeviceEchoRequest:
    ret = lifxDecoder_DecodeDeviceEchoRequest(buff, &pkt->DeviceEchoRequest);
    break;
    case kLifxPacketTypeDeviceEchoResponse:
    ret = lifxDecoder_DecodeDeviceEchoResponse(buff, &pkt->DeviceEchoResponse);
    break;
    case kLifxPacketTypeLightGet:
    ret = lifxDecoder_DecodeLightGet(buff, &pkt->LightGet);
    break;
    case kLifxPacketTypeLightSetColor:
    ret = lifxDecoder_DecodeLightSetColor(buff, &pkt->LightSetColor);
    break;
    case kLifxPacketTypeLightSetWaveform:
    ret = lifxDecoder_DecodeLightSetWaveform(buff, &pkt->LightSetWaveform);
    break;
    case kLifxPacketTypeLightState:
    ret = lifxDecoder_DecodeLightState(buff, &pkt->LightState);
    break;
    case kLifxPacketTypeLightGetPower:
    ret = lifxDecoder_DecodeLightGetPower(buff, &pkt->LightGetPower);
    break;
    case kLifxPacketTypeLightSetPower:
    ret = lifxDecoder_DecodeLightSetPower(buff, &pkt->LightSetPower);
    break;
    case kLifxPacketTypeLightStatePower:
    ret = lifxDecoder_DecodeLightStatePower(buff, &pkt->LightStatePower);
    break;
    case kLifxPacketTypeLightSetWaveformOptional:
    ret = lifxDecoder_DecodeLightSetWaveformOptional(buff, &pkt->LightSetWaveformOptional);
    break;
    case kLifxPacketTypeLightGetInfrared:
    ret = lifxDecoder_DecodeLightGetInfrared(buff, &pkt->LightGetInfrared);
    break;
    case kLifxPacketTypeLightStateInfrared:
    ret = lifxDecoder_DecodeLightStateInfrared(buff, &pkt->LightStateInfrared);
    break;
    case kLifxPacketTypeLightSetInfrared:
    ret = lifxDecoder_DecodeLightSetInfrared(buff, &pkt->LightSetInfrared);
    break;
    case kLifxPacketTypeMultiZoneSetColorZones:
    ret = lifxDecoder_DecodeMultiZoneSetColorZones(buff, &pkt->MultiZoneSetColorZones);
    break;
    case kLifxPacketTypeMultiZoneGetColorZones:
    ret = lifxDecoder_DecodeMultiZoneGetColorZones(buff, &pkt->MultiZoneGetColorZones);
    break;
    case kLifxPacketTypeMultiZoneStateZone:
    ret = lifxDecoder_DecodeMultiZoneStateZone(buff, &pkt->MultiZoneStateZone);
    break;
    case kLifxPacketTypeMultiZoneStateMultiZone:
    ret = lifxDecoder_DecodeMultiZoneStateMultiZone(buff, &pkt->MultiZoneStateMultiZone);
    break;
    case kLifxPacketTypeMultiZoneGetEffect:
    ret = lifxDecoder_DecodeMultiZoneGetEffect(buff, &pkt->MultiZoneGetEffect);
    break;
    case kLifxPacketTypeMultiZoneSetEffect:
    ret = lifxDecoder_DecodeMultiZoneSetEffect(buff, &pkt->MultiZoneSetEffect);
    break;
    case kLifxPacketTypeMultiZoneStateEffect:
    ret = lifxDecoder_DecodeMultiZoneStateEffect(buff, &pkt->MultiZoneStateEffect);
    break;
    case kLifxPacketTypeMultiZoneExtendedSetColorZones:
    ret = lifxDecoder_DecodeMultiZoneExtendedSetColorZones(buff, &pkt->MultiZoneExtendedSetColorZones);
    break;
    case kLifxPacketTypeMultiZoneExtendedGetColorZones:
    ret = lifxDecoder_DecodeMultiZoneExtendedGetColorZones(buff, &pkt->MultiZoneExtendedGetColorZones);
    break;
    case kLifxPacketTypeMultiZoneExtendedStateMultiZone:
    ret = lifxDecoder_DecodeMultiZoneExtendedStateMultiZone(buff, &pkt->MultiZoneExtendedStateMultiZone);
    break;
    case kLifxPacketTypeTileGetDeviceChain:
    ret = lifxDecoder_DecodeTileGetDeviceChain(buff, &pkt->TileGetDeviceChain);
    break;
    case kLifxPacketTypeTileStateDeviceChain:
    ret = lifxDecoder_DecodeTileStateDeviceChain(buff, &pkt->TileStateDeviceChain);
    break;
    case kLifxPacketTypeTileSetUserPosition:
    ret = lifxDecoder_DecodeTileSetUserPosition(buff, &pkt->TileSetUserPosition);
    break;
    case kLifxPacketTypeTileGet64:
    ret = lifxDecoder_DecodeTileGet64(buff, &pkt->TileGet64);
    break;
    case kLifxPacketTypeTileState64:
    ret = lifxDecoder_DecodeTileState64(buff, &pkt->TileState64);
    break;
    case kLifxPacketTypeTileSet64:
    ret = lifxDecoder_DecodeTileSet64(buff, &pkt->TileSet64);
    break;
    case kLifxPacketTypeTileGetEffect:
    ret = lifxDecoder_DecodeTileGetEffect(buff, &pkt->TileGetEffect);
    break;
    case kLifxPacketTypeTileSetEffect:
    ret = lifxDecoder_DecodeTileSetEffect(buff, &pkt->TileSetEffect);
    break;
    case kLifxPacketTypeTileStateEffect:
    ret = lifxDecoder_DecodeTileStateEffect(buff, &pkt->TileStateEffect);
    break;
  }
  return ret;
}

int lifxEncoder_EncodePacket(lifxBuffer_t* buff, lifxPacketType_t type, lifxPacket_t const* pkt)
{
  int ret = 0;
  switch (type)
  {
    case kLifxPacketTypeDeviceGetService:
    ret = lifxEncoder_EncodeDeviceGetService(buff, &pkt->DeviceGetService);
    break;
    case kLifxPacketTypeDeviceStateService:
    ret = lifxEncoder_EncodeDeviceStateService(buff, &pkt->DeviceStateService);
    break;
    case kLifxPacketTypeDeviceGetHostInfo:
    ret = lifxEncoder_EncodeDeviceGetHostInfo(buff, &pkt->DeviceGetHostInfo);
    break;
    case kLifxPacketTypeDeviceStateHostInfo:
    ret = lifxEncoder_EncodeDeviceStateHostInfo(buff, &pkt->DeviceStateHostInfo);
    break;
    case kLifxPacketTypeDeviceGetHostFirmware:
    ret = lifxEncoder_EncodeDeviceGetHostFirmware(buff, &pkt->DeviceGetHostFirmware);
    break;
    case kLifxPacketTypeDeviceStateHostFirmware:
    ret = lifxEncoder_EncodeDeviceStateHostFirmware(buff, &pkt->DeviceStateHostFirmware);
    break;
    case kLifxPacketTypeDeviceGetWifiInfo:
    ret = lifxEncoder_EncodeDeviceGetWifiInfo(buff, &pkt->DeviceGetWifiInfo);
    break;
    case kLifxPacketTypeDeviceStateWifiInfo:
    ret = lifxEncoder_EncodeDeviceStateWifiInfo(buff, &pkt->DeviceStateWifiInfo);
    break;
    case kLifxPacketTypeDeviceGetWifiFirmware:
    ret = lifxEncoder_EncodeDeviceGetWifiFirmware(buff, &pkt->DeviceGetWifiFirmware);
    break;
    case kLifxPacketTypeDeviceStateWifiFirmware:
    ret = lifxEncoder_EncodeDeviceStateWifiFirmware(buff, &pkt->DeviceStateWifiFirmware);
    break;
    case kLifxPacketTypeDeviceGetPower:
    ret = lifxEncoder_EncodeDeviceGetPower(buff, &pkt->DeviceGetPower);
    break;
    case kLifxPacketTypeDeviceSetPower:
    ret = lifxEncoder_EncodeDeviceSetPower(buff, &pkt->DeviceSetPower);
    break;
    case kLifxPacketTypeDeviceStatePower:
    ret = lifxEncoder_EncodeDeviceStatePower(buff, &pkt->DeviceStatePower);
    break;
    case kLifxPacketTypeDeviceGetLabel:
    ret = lifxEncoder_EncodeDeviceGetLabel(buff, &pkt->DeviceGetLabel);
    break;
    case kLifxPacketTypeDeviceSetLabel:
    ret = lifxEncoder_EncodeDeviceSetLabel(buff, &pkt->DeviceSetLabel);
    break;
    case kLifxPacketTypeDeviceStateLabel:
    ret = lifxEncoder_EncodeDeviceStateLabel(buff, &pkt->DeviceStateLabel);
    break;
    case kLifxPacketTypeDeviceGetVersion:
    ret = lifxEncoder_EncodeDeviceGetVersion(buff, &pkt->DeviceGetVersion);
    break;
    case kLifxPacketTypeDeviceStateVersion:
    ret = lifxEncoder_EncodeDeviceStateVersion(buff, &pkt->DeviceStateVersion);
    break;
    case kLifxPacketTypeDeviceGetInfo:
    ret = lifxEncoder_EncodeDeviceGetInfo(buff, &pkt->DeviceGetInfo);
    break;
    case kLifxPacketTypeDeviceStateInfo:
    ret = lifxEncoder_EncodeDeviceStateInfo(buff, &pkt->DeviceStateInfo);
    break;
    case kLifxPacketTypeDeviceAcknowledgement:
    ret = lifxEncoder_EncodeDeviceAcknowledgement(buff, &pkt->DeviceAcknowledgement);
    break;
    case kLifxPacketTypeDeviceGetLocation:
    ret = lifxEncoder_EncodeDeviceGetLocation(buff, &pkt->DeviceGetLocation);
    break;
    case kLifxPacketTypeDeviceSetLocation:
    ret = lifxEncoder_EncodeDeviceSetLocation(buff, &pkt->DeviceSetLocation);
    break;
    case kLifxPacketTypeDeviceStateLocation:
    ret = lifxEncoder_EncodeDeviceStateLocation(buff, &pkt->DeviceStateLocation);
    break;
    case kLifxPacketTypeDeviceGetGroup:
    ret = lifxEncoder_EncodeDeviceGetGroup(buff, &pkt->DeviceGetGroup);
    break;
    case kLifxPacketTypeDeviceSetGroup:
    ret = lifxEncoder_EncodeDeviceSetGroup(buff, &pkt->DeviceSetGroup);
    break;
    case kLifxPacketTypeDeviceStateGroup:
    ret = lifxEncoder_EncodeDeviceStateGroup(buff, &pkt->DeviceStateGroup);
    break;
    case kLifxPacketTypeDeviceEchoRequest:
    ret = lifxEncoder_EncodeDeviceEchoRequest(buff, &pkt->DeviceEchoRequest);
    break;
    case kLifxPacketTypeDeviceEchoResponse:
    ret = lifxEncoder_EncodeDeviceEchoResponse(buff, &pkt->DeviceEchoResponse);
    break;
    case kLifxPacketTypeLightGet:
    ret = lifxEncoder_EncodeLightGet(buff, &pkt->LightGet);
    break;
    case kLifxPacketTypeLightSetColor:
    ret = lifxEncoder_EncodeLightSetColor(buff, &pkt->LightSetColor);
    break;
    case kLifxPacketTypeLightSetWaveform:
    ret = lifxEncoder_EncodeLightSetWaveform(buff, &pkt->LightSetWaveform);
    break;
    case kLifxPacketTypeLightState:
    ret = lifxEncoder_EncodeLightState(buff, &pkt->LightState);
    break;
    case kLifxPacketTypeLightGetPower:
    ret = lifxEncoder_EncodeLightGetPower(buff, &pkt->LightGetPower);
    break;
    case kLifxPacketTypeLightSetPower:
    ret = lifxEncoder_EncodeLightSetPower(buff, &pkt->LightSetPower);
    break;
    case kLifxPacketTypeLightStatePower:
    ret = lifxEncoder_EncodeLightStatePower(buff, &pkt->LightStatePower);
    break;
    case kLifxPacketTypeLightSetWaveformOptional:
    ret = lifxEncoder_EncodeLightSetWaveformOptional(buff, &pkt->LightSetWaveformOptional);
    break;
    case kLifxPacketTypeLightGetInfrared:
    ret = lifxEncoder_EncodeLightGetInfrared(buff, &pkt->LightGetInfrared);
    break;
    case kLifxPacketTypeLightStateInfrared:
    ret = lifxEncoder_EncodeLightStateInfrared(buff, &pkt->LightStateInfrared);
    break;
    case kLifxPacketTypeLightSetInfrared:
    ret = lifxEncoder_EncodeLightSetInfrared(buff, &pkt->LightSetInfrared);
    break;
    case kLifxPacketTypeMultiZoneSetColorZones:
    ret = lifxEncoder_EncodeMultiZoneSetColorZones(buff, &pkt->MultiZoneSetColorZones);
    break;
    case kLifxPacketTypeMultiZoneGetColorZones:
    ret = lifxEncoder_EncodeMultiZoneGetColorZones(buff, &pkt->MultiZoneGetColorZones);
    break;
    case kLifxPacketTypeMultiZoneStateZone:
    ret = lifxEncoder_EncodeMultiZoneStateZone(buff, &pkt->MultiZoneStateZone);
    break;
    case kLifxPacketTypeMultiZoneStateMultiZone:
    ret = lifxEncoder_EncodeMultiZoneStateMultiZone(buff, &pkt->MultiZoneStateMultiZone);
    break;
    case kLifxPacketTypeMultiZoneGetEffect:
    ret = lifxEncoder_EncodeMultiZoneGetEffect(buff, &pkt->MultiZoneGetEffect);
    break;
    case kLifxPacketTypeMultiZoneSetEffect:
    ret = lifxEncoder_EncodeMultiZoneSetEffect(buff, &pkt->MultiZoneSetEffect);
    break;
    case kLifxPacketTypeMultiZoneStateEffect:
    ret = lifxEncoder_EncodeMultiZoneStateEffect(buff, &pkt->MultiZoneStateEffect);
    break;
    case kLifxPacketTypeMultiZoneExtendedSetColorZones:
    ret = lifxEncoder_EncodeMultiZoneExtendedSetColorZones(buff, &pkt->MultiZoneExtendedSetColorZones);
    break;
    case kLifxPacketTypeMultiZoneExtendedGetColorZones:
    ret = lifxEncoder_EncodeMultiZoneExtendedGetColorZones(buff, &pkt->MultiZoneExtendedGetColorZones);
    break;
    case kLifxPacketTypeMultiZoneExtendedStateMultiZone:
    ret = lifxEncoder_EncodeMultiZoneExtendedStateMultiZone(buff, &pkt->MultiZoneExtendedStateMultiZone);
    break;
    case kLifxPacketTypeTileGetDeviceChain:
    ret = lifxEncoder_EncodeTileGetDeviceChain(buff, &pkt->TileGetDeviceChain);
    break;
    case kLifxPacketTypeTileStateDeviceChain:
    ret = lifxEncoder_EncodeTileStateDeviceChain(buff, &pkt->TileStateDeviceChain);
    break;
    case kLifxPacketTypeTileSetUserPosition:
    ret = lifxEncoder_EncodeTileSetUserPosition(buff, &pkt->TileSetUserPosition);
    break;
    case kLifxPacketTypeTileGet64:
    ret = lifxEncoder_EncodeTileGet64(buff, &pkt->TileGet64);
    break;
    case kLifxPacketTypeTileState64:
    ret = lifxEncoder_EncodeTileState64(buff, &pkt->TileState64);
    break;
    case kLifxPacketTypeTileSet64:
    ret = lifxEncoder_EncodeTileSet64(buff, &pkt->TileSet64);
    break;
    case kLifxPacketTypeTileGetEffect:
    ret = lifxEncoder_EncodeTileGetEffect(buff, &pkt->TileGetEffect);
    break;
    case kLifxPacketTypeTileSetEffect:
    ret = lifxEncoder_EncodeTileSetEffect(buff, &pkt->TileSetEffect);
    break;
    case kLifxPacketTypeTileStateEffect:
    ret = lifxEncoder_EncodeTileStateEffect(buff, &pkt->TileStateEffect);
    break;
  }
  return ret;
}

int lifxEncoder_GetEncodedSize(lifxPacketType_t type)
{
  int ret = 0;
  switch (type)
  {
    // {'pkt_type': 2, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetService:
    ret = 0;
    break;
    // {'pkt_type': 3, 'size_bytes': 5, 'fields': [{'name': 'Service', 'type': '<DeviceService>', 'size_bytes': 1}, {'name': 'Port', 'type': 'uint32', 'size_bytes': 4}]}
    case kLifxPacketTypeDeviceStateService:
    ret = 5;
    break;
    // {'pkt_type': 12, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetHostInfo:
    ret = 0;
    break;
    // {'pkt_type': 13, 'size_bytes': 14, 'fields': [{'name': 'Signal', 'type': 'float32', 'size_bytes': 4}, {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}, {'type': 'reserved', 'size_bytes': 2}]}
    case kLifxPacketTypeDeviceStateHostInfo:
    ret = 14;
    break;
    // {'pkt_type': 14, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetHostFirmware:
    ret = 0;
    break;
    // {'pkt_type': 15, 'size_bytes': 20, 'fields': [{'name': 'Build', 'type': 'uint64', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 8}, {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}, {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}]}
    case kLifxPacketTypeDeviceStateHostFirmware:
    ret = 20;
    break;
    // {'pkt_type': 16, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetWifiInfo:
    ret = 0;
    break;
    // {'pkt_type': 17, 'size_bytes': 14, 'fields': [{'name': 'Signal', 'type': 'float32', 'size_bytes': 4}, {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}, {'type': 'reserved', 'size_bytes': 2}]}
    case kLifxPacketTypeDeviceStateWifiInfo:
    ret = 14;
    break;
    // {'pkt_type': 18, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetWifiFirmware:
    ret = 0;
    break;
    // {'pkt_type': 19, 'size_bytes': 20, 'fields': [{'name': 'Build', 'type': 'uint64', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 8}, {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}, {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}]}
    case kLifxPacketTypeDeviceStateWifiFirmware:
    ret = 20;
    break;
    // {'pkt_type': 20, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetPower:
    ret = 0;
    break;
    // {'pkt_type': 21, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
    case kLifxPacketTypeDeviceSetPower:
    ret = 2;
    break;
    // {'pkt_type': 22, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
    case kLifxPacketTypeDeviceStatePower:
    ret = 2;
    break;
    // {'pkt_type': 23, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetLabel:
    ret = 0;
    break;
    // {'pkt_type': 24, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
    case kLifxPacketTypeDeviceSetLabel:
    ret = 32;
    break;
    // {'pkt_type': 25, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
    case kLifxPacketTypeDeviceStateLabel:
    ret = 32;
    break;
    // {'pkt_type': 32, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetVersion:
    ret = 0;
    break;
    // {'pkt_type': 33, 'size_bytes': 12, 'fields': [{'name': 'Vendor', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Product', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Version', 'type': 'uint32', 'size_bytes': 4}]}
    case kLifxPacketTypeDeviceStateVersion:
    ret = 12;
    break;
    // {'pkt_type': 34, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetInfo:
    ret = 0;
    break;
    // {'pkt_type': 35, 'size_bytes': 24, 'fields': [{'name': 'Time', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Uptime', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Downtime', 'type': 'uint64', 'size_bytes': 8}]}
    case kLifxPacketTypeDeviceStateInfo:
    ret = 24;
    break;
    // {'pkt_type': 45, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceAcknowledgement:
    ret = 0;
    break;
    // {'pkt_type': 48, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetLocation:
    ret = 0;
    break;
    // {'pkt_type': 49, 'size_bytes': 56, 'fields': [{'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
    case kLifxPacketTypeDeviceSetLocation:
    ret = 56;
    break;
    // {'pkt_type': 50, 'size_bytes': 56, 'fields': [{'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
    case kLifxPacketTypeDeviceStateLocation:
    ret = 56;
    break;
    // {'pkt_type': 51, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetGroup:
    ret = 0;
    break;
    // {'pkt_type': 52, 'size_bytes': 56, 'fields': [{'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
    case kLifxPacketTypeDeviceSetGroup:
    ret = 56;
    break;
    // {'pkt_type': 53, 'size_bytes': 56, 'fields': [{'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
    case kLifxPacketTypeDeviceStateGroup:
    ret = 56;
    break;
    // {'pkt_type': 58, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
    case kLifxPacketTypeDeviceEchoRequest:
    ret = 64;
    break;
    // {'pkt_type': 59, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
    case kLifxPacketTypeDeviceEchoResponse:
    ret = 64;
    break;
    // {'pkt_type': 101, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeLightGet:
    ret = 0;
    break;
    // {'pkt_type': 102, 'size_bytes': 13, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
    case kLifxPacketTypeLightSetColor:
    ret = 13;
    break;
    // {'pkt_type': 119, 'size_bytes': 25, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}, {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}, {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}, {'name': 'SetHue', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetSaturation', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetBrightness', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetKelvin', 'type': 'bool', 'size_bytes': 1}]}
    case kLifxPacketTypeLightSetWaveformOptional:
    ret = 25;
    break;
    // {'pkt_type': 103, 'size_bytes': 21, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}, {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}, {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}]}
    case kLifxPacketTypeLightSetWaveform:
    ret = 21;
    break;
    // {'pkt_type': 116, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeLightGetPower:
    ret = 0;
    break;
    // {'pkt_type': 117, 'size_bytes': 6, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
    case kLifxPacketTypeLightSetPower:
    ret = 6;
    break;
    // {'pkt_type': 118, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
    case kLifxPacketTypeLightStatePower:
    ret = 2;
    break;
    // {'pkt_type': 107, 'size_bytes': 52, 'fields': [{'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'Power', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'type': 'reserved', 'size_bytes': 8}]}
    case kLifxPacketTypeLightState:
    ret = 52;
    break;
    // {'pkt_type': 120, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeLightGetInfrared:
    ret = 0;
    break;
    // {'pkt_type': 121, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
    case kLifxPacketTypeLightStateInfrared:
    ret = 2;
    break;
    // {'pkt_type': 122, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
    case kLifxPacketTypeLightSetInfrared:
    ret = 2;
    break;
    // {'pkt_type': 701, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeTileGetDeviceChain:
    ret = 0;
    break;
    // {'pkt_type': 702, 'size_bytes': 882, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'TileDevices', 'type': '[16]<TileStateDevice>', 'size_bytes': 880}, {'name': 'TileDevicesCount', 'type': 'uint8', 'size_bytes': 1}]}
    case kLifxPacketTypeTileStateDeviceChain:
    ret = 882;
    break;
    // {'pkt_type': 703, 'size_bytes': 11, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'UserX', 'type': 'float32', 'size_bytes': 4}, {'name': 'UserY', 'type': 'float32', 'size_bytes': 4}]}
    case kLifxPacketTypeTileSetUserPosition:
    ret = 11;
    break;
    // {'pkt_type': 707, 'size_bytes': 6, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}]}
    case kLifxPacketTypeTileGet64:
    ret = 6;
    break;
    // {'pkt_type': 711, 'size_bytes': 517, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}, {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}]}
    case kLifxPacketTypeTileState64:
    ret = 517;
    break;
    // {'pkt_type': 715, 'size_bytes': 522, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}]}
    case kLifxPacketTypeTileSet64:
    ret = 522;
    break;
    // {'pkt_type': 718, 'size_bytes': 2, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}]}
    case kLifxPacketTypeTileGetEffect:
    ret = 2;
    break;
    // {'pkt_type': 719, 'size_bytes': 188, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
    case kLifxPacketTypeTileSetEffect:
    ret = 188;
    break;
    // {'pkt_type': 720, 'size_bytes': 187, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
    case kLifxPacketTypeTileStateEffect:
    ret = 187;
    break;
    // {'pkt_type': 501, 'size_bytes': 15, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Apply', 'type': '<MultiZoneApplicationRequest>', 'size_bytes': 1}]}
    case kLifxPacketTypeMultiZoneSetColorZones:
    ret = 15;
    break;
    // {'pkt_type': 502, 'size_bytes': 2, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}]}
    case kLifxPacketTypeMultiZoneGetColorZones:
    ret = 2;
    break;
    // {'pkt_type': 503, 'size_bytes': 10, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}]}
    case kLifxPacketTypeMultiZoneStateZone:
    ret = 10;
    break;
    // {'pkt_type': 506, 'size_bytes': 66, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[8]<LightHsbk>', 'size_bytes': 64}]}
    case kLifxPacketTypeMultiZoneStateMultiZone:
    ret = 66;
    break;
    // {'pkt_type': 507, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeMultiZoneGetEffect:
    ret = 0;
    break;
    // {'pkt_type': 508, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
    case kLifxPacketTypeMultiZoneSetEffect:
    ret = 59;
    break;
    // {'pkt_type': 509, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
    case kLifxPacketTypeMultiZoneStateEffect:
    ret = 59;
    break;
    // {'pkt_type': 510, 'size_bytes': 664, 'fields': [{'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Apply', 'type': '<MultiZoneExtendedApplicationRequest>', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}, {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}]}
    case kLifxPacketTypeMultiZoneExtendedSetColorZones:
    ret = 664;
    break;
    // {'pkt_type': 511, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeMultiZoneExtendedGetColorZones:
    ret = 0;
    break;
    // {'pkt_type': 512, 'size_bytes': 661, 'fields': [{'name': 'Count', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}, {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}]}
    case kLifxPacketTypeMultiZoneExtendedStateMultiZone:
    ret = 661;
    break;
  }
  return ret;
}

int lifxEncoder_EncodeDeviceGetService(lifxBuffer_t* buff, lifxDeviceGetService_t const* pkt)
{
  // {'pkt_type': 2, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeDeviceGetService(lifxBuffer_t* buff, lifxDeviceGetService_t* pkt)
{
  // {'pkt_type': 2, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceStateService(lifxBuffer_t* buff, lifxDeviceStateService_t const* pkt)
{
  // {'pkt_type': 3, 'size_bytes': 5, 'fields': [{'name': 'Service', 'type': '<DeviceService>', 'size_bytes': 1}, {'name': 'Port', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Service', 'type': '<DeviceService>', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Service);
  // {'name': 'Port', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Port);
  return 0;
}

int lifxDecoder_DecodeDeviceStateService(lifxBuffer_t* buff, lifxDeviceStateService_t* pkt)
{
  // {'pkt_type': 3, 'size_bytes': 5, 'fields': [{'name': 'Service', 'type': '<DeviceService>', 'size_bytes': 1}, {'name': 'Port', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Service', 'type': '<DeviceService>', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Service);
  // {'name': 'Port', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Port);
  return 0;
}

int lifxEncoder_EncodeDeviceGetHostInfo(lifxBuffer_t* buff, lifxDeviceGetHostInfo_t const* pkt)
{
  // {'pkt_type': 12, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeDeviceGetHostInfo(lifxBuffer_t* buff, lifxDeviceGetHostInfo_t* pkt)
{
  // {'pkt_type': 12, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceStateHostInfo(lifxBuffer_t* buff, lifxDeviceStateHostInfo_t const* pkt)
{
  // {'pkt_type': 13, 'size_bytes': 14, 'fields': [{'name': 'Signal', 'type': 'float32', 'size_bytes': 4}, {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}, {'type': 'reserved', 'size_bytes': 2}]}
  // {'name': 'Signal', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_WriteFloat(buff, pkt->Signal);
  // {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Tx);
  // {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Rx);
  // {'type': 'reserved', 'size_bytes': 2}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxDecoder_DecodeDeviceStateHostInfo(lifxBuffer_t* buff, lifxDeviceStateHostInfo_t* pkt)
{
  // {'pkt_type': 13, 'size_bytes': 14, 'fields': [{'name': 'Signal', 'type': 'float32', 'size_bytes': 4}, {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}, {'type': 'reserved', 'size_bytes': 2}]}
  // {'name': 'Signal', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_ReadFloat(buff, &pkt->Signal);
  // {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Tx);
  // {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Rx);
  // {'type': 'reserved', 'size_bytes': 2}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxEncoder_EncodeDeviceGetHostFirmware(lifxBuffer_t* buff, lifxDeviceGetHostFirmware_t const* pkt)
{
  // {'pkt_type': 14, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeDeviceGetHostFirmware(lifxBuffer_t* buff, lifxDeviceGetHostFirmware_t* pkt)
{
  // {'pkt_type': 14, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceStateHostFirmware(lifxBuffer_t* buff, lifxDeviceStateHostFirmware_t const* pkt)
{
  // {'pkt_type': 15, 'size_bytes': 20, 'fields': [{'name': 'Build', 'type': 'uint64', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 8}, {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}, {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Build', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->Build);
  // {'type': 'reserved', 'size_bytes': 8}
  lifxBuffer_Seek(buff, 8, kLifxBufferWhenceCurrent);
  // {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->VersionMinor);
  // {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->VersionMajor);
  return 0;
}

int lifxDecoder_DecodeDeviceStateHostFirmware(lifxBuffer_t* buff, lifxDeviceStateHostFirmware_t* pkt)
{
  // {'pkt_type': 15, 'size_bytes': 20, 'fields': [{'name': 'Build', 'type': 'uint64', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 8}, {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}, {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Build', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->Build);
  // {'type': 'reserved', 'size_bytes': 8}
  lifxBuffer_Seek(buff, 8, kLifxBufferWhenceCurrent);
  // {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->VersionMinor);
  // {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->VersionMajor);
  return 0;
}

int lifxEncoder_EncodeDeviceGetWifiInfo(lifxBuffer_t* buff, lifxDeviceGetWifiInfo_t const* pkt)
{
  // {'pkt_type': 16, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeDeviceGetWifiInfo(lifxBuffer_t* buff, lifxDeviceGetWifiInfo_t* pkt)
{
  // {'pkt_type': 16, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceStateWifiInfo(lifxBuffer_t* buff, lifxDeviceStateWifiInfo_t const* pkt)
{
  // {'pkt_type': 17, 'size_bytes': 14, 'fields': [{'name': 'Signal', 'type': 'float32', 'size_bytes': 4}, {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}, {'type': 'reserved', 'size_bytes': 2}]}
  // {'name': 'Signal', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_WriteFloat(buff, pkt->Signal);
  // {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Tx);
  // {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Rx);
  // {'type': 'reserved', 'size_bytes': 2}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxDecoder_DecodeDeviceStateWifiInfo(lifxBuffer_t* buff, lifxDeviceStateWifiInfo_t* pkt)
{
  // {'pkt_type': 17, 'size_bytes': 14, 'fields': [{'name': 'Signal', 'type': 'float32', 'size_bytes': 4}, {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}, {'type': 'reserved', 'size_bytes': 2}]}
  // {'name': 'Signal', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_ReadFloat(buff, &pkt->Signal);
  // {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Tx);
  // {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Rx);
  // {'type': 'reserved', 'size_bytes': 2}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxEncoder_EncodeDeviceGetWifiFirmware(lifxBuffer_t* buff, lifxDeviceGetWifiFirmware_t const* pkt)
{
  // {'pkt_type': 18, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeDeviceGetWifiFirmware(lifxBuffer_t* buff, lifxDeviceGetWifiFirmware_t* pkt)
{
  // {'pkt_type': 18, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceStateWifiFirmware(lifxBuffer_t* buff, lifxDeviceStateWifiFirmware_t const* pkt)
{
  // {'pkt_type': 19, 'size_bytes': 20, 'fields': [{'name': 'Build', 'type': 'uint64', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 8}, {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}, {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Build', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->Build);
  // {'type': 'reserved', 'size_bytes': 8}
  lifxBuffer_Seek(buff, 8, kLifxBufferWhenceCurrent);
  // {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->VersionMinor);
  // {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->VersionMajor);
  return 0;
}

int lifxDecoder_DecodeDeviceStateWifiFirmware(lifxBuffer_t* buff, lifxDeviceStateWifiFirmware_t* pkt)
{
  // {'pkt_type': 19, 'size_bytes': 20, 'fields': [{'name': 'Build', 'type': 'uint64', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 8}, {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}, {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Build', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->Build);
  // {'type': 'reserved', 'size_bytes': 8}
  lifxBuffer_Seek(buff, 8, kLifxBufferWhenceCurrent);
  // {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->VersionMinor);
  // {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->VersionMajor);
  return 0;
}

int lifxEncoder_EncodeDeviceGetPower(lifxBuffer_t* buff, lifxDeviceGetPower_t const* pkt)
{
  // {'pkt_type': 20, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeDeviceGetPower(lifxBuffer_t* buff, lifxDeviceGetPower_t* pkt)
{
  // {'pkt_type': 20, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceSetPower(lifxBuffer_t* buff, lifxDeviceSetPower_t const* pkt)
{
  // {'pkt_type': 21, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  return 0;
}

int lifxDecoder_DecodeDeviceSetPower(lifxBuffer_t* buff, lifxDeviceSetPower_t* pkt)
{
  // {'pkt_type': 21, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
  return 0;
}

int lifxEncoder_EncodeDeviceStatePower(lifxBuffer_t* buff, lifxDeviceStatePower_t const* pkt)
{
  // {'pkt_type': 22, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  return 0;
}

int lifxDecoder_DecodeDeviceStatePower(lifxBuffer_t* buff, lifxDeviceStatePower_t* pkt)
{
  // {'pkt_type': 22, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
  return 0;
}

int lifxEncoder_EncodeDeviceGetLabel(lifxBuffer_t* buff, lifxDeviceGetLabel_t const* pkt)
{
  // {'pkt_type': 23, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeDeviceGetLabel(lifxBuffer_t* buff, lifxDeviceGetLabel_t* pkt)
{
  // {'pkt_type': 23, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceSetLabel(lifxBuffer_t* buff, lifxDeviceSetLabel_t const* pkt)
{
  // {'pkt_type': 24, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  return 0;
}

int lifxDecoder_DecodeDeviceSetLabel(lifxBuffer_t* buff, lifxDeviceSetLabel_t* pkt)
{
  // {'pkt_type': 24, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Read(buff, pkt->Label, 32);
  return 0;
}

int lifxEncoder_EncodeDeviceStateLabel(lifxBuffer_t* buff, lifxDeviceStateLabel_t const* pkt)
{
  // {'pkt_type': 25, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  return 0;
}

int lifxDecoder_DecodeDeviceStateLabel(lifxBuffer_t* buff, lifxDeviceStateLabel_t* pkt)
{
  // {'pkt_type': 25, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Read(buff, pkt->Label, 32);
  return 0;
}

int lifxEncoder_EncodeDeviceGetVersion(lifxBuffer_t* buff, lifxDeviceGetVersion_t const* pkt)
{
  // {'pkt_type': 32, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeDeviceGetVersion(lifxBuffer_t* buff, lifxDeviceGetVersion_t* pkt)
{
  // {'pkt_type': 32, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceStateVersion(lifxBuffer_t* buff, lifxDeviceStateVersion_t const* pkt)
{
  // {'pkt_type': 33, 'size_bytes': 12, 'fields': [{'name': 'Vendor', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Product', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Version', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Vendor', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Vendor);
  // {'name': 'Product', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Product);
  // {'name': 'Version', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Version);
  return 0;
}

int lifxDecoder_DecodeDeviceStateVersion(lifxBuffer_t* buff, lifxDeviceStateVersion_t* pkt)
{
  // {'pkt_type': 33, 'size_bytes': 12, 'fields': [{'name': 'Vendor', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Product', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Version', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Vendor', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Vendor);
  // {'name': 'Product', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Product);
  // {'name': 'Version', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Version);
  return 0;
}

int lifxEncoder_EncodeDeviceGetInfo(lifxBuffer_t* buff, lifxDeviceGetInfo_t const* pkt)
{
  // {'pkt_type': 34, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeDeviceGetInfo(lifxBuffer_t* buff, lifxDeviceGetInfo_t* pkt)
{
  // {'pkt_type': 34, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceStateInfo(lifxBuffer_t* buff, lifxDeviceStateInfo_t const* pkt)
{
  // {'pkt_type': 35, 'size_bytes': 24, 'fields': [{'name': 'Time', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Uptime', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Downtime', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Time', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->Time);
  // {'name': 'Uptime', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->Uptime);
  // {'name': 'Downtime', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->Downtime);
  return 0;
}

int lifxDecoder_DecodeDeviceStateInfo(lifxBuffer_t* buff, lifxDeviceStateInfo_t* pkt)
{
  // {'pkt_type': 35, 'size_bytes': 24, 'fields': [{'name': 'Time', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Uptime', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Downtime', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Time', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->Time);
  // {'name': 'Uptime', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->Uptime);
  // {'name': 'Downtime', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->Downtime);
  return 0;
}

int lifxEncoder_EncodeDeviceAcknowledgement(lifxBuffer_t* buff, lifxDeviceAcknowledgement_t const* pkt)
{
  // {'pkt_type': 45, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeDeviceAcknowledgement(lifxBuffer_t* buff, lifxDeviceAcknowledgement_t* pkt)
{
  // {'pkt_type': 45, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceGetLocation(lifxBuffer_t* buff, lifxDeviceGetLocation_t const* pkt)
{
  // {'pkt_type': 48, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeDeviceGetLocation(lifxBuffer_t* buff, lifxDeviceGetLocation_t* pkt)
{
  // {'pkt_type': 48, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceSetLocation(lifxBuffer_t* buff, lifxDeviceSetLocation_t const* pkt)
{
  // {'pkt_type': 49, 'size_bytes': 56, 'fields': [{'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Write(buff, pkt->Location, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return 0;
}

int lifxDecoder_DecodeDeviceSetLocation(lifxBuffer_t* buff, lifxDeviceSetLocation_t* pkt)
{
  // {'pkt_type': 49, 'size_bytes': 56, 'fields': [{'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Read(buff, pkt->Location, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Read(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->UpdatedAt);
  return 0;
}

int lifxEncoder_EncodeDeviceStateLocation(lifxBuffer_t* buff, lifxDeviceStateLocation_t const* pkt)
{
  // {'pkt_type': 50, 'size_bytes': 56, 'fields': [{'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Write(buff, pkt->Location, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return 0;
}

int lifxDecoder_DecodeDeviceStateLocation(lifxBuffer_t* buff, lifxDeviceStateLocation_t* pkt)
{
  // {'pkt_type': 50, 'size_bytes': 56, 'fields': [{'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Read(buff, pkt->Location, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Read(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->UpdatedAt);
  return 0;
}

int lifxEncoder_EncodeDeviceGetGroup(lifxBuffer_t* buff, lifxDeviceGetGroup_t const* pkt)
{
  // {'pkt_type': 51, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeDeviceGetGroup(lifxBuffer_t* buff, lifxDeviceGetGroup_t* pkt)
{
  // {'pkt_type': 51, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceSetGroup(lifxBuffer_t* buff, lifxDeviceSetGroup_t const* pkt)
{
  // {'pkt_type': 52, 'size_bytes': 56, 'fields': [{'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Write(buff, pkt->Group, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return 0;
}

int lifxDecoder_DecodeDeviceSetGroup(lifxBuffer_t* buff, lifxDeviceSetGroup_t* pkt)
{
  // {'pkt_type': 52, 'size_bytes': 56, 'fields': [{'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Read(buff, pkt->Group, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Read(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->UpdatedAt);
  return 0;
}

int lifxEncoder_EncodeDeviceStateGroup(lifxBuffer_t* buff, lifxDeviceStateGroup_t const* pkt)
{
  // {'pkt_type': 53, 'size_bytes': 56, 'fields': [{'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Write(buff, pkt->Group, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return 0;
}

int lifxDecoder_DecodeDeviceStateGroup(lifxBuffer_t* buff, lifxDeviceStateGroup_t* pkt)
{
  // {'pkt_type': 53, 'size_bytes': 56, 'fields': [{'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Read(buff, pkt->Group, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Read(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->UpdatedAt);
  return 0;
}

int lifxEncoder_EncodeDeviceEchoRequest(lifxBuffer_t* buff, lifxDeviceEchoRequest_t const* pkt)
{
  // {'pkt_type': 58, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
  // {'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}
  lifxBuffer_Write(buff, pkt->Payload, 64);
  return 0;
}

int lifxDecoder_DecodeDeviceEchoRequest(lifxBuffer_t* buff, lifxDeviceEchoRequest_t* pkt)
{
  // {'pkt_type': 58, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
  // {'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}
  lifxBuffer_Read(buff, pkt->Payload, 64);
  return 0;
}

int lifxEncoder_EncodeDeviceEchoResponse(lifxBuffer_t* buff, lifxDeviceEchoResponse_t const* pkt)
{
  // {'pkt_type': 59, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
  // {'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}
  lifxBuffer_Write(buff, pkt->Payload, 64);
  return 0;
}

int lifxDecoder_DecodeDeviceEchoResponse(lifxBuffer_t* buff, lifxDeviceEchoResponse_t* pkt)
{
  // {'pkt_type': 59, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
  // {'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}
  lifxBuffer_Read(buff, pkt->Payload, 64);
  return 0;
}

int lifxEncoder_EncodeLightGet(lifxBuffer_t* buff, lifxLightGet_t const* pkt)
{
  // {'pkt_type': 101, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeLightGet(lifxBuffer_t* buff, lifxLightGet_t* pkt)
{
  // {'pkt_type': 101, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeLightSetColor(lifxBuffer_t* buff, lifxLightSetColor_t const* pkt)
{
  // {'pkt_type': 102, 'size_bytes': 13, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Color);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  return 0;
}

int lifxDecoder_DecodeLightSetColor(lifxBuffer_t* buff, lifxLightSetColor_t* pkt)
{
  // {'pkt_type': 102, 'size_bytes': 13, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Color);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  return 0;
}

int lifxEncoder_EncodeLightSetWaveformOptional(lifxBuffer_t* buff, lifxLightSetWaveformOptional_t const* pkt)
{
  // {'pkt_type': 119, 'size_bytes': 25, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}, {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}, {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}, {'name': 'SetHue', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetSaturation', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetBrightness', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetKelvin', 'type': 'bool', 'size_bytes': 1}]}
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_WriteBool(buff, pkt->Transient);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Color);
  // {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Period);
  // {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_WriteFloat(buff, pkt->Cycles);
  // {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_WriteInt16(buff, pkt->SkewRatio);
  // {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Waveform);
  // {'name': 'SetHue', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_WriteBool(buff, pkt->SetHue);
  // {'name': 'SetSaturation', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_WriteBool(buff, pkt->SetSaturation);
  // {'name': 'SetBrightness', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_WriteBool(buff, pkt->SetBrightness);
  // {'name': 'SetKelvin', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_WriteBool(buff, pkt->SetKelvin);
  return 0;
}

int lifxDecoder_DecodeLightSetWaveformOptional(lifxBuffer_t* buff, lifxLightSetWaveformOptional_t* pkt)
{
  // {'pkt_type': 119, 'size_bytes': 25, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}, {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}, {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}, {'name': 'SetHue', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetSaturation', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetBrightness', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetKelvin', 'type': 'bool', 'size_bytes': 1}]}
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_ReadBool(buff, &pkt->Transient);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Color);
  // {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Period);
  // {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_ReadFloat(buff, &pkt->Cycles);
  // {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_ReadInt16(buff, &pkt->SkewRatio);
  // {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Waveform);
  // {'name': 'SetHue', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_ReadBool(buff, &pkt->SetHue);
  // {'name': 'SetSaturation', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_ReadBool(buff, &pkt->SetSaturation);
  // {'name': 'SetBrightness', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_ReadBool(buff, &pkt->SetBrightness);
  // {'name': 'SetKelvin', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_ReadBool(buff, &pkt->SetKelvin);
  return 0;
}

int lifxEncoder_EncodeLightSetWaveform(lifxBuffer_t* buff, lifxLightSetWaveform_t const* pkt)
{
  // {'pkt_type': 103, 'size_bytes': 21, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}, {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}, {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}]}
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_WriteBool(buff, pkt->Transient);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Color);
  // {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Period);
  // {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_WriteFloat(buff, pkt->Cycles);
  // {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_WriteInt16(buff, pkt->SkewRatio);
  // {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Waveform);
  return 0;
}

int lifxDecoder_DecodeLightSetWaveform(lifxBuffer_t* buff, lifxLightSetWaveform_t* pkt)
{
  // {'pkt_type': 103, 'size_bytes': 21, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}, {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}, {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}]}
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_ReadBool(buff, &pkt->Transient);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Color);
  // {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Period);
  // {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_ReadFloat(buff, &pkt->Cycles);
  // {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_ReadInt16(buff, &pkt->SkewRatio);
  // {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Waveform);
  return 0;
}

int lifxEncoder_EncodeLightGetPower(lifxBuffer_t* buff, lifxLightGetPower_t const* pkt)
{
  // {'pkt_type': 116, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeLightGetPower(lifxBuffer_t* buff, lifxLightGetPower_t* pkt)
{
  // {'pkt_type': 116, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeLightSetPower(lifxBuffer_t* buff, lifxLightSetPower_t const* pkt)
{
  // {'pkt_type': 117, 'size_bytes': 6, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  return 0;
}

int lifxDecoder_DecodeLightSetPower(lifxBuffer_t* buff, lifxLightSetPower_t* pkt)
{
  // {'pkt_type': 117, 'size_bytes': 6, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  return 0;
}

int lifxEncoder_EncodeLightStatePower(lifxBuffer_t* buff, lifxLightStatePower_t const* pkt)
{
  // {'pkt_type': 118, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  return 0;
}

int lifxDecoder_DecodeLightStatePower(lifxBuffer_t* buff, lifxLightStatePower_t* pkt)
{
  // {'pkt_type': 118, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
  return 0;
}

int lifxEncoder_EncodeLightState(lifxBuffer_t* buff, lifxLightState_t const* pkt)
{
  // {'pkt_type': 107, 'size_bytes': 52, 'fields': [{'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'Power', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'type': 'reserved', 'size_bytes': 8}]}
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Color);
  // {'type': 'reserved', 'size_bytes': 2}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'name': 'Power', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Power);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'type': 'reserved', 'size_bytes': 8}
  lifxBuffer_Seek(buff, 8, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxDecoder_DecodeLightState(lifxBuffer_t* buff, lifxLightState_t* pkt)
{
  // {'pkt_type': 107, 'size_bytes': 52, 'fields': [{'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'Power', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'type': 'reserved', 'size_bytes': 8}]}
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Color);
  // {'type': 'reserved', 'size_bytes': 2}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'name': 'Power', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Power);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Read(buff, pkt->Label, 32);
  // {'type': 'reserved', 'size_bytes': 8}
  lifxBuffer_Seek(buff, 8, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxEncoder_EncodeLightGetInfrared(lifxBuffer_t* buff, lifxLightGetInfrared_t const* pkt)
{
  // {'pkt_type': 120, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeLightGetInfrared(lifxBuffer_t* buff, lifxLightGetInfrared_t* pkt)
{
  // {'pkt_type': 120, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeLightStateInfrared(lifxBuffer_t* buff, lifxLightStateInfrared_t const* pkt)
{
  // {'pkt_type': 121, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Brightness);
  return 0;
}

int lifxDecoder_DecodeLightStateInfrared(lifxBuffer_t* buff, lifxLightStateInfrared_t* pkt)
{
  // {'pkt_type': 121, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Brightness);
  return 0;
}

int lifxEncoder_EncodeLightSetInfrared(lifxBuffer_t* buff, lifxLightSetInfrared_t const* pkt)
{
  // {'pkt_type': 122, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Brightness);
  return 0;
}

int lifxDecoder_DecodeLightSetInfrared(lifxBuffer_t* buff, lifxLightSetInfrared_t* pkt)
{
  // {'pkt_type': 122, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Brightness);
  return 0;
}

int lifxEncoder_EncodeTileGetDeviceChain(lifxBuffer_t* buff, lifxTileGetDeviceChain_t const* pkt)
{
  // {'pkt_type': 701, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeTileGetDeviceChain(lifxBuffer_t* buff, lifxTileGetDeviceChain_t* pkt)
{
  // {'pkt_type': 701, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeTileStateDeviceChain(lifxBuffer_t* buff, lifxTileStateDeviceChain_t const* pkt)
{
  // {'pkt_type': 702, 'size_bytes': 882, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'TileDevices', 'type': '[16]<TileStateDevice>', 'size_bytes': 880}, {'name': 'TileDevicesCount', 'type': 'uint8', 'size_bytes': 1}]}
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->StartIndex);
  // {'name': 'TileDevices', 'type': '[16]<TileStateDevice>', 'size_bytes': 880}
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices);
  // {'name': 'TileDevicesCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->TileDevicesCount);
  return 0;
}

int lifxDecoder_DecodeTileStateDeviceChain(lifxBuffer_t* buff, lifxTileStateDeviceChain_t* pkt)
{
  // {'pkt_type': 702, 'size_bytes': 882, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'TileDevices', 'type': '[16]<TileStateDevice>', 'size_bytes': 880}, {'name': 'TileDevicesCount', 'type': 'uint8', 'size_bytes': 1}]}
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->StartIndex);
  // {'name': 'TileDevices', 'type': '[16]<TileStateDevice>', 'size_bytes': 880}
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices);
  // {'name': 'TileDevicesCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->TileDevicesCount);
  return 0;
}

int lifxEncoder_EncodeTileSetUserPosition(lifxBuffer_t* buff, lifxTileSetUserPosition_t const* pkt)
{
  // {'pkt_type': 703, 'size_bytes': 11, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'UserX', 'type': 'float32', 'size_bytes': 4}, {'name': 'UserY', 'type': 'float32', 'size_bytes': 4}]}
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->TileIndex);
  // {'type': 'reserved', 'size_bytes': 2}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'name': 'UserX', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_WriteFloat(buff, pkt->UserX);
  // {'name': 'UserY', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_WriteFloat(buff, pkt->UserY);
  return 0;
}

int lifxDecoder_DecodeTileSetUserPosition(lifxBuffer_t* buff, lifxTileSetUserPosition_t* pkt)
{
  // {'pkt_type': 703, 'size_bytes': 11, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'UserX', 'type': 'float32', 'size_bytes': 4}, {'name': 'UserY', 'type': 'float32', 'size_bytes': 4}]}
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->TileIndex);
  // {'type': 'reserved', 'size_bytes': 2}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'name': 'UserX', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_ReadFloat(buff, &pkt->UserX);
  // {'name': 'UserY', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_ReadFloat(buff, &pkt->UserY);
  return 0;
}

int lifxEncoder_EncodeTileGet64(lifxBuffer_t* buff, lifxTileGet64_t const* pkt)
{
  // {'pkt_type': 707, 'size_bytes': 6, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}]}
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->TileIndex);
  // {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Length);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxEncoder_EncodeTileBufferRect(buff, &pkt->Rect);
  return 0;
}

int lifxDecoder_DecodeTileGet64(lifxBuffer_t* buff, lifxTileGet64_t* pkt)
{
  // {'pkt_type': 707, 'size_bytes': 6, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}]}
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->TileIndex);
  // {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Length);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxDecoder_DecodeTileBufferRect(buff, &pkt->Rect);
  return 0;
}

int lifxEncoder_EncodeTileState64(lifxBuffer_t* buff, lifxTileState64_t const* pkt)
{
  // {'pkt_type': 711, 'size_bytes': 517, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}, {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}]}
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->TileIndex);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxEncoder_EncodeTileBufferRect(buff, &pkt->Rect);
  // {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors);
  return 0;
}

int lifxDecoder_DecodeTileState64(lifxBuffer_t* buff, lifxTileState64_t* pkt)
{
  // {'pkt_type': 711, 'size_bytes': 517, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}, {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}]}
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->TileIndex);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxDecoder_DecodeTileBufferRect(buff, &pkt->Rect);
  // {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors);
  return 0;
}

int lifxEncoder_EncodeTileSet64(lifxBuffer_t* buff, lifxTileSet64_t const* pkt)
{
  // {'pkt_type': 715, 'size_bytes': 522, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}]}
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->TileIndex);
  // {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Length);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxEncoder_EncodeTileBufferRect(buff, &pkt->Rect);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  // {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors);
  return 0;
}

int lifxDecoder_DecodeTileSet64(lifxBuffer_t* buff, lifxTileSet64_t* pkt)
{
  // {'pkt_type': 715, 'size_bytes': 522, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}]}
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->TileIndex);
  // {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Length);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxDecoder_DecodeTileBufferRect(buff, &pkt->Rect);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  // {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors);
  return 0;
}

int lifxEncoder_EncodeTileGetEffect(lifxBuffer_t* buff, lifxTileGetEffect_t const* pkt)
{
  // {'pkt_type': 718, 'size_bytes': 2, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}]}
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved0);
  // {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved1);
  return 0;
}

int lifxDecoder_DecodeTileGetEffect(lifxBuffer_t* buff, lifxTileGetEffect_t* pkt)
{
  // {'pkt_type': 718, 'size_bytes': 2, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}]}
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved0);
  // {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved1);
  return 0;
}

int lifxEncoder_EncodeTileSetEffect(lifxBuffer_t* buff, lifxTileSetEffect_t const* pkt)
{
  // {'pkt_type': 719, 'size_bytes': 188, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved0);
  // {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved1);
  // {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}
  lifxEncoder_EncodeTileEffectSettings(buff, &pkt->Settings);
  return 0;
}

int lifxDecoder_DecodeTileSetEffect(lifxBuffer_t* buff, lifxTileSetEffect_t* pkt)
{
  // {'pkt_type': 719, 'size_bytes': 188, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved0);
  // {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved1);
  // {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}
  lifxDecoder_DecodeTileEffectSettings(buff, &pkt->Settings);
  return 0;
}

int lifxEncoder_EncodeTileStateEffect(lifxBuffer_t* buff, lifxTileStateEffect_t const* pkt)
{
  // {'pkt_type': 720, 'size_bytes': 187, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved0);
  // {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}
  lifxEncoder_EncodeTileEffectSettings(buff, &pkt->Settings);
  return 0;
}

int lifxDecoder_DecodeTileStateEffect(lifxBuffer_t* buff, lifxTileStateEffect_t* pkt)
{
  // {'pkt_type': 720, 'size_bytes': 187, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved0);
  // {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}
  lifxDecoder_DecodeTileEffectSettings(buff, &pkt->Settings);
  return 0;
}

int lifxEncoder_EncodeMultiZoneSetColorZones(lifxBuffer_t* buff, lifxMultiZoneSetColorZones_t const* pkt)
{
  // {'pkt_type': 501, 'size_bytes': 15, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Apply', 'type': '<MultiZoneApplicationRequest>', 'size_bytes': 1}]}
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->StartIndex);
  // {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->EndIndex);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Color);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  // {'name': 'Apply', 'type': '<MultiZoneApplicationRequest>', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Apply);
  return 0;
}

int lifxDecoder_DecodeMultiZoneSetColorZones(lifxBuffer_t* buff, lifxMultiZoneSetColorZones_t* pkt)
{
  // {'pkt_type': 501, 'size_bytes': 15, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Apply', 'type': '<MultiZoneApplicationRequest>', 'size_bytes': 1}]}
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->StartIndex);
  // {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->EndIndex);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Color);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  // {'name': 'Apply', 'type': '<MultiZoneApplicationRequest>', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Apply);
  return 0;
}

int lifxEncoder_EncodeMultiZoneGetColorZones(lifxBuffer_t* buff, lifxMultiZoneGetColorZones_t const* pkt)
{
  // {'pkt_type': 502, 'size_bytes': 2, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}]}
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->StartIndex);
  // {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->EndIndex);
  return 0;
}

int lifxDecoder_DecodeMultiZoneGetColorZones(lifxBuffer_t* buff, lifxMultiZoneGetColorZones_t* pkt)
{
  // {'pkt_type': 502, 'size_bytes': 2, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}]}
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->StartIndex);
  // {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->EndIndex);
  return 0;
}

int lifxEncoder_EncodeMultiZoneStateZone(lifxBuffer_t* buff, lifxMultiZoneStateZone_t const* pkt)
{
  // {'pkt_type': 503, 'size_bytes': 10, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}]}
  // {'name': 'Count', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Count);
  // {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Index);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Color);
  return 0;
}

int lifxDecoder_DecodeMultiZoneStateZone(lifxBuffer_t* buff, lifxMultiZoneStateZone_t* pkt)
{
  // {'pkt_type': 503, 'size_bytes': 10, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}]}
  // {'name': 'Count', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Count);
  // {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Index);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Color);
  return 0;
}

int lifxEncoder_EncodeMultiZoneStateMultiZone(lifxBuffer_t* buff, lifxMultiZoneStateMultiZone_t const* pkt)
{
  // {'pkt_type': 506, 'size_bytes': 66, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[8]<LightHsbk>', 'size_bytes': 64}]}
  // {'name': 'Count', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Count);
  // {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Index);
  // {'name': 'Colors', 'type': '[8]<LightHsbk>', 'size_bytes': 64}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors);
  return 0;
}

int lifxDecoder_DecodeMultiZoneStateMultiZone(lifxBuffer_t* buff, lifxMultiZoneStateMultiZone_t* pkt)
{
  // {'pkt_type': 506, 'size_bytes': 66, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[8]<LightHsbk>', 'size_bytes': 64}]}
  // {'name': 'Count', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Count);
  // {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Index);
  // {'name': 'Colors', 'type': '[8]<LightHsbk>', 'size_bytes': 64}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors);
  return 0;
}

int lifxEncoder_EncodeMultiZoneGetEffect(lifxBuffer_t* buff, lifxMultiZoneGetEffect_t const* pkt)
{
  // {'pkt_type': 507, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeMultiZoneGetEffect(lifxBuffer_t* buff, lifxMultiZoneGetEffect_t* pkt)
{
  // {'pkt_type': 507, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeMultiZoneSetEffect(lifxBuffer_t* buff, lifxMultiZoneSetEffect_t const* pkt)
{
  // {'pkt_type': 508, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
  // {'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}
  lifxEncoder_EncodeMultiZoneEffectSettings(buff, &pkt->Settings);
  return 0;
}

int lifxDecoder_DecodeMultiZoneSetEffect(lifxBuffer_t* buff, lifxMultiZoneSetEffect_t* pkt)
{
  // {'pkt_type': 508, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
  // {'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}
  lifxDecoder_DecodeMultiZoneEffectSettings(buff, &pkt->Settings);
  return 0;
}

int lifxEncoder_EncodeMultiZoneStateEffect(lifxBuffer_t* buff, lifxMultiZoneStateEffect_t const* pkt)
{
  // {'pkt_type': 509, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
  // {'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}
  lifxEncoder_EncodeMultiZoneEffectSettings(buff, &pkt->Settings);
  return 0;
}

int lifxDecoder_DecodeMultiZoneStateEffect(lifxBuffer_t* buff, lifxMultiZoneStateEffect_t* pkt)
{
  // {'pkt_type': 509, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
  // {'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}
  lifxDecoder_DecodeMultiZoneEffectSettings(buff, &pkt->Settings);
  return 0;
}

int lifxEncoder_EncodeMultiZoneExtendedSetColorZones(lifxBuffer_t* buff, lifxMultiZoneExtendedSetColorZones_t const* pkt)
{
  // {'pkt_type': 510, 'size_bytes': 664, 'fields': [{'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Apply', 'type': '<MultiZoneExtendedApplicationRequest>', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}, {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}]}
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  // {'name': 'Apply', 'type': '<MultiZoneExtendedApplicationRequest>', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Apply);
  // {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Index);
  // {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->ColorsCount);
  // {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors);
  return 0;
}

int lifxDecoder_DecodeMultiZoneExtendedSetColorZones(lifxBuffer_t* buff, lifxMultiZoneExtendedSetColorZones_t* pkt)
{
  // {'pkt_type': 510, 'size_bytes': 664, 'fields': [{'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Apply', 'type': '<MultiZoneExtendedApplicationRequest>', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}, {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}]}
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  // {'name': 'Apply', 'type': '<MultiZoneExtendedApplicationRequest>', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Apply);
  // {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Index);
  // {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->ColorsCount);
  // {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors);
  return 0;
}

int lifxEncoder_EncodeMultiZoneExtendedGetColorZones(lifxBuffer_t* buff, lifxMultiZoneExtendedGetColorZones_t const* pkt)
{
  // {'pkt_type': 511, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxDecoder_DecodeMultiZoneExtendedGetColorZones(lifxBuffer_t* buff, lifxMultiZoneExtendedGetColorZones_t* pkt)
{
  // {'pkt_type': 511, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeMultiZoneExtendedStateMultiZone(lifxBuffer_t* buff, lifxMultiZoneExtendedStateMultiZone_t const* pkt)
{
  // {'pkt_type': 512, 'size_bytes': 661, 'fields': [{'name': 'Count', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}, {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}]}
  // {'name': 'Count', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Count);
  // {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Index);
  // {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->ColorsCount);
  // {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors);
  return 0;
}

int lifxDecoder_DecodeMultiZoneExtendedStateMultiZone(lifxBuffer_t* buff, lifxMultiZoneExtendedStateMultiZone_t* pkt)
{
  // {'pkt_type': 512, 'size_bytes': 661, 'fields': [{'name': 'Count', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}, {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}]}
  // {'name': 'Count', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Count);
  // {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Index);
  // {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->ColorsCount);
  // {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors);
  return 0;
}

int lifxEncoder_EncodeLightHsbk(lifxBuffer_t* buff, lifxLightHsbk_t const* pkt)
{
  // {'size_bytes': 8, 'fields': [{'name': 'Hue', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Saturation', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Kelvin', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Hue', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Hue);
  // {'name': 'Saturation', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Saturation);
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Brightness);
  // {'name': 'Kelvin', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Kelvin);
  return 0;
}

int lifxDecoder_DecodeLightHsbk(lifxBuffer_t* buff, lifxLightHsbk_t* pkt)
{
  // {'size_bytes': 8, 'fields': [{'name': 'Hue', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Saturation', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Kelvin', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Hue', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Hue);
  // {'name': 'Saturation', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Saturation);
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Brightness);
  // {'name': 'Kelvin', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Kelvin);
  return 0;
}

int lifxEncoder_EncodeMultiZoneEffectParameter(lifxBuffer_t* buff, lifxMultiZoneEffectParameter_t const* pkt)
{
  // {'size_bytes': 32, 'fields': [{'name': 'Parameter0', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter1', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter2', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter3', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter4', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter5', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter6', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter7', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Parameter0', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter0);
  // {'name': 'Parameter1', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter1);
  // {'name': 'Parameter2', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter2);
  // {'name': 'Parameter3', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter3);
  // {'name': 'Parameter4', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter4);
  // {'name': 'Parameter5', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter5);
  // {'name': 'Parameter6', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter6);
  // {'name': 'Parameter7', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter7);
  return 0;
}

int lifxDecoder_DecodeMultiZoneEffectParameter(lifxBuffer_t* buff, lifxMultiZoneEffectParameter_t* pkt)
{
  // {'size_bytes': 32, 'fields': [{'name': 'Parameter0', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter1', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter2', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter3', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter4', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter5', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter6', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter7', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Parameter0', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter0);
  // {'name': 'Parameter1', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter1);
  // {'name': 'Parameter2', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter2);
  // {'name': 'Parameter3', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter3);
  // {'name': 'Parameter4', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter4);
  // {'name': 'Parameter5', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter5);
  // {'name': 'Parameter6', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter6);
  // {'name': 'Parameter7', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter7);
  return 0;
}

int lifxEncoder_EncodeMultiZoneEffectSettings(lifxBuffer_t* buff, lifxMultiZoneEffectSettings_t const* pkt)
{
  // {'size_bytes': 59, 'fields': [{'name': 'Instanceid', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Type', 'type': '<MultiZoneEffectType>', 'size_bytes': 1}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'Speed', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Duration', 'type': 'uint64', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 4}, {'type': 'reserved', 'size_bytes': 4}, {'name': 'Parameter', 'type': '<MultiZoneEffectParameter>', 'size_bytes': 32}]}
  // {'name': 'Instanceid', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Instanceid);
  // {'name': 'Type', 'type': '<MultiZoneEffectType>', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Type);
  // {'type': 'reserved', 'size_bytes': 2}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'name': 'Speed', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Speed);
  // {'name': 'Duration', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->Duration);
  // {'type': 'reserved', 'size_bytes': 4}
  lifxBuffer_Seek(buff, 4, kLifxBufferWhenceCurrent);
  // {'type': 'reserved', 'size_bytes': 4}
  lifxBuffer_Seek(buff, 4, kLifxBufferWhenceCurrent);
  // {'name': 'Parameter', 'type': '<MultiZoneEffectParameter>', 'size_bytes': 32}
  lifxEncoder_EncodeMultiZoneEffectParameter(buff, &pkt->Parameter);
  return 0;
}

int lifxDecoder_DecodeMultiZoneEffectSettings(lifxBuffer_t* buff, lifxMultiZoneEffectSettings_t* pkt)
{
  // {'size_bytes': 59, 'fields': [{'name': 'Instanceid', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Type', 'type': '<MultiZoneEffectType>', 'size_bytes': 1}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'Speed', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Duration', 'type': 'uint64', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 4}, {'type': 'reserved', 'size_bytes': 4}, {'name': 'Parameter', 'type': '<MultiZoneEffectParameter>', 'size_bytes': 32}]}
  // {'name': 'Instanceid', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Instanceid);
  // {'name': 'Type', 'type': '<MultiZoneEffectType>', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Type);
  // {'type': 'reserved', 'size_bytes': 2}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'name': 'Speed', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Speed);
  // {'name': 'Duration', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->Duration);
  // {'type': 'reserved', 'size_bytes': 4}
  lifxBuffer_Seek(buff, 4, kLifxBufferWhenceCurrent);
  // {'type': 'reserved', 'size_bytes': 4}
  lifxBuffer_Seek(buff, 4, kLifxBufferWhenceCurrent);
  // {'name': 'Parameter', 'type': '<MultiZoneEffectParameter>', 'size_bytes': 32}
  lifxDecoder_DecodeMultiZoneEffectParameter(buff, &pkt->Parameter);
  return 0;
}

int lifxEncoder_EncodeTileAccelMeas(lifxBuffer_t* buff, lifxTileAccelMeas_t const* pkt)
{
  // {'size_bytes': 6, 'fields': [{'name': 'X', 'type': 'int16', 'size_bytes': 2}, {'name': 'Y', 'type': 'int16', 'size_bytes': 2}, {'name': 'Z', 'type': 'int16', 'size_bytes': 2}]}
  // {'name': 'X', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_WriteInt16(buff, pkt->X);
  // {'name': 'Y', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_WriteInt16(buff, pkt->Y);
  // {'name': 'Z', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_WriteInt16(buff, pkt->Z);
  return 0;
}

int lifxDecoder_DecodeTileAccelMeas(lifxBuffer_t* buff, lifxTileAccelMeas_t* pkt)
{
  // {'size_bytes': 6, 'fields': [{'name': 'X', 'type': 'int16', 'size_bytes': 2}, {'name': 'Y', 'type': 'int16', 'size_bytes': 2}, {'name': 'Z', 'type': 'int16', 'size_bytes': 2}]}
  // {'name': 'X', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_ReadInt16(buff, &pkt->X);
  // {'name': 'Y', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_ReadInt16(buff, &pkt->Y);
  // {'name': 'Z', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_ReadInt16(buff, &pkt->Z);
  return 0;
}

int lifxEncoder_EncodeTileStateDevice(lifxBuffer_t* buff, lifxTileStateDevice_t const* pkt)
{
  // {'size_bytes': 55, 'fields': [{'name': 'AccelMeas', 'type': '<TileAccelMeas>', 'size_bytes': 6}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'UserX', 'type': 'float32', 'size_bytes': 4}, {'name': 'UserY', 'type': 'float32', 'size_bytes': 4}, {'name': 'Width', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Height', 'type': 'uint8', 'size_bytes': 1}, {'type': 'reserved', 'size_bytes': 1}, {'name': 'DeviceVersion', 'type': '<DeviceStateVersion>', 'size_bytes': 12}, {'name': 'Firmware', 'type': '<DeviceStateHostFirmware>', 'size_bytes': 20}, {'type': 'reserved', 'size_bytes': 4}]}
  // {'name': 'AccelMeas', 'type': '<TileAccelMeas>', 'size_bytes': 6}
  lifxEncoder_EncodeTileAccelMeas(buff, &pkt->AccelMeas);
  // {'type': 'reserved', 'size_bytes': 2}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'name': 'UserX', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_WriteFloat(buff, pkt->UserX);
  // {'name': 'UserY', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_WriteFloat(buff, pkt->UserY);
  // {'name': 'Width', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Width);
  // {'name': 'Height', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Height);
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'DeviceVersion', 'type': '<DeviceStateVersion>', 'size_bytes': 12}
  lifxEncoder_EncodeDeviceStateVersion(buff, &pkt->DeviceVersion);
  // {'name': 'Firmware', 'type': '<DeviceStateHostFirmware>', 'size_bytes': 20}
  lifxEncoder_EncodeDeviceStateHostFirmware(buff, &pkt->Firmware);
  // {'type': 'reserved', 'size_bytes': 4}
  lifxBuffer_Seek(buff, 4, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxDecoder_DecodeTileStateDevice(lifxBuffer_t* buff, lifxTileStateDevice_t* pkt)
{
  // {'size_bytes': 55, 'fields': [{'name': 'AccelMeas', 'type': '<TileAccelMeas>', 'size_bytes': 6}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'UserX', 'type': 'float32', 'size_bytes': 4}, {'name': 'UserY', 'type': 'float32', 'size_bytes': 4}, {'name': 'Width', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Height', 'type': 'uint8', 'size_bytes': 1}, {'type': 'reserved', 'size_bytes': 1}, {'name': 'DeviceVersion', 'type': '<DeviceStateVersion>', 'size_bytes': 12}, {'name': 'Firmware', 'type': '<DeviceStateHostFirmware>', 'size_bytes': 20}, {'type': 'reserved', 'size_bytes': 4}]}
  // {'name': 'AccelMeas', 'type': '<TileAccelMeas>', 'size_bytes': 6}
  lifxDecoder_DecodeTileAccelMeas(buff, &pkt->AccelMeas);
  // {'type': 'reserved', 'size_bytes': 2}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'name': 'UserX', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_ReadFloat(buff, &pkt->UserX);
  // {'name': 'UserY', 'type': 'float32', 'size_bytes': 4}
  lifxBuffer_ReadFloat(buff, &pkt->UserY);
  // {'name': 'Width', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Width);
  // {'name': 'Height', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Height);
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'DeviceVersion', 'type': '<DeviceStateVersion>', 'size_bytes': 12}
  lifxDecoder_DecodeDeviceStateVersion(buff, &pkt->DeviceVersion);
  // {'name': 'Firmware', 'type': '<DeviceStateHostFirmware>', 'size_bytes': 20}
  lifxDecoder_DecodeDeviceStateHostFirmware(buff, &pkt->Firmware);
  // {'type': 'reserved', 'size_bytes': 4}
  lifxBuffer_Seek(buff, 4, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxEncoder_EncodeTileBufferRect(lifxBuffer_t* buff, lifxTileBufferRect_t const* pkt)
{
  // {'size_bytes': 4, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'X', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Y', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Width', 'type': 'uint8', 'size_bytes': 1}]}
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'X', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->X);
  // {'name': 'Y', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Y);
  // {'name': 'Width', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Width);
  return 0;
}

int lifxDecoder_DecodeTileBufferRect(lifxBuffer_t* buff, lifxTileBufferRect_t* pkt)
{
  // {'size_bytes': 4, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'X', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Y', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Width', 'type': 'uint8', 'size_bytes': 1}]}
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'X', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->X);
  // {'name': 'Y', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Y);
  // {'name': 'Width', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Width);
  return 0;
}

int lifxEncoder_EncodeTileEffectParameter(lifxBuffer_t* buff, lifxTileEffectParameter_t const* pkt)
{
  // {'size_bytes': 32, 'fields': [{'name': 'Parameter0', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter1', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter2', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter3', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter4', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter5', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter6', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter7', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Parameter0', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter0);
  // {'name': 'Parameter1', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter1);
  // {'name': 'Parameter2', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter2);
  // {'name': 'Parameter3', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter3);
  // {'name': 'Parameter4', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter4);
  // {'name': 'Parameter5', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter5);
  // {'name': 'Parameter6', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter6);
  // {'name': 'Parameter7', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter7);
  return 0;
}

int lifxDecoder_DecodeTileEffectParameter(lifxBuffer_t* buff, lifxTileEffectParameter_t* pkt)
{
  // {'size_bytes': 32, 'fields': [{'name': 'Parameter0', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter1', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter2', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter3', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter4', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter5', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter6', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter7', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Parameter0', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter0);
  // {'name': 'Parameter1', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter1);
  // {'name': 'Parameter2', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter2);
  // {'name': 'Parameter3', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter3);
  // {'name': 'Parameter4', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter4);
  // {'name': 'Parameter5', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter5);
  // {'name': 'Parameter6', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter6);
  // {'name': 'Parameter7', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter7);
  return 0;
}

int lifxEncoder_EncodeTileEffectSettings(lifxBuffer_t* buff, lifxTileEffectSettings_t const* pkt)
{
  // {'size_bytes': 186, 'fields': [{'name': 'Instanceid', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Type', 'type': '<TileEffectType>', 'size_bytes': 1}, {'name': 'Speed', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Duration', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Reserved0', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Reserved1', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter', 'type': '<TileEffectParameter>', 'size_bytes': 32}, {'name': 'PaletteCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Palette', 'type': '[16]<LightHsbk>', 'size_bytes': 128}]}
  // {'name': 'Instanceid', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Instanceid);
  // {'name': 'Type', 'type': '<TileEffectType>', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Type);
  // {'name': 'Speed', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Speed);
  // {'name': 'Duration', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->Duration);
  // {'name': 'Reserved0', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Reserved0);
  // {'name': 'Reserved1', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Reserved1);
  // {'name': 'Parameter', 'type': '<TileEffectParameter>', 'size_bytes': 32}
  lifxEncoder_EncodeTileEffectParameter(buff, &pkt->Parameter);
  // {'name': 'PaletteCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->PaletteCount);
  // {'name': 'Palette', 'type': '[16]<LightHsbk>', 'size_bytes': 128}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette);
  return 0;
}

int lifxDecoder_DecodeTileEffectSettings(lifxBuffer_t* buff, lifxTileEffectSettings_t* pkt)
{
  // {'size_bytes': 186, 'fields': [{'name': 'Instanceid', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Type', 'type': '<TileEffectType>', 'size_bytes': 1}, {'name': 'Speed', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Duration', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Reserved0', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Reserved1', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter', 'type': '<TileEffectParameter>', 'size_bytes': 32}, {'name': 'PaletteCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Palette', 'type': '[16]<LightHsbk>', 'size_bytes': 128}]}
  // {'name': 'Instanceid', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Instanceid);
  // {'name': 'Type', 'type': '<TileEffectType>', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Type);
  // {'name': 'Speed', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Speed);
  // {'name': 'Duration', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->Duration);
  // {'name': 'Reserved0', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Reserved0);
  // {'name': 'Reserved1', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Reserved1);
  // {'name': 'Parameter', 'type': '<TileEffectParameter>', 'size_bytes': 32}
  lifxDecoder_DecodeTileEffectParameter(buff, &pkt->Parameter);
  // {'name': 'PaletteCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->PaletteCount);
  // {'name': 'Palette', 'type': '[16]<LightHsbk>', 'size_bytes': 128}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette);
  return 0;
}

