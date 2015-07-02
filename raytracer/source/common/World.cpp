#include <World.h>
#include <ImageBufferPNG.h>
#include <ViewPlane.h>

World::World()
    : outputFileName(""), sceneFileName(""), imgBuffer(nullptr), vp(nullptr)
{    
}

World::~World()
{
    delete imgBuffer;
    delete vp;
}

World& World::SetOutputFilename(const char* outputfile)
{
    this->outputFileName = outputfile;
    return *this;
}

const std::string& World::GetOutputFilename()
{
    return this->outputFileName;
}

void World::RenderScene()
{
    for (int i = 0; i < imgBuffer->GetWidth(); i++)
    for (int j = 0; j < imgBuffer->GetHeight(); j++)
    {
        imgBuffer->SetPixel(i, j, 0xFF00FFFF);
    }
    imgBuffer->SaveToPngFile(outputFileName.c_str());
}

void World::Build()
{
    vp = new ViewPlane();
    vp->SetWidth(640)
       .SetHeight(480)
       .SetPixelSize(1.f);
    imgBuffer = new ImageBufferPNG(vp->GetWidth(), vp->GetHeight());
}

