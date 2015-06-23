#pragma once
#include <glm/glm.hpp>

class Ray
{
public:
    glm::vec3 o;        // origin
    glm::vec3 d;        // direction
    
    Ray();
    ~Ray();
};