#include <materials/Phong.h>
#include <RGBColor.h>
#include <HitRec.h>
#include <brdf/Lambertian.h>
#include <brdf/GlossySpecular.h>
#include <glm/glm.hpp>

Phong::Phong()
: ambient_brdf(nullptr)
, diffuse_brdf(nullptr)
, specular_brdf(nullptr)
{
}

RGBColor Phong::shade(HitRec& hr)
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
            RGBColor col = diffuse_brdf->f(hr, wi, wo) + specular_brdf->f(hr, wi, wo);
            L += col * hr.world.GetLights()[i]->L(hr) * ndotwi;
        }
    }
    return L;
}

Phong& Phong::SetAmbient(Lambertian* ambient)
{
    if (this->ambient_brdf != nullptr)
    {
        delete this->ambient_brdf;
    }
    this->ambient_brdf = ambient;
    return *this;
}

Phong& Phong::SetDiffuse(Lambertian* diffuse)
{
    if (this->diffuse_brdf != nullptr)
    {
        delete this->diffuse_brdf;
    }
    this->diffuse_brdf = diffuse;
    return *this;
}

Phong& Phong::SetSpecular(GlossySpecular* specular)
{
    if (this->specular_brdf != nullptr)
    {
        delete this->specular_brdf;
    }
    this->specular_brdf = specular;
    return *this;
}