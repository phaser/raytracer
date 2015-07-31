#include <MeshLoader.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <qui/Log.h>

MeshLoader::MeshLoader(const std::string& filename, World* world)
    : filename(filename)
    , world(world)
{
}

void MeshLoader::ExecuteLoading()
{
    // Test assimp
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
    // end test
    
}
