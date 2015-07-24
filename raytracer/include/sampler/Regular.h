#pragma once
#include <sampler/Sampler.h>
#include <random>

/** \brief The regular sampler divides the interval into a grid and shoots a ray trough each square */
class Regular : public Sampler
{
public:
    Regular(uint16_t num_samples);
    void GenerateSamples() override;
};