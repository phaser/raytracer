#pragma once
#include <string>
#include <RGBColor.h>
#include <geom/Sphere.h>

class ImageBufferPNG;
class ViewPlane;
class RayTracer;

class World
{
public:
    Sphere sphere;
    
    World();
    ~World();
    World& SetOutputFilename(const char* outputfile);
    const std::string& GetOutputFilename();
    void Build();
    void RenderScene();
private:
    std::string outputFileName;
    std::string sceneFileName;
    ImageBufferPNG* imgBuffer;
    ViewPlane* vp;
    RayTracer* tracerPtr;
    RGBColor backColor;
    
    void DisplayPixel(uint16_t i, uint16_t j, const RGBColor& color);
};