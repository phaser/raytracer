#pragma once
#include <string>

class World;
class aiScene;

class MeshLoader
{
public:
    MeshLoader(const std::string& filename, World* world);
    void ExecuteLoading();
private:
    std::string filename;
    World* world;
    
    void LoadLights(const aiScene* scene);
    void LoadMeshes(const aiScene* scene);
};