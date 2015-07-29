#include <lights/Ambient.h>

Ambient::Ambient()
    : ls(1.f)
    , color(glm::vec3(1.f))
{
}

glm::vec3 Ambient::GetDirection(const HitRec& hr)
{
    return glm::vec3(0.f);
}

RGBColor Ambient::L(const HitRec& hr)
{
    return (color * ls);
}

Ambient& Ambient::SetColor(const RGBColor& color)
{
    this->color = color;
    return *this;
}

RGBColor Ambient::GetColor() const
{
    return this->color;
}

Ambient& Ambient::SetLightIntensity(const float ls)
{
    this->ls = ls;
    return *this;
}

float Ambient::GetLightIntensity() const
{
    return this->ls;
}

bool Ambient::IsInShadow(const Ray& ray, const HitRec& hr) const
{
    return false;
}