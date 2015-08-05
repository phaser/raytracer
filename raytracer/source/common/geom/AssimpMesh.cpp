#include <geom/AssimpMesh.h>
#include <assimp/scene.h>
#include <qui/log.h>
#include <glm/glm.hpp>
#include <Ray.h>
#include <HitRec.h>
#include <limits>

const double AssimpMesh::kEpsilon = 0.1;

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
    aiNode* meshNode = scene->mRootNode->FindNode(mesh->mName);
    aiMatrix4x4 transformMat = meshNode->mTransformation;
    bool intersects = false;
    tmin = std::numeric_limits<double>::infinity();
    for (size_t i = 0; i < mesh->mNumFaces; ++i)
    {
        size_t numIndices = mesh->mFaces[i].mNumIndices;
        if (numIndices > 3)
        {
            LOG(LERROR) << "A triangulated mesh was expected but it seems it isn't!";
            continue;
        }
        glm::vec3 v0, v1, v2;
        aiVectorToGlm(v0, transformMat * mesh->mVertices[mesh->mFaces[i].mIndices[0]]);
        aiVectorToGlm(v1, transformMat * mesh->mVertices[mesh->mFaces[i].mIndices[1]]);
        aiVectorToGlm(v2, transformMat * mesh->mVertices[mesh->mFaces[i].mIndices[2]]);
        glm::vec3 normal;
        glm::vec3 v0v1 = v1 - v0;
        glm::vec3 v0v2 = v2 - v0;
        normal = glm::cross(v0v1, v0v2);
        normal = glm::normalize(normal);

        glm::vec3 tmp = v0 - ray.o;
        double a = glm::dot(tmp, normal);
        double b = glm::dot(ray.d, normal);
        double t = a / b;
        if (t > kEpsilon)
        {
            if (t > tmin) continue;
            
            glm::vec3 P = ray.o + (float)t * ray.d;
            glm::vec3 C;
            //LOG(INFO) << "Hit: " << P.x << " " << P.y << " " << P.z;
            
            // edge 0
            glm::vec3 edge0 = v1 - v0;
            glm::vec3 vp0 = P - v0;
            C = glm::cross(edge0, vp0);
            if (glm::dot(normal, C) < 0) continue;
            
            //edge 1
            glm::vec3 edge1 = v2 - v1;
            glm::vec3 vp1 = P - v1;
            C = glm::cross(edge1, vp1);
            if (glm::dot(normal, C) < 0) continue;
            
            //edge 2
            glm::vec3 edge2 = v0 - v2;
            glm::vec3 vp2 = P - v2;
            C = glm::cross(edge2, vp2);
            if (glm::dot(normal, C) < 0) continue;
            
            tmin = t;
            hr.normal = normal;
            hr.hitPoint = P;
            //LOG(INFO) << "Hit: " << P.x << " " << P.y << " " << P.z;
            intersects = true;
        }
    }
    return intersects;
}

bool AssimpMesh::DidShadowHit(const Ray& ray, float& t)
{
    return false;
}