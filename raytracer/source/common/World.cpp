#include <World.h>
#include <ImageBufferPNG.h>
#include <ViewPlane.h>
#include <tracer/SingleSphere.h>
#include <Ray.h>

World::World()
    : outputFileName("")
    , sceneFileName("")
    , imgBuffer(nullptr)
    , vp(nullptr)
    , backColor(RGBColor::black)
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
    RGBColor pixel_color;
    Ray ray;
    double zw = 100.0;
    double x, y;
    
    ray.d = glm::vec3(0, 0, -1);
    
    for (int i = 0; i < vp->GetWidth(); i++)
    for (int j = 0; j < vp->GetHeight(); j++)
    {
        x = vp->GetPixelSize() * (i - 0.5 * (vp->GetWidth() - 1.0));
        y = vp->GetPixelSize() * (j - 0.5 * (vp->GetHeight() - 1.0));
        ray.o = glm::vec3(x, y, zw);
        pixel_color = tracerPtr->TraceRay(ray);
        DisplayPixel(i, j, pixel_color);
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
    tracerPtr = new SingleSphere(this);
    sphere.SetCenter(glm::vec3(0.f, 0.f, 0.f));
    sphere.SetRadius(85.0);
    outputFileName = "SingleSphere.png";
}

void World::DisplayPixel(uint16_t i, uint16_t j, const RGBColor& color)
{
    imgBuffer->SetPixel(i, j, color.GetRGBAIntPacked());
}

RGBColor World::GetBackground()
{
    return this->backColor;
}

void World::AddObject(GeometricObject* obj)
{
    objects.push_back(obj);
}

std::vector<GeometricObject*>& World::GetObjects()
{
    return objects;
}
