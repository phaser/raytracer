#pragma once
#include <geom/GeometricObject.h>
#include <glm/glm.hpp>
#include <RGBColor.h>

class Sphere : public GeometricObject
{
public:
    RGBColor baseColor;
    bool Hit(const Ray& ray, double& tmin, HitRec& hr) const override;
    void SetCenter(const glm::vec3& center);
    void SetRadius(double radius);
    bool DidShadowHit(const Ray& ray, double& t) override;
private:
    glm::vec3 center;
    double radius;
    static const double kEpsilon;
};