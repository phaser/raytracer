#include <ImageBufferPNG.h>
#include <memory>
#include <lodepng.h>

using std::unique_ptr;

ImageBufferPNG::ImageBufferPNG(uint16_t width, uint16_t height) : width(width), height(height)
{
    imgBuffer = unique_ptr<Pixel>(new Pixel[width * height * sizeof(Pixel)]);
}

ImageBufferPNG::~ImageBufferPNG()
{
}

void ImageBufferPNG::SaveToPngFile(const char* file) const
{
    Pixel* ib = imgBuffer.get();
    unsigned char* cib = (unsigned char*)ib;
    
    /*Encode the image*/
    unsigned error = lodepng_encode32_file(file, cib, width, height);
    
    /*if there's an error, display it*/
    if(error) printf("error %u: %s\n", error, lodepng_error_text(error));
}

void ImageBufferPNG::SetPixel(uint16_t x, uint16_t y, uint32_t color)
{
    if (x >= width || y >= height)
    {
        return;
    }
    imgBuffer.get()[y * width + x].color = color;
}