//
// DO NOT EDIT - AUTO-GENERATE:2020-02-10 14:58:43.460015
//
#ifndef __LIFX_PACKETS_H__
#define __LIFX_PACKETS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <lifx_enums.h>
#include <lifx_fields.h>

typedef enum {
  kLifxPacketTypeDeviceGetService = 2,
  kLifxPacketTypeDeviceStateService = 3,
  kLifxPacketTypeDeviceGetHostInfo = 12,
  kLifxPacketTypeDeviceStateHostInfo = 13,
  kLifxPacketTypeDeviceGetHostFirmware = 14,
  kLifxPacketTypeDeviceStateHostFirmware = 15,
  kLifxPacketTypeDeviceGetWifiInfo = 16,
  kLifxPacketTypeDeviceStateWifiInfo = 17,
  kLifxPacketTypeDeviceGetWifiFirmware = 18,
  kLifxPacketTypeDeviceStateWifiFirmware = 19,
  kLifxPacketTypeDeviceGetPower = 20,
  kLifxPacketTypeDeviceSetPower = 21,
  kLifxPacketTypeDeviceStatePower = 22,
  kLifxPacketTypeDeviceGetLabel = 23,
  kLifxPacketTypeDeviceSetLabel = 24,
  kLifxPacketTypeDeviceStateLabel = 25,
  kLifxPacketTypeDeviceGetVersion = 32,
  kLifxPacketTypeDeviceStateVersion = 33,
  kLifxPacketTypeDeviceGetInfo = 34,
  kLifxPacketTypeDeviceStateInfo = 35,
  kLifxPacketTypeDeviceAcknowledgement = 45,
  kLifxPacketTypeDeviceGetLocation = 48,
  kLifxPacketTypeDeviceSetLocation = 49,
  kLifxPacketTypeDeviceStateLocation = 50,
  kLifxPacketTypeDeviceGetGroup = 51,
  kLifxPacketTypeDeviceSetGroup = 52,
  kLifxPacketTypeDeviceStateGroup = 53,
  kLifxPacketTypeDeviceEchoRequest = 58,
  kLifxPacketTypeDeviceEchoResponse = 59,
  kLifxPacketTypeLightGet = 101,
  kLifxPacketTypeLightSetColor = 102,
  kLifxPacketTypeLightSetWaveform = 103,
  kLifxPacketTypeLightState = 107,
  kLifxPacketTypeLightGetPower = 116,
  kLifxPacketTypeLightSetPower = 117,
  kLifxPacketTypeLightStatePower = 118,
  kLifxPacketTypeLightSetWaveformOptional = 119,
  kLifxPacketTypeLightGetInfrared = 120,
  kLifxPacketTypeLightStateInfrared = 121,
  kLifxPacketTypeLightSetInfrared = 122,
  kLifxPacketTypeMultiZoneSetColorZones = 501,
  kLifxPacketTypeMultiZoneGetColorZones = 502,
  kLifxPacketTypeMultiZoneStateZone = 503,
  kLifxPacketTypeMultiZoneStateMultiZone = 506,
  kLifxPacketTypeMultiZoneGetEffect = 507,
  kLifxPacketTypeMultiZoneSetEffect = 508,
  kLifxPacketTypeMultiZoneStateEffect = 509,
  kLifxPacketTypeMultiZoneExtendedSetColorZones = 510,
  kLifxPacketTypeMultiZoneExtendedGetColorZones = 511,
  kLifxPacketTypeMultiZoneExtendedStateMultiZone = 512,
  kLifxPacketTypeTileGetDeviceChain = 701,
  kLifxPacketTypeTileStateDeviceChain = 702,
  kLifxPacketTypeTileSetUserPosition = 703,
  kLifxPacketTypeTileGet64 = 707,
  kLifxPacketTypeTileState64 = 711,
  kLifxPacketTypeTileSet64 = 715,
  kLifxPacketTypeTileGetEffect = 718,
  kLifxPacketTypeTileSetEffect = 719,
  kLifxPacketTypeTileStateEffect = 720  
} lifxPacketType_t;


// {'pkt_type': 45, 'size_bytes': 0}
typedef struct {
} lifxDeviceAcknowledgement_t;

// {'pkt_type': 3, 'size_bytes': 5}
typedef struct {
  // {'size_bytes': 1, 'type': '<DeviceService>', 'name': 'Service'}
  lifxDeviceService_t Service;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Port'}
  uint32_t Port;
} lifxDeviceStateService_t;

// {'pkt_type': 14, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetHostFirmware_t;

// {'pkt_type': 13, 'size_bytes': 14}
typedef struct {
  // {'size_bytes': 4, 'type': 'float32', 'name': 'Signal'}
  float Signal;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Tx'}
  uint32_t Tx;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Rx'}
  uint32_t Rx;
  // {'size_bytes': 2, 'type': 'reserved'}
  uint8_t pad3[2];
} lifxDeviceStateHostInfo_t;

// {'pkt_type': 23, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetLabel_t;

// {'pkt_type': 16, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetWifiInfo_t;

// {'pkt_type': 25, 'size_bytes': 32}
typedef struct {
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  uint8_t Label[32];
} lifxDeviceStateLabel_t;

// {'pkt_type': 48, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetLocation_t;

// {'pkt_type': 20, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetPower_t;

// {'pkt_type': 12, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetHostInfo_t;

// {'pkt_type': 19, 'size_bytes': 20}
typedef struct {
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Build'}
  uint64_t Build;
  // {'size_bytes': 8, 'type': 'reserved'}
  uint8_t pad1[8];
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMinor'}
  uint16_t VersionMinor;
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMajor'}
  uint16_t VersionMajor;
} lifxDeviceStateWifiFirmware_t;

// HACK: DeviceStateVersion is in lifx_fields.h

// {'pkt_type': 32, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetVersion_t;

// {'pkt_type': 34, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetInfo_t;

// {'pkt_type': 17, 'size_bytes': 14}
typedef struct {
  // {'size_bytes': 4, 'type': 'float32', 'name': 'Signal'}
  float Signal;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Tx'}
  uint32_t Tx;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Rx'}
  uint32_t Rx;
  // {'size_bytes': 2, 'type': 'reserved'}
  uint8_t pad3[2];
} lifxDeviceStateWifiInfo_t;

// {'pkt_type': 24, 'size_bytes': 32}
typedef struct {
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  uint8_t Label[32];
} lifxDeviceSetLabel_t;

// {'pkt_type': 22, 'size_bytes': 2}
typedef struct {
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}
  uint16_t Level;
} lifxDeviceStatePower_t;

// {'pkt_type': 53, 'size_bytes': 56}
typedef struct {
  // {'size_bytes': 16, 'type': '[16]byte', 'name': 'Group'}
  uint8_t Group[16];
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  uint8_t Label[32];
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}
  uint64_t UpdatedAt;
} lifxDeviceStateGroup_t;

// {'pkt_type': 18, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetWifiFirmware_t;

// {'pkt_type': 35, 'size_bytes': 24}
typedef struct {
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Time'}
  uint64_t Time;
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Uptime'}
  uint64_t Uptime;
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Downtime'}
  uint64_t Downtime;
} lifxDeviceStateInfo_t;

// HACK: DeviceStateHostFirmware is in lifx_fields.h

// {'pkt_type': 50, 'size_bytes': 56}
typedef struct {
  // {'size_bytes': 16, 'type': '[16]byte', 'name': 'Location'}
  uint8_t Location[16];
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  uint8_t Label[32];
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}
  uint64_t UpdatedAt;
} lifxDeviceStateLocation_t;

// {'pkt_type': 58, 'size_bytes': 64}
typedef struct {
  // {'size_bytes': 64, 'type': '[64]byte', 'name': 'Payload'}
  uint8_t Payload[64];
} lifxDeviceEchoRequest_t;

// {'pkt_type': 52, 'size_bytes': 56}
typedef struct {
  // {'size_bytes': 16, 'type': '[16]byte', 'name': 'Group'}
  uint8_t Group[16];
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  uint8_t Label[32];
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}
  uint64_t UpdatedAt;
} lifxDeviceSetGroup_t;

// {'pkt_type': 49, 'size_bytes': 56}
typedef struct {
  // {'size_bytes': 16, 'type': '[16]byte', 'name': 'Location'}
  uint8_t Location[16];
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  uint8_t Label[32];
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'UpdatedAt'}
  uint64_t UpdatedAt;
} lifxDeviceSetLocation_t;

// {'pkt_type': 21, 'size_bytes': 2}
typedef struct {
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}
  uint16_t Level;
} lifxDeviceSetPower_t;

// {'pkt_type': 59, 'size_bytes': 64}
typedef struct {
  // {'size_bytes': 64, 'type': '[64]byte', 'name': 'Payload'}
  uint8_t Payload[64];
} lifxDeviceEchoResponse_t;

// {'pkt_type': 51, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetGroup_t;

// {'pkt_type': 2, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetService_t;

// {'pkt_type': 118, 'size_bytes': 2}
typedef struct {
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}
  uint16_t Level;
} lifxLightStatePower_t;

// {'pkt_type': 120, 'size_bytes': 0}
typedef struct {
} lifxLightGetInfrared_t;

// {'pkt_type': 107, 'size_bytes': 52}
typedef struct {
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxLightHsbk_t Color;
  // {'size_bytes': 2, 'type': 'reserved'}
  uint8_t pad1[2];
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Power'}
  uint16_t Power;
  // {'size_bytes': 32, 'type': '[32]byte', 'name': 'Label'}
  uint8_t Label[32];
  // {'size_bytes': 8, 'type': 'reserved'}
  uint8_t pad4[8];
} lifxLightState_t;

// {'pkt_type': 117, 'size_bytes': 6}
typedef struct {
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Level'}
  uint16_t Level;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}
  uint32_t Duration;
} lifxLightSetPower_t;

// {'pkt_type': 119, 'size_bytes': 25}
typedef struct {
  // {'size_bytes': 1, 'type': 'reserved'}
  uint8_t pad0;
  // {'size_bytes': 1, 'type': 'bool', 'name': 'Transient'}
  bool Transient;
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxLightHsbk_t Color;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Period'}
  uint32_t Period;
  // {'size_bytes': 4, 'type': 'float32', 'name': 'Cycles'}
  float Cycles;
  // {'size_bytes': 2, 'type': 'int16', 'name': 'SkewRatio'}
  int16_t SkewRatio;
  // {'size_bytes': 1, 'type': '<LightWaveform>', 'name': 'Waveform'}
  lifxLightWaveform_t Waveform;
  // {'size_bytes': 1, 'type': 'bool', 'name': 'SetHue'}
  bool SetHue;
  // {'size_bytes': 1, 'type': 'bool', 'name': 'SetSaturation'}
  bool SetSaturation;
  // {'size_bytes': 1, 'type': 'bool', 'name': 'SetBrightness'}
  bool SetBrightness;
  // {'size_bytes': 1, 'type': 'bool', 'name': 'SetKelvin'}
  bool SetKelvin;
} lifxLightSetWaveformOptional_t;

// {'pkt_type': 103, 'size_bytes': 21}
typedef struct {
  // {'size_bytes': 1, 'type': 'reserved'}
  uint8_t pad0;
  // {'size_bytes': 1, 'type': 'bool', 'name': 'Transient'}
  bool Transient;
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxLightHsbk_t Color;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Period'}
  uint32_t Period;
  // {'size_bytes': 4, 'type': 'float32', 'name': 'Cycles'}
  float Cycles;
  // {'size_bytes': 2, 'type': 'int16', 'name': 'SkewRatio'}
  int16_t SkewRatio;
  // {'size_bytes': 1, 'type': '<LightWaveform>', 'name': 'Waveform'}
  lifxLightWaveform_t Waveform;
} lifxLightSetWaveform_t;

// {'pkt_type': 101, 'size_bytes': 0}
typedef struct {
} lifxLightGet_t;

// {'pkt_type': 122, 'size_bytes': 2}
typedef struct {
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Brightness'}
  uint16_t Brightness;
} lifxLightSetInfrared_t;

// {'pkt_type': 102, 'size_bytes': 13}
typedef struct {
  // {'size_bytes': 1, 'type': 'reserved'}
  uint8_t pad0;
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxLightHsbk_t Color;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}
  uint32_t Duration;
} lifxLightSetColor_t;

// {'pkt_type': 121, 'size_bytes': 2}
typedef struct {
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Brightness'}
  uint16_t Brightness;
} lifxLightStateInfrared_t;

// {'pkt_type': 116, 'size_bytes': 0}
typedef struct {
} lifxLightGetPower_t;

// {'pkt_type': 718, 'size_bytes': 2}
typedef struct {
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved0'}
  uint8_t Reserved0;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved1'}
  uint8_t Reserved1;
} lifxTileGetEffect_t;

// {'pkt_type': 701, 'size_bytes': 0}
typedef struct {
} lifxTileGetDeviceChain_t;

// {'pkt_type': 702, 'size_bytes': 882}
typedef struct {
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'StartIndex'}
  uint8_t StartIndex;
  // {'size_bytes': 880, 'type': '[16]<TileStateDevice>', 'name': 'TileDevices'}
  lifxTileStateDevice_t TileDevices;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'TileDevicesCount'}
  uint8_t TileDevicesCount;
} lifxTileStateDeviceChain_t;

// {'pkt_type': 711, 'size_bytes': 517}
typedef struct {
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}
  uint8_t TileIndex;
  // {'size_bytes': 4, 'type': '<TileBufferRect>', 'name': 'Rect'}
  lifxTileBufferRect_t Rect;
  // {'size_bytes': 512, 'type': '[64]<LightHsbk>', 'name': 'Colors'}
  lifxLightHsbk_t Colors;
} lifxTileState64_t;

// {'pkt_type': 715, 'size_bytes': 522}
typedef struct {
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}
  uint8_t TileIndex;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Length'}
  uint8_t Length;
  // {'size_bytes': 4, 'type': '<TileBufferRect>', 'name': 'Rect'}
  lifxTileBufferRect_t Rect;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}
  uint32_t Duration;
  // {'size_bytes': 512, 'type': '[64]<LightHsbk>', 'name': 'Colors'}
  lifxLightHsbk_t Colors;
} lifxTileSet64_t;

// {'pkt_type': 703, 'size_bytes': 11}
typedef struct {
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}
  uint8_t TileIndex;
  // {'size_bytes': 2, 'type': 'reserved'}
  uint8_t pad1[2];
  // {'size_bytes': 4, 'type': 'float32', 'name': 'UserX'}
  float UserX;
  // {'size_bytes': 4, 'type': 'float32', 'name': 'UserY'}
  float UserY;
} lifxTileSetUserPosition_t;

// {'pkt_type': 719, 'size_bytes': 188}
typedef struct {
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved0'}
  uint8_t Reserved0;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved1'}
  uint8_t Reserved1;
  // {'size_bytes': 186, 'type': '<TileEffectSettings>', 'name': 'Settings'}
  lifxTileEffectSettings_t Settings;
} lifxTileSetEffect_t;

// {'pkt_type': 720, 'size_bytes': 187}
typedef struct {
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Reserved0'}
  uint8_t Reserved0;
  // {'size_bytes': 186, 'type': '<TileEffectSettings>', 'name': 'Settings'}
  lifxTileEffectSettings_t Settings;
} lifxTileStateEffect_t;

// {'pkt_type': 707, 'size_bytes': 6}
typedef struct {
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'TileIndex'}
  uint8_t TileIndex;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Length'}
  uint8_t Length;
  // {'size_bytes': 4, 'type': '<TileBufferRect>', 'name': 'Rect'}
  lifxTileBufferRect_t Rect;
} lifxTileGet64_t;

// {'pkt_type': 512, 'size_bytes': 661}
typedef struct {
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Count'}
  uint16_t Count;
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Index'}
  uint16_t Index;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'ColorsCount'}
  uint8_t ColorsCount;
  // {'size_bytes': 656, 'type': '[82]<LightHsbk>', 'name': 'Colors'}
  lifxLightHsbk_t Colors;
} lifxMultiZoneExtendedStateMultiZone_t;

// {'pkt_type': 506, 'size_bytes': 66}
typedef struct {
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Count'}
  uint8_t Count;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Index'}
  uint8_t Index;
  // {'size_bytes': 64, 'type': '[8]<LightHsbk>', 'name': 'Colors'}
  lifxLightHsbk_t Colors;
} lifxMultiZoneStateMultiZone_t;

// {'pkt_type': 501, 'size_bytes': 15}
typedef struct {
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'StartIndex'}
  uint8_t StartIndex;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'EndIndex'}
  uint8_t EndIndex;
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxLightHsbk_t Color;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}
  uint32_t Duration;
  // {'size_bytes': 1, 'type': '<MultiZoneApplicationRequest>', 'name': 'Apply'}
  lifxMultiZoneApplicationRequest_t Apply;
} lifxMultiZoneSetColorZones_t;

// {'pkt_type': 508, 'size_bytes': 59}
typedef struct {
  // {'size_bytes': 59, 'type': '<MultiZoneEffectSettings>', 'name': 'Settings'}
  lifxMultiZoneEffectSettings_t Settings;
} lifxMultiZoneSetEffect_t;

// {'pkt_type': 502, 'size_bytes': 2}
typedef struct {
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'StartIndex'}
  uint8_t StartIndex;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'EndIndex'}
  uint8_t EndIndex;
} lifxMultiZoneGetColorZones_t;

// {'pkt_type': 503, 'size_bytes': 10}
typedef struct {
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Count'}
  uint8_t Count;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Index'}
  uint8_t Index;
  // {'size_bytes': 8, 'type': '<LightHsbk>', 'name': 'Color'}
  lifxLightHsbk_t Color;
} lifxMultiZoneStateZone_t;

// {'pkt_type': 507, 'size_bytes': 0}
typedef struct {
} lifxMultiZoneGetEffect_t;

// {'pkt_type': 509, 'size_bytes': 59}
typedef struct {
  // {'size_bytes': 59, 'type': '<MultiZoneEffectSettings>', 'name': 'Settings'}
  lifxMultiZoneEffectSettings_t Settings;
} lifxMultiZoneStateEffect_t;

// {'pkt_type': 510, 'size_bytes': 664}
typedef struct {
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Duration'}
  uint32_t Duration;
  // {'size_bytes': 1, 'type': '<MultiZoneExtendedApplicationRequest>', 'name': 'Apply'}
  lifxMultiZoneExtendedApplicationRequest_t Apply;
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Index'}
  uint16_t Index;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'ColorsCount'}
  uint8_t ColorsCount;
  // {'size_bytes': 656, 'type': '[82]<LightHsbk>', 'name': 'Colors'}
  lifxLightHsbk_t Colors;
} lifxMultiZoneExtendedSetColorZones_t;

// {'pkt_type': 511, 'size_bytes': 0}
typedef struct {
} lifxMultiZoneExtendedGetColorZones_t;

typedef union
{
  lifxDeviceAcknowledgement_t DeviceAcknowledgement;
  lifxDeviceStateService_t DeviceStateService;
  lifxDeviceGetHostFirmware_t DeviceGetHostFirmware;
  lifxDeviceStateHostInfo_t DeviceStateHostInfo;
  lifxDeviceGetLabel_t DeviceGetLabel;
  lifxDeviceGetWifiInfo_t DeviceGetWifiInfo;
  lifxDeviceStateLabel_t DeviceStateLabel;
  lifxDeviceGetLocation_t DeviceGetLocation;
  lifxDeviceGetPower_t DeviceGetPower;
  lifxDeviceGetHostInfo_t DeviceGetHostInfo;
  lifxDeviceStateWifiFirmware_t DeviceStateWifiFirmware;
  lifxDeviceStateVersion_t DeviceStateVersion;
  lifxDeviceGetVersion_t DeviceGetVersion;
  lifxDeviceGetInfo_t DeviceGetInfo;
  lifxDeviceStateWifiInfo_t DeviceStateWifiInfo;
  lifxDeviceSetLabel_t DeviceSetLabel;
  lifxDeviceStatePower_t DeviceStatePower;
  lifxDeviceStateGroup_t DeviceStateGroup;
  lifxDeviceGetWifiFirmware_t DeviceGetWifiFirmware;
  lifxDeviceStateInfo_t DeviceStateInfo;
  lifxDeviceStateHostFirmware_t DeviceStateHostFirmware;
  lifxDeviceStateLocation_t DeviceStateLocation;
  lifxDeviceEchoRequest_t DeviceEchoRequest;
  lifxDeviceSetGroup_t DeviceSetGroup;
  lifxDeviceSetLocation_t DeviceSetLocation;
  lifxDeviceSetPower_t DeviceSetPower;
  lifxDeviceEchoResponse_t DeviceEchoResponse;
  lifxDeviceGetGroup_t DeviceGetGroup;
  lifxDeviceGetService_t DeviceGetService;
  lifxLightStatePower_t LightStatePower;
  lifxLightGetInfrared_t LightGetInfrared;
  lifxLightState_t LightState;
  lifxLightSetPower_t LightSetPower;
  lifxLightSetWaveformOptional_t LightSetWaveformOptional;
  lifxLightSetWaveform_t LightSetWaveform;
  lifxLightGet_t LightGet;
  lifxLightSetInfrared_t LightSetInfrared;
  lifxLightSetColor_t LightSetColor;
  lifxLightStateInfrared_t LightStateInfrared;
  lifxLightGetPower_t LightGetPower;
  lifxMultiZoneExtendedStateMultiZone_t MultiZoneExtendedStateMultiZone;
  lifxMultiZoneStateMultiZone_t MultiZoneStateMultiZone;
  lifxMultiZoneSetColorZones_t MultiZoneSetColorZones;
  lifxMultiZoneSetEffect_t MultiZoneSetEffect;
  lifxMultiZoneGetColorZones_t MultiZoneGetColorZones;
  lifxMultiZoneStateZone_t MultiZoneStateZone;
  lifxMultiZoneGetEffect_t MultiZoneGetEffect;
  lifxMultiZoneStateEffect_t MultiZoneStateEffect;
  lifxMultiZoneExtendedSetColorZones_t MultiZoneExtendedSetColorZones;
  lifxMultiZoneExtendedGetColorZones_t MultiZoneExtendedGetColorZones;
  lifxTileGetEffect_t TileGetEffect;
  lifxTileGetDeviceChain_t TileGetDeviceChain;
  lifxTileStateDeviceChain_t TileStateDeviceChain;
  lifxTileState64_t TileState64;
  lifxTileSet64_t TileSet64;
  lifxTileSetUserPosition_t TileSetUserPosition;
  lifxTileSetEffect_t TileSetEffect;
  lifxTileStateEffect_t TileStateEffect;
  lifxTileGet64_t TileGet64;
} lifxPacket_t;

#ifdef __cplusplus
}
#endif
#endif
