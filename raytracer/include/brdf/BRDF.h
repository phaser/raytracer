#pragma once
#include <glm/glm.hpp>

class HitRec;
class RGBColor;

class BRDF
{
public:
    virtual RGBColor f(const HitRec& hr, const glm::vec3& wi, const glm::vec3& wo) =0;
    virtual RGBColor rho(const HitRec& hr, const glm::vec3& wo) =0;
    virtual ~BRDF() {}
};