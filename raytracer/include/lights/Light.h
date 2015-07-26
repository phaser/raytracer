#pragma once
#include <glm/glm.hpp>
#include <RGBColor.h>

/** \brief The class that models a light in the scene. */
class Light
{
public:
    Light();
    Light(const glm::vec3& position);
    glm::vec3 GetPosition() const;
    void SetPosition(const glm::vec3& position);
    glm::vec3 GetDirection() const;
    void SetDirection(const glm::vec3& direction);
private:
    glm::vec3 position;       /**< The position of the light. */
    glm::vec3 direction;      /**< The direction of the light. */
};