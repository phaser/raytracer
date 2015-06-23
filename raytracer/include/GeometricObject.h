#pragma once

class Ray;
class HitRec;

class GeometricObject
{
public:
    virtual bool Hit(const Ray& ray, double& tmin, HitRec& hr) const =0;
};