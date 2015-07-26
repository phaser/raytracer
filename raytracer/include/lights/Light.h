#pragma once
#include <glm/glm.hpp>

class HitRec;
class RGBColor;

/** \brief The class that models a light in the scene. */
class Light
{
public:
    /** \brief Returns the direction of the light at hitpoint */
    virtual glm::vec3 GetDirection(const HitRec& hr) =0;
    /** \brief Return the radiance of the light at hitpoint */
    virtual RGBColor L(const HitRec& hr) =0;
protected:
    bool shadows;
};