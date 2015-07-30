#include <cstdio>
#include <tracer/RayTracer.h>
#include <World.h>
#include <qui/Log.h>
#include <time.h>

int main(int argc, char** argv)
{
    LOG(INFO) << "Start:";
    time_t initial_time;
    time_t final_time;
    double seconds;
    time(&initial_time);
    World w;
    w.Build();
    w.RenderScene();
    time(&final_time);
    seconds = difftime(final_time, initial_time);
    LOG(INFO) << "End: " << seconds << " seconds passed!";
    return 0;
}
