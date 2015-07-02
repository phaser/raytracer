#include <RayTracer.h>
#include <ImageBufferPNG.h>
#include <Ray.h>
#include <World.h>
#include <RGBColor.h>

RayTracer::RayTracer(World* world) : world(world)
{
}

RayTracer::~RayTracer()
{
}

RGBColor RayTracer::TraceRay(const Ray& ray) const
{
    
}