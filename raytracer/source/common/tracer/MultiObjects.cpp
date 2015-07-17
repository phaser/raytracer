#include <tracer/MultiObjects.h>
#include <RGBColor.h>
#include <HitRec.h>
#include <World.h>
#include <cfloat>

MultiObjects::MultiObjects(World* world)
: RayTracer(world)
{
}

RGBColor MultiObjects::TraceRay(const Ray& ray) const
{
    HitRec sr;
    double t;
    double tmin = FLT_MAX;
    GeometricObject* obj_min = nullptr;
    
    for (auto obj : world->GetObjects())
    {
        if (obj->Hit(ray, t, sr))
        {
            if (t < tmin)
            {
                tmin = t;
                obj_min = obj;
            }
        }
    }
    
    if (obj_min != nullptr)
    {
        
    }
    return RGBColor::black;
}