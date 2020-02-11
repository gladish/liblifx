//
// DO NOT EDIT - AUTO-GENERATE:2020-02-10 14:58:43.459695
//
#ifndef __LIFX_FIELDS_H__
#define __LIFX_FIELDS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <lifx_enums.h>

// XXX: Hack These are actually packets, but are
//      referenced in the fields structures
// {'pkt_type': 33, 'size_bytes': 12}
typedef struct {
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Vendor'}
  uint32_t Vendor;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Product'}
  uint32_t Product;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Version'}
  uint32_t Version;
} lifxDeviceStateVersion_t;
// {'pkt_type': 15, 'size_bytes': 20}
typedef struct {
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Build'}
  uint64_t Build;
  // {'size_bytes': 8, 'type': 'reserved'}
  uint8_t pad1[8];
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMinor'}
  uint16_t VersionMinor;
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'VersionMajor'}
  uint16_t VersionMajor;
} lifxDeviceStateHostFirmware_t;
// XXX: end hack

// {'size_bytes': 8}
typedef struct {
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Hue'}
  uint16_t Hue;
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Saturation'}
  uint16_t Saturation;
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Brightness'}
  uint16_t Brightness;
  // {'size_bytes': 2, 'type': 'uint16', 'name': 'Kelvin'}
  uint16_t Kelvin;
} lifxLightHsbk_t;

// {'size_bytes': 6}
typedef struct {
  // {'size_bytes': 2, 'type': 'int16', 'name': 'X'}
  int16_t X;
  // {'size_bytes': 2, 'type': 'int16', 'name': 'Y'}
  int16_t Y;
  // {'size_bytes': 2, 'type': 'int16', 'name': 'Z'}
  int16_t Z;
} lifxTileAccelMeas_t;

// {'size_bytes': 32}
typedef struct {
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter0'}
  uint32_t Parameter0;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter1'}
  uint32_t Parameter1;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter2'}
  uint32_t Parameter2;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter3'}
  uint32_t Parameter3;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter4'}
  uint32_t Parameter4;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter5'}
  uint32_t Parameter5;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter6'}
  uint32_t Parameter6;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter7'}
  uint32_t Parameter7;
} lifxTileEffectParameter_t;

// {'size_bytes': 55}
typedef struct {
  // {'size_bytes': 6, 'type': '<TileAccelMeas>', 'name': 'AccelMeas'}
  lifxTileAccelMeas_t AccelMeas;
  // {'size_bytes': 2, 'type': 'reserved'}
  uint8_t pad1[2];
  // {'size_bytes': 4, 'type': 'float32', 'name': 'UserX'}
  float UserX;
  // {'size_bytes': 4, 'type': 'float32', 'name': 'UserY'}
  float UserY;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Width'}
  uint8_t Width;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Height'}
  uint8_t Height;
  // {'size_bytes': 1, 'type': 'reserved'}
  uint8_t pad6;
  // {'size_bytes': 12, 'type': '<DeviceStateVersion>', 'name': 'DeviceVersion'}
  lifxDeviceStateVersion_t DeviceVersion;
  // {'size_bytes': 20, 'type': '<DeviceStateHostFirmware>', 'name': 'Firmware'}
  lifxDeviceStateHostFirmware_t Firmware;
  // {'size_bytes': 4, 'type': 'reserved'}
  uint8_t pad9[4];
} lifxTileStateDevice_t;

// {'size_bytes': 186}
typedef struct {
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Instanceid'}
  uint32_t Instanceid;
  // {'size_bytes': 1, 'type': '<TileEffectType>', 'name': 'Type'}
  lifxTileEffectType_t Type;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Speed'}
  uint32_t Speed;
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Duration'}
  uint64_t Duration;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Reserved0'}
  uint32_t Reserved0;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Reserved1'}
  uint32_t Reserved1;
  // {'size_bytes': 32, 'type': '<TileEffectParameter>', 'name': 'Parameter'}
  lifxTileEffectParameter_t Parameter;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'PaletteCount'}
  uint8_t PaletteCount;
  // {'size_bytes': 128, 'type': '[16]<LightHsbk>', 'name': 'Palette'}
  lifxLightHsbk_t Palette;
} lifxTileEffectSettings_t;

// {'size_bytes': 32}
typedef struct {
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter0'}
  uint32_t Parameter0;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter1'}
  uint32_t Parameter1;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter2'}
  uint32_t Parameter2;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter3'}
  uint32_t Parameter3;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter4'}
  uint32_t Parameter4;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter5'}
  uint32_t Parameter5;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter6'}
  uint32_t Parameter6;
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Parameter7'}
  uint32_t Parameter7;
} lifxMultiZoneEffectParameter_t;

// {'size_bytes': 59}
typedef struct {
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Instanceid'}
  uint32_t Instanceid;
  // {'size_bytes': 1, 'type': '<MultiZoneEffectType>', 'name': 'Type'}
  lifxMultiZoneEffectType_t Type;
  // {'size_bytes': 2, 'type': 'reserved'}
  uint8_t pad2[2];
  // {'size_bytes': 4, 'type': 'uint32', 'name': 'Speed'}
  uint32_t Speed;
  // {'size_bytes': 8, 'type': 'uint64', 'name': 'Duration'}
  uint64_t Duration;
  // {'size_bytes': 4, 'type': 'reserved'}
  uint8_t pad5[4];
  // {'size_bytes': 4, 'type': 'reserved'}
  uint8_t pad6[4];
  // {'size_bytes': 32, 'type': '<MultiZoneEffectParameter>', 'name': 'Parameter'}
  lifxMultiZoneEffectParameter_t Parameter;
} lifxMultiZoneEffectSettings_t;

// {'size_bytes': 4}
typedef struct {
  // {'size_bytes': 1, 'type': 'reserved'}
  uint8_t pad0;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'X'}
  uint8_t X;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Y'}
  uint8_t Y;
  // {'size_bytes': 1, 'type': 'uint8', 'name': 'Width'}
  uint8_t Width;
} lifxTileBufferRect_t;

#ifdef __cplusplus
}
#endif
#endif
