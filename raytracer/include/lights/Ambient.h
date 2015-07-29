#pragma once
#include <lights/Light.h>
#include <RGBColor.h>

class Ambient : public Light
{
public:
    Ambient();
    glm::vec3 GetDirection(const HitRec& hr) override;
    RGBColor L(const HitRec& hr) override;
    Ambient& SetColor(const RGBColor& color);
    RGBColor GetColor() const;
    Ambient& SetLightIntensity(const float ls);
    float GetLightIntensity() const;
    bool IsInShadow(const Ray& ray, const HitRec& hr) const;
private:
    float ls;           /**< Parameter to tune the brightness of the light */
    RGBColor color;     /**< The color of the light. */
};