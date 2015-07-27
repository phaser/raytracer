#include <brdf/Lambertian.h>
#include <RGBColor.h>
#include <glm/ext.hpp>

RGBColor Lambertian::f(const HitRec& hr, const glm::vec3& wi, const glm::vec3& wo)
{
    return cd * kd * glm::one_over_pi<float>();
}

RGBColor Lambertian::rho(const HitRec& hr, const glm::vec3& wo)
{
    return cd * kd;
}

Lambertian& Lambertian::SetKd(const float kd)
{
    this->kd = kd;
    return *this;
}

float Lambertian::GetKd() const
{
    return this->kd;
}

Lambertian& Lambertian::SetCd(const RGBColor& col)
{
    this->cd = col;
    return *this;
}

RGBColor Lambertian::GetCd() const
{
    return this->cd;
}
