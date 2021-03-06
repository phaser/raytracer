/*
#include <geom/AssimpMesh.h>
#include <assimp/scene.h>
#include <qui/log.h>
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
        
        // If triangles are oriented away from the ray, discard them
        if (glm::dot(normal, ray.d) >= 0) continue;
        
        glm::vec3 tmp = v0 - ray.o;
        double a = glm::dot(tmp, normal);
        double b = glm::dot(ray.d, normal);
        double t = a / b;
        if (t > kEpsilon)
        {
            if (t > tmin) continue;
            
            glm::vec3 P = ray.o + (float)t * ray.d;
            
            if (IsPointInsideTriangle(P, normal, v0, v1, v2) == false) continue;
            
            tmin = t;
            
            glm::vec3 n0, n1, n2;
            aiVectorToGlm(n0, mesh->mNormals[mesh->mFaces[i].mIndices[0]]);
            aiVectorToGlm(n1, mesh->mNormals[mesh->mFaces[i].mIndices[1]]);
            aiVectorToGlm(n2, mesh->mNormals[mesh->mFaces[i].mIndices[2]]);
 
            float totalArea = glm::length(glm::cross(v0 - v1, v0 - v2));
            float l0 = glm::length(glm::cross(P - v1, P - v2)) / totalArea;
            float l1 = glm::length(glm::cross(P - v2, P - v0)) / totalArea;
            float l2 = glm::length(glm::cross(P - v0, P - v1)) / totalArea;
            hr.normal = n0 * l0 + n1 * l1 + n2 * l2;
            hr.hitPoint = P;
            if (mesh->HasTextureCoords(0))
            {
                glm::vec3 uv0, uv1, uv2;
                aiVectorToGlm(uv0, mesh->mTextureCoords[0][mesh->mFaces[i].mIndices[0]]);
                aiVectorToGlm(uv1, mesh->mTextureCoords[0][mesh->mFaces[i].mIndices[1]]);
                aiVectorToGlm(uv2, mesh->mTextureCoords[0][mesh->mFaces[i].mIndices[2]]);
                glm::vec3 uv = uv0 * l0 + uv1 * l1 + uv2 * l2;
                hr.uv = glm::vec2(uv.x, uv.y);
            }
            //LOG(INFO) << "Hit: " << P.x << " " << P.y << " " << P.z;
            intersects = true;
        }
    }
    return intersects;
}

bool AssimpMesh::DidShadowHit(const Ray& ray, double& t)
{
    World w;
    HitRec hr(w);
    return Hit(ray, t, hr);
}

bool AssimpMesh::IsPointInsideTriangle(const glm::vec3& P, const glm::vec3& normal, const glm::vec3& v0, const glm::vec3& v1, const glm::vec3& v2) const
{
    glm::vec3 C;
    
    // edge 0
    glm::vec3 edge0 = v1 - v0;
    glm::vec3 vp0 = P - v0;
    C = glm::cross(edge0, vp0);
    if (glm::dot(normal, C) < 0) return false;
    
    //edge 1
    glm::vec3 edge1 = v2 - v1;
    glm::vec3 vp1 = P - v1;
    C = glm::cross(edge1, vp1);
    if (glm::dot(normal, C) < 0) return false;
    
    //edge 2
    glm::vec3 edge2 = v0 - v2;
    glm::vec3 vp2 = P - v2;
    C = glm::cross(edge2, vp2);
    if (glm::dot(normal, C) < 0) return false;
 
    return true;
}
*/