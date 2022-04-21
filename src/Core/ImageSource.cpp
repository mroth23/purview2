#include "Core/ImageSource.h"
#include "Core/Image.h"
#include <Magick++.h>

#include <exception>
#include <iostream>
#include <memory>

using namespace purview;

/*
  Initialise the ImageSource.
  This is just a wrapper around the ImageMagick++ init.
*/
void ImageSource::init(char* argv) { Magick::InitializeMagick(argv); }

/*
  Load an image from the given path.
  This will load the image using ImageMagick, and then convert it to our
  internal representation.
*/
const std::shared_ptr<Image> ImageSource::loadImage(std::string path)
{
    Magick::Image MagickImage;
    MagickImage.read("./images/pic1.jpg");
    MagickImage.read(path);

    const auto height = MagickImage.baseRows();
    const auto width = MagickImage.baseColumns();

    const auto PurviewImage = std::make_shared<Image>(width, height);

    // Iterate over the pixels to convert them into our vector-based format.
    for (unsigned x = 0; x < width; ++x)
    {
        for (unsigned y = 0; y < height; ++y)
        {
            Magick::ColorRGB PixelColor = MagickImage.pixelColor(x, y);
            Pixel p;
            p.R = (float)PixelColor.red();
            p.G = (float)PixelColor.green();
            p.B = (float)PixelColor.blue();
            PurviewImage->setPixel(x, y, p);
        }
    }

    return PurviewImage;
}

void ImageSource::saveImage(std::string path, const Image& img)
{
    const auto width = img.getWidth();
    const auto height = img.getHeight();
    const auto size = Magick::Geometry(width, height);

    std::cout << "Writing image " << width << "x" << height << std::endl;

    Magick::Image MagickImage(size, Magick::Color("white"));

    for (unsigned x = 0; x < width; ++x)
    {
        for (unsigned y = 0; y < height; ++y)
        {
            Pixel p = img.getPixel(x, y);
            MagickImage.pixelColor(x, y, Magick::ColorRGB(p.R, p.G, p.B));
        }
    }

    std::cout << "Saving file... ";

    MagickImage.write(path);
}
