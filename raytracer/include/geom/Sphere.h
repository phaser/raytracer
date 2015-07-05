#pragma once
#include <geom/GeometricObject.h>
#include <glm/glm.hpp>

class Sphere : GeometricObject
{
public:
    bool Hit(const Ray& ray, double& tmin, HitRec& hr) const;
    void SetCenter(const glm::vec3& center);
    void SetRadius(double radius);
private:
    glm::vec3 center;
    double radius;
    static const double kEpsilon;
};