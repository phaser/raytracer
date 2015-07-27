#include <geom/Sphere.h>
#include <Ray.h>
#include <HitRec.h>
#include <RGBColor.h>
#include <materials/Material.h>

const double Sphere::kEpsilon = 0.1;

bool Sphere::Hit(const Ray& ray, double& tmin, HitRec& hr) const
{
    double t;
    glm::vec3 temp = ray.o - center;
    double a = glm::dot(ray.d, ray.d);
    double b = glm::dot(2.0f * temp, ray.d);
    double c = glm::dot(temp, temp) - radius * radius;
    double disc = b * b - 4.0f * a * c;
    
    if (disc < 0.0)
    {
        return false;
    } else
    {
        double e = sqrt(disc);
        double denom = 2.0 * a;
        t = (-b - e) / denom;       // smaller root
        
        if (t > kEpsilon)
        {
            tmin = t;
            //hr.normal = (temp + static_cast<float>(t) * ray.d) * static_cast<float>((1.0f/radius));
            hr.hitPoint = ray.o + static_cast<float>(t) * ray.d;
            hr.normal = glm::normalize(hr.hitPoint - center);
            return true;
        }
        
        t = (-b + e) / denom;       // larger root
        if (t > kEpsilon)
        {
            tmin = t;
            //hr.normal = (temp + static_cast<float>(t) * ray.d) * static_cast<float>((1.0f/radius));
            hr.hitPoint = ray.o + static_cast<float>(t) * ray.d;
            hr.normal = glm::normalize(hr.hitPoint - center);
            return true;
        }
    }
    return false;
}

void Sphere::SetCenter(const glm::vec3& center)
{
    this->center = center;
}

void Sphere::SetRadius(double radius)
{
    this->radius = radius;
}
