/*
    Colors.cpp - Library for color handling because I don't like the one provided by NeoPixel.
    Created by Henry Lehmann, December 29, 2020.
    Released into the public domain.
*/

#include "Arduino.h"
#include "Colors.h"

uint32_t Colors::hsbToRgb(uint16_t h, uint8_t s, uint8_t b) {

    uint32_t c = s * b / 255;
    uint32_t x = c * (60 - abs(h % 120 - 60)) / 255;
    uint32_t m = b - c;
    c += m;
    x += m;

    uint8_t hi = h / 60;
    switch (hi)
    {
        case 0:
        case 6:
            return c << 16 | x << 8 | m;
        case 1:
            return x << 16 | c << 8 | m;
        case 2:
            return m << 16 | c << 8 | x;
        case 3:
            return m << 16 | x << 8 | c;
        case 4:
            return x << 16 | m << 8 | c;
        case 5:
            return c << 16 | m << 8 | x;
        default:
            return 0;
    }
}

uint32_t Colors::hueToRgb(uint16_t h) {
    
    uint32_t t = (h % 60) * 255 / 60;
    uint32_t q = 255 - t;

    uint16_t hi = h / 60;
    switch (hi) {
        case 0:
        case 6:
            return t << 8  | 0xFF0000;
        case 1:
            return q << 16 | 0x00FF00;
        case 2:
            return t       | 0x00FF00;
        case 3:
            return q << 8  | 0x0000FF;
        case 4:
            return t << 16 | 0x0000FF;
        case 5:
            return q       | 0xFF0000;
        default:
            return 0;
    }

}
