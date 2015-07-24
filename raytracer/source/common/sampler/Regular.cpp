#include <sampler/Regular.h>

Regular::Regular(uint16_t num_samples)
    : Sampler(num_samples)
{
}

void Regular::GenerateSamples()
{
    uint16_t n = (uint16_t)(glm::sqrt(num_samples));
    for (int j = 0; j < n; ++j)
    for (int k = 0; k < n; ++k)
    {
        glm::vec2 sp((float)k / (float)n, (float)j / (float)n);
        samples.push_back(sp);
    }
}
