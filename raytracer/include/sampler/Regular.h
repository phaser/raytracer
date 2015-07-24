#pragma once
#include <sampler/Sampler.h>
#include <random>

class Regular : public Sampler
{
public:
    Regular(uint16_t num_samples);
    void GenerateSamples() override;
};