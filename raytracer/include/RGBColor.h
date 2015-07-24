#pragma once
#include <glm/glm.hpp>

class RGBColor
{
public:
    static RGBColor black;
    static RGBColor red;
    static RGBColor yellow;
    RGBColor();
    RGBColor(const glm::vec3& color);
    glm::vec3 GetRGBComponents() const;
    uint32_t GetRGBAIntPacked() const;
    RGBColor operator+(const RGBColor& rhs);
    RGBColor operator+=(const RGBColor& rhs);
    RGBColor operator/=(int d);
private:
    glm::vec3 color;
};
