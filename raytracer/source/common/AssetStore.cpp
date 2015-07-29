#include <AssetStore.h>

AssetStore AssetStore::_instance;

AssetStore& AssetStore::Instance()
{
    return _instance;
}
