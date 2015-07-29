#include <geom/GeometricObject.h>
#include <HitRec.h>

GeometricObject::GeometricObject()
    : material(nullptr)
{
}

GeometricObject::~GeometricObject()
{
}

std::string& GeometricObject::GetMaterial()
{
    return this->material;
}

GeometricObject& GeometricObject::SetMaterial(const std::string& material)
{
    this->material = material;
    return *this;
}