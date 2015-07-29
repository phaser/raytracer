#pragma once
#include <qui/UniversalHashStore.h>

class Material;
class Light;
class BRDF;

class AssetStore
{
public:
    static AssetStore& Instance();
    qui::UniversalHashStore<std::shared_ptr<Material>> materials;
    qui::UniversalHashStore<std::shared_ptr<Light>> lights;
    qui::UniversalHashStore<std::shared_ptr<BRDF>> brdfs;
private:
    AssetStore() {}
    static AssetStore _instance;
};