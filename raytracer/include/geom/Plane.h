#pragma once
#include <geom/GeometricObject.h>

class Plane : public GeometricObject
{
public:
    bool Hit(const Ray& ray, double& tmin, HitRec& hr) const;    
};