#pragma once
#include <glm/glm.hpp>

class RGBColor
{
public:
    static RGBColor black;
    static RGBColor red;
    RGBColor();
    RGBColor(const glm::vec3& color);
    glm::vec3 GetRGBComponents() const;
    uint32_t GetRGBAIntPacked() const;
private:
    glm::vec3 color;
};
