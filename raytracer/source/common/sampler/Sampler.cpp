#include <sampler/Sampler.h>

Sampler::Sampler(uint16_t num_samples)
    : num_samples(num_samples)
    , num_sets(1)
    , count(0)
{
}

Sampler::~Sampler()
{
}

glm::vec2 Sampler::GetNextSample()
{
    return samples[count++ % (num_samples * num_sets)];
}

void Sampler::SetNumSets(uint16_t num_sets)
{
    this->num_sets = num_sets;
}

uint16_t Sampler::GetNumSets() const
{
    return num_sets;
}

void Sampler::SetNumSamples(uint16_t num_samples)
{
    this->num_samples = num_samples;
}

uint16_t Sampler::GetNumSamples() const
{
    return num_samples;
}