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
    HitRec sr_min;
    
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
        glm::vec3 col = obj_min->GetBaseColor().GetRGBComponents() + world->GetLights()[0].GetColor().GetRGBComponents() * glm::clamp(glm::dot(world->GetLights()[0].GetPosition(), sr_min.normal), 0.f, 1.f);
        return RGBColor(col);
    }
    return RGBColor::black;
}