#include <sampler/Regular.h>

Regular::Regular(uint16_t num_samples)
    : Sampler(num_samples)
{
}

void Regular::GenerateSamples()
{
    uint16_t n = (uint16_t)(glm::sqrt(num_samples));
    for (int i = 0; i < num_sets; ++i)
    {
        for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
        {
            glm::vec2 sp((k + 0.5) / n, (j + 0.5) / n);
            samples.push_back(sp);
        }
    }
}
