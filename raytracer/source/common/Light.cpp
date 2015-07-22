#include <Light.h>

Light::Light()
: position(glm::vec3(0.f, 0.f, 0.f))
{
}

Light::Light(const glm::vec3& position)
: position(position)
{
}

/** \brief Getter for Light::position */
glm::vec3 Light::GetPosition() const
{
    return this->position;
}

/** \brief Setter for Light::position */
void Light::SetPosition(const glm::vec3& position)
{
    this->position = position;
}

RGBColor Light::GetColor()
{
    return this->color;
}

void Light::SetColor(const RGBColor& color)
{
    this->color = color;
}
