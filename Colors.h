/*
    Colors.h - Library for color handling because I don't like the one provided by NeoPixel.
    Created by Henry Lehmann, December 29, 2020.
    Released into the public domain.
*/
#ifndef Colors_h
#define Colors_h

#include "Arduino.h"

class Colors {
    public:
        static const uint32_t WHITE = 0xFFFFFF;
        static const uint32_t RED = 0xFF0000;
        static const uint32_t GREEN = 0x00FF00;
        static const uint32_t BLUE = 0x0000FF;
        static const uint32_t LIGHTBLUE = 0x00BFFF;

        uint32_t hsbToRgb(uint16_t h, uint8_t s, uint8_t b);
        uint32_t hueToRgb(uint16_t hue);
};

#endif