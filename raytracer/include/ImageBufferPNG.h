#pragma once
#include <stdint.h>
#include <memory>

class RGBColor;
struct Pixel
{
    uint32_t color;
};

class ImageBufferPNG
{
public:
    ImageBufferPNG();
    ~ImageBufferPNG();
    void AllocImage(uint16_t width, uint16_t height);
    void SaveToPngFile(const char* file) const;
    void SetPixel(uint16_t x, uint16_t y, uint32_t color);
    RGBColor GetPixel(uint16_t x, uint16_t y);
    uint16_t GetWidth() { return width; }
    uint16_t GetHeight() { return height; }
    bool LoadFromFile(const std::string& path);
private:
    std::unique_ptr<Pixel> imgBuffer;
    uint16_t width, height;
};