#include <HitRec.h>

HitRec::HitRec(World& w)
    : didHit (true)
    , hitPoint (glm::vec3(0.f, 0.f, 0.f))
    , normal (glm::vec3(0.f, 0.f, 0.f))
    , world(w)
{
}

HitRec::HitRec(const HitRec& co)
    : world(co.world)
{
    *this = co;
}

HitRec& HitRec::operator=(const HitRec& co)
{
    this->didHit = co.didHit;
    this->hitPoint = co.hitPoint;
    this->normal = co.normal;
    this->ray = co.ray;
    return *this;
}