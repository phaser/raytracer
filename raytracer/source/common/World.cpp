#include <World.h>
#include <ImageBufferPNG.h>
#include <ViewPlane.h>
#include <tracer/MultiObjects.h>
#include <Ray.h>
#include <geom/Plane.h>
#include <sampler/Regular.h>
#include <sampler/Jitter.h>
#include <lights/Light.h>
#include <lights/Ambient.h>
#include <brdf/Lambertian.h>
#include <brdf/GlossySpecular.h>
#include <materials/Matte.h>
#include <materials/Phong.h>
#include <lights/PointLight.h>
#include <glm/ext.hpp>
#include <AssetStore.h>
#include <qui/Log.h>
#include <MeshLoader.h>

World::World()
    : ambient_ptr(nullptr)
    , outputFileName("")
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
    delete ambient_ptr;
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
    LOG(INFO) << "ViewPlane: " << vp->GetWidth() << "x" << vp->GetHeight();
    LOG(INFO) << "Output file: " << outputFileName;
    RGBColor pixel_color(glm::vec3(0.f, 0.f, 0.f));
    Ray ray;
    
    for (int i = 0; i < vp->GetWidth(); i++)
    for (int j = 0; j < vp->GetHeight(); j++)
    {
        size_t sz = (vp->GetSamplerPtr() != nullptr ? vp->GetSamplerPtr()->GetNumSamples() : 1);
        pixel_color = glm::vec3(0.f, 0.f, 0.f);
        for (int k = 0; k < sz; ++k)
        {
            pixel_color += tracerPtr->TraceRay(vp->GenerateRay(i, j));
        }
        pixel_color /= sz;
        DisplayPixel(i, j, pixel_color);
    }
    imgBuffer->SaveToPngFile(outputFileName.c_str());
}

/** \brief The build function is used to create all the objects in the scene. */
void World::Build()
{
    MeshLoader ml("test.blend", this);
    ml.ExecuteLoading();
    #include <scenes/Scene_Blender.h>
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

void World::AddLight(Light* light)
{
    this->lights.push_back(light);
}

std::vector<Light*>& World::GetLights()
{
    return lights;
}
