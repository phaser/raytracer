#include <lights/PointLight.h>
#include <RGBColor.h>
#include <HitRec.h>

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
