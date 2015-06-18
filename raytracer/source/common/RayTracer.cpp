#include <RayTracer.h>
#include <ImageBufferPNG.h>

RayTracer::RayTracer() : outputFileName(""), sceneFileName("")
{
}

RayTracer::RayTracer(const std::string& outputFileName, const std::string& sceneFileName)
: outputFileName(outputFileName), sceneFileName(sceneFileName)
{
}

void RayTracer::InitImageBuffer(uint16_t width, uint16_t height)
{
    imgBuffer = std::unique_ptr<ImageBufferPNG>(new ImageBufferPNG(width, height));
}

void RayTracer::SetOutputFileName(const std::string& outputFileName)
{
    this->outputFileName = outputFileName;
}

std::string RayTracer::GetOutputFileName() const
{
    return this->outputFileName;
}

void RayTracer::RayTrace()
{
    for (int i = 0; i < imgBuffer->GetWidth(); i++)
    for (int j = 0; j < imgBuffer->GetHeight(); j++)
    {
        imgBuffer->SetPixel(i, j, 0xFF00FFFF);
    }
    imgBuffer->SaveToPngFile(outputFileName.c_str());
}