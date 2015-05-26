#include <cstdio>
#include <ImageBufferPNG.h>

int main()
{
    ImageBufferPNG image(100, 100);
    for (int i = 0; i < 10; i++)
    for (int j = 0; j < 20; j++)
    {
        image.SetPixel(i, j, 0xFF00FFFF);
    }
    image.SaveToPngFile("test1.png");
    return 0;
}