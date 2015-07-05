#include <cstdio>
#include <tracer/RayTracer.h>
#include <World.h>

int main(int argc, char** argv)
{
    World w;
    w.Build();
    w.RenderScene();
    return 0;
}
