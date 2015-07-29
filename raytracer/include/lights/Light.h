#pragma once
#include <glm/glm.hpp>

class HitRec;
class RGBColor;
class Ray;

/** \brief The class that models a light in the scene. */
class Light
{
public:
    virtual ~Light() {}
    /** \brief Returns the direction of the light at hitpoint */
    virtual glm::vec3 GetDirection(const HitRec& hr) =0;
    /** \brief Return the radiance of the light at hitpoint */
    virtual RGBColor L(const HitRec& hr) =0;
    /** \brief Intersects the shadow ray with all the objects */
    virtual bool IsInShadow(const Ray& ray, const HitRec& hr) const =0;
    
protected:
    bool shadows;
};