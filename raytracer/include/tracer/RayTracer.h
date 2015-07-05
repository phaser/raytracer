#pragma once
#include <string>
#include <memory>

class World;
class Ray;
class RGBColor;

class RayTracer
{
public:
    RayTracer(World* world);
    ~RayTracer();
    virtual RGBColor TraceRay(const Ray& ray) const;
protected:
    World* world;
};