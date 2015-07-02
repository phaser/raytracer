#include <RGBColor.h>

RGBColor RGBColor::black(glm::vec3(0.f, 0.f, 0.f));
RGBColor::RGBColor()
    : color(glm::vec3(0.f, 0.f, 0.f))
{
}

RGBColor::RGBColor(const glm::vec3& color)
    : color(color)
{
}

