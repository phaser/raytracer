#pragma once
#include <tracer/RayTracer.h>

class SingleSphere : public RayTracer
{
public:
    SingleSphere(World* world);
    RGBColor TraceRay(const Ray& ray) const;
};