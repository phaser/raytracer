#pragma once
#include <glm/glm.hpp>

class RGBColor
{
public:
    static RGBColor black;
    RGBColor();
    RGBColor(const glm::vec3& color);
    glm::vec3 GetRGBComponents() const;
private:
    glm::vec3 color;
};
