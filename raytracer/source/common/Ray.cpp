#include <Ray.h>

Ray::Ray()
    : origin(glm::vec3(0.f, 0.f, 0.f))
    , direction(glm::vec3(0.f, 0.f, 1.f))
{
}

Ray::~Ray()
{
}
