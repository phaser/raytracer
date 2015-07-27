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
    HitRec sr(*world);
    double t;
    double tmin = FLT_MAX;
    GeometricObject* obj_min = nullptr;
    HitRec sr_min(*world);
    
    for (auto obj : world->GetObjects())
    {
        if (obj->Hit(ray, t, sr))
        {
            if (t < tmin)
            {
                tmin = t;
                obj_min = obj;
                sr_min = sr;
            }
        }
    }
    
    if (obj_min != nullptr)
    {
        obj_min->GetMaterial().shade(sr_min);
        RGBColor col = obj_min->GetMaterial().shade(sr_min);
        col.Clamp();
        return col;
    }
    return RGBColor::black;
}