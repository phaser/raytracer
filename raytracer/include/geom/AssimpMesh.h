#pragma once
#include <geom/GeometricObject.h>
#include <glm/glm.hpp>

struct aiMesh;
struct aiScene;

class AssimpMesh : public GeometricObject
{
public:
    AssimpMesh(const aiScene* scene, aiMesh* mesh);
    bool Hit(const Ray& ray, double& tmin, HitRec& hr) const override;
    bool DidShadowHit(const Ray& ray, double& t) override;
private:
    const aiScene *scene;
    aiMesh *mesh;
    static const double kEpsilon;
    
    bool IsPointInsideTriangle(const glm::vec3& P, const glm::vec3& normal, const glm::vec3& v0, const glm::vec3& v1, const glm::vec3& v2) const;
};