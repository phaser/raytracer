#pragma once
#include <string>

class World;
struct aiScene;
namespace Assimp {
    class Importer;
}

class MeshLoader
{
public:
    MeshLoader(const std::string& filename, World* world);
    ~MeshLoader();
    void ExecuteLoading();
private:
    std::string filename;
    World* world;
    Assimp::Importer *importer;
    
    void LoadLights(const aiScene* scene);
    void LoadMeshes(const aiScene* scene);
};