//
// DO NOT EDIT - AUTO-GENERATE:2020-03-05 16:03:34.525377
//
#ifndef LIFX_FIELDS_H
#define LIFX_FIELDS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <lifx_enums.h>

#include <stdbool.h>
// XXX: Hack These are actually packets, but are
//      referenced in the fields structures
// {'pkt_type': 33, 'size_bytes': 12}
typedef struct {
  // {'name': 'Vendor', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Vendor;
  // {'name': 'Product', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Product;
  // {'name': 'Version', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Version;
} lifxDeviceStateVersion_t;
// {'pkt_type': 15, 'size_bytes': 20}
typedef struct {
  // {'name': 'Build', 'type': 'uint64', 'size_bytes': 8}
  uint64_t Build;
  // {'type': 'reserved', 'size_bytes': 8}
  uint8_t pad1[8];
  // {'name': 'VersionMinor', 'type': 'uint16', 'size_bytes': 2}
  uint16_t VersionMinor;
  // {'name': 'VersionMajor', 'type': 'uint16', 'size_bytes': 2}
  uint16_t VersionMajor;
} lifxDeviceStateHostFirmware_t;
// XXX: end hack



// {'size_bytes': 8}
typedef struct {
  // {'name': 'Hue', 'type': 'uint16', 'size_bytes': 2}
  uint16_t Hue;
  // {'name': 'Saturation', 'type': 'uint16', 'size_bytes': 2}
  uint16_t Saturation;
  // {'name': 'Brightness', 'type': 'uint16', 'size_bytes': 2}
  uint16_t Brightness;
  // {'name': 'Kelvin', 'type': 'uint16', 'size_bytes': 2}
  uint16_t Kelvin;
} lifxLightHsbk_t;

// {'size_bytes': 32}
typedef struct {
  // {'name': 'Parameter0', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter0;
  // {'name': 'Parameter1', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter1;
  // {'name': 'Parameter2', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter2;
  // {'name': 'Parameter3', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter3;
  // {'name': 'Parameter4', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter4;
  // {'name': 'Parameter5', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter5;
  // {'name': 'Parameter6', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter6;
  // {'name': 'Parameter7', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter7;
} lifxMultiZoneEffectParameter_t;

// {'size_bytes': 59}
typedef struct {
  // {'name': 'Instanceid', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Instanceid;
  // {'name': 'Type', 'type': '<MultiZoneEffectType>', 'size_bytes': 1}
  lifxMultiZoneEffectType_t Type;
  // {'type': 'reserved', 'size_bytes': 2}
  uint8_t pad2[2];
  // {'name': 'Speed', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Speed;
  // {'name': 'Duration', 'type': 'uint64', 'size_bytes': 8}
  uint64_t Duration;
  // {'type': 'reserved', 'size_bytes': 4}
  uint8_t pad5[4];
  // {'type': 'reserved', 'size_bytes': 4}
  uint8_t pad6[4];
  // {'name': 'Parameter', 'type': '<MultiZoneEffectParameter>', 'size_bytes': 32}
  lifxMultiZoneEffectParameter_t Parameter;
} lifxMultiZoneEffectSettings_t;

// {'size_bytes': 6}
typedef struct {
  // {'name': 'X', 'type': 'int16', 'size_bytes': 2}
  int16_t X;
  // {'name': 'Y', 'type': 'int16', 'size_bytes': 2}
  int16_t Y;
  // {'name': 'Z', 'type': 'int16', 'size_bytes': 2}
  int16_t Z;
} lifxTileAccelMeas_t;

// {'size_bytes': 55}
typedef struct {
  // {'name': 'AccelMeas', 'type': '<TileAccelMeas>', 'size_bytes': 6}
  lifxTileAccelMeas_t AccelMeas;
  // {'type': 'reserved', 'size_bytes': 2}
  uint8_t pad1[2];
  // {'name': 'UserX', 'type': 'float32', 'size_bytes': 4}
  float UserX;
  // {'name': 'UserY', 'type': 'float32', 'size_bytes': 4}
  float UserY;
  // {'name': 'Width', 'type': 'uint8', 'size_bytes': 1}
  uint8_t Width;
  // {'name': 'Height', 'type': 'uint8', 'size_bytes': 1}
  uint8_t Height;
  // {'type': 'reserved', 'size_bytes': 1}
  uint8_t pad6;
  // {'name': 'DeviceVersion', 'type': '<DeviceStateVersion>', 'size_bytes': 12}
  lifxDeviceStateVersion_t DeviceVersion;
  // {'name': 'Firmware', 'type': '<DeviceStateHostFirmware>', 'size_bytes': 20}
  lifxDeviceStateHostFirmware_t Firmware;
  // {'type': 'reserved', 'size_bytes': 4}
  uint8_t pad9[4];
} lifxTileStateDevice_t;

// {'size_bytes': 4}
typedef struct {
  // {'type': 'reserved', 'size_bytes': 1}
  uint8_t pad0;
  // {'name': 'X', 'type': 'uint8', 'size_bytes': 1}
  uint8_t X;
  // {'name': 'Y', 'type': 'uint8', 'size_bytes': 1}
  uint8_t Y;
  // {'name': 'Width', 'type': 'uint8', 'size_bytes': 1}
  uint8_t Width;
} lifxTileBufferRect_t;

// {'size_bytes': 32}
typedef struct {
  // {'name': 'Parameter0', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter0;
  // {'name': 'Parameter1', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter1;
  // {'name': 'Parameter2', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter2;
  // {'name': 'Parameter3', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter3;
  // {'name': 'Parameter4', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter4;
  // {'name': 'Parameter5', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter5;
  // {'name': 'Parameter6', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter6;
  // {'name': 'Parameter7', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Parameter7;
} lifxTileEffectParameter_t;

// {'size_bytes': 186}
typedef struct {
  // {'name': 'Instanceid', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Instanceid;
  // {'name': 'Type', 'type': '<TileEffectType>', 'size_bytes': 1}
  lifxTileEffectType_t Type;
  // {'name': 'Speed', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Speed;
  // {'name': 'Duration', 'type': 'uint64', 'size_bytes': 8}
  uint64_t Duration;
  // {'name': 'Reserved0', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Reserved0;
  // {'name': 'Reserved1', 'type': 'uint32', 'size_bytes': 4}
  uint32_t Reserved1;
  // {'name': 'Parameter', 'type': '<TileEffectParameter>', 'size_bytes': 32}
  lifxTileEffectParameter_t Parameter;
  // {'name': 'PaletteCount', 'type': 'uint8', 'size_bytes': 1}
  uint8_t PaletteCount;
  // {'name': 'Palette', 'type': '[16]<LightHsbk>', 'size_bytes': 128}
  lifxLightHsbk_t Palette[16];
} lifxTileEffectSettings_t;

#ifdef __cplusplus
}
#endif
#endif
