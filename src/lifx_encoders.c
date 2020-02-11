//
// DO NOT EDIT - AUTO-GENERATE:2020-02-10 14:58:43.460918
//
#include "lifx.h"
#include "lifx_encoders.h"

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

int lifxEncoder_EncodeDeviceStateService(lifxDeviceStateService_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 3, 'size_bytes': 5, 'fields': [{'size_bytes': 1, 'type': '<DeviceService>', 'name': 'Service'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Port'}]}
  lifxBuffer_Init(buff, 5);
  // {'size_bytes': 1, 'type': '<DeviceService>', 'name': 'Service'}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Service);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Port'}
  lifxBuffer_WriteUInt32(buff, pkt->Port);
  return 0;
}

int lifxDecoder_DecodeDeviceStateService(lifxDeviceStateService_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 3, 'size_bytes': 5, 'fields': [{'size_bytes': 1, 'type': '<DeviceService>', 'name': 'Service'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Port'}]}
  // {'size_bytes': 1, 'type': '<DeviceService>', 'name': 'Service'}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Service);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Port'}
  lifxBuffer_ReadUInt32(buff, &pkt->Port);
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

int lifxEncoder_EncodeDeviceStateHostInfo(lifxDeviceStateHostInfo_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 13, 'size_bytes': 14, 'fields': [{'size_bytes': 4, 'type': 'float32', 'name': 'Signal'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Tx'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Rx'}, {'size_bytes': 2, 'type': 'reserved'}]}
  lifxBuffer_Init(buff, 14);
  // {'size_bytes': 4, 'type': 'float32', 'name': 'Signal'}
  lifxBuffer_WriteFloat(buff, pkt->Signal);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Tx'}
  lifxBuffer_WriteUInt32(buff, pkt->Tx);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Rx'}
  lifxBuffer_WriteUInt32(buff, pkt->Rx);
  // {'size_bytes': 2, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxDecoder_DecodeDeviceStateHostInfo(lifxDeviceStateHostInfo_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 13, 'size_bytes': 14, 'fields': [{'size_bytes': 4, 'type': 'float32', 'name': 'Signal'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Tx'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Rx'}, {'size_bytes': 2, 'type': 'reserved'}]}
  // {'size_bytes': 4, 'type': 'float32', 'name': 'Signal'}
  lifxBuffer_ReadFloat(buff, &pkt->Signal);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Tx'}
  lifxBuffer_ReadUInt32(buff, &pkt->Tx);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Rx'}
  lifxBuffer_ReadUInt32(buff, &pkt->Rx);
  // {'size_bytes': 2, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
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

int lifxEncoder_EncodeDeviceStateLabel(lifxDeviceStateLabel_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 25, 'size_bytes': 32, 'fields': [{'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}]}
  lifxBuffer_Init(buff, 32);
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  lifxBuffer_Write(buff, pkt->Label, 32);
  return 0;
}

int lifxDecoder_DecodeDeviceStateLabel(lifxDeviceStateLabel_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 25, 'size_bytes': 32, 'fields': [{'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}]}
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  lifxBuffer_Read(buff, pkt->Label, 32);
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

int lifxEncoder_EncodeDeviceStateWifiFirmware(lifxDeviceStateWifiFirmware_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 19, 'size_bytes': 20, 'fields': [{'size_bytes': 8, 'type': 'uint64', 'name': 'Build'}, {'size_bytes': 8, 'type': 'reserved'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMinor'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMajor'}]}
  lifxBuffer_Init(buff, 20);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Build'}
  lifxBuffer_WriteUInt64(buff, pkt->Build);
  // {'size_bytes': 8, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 8, kLifxBufferWhenceCurrent);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMinor'}
  lifxBuffer_WriteUInt16(buff, pkt->VersionMinor);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMajor'}
  lifxBuffer_WriteUInt16(buff, pkt->VersionMajor);
  return 0;
}

int lifxDecoder_DecodeDeviceStateWifiFirmware(lifxDeviceStateWifiFirmware_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 19, 'size_bytes': 20, 'fields': [{'size_bytes': 8, 'type': 'uint64', 'name': 'Build'}, {'size_bytes': 8, 'type': 'reserved'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMinor'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMajor'}]}
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Build'}
  lifxBuffer_ReadUInt64(buff, &pkt->Build);
  // {'size_bytes': 8, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 8, kLifxBufferWhenceCurrent);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMinor'}
  lifxBuffer_ReadUInt16(buff, &pkt->VersionMinor);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMajor'}
  lifxBuffer_ReadUInt16(buff, &pkt->VersionMajor);
  return 0;
}

int lifxEncoder_EncodeDeviceStateVersion(lifxDeviceStateVersion_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 33, 'size_bytes': 12, 'fields': [{'size_bytes': 4, 'type': 'uint32', 'name': 'Vendor'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Product'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Version'}]}
  lifxBuffer_Init(buff, 12);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Vendor'}
  lifxBuffer_WriteUInt32(buff, pkt->Vendor);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Product'}
  lifxBuffer_WriteUInt32(buff, pkt->Product);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Version'}
  lifxBuffer_WriteUInt32(buff, pkt->Version);
  return 0;
}

int lifxDecoder_DecodeDeviceStateVersion(lifxDeviceStateVersion_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 33, 'size_bytes': 12, 'fields': [{'size_bytes': 4, 'type': 'uint32', 'name': 'Vendor'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Product'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Version'}]}
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Vendor'}
  lifxBuffer_ReadUInt32(buff, &pkt->Vendor);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Product'}
  lifxBuffer_ReadUInt32(buff, &pkt->Product);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Version'}
  lifxBuffer_ReadUInt32(buff, &pkt->Version);
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

int lifxEncoder_EncodeDeviceStateWifiInfo(lifxDeviceStateWifiInfo_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 17, 'size_bytes': 14, 'fields': [{'size_bytes': 4, 'type': 'float32', 'name': 'Signal'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Tx'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Rx'}, {'size_bytes': 2, 'type': 'reserved'}]}
  lifxBuffer_Init(buff, 14);
  // {'size_bytes': 4, 'type': 'float32', 'name': 'Signal'}
  lifxBuffer_WriteFloat(buff, pkt->Signal);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Tx'}
  lifxBuffer_WriteUInt32(buff, pkt->Tx);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Rx'}
  lifxBuffer_WriteUInt32(buff, pkt->Rx);
  // {'size_bytes': 2, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxDecoder_DecodeDeviceStateWifiInfo(lifxDeviceStateWifiInfo_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 17, 'size_bytes': 14, 'fields': [{'size_bytes': 4, 'type': 'float32', 'name': 'Signal'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Tx'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Rx'}, {'size_bytes': 2, 'type': 'reserved'}]}
  // {'size_bytes': 4, 'type': 'float32', 'name': 'Signal'}
  lifxBuffer_ReadFloat(buff, &pkt->Signal);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Tx'}
  lifxBuffer_ReadUInt32(buff, &pkt->Tx);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Rx'}
  lifxBuffer_ReadUInt32(buff, &pkt->Rx);
  // {'size_bytes': 2, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxEncoder_EncodeDeviceSetLabel(lifxDeviceSetLabel_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 24, 'size_bytes': 32, 'fields': [{'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}]}
  lifxBuffer_Init(buff, 32);
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  lifxBuffer_Write(buff, pkt->Label, 32);
  return 0;
}

int lifxDecoder_DecodeDeviceSetLabel(lifxDeviceSetLabel_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 24, 'size_bytes': 32, 'fields': [{'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}]}
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  lifxBuffer_Read(buff, pkt->Label, 32);
  return 0;
}

int lifxEncoder_EncodeDeviceStatePower(lifxDeviceStatePower_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 22, 'size_bytes': 2, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}]}
  lifxBuffer_Init(buff, 2);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  return 0;
}

int lifxDecoder_DecodeDeviceStatePower(lifxDeviceStatePower_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 22, 'size_bytes': 2, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}]}
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
  return 0;
}

int lifxEncoder_EncodeDeviceStateGroup(lifxDeviceStateGroup_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 53, 'size_bytes': 56, 'fields': [{'size_bytes': 16, 'type': '[16]byte', 'name': 'Group'}, {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}]}
  lifxBuffer_Init(buff, 56);
  // {'size_bytes': 16, 'type': '[16]byte', 'name': 'Group'}
  lifxBuffer_Write(buff, pkt->Group, 16);
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return 0;
}

int lifxDecoder_DecodeDeviceStateGroup(lifxDeviceStateGroup_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 53, 'size_bytes': 56, 'fields': [{'size_bytes': 16, 'type': '[16]byte', 'name': 'Group'}, {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}]}
  // {'size_bytes': 16, 'type': '[16]byte', 'name': 'Group'}
  lifxBuffer_Read(buff, pkt->Group, 16);
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  lifxBuffer_Read(buff, pkt->Label, 32);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}
  lifxBuffer_ReadUInt64(buff, &pkt->UpdatedAt);
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

int lifxEncoder_EncodeDeviceStateInfo(lifxDeviceStateInfo_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 35, 'size_bytes': 24, 'fields': [{'size_bytes': 8, 'type': 'uint64', 'name': 'Time'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'Uptime'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'Downtime'}]}
  lifxBuffer_Init(buff, 24);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Time'}
  lifxBuffer_WriteUInt64(buff, pkt->Time);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Uptime'}
  lifxBuffer_WriteUInt64(buff, pkt->Uptime);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Downtime'}
  lifxBuffer_WriteUInt64(buff, pkt->Downtime);
  return 0;
}

int lifxDecoder_DecodeDeviceStateInfo(lifxDeviceStateInfo_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 35, 'size_bytes': 24, 'fields': [{'size_bytes': 8, 'type': 'uint64', 'name': 'Time'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'Uptime'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'Downtime'}]}
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Time'}
  lifxBuffer_ReadUInt64(buff, &pkt->Time);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Uptime'}
  lifxBuffer_ReadUInt64(buff, &pkt->Uptime);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Downtime'}
  lifxBuffer_ReadUInt64(buff, &pkt->Downtime);
  return 0;
}

int lifxEncoder_EncodeDeviceStateHostFirmware(lifxDeviceStateHostFirmware_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 15, 'size_bytes': 20, 'fields': [{'size_bytes': 8, 'type': 'uint64', 'name': 'Build'}, {'size_bytes': 8, 'type': 'reserved'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMinor'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMajor'}]}
  lifxBuffer_Init(buff, 20);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Build'}
  lifxBuffer_WriteUInt64(buff, pkt->Build);
  // {'size_bytes': 8, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 8, kLifxBufferWhenceCurrent);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMinor'}
  lifxBuffer_WriteUInt16(buff, pkt->VersionMinor);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMajor'}
  lifxBuffer_WriteUInt16(buff, pkt->VersionMajor);
  return 0;
}

int lifxDecoder_DecodeDeviceStateHostFirmware(lifxDeviceStateHostFirmware_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 15, 'size_bytes': 20, 'fields': [{'size_bytes': 8, 'type': 'uint64', 'name': 'Build'}, {'size_bytes': 8, 'type': 'reserved'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMinor'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMajor'}]}
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Build'}
  lifxBuffer_ReadUInt64(buff, &pkt->Build);
  // {'size_bytes': 8, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 8, kLifxBufferWhenceCurrent);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMinor'}
  lifxBuffer_ReadUInt16(buff, &pkt->VersionMinor);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMajor'}
  lifxBuffer_ReadUInt16(buff, &pkt->VersionMajor);
  return 0;
}

int lifxEncoder_EncodeDeviceStateLocation(lifxDeviceStateLocation_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 50, 'size_bytes': 56, 'fields': [{'size_bytes': 16, 'type': '[16]byte', 'name': 'Location'}, {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}]}
  lifxBuffer_Init(buff, 56);
  // {'size_bytes': 16, 'type': '[16]byte', 'name': 'Location'}
  lifxBuffer_Write(buff, pkt->Location, 16);
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return 0;
}

int lifxDecoder_DecodeDeviceStateLocation(lifxDeviceStateLocation_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 50, 'size_bytes': 56, 'fields': [{'size_bytes': 16, 'type': '[16]byte', 'name': 'Location'}, {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}]}
  // {'size_bytes': 16, 'type': '[16]byte', 'name': 'Location'}
  lifxBuffer_Read(buff, pkt->Location, 16);
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  lifxBuffer_Read(buff, pkt->Label, 32);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}
  lifxBuffer_ReadUInt64(buff, &pkt->UpdatedAt);
  return 0;
}

int lifxEncoder_EncodeDeviceEchoRequest(lifxDeviceEchoRequest_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 58, 'size_bytes': 64, 'fields': [{'size_bytes': 64, 'type': '[64]byte', 'name': 'Payload'}]}
  lifxBuffer_Init(buff, 64);
  // {'size_bytes': 64, 'type': '[64]byte', 'name': 'Payload'}
  lifxBuffer_Write(buff, pkt->Payload, 64);
  return 0;
}

int lifxDecoder_DecodeDeviceEchoRequest(lifxDeviceEchoRequest_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 58, 'size_bytes': 64, 'fields': [{'size_bytes': 64, 'type': '[64]byte', 'name': 'Payload'}]}
  // {'size_bytes': 64, 'type': '[64]byte', 'name': 'Payload'}
  lifxBuffer_Read(buff, pkt->Payload, 64);
  return 0;
}

int lifxEncoder_EncodeDeviceSetGroup(lifxDeviceSetGroup_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 52, 'size_bytes': 56, 'fields': [{'size_bytes': 16, 'type': '[16]byte', 'name': 'Group'}, {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}]}
  lifxBuffer_Init(buff, 56);
  // {'size_bytes': 16, 'type': '[16]byte', 'name': 'Group'}
  lifxBuffer_Write(buff, pkt->Group, 16);
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return 0;
}

int lifxDecoder_DecodeDeviceSetGroup(lifxDeviceSetGroup_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 52, 'size_bytes': 56, 'fields': [{'size_bytes': 16, 'type': '[16]byte', 'name': 'Group'}, {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}]}
  // {'size_bytes': 16, 'type': '[16]byte', 'name': 'Group'}
  lifxBuffer_Read(buff, pkt->Group, 16);
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  lifxBuffer_Read(buff, pkt->Label, 32);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}
  lifxBuffer_ReadUInt64(buff, &pkt->UpdatedAt);
  return 0;
}

int lifxEncoder_EncodeDeviceSetLocation(lifxDeviceSetLocation_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 49, 'size_bytes': 56, 'fields': [{'size_bytes': 16, 'type': '[16]byte', 'name': 'Location'}, {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}]}
  lifxBuffer_Init(buff, 56);
  // {'size_bytes': 16, 'type': '[16]byte', 'name': 'Location'}
  lifxBuffer_Write(buff, pkt->Location, 16);
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}
  lifxBuffer_WriteUInt64(buff, pkt->UpdatedAt);
  return 0;
}

int lifxDecoder_DecodeDeviceSetLocation(lifxDeviceSetLocation_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 49, 'size_bytes': 56, 'fields': [{'size_bytes': 16, 'type': '[16]byte', 'name': 'Location'}, {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}]}
  // {'size_bytes': 16, 'type': '[16]byte', 'name': 'Location'}
  lifxBuffer_Read(buff, pkt->Location, 16);
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  lifxBuffer_Read(buff, pkt->Label, 32);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}
  lifxBuffer_ReadUInt64(buff, &pkt->UpdatedAt);
  return 0;
}

int lifxEncoder_EncodeDeviceSetPower(lifxDeviceSetPower_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 21, 'size_bytes': 2, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}]}
  lifxBuffer_Init(buff, 2);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  return 0;
}

int lifxDecoder_DecodeDeviceSetPower(lifxDeviceSetPower_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 21, 'size_bytes': 2, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}]}
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
  return 0;
}

int lifxEncoder_EncodeDeviceEchoResponse(lifxDeviceEchoResponse_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 59, 'size_bytes': 64, 'fields': [{'size_bytes': 64, 'type': '[64]byte', 'name': 'Payload'}]}
  lifxBuffer_Init(buff, 64);
  // {'size_bytes': 64, 'type': '[64]byte', 'name': 'Payload'}
  lifxBuffer_Write(buff, pkt->Payload, 64);
  return 0;
}

int lifxDecoder_DecodeDeviceEchoResponse(lifxDeviceEchoResponse_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 59, 'size_bytes': 64, 'fields': [{'size_bytes': 64, 'type': '[64]byte', 'name': 'Payload'}]}
  // {'size_bytes': 64, 'type': '[64]byte', 'name': 'Payload'}
  lifxBuffer_Read(buff, pkt->Payload, 64);
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

int lifxEncoder_EncodeLightStatePower(lifxLightStatePower_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 118, 'size_bytes': 2, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}]}
  lifxBuffer_Init(buff, 2);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  return 0;
}

int lifxDecoder_DecodeLightStatePower(lifxLightStatePower_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 118, 'size_bytes': 2, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}]}
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
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

int lifxEncoder_EncodeLightState(lifxLightState_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 107, 'size_bytes': 52, 'fields': [{'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}, {'size_bytes': 2, 'type': 'reserved'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'Power'}, {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}, {'size_bytes': 8, 'type': 'reserved'}]}
  lifxBuffer_Init(buff, 52);
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxEncoder_EncodeLightHsbk(&pkt->Color, buff);
  // {'size_bytes': 2, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Power'}
  lifxBuffer_WriteUInt16(buff, pkt->Power);
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  lifxBuffer_Write(buff, pkt->Label, 32);
  // {'size_bytes': 8, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 8, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxDecoder_DecodeLightState(lifxLightState_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 107, 'size_bytes': 52, 'fields': [{'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}, {'size_bytes': 2, 'type': 'reserved'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'Power'}, {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}, {'size_bytes': 8, 'type': 'reserved'}]}
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxDecoder_DecodeLightHsbk(&pkt->Color, buff);
  // {'size_bytes': 2, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Power'}
  lifxBuffer_ReadUInt16(buff, &pkt->Power);
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  lifxBuffer_Read(buff, pkt->Label, 32);
  // {'size_bytes': 8, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 8, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxEncoder_EncodeLightSetPower(lifxLightSetPower_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 117, 'size_bytes': 6, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}]}
  lifxBuffer_Init(buff, 6);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}
  lifxBuffer_WriteUInt16(buff, pkt->Level);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  return 0;
}

int lifxDecoder_DecodeLightSetPower(lifxLightSetPower_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 117, 'size_bytes': 6, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}]}
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}
  lifxBuffer_ReadUInt16(buff, &pkt->Level);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  return 0;
}

int lifxEncoder_EncodeLightSetWaveformOptional(lifxLightSetWaveformOptional_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 119, 'size_bytes': 25, 'fields': [{'size_bytes': 1, 'type': 'reserved'}, {'size_bytes': 1, 'type': 'bool', 'name': 'Transient'}, {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Period'}, {'size_bytes': 4, 'type': 'float32', 'name': 'Cycles'}, {'size_bytes': 2, 'type': 'int16', 'name': 'SkewRatio'}, {'size_bytes': 1, 'type': '<LightWaveform>', 'name': 'Waveform'}, {'size_bytes': 1, 'type': 'bool', 'name': 'SetHue'}, {'size_bytes': 1, 'type': 'bool', 'name': 'SetSaturation'}, {'size_bytes': 1, 'type': 'bool', 'name': 'SetBrightness'}, {'size_bytes': 1, 'type': 'bool', 'name': 'SetKelvin'}]}
  lifxBuffer_Init(buff, 25);
  // {'size_bytes': 1, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'size_bytes': 1, 'type': 'bool', 'name': 'Transient'}
  lifxBuffer_WriteBool(buff, pkt->Transient);
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxEncoder_EncodeLightHsbk(&pkt->Color, buff);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Period'}
  lifxBuffer_WriteUInt32(buff, pkt->Period);
  // {'size_bytes': 4, 'type': 'float32', 'name': 'Cycles'}
  lifxBuffer_WriteFloat(buff, pkt->Cycles);
  // {'size_bytes': 2, 'type': 'int16', 'name': 'SkewRatio'}
  lifxBuffer_WriteInt16(buff, pkt->SkewRatio);
  // {'size_bytes': 1, 'type': '<LightWaveform>', 'name': 'Waveform'}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Waveform);
  // {'size_bytes': 1, 'type': 'bool', 'name': 'SetHue'}
  lifxBuffer_WriteBool(buff, pkt->SetHue);
  // {'size_bytes': 1, 'type': 'bool', 'name': 'SetSaturation'}
  lifxBuffer_WriteBool(buff, pkt->SetSaturation);
  // {'size_bytes': 1, 'type': 'bool', 'name': 'SetBrightness'}
  lifxBuffer_WriteBool(buff, pkt->SetBrightness);
  // {'size_bytes': 1, 'type': 'bool', 'name': 'SetKelvin'}
  lifxBuffer_WriteBool(buff, pkt->SetKelvin);
  return 0;
}

int lifxDecoder_DecodeLightSetWaveformOptional(lifxLightSetWaveformOptional_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 119, 'size_bytes': 25, 'fields': [{'size_bytes': 1, 'type': 'reserved'}, {'size_bytes': 1, 'type': 'bool', 'name': 'Transient'}, {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Period'}, {'size_bytes': 4, 'type': 'float32', 'name': 'Cycles'}, {'size_bytes': 2, 'type': 'int16', 'name': 'SkewRatio'}, {'size_bytes': 1, 'type': '<LightWaveform>', 'name': 'Waveform'}, {'size_bytes': 1, 'type': 'bool', 'name': 'SetHue'}, {'size_bytes': 1, 'type': 'bool', 'name': 'SetSaturation'}, {'size_bytes': 1, 'type': 'bool', 'name': 'SetBrightness'}, {'size_bytes': 1, 'type': 'bool', 'name': 'SetKelvin'}]}
  // {'size_bytes': 1, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'size_bytes': 1, 'type': 'bool', 'name': 'Transient'}
  lifxBuffer_ReadBool(buff, &pkt->Transient);
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxDecoder_DecodeLightHsbk(&pkt->Color, buff);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Period'}
  lifxBuffer_ReadUInt32(buff, &pkt->Period);
  // {'size_bytes': 4, 'type': 'float32', 'name': 'Cycles'}
  lifxBuffer_ReadFloat(buff, &pkt->Cycles);
  // {'size_bytes': 2, 'type': 'int16', 'name': 'SkewRatio'}
  lifxBuffer_ReadInt16(buff, &pkt->SkewRatio);
  // {'size_bytes': 1, 'type': '<LightWaveform>', 'name': 'Waveform'}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Waveform);
  // {'size_bytes': 1, 'type': 'bool', 'name': 'SetHue'}
  lifxBuffer_ReadBool(buff, &pkt->SetHue);
  // {'size_bytes': 1, 'type': 'bool', 'name': 'SetSaturation'}
  lifxBuffer_ReadBool(buff, &pkt->SetSaturation);
  // {'size_bytes': 1, 'type': 'bool', 'name': 'SetBrightness'}
  lifxBuffer_ReadBool(buff, &pkt->SetBrightness);
  // {'size_bytes': 1, 'type': 'bool', 'name': 'SetKelvin'}
  lifxBuffer_ReadBool(buff, &pkt->SetKelvin);
  return 0;
}

int lifxEncoder_EncodeLightSetWaveform(lifxLightSetWaveform_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 103, 'size_bytes': 21, 'fields': [{'size_bytes': 1, 'type': 'reserved'}, {'size_bytes': 1, 'type': 'bool', 'name': 'Transient'}, {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Period'}, {'size_bytes': 4, 'type': 'float32', 'name': 'Cycles'}, {'size_bytes': 2, 'type': 'int16', 'name': 'SkewRatio'}, {'size_bytes': 1, 'type': '<LightWaveform>', 'name': 'Waveform'}]}
  lifxBuffer_Init(buff, 21);
  // {'size_bytes': 1, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'size_bytes': 1, 'type': 'bool', 'name': 'Transient'}
  lifxBuffer_WriteBool(buff, pkt->Transient);
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxEncoder_EncodeLightHsbk(&pkt->Color, buff);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Period'}
  lifxBuffer_WriteUInt32(buff, pkt->Period);
  // {'size_bytes': 4, 'type': 'float32', 'name': 'Cycles'}
  lifxBuffer_WriteFloat(buff, pkt->Cycles);
  // {'size_bytes': 2, 'type': 'int16', 'name': 'SkewRatio'}
  lifxBuffer_WriteInt16(buff, pkt->SkewRatio);
  // {'size_bytes': 1, 'type': '<LightWaveform>', 'name': 'Waveform'}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Waveform);
  return 0;
}

int lifxDecoder_DecodeLightSetWaveform(lifxLightSetWaveform_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 103, 'size_bytes': 21, 'fields': [{'size_bytes': 1, 'type': 'reserved'}, {'size_bytes': 1, 'type': 'bool', 'name': 'Transient'}, {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Period'}, {'size_bytes': 4, 'type': 'float32', 'name': 'Cycles'}, {'size_bytes': 2, 'type': 'int16', 'name': 'SkewRatio'}, {'size_bytes': 1, 'type': '<LightWaveform>', 'name': 'Waveform'}]}
  // {'size_bytes': 1, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'size_bytes': 1, 'type': 'bool', 'name': 'Transient'}
  lifxBuffer_ReadBool(buff, &pkt->Transient);
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxDecoder_DecodeLightHsbk(&pkt->Color, buff);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Period'}
  lifxBuffer_ReadUInt32(buff, &pkt->Period);
  // {'size_bytes': 4, 'type': 'float32', 'name': 'Cycles'}
  lifxBuffer_ReadFloat(buff, &pkt->Cycles);
  // {'size_bytes': 2, 'type': 'int16', 'name': 'SkewRatio'}
  lifxBuffer_ReadInt16(buff, &pkt->SkewRatio);
  // {'size_bytes': 1, 'type': '<LightWaveform>', 'name': 'Waveform'}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Waveform);
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

int lifxEncoder_EncodeLightSetInfrared(lifxLightSetInfrared_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 122, 'size_bytes': 2, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Brightness'}]}
  lifxBuffer_Init(buff, 2);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Brightness'}
  lifxBuffer_WriteUInt16(buff, pkt->Brightness);
  return 0;
}

int lifxDecoder_DecodeLightSetInfrared(lifxLightSetInfrared_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 122, 'size_bytes': 2, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Brightness'}]}
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Brightness'}
  lifxBuffer_ReadUInt16(buff, &pkt->Brightness);
  return 0;
}

int lifxEncoder_EncodeLightSetColor(lifxLightSetColor_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 102, 'size_bytes': 13, 'fields': [{'size_bytes': 1, 'type': 'reserved'}, {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}]}
  lifxBuffer_Init(buff, 13);
  // {'size_bytes': 1, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxEncoder_EncodeLightHsbk(&pkt->Color, buff);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  return 0;
}

int lifxDecoder_DecodeLightSetColor(lifxLightSetColor_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 102, 'size_bytes': 13, 'fields': [{'size_bytes': 1, 'type': 'reserved'}, {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}]}
  // {'size_bytes': 1, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxDecoder_DecodeLightHsbk(&pkt->Color, buff);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  return 0;
}

int lifxEncoder_EncodeLightStateInfrared(lifxLightStateInfrared_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 121, 'size_bytes': 2, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Brightness'}]}
  lifxBuffer_Init(buff, 2);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Brightness'}
  lifxBuffer_WriteUInt16(buff, pkt->Brightness);
  return 0;
}

int lifxDecoder_DecodeLightStateInfrared(lifxLightStateInfrared_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 121, 'size_bytes': 2, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Brightness'}]}
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Brightness'}
  lifxBuffer_ReadUInt16(buff, &pkt->Brightness);
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

int lifxEncoder_EncodeTileGetEffect(lifxTileGetEffect_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 718, 'size_bytes': 2, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved0'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved1'}]}
  lifxBuffer_Init(buff, 2);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved0'}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved0);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved1'}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved1);
  return 0;
}

int lifxDecoder_DecodeTileGetEffect(lifxTileGetEffect_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 718, 'size_bytes': 2, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved0'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved1'}]}
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved0'}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved0);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved1'}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved1);
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
  // {'pkt_type': 702, 'size_bytes': 882, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'StartIndex'}, {'size_bytes': 880, 'type': '[16]<TileStateDevice>', 'name': 'TileDevices'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'TileDevicesCount'}]}
  lifxBuffer_Init(buff, 882);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'StartIndex'}
  lifxBuffer_WriteUInt8(buff, pkt->StartIndex);
  // {'size_bytes': 880, 'type': '[16]<TileStateDevice>', 'name': 'TileDevices'}
  lifxEncoder_EncodeTileStateDevice(&pkt->TileDevices, buff);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'TileDevicesCount'}
  lifxBuffer_WriteUInt8(buff, pkt->TileDevicesCount);
  return 0;
}

int lifxDecoder_DecodeTileStateDeviceChain(lifxTileStateDeviceChain_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 702, 'size_bytes': 882, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'StartIndex'}, {'size_bytes': 880, 'type': '[16]<TileStateDevice>', 'name': 'TileDevices'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'TileDevicesCount'}]}
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'StartIndex'}
  lifxBuffer_ReadUInt8(buff, &pkt->StartIndex);
  // {'size_bytes': 880, 'type': '[16]<TileStateDevice>', 'name': 'TileDevices'}
  lifxDecoder_DecodeTileStateDevice(&pkt->TileDevices, buff);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'TileDevicesCount'}
  lifxBuffer_ReadUInt8(buff, &pkt->TileDevicesCount);
  return 0;
}

int lifxEncoder_EncodeTileState64(lifxTileState64_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 711, 'size_bytes': 517, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}, {'size_bytes': 4, 'type': '<TileBufferRect>', 'name': 'Rect'}, {'size_bytes': 512, 'type': '[64]<LightHsbk>', 'name': 'Colors'}]}
  lifxBuffer_Init(buff, 517);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}
  lifxBuffer_WriteUInt8(buff, pkt->TileIndex);
  // {'size_bytes': 4, 'type': '<TileBufferRect>', 'name': 'Rect'}
  lifxEncoder_EncodeTileBufferRect(&pkt->Rect, buff);
  // {'size_bytes': 512, 'type': '[64]<LightHsbk>', 'name': 'Colors'}
  lifxEncoder_EncodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxDecoder_DecodeTileState64(lifxTileState64_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 711, 'size_bytes': 517, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}, {'size_bytes': 4, 'type': '<TileBufferRect>', 'name': 'Rect'}, {'size_bytes': 512, 'type': '[64]<LightHsbk>', 'name': 'Colors'}]}
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}
  lifxBuffer_ReadUInt8(buff, &pkt->TileIndex);
  // {'size_bytes': 4, 'type': '<TileBufferRect>', 'name': 'Rect'}
  lifxDecoder_DecodeTileBufferRect(&pkt->Rect, buff);
  // {'size_bytes': 512, 'type': '[64]<LightHsbk>', 'name': 'Colors'}
  lifxDecoder_DecodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxEncoder_EncodeTileSet64(lifxTileSet64_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 715, 'size_bytes': 522, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Length'}, {'size_bytes': 4, 'type': '<TileBufferRect>', 'name': 'Rect'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}, {'size_bytes': 512, 'type': '[64]<LightHsbk>', 'name': 'Colors'}]}
  lifxBuffer_Init(buff, 522);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}
  lifxBuffer_WriteUInt8(buff, pkt->TileIndex);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Length'}
  lifxBuffer_WriteUInt8(buff, pkt->Length);
  // {'size_bytes': 4, 'type': '<TileBufferRect>', 'name': 'Rect'}
  lifxEncoder_EncodeTileBufferRect(&pkt->Rect, buff);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  // {'size_bytes': 512, 'type': '[64]<LightHsbk>', 'name': 'Colors'}
  lifxEncoder_EncodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxDecoder_DecodeTileSet64(lifxTileSet64_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 715, 'size_bytes': 522, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Length'}, {'size_bytes': 4, 'type': '<TileBufferRect>', 'name': 'Rect'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}, {'size_bytes': 512, 'type': '[64]<LightHsbk>', 'name': 'Colors'}]}
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}
  lifxBuffer_ReadUInt8(buff, &pkt->TileIndex);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Length'}
  lifxBuffer_ReadUInt8(buff, &pkt->Length);
  // {'size_bytes': 4, 'type': '<TileBufferRect>', 'name': 'Rect'}
  lifxDecoder_DecodeTileBufferRect(&pkt->Rect, buff);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  // {'size_bytes': 512, 'type': '[64]<LightHsbk>', 'name': 'Colors'}
  lifxDecoder_DecodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxEncoder_EncodeTileSetUserPosition(lifxTileSetUserPosition_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 703, 'size_bytes': 11, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}, {'size_bytes': 2, 'type': 'reserved'}, {'size_bytes': 4, 'type': 'float32', 'name': 'UserX'}, {'size_bytes': 4, 'type': 'float32', 'name': 'UserY'}]}
  lifxBuffer_Init(buff, 11);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}
  lifxBuffer_WriteUInt8(buff, pkt->TileIndex);
  // {'size_bytes': 2, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'size_bytes': 4, 'type': 'float32', 'name': 'UserX'}
  lifxBuffer_WriteFloat(buff, pkt->UserX);
  // {'size_bytes': 4, 'type': 'float32', 'name': 'UserY'}
  lifxBuffer_WriteFloat(buff, pkt->UserY);
  return 0;
}

int lifxDecoder_DecodeTileSetUserPosition(lifxTileSetUserPosition_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 703, 'size_bytes': 11, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}, {'size_bytes': 2, 'type': 'reserved'}, {'size_bytes': 4, 'type': 'float32', 'name': 'UserX'}, {'size_bytes': 4, 'type': 'float32', 'name': 'UserY'}]}
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}
  lifxBuffer_ReadUInt8(buff, &pkt->TileIndex);
  // {'size_bytes': 2, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'size_bytes': 4, 'type': 'float32', 'name': 'UserX'}
  lifxBuffer_ReadFloat(buff, &pkt->UserX);
  // {'size_bytes': 4, 'type': 'float32', 'name': 'UserY'}
  lifxBuffer_ReadFloat(buff, &pkt->UserY);
  return 0;
}

int lifxEncoder_EncodeTileSetEffect(lifxTileSetEffect_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 719, 'size_bytes': 188, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved0'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved1'}, {'size_bytes': 186, 'type': '<TileEffectSettings>', 'name': 'Settings'}]}
  lifxBuffer_Init(buff, 188);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved0'}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved0);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved1'}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved1);
  // {'size_bytes': 186, 'type': '<TileEffectSettings>', 'name': 'Settings'}
  lifxEncoder_EncodeTileEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxDecoder_DecodeTileSetEffect(lifxTileSetEffect_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 719, 'size_bytes': 188, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved0'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved1'}, {'size_bytes': 186, 'type': '<TileEffectSettings>', 'name': 'Settings'}]}
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved0'}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved0);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved1'}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved1);
  // {'size_bytes': 186, 'type': '<TileEffectSettings>', 'name': 'Settings'}
  lifxDecoder_DecodeTileEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxEncoder_EncodeTileStateEffect(lifxTileStateEffect_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 720, 'size_bytes': 187, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved0'}, {'size_bytes': 186, 'type': '<TileEffectSettings>', 'name': 'Settings'}]}
  lifxBuffer_Init(buff, 187);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved0'}
  lifxBuffer_WriteUInt8(buff, pkt->Reserved0);
  // {'size_bytes': 186, 'type': '<TileEffectSettings>', 'name': 'Settings'}
  lifxEncoder_EncodeTileEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxDecoder_DecodeTileStateEffect(lifxTileStateEffect_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 720, 'size_bytes': 187, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved0'}, {'size_bytes': 186, 'type': '<TileEffectSettings>', 'name': 'Settings'}]}
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved0'}
  lifxBuffer_ReadUInt8(buff, &pkt->Reserved0);
  // {'size_bytes': 186, 'type': '<TileEffectSettings>', 'name': 'Settings'}
  lifxDecoder_DecodeTileEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxEncoder_EncodeTileGet64(lifxTileGet64_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 707, 'size_bytes': 6, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Length'}, {'size_bytes': 4, 'type': '<TileBufferRect>', 'name': 'Rect'}]}
  lifxBuffer_Init(buff, 6);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}
  lifxBuffer_WriteUInt8(buff, pkt->TileIndex);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Length'}
  lifxBuffer_WriteUInt8(buff, pkt->Length);
  // {'size_bytes': 4, 'type': '<TileBufferRect>', 'name': 'Rect'}
  lifxEncoder_EncodeTileBufferRect(&pkt->Rect, buff);
  return 0;
}

int lifxDecoder_DecodeTileGet64(lifxTileGet64_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 707, 'size_bytes': 6, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Length'}, {'size_bytes': 4, 'type': '<TileBufferRect>', 'name': 'Rect'}]}
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}
  lifxBuffer_ReadUInt8(buff, &pkt->TileIndex);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Length'}
  lifxBuffer_ReadUInt8(buff, &pkt->Length);
  // {'size_bytes': 4, 'type': '<TileBufferRect>', 'name': 'Rect'}
  lifxDecoder_DecodeTileBufferRect(&pkt->Rect, buff);
  return 0;
}

int lifxEncoder_EncodeMultiZoneExtendedStateMultiZone(lifxMultiZoneExtendedStateMultiZone_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 512, 'size_bytes': 661, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Count'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'Index'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'ColorsCount'}, {'size_bytes': 656, 'type': '[82]<LightHsbk>', 'name': 'Colors'}]}
  lifxBuffer_Init(buff, 661);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Count'}
  lifxBuffer_WriteUInt16(buff, pkt->Count);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Index'}
  lifxBuffer_WriteUInt16(buff, pkt->Index);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'ColorsCount'}
  lifxBuffer_WriteUInt8(buff, pkt->ColorsCount);
  // {'size_bytes': 656, 'type': '[82]<LightHsbk>', 'name': 'Colors'}
  lifxEncoder_EncodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxDecoder_DecodeMultiZoneExtendedStateMultiZone(lifxMultiZoneExtendedStateMultiZone_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 512, 'size_bytes': 661, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Count'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'Index'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'ColorsCount'}, {'size_bytes': 656, 'type': '[82]<LightHsbk>', 'name': 'Colors'}]}
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Count'}
  lifxBuffer_ReadUInt16(buff, &pkt->Count);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Index'}
  lifxBuffer_ReadUInt16(buff, &pkt->Index);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'ColorsCount'}
  lifxBuffer_ReadUInt8(buff, &pkt->ColorsCount);
  // {'size_bytes': 656, 'type': '[82]<LightHsbk>', 'name': 'Colors'}
  lifxDecoder_DecodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxEncoder_EncodeMultiZoneStateMultiZone(lifxMultiZoneStateMultiZone_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 506, 'size_bytes': 66, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'Count'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Index'}, {'size_bytes': 64, 'type': '[8]<LightHsbk>', 'name': 'Colors'}]}
  lifxBuffer_Init(buff, 66);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Count'}
  lifxBuffer_WriteUInt8(buff, pkt->Count);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Index'}
  lifxBuffer_WriteUInt8(buff, pkt->Index);
  // {'size_bytes': 64, 'type': '[8]<LightHsbk>', 'name': 'Colors'}
  lifxEncoder_EncodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxDecoder_DecodeMultiZoneStateMultiZone(lifxMultiZoneStateMultiZone_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 506, 'size_bytes': 66, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'Count'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Index'}, {'size_bytes': 64, 'type': '[8]<LightHsbk>', 'name': 'Colors'}]}
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Count'}
  lifxBuffer_ReadUInt8(buff, &pkt->Count);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Index'}
  lifxBuffer_ReadUInt8(buff, &pkt->Index);
  // {'size_bytes': 64, 'type': '[8]<LightHsbk>', 'name': 'Colors'}
  lifxDecoder_DecodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxEncoder_EncodeMultiZoneSetColorZones(lifxMultiZoneSetColorZones_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 501, 'size_bytes': 15, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'StartIndex'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'EndIndex'}, {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}, {'size_bytes': 1, 'type': '<MultiZoneApplicationRequest>', 'name': 'Apply'}]}
  lifxBuffer_Init(buff, 15);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'StartIndex'}
  lifxBuffer_WriteUInt8(buff, pkt->StartIndex);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'EndIndex'}
  lifxBuffer_WriteUInt8(buff, pkt->EndIndex);
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxEncoder_EncodeLightHsbk(&pkt->Color, buff);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  // {'size_bytes': 1, 'type': '<MultiZoneApplicationRequest>', 'name': 'Apply'}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Apply);
  return 0;
}

int lifxDecoder_DecodeMultiZoneSetColorZones(lifxMultiZoneSetColorZones_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 501, 'size_bytes': 15, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'StartIndex'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'EndIndex'}, {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}, {'size_bytes': 1, 'type': '<MultiZoneApplicationRequest>', 'name': 'Apply'}]}
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'StartIndex'}
  lifxBuffer_ReadUInt8(buff, &pkt->StartIndex);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'EndIndex'}
  lifxBuffer_ReadUInt8(buff, &pkt->EndIndex);
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxDecoder_DecodeLightHsbk(&pkt->Color, buff);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  // {'size_bytes': 1, 'type': '<MultiZoneApplicationRequest>', 'name': 'Apply'}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Apply);
  return 0;
}

int lifxEncoder_EncodeMultiZoneSetEffect(lifxMultiZoneSetEffect_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 508, 'size_bytes': 59, 'fields': [{'size_bytes': 59, 'type': '<MultiZoneEffectSettings>', 'name': 'Settings'}]}
  lifxBuffer_Init(buff, 59);
  // {'size_bytes': 59, 'type': '<MultiZoneEffectSettings>', 'name': 'Settings'}
  lifxEncoder_EncodeMultiZoneEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxDecoder_DecodeMultiZoneSetEffect(lifxMultiZoneSetEffect_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 508, 'size_bytes': 59, 'fields': [{'size_bytes': 59, 'type': '<MultiZoneEffectSettings>', 'name': 'Settings'}]}
  // {'size_bytes': 59, 'type': '<MultiZoneEffectSettings>', 'name': 'Settings'}
  lifxDecoder_DecodeMultiZoneEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxEncoder_EncodeMultiZoneGetColorZones(lifxMultiZoneGetColorZones_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 502, 'size_bytes': 2, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'StartIndex'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'EndIndex'}]}
  lifxBuffer_Init(buff, 2);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'StartIndex'}
  lifxBuffer_WriteUInt8(buff, pkt->StartIndex);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'EndIndex'}
  lifxBuffer_WriteUInt8(buff, pkt->EndIndex);
  return 0;
}

int lifxDecoder_DecodeMultiZoneGetColorZones(lifxMultiZoneGetColorZones_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 502, 'size_bytes': 2, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'StartIndex'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'EndIndex'}]}
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'StartIndex'}
  lifxBuffer_ReadUInt8(buff, &pkt->StartIndex);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'EndIndex'}
  lifxBuffer_ReadUInt8(buff, &pkt->EndIndex);
  return 0;
}

int lifxEncoder_EncodeMultiZoneStateZone(lifxMultiZoneStateZone_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 503, 'size_bytes': 10, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'Count'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Index'}, {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}]}
  lifxBuffer_Init(buff, 10);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Count'}
  lifxBuffer_WriteUInt8(buff, pkt->Count);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Index'}
  lifxBuffer_WriteUInt8(buff, pkt->Index);
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxEncoder_EncodeLightHsbk(&pkt->Color, buff);
  return 0;
}

int lifxDecoder_DecodeMultiZoneStateZone(lifxMultiZoneStateZone_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 503, 'size_bytes': 10, 'fields': [{'size_bytes': 1, 'type': 'uint8', 'name': 'Count'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Index'}, {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}]}
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Count'}
  lifxBuffer_ReadUInt8(buff, &pkt->Count);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Index'}
  lifxBuffer_ReadUInt8(buff, &pkt->Index);
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxDecoder_DecodeLightHsbk(&pkt->Color, buff);
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

int lifxEncoder_EncodeMultiZoneStateEffect(lifxMultiZoneStateEffect_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 509, 'size_bytes': 59, 'fields': [{'size_bytes': 59, 'type': '<MultiZoneEffectSettings>', 'name': 'Settings'}]}
  lifxBuffer_Init(buff, 59);
  // {'size_bytes': 59, 'type': '<MultiZoneEffectSettings>', 'name': 'Settings'}
  lifxEncoder_EncodeMultiZoneEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxDecoder_DecodeMultiZoneStateEffect(lifxMultiZoneStateEffect_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 509, 'size_bytes': 59, 'fields': [{'size_bytes': 59, 'type': '<MultiZoneEffectSettings>', 'name': 'Settings'}]}
  // {'size_bytes': 59, 'type': '<MultiZoneEffectSettings>', 'name': 'Settings'}
  lifxDecoder_DecodeMultiZoneEffectSettings(&pkt->Settings, buff);
  return 0;
}

int lifxEncoder_EncodeMultiZoneExtendedSetColorZones(lifxMultiZoneExtendedSetColorZones_t const* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 510, 'size_bytes': 664, 'fields': [{'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}, {'size_bytes': 1, 'type': '<MultiZoneExtendedApplicationRequest>', 'name': 'Apply'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'Index'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'ColorsCount'}, {'size_bytes': 656, 'type': '[82]<LightHsbk>', 'name': 'Colors'}]}
  lifxBuffer_Init(buff, 664);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}
  lifxBuffer_WriteUInt32(buff, pkt->Duration);
  // {'size_bytes': 1, 'type': '<MultiZoneExtendedApplicationRequest>', 'name': 'Apply'}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Apply);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Index'}
  lifxBuffer_WriteUInt16(buff, pkt->Index);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'ColorsCount'}
  lifxBuffer_WriteUInt8(buff, pkt->ColorsCount);
  // {'size_bytes': 656, 'type': '[82]<LightHsbk>', 'name': 'Colors'}
  lifxEncoder_EncodeLightHsbk(&pkt->Colors, buff);
  return 0;
}

int lifxDecoder_DecodeMultiZoneExtendedSetColorZones(lifxMultiZoneExtendedSetColorZones_t* pkt, lifxBuffer_t* buff)
{
  // {'pkt_type': 510, 'size_bytes': 664, 'fields': [{'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}, {'size_bytes': 1, 'type': '<MultiZoneExtendedApplicationRequest>', 'name': 'Apply'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'Index'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'ColorsCount'}, {'size_bytes': 656, 'type': '[82]<LightHsbk>', 'name': 'Colors'}]}
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}
  lifxBuffer_ReadUInt32(buff, &pkt->Duration);
  // {'size_bytes': 1, 'type': '<MultiZoneExtendedApplicationRequest>', 'name': 'Apply'}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Apply);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Index'}
  lifxBuffer_ReadUInt16(buff, &pkt->Index);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'ColorsCount'}
  lifxBuffer_ReadUInt8(buff, &pkt->ColorsCount);
  // {'size_bytes': 656, 'type': '[82]<LightHsbk>', 'name': 'Colors'}
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

int lifxEncoder_EncodeTileStateDevice(lifxTileStateDevice_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 55, 'fields': [{'size_bytes': 6, 'type': '<TileAccelMeas>', 'name': 'AccelMeas'}, {'size_bytes': 2, 'type': 'reserved'}, {'size_bytes': 4, 'type': 'float32', 'name': 'UserX'}, {'size_bytes': 4, 'type': 'float32', 'name': 'UserY'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Width'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Height'}, {'size_bytes': 1, 'type': 'reserved'}, {'size_bytes': 12, 'type': '<DeviceStateVersion>', 'name': 'DeviceVersion'}, {'size_bytes': 20, 'type': '<DeviceStateHostFirmware>', 'name': 'Firmware'}, {'size_bytes': 4, 'type': 'reserved'}]}
  lifxBuffer_Init(buff, 55);
  // {'size_bytes': 6, 'type': '<TileAccelMeas>', 'name': 'AccelMeas'}
  lifxEncoder_EncodeTileAccelMeas(&pkt->AccelMeas, buff);
  // {'size_bytes': 2, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'size_bytes': 4, 'type': 'float32', 'name': 'UserX'}
  lifxBuffer_WriteFloat(buff, pkt->UserX);
  // {'size_bytes': 4, 'type': 'float32', 'name': 'UserY'}
  lifxBuffer_WriteFloat(buff, pkt->UserY);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Width'}
  lifxBuffer_WriteUInt8(buff, pkt->Width);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Height'}
  lifxBuffer_WriteUInt8(buff, pkt->Height);
  // {'size_bytes': 1, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'size_bytes': 12, 'type': '<DeviceStateVersion>', 'name': 'DeviceVersion'}
  lifxEncoder_EncodeDeviceStateVersion(&pkt->DeviceVersion, buff);
  // {'size_bytes': 20, 'type': '<DeviceStateHostFirmware>', 'name': 'Firmware'}
  lifxEncoder_EncodeDeviceStateHostFirmware(&pkt->Firmware, buff);
  // {'size_bytes': 4, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 4, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxDecoder_DecodeTileStateDevice(lifxTileStateDevice_t* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 55, 'fields': [{'size_bytes': 6, 'type': '<TileAccelMeas>', 'name': 'AccelMeas'}, {'size_bytes': 2, 'type': 'reserved'}, {'size_bytes': 4, 'type': 'float32', 'name': 'UserX'}, {'size_bytes': 4, 'type': 'float32', 'name': 'UserY'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Width'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Height'}, {'size_bytes': 1, 'type': 'reserved'}, {'size_bytes': 12, 'type': '<DeviceStateVersion>', 'name': 'DeviceVersion'}, {'size_bytes': 20, 'type': '<DeviceStateHostFirmware>', 'name': 'Firmware'}, {'size_bytes': 4, 'type': 'reserved'}]}
  // {'size_bytes': 6, 'type': '<TileAccelMeas>', 'name': 'AccelMeas'}
  lifxDecoder_DecodeTileAccelMeas(&pkt->AccelMeas, buff);
  // {'size_bytes': 2, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'size_bytes': 4, 'type': 'float32', 'name': 'UserX'}
  lifxBuffer_ReadFloat(buff, &pkt->UserX);
  // {'size_bytes': 4, 'type': 'float32', 'name': 'UserY'}
  lifxBuffer_ReadFloat(buff, &pkt->UserY);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Width'}
  lifxBuffer_ReadUInt8(buff, &pkt->Width);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Height'}
  lifxBuffer_ReadUInt8(buff, &pkt->Height);
  // {'size_bytes': 1, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'size_bytes': 12, 'type': '<DeviceStateVersion>', 'name': 'DeviceVersion'}
  lifxDecoder_DecodeDeviceStateVersion(&pkt->DeviceVersion, buff);
  // {'size_bytes': 20, 'type': '<DeviceStateHostFirmware>', 'name': 'Firmware'}
  lifxDecoder_DecodeDeviceStateHostFirmware(&pkt->Firmware, buff);
  // {'size_bytes': 4, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 4, kLifxBufferWhenceCurrent);
  return 0;
}

int lifxEncoder_EncodeTileEffectSettings(lifxTileEffectSettings_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 186, 'fields': [{'size_bytes': 4, 'type': 'uint32', 'name': 'Instanceid'}, {'size_bytes': 1, 'type': '<TileEffectType>', 'name': 'Type'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Speed'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'Duration'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Reserved0'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Reserved1'}, {'size_bytes': 32, 'type': '<TileEffectParameter>', 'name': 'Parameter'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'PaletteCount'}, {'size_bytes': 128, 'type': '[16]<LightHsbk>', 'name': 'Palette'}]}
  lifxBuffer_Init(buff, 186);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Instanceid'}
  lifxBuffer_WriteUInt32(buff, pkt->Instanceid);
  // {'size_bytes': 1, 'type': '<TileEffectType>', 'name': 'Type'}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Type);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Speed'}
  lifxBuffer_WriteUInt32(buff, pkt->Speed);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Duration'}
  lifxBuffer_WriteUInt64(buff, pkt->Duration);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Reserved0'}
  lifxBuffer_WriteUInt32(buff, pkt->Reserved0);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Reserved1'}
  lifxBuffer_WriteUInt32(buff, pkt->Reserved1);
  // {'size_bytes': 32, 'type': '<TileEffectParameter>', 'name': 'Parameter'}
  lifxEncoder_EncodeTileEffectParameter(&pkt->Parameter, buff);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'PaletteCount'}
  lifxBuffer_WriteUInt8(buff, pkt->PaletteCount);
  // {'size_bytes': 128, 'type': '[16]<LightHsbk>', 'name': 'Palette'}
  lifxEncoder_EncodeLightHsbk(&pkt->Palette, buff);
  return 0;
}

int lifxDecoder_DecodeTileEffectSettings(lifxTileEffectSettings_t* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 186, 'fields': [{'size_bytes': 4, 'type': 'uint32', 'name': 'Instanceid'}, {'size_bytes': 1, 'type': '<TileEffectType>', 'name': 'Type'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Speed'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'Duration'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Reserved0'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Reserved1'}, {'size_bytes': 32, 'type': '<TileEffectParameter>', 'name': 'Parameter'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'PaletteCount'}, {'size_bytes': 128, 'type': '[16]<LightHsbk>', 'name': 'Palette'}]}
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Instanceid'}
  lifxBuffer_ReadUInt32(buff, &pkt->Instanceid);
  // {'size_bytes': 1, 'type': '<TileEffectType>', 'name': 'Type'}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Type);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Speed'}
  lifxBuffer_ReadUInt32(buff, &pkt->Speed);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Duration'}
  lifxBuffer_ReadUInt64(buff, &pkt->Duration);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Reserved0'}
  lifxBuffer_ReadUInt32(buff, &pkt->Reserved0);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Reserved1'}
  lifxBuffer_ReadUInt32(buff, &pkt->Reserved1);
  // {'size_bytes': 32, 'type': '<TileEffectParameter>', 'name': 'Parameter'}
  lifxDecoder_DecodeTileEffectParameter(&pkt->Parameter, buff);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'PaletteCount'}
  lifxBuffer_ReadUInt8(buff, &pkt->PaletteCount);
  // {'size_bytes': 128, 'type': '[16]<LightHsbk>', 'name': 'Palette'}
  lifxDecoder_DecodeLightHsbk(&pkt->Palette, buff);
  return 0;
}

int lifxEncoder_EncodeMultiZoneEffectParameter(lifxMultiZoneEffectParameter_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 32, 'fields': [{'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter0'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter1'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter2'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter3'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter4'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter5'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter6'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter7'}]}
  lifxBuffer_Init(buff, 32);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter0'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter0);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter1'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter1);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter2'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter2);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter3'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter3);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter4'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter4);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter5'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter5);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter6'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter6);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter7'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter7);
  return 0;
}

int lifxDecoder_DecodeMultiZoneEffectParameter(lifxMultiZoneEffectParameter_t* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 32, 'fields': [{'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter0'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter1'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter2'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter3'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter4'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter5'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter6'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter7'}]}
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter0'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter0);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter1'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter1);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter2'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter2);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter3'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter3);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter4'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter4);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter5'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter5);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter6'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter6);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter7'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter7);
  return 0;
}

int lifxEncoder_EncodeTileAccelMeas(lifxTileAccelMeas_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 6, 'fields': [{'size_bytes': 2, 'type': 'int16', 'name': 'X'}, {'size_bytes': 2, 'type': 'int16', 'name': 'Y'}, {'size_bytes': 2, 'type': 'int16', 'name': 'Z'}]}
  lifxBuffer_Init(buff, 6);
  // {'size_bytes': 2, 'type': 'int16', 'name': 'X'}
  lifxBuffer_WriteInt16(buff, pkt->X);
  // {'size_bytes': 2, 'type': 'int16', 'name': 'Y'}
  lifxBuffer_WriteInt16(buff, pkt->Y);
  // {'size_bytes': 2, 'type': 'int16', 'name': 'Z'}
  lifxBuffer_WriteInt16(buff, pkt->Z);
  return 0;
}

int lifxDecoder_DecodeTileAccelMeas(lifxTileAccelMeas_t* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 6, 'fields': [{'size_bytes': 2, 'type': 'int16', 'name': 'X'}, {'size_bytes': 2, 'type': 'int16', 'name': 'Y'}, {'size_bytes': 2, 'type': 'int16', 'name': 'Z'}]}
  // {'size_bytes': 2, 'type': 'int16', 'name': 'X'}
  lifxBuffer_ReadInt16(buff, &pkt->X);
  // {'size_bytes': 2, 'type': 'int16', 'name': 'Y'}
  lifxBuffer_ReadInt16(buff, &pkt->Y);
  // {'size_bytes': 2, 'type': 'int16', 'name': 'Z'}
  lifxBuffer_ReadInt16(buff, &pkt->Z);
  return 0;
}

int lifxEncoder_EncodeLightHsbk(lifxLightHsbk_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 8, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Hue'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'Saturation'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'Brightness'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'Kelvin'}]}
  lifxBuffer_Init(buff, 8);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Hue'}
  lifxBuffer_WriteUInt16(buff, pkt->Hue);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Saturation'}
  lifxBuffer_WriteUInt16(buff, pkt->Saturation);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Brightness'}
  lifxBuffer_WriteUInt16(buff, pkt->Brightness);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Kelvin'}
  lifxBuffer_WriteUInt16(buff, pkt->Kelvin);
  return 0;
}

int lifxDecoder_DecodeLightHsbk(lifxLightHsbk_t* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 8, 'fields': [{'size_bytes': 2, 'type': 'uint16', 'name': 'Hue'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'Saturation'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'Brightness'}, {'size_bytes': 2, 'type': 'uint16', 'name': 'Kelvin'}]}
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Hue'}
  lifxBuffer_ReadUInt16(buff, &pkt->Hue);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Saturation'}
  lifxBuffer_ReadUInt16(buff, &pkt->Saturation);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Brightness'}
  lifxBuffer_ReadUInt16(buff, &pkt->Brightness);
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Kelvin'}
  lifxBuffer_ReadUInt16(buff, &pkt->Kelvin);
  return 0;
}

int lifxEncoder_EncodeMultiZoneEffectSettings(lifxMultiZoneEffectSettings_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 59, 'fields': [{'size_bytes': 4, 'type': 'uint32', 'name': 'Instanceid'}, {'size_bytes': 1, 'type': '<MultiZoneEffectType>', 'name': 'Type'}, {'size_bytes': 2, 'type': 'reserved'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Speed'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'Duration'}, {'size_bytes': 4, 'type': 'reserved'}, {'size_bytes': 4, 'type': 'reserved'}, {'size_bytes': 32, 'type': '<MultiZoneEffectParameter>', 'name': 'Parameter'}]}
  lifxBuffer_Init(buff, 59);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Instanceid'}
  lifxBuffer_WriteUInt32(buff, pkt->Instanceid);
  // {'size_bytes': 1, 'type': '<MultiZoneEffectType>', 'name': 'Type'}
  lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->Type);
  // {'size_bytes': 2, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Speed'}
  lifxBuffer_WriteUInt32(buff, pkt->Speed);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Duration'}
  lifxBuffer_WriteUInt64(buff, pkt->Duration);
  // {'size_bytes': 4, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 4, kLifxBufferWhenceCurrent);
  // {'size_bytes': 4, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 4, kLifxBufferWhenceCurrent);
  // {'size_bytes': 32, 'type': '<MultiZoneEffectParameter>', 'name': 'Parameter'}
  lifxEncoder_EncodeMultiZoneEffectParameter(&pkt->Parameter, buff);
  return 0;
}

int lifxDecoder_DecodeMultiZoneEffectSettings(lifxMultiZoneEffectSettings_t* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 59, 'fields': [{'size_bytes': 4, 'type': 'uint32', 'name': 'Instanceid'}, {'size_bytes': 1, 'type': '<MultiZoneEffectType>', 'name': 'Type'}, {'size_bytes': 2, 'type': 'reserved'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Speed'}, {'size_bytes': 8, 'type': 'uint64', 'name': 'Duration'}, {'size_bytes': 4, 'type': 'reserved'}, {'size_bytes': 4, 'type': 'reserved'}, {'size_bytes': 32, 'type': '<MultiZoneEffectParameter>', 'name': 'Parameter'}]}
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Instanceid'}
  lifxBuffer_ReadUInt32(buff, &pkt->Instanceid);
  // {'size_bytes': 1, 'type': '<MultiZoneEffectType>', 'name': 'Type'}
  lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->Type);
  // {'size_bytes': 2, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 2, kLifxBufferWhenceCurrent);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Speed'}
  lifxBuffer_ReadUInt32(buff, &pkt->Speed);
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Duration'}
  lifxBuffer_ReadUInt64(buff, &pkt->Duration);
  // {'size_bytes': 4, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 4, kLifxBufferWhenceCurrent);
  // {'size_bytes': 4, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 4, kLifxBufferWhenceCurrent);
  // {'size_bytes': 32, 'type': '<MultiZoneEffectParameter>', 'name': 'Parameter'}
  lifxDecoder_DecodeMultiZoneEffectParameter(&pkt->Parameter, buff);
  return 0;
}

int lifxEncoder_EncodeTileEffectParameter(lifxTileEffectParameter_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 32, 'fields': [{'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter0'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter1'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter2'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter3'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter4'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter5'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter6'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter7'}]}
  lifxBuffer_Init(buff, 32);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter0'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter0);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter1'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter1);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter2'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter2);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter3'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter3);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter4'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter4);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter5'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter5);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter6'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter6);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter7'}
  lifxBuffer_WriteUInt32(buff, pkt->Parameter7);
  return 0;
}

int lifxDecoder_DecodeTileEffectParameter(lifxTileEffectParameter_t* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 32, 'fields': [{'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter0'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter1'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter2'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter3'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter4'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter5'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter6'}, {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter7'}]}
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter0'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter0);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter1'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter1);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter2'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter2);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter3'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter3);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter4'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter4);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter5'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter5);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter6'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter6);
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter7'}
  lifxBuffer_ReadUInt32(buff, &pkt->Parameter7);
  return 0;
}

int lifxEncoder_EncodeTileBufferRect(lifxTileBufferRect_t const* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 4, 'fields': [{'size_bytes': 1, 'type': 'reserved'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'X'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Y'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Width'}]}
  lifxBuffer_Init(buff, 4);
  // {'size_bytes': 1, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'X'}
  lifxBuffer_WriteUInt8(buff, pkt->X);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Y'}
  lifxBuffer_WriteUInt8(buff, pkt->Y);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Width'}
  lifxBuffer_WriteUInt8(buff, pkt->Width);
  return 0;
}

int lifxDecoder_DecodeTileBufferRect(lifxTileBufferRect_t* pkt, lifxBuffer_t* buff)
{
  // {'size_bytes': 4, 'fields': [{'size_bytes': 1, 'type': 'reserved'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'X'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Y'}, {'size_bytes': 1, 'type': 'uint8', 'name': 'Width'}]}
  // {'size_bytes': 1, 'type': 'reserved'}
  lifxBuffer_Seek(buff, 1, kLifxBufferWhenceCurrent);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'X'}
  lifxBuffer_ReadUInt8(buff, &pkt->X);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Y'}
  lifxBuffer_ReadUInt8(buff, &pkt->Y);
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Width'}
  lifxBuffer_ReadUInt8(buff, &pkt->Width);
  return 0;
}

