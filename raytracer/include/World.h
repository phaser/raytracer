#pragma once
#include <string>
#include <RGBColor.h>
#include <geom/Sphere.h>
#include <vector>
#include <lights/Light.h>
#include <thread>

class ImageBufferPNG;
class ViewPlane;
class RayTracer;
class GeometricObject;
class MeshLoader;

class World
{
public:
    Sphere sphere;
    Light* ambient_ptr;
    
    World();
    ~World();
    World& SetOutputFilename(const char* outputfile);
    const std::string& GetOutputFilename();
    void Build();
    void RenderScene();
    RGBColor GetBackground();
    void AddObject(GeometricObject* obj);
    std::vector<GeometricObject*>& GetObjects();
    void AddLight(Light* light);
    std::vector<Light*>& GetLights();
private:
    std::string outputFileName;
    std::string sceneFileName;
    ImageBufferPNG* imgBuffer;
    ViewPlane* vp;
    RayTracer* tracerPtr;
    RGBColor backColor;
    std::vector<GeometricObject*> objects;
    std::vector<Light*> lights;
    MeshLoader *meshLoader;
    std::vector<std::thread> threads;
    std::atomic_uint finishedThreads;
    
    void RenderLines(size_t b, size_t e);
    void DisplayPixel(uint16_t i, uint16_t j, const RGBColor& color);
};
