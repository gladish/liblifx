//
// DO NOT EDIT - AUTO-GENERATE:2020-02-24 16:44:03.993217
//
#include "lifx_private.h"
#include "lifx_encoders.h"

lifxStatus_t lifxDecoder_DecodePacket(lifxBuffer_t* buff, lifxPacketType_t type, lifxPacket_t* pkt)
{
  lifxStatus_t status = kLifxStatusOk;
  switch (type)
  {
    case kLifxPacketTypeDeviceGetService:
    status = lifxDecoder_DecodeDeviceGetService(buff, &pkt->DeviceGetService);
    break;
    case kLifxPacketTypeDeviceStateService:
    status = lifxDecoder_DecodeDeviceStateService(buff, &pkt->DeviceStateService);
    break;
    case kLifxPacketTypeDeviceGetHostInfo:
    status = lifxDecoder_DecodeDeviceGetHostInfo(buff, &pkt->DeviceGetHostInfo);
    break;
    case kLifxPacketTypeDeviceStateHostInfo:
    status = lifxDecoder_DecodeDeviceStateHostInfo(buff, &pkt->DeviceStateHostInfo);
    break;
    case kLifxPacketTypeDeviceGetHostFirmware:
    status = lifxDecoder_DecodeDeviceGetHostFirmware(buff, &pkt->DeviceGetHostFirmware);
    break;
    case kLifxPacketTypeDeviceStateHostFirmware:
    status = lifxDecoder_DecodeDeviceStateHostFirmware(buff, &pkt->DeviceStateHostFirmware);
    break;
    case kLifxPacketTypeDeviceGetWifiInfo:
    status = lifxDecoder_DecodeDeviceGetWifiInfo(buff, &pkt->DeviceGetWifiInfo);
    break;
    case kLifxPacketTypeDeviceStateWifiInfo:
    status = lifxDecoder_DecodeDeviceStateWifiInfo(buff, &pkt->DeviceStateWifiInfo);
    break;
    case kLifxPacketTypeDeviceGetWifiFirmware:
    status = lifxDecoder_DecodeDeviceGetWifiFirmware(buff, &pkt->DeviceGetWifiFirmware);
    break;
    case kLifxPacketTypeDeviceStateWifiFirmware:
    status = lifxDecoder_DecodeDeviceStateWifiFirmware(buff, &pkt->DeviceStateWifiFirmware);
    break;
    case kLifxPacketTypeDeviceGetPower:
    status = lifxDecoder_DecodeDeviceGetPower(buff, &pkt->DeviceGetPower);
    break;
    case kLifxPacketTypeDeviceSetPower:
    status = lifxDecoder_DecodeDeviceSetPower(buff, &pkt->DeviceSetPower);
    break;
    case kLifxPacketTypeDeviceStatePower:
    status = lifxDecoder_DecodeDeviceStatePower(buff, &pkt->DeviceStatePower);
    break;
    case kLifxPacketTypeDeviceGetLabel:
    status = lifxDecoder_DecodeDeviceGetLabel(buff, &pkt->DeviceGetLabel);
    break;
    case kLifxPacketTypeDeviceSetLabel:
    status = lifxDecoder_DecodeDeviceSetLabel(buff, &pkt->DeviceSetLabel);
    break;
    case kLifxPacketTypeDeviceStateLabel:
    status = lifxDecoder_DecodeDeviceStateLabel(buff, &pkt->DeviceStateLabel);
    break;
    case kLifxPacketTypeDeviceGetVersion:
    status = lifxDecoder_DecodeDeviceGetVersion(buff, &pkt->DeviceGetVersion);
    break;
    case kLifxPacketTypeDeviceStateVersion:
    status = lifxDecoder_DecodeDeviceStateVersion(buff, &pkt->DeviceStateVersion);
    break;
    case kLifxPacketTypeDeviceGetInfo:
    status = lifxDecoder_DecodeDeviceGetInfo(buff, &pkt->DeviceGetInfo);
    break;
    case kLifxPacketTypeDeviceStateInfo:
    status = lifxDecoder_DecodeDeviceStateInfo(buff, &pkt->DeviceStateInfo);
    break;
    case kLifxPacketTypeDeviceAcknowledgement:
    status = lifxDecoder_DecodeDeviceAcknowledgement(buff, &pkt->DeviceAcknowledgement);
    break;
    case kLifxPacketTypeDeviceGetLocation:
    status = lifxDecoder_DecodeDeviceGetLocation(buff, &pkt->DeviceGetLocation);
    break;
    case kLifxPacketTypeDeviceSetLocation:
    status = lifxDecoder_DecodeDeviceSetLocation(buff, &pkt->DeviceSetLocation);
    break;
    case kLifxPacketTypeDeviceStateLocation:
    status = lifxDecoder_DecodeDeviceStateLocation(buff, &pkt->DeviceStateLocation);
    break;
    case kLifxPacketTypeDeviceGetGroup:
    status = lifxDecoder_DecodeDeviceGetGroup(buff, &pkt->DeviceGetGroup);
    break;
    case kLifxPacketTypeDeviceSetGroup:
    status = lifxDecoder_DecodeDeviceSetGroup(buff, &pkt->DeviceSetGroup);
    break;
    case kLifxPacketTypeDeviceStateGroup:
    status = lifxDecoder_DecodeDeviceStateGroup(buff, &pkt->DeviceStateGroup);
    break;
    case kLifxPacketTypeDeviceEchoRequest:
    status = lifxDecoder_DecodeDeviceEchoRequest(buff, &pkt->DeviceEchoRequest);
    break;
    case kLifxPacketTypeDeviceEchoResponse:
    status = lifxDecoder_DecodeDeviceEchoResponse(buff, &pkt->DeviceEchoResponse);
    break;
    case kLifxPacketTypeLightGet:
    status = lifxDecoder_DecodeLightGet(buff, &pkt->LightGet);
    break;
    case kLifxPacketTypeLightSetColor:
    status = lifxDecoder_DecodeLightSetColor(buff, &pkt->LightSetColor);
    break;
    case kLifxPacketTypeLightSetWaveform:
    status = lifxDecoder_DecodeLightSetWaveform(buff, &pkt->LightSetWaveform);
    break;
    case kLifxPacketTypeLightState:
    status = lifxDecoder_DecodeLightState(buff, &pkt->LightState);
    break;
    case kLifxPacketTypeLightGetPower:
    status = lifxDecoder_DecodeLightGetPower(buff, &pkt->LightGetPower);
    break;
    case kLifxPacketTypeLightSetPower:
    status = lifxDecoder_DecodeLightSetPower(buff, &pkt->LightSetPower);
    break;
    case kLifxPacketTypeLightStatePower:
    status = lifxDecoder_DecodeLightStatePower(buff, &pkt->LightStatePower);
    break;
    case kLifxPacketTypeLightSetWaveformOptional:
    status = lifxDecoder_DecodeLightSetWaveformOptional(buff, &pkt->LightSetWaveformOptional);
    break;
    case kLifxPacketTypeLightGetInfrared:
    status = lifxDecoder_DecodeLightGetInfrared(buff, &pkt->LightGetInfrared);
    break;
    case kLifxPacketTypeLightStateInfrared:
    status = lifxDecoder_DecodeLightStateInfrared(buff, &pkt->LightStateInfrared);
    break;
    case kLifxPacketTypeLightSetInfrared:
    status = lifxDecoder_DecodeLightSetInfrared(buff, &pkt->LightSetInfrared);
    break;
    case kLifxPacketTypeMultiZoneSetColorZones:
    status = lifxDecoder_DecodeMultiZoneSetColorZones(buff, &pkt->MultiZoneSetColorZones);
    break;
    case kLifxPacketTypeMultiZoneGetColorZones:
    status = lifxDecoder_DecodeMultiZoneGetColorZones(buff, &pkt->MultiZoneGetColorZones);
    break;
    case kLifxPacketTypeMultiZoneStateZone:
    status = lifxDecoder_DecodeMultiZoneStateZone(buff, &pkt->MultiZoneStateZone);
    break;
    case kLifxPacketTypeMultiZoneStateMultiZone:
    status = lifxDecoder_DecodeMultiZoneStateMultiZone(buff, &pkt->MultiZoneStateMultiZone);
    break;
    case kLifxPacketTypeMultiZoneGetEffect:
    status = lifxDecoder_DecodeMultiZoneGetEffect(buff, &pkt->MultiZoneGetEffect);
    break;
    case kLifxPacketTypeMultiZoneSetEffect:
    status = lifxDecoder_DecodeMultiZoneSetEffect(buff, &pkt->MultiZoneSetEffect);
    break;
    case kLifxPacketTypeMultiZoneStateEffect:
    status = lifxDecoder_DecodeMultiZoneStateEffect(buff, &pkt->MultiZoneStateEffect);
    break;
    case kLifxPacketTypeMultiZoneExtendedSetColorZones:
    status = lifxDecoder_DecodeMultiZoneExtendedSetColorZones(buff, &pkt->MultiZoneExtendedSetColorZones);
    break;
    case kLifxPacketTypeMultiZoneExtendedGetColorZones:
    status = lifxDecoder_DecodeMultiZoneExtendedGetColorZones(buff, &pkt->MultiZoneExtendedGetColorZones);
    break;
    case kLifxPacketTypeMultiZoneExtendedStateMultiZone:
    status = lifxDecoder_DecodeMultiZoneExtendedStateMultiZone(buff, &pkt->MultiZoneExtendedStateMultiZone);
    break;
    case kLifxPacketTypeTileGetDeviceChain:
    status = lifxDecoder_DecodeTileGetDeviceChain(buff, &pkt->TileGetDeviceChain);
    break;
    case kLifxPacketTypeTileStateDeviceChain:
    status = lifxDecoder_DecodeTileStateDeviceChain(buff, &pkt->TileStateDeviceChain);
    break;
    case kLifxPacketTypeTileSetUserPosition:
    status = lifxDecoder_DecodeTileSetUserPosition(buff, &pkt->TileSetUserPosition);
    break;
    case kLifxPacketTypeTileGet64:
    status = lifxDecoder_DecodeTileGet64(buff, &pkt->TileGet64);
    break;
    case kLifxPacketTypeTileState64:
    status = lifxDecoder_DecodeTileState64(buff, &pkt->TileState64);
    break;
    case kLifxPacketTypeTileSet64:
    status = lifxDecoder_DecodeTileSet64(buff, &pkt->TileSet64);
    break;
    case kLifxPacketTypeTileGetEffect:
    status = lifxDecoder_DecodeTileGetEffect(buff, &pkt->TileGetEffect);
    break;
    case kLifxPacketTypeTileSetEffect:
    status = lifxDecoder_DecodeTileSetEffect(buff, &pkt->TileSetEffect);
    break;
    case kLifxPacketTypeTileStateEffect:
    status = lifxDecoder_DecodeTileStateEffect(buff, &pkt->TileStateEffect);
    break;
  }
  return status;
}

lifxStatus_t lifxEncoder_EncodePacket(lifxBuffer_t* buff, lifxPacketType_t type, lifxPacket_t const* pkt)
{
  lifxStatus_t status = kLifxStatusOk;
  switch (type)
  {
    case kLifxPacketTypeDeviceGetService:
    status = lifxEncoder_EncodeDeviceGetService(buff, &pkt->DeviceGetService);
    break;
    case kLifxPacketTypeDeviceStateService:
    status = lifxEncoder_EncodeDeviceStateService(buff, &pkt->DeviceStateService);
    break;
    case kLifxPacketTypeDeviceGetHostInfo:
    status = lifxEncoder_EncodeDeviceGetHostInfo(buff, &pkt->DeviceGetHostInfo);
    break;
    case kLifxPacketTypeDeviceStateHostInfo:
    status = lifxEncoder_EncodeDeviceStateHostInfo(buff, &pkt->DeviceStateHostInfo);
    break;
    case kLifxPacketTypeDeviceGetHostFirmware:
    status = lifxEncoder_EncodeDeviceGetHostFirmware(buff, &pkt->DeviceGetHostFirmware);
    break;
    case kLifxPacketTypeDeviceStateHostFirmware:
    status = lifxEncoder_EncodeDeviceStateHostFirmware(buff, &pkt->DeviceStateHostFirmware);
    break;
    case kLifxPacketTypeDeviceGetWifiInfo:
    status = lifxEncoder_EncodeDeviceGetWifiInfo(buff, &pkt->DeviceGetWifiInfo);
    break;
    case kLifxPacketTypeDeviceStateWifiInfo:
    status = lifxEncoder_EncodeDeviceStateWifiInfo(buff, &pkt->DeviceStateWifiInfo);
    break;
    case kLifxPacketTypeDeviceGetWifiFirmware:
    status = lifxEncoder_EncodeDeviceGetWifiFirmware(buff, &pkt->DeviceGetWifiFirmware);
    break;
    case kLifxPacketTypeDeviceStateWifiFirmware:
    status = lifxEncoder_EncodeDeviceStateWifiFirmware(buff, &pkt->DeviceStateWifiFirmware);
    break;
    case kLifxPacketTypeDeviceGetPower:
    status = lifxEncoder_EncodeDeviceGetPower(buff, &pkt->DeviceGetPower);
    break;
    case kLifxPacketTypeDeviceSetPower:
    status = lifxEncoder_EncodeDeviceSetPower(buff, &pkt->DeviceSetPower);
    break;
    case kLifxPacketTypeDeviceStatePower:
    status = lifxEncoder_EncodeDeviceStatePower(buff, &pkt->DeviceStatePower);
    break;
    case kLifxPacketTypeDeviceGetLabel:
    status = lifxEncoder_EncodeDeviceGetLabel(buff, &pkt->DeviceGetLabel);
    break;
    case kLifxPacketTypeDeviceSetLabel:
    status = lifxEncoder_EncodeDeviceSetLabel(buff, &pkt->DeviceSetLabel);
    break;
    case kLifxPacketTypeDeviceStateLabel:
    status = lifxEncoder_EncodeDeviceStateLabel(buff, &pkt->DeviceStateLabel);
    break;
    case kLifxPacketTypeDeviceGetVersion:
    status = lifxEncoder_EncodeDeviceGetVersion(buff, &pkt->DeviceGetVersion);
    break;
    case kLifxPacketTypeDeviceStateVersion:
    status = lifxEncoder_EncodeDeviceStateVersion(buff, &pkt->DeviceStateVersion);
    break;
    case kLifxPacketTypeDeviceGetInfo:
    status = lifxEncoder_EncodeDeviceGetInfo(buff, &pkt->DeviceGetInfo);
    break;
    case kLifxPacketTypeDeviceStateInfo:
    status = lifxEncoder_EncodeDeviceStateInfo(buff, &pkt->DeviceStateInfo);
    break;
    case kLifxPacketTypeDeviceAcknowledgement:
    status = lifxEncoder_EncodeDeviceAcknowledgement(buff, &pkt->DeviceAcknowledgement);
    break;
    case kLifxPacketTypeDeviceGetLocation:
    status = lifxEncoder_EncodeDeviceGetLocation(buff, &pkt->DeviceGetLocation);
    break;
    case kLifxPacketTypeDeviceSetLocation:
    status = lifxEncoder_EncodeDeviceSetLocation(buff, &pkt->DeviceSetLocation);
    break;
    case kLifxPacketTypeDeviceStateLocation:
    status = lifxEncoder_EncodeDeviceStateLocation(buff, &pkt->DeviceStateLocation);
    break;
    case kLifxPacketTypeDeviceGetGroup:
    status = lifxEncoder_EncodeDeviceGetGroup(buff, &pkt->DeviceGetGroup);
    break;
    case kLifxPacketTypeDeviceSetGroup:
    status = lifxEncoder_EncodeDeviceSetGroup(buff, &pkt->DeviceSetGroup);
    break;
    case kLifxPacketTypeDeviceStateGroup:
    status = lifxEncoder_EncodeDeviceStateGroup(buff, &pkt->DeviceStateGroup);
    break;
    case kLifxPacketTypeDeviceEchoRequest:
    status = lifxEncoder_EncodeDeviceEchoRequest(buff, &pkt->DeviceEchoRequest);
    break;
    case kLifxPacketTypeDeviceEchoResponse:
    status = lifxEncoder_EncodeDeviceEchoResponse(buff, &pkt->DeviceEchoResponse);
    break;
    case kLifxPacketTypeLightGet:
    status = lifxEncoder_EncodeLightGet(buff, &pkt->LightGet);
    break;
    case kLifxPacketTypeLightSetColor:
    status = lifxEncoder_EncodeLightSetColor(buff, &pkt->LightSetColor);
    break;
    case kLifxPacketTypeLightSetWaveform:
    status = lifxEncoder_EncodeLightSetWaveform(buff, &pkt->LightSetWaveform);
    break;
    case kLifxPacketTypeLightState:
    status = lifxEncoder_EncodeLightState(buff, &pkt->LightState);
    break;
    case kLifxPacketTypeLightGetPower:
    status = lifxEncoder_EncodeLightGetPower(buff, &pkt->LightGetPower);
    break;
    case kLifxPacketTypeLightSetPower:
    status = lifxEncoder_EncodeLightSetPower(buff, &pkt->LightSetPower);
    break;
    case kLifxPacketTypeLightStatePower:
    status = lifxEncoder_EncodeLightStatePower(buff, &pkt->LightStatePower);
    break;
    case kLifxPacketTypeLightSetWaveformOptional:
    status = lifxEncoder_EncodeLightSetWaveformOptional(buff, &pkt->LightSetWaveformOptional);
    break;
    case kLifxPacketTypeLightGetInfrared:
    status = lifxEncoder_EncodeLightGetInfrared(buff, &pkt->LightGetInfrared);
    break;
    case kLifxPacketTypeLightStateInfrared:
    status = lifxEncoder_EncodeLightStateInfrared(buff, &pkt->LightStateInfrared);
    break;
    case kLifxPacketTypeLightSetInfrared:
    status = lifxEncoder_EncodeLightSetInfrared(buff, &pkt->LightSetInfrared);
    break;
    case kLifxPacketTypeMultiZoneSetColorZones:
    status = lifxEncoder_EncodeMultiZoneSetColorZones(buff, &pkt->MultiZoneSetColorZones);
    break;
    case kLifxPacketTypeMultiZoneGetColorZones:
    status = lifxEncoder_EncodeMultiZoneGetColorZones(buff, &pkt->MultiZoneGetColorZones);
    break;
    case kLifxPacketTypeMultiZoneStateZone:
    status = lifxEncoder_EncodeMultiZoneStateZone(buff, &pkt->MultiZoneStateZone);
    break;
    case kLifxPacketTypeMultiZoneStateMultiZone:
    status = lifxEncoder_EncodeMultiZoneStateMultiZone(buff, &pkt->MultiZoneStateMultiZone);
    break;
    case kLifxPacketTypeMultiZoneGetEffect:
    status = lifxEncoder_EncodeMultiZoneGetEffect(buff, &pkt->MultiZoneGetEffect);
    break;
    case kLifxPacketTypeMultiZoneSetEffect:
    status = lifxEncoder_EncodeMultiZoneSetEffect(buff, &pkt->MultiZoneSetEffect);
    break;
    case kLifxPacketTypeMultiZoneStateEffect:
    status = lifxEncoder_EncodeMultiZoneStateEffect(buff, &pkt->MultiZoneStateEffect);
    break;
    case kLifxPacketTypeMultiZoneExtendedSetColorZones:
    status = lifxEncoder_EncodeMultiZoneExtendedSetColorZones(buff, &pkt->MultiZoneExtendedSetColorZones);
    break;
    case kLifxPacketTypeMultiZoneExtendedGetColorZones:
    status = lifxEncoder_EncodeMultiZoneExtendedGetColorZones(buff, &pkt->MultiZoneExtendedGetColorZones);
    break;
    case kLifxPacketTypeMultiZoneExtendedStateMultiZone:
    status = lifxEncoder_EncodeMultiZoneExtendedStateMultiZone(buff, &pkt->MultiZoneExtendedStateMultiZone);
    break;
    case kLifxPacketTypeTileGetDeviceChain:
    status = lifxEncoder_EncodeTileGetDeviceChain(buff, &pkt->TileGetDeviceChain);
    break;
    case kLifxPacketTypeTileStateDeviceChain:
    status = lifxEncoder_EncodeTileStateDeviceChain(buff, &pkt->TileStateDeviceChain);
    break;
    case kLifxPacketTypeTileSetUserPosition:
    status = lifxEncoder_EncodeTileSetUserPosition(buff, &pkt->TileSetUserPosition);
    break;
    case kLifxPacketTypeTileGet64:
    status = lifxEncoder_EncodeTileGet64(buff, &pkt->TileGet64);
    break;
    case kLifxPacketTypeTileState64:
    status = lifxEncoder_EncodeTileState64(buff, &pkt->TileState64);
    break;
    case kLifxPacketTypeTileSet64:
    status = lifxEncoder_EncodeTileSet64(buff, &pkt->TileSet64);
    break;
    case kLifxPacketTypeTileGetEffect:
    status = lifxEncoder_EncodeTileGetEffect(buff, &pkt->TileGetEffect);
    break;
    case kLifxPacketTypeTileSetEffect:
    status = lifxEncoder_EncodeTileSetEffect(buff, &pkt->TileSetEffect);
    break;
    case kLifxPacketTypeTileStateEffect:
    status = lifxEncoder_EncodeTileStateEffect(buff, &pkt->TileStateEffect);
    break;
  }
  return status;
}

int lifxEncoder_GetEncodedSize(lifxPacketType_t type)
{
  int encoded_size = 0;
  switch (type)
  {
    // {'pkt_type': 2, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetService:
    encoded_size = 0;
    break;
    // {'pkt_type': 3, 'size_bytes': 5, 'fields': [{'name': 'Service', 'type': '<DeviceService>', 'size_bytes': 1}, {'name': 'Port', 'type': 'uint32', 'size_bytes': 4}]}
    case kLifxPacketTypeDeviceStateService:
    encoded_size = 5;
    break;
    // {'pkt_type': 12, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetHostInfo:
    encoded_size = 0;
    break;
    // {'pkt_type': 13, 'size_bytes': 14, 'fields': [{'name': 'Signal', 'type': 'float32', 'size_bytes': 4}, {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}, {'type': 'reserved', 'size_bytes': 2}]}
    case kLifxPacketTypeDeviceStateHostInfo:
    encoded_size = 14;
    break;
    // {'pkt_type': 14, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetHostFirmware:
    encoded_size = 0;
    break;
    // {'pkt_type': 15, 'size_bytes': 20, 'fields': [{'name': 'Build', 'type': 'uint64', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 8}, {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}, {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}]}
    case kLifxPacketTypeDeviceStateHostFirmware:
    encoded_size = 20;
    break;
    // {'pkt_type': 16, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetWifiInfo:
    encoded_size = 0;
    break;
    // {'pkt_type': 17, 'size_bytes': 14, 'fields': [{'name': 'Signal', 'type': 'float32', 'size_bytes': 4}, {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}, {'type': 'reserved', 'size_bytes': 2}]}
    case kLifxPacketTypeDeviceStateWifiInfo:
    encoded_size = 14;
    break;
    // {'pkt_type': 18, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetWifiFirmware:
    encoded_size = 0;
    break;
    // {'pkt_type': 19, 'size_bytes': 20, 'fields': [{'name': 'Build', 'type': 'uint64', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 8}, {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}, {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}]}
    case kLifxPacketTypeDeviceStateWifiFirmware:
    encoded_size = 20;
    break;
    // {'pkt_type': 20, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetPower:
    encoded_size = 0;
    break;
    // {'pkt_type': 21, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
    case kLifxPacketTypeDeviceSetPower:
    encoded_size = 2;
    break;
    // {'pkt_type': 22, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
    case kLifxPacketTypeDeviceStatePower:
    encoded_size = 2;
    break;
    // {'pkt_type': 23, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetLabel:
    encoded_size = 0;
    break;
    // {'pkt_type': 24, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
    case kLifxPacketTypeDeviceSetLabel:
    encoded_size = 32;
    break;
    // {'pkt_type': 25, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
    case kLifxPacketTypeDeviceStateLabel:
    encoded_size = 32;
    break;
    // {'pkt_type': 32, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetVersion:
    encoded_size = 0;
    break;
    // {'pkt_type': 33, 'size_bytes': 12, 'fields': [{'name': 'Vendor', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Product', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Version', 'type': 'uint32', 'size_bytes': 4}]}
    case kLifxPacketTypeDeviceStateVersion:
    encoded_size = 12;
    break;
    // {'pkt_type': 34, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetInfo:
    encoded_size = 0;
    break;
    // {'pkt_type': 35, 'size_bytes': 24, 'fields': [{'name': 'Time', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Uptime', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Downtime', 'type': 'uint64', 'size_bytes': 8}]}
    case kLifxPacketTypeDeviceStateInfo:
    encoded_size = 24;
    break;
    // {'pkt_type': 45, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceAcknowledgement:
    encoded_size = 0;
    break;
    // {'pkt_type': 48, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetLocation:
    encoded_size = 0;
    break;
    // {'pkt_type': 49, 'size_bytes': 56, 'fields': [{'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
    case kLifxPacketTypeDeviceSetLocation:
    encoded_size = 56;
    break;
    // {'pkt_type': 50, 'size_bytes': 56, 'fields': [{'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
    case kLifxPacketTypeDeviceStateLocation:
    encoded_size = 56;
    break;
    // {'pkt_type': 51, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeDeviceGetGroup:
    encoded_size = 0;
    break;
    // {'pkt_type': 52, 'size_bytes': 56, 'fields': [{'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
    case kLifxPacketTypeDeviceSetGroup:
    encoded_size = 56;
    break;
    // {'pkt_type': 53, 'size_bytes': 56, 'fields': [{'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
    case kLifxPacketTypeDeviceStateGroup:
    encoded_size = 56;
    break;
    // {'pkt_type': 58, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
    case kLifxPacketTypeDeviceEchoRequest:
    encoded_size = 64;
    break;
    // {'pkt_type': 59, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
    case kLifxPacketTypeDeviceEchoResponse:
    encoded_size = 64;
    break;
    // {'pkt_type': 101, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeLightGet:
    encoded_size = 0;
    break;
    // {'pkt_type': 102, 'size_bytes': 13, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
    case kLifxPacketTypeLightSetColor:
    encoded_size = 13;
    break;
    // {'pkt_type': 119, 'size_bytes': 25, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}, {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}, {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}, {'name': 'SetHue', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetSaturation', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetBrightness', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetKelvin', 'type': 'bool', 'size_bytes': 1}]}
    case kLifxPacketTypeLightSetWaveformOptional:
    encoded_size = 25;
    break;
    // {'pkt_type': 103, 'size_bytes': 21, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}, {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}, {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}]}
    case kLifxPacketTypeLightSetWaveform:
    encoded_size = 21;
    break;
    // {'pkt_type': 116, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeLightGetPower:
    encoded_size = 0;
    break;
    // {'pkt_type': 117, 'size_bytes': 6, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
    case kLifxPacketTypeLightSetPower:
    encoded_size = 6;
    break;
    // {'pkt_type': 118, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
    case kLifxPacketTypeLightStatePower:
    encoded_size = 2;
    break;
    // {'pkt_type': 107, 'size_bytes': 52, 'fields': [{'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'Power', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'type': 'reserved', 'size_bytes': 8}]}
    case kLifxPacketTypeLightState:
    encoded_size = 52;
    break;
    // {'pkt_type': 120, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeLightGetInfrared:
    encoded_size = 0;
    break;
    // {'pkt_type': 121, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
    case kLifxPacketTypeLightStateInfrared:
    encoded_size = 2;
    break;
    // {'pkt_type': 122, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
    case kLifxPacketTypeLightSetInfrared:
    encoded_size = 2;
    break;
    // {'pkt_type': 701, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeTileGetDeviceChain:
    encoded_size = 0;
    break;
    // {'pkt_type': 702, 'size_bytes': 882, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'TileDevices', 'type': '[16]<TileStateDevice>', 'size_bytes': 880}, {'name': 'TileDevicesCount', 'type': 'uint8', 'size_bytes': 1}]}
    case kLifxPacketTypeTileStateDeviceChain:
    encoded_size = 882;
    break;
    // {'pkt_type': 703, 'size_bytes': 11, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'UserX', 'type': 'float32', 'size_bytes': 4}, {'name': 'UserY', 'type': 'float32', 'size_bytes': 4}]}
    case kLifxPacketTypeTileSetUserPosition:
    encoded_size = 11;
    break;
    // {'pkt_type': 707, 'size_bytes': 6, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}]}
    case kLifxPacketTypeTileGet64:
    encoded_size = 6;
    break;
    // {'pkt_type': 711, 'size_bytes': 517, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}, {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}]}
    case kLifxPacketTypeTileState64:
    encoded_size = 517;
    break;
    // {'pkt_type': 715, 'size_bytes': 522, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}]}
    case kLifxPacketTypeTileSet64:
    encoded_size = 522;
    break;
    // {'pkt_type': 718, 'size_bytes': 2, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}]}
    case kLifxPacketTypeTileGetEffect:
    encoded_size = 2;
    break;
    // {'pkt_type': 719, 'size_bytes': 188, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
    case kLifxPacketTypeTileSetEffect:
    encoded_size = 188;
    break;
    // {'pkt_type': 720, 'size_bytes': 187, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
    case kLifxPacketTypeTileStateEffect:
    encoded_size = 187;
    break;
    // {'pkt_type': 501, 'size_bytes': 15, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Apply', 'type': '<MultiZoneApplicationRequest>', 'size_bytes': 1}]}
    case kLifxPacketTypeMultiZoneSetColorZones:
    encoded_size = 15;
    break;
    // {'pkt_type': 502, 'size_bytes': 2, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}]}
    case kLifxPacketTypeMultiZoneGetColorZones:
    encoded_size = 2;
    break;
    // {'pkt_type': 503, 'size_bytes': 10, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}]}
    case kLifxPacketTypeMultiZoneStateZone:
    encoded_size = 10;
    break;
    // {'pkt_type': 506, 'size_bytes': 66, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[8]<LightHsbk>', 'size_bytes': 64}]}
    case kLifxPacketTypeMultiZoneStateMultiZone:
    encoded_size = 66;
    break;
    // {'pkt_type': 507, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeMultiZoneGetEffect:
    encoded_size = 0;
    break;
    // {'pkt_type': 508, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
    case kLifxPacketTypeMultiZoneSetEffect:
    encoded_size = 59;
    break;
    // {'pkt_type': 509, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
    case kLifxPacketTypeMultiZoneStateEffect:
    encoded_size = 59;
    break;
    // {'pkt_type': 510, 'size_bytes': 664, 'fields': [{'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Apply', 'type': '<MultiZoneExtendedApplicationRequest>', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}, {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}]}
    case kLifxPacketTypeMultiZoneExtendedSetColorZones:
    encoded_size = 664;
    break;
    // {'pkt_type': 511, 'size_bytes': 0, 'fields': []}
    case kLifxPacketTypeMultiZoneExtendedGetColorZones:
    encoded_size = 0;
    break;
    // {'pkt_type': 512, 'size_bytes': 661, 'fields': [{'name': 'Count', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}, {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}]}
    case kLifxPacketTypeMultiZoneExtendedStateMultiZone:
    encoded_size = 661;
    break;
  }
  return encoded_size;
}

lifxStatus_t lifxEncoder_EncodeDeviceGetService(lifxBuffer_t* buff, lifxDeviceGetService_t const* pkt)
{
  // {'pkt_type': 2, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceGetService(lifxBuffer_t* buff, lifxDeviceGetService_t* pkt)
{
  // {'pkt_type': 2, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceStateService(lifxBuffer_t* buff, lifxDeviceStateService_t const* pkt)
{
  // {'pkt_type': 3, 'size_bytes': 5, 'fields': [{'name': 'Service', 'type': '<DeviceService>', 'size_bytes': 1}, {'name': 'Port', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Service', 'type': '<DeviceService>', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Service);
  // {'name': 'Port', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Port);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceStateService(lifxBuffer_t* buff, lifxDeviceStateService_t* pkt)
{
  // {'pkt_type': 3, 'size_bytes': 5, 'fields': [{'name': 'Service', 'type': '<DeviceService>', 'size_bytes': 1}, {'name': 'Port', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Service', 'type': '<DeviceService>', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Service);
  // {'name': 'Port', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Port);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceGetHostInfo(lifxBuffer_t* buff, lifxDeviceGetHostInfo_t const* pkt)
{
  // {'pkt_type': 12, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceGetHostInfo(lifxBuffer_t* buff, lifxDeviceGetHostInfo_t* pkt)
{
  // {'pkt_type': 12, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceStateHostInfo(lifxBuffer_t* buff, lifxDeviceStateHostInfo_t const* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceStateHostInfo(lifxBuffer_t* buff, lifxDeviceStateHostInfo_t* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceGetHostFirmware(lifxBuffer_t* buff, lifxDeviceGetHostFirmware_t const* pkt)
{
  // {'pkt_type': 14, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceGetHostFirmware(lifxBuffer_t* buff, lifxDeviceGetHostFirmware_t* pkt)
{
  // {'pkt_type': 14, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceStateHostFirmware(lifxBuffer_t* buff, lifxDeviceStateHostFirmware_t const* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceStateHostFirmware(lifxBuffer_t* buff, lifxDeviceStateHostFirmware_t* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceGetWifiInfo(lifxBuffer_t* buff, lifxDeviceGetWifiInfo_t const* pkt)
{
  // {'pkt_type': 16, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceGetWifiInfo(lifxBuffer_t* buff, lifxDeviceGetWifiInfo_t* pkt)
{
  // {'pkt_type': 16, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceStateWifiInfo(lifxBuffer_t* buff, lifxDeviceStateWifiInfo_t const* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceStateWifiInfo(lifxBuffer_t* buff, lifxDeviceStateWifiInfo_t* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceGetWifiFirmware(lifxBuffer_t* buff, lifxDeviceGetWifiFirmware_t const* pkt)
{
  // {'pkt_type': 18, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceGetWifiFirmware(lifxBuffer_t* buff, lifxDeviceGetWifiFirmware_t* pkt)
{
  // {'pkt_type': 18, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceStateWifiFirmware(lifxBuffer_t* buff, lifxDeviceStateWifiFirmware_t const* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceStateWifiFirmware(lifxBuffer_t* buff, lifxDeviceStateWifiFirmware_t* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceGetPower(lifxBuffer_t* buff, lifxDeviceGetPower_t const* pkt)
{
  // {'pkt_type': 20, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceGetPower(lifxBuffer_t* buff, lifxDeviceGetPower_t* pkt)
{
  // {'pkt_type': 20, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceSetPower(lifxBuffer_t* buff, lifxDeviceSetPower_t const* pkt)
{
  // {'pkt_type': 21, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceSetPower(lifxBuffer_t* buff, lifxDeviceSetPower_t* pkt)
{
  // {'pkt_type': 21, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceStatePower(lifxBuffer_t* buff, lifxDeviceStatePower_t const* pkt)
{
  // {'pkt_type': 22, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceStatePower(lifxBuffer_t* buff, lifxDeviceStatePower_t* pkt)
{
  // {'pkt_type': 22, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceGetLabel(lifxBuffer_t* buff, lifxDeviceGetLabel_t const* pkt)
{
  // {'pkt_type': 23, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceGetLabel(lifxBuffer_t* buff, lifxDeviceGetLabel_t* pkt)
{
  // {'pkt_type': 23, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceSetLabel(lifxBuffer_t* buff, lifxDeviceSetLabel_t const* pkt)
{
  // {'pkt_type': 24, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceSetLabel(lifxBuffer_t* buff, lifxDeviceSetLabel_t* pkt)
{
  // {'pkt_type': 24, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Read(buff, pkt->Label, 32);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceStateLabel(lifxBuffer_t* buff, lifxDeviceStateLabel_t const* pkt)
{
  // {'pkt_type': 25, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceStateLabel(lifxBuffer_t* buff, lifxDeviceStateLabel_t* pkt)
{
  // {'pkt_type': 25, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Read(buff, pkt->Label, 32);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceGetVersion(lifxBuffer_t* buff, lifxDeviceGetVersion_t const* pkt)
{
  // {'pkt_type': 32, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceGetVersion(lifxBuffer_t* buff, lifxDeviceGetVersion_t* pkt)
{
  // {'pkt_type': 32, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceStateVersion(lifxBuffer_t* buff, lifxDeviceStateVersion_t const* pkt)
{
  // {'pkt_type': 33, 'size_bytes': 12, 'fields': [{'name': 'Vendor', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Product', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Version', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Vendor', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Vendor);
  // {'name': 'Product', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Product);
  // {'name': 'Version', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Version);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceStateVersion(lifxBuffer_t* buff, lifxDeviceStateVersion_t* pkt)
{
  // {'pkt_type': 33, 'size_bytes': 12, 'fields': [{'name': 'Vendor', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Product', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Version', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Vendor', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Vendor);
  // {'name': 'Product', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Product);
  // {'name': 'Version', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Version);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceGetInfo(lifxBuffer_t* buff, lifxDeviceGetInfo_t const* pkt)
{
  // {'pkt_type': 34, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceGetInfo(lifxBuffer_t* buff, lifxDeviceGetInfo_t* pkt)
{
  // {'pkt_type': 34, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceStateInfo(lifxBuffer_t* buff, lifxDeviceStateInfo_t const* pkt)
{
  // {'pkt_type': 35, 'size_bytes': 24, 'fields': [{'name': 'Time', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Uptime', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Downtime', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Time', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->Time);
  // {'name': 'Uptime', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->Uptime);
  // {'name': 'Downtime', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->Downtime);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceStateInfo(lifxBuffer_t* buff, lifxDeviceStateInfo_t* pkt)
{
  // {'pkt_type': 35, 'size_bytes': 24, 'fields': [{'name': 'Time', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Uptime', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Downtime', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Time', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->Time);
  // {'name': 'Uptime', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->Uptime);
  // {'name': 'Downtime', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->Downtime);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceAcknowledgement(lifxBuffer_t* buff, lifxDeviceAcknowledgement_t const* pkt)
{
  // {'pkt_type': 45, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceAcknowledgement(lifxBuffer_t* buff, lifxDeviceAcknowledgement_t* pkt)
{
  // {'pkt_type': 45, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceGetLocation(lifxBuffer_t* buff, lifxDeviceGetLocation_t const* pkt)
{
  // {'pkt_type': 48, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceGetLocation(lifxBuffer_t* buff, lifxDeviceGetLocation_t* pkt)
{
  // {'pkt_type': 48, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceSetLocation(lifxBuffer_t* buff, lifxDeviceSetLocation_t const* pkt)
{
  // {'pkt_type': 49, 'size_bytes': 56, 'fields': [{'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Write(buff, pkt->Location, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceSetLocation(lifxBuffer_t* buff, lifxDeviceSetLocation_t* pkt)
{
  // {'pkt_type': 49, 'size_bytes': 56, 'fields': [{'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Read(buff, pkt->Location, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Read(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->UpdatedAt);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceStateLocation(lifxBuffer_t* buff, lifxDeviceStateLocation_t const* pkt)
{
  // {'pkt_type': 50, 'size_bytes': 56, 'fields': [{'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Write(buff, pkt->Location, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceStateLocation(lifxBuffer_t* buff, lifxDeviceStateLocation_t* pkt)
{
  // {'pkt_type': 50, 'size_bytes': 56, 'fields': [{'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Read(buff, pkt->Location, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Read(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->UpdatedAt);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceGetGroup(lifxBuffer_t* buff, lifxDeviceGetGroup_t const* pkt)
{
  // {'pkt_type': 51, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceGetGroup(lifxBuffer_t* buff, lifxDeviceGetGroup_t* pkt)
{
  // {'pkt_type': 51, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceSetGroup(lifxBuffer_t* buff, lifxDeviceSetGroup_t const* pkt)
{
  // {'pkt_type': 52, 'size_bytes': 56, 'fields': [{'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Write(buff, pkt->Group, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceSetGroup(lifxBuffer_t* buff, lifxDeviceSetGroup_t* pkt)
{
  // {'pkt_type': 52, 'size_bytes': 56, 'fields': [{'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Read(buff, pkt->Group, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Read(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->UpdatedAt);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceStateGroup(lifxBuffer_t* buff, lifxDeviceStateGroup_t const* pkt)
{
  // {'pkt_type': 53, 'size_bytes': 56, 'fields': [{'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Write(buff, pkt->Group, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceStateGroup(lifxBuffer_t* buff, lifxDeviceStateGroup_t* pkt)
{
  // {'pkt_type': 53, 'size_bytes': 56, 'fields': [{'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  // {'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Read(buff, pkt->Group, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Read(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_ReadUInt64(buff, &pkt->UpdatedAt);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceEchoRequest(lifxBuffer_t* buff, lifxDeviceEchoRequest_t const* pkt)
{
  // {'pkt_type': 58, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
  // {'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}
  lifxBuffer_Write(buff, pkt->Payload, 64);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceEchoRequest(lifxBuffer_t* buff, lifxDeviceEchoRequest_t* pkt)
{
  // {'pkt_type': 58, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
  // {'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}
  lifxBuffer_Read(buff, pkt->Payload, 64);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeDeviceEchoResponse(lifxBuffer_t* buff, lifxDeviceEchoResponse_t const* pkt)
{
  // {'pkt_type': 59, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
  // {'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}
  lifxBuffer_Write(buff, pkt->Payload, 64);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeDeviceEchoResponse(lifxBuffer_t* buff, lifxDeviceEchoResponse_t* pkt)
{
  // {'pkt_type': 59, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
  // {'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}
  lifxBuffer_Read(buff, pkt->Payload, 64);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeLightGet(lifxBuffer_t* buff, lifxLightGet_t const* pkt)
{
  // {'pkt_type': 101, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeLightGet(lifxBuffer_t* buff, lifxLightGet_t* pkt)
{
  // {'pkt_type': 101, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeLightSetColor(lifxBuffer_t* buff, lifxLightSetColor_t const* pkt)
{
  // {'pkt_type': 102, 'size_bytes': 13, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Color);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeLightSetColor(lifxBuffer_t* buff, lifxLightSetColor_t* pkt)
{
  // {'pkt_type': 102, 'size_bytes': 13, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Color);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeLightSetWaveformOptional(lifxBuffer_t* buff, lifxLightSetWaveformOptional_t const* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeLightSetWaveformOptional(lifxBuffer_t* buff, lifxLightSetWaveformOptional_t* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeLightSetWaveform(lifxBuffer_t* buff, lifxLightSetWaveform_t const* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeLightSetWaveform(lifxBuffer_t* buff, lifxLightSetWaveform_t* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeLightGetPower(lifxBuffer_t* buff, lifxLightGetPower_t const* pkt)
{
  // {'pkt_type': 116, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeLightGetPower(lifxBuffer_t* buff, lifxLightGetPower_t* pkt)
{
  // {'pkt_type': 116, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeLightSetPower(lifxBuffer_t* buff, lifxLightSetPower_t const* pkt)
{
  // {'pkt_type': 117, 'size_bytes': 6, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeLightSetPower(lifxBuffer_t* buff, lifxLightSetPower_t* pkt)
{
  // {'pkt_type': 117, 'size_bytes': 6, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeLightStatePower(lifxBuffer_t* buff, lifxLightStatePower_t const* pkt)
{
  // {'pkt_type': 118, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeLightStatePower(lifxBuffer_t* buff, lifxLightStatePower_t* pkt)
{
  // {'pkt_type': 118, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeLightState(lifxBuffer_t* buff, lifxLightState_t const* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeLightState(lifxBuffer_t* buff, lifxLightState_t* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeLightGetInfrared(lifxBuffer_t* buff, lifxLightGetInfrared_t const* pkt)
{
  // {'pkt_type': 120, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeLightGetInfrared(lifxBuffer_t* buff, lifxLightGetInfrared_t* pkt)
{
  // {'pkt_type': 120, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeLightStateInfrared(lifxBuffer_t* buff, lifxLightStateInfrared_t const* pkt)
{
  // {'pkt_type': 121, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Brightness);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeLightStateInfrared(lifxBuffer_t* buff, lifxLightStateInfrared_t* pkt)
{
  // {'pkt_type': 121, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Brightness);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeLightSetInfrared(lifxBuffer_t* buff, lifxLightSetInfrared_t const* pkt)
{
  // {'pkt_type': 122, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Brightness);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeLightSetInfrared(lifxBuffer_t* buff, lifxLightSetInfrared_t* pkt)
{
  // {'pkt_type': 122, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Brightness);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeTileGetDeviceChain(lifxBuffer_t* buff, lifxTileGetDeviceChain_t const* pkt)
{
  // {'pkt_type': 701, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeTileGetDeviceChain(lifxBuffer_t* buff, lifxTileGetDeviceChain_t* pkt)
{
  // {'pkt_type': 701, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeTileStateDeviceChain(lifxBuffer_t* buff, lifxTileStateDeviceChain_t const* pkt)
{
  // {'pkt_type': 702, 'size_bytes': 882, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'TileDevices', 'type': '[16]<TileStateDevice>', 'size_bytes': 880}, {'name': 'TileDevicesCount', 'type': 'uint8', 'size_bytes': 1}]}
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->StartIndex);
  // {'name': 'TileDevices', 'type': '[16]<TileStateDevice>', 'size_bytes': 880}
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[0]);
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[1]);
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[2]);
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[3]);
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[4]);
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[5]);
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[6]);
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[7]);
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[8]);
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[9]);
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[10]);
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[11]);
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[12]);
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[13]);
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[14]);
  lifxEncoder_EncodeTileStateDevice(buff, &pkt->TileDevices[15]);
  // {'name': 'TileDevicesCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->TileDevicesCount);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeTileStateDeviceChain(lifxBuffer_t* buff, lifxTileStateDeviceChain_t* pkt)
{
  // {'pkt_type': 702, 'size_bytes': 882, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'TileDevices', 'type': '[16]<TileStateDevice>', 'size_bytes': 880}, {'name': 'TileDevicesCount', 'type': 'uint8', 'size_bytes': 1}]}
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->StartIndex);
  // {'name': 'TileDevices', 'type': '[16]<TileStateDevice>', 'size_bytes': 880}
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[0]);
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[1]);
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[2]);
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[3]);
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[4]);
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[5]);
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[6]);
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[7]);
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[8]);
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[9]);
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[10]);
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[11]);
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[12]);
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[13]);
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[14]);
  lifxDecoder_DecodeTileStateDevice(buff, &pkt->TileDevices[15]);
  // {'name': 'TileDevicesCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->TileDevicesCount);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeTileSetUserPosition(lifxBuffer_t* buff, lifxTileSetUserPosition_t const* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeTileSetUserPosition(lifxBuffer_t* buff, lifxTileSetUserPosition_t* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeTileGet64(lifxBuffer_t* buff, lifxTileGet64_t const* pkt)
{
  // {'pkt_type': 707, 'size_bytes': 6, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}]}
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->TileIndex);
  // {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Length);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxEncoder_EncodeTileBufferRect(buff, &pkt->Rect);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeTileGet64(lifxBuffer_t* buff, lifxTileGet64_t* pkt)
{
  // {'pkt_type': 707, 'size_bytes': 6, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}]}
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->TileIndex);
  // {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Length);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxDecoder_DecodeTileBufferRect(buff, &pkt->Rect);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeTileState64(lifxBuffer_t* buff, lifxTileState64_t const* pkt)
{
  // {'pkt_type': 711, 'size_bytes': 517, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}, {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}]}
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->TileIndex);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxEncoder_EncodeTileBufferRect(buff, &pkt->Rect);
  // {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[0]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[1]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[2]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[3]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[4]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[5]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[6]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[7]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[8]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[9]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[10]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[11]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[12]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[13]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[14]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[15]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[16]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[17]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[18]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[19]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[20]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[21]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[22]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[23]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[24]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[25]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[26]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[27]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[28]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[29]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[30]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[31]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[32]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[33]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[34]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[35]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[36]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[37]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[38]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[39]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[40]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[41]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[42]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[43]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[44]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[45]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[46]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[47]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[48]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[49]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[50]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[51]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[52]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[53]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[54]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[55]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[56]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[57]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[58]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[59]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[60]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[61]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[62]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[63]);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeTileState64(lifxBuffer_t* buff, lifxTileState64_t* pkt)
{
  // {'pkt_type': 711, 'size_bytes': 517, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}, {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}]}
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->TileIndex);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxDecoder_DecodeTileBufferRect(buff, &pkt->Rect);
  // {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[0]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[1]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[2]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[3]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[4]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[5]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[6]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[7]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[8]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[9]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[10]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[11]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[12]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[13]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[14]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[15]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[16]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[17]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[18]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[19]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[20]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[21]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[22]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[23]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[24]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[25]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[26]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[27]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[28]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[29]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[30]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[31]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[32]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[33]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[34]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[35]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[36]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[37]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[38]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[39]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[40]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[41]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[42]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[43]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[44]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[45]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[46]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[47]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[48]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[49]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[50]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[51]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[52]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[53]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[54]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[55]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[56]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[57]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[58]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[59]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[60]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[61]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[62]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[63]);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeTileSet64(lifxBuffer_t* buff, lifxTileSet64_t const* pkt)
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
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[0]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[1]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[2]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[3]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[4]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[5]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[6]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[7]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[8]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[9]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[10]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[11]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[12]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[13]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[14]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[15]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[16]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[17]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[18]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[19]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[20]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[21]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[22]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[23]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[24]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[25]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[26]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[27]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[28]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[29]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[30]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[31]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[32]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[33]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[34]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[35]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[36]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[37]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[38]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[39]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[40]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[41]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[42]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[43]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[44]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[45]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[46]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[47]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[48]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[49]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[50]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[51]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[52]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[53]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[54]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[55]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[56]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[57]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[58]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[59]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[60]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[61]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[62]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[63]);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeTileSet64(lifxBuffer_t* buff, lifxTileSet64_t* pkt)
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
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[0]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[1]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[2]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[3]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[4]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[5]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[6]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[7]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[8]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[9]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[10]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[11]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[12]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[13]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[14]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[15]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[16]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[17]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[18]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[19]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[20]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[21]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[22]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[23]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[24]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[25]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[26]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[27]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[28]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[29]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[30]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[31]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[32]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[33]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[34]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[35]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[36]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[37]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[38]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[39]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[40]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[41]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[42]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[43]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[44]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[45]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[46]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[47]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[48]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[49]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[50]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[51]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[52]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[53]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[54]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[55]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[56]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[57]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[58]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[59]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[60]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[61]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[62]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[63]);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeTileGetEffect(lifxBuffer_t* buff, lifxTileGetEffect_t const* pkt)
{
  // {'pkt_type': 718, 'size_bytes': 2, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}]}
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved0);
  // {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved1);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeTileGetEffect(lifxBuffer_t* buff, lifxTileGetEffect_t* pkt)
{
  // {'pkt_type': 718, 'size_bytes': 2, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}]}
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved0);
  // {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved1);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeTileSetEffect(lifxBuffer_t* buff, lifxTileSetEffect_t const* pkt)
{
  // {'pkt_type': 719, 'size_bytes': 188, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved0);
  // {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved1);
  // {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}
  lifxEncoder_EncodeTileEffectSettings(buff, &pkt->Settings);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeTileSetEffect(lifxBuffer_t* buff, lifxTileSetEffect_t* pkt)
{
  // {'pkt_type': 719, 'size_bytes': 188, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved0);
  // {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved1);
  // {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}
  lifxDecoder_DecodeTileEffectSettings(buff, &pkt->Settings);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeTileStateEffect(lifxBuffer_t* buff, lifxTileStateEffect_t const* pkt)
{
  // {'pkt_type': 720, 'size_bytes': 187, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved0);
  // {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}
  lifxEncoder_EncodeTileEffectSettings(buff, &pkt->Settings);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeTileStateEffect(lifxBuffer_t* buff, lifxTileStateEffect_t* pkt)
{
  // {'pkt_type': 720, 'size_bytes': 187, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved0);
  // {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}
  lifxDecoder_DecodeTileEffectSettings(buff, &pkt->Settings);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeMultiZoneSetColorZones(lifxBuffer_t* buff, lifxMultiZoneSetColorZones_t const* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeMultiZoneSetColorZones(lifxBuffer_t* buff, lifxMultiZoneSetColorZones_t* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeMultiZoneGetColorZones(lifxBuffer_t* buff, lifxMultiZoneGetColorZones_t const* pkt)
{
  // {'pkt_type': 502, 'size_bytes': 2, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}]}
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->StartIndex);
  // {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->EndIndex);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeMultiZoneGetColorZones(lifxBuffer_t* buff, lifxMultiZoneGetColorZones_t* pkt)
{
  // {'pkt_type': 502, 'size_bytes': 2, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}]}
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->StartIndex);
  // {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->EndIndex);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeMultiZoneStateZone(lifxBuffer_t* buff, lifxMultiZoneStateZone_t const* pkt)
{
  // {'pkt_type': 503, 'size_bytes': 10, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}]}
  // {'name': 'Count', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Count);
  // {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Index);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Color);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeMultiZoneStateZone(lifxBuffer_t* buff, lifxMultiZoneStateZone_t* pkt)
{
  // {'pkt_type': 503, 'size_bytes': 10, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}]}
  // {'name': 'Count', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Count);
  // {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Index);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Color);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeMultiZoneStateMultiZone(lifxBuffer_t* buff, lifxMultiZoneStateMultiZone_t const* pkt)
{
  // {'pkt_type': 506, 'size_bytes': 66, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[8]<LightHsbk>', 'size_bytes': 64}]}
  // {'name': 'Count', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Count);
  // {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Index);
  // {'name': 'Colors', 'type': '[8]<LightHsbk>', 'size_bytes': 64}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[0]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[1]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[2]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[3]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[4]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[5]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[6]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[7]);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeMultiZoneStateMultiZone(lifxBuffer_t* buff, lifxMultiZoneStateMultiZone_t* pkt)
{
  // {'pkt_type': 506, 'size_bytes': 66, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[8]<LightHsbk>', 'size_bytes': 64}]}
  // {'name': 'Count', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Count);
  // {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Index);
  // {'name': 'Colors', 'type': '[8]<LightHsbk>', 'size_bytes': 64}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[0]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[1]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[2]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[3]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[4]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[5]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[6]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[7]);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeMultiZoneGetEffect(lifxBuffer_t* buff, lifxMultiZoneGetEffect_t const* pkt)
{
  // {'pkt_type': 507, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeMultiZoneGetEffect(lifxBuffer_t* buff, lifxMultiZoneGetEffect_t* pkt)
{
  // {'pkt_type': 507, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeMultiZoneSetEffect(lifxBuffer_t* buff, lifxMultiZoneSetEffect_t const* pkt)
{
  // {'pkt_type': 508, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
  // {'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}
  lifxEncoder_EncodeMultiZoneEffectSettings(buff, &pkt->Settings);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeMultiZoneSetEffect(lifxBuffer_t* buff, lifxMultiZoneSetEffect_t* pkt)
{
  // {'pkt_type': 508, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
  // {'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}
  lifxDecoder_DecodeMultiZoneEffectSettings(buff, &pkt->Settings);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeMultiZoneStateEffect(lifxBuffer_t* buff, lifxMultiZoneStateEffect_t const* pkt)
{
  // {'pkt_type': 509, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
  // {'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}
  lifxEncoder_EncodeMultiZoneEffectSettings(buff, &pkt->Settings);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeMultiZoneStateEffect(lifxBuffer_t* buff, lifxMultiZoneStateEffect_t* pkt)
{
  // {'pkt_type': 509, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
  // {'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}
  lifxDecoder_DecodeMultiZoneEffectSettings(buff, &pkt->Settings);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeMultiZoneExtendedSetColorZones(lifxBuffer_t* buff, lifxMultiZoneExtendedSetColorZones_t const* pkt)
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
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[0]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[1]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[2]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[3]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[4]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[5]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[6]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[7]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[8]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[9]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[10]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[11]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[12]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[13]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[14]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[15]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[16]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[17]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[18]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[19]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[20]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[21]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[22]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[23]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[24]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[25]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[26]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[27]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[28]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[29]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[30]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[31]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[32]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[33]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[34]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[35]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[36]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[37]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[38]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[39]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[40]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[41]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[42]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[43]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[44]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[45]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[46]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[47]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[48]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[49]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[50]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[51]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[52]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[53]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[54]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[55]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[56]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[57]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[58]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[59]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[60]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[61]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[62]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[63]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[64]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[65]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[66]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[67]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[68]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[69]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[70]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[71]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[72]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[73]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[74]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[75]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[76]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[77]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[78]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[79]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[80]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[81]);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeMultiZoneExtendedSetColorZones(lifxBuffer_t* buff, lifxMultiZoneExtendedSetColorZones_t* pkt)
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
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[0]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[1]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[2]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[3]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[4]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[5]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[6]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[7]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[8]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[9]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[10]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[11]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[12]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[13]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[14]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[15]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[16]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[17]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[18]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[19]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[20]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[21]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[22]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[23]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[24]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[25]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[26]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[27]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[28]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[29]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[30]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[31]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[32]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[33]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[34]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[35]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[36]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[37]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[38]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[39]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[40]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[41]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[42]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[43]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[44]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[45]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[46]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[47]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[48]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[49]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[50]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[51]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[52]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[53]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[54]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[55]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[56]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[57]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[58]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[59]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[60]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[61]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[62]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[63]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[64]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[65]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[66]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[67]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[68]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[69]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[70]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[71]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[72]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[73]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[74]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[75]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[76]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[77]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[78]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[79]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[80]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[81]);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeMultiZoneExtendedGetColorZones(lifxBuffer_t* buff, lifxMultiZoneExtendedGetColorZones_t const* pkt)
{
  // {'pkt_type': 511, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeMultiZoneExtendedGetColorZones(lifxBuffer_t* buff, lifxMultiZoneExtendedGetColorZones_t* pkt)
{
  // {'pkt_type': 511, 'size_bytes': 0, 'fields': []}
  (void) buff;
  (void) pkt;
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeMultiZoneExtendedStateMultiZone(lifxBuffer_t* buff, lifxMultiZoneExtendedStateMultiZone_t const* pkt)
{
  // {'pkt_type': 512, 'size_bytes': 661, 'fields': [{'name': 'Count', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}, {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}]}
  // {'name': 'Count', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Count);
  // {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Index);
  // {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->ColorsCount);
  // {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[0]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[1]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[2]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[3]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[4]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[5]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[6]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[7]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[8]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[9]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[10]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[11]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[12]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[13]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[14]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[15]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[16]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[17]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[18]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[19]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[20]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[21]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[22]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[23]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[24]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[25]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[26]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[27]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[28]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[29]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[30]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[31]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[32]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[33]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[34]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[35]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[36]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[37]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[38]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[39]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[40]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[41]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[42]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[43]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[44]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[45]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[46]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[47]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[48]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[49]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[50]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[51]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[52]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[53]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[54]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[55]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[56]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[57]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[58]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[59]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[60]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[61]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[62]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[63]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[64]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[65]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[66]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[67]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[68]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[69]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[70]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[71]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[72]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[73]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[74]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[75]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[76]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[77]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[78]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[79]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[80]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Colors[81]);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeMultiZoneExtendedStateMultiZone(lifxBuffer_t* buff, lifxMultiZoneExtendedStateMultiZone_t* pkt)
{
  // {'pkt_type': 512, 'size_bytes': 661, 'fields': [{'name': 'Count', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}, {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}]}
  // {'name': 'Count', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Count);
  // {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Index);
  // {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->ColorsCount);
  // {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[0]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[1]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[2]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[3]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[4]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[5]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[6]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[7]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[8]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[9]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[10]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[11]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[12]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[13]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[14]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[15]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[16]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[17]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[18]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[19]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[20]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[21]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[22]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[23]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[24]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[25]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[26]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[27]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[28]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[29]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[30]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[31]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[32]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[33]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[34]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[35]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[36]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[37]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[38]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[39]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[40]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[41]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[42]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[43]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[44]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[45]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[46]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[47]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[48]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[49]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[50]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[51]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[52]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[53]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[54]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[55]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[56]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[57]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[58]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[59]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[60]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[61]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[62]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[63]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[64]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[65]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[66]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[67]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[68]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[69]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[70]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[71]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[72]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[73]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[74]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[75]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[76]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[77]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[78]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[79]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[80]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Colors[81]);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeLightHsbk(lifxBuffer_t* buff, lifxLightHsbk_t const* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeLightHsbk(lifxBuffer_t* buff, lifxLightHsbk_t* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeMultiZoneEffectParameter(lifxBuffer_t* buff, lifxMultiZoneEffectParameter_t const* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeMultiZoneEffectParameter(lifxBuffer_t* buff, lifxMultiZoneEffectParameter_t* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeMultiZoneEffectSettings(lifxBuffer_t* buff, lifxMultiZoneEffectSettings_t const* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeMultiZoneEffectSettings(lifxBuffer_t* buff, lifxMultiZoneEffectSettings_t* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeTileAccelMeas(lifxBuffer_t* buff, lifxTileAccelMeas_t const* pkt)
{
  // {'size_bytes': 6, 'fields': [{'name': 'X', 'type': 'int16', 'size_bytes': 2}, {'name': 'Y', 'type': 'int16', 'size_bytes': 2}, {'name': 'Z', 'type': 'int16', 'size_bytes': 2}]}
  // {'name': 'X', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_WriteInt16(buff, pkt->X);
  // {'name': 'Y', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_WriteInt16(buff, pkt->Y);
  // {'name': 'Z', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_WriteInt16(buff, pkt->Z);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeTileAccelMeas(lifxBuffer_t* buff, lifxTileAccelMeas_t* pkt)
{
  // {'size_bytes': 6, 'fields': [{'name': 'X', 'type': 'int16', 'size_bytes': 2}, {'name': 'Y', 'type': 'int16', 'size_bytes': 2}, {'name': 'Z', 'type': 'int16', 'size_bytes': 2}]}
  // {'name': 'X', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_ReadInt16(buff, &pkt->X);
  // {'name': 'Y', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_ReadInt16(buff, &pkt->Y);
  // {'name': 'Z', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_ReadInt16(buff, &pkt->Z);
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeTileStateDevice(lifxBuffer_t* buff, lifxTileStateDevice_t const* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeTileStateDevice(lifxBuffer_t* buff, lifxTileStateDevice_t* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeTileBufferRect(lifxBuffer_t* buff, lifxTileBufferRect_t const* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeTileBufferRect(lifxBuffer_t* buff, lifxTileBufferRect_t* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeTileEffectParameter(lifxBuffer_t* buff, lifxTileEffectParameter_t const* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeTileEffectParameter(lifxBuffer_t* buff, lifxTileEffectParameter_t* pkt)
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
  return kLifxStatusOk;
}

lifxStatus_t lifxEncoder_EncodeTileEffectSettings(lifxBuffer_t* buff, lifxTileEffectSettings_t const* pkt)
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
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[0]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[1]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[2]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[3]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[4]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[5]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[6]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[7]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[8]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[9]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[10]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[11]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[12]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[13]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[14]);
  lifxEncoder_EncodeLightHsbk(buff, &pkt->Palette[15]);
  return kLifxStatusOk;
}

lifxStatus_t lifxDecoder_DecodeTileEffectSettings(lifxBuffer_t* buff, lifxTileEffectSettings_t* pkt)
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
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[0]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[1]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[2]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[3]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[4]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[5]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[6]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[7]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[8]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[9]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[10]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[11]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[12]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[13]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[14]);
  lifxDecoder_DecodeLightHsbk(buff, &pkt->Palette[15]);
  return kLifxStatusOk;
}

