#pragma once
#include <stdint.h>
#include <memory>

struct Pixel
{
    uint32_t color;
};

class ImageBufferPNG
{
public:
    ImageBufferPNG(uint16_t width, uint16_t height);
    ~ImageBufferPNG();
    void SaveToPngFile(const char* file) const;
    void SetPixel(uint16_t x, uint16_t y, uint32_t color);
private:
    std::unique_ptr<Pixel> imgBuffer;
    uint16_t width, height;
};