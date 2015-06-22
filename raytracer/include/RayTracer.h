#pragma once
#include <string>
#include <memory>

class ImageBufferPNG;

class RayTracer
{
public:
    RayTracer();
    RayTracer(const std::string& outputFileName, const std::string& sceneFileName);
    ~RayTracer();
    void InitImageBuffer(uint16_t width, uint16_t height);
    void SetOutputFileName(const std::string& outputFileName);
    std::string GetOutputFileName() const;
    void RayTrace();
private:
    std::string outputFileName;
    std::string sceneFileName;
    ImageBufferPNG* imgBuffer;
};