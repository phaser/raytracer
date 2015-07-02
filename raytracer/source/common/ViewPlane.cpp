#include <ViewPlane.h>

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
