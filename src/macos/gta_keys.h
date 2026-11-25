#pragma once
#include <stdint.h>

/* GTA_KEYS="15:enter,30:up*3" (or --autotap S: "S:enter"): played from launch. */
void gta_keys_start(int autotap_s);
/* GTA_SHOTS=DIR: a frame written as DIR/frameNNN.ppm. */
void gta_shoot(const uint8_t *px, int w, int h, int pitch, int bpp, const uint32_t *pal, long n);
