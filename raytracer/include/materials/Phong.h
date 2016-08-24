#pragma once
#include <materials/Material.h>

class Lambertian;
class GlossySpecular;
class ImageBufferPNG;

class Phong : public Material
{
public:
    Phong();
    ~Phong();
    RGBColor shade(HitRec& hr);
    Phong& SetAmbient(Lambertian* ambient);
    Phong& SetDiffuse(Lambertian* diffuse);
    Phong& SetSpecular(GlossySpecular* specular);
    Phong& SetTexture(ImageBufferPNG *png);
    Phong& SetCheckered(bool);
private:
    Lambertian* ambient_brdf;
    Lambertian* diffuse_brdf;
    GlossySpecular* specular_brdf;
    ImageBufferPNG *png;
    bool checkered;
};