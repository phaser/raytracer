#include <World.h>
#include <ImageBufferPNG.h>
#include <ViewPlane.h>
#include <tracer/MultiObjects.h>
#include <Ray.h>
#include <geom/Plane.h>


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
    
    for (int i = 0; i < vp->GetWidth(); i++)
    for (int j = 0; j < vp->GetHeight(); j++)
    {
        pixel_color = tracerPtr->TraceRay(vp->GenerateRay(i, j));
        DisplayPixel(i, j, pixel_color);
    }
    imgBuffer->SaveToPngFile(outputFileName.c_str());
}

/** \brief The build function is used to create all the objects in the scene. */
void World::Build()
{
    vp = new ViewPlane();
    vp->SetWidth(640)
       .SetHeight(480)
       .SetPixelSize(1.f);
    vp->SetFocalDistance(800.f);
    imgBuffer = new ImageBufferPNG(vp->GetWidth(), vp->GetHeight());
    tracerPtr = new MultiObjects(this);
    
    sphere.SetCenter(glm::vec3(0.f, 0.f, 0.f));
    sphere.SetRadius(85.0);
    Sphere *msphere = new Sphere();
    msphere->SetCenter(glm::vec3(-100.f, -100.f, -100.f));
    msphere->SetRadius(85.0);
    msphere->baseColor = RGBColor::red;
    this->AddObject(msphere);
    msphere = new Sphere();
    msphere->SetCenter(glm::vec3(100.f, -100.f, -100.f));
    msphere->SetRadius(65.f);
    msphere->baseColor = RGBColor::yellow;
    this->AddObject(msphere);
    Plane* plane = new Plane(glm::vec3(0.f, 50.f, -10.f), glm::vec3(0.f, -1.0f, 0.f));
    this->AddObject(plane);
    
    Light light;
    light.SetPosition(glm::vec3(100.f, -100.f, 100.f));
    light.SetDirection(glm::vec3(10.f, -10.f, 10.f));
    this->AddLight(light);
    
    outputFileName = "MultiObject.png";
}

/** \brief It is a separate function because it should be used to perform gamma correction. Right now
  *        it doesn't.
  */
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

void World::AddLight(const Light& light)
{
    this->lights.push_back(light);
}

std::vector<Light>& World::GetLights()
{
    return lights;
}
