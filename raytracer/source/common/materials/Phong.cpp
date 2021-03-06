#include <materials/Phong.h>
#include <RGBColor.h>
#include <HitRec.h>
#include <brdf/Lambertian.h>
#include <brdf/GlossySpecular.h>
#include <glm/glm.hpp>
#include <ImageBufferPNG.h>

Phong::Phong()
: ambient_brdf(nullptr)
, diffuse_brdf(nullptr)
, specular_brdf(nullptr)
, png(nullptr)
, checkered(false)
{
}

Phong::~Phong()
{
    delete ambient_brdf;
    delete diffuse_brdf;
    delete specular_brdf;
    delete png;
}

RGBColor Phong::shade(HitRec& hr)
{
#define UNIT 50
#define HALF_UNIT 25
    glm::vec3 wo = -hr.ray.d;
    RGBColor L(glm::vec3(0));
    if (png == nullptr)
    {
        float intensity = 1.f;
        if (checkered)
        {
            glm::vec3 mhp;
            mhp.x = (int)glm::abs((int)hr.hitPoint.x % UNIT);
            mhp.y = (int)glm::abs((int)hr.hitPoint.y % UNIT);
            mhp.z = (int)glm::abs((int)hr.hitPoint.z % UNIT);
            bool cond = (glm::abs((int)mhp.x / HALF_UNIT) % 2) != (glm::abs((int)mhp.z / HALF_UNIT) % 2);
            bool cond2 = ((int)glm::abs(mhp.x) < HALF_UNIT || (int)glm::abs(mhp.z) < HALF_UNIT);
            bool cond3 = cond && cond2;
            if (hr.hitPoint.x < 0)
            {
                cond3 = !cond3;
            }
            if (cond3)
            {
                intensity = 1.5f;
            }
        }
        L = ambient_brdf->rho(hr, wo) * hr.world.ambient_ptr->L(hr) * intensity;
    } else {
        float u = png->GetWidth() * hr.uv.x;
        float v = png->GetHeight() * hr.uv.y;
        ambient_brdf->SetCd(png->GetPixel((int)u, (int)v));
        L = ambient_brdf->rho(hr, wo) * hr.world.ambient_ptr->L(hr);
    }
    
    size_t num_lights = hr.world.GetLights().size();
    for (int i = 0; i < num_lights; ++i)
    {
        glm::vec3 wi = hr.world.GetLights()[i]->GetDirection(hr);
        float ndotwi = glm::dot(hr.normal, wi);
        if (ndotwi > 0.f)
        {
            Ray shadowRay;
            shadowRay.o = hr.hitPoint;
            shadowRay.d = wi;
            bool inShadow = hr.world.GetLights()[i]->IsInShadow(shadowRay, hr);
            
            if (!inShadow)
            {
                RGBColor col;
                if (png == nullptr)
                {
                    col = diffuse_brdf->f(hr, wi, wo) + specular_brdf->f(hr, wi, wo);
                    L += col * hr.world.GetLights()[i]->L(hr) * ndotwi;
                } else
                {
                    float u = png->GetWidth() * hr.uv.x;
                    float v = png->GetHeight() * hr.uv.y;
                    diffuse_brdf->SetCd(png->GetPixel((int)u, (int)v));
                    col = diffuse_brdf->f(hr, wi, wo) + specular_brdf->f(hr, wi, wo);
                    L += col * hr.world.GetLights()[i]->L(hr) * ndotwi;
                }
 
            }
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

Phong& Phong::SetTexture(ImageBufferPNG *png)
{
    if (this->png != nullptr)
    {
        delete this->png;
    }
    this->png = png;
    return *this;
}

Phong& Phong::SetCheckered(bool value)
{
    checkered = value;
    return *this;
}