//
// DO NOT EDIT - AUTO-GENERATE:2020-02-21 15:04:04.597814
//
#ifndef LIFX_ENUMS_H
#define LIFX_ENUMS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef enum {
  kLifxDeviceServiceUdp = 1,
  kLifxDeviceService_reserved1 = 2,
  kLifxDeviceService_reserved2 = 3,
  kLifxDeviceService_reserved3 = 4,
  kLifxDeviceService_reserved4 = 5  
} lifxDeviceService_t;

typedef enum {
  kLifxLightWaveformSaw = 0,
  kLifxLightWaveformSine = 1,
  kLifxLightWaveformHalfSine = 2,
  kLifxLightWaveformTriangle = 3,
  kLifxLightWaveformPulse = 4  
} lifxLightWaveform_t;

typedef enum {
  kLifxMultiZoneApplicationRequestNoApply = 0,
  kLifxMultiZoneApplicationRequestApply = 1,
  kLifxMultiZoneApplicationRequestApplyOnly = 2  
} lifxMultiZoneApplicationRequest_t;

typedef enum {
  kLifxMultiZoneEffectTypeOff = 0,
  kLifxMultiZoneEffectTypeMove = 1,
  kLifxMultiZoneEffectType_reserved2 = 2,
  kLifxMultiZoneEffectType_reserved3 = 3  
} lifxMultiZoneEffectType_t;

typedef enum {
  kLifxMultiZoneExtendedApplicationRequestNoApply = 0,
  kLifxMultiZoneExtendedApplicationRequestApply = 1,
  kLifxMultiZoneExtendedApplicationRequestApplyOnly = 2  
} lifxMultiZoneExtendedApplicationRequest_t;

typedef enum {
  kLifxTileEffectTypeOff = 0,
  kLifxTileEffectType_reserved1 = 1,
  kLifxTileEffectTypeMorph = 2,
  kLifxTileEffectTypeFlame = 3,
  kLifxTileEffectType_reserved4 = 4  
} lifxTileEffectType_t;

#ifdef __cplusplus
}
#endif
#endif
