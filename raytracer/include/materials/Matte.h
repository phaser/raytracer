#pragma once
#include <materials/Material.h>

class Lambertian;

class Matte : public Material
{
public:
    Matte();
    RGBColor shade(HitRec& hr);
    Matte& SetAmbient(Lambertian* ambient);
    Matte& SetDiffuse(Lambertian* diffuse);
private:
    Lambertian* ambient_brdf;
    Lambertian* diffuse_brdf;
};