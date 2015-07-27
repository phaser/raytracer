#include <brdf/GlossySpecular.h>
#include <RGBColor.h>
#include <HitRec.h>

GlossySpecular::GlossySpecular()
    : ks(1.f)
    , exp(5.f)
{
    
}

GlossySpecular& GlossySpecular::SetKs(float ks)
{
    this->ks = ks;
    return *this;
}

RGBColor GlossySpecular::f(const HitRec& hr, const glm::vec3& wi, const glm::vec3& wo)
{
    RGBColor L;
    float ndotwi = glm::dot(hr.normal, wi);
    glm::vec3 r(-wi + 2.f * ndotwi * hr.normal);
    float rdotwo = glm::dot(r, wo);
    
    if (rdotwo > 0.f)
    {
        L = ks * glm::pow(rdotwo, exp);
    }
    return L;
}

RGBColor GlossySpecular::rho(const HitRec& hr, const glm::vec3& wo)
{
    return RGBColor::black;
}
