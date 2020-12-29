/*
    Colors.cpp - Library for color handling because I don't like the one provided by NeoPixel.
    Created by Henry Lehmann, December 29, 2020.
    Released into the public domain.
*/

#include "Arduino.h"
#include "Colors.h"

int* Colors::hsbToRgb(int hue, float saturation, float brightness) {
    int rgb[3];

    int hi = hue / 60;
    float f = ((float)hue) / 60 - hi;
    float p = brightness * (1 - saturation);
    float q = brightness * (1 - saturation * f);
    float t = brightness * (1 - saturation * (1 - f));

    switch (hi)
    {
        case 0:
        case 6:
            rgb[0] = brightness * 255;
            rgb[1] = t * 255;
            rgb[2] = p * 255;
            break;
        case 1:
            rgb[0] = q * 255;
            rgb[1] = brightness * 255;
            rgb[2] = p * 255;
            break;
        case 2:
            rgb[0] = p * 255;
            rgb[1] = brightness * 255;
            rgb[2] = t * 255;
            break;
        case 3:
            rgb[0] = p * 255;
            rgb[1] = q * 255;
            rgb[2] = brightness * 255;
            break;
        case 4:
            rgb[0] = t * 255;
            rgb[1] = p * 255;
            rgb[2] = brightness * 255;
            break;
        case 5:
            rgb[0] = brightness * 255;
            rgb[1] = p * 255;
            rgb[2] = q * 255;
            break;

        default:
            break;
    }

    return rgb;
}