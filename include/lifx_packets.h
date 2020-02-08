//
// DO NOT EDIT - AUTO-GENERATE:2020-02-07 15:15:32.047157
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


// {'pkt_type': 2, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetService_t;

// {'pkt_type': 3, 'size_bytes': 5}
typedef struct {
  // {'name': 'Service', 'type': '<DeviceService>', 'size_bytes': 1}
  lifxDeviceService_t Service;
  // {'name': 'Port', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Port;
} lifxDeviceStateService_t;

// {'pkt_type': 12, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetHostInfo_t;

// {'pkt_type': 13, 'size_bytes': 14}
typedef struct {
  // {'name': 'Signal', 'type': 'float32', 'size_bytes': 4}
  float Signal;
  // {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Tx;
  // {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Rx;
  // {'type': 'reserved', 'size_bytes': 2}
  uint8_t pad3[2];
} lifxDeviceStateHostInfo_t;

// {'pkt_type': 14, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetHostFirmware_t;

// HACK: DeviceStateHostFirmware is in lifx_fields.h

// {'pkt_type': 16, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetWifiInfo_t;

// {'pkt_type': 17, 'size_bytes': 14}
typedef struct {
  // {'name': 'Signal', 'type': 'float32', 'size_bytes': 4}
  float Signal;
  // {'name': 'Tx', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Tx;
  // {'name': 'Rx', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Rx;
  // {'type': 'reserved', 'size_bytes': 2}
  uint8_t pad3[2];
} lifxDeviceStateWifiInfo_t;

// {'pkt_type': 18, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetWifiFirmware_t;

// {'pkt_type': 19, 'size_bytes': 20}
typedef struct {
  // {'name': 'Build', 'type': 'uint64', 'size_bytes': 8}
  uint64_t Build;
  // {'type': 'reserved', 'size_bytes': 8}
  uint8_t pad1[8];
  // {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}
  uint16_t VersionMinor;
  // {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}
  uint16_t VersionMajor;
} lifxDeviceStateWifiFirmware_t;

// {'pkt_type': 20, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetPower_t;

// {'pkt_type': 21, 'size_bytes': 2}
typedef struct {
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  uint16_t Level;
} lifxDeviceSetPower_t;

// {'pkt_type': 22, 'size_bytes': 2}
typedef struct {
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  uint16_t Level;
} lifxDeviceStatePower_t;

// {'pkt_type': 23, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetLabel_t;

// {'pkt_type': 24, 'size_bytes': 32}
typedef struct {
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  uint8_t Label[32];
} lifxDeviceSetLabel_t;

// {'pkt_type': 25, 'size_bytes': 32}
typedef struct {
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  uint8_t Label[32];
} lifxDeviceStateLabel_t;

// {'pkt_type': 32, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetVersion_t;

// HACK: DeviceStateVersion is in lifx_fields.h

// {'pkt_type': 34, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetInfo_t;

// {'pkt_type': 35, 'size_bytes': 24}
typedef struct {
  // {'name': 'Time', 'type': 'uint64', 'size_bytes': 8}
  uint64_t Time;
  // {'name': 'Uptime', 'type': 'uint64', 'size_bytes': 8}
  uint64_t Uptime;
  // {'name': 'Downtime', 'type': 'uint64', 'size_bytes': 8}
  uint64_t Downtime;
} lifxDeviceStateInfo_t;

// {'pkt_type': 45, 'size_bytes': 0}
typedef struct {
} lifxDeviceAcknowledgement_t;

// {'pkt_type': 48, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetLocation_t;

// {'pkt_type': 49, 'size_bytes': 56}
typedef struct {
  // {'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}
  uint8_t Location[16];
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  uint8_t Label[32];
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  uint64_t UpdatedAt;
} lifxDeviceSetLocation_t;

// {'pkt_type': 50, 'size_bytes': 56}
typedef struct {
  // {'name': 'Location', 'type': '[16]byte', 'size_bytes': 16}
  uint8_t Location[16];
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  uint8_t Label[32];
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  uint64_t UpdatedAt;
} lifxDeviceStateLocation_t;

// {'pkt_type': 51, 'size_bytes': 0}
typedef struct {
} lifxDeviceGetGroup_t;

// {'pkt_type': 52, 'size_bytes': 56}
typedef struct {
  // {'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}
  uint8_t Group[16];
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  uint8_t Label[32];
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  uint64_t UpdatedAt;
} lifxDeviceSetGroup_t;

// {'pkt_type': 53, 'size_bytes': 56}
typedef struct {
  // {'name': 'Group', 'type': '[16]byte', 'size_bytes': 16}
  uint8_t Group[16];
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  uint8_t Label[32];
  // {'name': 'UpdatedAt', 'type': 'uint64', 'size_bytes': 8}
  uint64_t UpdatedAt;
} lifxDeviceStateGroup_t;

// {'pkt_type': 58, 'size_bytes': 64}
typedef struct {
  // {'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}
  uint8_t Payload[64];
} lifxDeviceEchoRequest_t;

// {'pkt_type': 59, 'size_bytes': 64}
typedef struct {
  // {'name': 'Payload', 'type': '[64]byte', 'size_bytes': 64}
  uint8_t Payload[64];
} lifxDeviceEchoResponse_t;

// {'pkt_type': 101, 'size_bytes': 0}
typedef struct {
} lifxLightGet_t;

// {'pkt_type': 102, 'size_bytes': 13}
typedef struct {
  // {'type': 'reserved', 'size_bytes': 1}
  uint8_t pad0;
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxLightHsbk_t Color;
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Duration;
} lifxLightSetColor_t;

// {'pkt_type': 119, 'size_bytes': 25}
typedef struct {
  // {'type': 'reserved', 'size_bytes': 1}
  uint8_t pad0;
  // {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}
  bool Transient;
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxLightHsbk_t Color;
  // {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Period;
  // {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}
  float Cycles;
  // {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}
  int16_t SkewRatio;
  // {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}
  lifxLightWaveform_t Waveform;
  // {'name': 'SetHue', 'type': 'bool', 'size_bytes': 1}
  bool SetHue;
  // {'name': 'SetSaturation', 'type': 'bool', 'size_bytes': 1}
  bool SetSaturation;
  // {'name': 'SetBrightness', 'type': 'bool', 'size_bytes': 1}
  bool SetBrightness;
  // {'name': 'SetKelvin', 'type': 'bool', 'size_bytes': 1}
  bool SetKelvin;
} lifxLightSetWaveformOptional_t;

// {'pkt_type': 103, 'size_bytes': 21}
typedef struct {
  // {'type': 'reserved', 'size_bytes': 1}
  uint8_t pad0;
  // {'name': 'Transient', 'type': 'bool', 'size_bytes': 1}
  bool Transient;
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxLightHsbk_t Color;
  // {'name': 'Period', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Period;
  // {'name': 'Cycles', 'type': 'float32', 'size_bytes': 4}
  float Cycles;
  // {'name': 'SkewRatio', 'type': 'int16', 'size_bytes': 2}
  int16_t SkewRatio;
  // {'name': 'Waveform', 'type': '<LightWaveform>', 'size_bytes': 1}
  lifxLightWaveform_t Waveform;
} lifxLightSetWaveform_t;

// {'pkt_type': 116, 'size_bytes': 0}
typedef struct {
} lifxLightGetPower_t;

// {'pkt_type': 117, 'size_bytes': 6}
typedef struct {
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  uint16_t Level;
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Duration;
} lifxLightSetPower_t;

// {'pkt_type': 118, 'size_bytes': 2}
typedef struct {
  // {'name': 'Level', 'type': 'uint16', 'size_bytes': 2}
  uint16_t Level;
} lifxLightStatePower_t;

// {'pkt_type': 107, 'size_bytes': 52}
typedef struct {
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxLightHsbk_t Color;
  // {'type': 'reserved', 'size_bytes': 2}
  uint8_t pad1[2];
  // {'name': 'Power', 'type': 'uint16', 'size_bytes': 2}
  uint16_t Power;
  // {'name': 'Label', 'type': '[32]byte', 'size_bytes': 32}
  uint8_t Label[32];
  // {'type': 'reserved', 'size_bytes': 8}
  uint8_t pad4[8];
} lifxLightState_t;

// {'pkt_type': 120, 'size_bytes': 0}
typedef struct {
} lifxLightGetInfrared_t;

// {'pkt_type': 121, 'size_bytes': 2}
typedef struct {
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  uint16_t Brightness;
} lifxLightStateInfrared_t;

// {'pkt_type': 122, 'size_bytes': 2}
typedef struct {
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  uint16_t Brightness;
} lifxLightSetInfrared_t;

// {'pkt_type': 701, 'size_bytes': 0}
typedef struct {
} lifxTileGetDeviceChain_t;

// {'pkt_type': 702, 'size_bytes': 882}
typedef struct {
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  uint8_t StartIndex;
  // {'name': 'TileDevices', 'type': '[16]<TileStateDevice>', 'size_bytes': 880}
  lifxTileStateDevice_t TileDevices;
  // {'name': 'TileDevicesCount', 'type': 'uint8', 'size_bytes': 1}
  uint8_t TileDevicesCount;
} lifxTileStateDeviceChain_t;

// {'pkt_type': 703, 'size_bytes': 11}
typedef struct {
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  uint8_t TileIndex;
  // {'type': 'reserved', 'size_bytes': 2}
  uint8_t pad1[2];
  // {'name': 'UserX', 'type': 'float32', 'size_bytes': 4}
  float UserX;
  // {'name': 'UserY', 'type': 'float32', 'size_bytes': 4}
  float UserY;
} lifxTileSetUserPosition_t;

// {'pkt_type': 707, 'size_bytes': 6}
typedef struct {
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  uint8_t TileIndex;
  // {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}
  uint8_t Length;
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxTileBufferRect_t Rect;
} lifxTileGet64_t;

// {'pkt_type': 711, 'size_bytes': 517}
typedef struct {
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  uint8_t TileIndex;
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxTileBufferRect_t Rect;
  // {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}
  lifxLightHsbk_t Colors;
} lifxTileState64_t;

// {'pkt_type': 715, 'size_bytes': 522}
typedef struct {
  // {'name': 'TileIndex', 'type': 'uint8', 'size_bytes': 1}
  uint8_t TileIndex;
  // {'name': 'Length', 'type': 'uint8', 'size_bytes': 1}
  uint8_t Length;
  // {'name': 'Rect', 'type': '<TileBufferRect>', 'size_bytes': 4}
  lifxTileBufferRect_t Rect;
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Duration;
  // {'name': 'Colors', 'type': '[64]<LightHsbk>', 'size_bytes': 512}
  lifxLightHsbk_t Colors;
} lifxTileSet64_t;

// {'pkt_type': 718, 'size_bytes': 2}
typedef struct {
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  uint8_t Reserved0;
  // {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}
  uint8_t Reserved1;
} lifxTileGetEffect_t;

// {'pkt_type': 719, 'size_bytes': 188}
typedef struct {
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  uint8_t Reserved0;
  // {'name': 'Reserved1', 'type': 'uint8', 'size_bytes': 1}
  uint8_t Reserved1;
  // {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}
  lifxTileEffectSettings_t Settings;
} lifxTileSetEffect_t;

// {'pkt_type': 720, 'size_bytes': 187}
typedef struct {
  // {'name': 'Reserved0', 'type': 'uint8', 'size_bytes': 1}
  uint8_t Reserved0;
  // {'name': 'Settings', 'type': '<TileEffectSettings>', 'size_bytes': 186}
  lifxTileEffectSettings_t Settings;
} lifxTileStateEffect_t;

// {'pkt_type': 501, 'size_bytes': 15}
typedef struct {
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  uint8_t StartIndex;
  // {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}
  uint8_t EndIndex;
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxLightHsbk_t Color;
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Duration;
  // {'name': 'Apply', 'type': '<MultiZoneApplicationRequest>', 'size_bytes': 1}
  lifxMultiZoneApplicationRequest_t Apply;
} lifxMultiZoneSetColorZones_t;

// {'pkt_type': 502, 'size_bytes': 2}
typedef struct {
  // {'name': 'StartIndex', 'type': 'uint8', 'size_bytes': 1}
  uint8_t StartIndex;
  // {'name': 'EndIndex', 'type': 'uint8', 'size_bytes': 1}
  uint8_t EndIndex;
} lifxMultiZoneGetColorZones_t;

// {'pkt_type': 503, 'size_bytes': 10}
typedef struct {
  // {'name': 'Count', 'type': 'uint8', 'size_bytes': 1}
  uint8_t Count;
  // {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}
  uint8_t Index;
  // {'name': 'Color', 'type': '<LightHsbk>', 'size_bytes': 8}
  lifxLightHsbk_t Color;
} lifxMultiZoneStateZone_t;

// {'pkt_type': 506, 'size_bytes': 66}
typedef struct {
  // {'name': 'Count', 'type': 'uint8', 'size_bytes': 1}
  uint8_t Count;
  // {'name': 'Index', 'type': 'uint8', 'size_bytes': 1}
  uint8_t Index;
  // {'name': 'Colors', 'type': '[8]<LightHsbk>', 'size_bytes': 64}
  lifxLightHsbk_t Colors;
} lifxMultiZoneStateMultiZone_t;

// {'pkt_type': 507, 'size_bytes': 0}
typedef struct {
} lifxMultiZoneGetEffect_t;

// {'pkt_type': 508, 'size_bytes': 59}
typedef struct {
  // {'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}
  lifxMultiZoneEffectSettings_t Settings;
} lifxMultiZoneSetEffect_t;

// {'pkt_type': 509, 'size_bytes': 59}
typedef struct {
  // {'name': 'Settings', 'type': '<MultiZoneEffectSettings>', 'size_bytes': 59}
  lifxMultiZoneEffectSettings_t Settings;
} lifxMultiZoneStateEffect_t;

// {'pkt_type': 510, 'size_bytes': 664}
typedef struct {
  // {'name': 'Duration', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Duration;
  // {'name': 'Apply', 'type': '<MultiZoneExtendedApplicationRequest>', 'size_bytes': 1}
  lifxMultiZoneExtendedApplicationRequest_t Apply;
  // {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}
  uint16_t Index;
  // {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}
  uint8_t ColorsCount;
  // {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}
  lifxLightHsbk_t Colors;
} lifxMultiZoneExtendedSetColorZones_t;

// {'pkt_type': 511, 'size_bytes': 0}
typedef struct {
} lifxMultiZoneExtendedGetColorZones_t;

// {'pkt_type': 512, 'size_bytes': 661}
typedef struct {
  // {'name': 'Count', 'type': 'uint16', 'size_bytes': 2}
  uint16_t Count;
  // {'name': 'Index', 'type': 'uint16', 'size_bytes': 2}
  uint16_t Index;
  // {'name': 'ColorsCount', 'type': 'uint8', 'size_bytes': 1}
  uint8_t ColorsCount;
  // {'name': 'Colors', 'type': '[82]<LightHsbk>', 'size_bytes': 656}
  lifxLightHsbk_t Colors;
} lifxMultiZoneExtendedStateMultiZone_t;

#ifdef __cplusplus
}
#endif
#endif
