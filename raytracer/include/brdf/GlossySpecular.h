#pragma once
#include <brdf/BRDF.h>

class GlossySpecular : public BRDF
{
public:
    GlossySpecular();
    GlossySpecular& SetKs(float ks);
    RGBColor f(const HitRec& hr, const glm::vec3& wi, const glm::vec3& wo);
    RGBColor rho(const HitRec& hr, const glm::vec3& wo);
private:
    float ks;
    float exp;
};