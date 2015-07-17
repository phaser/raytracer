#pragma once

class Ray;
class HitRec;
class RGBColor;

class GeometricObject
{
public:
    virtual bool Hit(const Ray& ray, double& tmin, HitRec& hr) const =0;
    virtual RGBColor GetBaseColor() =0;
};