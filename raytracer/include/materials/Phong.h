#pragma once
#include <materials/Material.h>

class Lambertian;
class GlossySpecular;

class Phong : public Material
{
public:
    Phong();
    RGBColor shade(HitRec& hr);
    Phong& SetAmbient(Lambertian* ambient);
    Phong& SetDiffuse(Lambertian* diffuse);
    Phong& SetSpecular(GlossySpecular* specular);
private:
    Lambertian* ambient_brdf;
    Lambertian* diffuse_brdf;
    GlossySpecular* specular_brdf;
};