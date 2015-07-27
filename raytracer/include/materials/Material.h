#pragma once

class HitRec;
class RGBColor;

class Material
{
public:
    virtual RGBColor shade(HitRec& hr) =0;
    virtual ~Material() {}
};