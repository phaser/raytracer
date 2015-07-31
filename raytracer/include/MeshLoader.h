#pragma once
#include <string>

class World;

class MeshLoader
{
public:
    MeshLoader(const std::string& filename, World* world);
    void ExecuteLoading();
private:
    std::string filename;
    World* world;
};