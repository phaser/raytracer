#include <MeshLoader.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <qui/Log.h>
#include <lights/PointLight.h>
#include <World.h>

MeshLoader::MeshLoader(const std::string& filename, World* world)
    : filename(filename)
    , world(world)
{
}

void MeshLoader::LoadLights(const aiScene *scene)
{
    for (size_t i = 0; i < scene->mNumLights; ++i)
    {
        aiLight *light = scene->mLights[i];
        switch (light->mType)
        {
            case (aiLightSource_AMBIENT):
            {
                LOG(INFO) << "Ambient ligth";
                break;
            }
            case (aiLightSource_SPOT):
            {
                LOG(INFO) << "Spot ligth";
                break;
            }
            case (aiLightSource_POINT):
            {
                LOG(INFO) << "Create a point ligth";
                aiNode *lightNode = scene->mRootNode->FindNode(light->mName);
                PointLight *pointlight = new PointLight();
                aiVector3D position = lightNode->mTransformation * light->mPosition;
                pointlight->SetLocation(glm::vec3(position.x, position.y, position.z))
                .SetColor(glm::vec3(light->mColorAmbient.r, light->mColorAmbient.g, light->mColorAmbient.b));
                LOG(INFO) << "Position: " << pointlight->GetLocation().x << " "
                                          << pointlight->GetLocation().y << " "
                                          << pointlight->GetLocation().z;
                LOG(INFO) << "Color: " << pointlight->GetColor().GetRGBComponents().x << " "
                                       << pointlight->GetColor().GetRGBComponents().y << " "
                                       << pointlight->GetColor().GetRGBComponents().z;
                this->world->AddLight(pointlight);
                break;
            }
            case (aiLightSource_DIRECTIONAL):
            {
                LOG(INFO) << "Directional ligth";
                break;
            }
            default:
            {
                LOG(WARNING) << "Unsupported light: " << light->mType;
            }
        }
    }
}

void MeshLoader::LoadMeshes(const aiScene* scene)
{
    for (size_t i = 0; i < scene->mNumMeshes; ++i)
    {
    }
}

void MeshLoader::ExecuteLoading()
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile("test.blend",
                                             aiProcess_Triangulate);
    if (!scene)
    {
        LOG(LERROR) << "Import failed: " << importer.GetErrorString();
    }
    
    LOG(INFO) << "Num meshes: " << scene->mNumMeshes;
    LOG(INFO) << "Num lights: " << scene->mNumLights;
    LOG(INFO) << "Num cameras " << scene->mNumCameras;

    LoadLights(scene);
    LoadMeshes(scene);
}
