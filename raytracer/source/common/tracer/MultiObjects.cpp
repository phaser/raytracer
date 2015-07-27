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
        glm::vec3 col = glm::clamp(obj_min->GetBaseColor().GetRGBComponents() * 0.2f + obj_min->GetBaseColor().GetRGBComponents()
                                   * (glm::dot(sr_min.normal, glm::normalize(glm::vec3(-1.f, -1.f, 1.f))))
                                     , 0.f, 1.f
                                    );
        return RGBColor(col);
    }
    return RGBColor::black;
}