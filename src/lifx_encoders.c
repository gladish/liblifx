//
// DO NOT EDIT - AUTO-GENERATE:2020-02-10 21:58:35.228111
//
#include "lifx.h"
#include "lifx_encoders.h"

int lifxDecoder_DecodePacket(lifxPacketType_t type, lifxPacket_t* pkt, lifxBuffer_t* buff)
{
  int ret = 0;
  switch (type)
  {
    case kLifxPacketTypeDeviceGetService:
    ret = lifxDecoder_DecodeDeviceGetService(&pkt->DeviceGetService, buff);
    break;
    case kLifxPacketTypeDeviceStateService:
    ret = lifxDecoder_DecodeDeviceStateService(&pkt->DeviceStateService, buff);
    break;
    case kLifxPacketTypeDeviceGetHostInfo:
    ret = lifxDecoder_DecodeDeviceGetHostInfo(&pkt->DeviceGetHostInfo, buff);
    break;
    case kLifxPacketTypeDeviceStateHostInfo:
    ret = lifxDecoder_DecodeDeviceStateHostInfo(&pkt->DeviceStateHostInfo, buff);
    break;
    case kLifxPacketTypeDeviceGetHostFirmware:
    ret = lifxDecoder_DecodeDeviceGetHostFirmware(&pkt->DeviceGetHostFirmware, buff);
    break;
    case kLifxPacketTypeDeviceStateHostFirmware:
    ret = lifxDecoder_DecodeDeviceStateHostFirmware(&pkt->DeviceStateHostFirmware, buff);
    break;
    case kLifxPacketTypeDeviceGetWifiInfo:
    ret = lifxDecoder_DecodeDeviceGetWifiInfo(&pkt->DeviceGetWifiInfo, buff);
    break;
    case kLifxPacketTypeDeviceStateWifiInfo:
    ret = lifxDecoder_DecodeDeviceStateWifiInfo(&pkt->DeviceStateWifiInfo, buff);
    break;
    case kLifxPacketTypeDeviceGetWifiFirmware:
    ret = lifxDecoder_DecodeDeviceGetWifiFirmware(&pkt->DeviceGetWifiFirmware, buff);
    break;
    case kLifxPacketTypeDeviceStateWifiFirmware:
    ret = lifxDecoder_DecodeDeviceStateWifiFirmware(&pkt->DeviceStateWifiFirmware, buff);
    break;
    case kLifxPacketTypeDeviceGetPower:
    ret = lifxDecoder_DecodeDeviceGetPower(&pkt->DeviceGetPower, buff);
    break;
    case kLifxPacketTypeDeviceSetPower:
    ret = lifxDecoder_DecodeDeviceSetPower(&pkt->DeviceSetPower, buff);
    break;
    case kLifxPacketTypeDeviceStatePower:
    ret = lifxDecoder_DecodeDeviceStatePower(&pkt->DeviceStatePower, buff);
    break;
    case kLifxPacketTypeDeviceGetLabel:
    ret = lifxDecoder_DecodeDeviceGetLabel(&pkt->DeviceGetLabel, buff);
    break;
    case kLifxPacketTypeDeviceSetLabel:
    ret = lifxDecoder_DecodeDeviceSetLabel(&pkt->DeviceSetLabel, buff);
    break;
    case kLifxPacketTypeDeviceStateLabel:
    ret = lifxDecoder_DecodeDeviceStateLabel(&pkt->DeviceStateLabel, buff);
    break;
    case kLifxPacketTypeDeviceGetVersion:
    ret = lifxDecoder_DecodeDeviceGetVersion(&pkt->DeviceGetVersion, buff);
    break;
    case kLifxPacketTypeDeviceStateVersion:
    ret = lifxDecoder_DecodeDeviceStateVersion(&pkt->DeviceStateVersion, buff);
    break;
    case kLifxPacketTypeDeviceGetInfo:
    ret = lifxDecoder_DecodeDeviceGetInfo(&pkt->DeviceGetInfo, buff);
    break;
    case kLifxPacketTypeDeviceStateInfo:
    ret = lifxDecoder_DecodeDeviceStateInfo(&pkt->DeviceStateInfo, buff);
    break;
    case kLifxPacketTypeDeviceAcknowledgement:
    ret = lifxDecoder_DecodeDeviceAcknowledgement(&pkt->DeviceAcknowledgement, buff);
    break;
    case kLifxPacketTypeDeviceGetLocation:
    ret = lifxDecoder_DecodeDeviceGetLocation(&pkt->DeviceGetLocation, buff);
    break;
    case kLifxPacketTypeDeviceSetLocation:
    ret = lifxDecoder_DecodeDeviceSetLocation(&pkt->DeviceSetLocation, buff);
    break;
    case kLifxPacketTypeDeviceStateLocation:
    ret = lifxDecoder_DecodeDeviceStateLocation(&pkt->DeviceStateLocation, buff);
    break;
    case kLifxPacketTypeDeviceGetGroup:
    ret = lifxDecoder_DecodeDeviceGetGroup(&pkt->DeviceGetGroup, buff);
    break;
    case kLifxPacketTypeDeviceSetGroup:
    ret = lifxDecoder_DecodeDeviceSetGroup(&pkt->DeviceSetGroup, buff);
    break;
    case kLifxPacketTypeDeviceStateGroup:
    ret = lifxDecoder_DecodeDeviceStateGroup(&pkt->DeviceStateGroup, buff);
    break;
    case kLifxPacketTypeDeviceEchoRequest:
    ret = lifxDecoder_DecodeDeviceEchoRequest(&pkt->DeviceEchoRequest, buff);
    break;
    case kLifxPacketTypeDeviceEchoResponse:
    ret = lifxDecoder_DecodeDeviceEchoResponse(&pkt->DeviceEchoResponse, buff);
    break;
    case kLifxPacketTypeLightGet:
    ret = lifxDecoder_DecodeLightGet(&pkt->LightGet, buff);
    break;
    case kLifxPacketTypeLightSetColor:
    ret = lifxDecoder_DecodeLightSetColor(&pkt->LightSetColor, buff);
    break;
    case kLifxPacketTypeLightSetWaveform:
    ret = lifxDecoder_DecodeLightSetWaveform(&pkt->LightSetWaveform, buff);
    break;
    case kLifxPacketTypeLightState:
    ret = lifxDecoder_DecodeLightState(&pkt->LightState, buff);
    break;
    case kLifxPacketTypeLightGetPower:
    ret = lifxDecoder_DecodeLightGetPower(&pkt->LightGetPower, buff);
    break;
    case kLifxPacketTypeLightSetPower:
    ret = lifxDecoder_DecodeLightSetPower(&pkt->LightSetPower, buff);
    break;
    case kLifxPacketTypeLightStatePower:
    ret = lifxDecoder_DecodeLightStatePower(&pkt->LightStatePower, buff);
    break;
    case kLifxPacketTypeLightSetWaveformOptional:
    ret = lifxDecoder_DecodeLightSetWaveformOptional(&pkt->LightSetWaveformOptional, buff);
    break;
    case kLifxPacketTypeLightGetInfrared:
    ret = lifxDecoder_DecodeLightGetInfrared(&pkt->LightGetInfrared, buff);
    break;
    case kLifxPacketTypeLightStateInfrared:
    ret = lifxDecoder_DecodeLightStateInfrared(&pkt->LightStateInfrared, buff);
    break;
    case kLifxPacketTypeLightSetInfrared:
    ret = lifxDecoder_DecodeLightSetInfrared(&pkt->LightSetInfrared, buff);
    break;
    case kLifxPacketTypeMultiZoneSetColorZones:
    ret = lifxDecoder_DecodeMultiZoneSetColorZones(&pkt->MultiZoneSetColorZones, buff);
    break;
    case kLifxPacketTypeMultiZoneGetColorZones:
    ret = lifxDecoder_DecodeMultiZoneGetColorZones(&pkt->MultiZoneGetColorZones, buff);
    break;
    case kLifxPacketTypeMultiZoneStateZone:
    ret = lifxDecoder_DecodeMultiZoneStateZone(&pkt->MultiZoneStateZone, buff);
    break;
    case kLifxPacketTypeMultiZoneStateMultiZone:
    ret = lifxDecoder_DecodeMultiZoneStateMultiZone(&pkt->MultiZoneStateMultiZone, buff);
    break;
    case kLifxPacketTypeMultiZoneGetEffect:
    ret = lifxDecoder_DecodeMultiZoneGetEffect(&pkt->MultiZoneGetEffect, buff);
    break;
    case kLifxPacketTypeMultiZoneSetEffect:
    ret = lifxDecoder_DecodeMultiZoneSetEffect(&pkt->MultiZoneSetEffect, buff);
    break;
    case kLifxPacketTypeMultiZoneStateEffect:
    ret = lifxDecoder_DecodeMultiZoneStateEffect(&pkt->MultiZoneStateEffect, buff);
    break;
    case kLifxPacketTypeMultiZoneExtendedSetColorZones:
    ret = lifxDecoder_DecodeMultiZoneExtendedSetColorZones(&pkt->MultiZoneExtendedSetColorZones, buff);
    break;
    case kLifxPacketTypeMultiZoneExtendedGetColorZones:
    ret = lifxDecoder_DecodeMultiZoneExtendedGetColorZones(&pkt->MultiZoneExtendedGetColorZones, buff);
    break;
    case kLifxPacketTypeMultiZoneExtendedStateMultiZone:
    ret = lifxDecoder_DecodeMultiZoneExtendedStateMultiZone(&pkt->MultiZoneExtendedStateMultiZone, buff);
    break;
    case kLifxPacketTypeTileGetDeviceChain:
    ret = lifxDecoder_DecodeTileGetDeviceChain(&pkt->TileGetDeviceChain, buff);
    break;
    case kLifxPacketTypeTileStateDeviceChain:
    ret = lifxDecoder_DecodeTileStateDeviceChain(&pkt->TileStateDeviceChain, buff);
    break;
    case kLifxPacketTypeTileSetUserPosition:
    ret = lifxDecoder_DecodeTileSetUserPosition(&pkt->TileSetUserPosition, buff);
    break;
    case kLifxPacketTypeTileGet64:
    ret = lifxDecoder_DecodeTileGet64(&pkt->TileGet64, buff);
    break;
    case kLifxPacketTypeTileState64:
    ret = lifxDecoder_DecodeTileState64(&pkt->TileState64, buff);
    break;
    case kLifxPacketTypeTileSet64:
    ret = lifxDecoder_DecodeTileSet64(&pkt->TileSet64, buff);
    break;
    case kLifxPacketTypeTileGetEffect:
    ret = lifxDecoder_DecodeTileGetEffect(&pkt->TileGetEffect, buff);
    break;
    case kLifxPacketTypeTileSetEffect:
    ret = lifxDecoder_DecodeTileSetEffect(&pkt->TileSetEffect, buff);
    break;
    case kLifxPacketTypeTileStateEffect:
    ret = lifxDecoder_DecodeTileStateEffect(&pkt->TileStateEffect, buff);
    break;
  }
  return ret;
}
int lifxEncoder_EncodeDeviceGetService(lifxDeviceGetService_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 2, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeDeviceGetService(lifxDeviceGetService_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 2, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceStateService(lifxDeviceStateService_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 3, 'size_bytes': 5, 'fields': [{'name': 'Service', 'type': '<DeviceService>', 'size_bytes': 1}, {'name': 'Port', 'type': 'uint32', 'size_bytes': 4}]}
  lifxBuffer_Init(buff, 5);
  // {'name': 'Service', 'type': '<DeviceService>', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Service);
  // {'name': 'Port', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Port);
  return 0;
}

int lifxDecoder_DecodeDeviceStateService(lifxDeviceStateService_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 3, 'size_bytes': 5, 'fields': [{'name': 'Service', 'type': '<DeviceService>', 'size_bytes': 1}, {'name': 'Port', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Service', 'type': '<DeviceService>', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Service);
  // {'name': 'Port', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Port);
  return 0;
}

int lifxEncoder_EncodeDeviceGetHostInfo(lifxDeviceGetHostInfo_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 12, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeDeviceGetHostInfo(lifxDeviceGetHostInfo_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 12, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceStateHostInfo(lifxDeviceStateHostInfo_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 13, 'size_bytes': 14, 'fields': [{'name': 'Signal', 'type': 'float32', 'size_bytes': 4}, {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}, {'type': 'reserved', 'size_bytes': 2}]}
  lifxBuffer_Init(buff, 14);
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

int lifxDecoder_DecodeDeviceStateHostInfo(lifxDeviceStateHostInfo_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeDeviceGetHostFirmware(lifxDeviceGetHostFirmware_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 14, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeDeviceGetHostFirmware(lifxDeviceGetHostFirmware_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 14, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceStateHostFirmware(lifxDeviceStateHostFirmware_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 15, 'size_bytes': 20, 'fields': [{'name': 'Build', 'type': 'uint64', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 8}, {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}, {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}]}
  lifxBuffer_Init(buff, 20);
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

int lifxDecoder_DecodeDeviceStateHostFirmware(lifxDeviceStateHostFirmware_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeDeviceGetWifiInfo(lifxDeviceGetWifiInfo_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 16, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeDeviceGetWifiInfo(lifxDeviceGetWifiInfo_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 16, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceStateWifiInfo(lifxDeviceStateWifiInfo_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 17, 'size_bytes': 14, 'fields': [{'name': 'Signal', 'type': 'float32', 'size_bytes': 4}, {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}, {'type': 'reserved', 'size_bytes': 2}]}
  lifxBuffer_Init(buff, 14);
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

int lifxDecoder_DecodeDeviceStateWifiInfo(lifxDeviceStateWifiInfo_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeDeviceGetWifiFirmware(lifxDeviceGetWifiFirmware_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 18, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeDeviceGetWifiFirmware(lifxDeviceGetWifiFirmware_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 18, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceStateWifiFirmware(lifxDeviceStateWifiFirmware_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 19, 'size_bytes': 20, 'fields': [{'name': 'Build', 'type': 'uint64', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 8}, {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}, {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}]}
  lifxBuffer_Init(buff, 20);
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

int lifxDecoder_DecodeDeviceStateWifiFirmware(lifxDeviceStateWifiFirmware_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeDeviceGetPower(lifxDeviceGetPower_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 20, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeDeviceGetPower(lifxDeviceGetPower_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 20, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceSetPower(lifxDeviceSetPower_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 21, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  lifxBuffer_Init(buff, 2);
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  return 0;
}

int lifxDecoder_DecodeDeviceSetPower(lifxDeviceSetPower_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 21, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
  return 0;
}

int lifxEncoder_EncodeDeviceStatePower(lifxDeviceStatePower_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 22, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  lifxBuffer_Init(buff, 2);
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  return 0;
}

int lifxDecoder_DecodeDeviceStatePower(lifxDeviceStatePower_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 22, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
  return 0;
}

int lifxEncoder_EncodeDeviceGetLabel(lifxDeviceGetLabel_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 23, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeDeviceGetLabel(lifxDeviceGetLabel_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 23, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceSetLabel(lifxDeviceSetLabel_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 24, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
  lifxBuffer_Init(buff, 32);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  return 0;
}

int lifxDecoder_DecodeDeviceSetLabel(lifxDeviceSetLabel_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 24, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Read(buff, pkt->Label, 32);
  return 0;
}

int lifxEncoder_EncodeDeviceStateLabel(lifxDeviceStateLabel_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 25, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
  lifxBuffer_Init(buff, 32);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  return 0;
}

int lifxDecoder_DecodeDeviceStateLabel(lifxDeviceStateLabel_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 25, 'size_bytes': 32, 'fields': [{'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}]}
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Read(buff, pkt->Label, 32);
  return 0;
}

int lifxEncoder_EncodeDeviceGetVersion(lifxDeviceGetVersion_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 32, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeDeviceGetVersion(lifxDeviceGetVersion_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 32, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceStateVersion(lifxDeviceStateVersion_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 33, 'size_bytes': 12, 'fields': [{'name': 'Vendor', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Product', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Version', 'type': 'uint32', 'size_bytes': 4}]}
  lifxBuffer_Init(buff, 12);
  // {'name': 'Vendor', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Vendor);
  // {'name': 'Product', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Product);
  // {'name': 'Version', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Version);
  return 0;
}

int lifxDecoder_DecodeDeviceStateVersion(lifxDeviceStateVersion_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeDeviceGetInfo(lifxDeviceGetInfo_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 34, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeDeviceGetInfo(lifxDeviceGetInfo_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 34, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceStateInfo(lifxDeviceStateInfo_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 35, 'size_bytes': 24, 'fields': [{'name': 'Time', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Uptime', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Downtime', 'type': 'uint64', 'size_bytes': 8}]}
  lifxBuffer_Init(buff, 24);
  // {'name': 'Time', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->Time);
  // {'name': 'Uptime', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->Uptime);
  // {'name': 'Downtime', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->Downtime);
  return 0;
}

int lifxDecoder_DecodeDeviceStateInfo(lifxDeviceStateInfo_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeDeviceAcknowledgement(lifxDeviceAcknowledgement_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 45, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeDeviceAcknowledgement(lifxDeviceAcknowledgement_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 45, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceGetLocation(lifxDeviceGetLocation_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 48, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeDeviceGetLocation(lifxDeviceGetLocation_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 48, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceSetLocation(lifxDeviceSetLocation_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 49, 'size_bytes': 56, 'fields': [{'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  lifxBuffer_Init(buff, 56);
  // {'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Write(buff, pkt->Location, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return 0;
}

int lifxDecoder_DecodeDeviceSetLocation(lifxDeviceSetLocation_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeDeviceStateLocation(lifxDeviceStateLocation_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 50, 'size_bytes': 56, 'fields': [{'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  lifxBuffer_Init(buff, 56);
  // {'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Write(buff, pkt->Location, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return 0;
}

int lifxDecoder_DecodeDeviceStateLocation(lifxDeviceStateLocation_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeDeviceGetGroup(lifxDeviceGetGroup_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 51, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeDeviceGetGroup(lifxDeviceGetGroup_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 51, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeDeviceSetGroup(lifxDeviceSetGroup_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 52, 'size_bytes': 56, 'fields': [{'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  lifxBuffer_Init(buff, 56);
  // {'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Write(buff, pkt->Group, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return 0;
}

int lifxDecoder_DecodeDeviceSetGroup(lifxDeviceSetGroup_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeDeviceStateGroup(lifxDeviceStateGroup_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 53, 'size_bytes': 56, 'fields': [{'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}]}
  lifxBuffer_Init(buff, 56);
  // {'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}
  lifxBuffer_Write(buff, pkt->Group, 16);
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return 0;
}

int lifxDecoder_DecodeDeviceStateGroup(lifxDeviceStateGroup_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeDeviceEchoRequest(lifxDeviceEchoRequest_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 58, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
  lifxBuffer_Init(buff, 64);
  // {'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}
  lifxBuffer_Write(buff, pkt->Payload, 64);
  return 0;
}

int lifxDecoder_DecodeDeviceEchoRequest(lifxDeviceEchoRequest_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 58, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
  // {'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}
  lifxBuffer_Read(buff, pkt->Payload, 64);
  return 0;
}

int lifxEncoder_EncodeDeviceEchoResponse(lifxDeviceEchoResponse_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 59, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
  lifxBuffer_Init(buff, 64);
  // {'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}
  lifxBuffer_Write(buff, pkt->Payload, 64);
  return 0;
}

int lifxDecoder_DecodeDeviceEchoResponse(lifxDeviceEchoResponse_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 59, 'size_bytes': 64, 'fields': [{'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}]}
  // {'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}
  lifxBuffer_Read(buff, pkt->Payload, 64);
  return 0;
}

int lifxEncoder_EncodeLightGet(lifxLightGet_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 101, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeLightGet(lifxLightGet_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 101, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeLightSetColor(lifxLightSetColor_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 102, 'size_bytes': 13, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
  lifxBuffer_Init(buff, 13);
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxEncoder_EncodeLightHsbk(&pkt->Color, buff);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  return 0;
}

int lifxDecoder_DecodeLightSetColor(lifxLightSetColor_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 102, 'size_bytes': 13, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxDecoder_DecodeLightHsbk(&pkt->Color, buff);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  return 0;
}

int lifxEncoder_EncodeLightSetWaveformOptional(lifxLightSetWaveformOptional_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 119, 'size_bytes': 25, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}, {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}, {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}, {'name': 'SetHue', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetSaturation', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetBrightness', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetKelvin', 'type': 'bool', 'size_bytes': 1}]}
  lifxBuffer_Init(buff, 25);
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_WriteBool(buff, pkt->Transient);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxEncoder_EncodeLightHsbk(&pkt->Color, buff);
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

int lifxDecoder_DecodeLightSetWaveformOptional(lifxLightSetWaveformOptional_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 119, 'size_bytes': 25, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}, {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}, {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}, {'name': 'SetHue', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetSaturation', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetBrightness', 'type': 'bool', 'size_bytes': 1}, {'name': 'SetKelvin', 'type': 'bool', 'size_bytes': 1}]}
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_ReadBool(buff, &pkt->Transient);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxDecoder_DecodeLightHsbk(&pkt->Color, buff);
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

int lifxEncoder_EncodeLightSetWaveform(lifxLightSetWaveform_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 103, 'size_bytes': 21, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}, {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}, {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}]}
  lifxBuffer_Init(buff, 21);
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_WriteBool(buff, pkt->Transient);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxEncoder_EncodeLightHsbk(&pkt->Color, buff);
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

int lifxDecoder_DecodeLightSetWaveform(lifxLightSetWaveform_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 103, 'size_bytes': 21, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}, {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}, {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}]}
  // {'type': 'reserved', 'size_bytes': 1}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}
  lifxBuffer_ReadBool(buff, &pkt->Transient);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxDecoder_DecodeLightHsbk(&pkt->Color, buff);
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

int lifxEncoder_EncodeLightGetPower(lifxLightGetPower_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 116, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeLightGetPower(lifxLightGetPower_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 116, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeLightSetPower(lifxLightSetPower_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 117, 'size_bytes': 6, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
  lifxBuffer_Init(buff, 6);
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  return 0;
}

int lifxDecoder_DecodeLightSetPower(lifxLightSetPower_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 117, 'size_bytes': 6, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  return 0;
}

int lifxEncoder_EncodeLightStatePower(lifxLightStatePower_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 118, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  lifxBuffer_Init(buff, 2);
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  return 0;
}

int lifxDecoder_DecodeLightStatePower(lifxLightStatePower_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 118, 'size_bytes': 2, 'fields': [{'name': 'Level', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
  return 0;
}

int lifxEncoder_EncodeLightState(lifxLightState_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 107, 'size_bytes': 52, 'fields': [{'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'Power', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'type': 'reserved', 'size_bytes': 8}]}
  lifxBuffer_Init(buff, 52);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxEncoder_EncodeLightHsbk(&pkt->Color, buff);
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

int lifxDecoder_DecodeLightState(lifxLightState_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 107, 'size_bytes': 52, 'fields': [{'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'Power', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}, {'type': 'reserved', 'size_bytes': 8}]}
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxDecoder_DecodeLightHsbk(&pkt->Color, buff);
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

int lifxEncoder_EncodeLightGetInfrared(lifxLightGetInfrared_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 120, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeLightGetInfrared(lifxLightGetInfrared_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 120, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeLightStateInfrared(lifxLightStateInfrared_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 121, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
  lifxBuffer_Init(buff, 2);
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Brightness);
  return 0;
}

int lifxDecoder_DecodeLightStateInfrared(lifxLightStateInfrared_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 121, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Brightness);
  return 0;
}

int lifxEncoder_EncodeLightSetInfrared(lifxLightSetInfrared_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 122, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
  lifxBuffer_Init(buff, 2);
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Brightness);
  return 0;
}

int lifxDecoder_DecodeLightSetInfrared(lifxLightSetInfrared_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 122, 'size_bytes': 2, 'fields': [{'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}]}
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Brightness);
  return 0;
}

int lifxEncoder_EncodeTileGetDeviceChain(lifxTileGetDeviceChain_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 701, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeTileGetDeviceChain(lifxTileGetDeviceChain_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 701, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeTileStateDeviceChain(lifxTileStateDeviceChain_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 702, 'size_bytes': 882, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'TileDevices', 'type': '[16]<TileStateDevice>', 'size_bytes': 880}, {'name': 'TileDevicesCount', 'type': 'uint8', 'size_bytes': 1}]}
  lifxBuffer_Init(buff, 882);
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->StartIndex);
  // {'name': 'TileDevices', 'type': '[16]<TileStateDevice>', 'size_bytes': 880}
  lifxEncoder_EncodeTileStateDevice(&pkt->TileDevices, buff);
  // {'name': 'TileDevicesCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->TileDevicesCount);
  return 0;
}

int lifxDecoder_DecodeTileStateDeviceChain(lifxTileStateDeviceChain_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 702, 'size_bytes': 882, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'TileDevices', 'type': '[16]<TileStateDevice>', 'size_bytes': 880}, {'name': 'TileDevicesCount', 'type': 'uint8', 'size_bytes': 1}]}
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->StartIndex);
  // {'name': 'TileDevices', 'type': '[16]<TileStateDevice>', 'size_bytes': 880}
  lifxDecoder_DecodeTileStateDevice(&pkt->TileDevices, buff);
  // {'name': 'TileDevicesCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->TileDevicesCount);
  return 0;
}

int lifxEncoder_EncodeTileSetUserPosition(lifxTileSetUserPosition_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 703, 'size_bytes': 11, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'UserX', 'type': 'float32', 'size_bytes': 4}, {'name': 'UserY', 'type': 'float32', 'size_bytes': 4}]}
  lifxBuffer_Init(buff, 11);
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

int lifxDecoder_DecodeTileSetUserPosition(lifxTileSetUserPosition_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeTileGet64(lifxTileGet64_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 707, 'size_bytes': 6, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}]}
  lifxBuffer_Init(buff, 6);
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->TileIndex);
  // {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Length);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxEncoder_EncodeTileBufferRect(&pkt->Rect, buff);
  return 0;
}

int lifxDecoder_DecodeTileGet64(lifxTileGet64_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 707, 'size_bytes': 6, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}]}
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->TileIndex);
  // {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Length);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxDecoder_DecodeTileBufferRect(&pkt->Rect, buff);
  return 0;
}

int lifxEncoder_EncodeTileState64(lifxTileState64_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 711, 'size_bytes': 517, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}, {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}]}
  lifxBuffer_Init(buff, 517);
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->TileIndex);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxEncoder_EncodeTileBufferRect(&pkt->Rect, buff);
  // {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}
  lifxEncoder_EncodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxDecoder_DecodeTileState64(lifxTileState64_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 711, 'size_bytes': 517, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}, {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}]}
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->TileIndex);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxDecoder_DecodeTileBufferRect(&pkt->Rect, buff);
  // {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}
  lifxDecoder_DecodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxEncoder_EncodeTileSet64(lifxTileSet64_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 715, 'size_bytes': 522, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}]}
  lifxBuffer_Init(buff, 522);
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->TileIndex);
  // {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Length);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxEncoder_EncodeTileBufferRect(&pkt->Rect, buff);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  // {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}
  lifxEncoder_EncodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxDecoder_DecodeTileSet64(lifxTileSet64_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 715, 'size_bytes': 522, 'fields': [{'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}]}
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->TileIndex);
  // {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Length);
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxDecoder_DecodeTileBufferRect(&pkt->Rect, buff);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  // {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}
  lifxDecoder_DecodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxEncoder_EncodeTileGetEffect(lifxTileGetEffect_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 718, 'size_bytes': 2, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}]}
  lifxBuffer_Init(buff, 2);
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved0);
  // {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved1);
  return 0;
}

int lifxDecoder_DecodeTileGetEffect(lifxTileGetEffect_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 718, 'size_bytes': 2, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}]}
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved0);
  // {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved1);
  return 0;
}

int lifxEncoder_EncodeTileSetEffect(lifxTileSetEffect_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 719, 'size_bytes': 188, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
  lifxBuffer_Init(buff, 188);
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved0);
  // {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved1);
  // {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}
  lifxEncoder_EncodeTileEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxDecoder_DecodeTileSetEffect(lifxTileSetEffect_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 719, 'size_bytes': 188, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved0);
  // {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved1);
  // {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}
  lifxDecoder_DecodeTileEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxEncoder_EncodeTileStateEffect(lifxTileStateEffect_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 720, 'size_bytes': 187, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
  lifxBuffer_Init(buff, 187);
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved0);
  // {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}
  lifxEncoder_EncodeTileEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxDecoder_DecodeTileStateEffect(lifxTileStateEffect_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 720, 'size_bytes': 187, 'fields': [{'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}]}
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved0);
  // {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}
  lifxDecoder_DecodeTileEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxEncoder_EncodeMultiZoneSetColorZones(lifxMultiZoneSetColorZones_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 501, 'size_bytes': 15, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Apply', 'type': '<MultiZoneApplicationRequest>', 'size_bytes': 1}]}
  lifxBuffer_Init(buff, 15);
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->StartIndex);
  // {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->EndIndex);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxEncoder_EncodeLightHsbk(&pkt->Color, buff);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  // {'name': 'Apply', 'type': '<MultiZoneApplicationRequest>', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Apply);
  return 0;
}

int lifxDecoder_DecodeMultiZoneSetColorZones(lifxMultiZoneSetColorZones_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 501, 'size_bytes': 15, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}, {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Apply', 'type': '<MultiZoneApplicationRequest>', 'size_bytes': 1}]}
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->StartIndex);
  // {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->EndIndex);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxDecoder_DecodeLightHsbk(&pkt->Color, buff);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  // {'name': 'Apply', 'type': '<MultiZoneApplicationRequest>', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Apply);
  return 0;
}

int lifxEncoder_EncodeMultiZoneGetColorZones(lifxMultiZoneGetColorZones_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 502, 'size_bytes': 2, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}]}
  lifxBuffer_Init(buff, 2);
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->StartIndex);
  // {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->EndIndex);
  return 0;
}

int lifxDecoder_DecodeMultiZoneGetColorZones(lifxMultiZoneGetColorZones_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 502, 'size_bytes': 2, 'fields': [{'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}, {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}]}
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->StartIndex);
  // {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->EndIndex);
  return 0;
}

int lifxEncoder_EncodeMultiZoneStateZone(lifxMultiZoneStateZone_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 503, 'size_bytes': 10, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}]}
  lifxBuffer_Init(buff, 10);
  // {'name': 'Count', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Count);
  // {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Index);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxEncoder_EncodeLightHsbk(&pkt->Color, buff);
  return 0;
}

int lifxDecoder_DecodeMultiZoneStateZone(lifxMultiZoneStateZone_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 503, 'size_bytes': 10, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}]}
  // {'name': 'Count', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Count);
  // {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Index);
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxDecoder_DecodeLightHsbk(&pkt->Color, buff);
  return 0;
}

int lifxEncoder_EncodeMultiZoneStateMultiZone(lifxMultiZoneStateMultiZone_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 506, 'size_bytes': 66, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[8]<LightHsbk>', 'size_bytes': 64}]}
  lifxBuffer_Init(buff, 66);
  // {'name': 'Count', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Count);
  // {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->Index);
  // {'name': 'Colors', 'type': '[8]<LightHsbk>', 'size_bytes': 64}
  lifxEncoder_EncodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxDecoder_DecodeMultiZoneStateMultiZone(lifxMultiZoneStateMultiZone_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 506, 'size_bytes': 66, 'fields': [{'name': 'Count', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[8]<LightHsbk>', 'size_bytes': 64}]}
  // {'name': 'Count', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Count);
  // {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->Index);
  // {'name': 'Colors', 'type': '[8]<LightHsbk>', 'size_bytes': 64}
  lifxDecoder_DecodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxEncoder_EncodeMultiZoneGetEffect(lifxMultiZoneGetEffect_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 507, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeMultiZoneGetEffect(lifxMultiZoneGetEffect_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 507, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeMultiZoneSetEffect(lifxMultiZoneSetEffect_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 508, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
  lifxBuffer_Init(buff, 59);
  // {'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}
  lifxEncoder_EncodeMultiZoneEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxDecoder_DecodeMultiZoneSetEffect(lifxMultiZoneSetEffect_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 508, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
  // {'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}
  lifxDecoder_DecodeMultiZoneEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxEncoder_EncodeMultiZoneStateEffect(lifxMultiZoneStateEffect_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 509, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
  lifxBuffer_Init(buff, 59);
  // {'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}
  lifxEncoder_EncodeMultiZoneEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxDecoder_DecodeMultiZoneStateEffect(lifxMultiZoneStateEffect_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 509, 'size_bytes': 59, 'fields': [{'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}]}
  // {'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}
  lifxDecoder_DecodeMultiZoneEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxEncoder_EncodeMultiZoneExtendedSetColorZones(lifxMultiZoneExtendedSetColorZones_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 510, 'size_bytes': 664, 'fields': [{'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Apply', 'type': '<MultiZoneExtendedApplicationRequest>', 'size_bytes': 1}, {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}, {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}]}
  lifxBuffer_Init(buff, 664);
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  // {'name': 'Apply', 'type': '<MultiZoneExtendedApplicationRequest>', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Apply);
  // {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Index);
  // {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->ColorsCount);
  // {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}
  lifxEncoder_EncodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxDecoder_DecodeMultiZoneExtendedSetColorZones(lifxMultiZoneExtendedSetColorZones_t* pkt, lifxBuffer_t* buff)
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
  lifxDecoder_DecodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxEncoder_EncodeMultiZoneExtendedGetColorZones(lifxMultiZoneExtendedGetColorZones_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 511, 'size_bytes': 0, 'fields': []}
  lifxBuffer_Init(buff, 0);
  return 0;
}

int lifxDecoder_DecodeMultiZoneExtendedGetColorZones(lifxMultiZoneExtendedGetColorZones_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 511, 'size_bytes': 0, 'fields': []}
  return 0;
}

int lifxEncoder_EncodeMultiZoneExtendedStateMultiZone(lifxMultiZoneExtendedStateMultiZone_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 512, 'size_bytes': 661, 'fields': [{'name': 'Count', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}, {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}]}
  lifxBuffer_Init(buff, 661);
  // {'name': 'Count', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Count);
  // {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_WriteUInt16(buff, pkt->Index);
  // {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->ColorsCount);
  // {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}
  lifxEncoder_EncodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxDecoder_DecodeMultiZoneExtendedStateMultiZone(lifxMultiZoneExtendedStateMultiZone_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 512, 'size_bytes': 661, 'fields': [{'name': 'Count', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}, {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}]}
  // {'name': 'Count', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Count);
  // {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}
  lifxBuffer_ReadUInt16(buff, &pkt->Index);
  // {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->ColorsCount);
  // {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}
  lifxDecoder_DecodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxEncoder_EncodeLightHsbk(lifxLightHsbk_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 8, 'fields': [{'name': 'Hue', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Saturation', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}, {'name': 'Kelvin', 'type': 'uint16', 'size_bytes': 2}]}
  lifxBuffer_Init(buff, 8);
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

int lifxDecoder_DecodeLightHsbk(lifxLightHsbk_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeMultiZoneEffectParameter(lifxMultiZoneEffectParameter_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 32, 'fields': [{'name': 'Parameter0', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter1', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter2', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter3', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter4', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter5', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter6', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter7', 'type': 'uint32', 'size_bytes': 4}]}
  lifxBuffer_Init(buff, 32);
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

int lifxDecoder_DecodeMultiZoneEffectParameter(lifxMultiZoneEffectParameter_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeMultiZoneEffectSettings(lifxMultiZoneEffectSettings_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 59, 'fields': [{'name': 'Instanceid', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Type', 'type': '<MultiZoneEffectType>', 'size_bytes': 1}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'Speed', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Duration', 'type': 'uint64', 'size_bytes': 8}, {'type': 'reserved', 'size_bytes': 4}, {'type': 'reserved', 'size_bytes': 4}, {'name': 'Parameter', 'type': '<MultiZoneEffectParameter>', 'size_bytes': 32}]}
  lifxBuffer_Init(buff, 59);
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
  lifxEncoder_EncodeMultiZoneEffectParameter(&pkt->Parameter, buff);
  return 0;
}

int lifxDecoder_DecodeMultiZoneEffectSettings(lifxMultiZoneEffectSettings_t* pkt, lifxBuffer_t* buff)
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
  lifxDecoder_DecodeMultiZoneEffectParameter(&pkt->Parameter, buff);
  return 0;
}

int lifxEncoder_EncodeTileAccelMeas(lifxTileAccelMeas_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 6, 'fields': [{'name': 'X', 'type': 'int16', 'size_bytes': 2}, {'name': 'Y', 'type': 'int16', 'size_bytes': 2}, {'name': 'Z', 'type': 'int16', 'size_bytes': 2}]}
  lifxBuffer_Init(buff, 6);
  // {'name': 'X', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_WriteInt16(buff, pkt->X);
  // {'name': 'Y', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_WriteInt16(buff, pkt->Y);
  // {'name': 'Z', 'type': 'int16', 'size_bytes': 2}
  lifxBuffer_WriteInt16(buff, pkt->Z);
  return 0;
}

int lifxDecoder_DecodeTileAccelMeas(lifxTileAccelMeas_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeTileStateDevice(lifxTileStateDevice_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 55, 'fields': [{'name': 'AccelMeas', 'type': '<TileAccelMeas>', 'size_bytes': 6}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'UserX', 'type': 'float32', 'size_bytes': 4}, {'name': 'UserY', 'type': 'float32', 'size_bytes': 4}, {'name': 'Width', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Height', 'type': 'uint8', 'size_bytes': 1}, {'type': 'reserved', 'size_bytes': 1}, {'name': 'DeviceVersion', 'type': '<DeviceStateVersion>', 'size_bytes': 12}, {'name': 'Firmware', 'type': '<DeviceStateHostFirmware>', 'size_bytes': 20}, {'type': 'reserved', 'size_bytes': 4}]}
  lifxBuffer_Init(buff, 55);
  // {'name': 'AccelMeas', 'type': '<TileAccelMeas>', 'size_bytes': 6}
  lifxEncoder_EncodeTileAccelMeas(&pkt->AccelMeas, buff);
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
  lifxEncoder_EncodeDeviceStateVersion(&pkt->DeviceVersion, buff);
  // {'name': 'Firmware', 'type': '<DeviceStateHostFirmware>', 'size_bytes': 20}
  lifxEncoder_EncodeDeviceStateHostFirmware(&pkt->Firmware, buff);
  // {'type': 'reserved', 'size_bytes': 4}
  lifxBuffer_Seek(buff, 4, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxDecoder_DecodeTileStateDevice(lifxTileStateDevice_t* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 55, 'fields': [{'name': 'AccelMeas', 'type': '<TileAccelMeas>', 'size_bytes': 6}, {'type': 'reserved', 'size_bytes': 2}, {'name': 'UserX', 'type': 'float32', 'size_bytes': 4}, {'name': 'UserY', 'type': 'float32', 'size_bytes': 4}, {'name': 'Width', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Height', 'type': 'uint8', 'size_bytes': 1}, {'type': 'reserved', 'size_bytes': 1}, {'name': 'DeviceVersion', 'type': '<DeviceStateVersion>', 'size_bytes': 12}, {'name': 'Firmware', 'type': '<DeviceStateHostFirmware>', 'size_bytes': 20}, {'type': 'reserved', 'size_bytes': 4}]}
  // {'name': 'AccelMeas', 'type': '<TileAccelMeas>', 'size_bytes': 6}
  lifxDecoder_DecodeTileAccelMeas(&pkt->AccelMeas, buff);
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
  lifxDecoder_DecodeDeviceStateVersion(&pkt->DeviceVersion, buff);
  // {'name': 'Firmware', 'type': '<DeviceStateHostFirmware>', 'size_bytes': 20}
  lifxDecoder_DecodeDeviceStateHostFirmware(&pkt->Firmware, buff);
  // {'type': 'reserved', 'size_bytes': 4}
  lifxBuffer_Seek(buff, 4, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxEncoder_EncodeTileBufferRect(lifxTileBufferRect_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 4, 'fields': [{'type': 'reserved', 'size_bytes': 1}, {'name': 'X', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Y', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Width', 'type': 'uint8', 'size_bytes': 1}]}
  lifxBuffer_Init(buff, 4);
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

int lifxDecoder_DecodeTileBufferRect(lifxTileBufferRect_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeTileEffectParameter(lifxTileEffectParameter_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 32, 'fields': [{'name': 'Parameter0', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter1', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter2', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter3', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter4', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter5', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter6', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter7', 'type': 'uint32', 'size_bytes': 4}]}
  lifxBuffer_Init(buff, 32);
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

int lifxDecoder_DecodeTileEffectParameter(lifxTileEffectParameter_t* pkt, lifxBuffer_t* buff)
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

int lifxEncoder_EncodeTileEffectSettings(lifxTileEffectSettings_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 186, 'fields': [{'name': 'Instanceid', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Type', 'type': '<TileEffectType>', 'size_bytes': 1}, {'name': 'Speed', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Duration', 'type': 'uint64', 'size_bytes': 8}, {'name': 'Reserved0', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Reserved1', 'type': 'uint32', 'size_bytes': 4}, {'name': 'Parameter', 'type': '<TileEffectParameter>', 'size_bytes': 32}, {'name': 'PaletteCount', 'type': 'uint8', 'size_bytes': 1}, {'name': 'Palette', 'type': '[16]<LightHsbk>', 'size_bytes': 128}]}
  lifxBuffer_Init(buff, 186);
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
  lifxEncoder_EncodeTileEffectParameter(&pkt->Parameter, buff);
  // {'name': 'PaletteCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_WriteUInt8(buff, pkt->PaletteCount);
  // {'name': 'Palette', 'type': '[16]<LightHsbk>', 'size_bytes': 128}
  lifxEncoder_EncodeLightHsbk(&pkt->Palette, buff);
  return 0;
}

int lifxDecoder_DecodeTileEffectSettings(lifxTileEffectSettings_t* pkt, lifxBuffer_t* buff)
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
  lifxDecoder_DecodeTileEffectParameter(&pkt->Parameter, buff);
  // {'name': 'PaletteCount', 'type': 'uint8', 'size_bytes': 1}
  lifxBuffer_ReadUInt8(buff, &pkt->PaletteCount);
  // {'name': 'Palette', 'type': '[16]<LightHsbk>', 'size_bytes': 128}
  lifxDecoder_DecodeLightHsbk(&pkt->Palette, buff);
  return 0;
}

