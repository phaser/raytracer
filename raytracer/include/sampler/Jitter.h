#pragma once
#include <sampler/Sampler.h>
#include <random>

/** \brief The jitter sampler divides the interval into squares and generates a random point 
  *        in each of the squares.
  */
class Jitter : public Sampler
{
public:
    Jitter(uint16_t num_samples);
    void GenerateSamples() override;
private:
    std::uniform_real_distribution<float> distribution;
    std::default_random_engine reng;
};