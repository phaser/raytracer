#pragma once
#include <stdint.h>

class Ray;

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
    Ray GenerateRay(uint32_t x, uint32_t y);
    void SetFocalDistance(float focalDistance);
    float GetFocalDistance() const;
private:
    uint16_t width;
    uint16_t height;
    float s;
    float gamma;
    float inv_gamma;
    float focalDistance;        /**< The point in the back of the viewplane where rays originate */
};