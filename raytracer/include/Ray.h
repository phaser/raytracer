#pragma once
#include <glm/glm.hpp>

/** \brief Class modelling a ray.
 *
 * The equation of the ray:
 * \f[
 *  point = origin + t \cdot direction
 * \f]
 * In order to find the intersection of the ray with various implicit surfaces \f$ f(p) = 0 \f$ we have 
 * to substitute the equation of the ray and solve for t: \f$ f(origin + t \cdot direction) = 0 \f$
 */
class Ray
{
public:
    glm::vec3 o;        /**< origin */
    glm::vec3 d;        /**< direction */
    
    Ray();
    ~Ray();
};