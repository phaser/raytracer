#pragma once
#include <glm/glm.hpp>

class HitRec
{
public:
    bool        didHit;        // did the ray hit an object
    glm::vec3   hitPoint;      // world coordinates of hit point
    glm::vec3   normal;
    
    HitRec();
};