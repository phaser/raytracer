#pragma once
#include <tracer/RayTracer.h>

class MultiObjects : public RayTracer
{
public:
    MultiObjects(World* world);
    RGBColor TraceRay(const Ray& ray) const;
};