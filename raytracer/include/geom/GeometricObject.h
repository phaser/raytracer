#pragma once

class Ray;
class HitRec;
class RGBColor;

/** \brief GeometricObject is the parent of all the geometric primitives
 *         that the raytracer will interact with.
 *
 *   The object contains a pure virtual function Hit that is used to determine
 *   intersection points with the object.
 */
class GeometricObject
{
public:
    /** \brief The Hit function is used to intersect rays with the object.
     *
     * It is declared pure virtual so every object who inherits from GeometricObject
     * will be forced to implement this.
     *
     * \param ray is the ray that will be tested for intersection
     * \param tmin is an out parameter returning the minimum intersected t
     * \param hr is the HitRecord @see HitRec
     */
    virtual bool Hit(const Ray& ray, double& tmin, HitRec& hr) const =0;
    virtual RGBColor GetBaseColor() =0;
};