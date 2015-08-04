#pragma once
#include <geom/GeometricObject.h>

class aiMesh;
class aiScene;

class AssimpMesh : public GeometricObject
{
public:
    AssimpMesh(const aiScene* scene, aiMesh* mesh);
    bool Hit(const Ray& ray, double& tmin, HitRec& hr) const override;
    bool DidShadowHit(const Ray& ray, float& t) override;
private:
    const aiScene *scene;
    aiMesh *mesh;
};