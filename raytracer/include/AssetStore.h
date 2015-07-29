#pragma once
#include <qui/UniversalHashStore.h>

class Material;
class Light;
class BRDF;

class AssetStore
{
public:
    static AssetStore& Instance();
    qui::UniversalHashStore<std::shared_ptr<Material>>& GetMaterials() { return materials; }
private:
    AssetStore() {}
    static AssetStore _instance;
    qui::UniversalHashStore<std::shared_ptr<Material>> materials;
};