#pragma once
#include <geom/GeometricObject.h>
#include <glm/glm.hpp>

/** \brief The GeometricObject representing a Plane
 *
 * The plane is defined by a point a and a normal n. So any point p will lie inside
 * the plane if the normal is perpendicular on the vector \f$p - a\f$. So the equation
 * of the plane is:
 * \f[
 * (p - a) \cdot n = 0
 * \f]
 */
class Plane : public GeometricObject
{
public:
    Plane(const glm::vec3& point, const glm::vec3& norm);
    bool Hit(const Ray& ray, double& tmin, HitRec& hr) const;
    bool DidShadowHit(const Ray& ray, float& t);

private:
    glm::vec3 norm;
    glm::vec3 point;
    static const double kEpsilon;
    bool RayIntersects(const Ray& ray, float& tmin) const;
};

