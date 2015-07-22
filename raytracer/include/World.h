#pragma once
#include <string>
#include <RGBColor.h>
#include <geom/Sphere.h>
#include <vector>
#include <Light.h>

class ImageBufferPNG;
class ViewPlane;
class RayTracer;
class GeometricObject;

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
    RGBColor GetBackground();
    void AddObject(GeometricObject* obj);
    std::vector<GeometricObject*>& GetObjects();
    void AddLight(const Light& light);
    std::vector<Light>& GetLights();
private:
    std::string outputFileName;
    std::string sceneFileName;
    ImageBufferPNG* imgBuffer;
    ViewPlane* vp;
    RayTracer* tracerPtr;
    RGBColor backColor;
    std::vector<GeometricObject*> objects;
    std::vector<Light> lights;

    void DisplayPixel(uint16_t i, uint16_t j, const RGBColor& color);
};
