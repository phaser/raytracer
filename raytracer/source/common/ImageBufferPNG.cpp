#include <ImageBufferPNG.h>
#include <memory>
#include <lodepng.h>
#include <RGBColor.h>

using std::unique_ptr;

ImageBufferPNG::ImageBufferPNG()
: width(0)
, height(0)
{
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

RGBColor ImageBufferPNG::GetPixel(uint16_t x, uint16_t y)
{
    RGBColor col(glm::vec3(0.f));
    if (x >= width || y >= height)
    {
        return col;
    }
    uint32_t color = imgBuffer.get()[y * width + x].color;
    col = glm::vec3((color & 0xFF) / 255.f
                 , ((color >> 8) & 0xFF) / 255.f
                 , ((color >> 16) & 0xFF) / 255.f);
    return col;
    
}

bool ImageBufferPNG::LoadFromFile(const std::string& path)
{
    unsigned error;
    unsigned char* image;
    unsigned width, height;
    error = lodepng_decode32_file(&image, &width, &height, path.c_str());
    if(error)
    {
        printf("error %u: %s\n", error, lodepng_error_text(error));
        return false;
    }
    this->width = width;
    this->height = height;
    this->imgBuffer = std::unique_ptr<Pixel>((Pixel*)image);
    return true;
}

void ImageBufferPNG::AllocImage(uint16_t width, uint16_t height)
{
    this->width = width;
    this->height = height;
    imgBuffer = unique_ptr<Pixel>(new Pixel[width * height * sizeof(Pixel)]);
}