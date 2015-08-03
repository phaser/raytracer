#include <geom/AssimpMesh.h>

AssimpMesh::AssimpMesh(aiScene* scene, aiMesh* mesh)
: GeometricObject()
, scene(scene)
, mesh(mesh)
{
}

bool AssimpMesh::Hit(const Ray& ray, double& tmin, HitRec& hr) const
{
    return false;
}

bool AssimpMesh::DidShadowHit(const Ray& ray, float& t)
{
    return false;
}