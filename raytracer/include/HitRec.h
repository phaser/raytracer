#pragma once
#include <glm/glm.hpp>
#include <World.h>
#include <Ray.h>

class HitRec
{
public:
    bool        didHit;        /**< did the ray hit an object */
    glm::vec3   hitPoint;      /**< world coordinates of hit point */
    glm::vec3   normal;        /**< normal at hit point */
    World&      world;         /**< Reference to World */
    Ray         ray;           /**< Reference to Ray */
    glm::vec2   uv;            /**< UV mapping */
    
    explicit HitRec(World& w);
    HitRec(const HitRec& co);
    HitRec& operator=(const HitRec& rhs);
};