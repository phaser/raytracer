#pragma once
#include <stdint.h>

class ViewPlane
{
public:
    ViewPlane();
    ViewPlane& SetWidth(uint16_t width);
    uint16_t GetWidth() const;
    ViewPlane& SetHeight(uint16_t height);
    uint16_t GetHeight() const;
    ViewPlane& SetPixelSize(float pixsize);
    float GetPixelSize() const;
private:
    uint16_t width;
    uint16_t height;
    float s;
    float gamma;
    float inv_gamma;
};