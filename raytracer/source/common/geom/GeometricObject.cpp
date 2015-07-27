#include <geom/GeometricObject.h>
#include <HitRec.h>

GeometricObject::GeometricObject()
    : material(nullptr)
{
}

GeometricObject::~GeometricObject()
{
    delete material;
}

Material& GeometricObject::GetMaterial()
{
    return *(this->material);
}

GeometricObject& GeometricObject::SetMaterial(Material* material)
{
    if (this->material != nullptr)
    {
        delete this->material;
    }
    this->material = material;
    return *this;
}