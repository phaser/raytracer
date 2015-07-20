#include <RGBColor.h>

RGBColor RGBColor::black(glm::vec3(0.f, 0.f, 0.f));
RGBColor RGBColor::red(glm::vec3(1.f, 0.f, 0.f));
RGBColor RGBColor::yellow(glm::vec3(0.5, 0.5, 0.f));

RGBColor::RGBColor()
    : color(glm::vec3(0.f, 0.f, 0.f))
{
}

RGBColor::RGBColor(const glm::vec3& color)
    : color(color)
{
}

glm::vec3 RGBColor::GetRGBComponents() const
{
    return this->color;
}

uint32_t RGBColor::GetRGBAIntPacked() const
{
    uint32_t col = 0;
    col = col | ((uint32_t)(color.x * 0xFF));
    col = col | ((uint32_t)(color.y * 0xFF) << 8);
    col = col | ((uint32_t)(color.z * 0xFF) << 16);
    col = col | (0xFF << 24);
    return col;
}
