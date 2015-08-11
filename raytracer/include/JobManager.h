#pragma once

#include <thread>
#include <stdint.h>

class JobManager
{
public:
    JobManager(uint8_t num_threads);
private:
    uint8_t num_threads;
};