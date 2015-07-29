#pragma once
#include <lights/Light.h>
#include <RGBColor.h>

class PointLight : public Light
{
public:
    PointLight();
    glm::vec3 GetDirection(const HitRec& hr);
    RGBColor L(const HitRec& hr);
    bool IsInShadow(const Ray& ray, const HitRec& hr) const;
    PointLight& SetColor(const RGBColor& color);
    RGBColor GetColor() const;
    PointLight& SetLightIntensity(const float ls);
    float GetLightIntensity() const;
    PointLight& SetLocation(const glm::vec3& location);
    glm::vec3 GetLocation() const;

private:
    float ls;
    RGBColor color;
    glm::vec3 location;
};