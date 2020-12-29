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
        int* hsbToRgb(int hue, float saturation, float brightness);
};

#endif