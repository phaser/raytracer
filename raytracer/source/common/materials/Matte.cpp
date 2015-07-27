#include <materials/Matte.h>
#include <RGBColor.h>
#include <HitRec.h>
#include <brdf/Lambertian.h>
#include <glm/glm.hpp>

Matte::Matte()
    : ambient_brdf(nullptr)
    , diffuse_brdf(nullptr)
{
}

RGBColor Matte::shade(HitRec& hr)
{
    glm::vec3 wo = -hr.ray.d;
    RGBColor L = ambient_brdf->rho(hr, wo) * hr.world.ambient_ptr->L(hr);
    size_t num_lights = hr.world.GetLights().size();
    for (int i = 0; i < num_lights; ++i)
    {
        glm::vec3 wi = hr.world.GetLights()[i]->GetDirection(hr);
        float ndotwi = glm::dot(hr.normal, wi);
        if (ndotwi > 0.f)
        {
            L += diffuse_brdf->f(hr, wi, wo) * hr.world.GetLights()[i]->L(hr) * ndotwi;
        }
    }
    return L;
}

Matte& Matte::SetAmbient(Lambertian* ambient)
{
    if (this->ambient_brdf != nullptr)
    {
        delete this->ambient_brdf;
    }
    this->ambient_brdf = ambient;
    return *this;
}

Matte& Matte::SetDiffuse(Lambertian* diffuse)
{
    if (this->diffuse_brdf != nullptr)
    {
        delete this->diffuse_brdf;
    }
    this->diffuse_brdf = diffuse;
    return *this;
}
