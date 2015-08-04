#include <geom/AssimpMesh.h>
#include <assimp/scene.h>
#include <qui/log.h>
#include <glm/glm.hpp>

AssimpMesh::AssimpMesh(const aiScene* scene, aiMesh* mesh)
: GeometricObject()
, scene(scene)
, mesh(mesh)
{
}

inline void aiVectorToGlm(glm::vec3& v, const aiVector3D& r)
{
    v.x = r.x;
    v.y = r.y;
    v.z = r.z;
}

bool AssimpMesh::Hit(const Ray& ray, double& tmin, HitRec& hr) const
{
    size_t i = 0;
    size_t numIndices = mesh->mFaces[i].mNumIndices;
    if (numIndices > 3)
    {
        LOG(LERROR) << "A triangulated mesh was expected but it seems it isn't!";
        return false;
    }
    glm::vec3 normal;
    if (mesh->mNormals == NULL)
    {
        LOG(INFO) << "Normals missing! Compute the normal...";
    } else {
        aiVector3D vec = mesh->mNormals[mesh->mFaces[i].mIndices[0]];
        aiVectorToGlm(normal, vec);
    }
    
    return false;
}

bool AssimpMesh::DidShadowHit(const Ray& ray, float& t)
{
    return false;
}