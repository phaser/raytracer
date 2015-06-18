#include <cstdio>
#include <RayTracer.h>

int main(int argc, char** argv)
{
    RayTracer rt("test1.png", "");
    rt.InitImageBuffer(100, 100);
    rt.RayTrace();
    return 0;
}