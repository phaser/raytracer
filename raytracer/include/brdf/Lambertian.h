#pragma once
#include <brdf/BRDF.h>
#include <RGBColor.h>

class Lambertian : public BRDF
{
public:
    Lambertian();
    RGBColor f(const HitRec& hr, const glm::vec3& wi, const glm::vec3& wo) override;
    RGBColor rho(const HitRec& hr, const glm::vec3& wo);
    Lambertian& SetKd(const float kd);
    float GetKd() const;
    Lambertian& SetCd(const RGBColor& col);
    RGBColor GetCd() const;
private:
    float kd;
    RGBColor cd;
};