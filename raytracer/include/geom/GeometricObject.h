#pragma once
#include <materials/Material.h>
#include <string>

class Ray;
class HitRec;
class Material;

/** \brief GeometricObject is the parent of all the geometric primitives
 *         that the raytracer will interact with.
 *
 *   The object contains a pure virtual function Hit that is used to determine
 *   intersection points with the object.
 */
class GeometricObject
{
public:
    GeometricObject();
    ~GeometricObject();
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
    virtual std::string& GetMaterial();
    virtual GeometricObject& SetMaterial(const std::string& material);
    virtual bool DidShadowHit(const Ray& ray, double& t) =0;
protected:
    std::string material;
};