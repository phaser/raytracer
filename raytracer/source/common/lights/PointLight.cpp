#include <lights/PointLight.h>
#include <RGBColor.h>
#include <HitRec.h>
#include <geom/GeometricObject.h>

PointLight::PointLight()
    : ls(1.f)
    , color(RGBColor(glm::vec3(1.f)))
    , location(glm::vec3(0.f))
{
}

glm::vec3 PointLight::GetDirection(const HitRec& hr)
{
    return glm::normalize(location - hr.hitPoint);
}

RGBColor PointLight::L(const HitRec& hr)
{
    return color * ls;
}

PointLight& PointLight::SetColor(const RGBColor& color)
{
    this->color = color;
    return *this;
}

RGBColor PointLight::GetColor() const
{
    return this->color;
}

PointLight& PointLight::SetLightIntensity(const float ls)
{
    this->ls = ls;
    return *this;
}

float PointLight::GetLightIntensity() const
{
    return this->ls;
}

PointLight& PointLight::SetLocation(const glm::vec3& location)
{
    this->location = location;
    return *this;
}

glm::vec3 PointLight::GetLocation() const
{
    return this->location;
}

bool PointLight::IsInShadow(const Ray& ray, const HitRec& hr) const
{
    double t;
    size_t num_objects = hr.world.GetObjects().size();
    float d = glm::distance(location, ray.o);
    for (size_t i = 0; i < num_objects; ++i)
    {
        if (hr.world.GetObjects()[i]->DidShadowHit(ray, t) && t < d)
        {
            return true;
        }
    }
    return false;
}
