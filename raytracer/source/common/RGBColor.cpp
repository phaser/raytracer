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

void RGBColor::Clamp()
{
    this->color = glm::clamp(this->color, 0.f, 1.f);
}

RGBColor RGBColor::operator+(const RGBColor& rhs)
{
    RGBColor col(this->GetRGBComponents() + rhs.GetRGBComponents());
    return col;
}

RGBColor RGBColor::operator+=(const RGBColor& rhs)
{
    *this = *this + rhs;
    return *this;
}

RGBColor RGBColor::operator/=(int d)
{
    this->color.x /= (float)d;
    this->color.y /= (float)d;
    this->color.z /= (float)d;
    return *this;
}

RGBColor RGBColor::operator*(float op)
{
    RGBColor col(*this);
    col.color.x *= op;
    col.color.y *= op;
    col.color.z *= op;
    return col;
}

RGBColor RGBColor::operator*(const RGBColor& rhs)
{
    RGBColor col(*this);
    col.color.x *= rhs.color.x;
    col.color.y *= rhs.color.y;
    col.color.z *= rhs.color.z;
    return col;
}

RGBColor RGBColor::operator=(const glm::vec3& rhs)
{
    this->color = rhs;
    return *this;
}

RGBColor RGBColor::operator=(const float f)
{
    this->color.x = this->color.y = this->color.z = f;
    return *this;
}