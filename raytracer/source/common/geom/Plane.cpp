#include <geom/Plane.h>
#include <Ray.h>
#include <HitRec.h>
#include <RGBColor.h>
#include <cstdio>

const double Plane::kEpsilon = 0.1;

Plane::Plane(const glm::vec3& point, const glm::vec3& norm)
: norm(norm), point(point)
{
}

/** \brief The hit function for the plane:
 *
 * The equation of the plane is \f$(p - a) \cdot n = 0\f$
 * If we substituthe the equation of the ray \f$o + td = 0\f$ and solve the equation for t
 * we obtain \f$t = \frac{(a - o)n}{d \cdot n}\f$
 */
bool Plane::Hit(const Ray& ray, double& tmin, HitRec& hr) const
{
    double t;
    bool result = RayIntersects(ray, t);
    if (result)
    {
        tmin = t;
        hr.normal = norm;
        hr.hitPoint = ray.o + (float)tmin * ray.d;
    }
    return result;
}

bool Plane::DidShadowHit(const Ray& ray, double& tmin)
{
    bool hit = RayIntersects(ray, tmin);
    return hit;
}

bool Plane::RayIntersects(const Ray& ray, double& tmin) const
{
    glm::vec3 tmp = point - ray.o;
    double a = glm::dot(tmp, norm);
    double b = glm::dot(ray.d, norm);
    double t = a / b;
    if (t > kEpsilon)
    {
        tmin = t;
        return true;
    }
    return false;
}
