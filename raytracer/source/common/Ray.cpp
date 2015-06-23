#include <Ray.h>

Ray::Ray()
    : o(glm::vec3(0.f, 0.f, 0.f))
    , d(glm::vec3(0.f, 0.f, 1.f))
{
}

Ray::~Ray()
{
}
