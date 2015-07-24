#include <ViewPlane.h>
#include <Ray.h>

ViewPlane::ViewPlane()
    : width(320), height(240), s(1.f), gamma(1.f), inv_gamma(1.f)
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
    glm::vec3(0.f, 0.f, this->focalDistance);
    ray.o = glm::vec3(0.f, 0.f, this->focalDistance);;
    double xp = this->GetPixelSize() * (x - 0.5 * (this->GetWidth() - 1.0));
    double yp = this->GetPixelSize() * (y - 0.5 * (this->GetHeight() - 1.0));
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
