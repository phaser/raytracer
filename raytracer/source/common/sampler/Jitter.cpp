#include <sampler/Jitter.h>

Jitter::Jitter(uint16_t num_samples)
    : Sampler(num_samples)
{
    distribution = std::uniform_real_distribution<float>(0.f, 1.f);
}

void Jitter::GenerateSamples()
{
    uint16_t n = (uint16_t)(glm::sqrt(num_samples));
    auto mrand = std::bind(distribution, reng);
    for (size_t i = 0; i < num_sets; ++i)
    {
        for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
        {
            glm::vec2 sp(((float)k + mrand()) / (float)n, ((float)j + mrand()) / (float)n);
            samples.push_back(sp);
        }
    }
}
