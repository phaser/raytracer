#pragma once
#include <string>

class ImageBufferPNG;
class ViewPlane;

class World
{
public:
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
};