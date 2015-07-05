#include <tracer/SingleSphere.h>
#include <RGBColor.h>
#include <HitRec.h>
#include <World.h>

SingleSphere::SingleSphere(World* world)
: RayTracer(world)
{
}

RGBColor SingleSphere::TraceRay(const Ray& ray) const
{
    HitRec sr;
    double t;
    
    if (this->world->sphere.Hit(ray, t, sr))
        return RGBColor::red;
    else
        return RGBColor::black;
}

