#include <ViewPlane.h>
#include <Ray.h>
#include <sampler/Sampler.h>

ViewPlane::ViewPlane()
    : width(320), height(240), s(1.f), gamma(1.f), inv_gamma(1.f), sampler_ptr(nullptr)
{
}

ViewPlane& ViewPlane::SetWidth(uint16_t width)
{
    this->width = width;
    return *this;
}

uint16_t ViewPlane::GetWidth() const
{
    return this->width;
}

ViewPlane& ViewPlane::SetHeight(uint16_t height)
{
    this->height = height;
    return *this;
}

uint16_t ViewPlane::GetHeight() const
{
    return this->height;
}

ViewPlane& ViewPlane::SetPixelSize(float pixsize)
{
    this->s = pixsize;
    return *this;
}

float ViewPlane::GetPixelSize() const
{
    return this->s;
}

Ray ViewPlane::GenerateRay(uint32_t x, uint32_t y)
{
    Ray ray;
    ray.o = glm::vec3(0.f, 0.f, this->focalDistance);
    glm::vec2 sp(0.f, 0.f);
    if (sampler_ptr != nullptr)
    {
        sp = sampler_ptr->GetNextSample();
    }
    double xp = this->GetPixelSize() * (x - 0.5 * (this->GetWidth() - 1.0) + sp.x);
    double yp = this->GetPixelSize() * (y - 0.5 * (this->GetHeight() - 1.0) + sp.y);
    glm::vec3 dir(xp, yp, 0.f);
    glm::vec3 ndir = dir - ray.o;
    ndir = glm::normalize(ndir);
    ray.d = ndir;
    return ray;
}

void ViewPlane::SetFocalDistance(float focalDistance)
{
    this->focalDistance = focalDistance;
}

float ViewPlane::GetFocalDistance() const
{
    return focalDistance;
}

Sampler* ViewPlane::GetSamplerPtr() const
{
    return this->sampler_ptr;
}

void ViewPlane::SetSamplerPtr(Sampler* sampler)
{
    if (this->sampler_ptr != nullptr)
    {
        delete sampler_ptr;
    }
    sampler->GenerateSamples();
    this->sampler_ptr = sampler;
}
