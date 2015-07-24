#pragma once
#include <glm/glm.hpp>
#include <stdint.h>
#include <vector>

/** \brief A base class for sampling. */
class Sampler
{
public:
    Sampler(uint16_t num_samples);
    virtual ~Sampler();
    virtual void GenerateSamples() =0;
    glm::vec2 GetNextSample();
    void SetNumSets(uint16_t num_sets);
    uint16_t GetNumSets() const;
    void SetNumSamples(uint16_t num_samples);
    uint16_t GetNumSamples() const;
protected:
    uint16_t num_samples;           /**< The number of samples it will generate */
    uint16_t num_sets;              /**< The number of samples sets stored */
    std::vector<glm::vec2> samples; /**< The actual sample array */
    size_t count;                   /**< The current count */
};