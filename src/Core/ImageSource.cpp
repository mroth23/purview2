#include "Core/ImageSource.h"
#include "Core/Image.h"
#include <Magick++.h>

#include <exception>
#include <iostream>

using namespace purview;

/*
  Initialise the ImageSource.
  This is just a wrapper around the ImageMagick++ init.
*/
void ImageSource::init(char *argv) { Magick::InitializeMagick(argv); }

/*
  Load an image from the given path.
  This will load the image using ImageMagick, and then convert it to our
  internal representation.
*/
std::shared_ptr<Image> ImageSource::loadImage(std::string Path) {
    Magick::Image MagickImage;
    MagickImage.read("./images/pic1.jpg");
    MagickImage.read(Path);

    const auto Height = MagickImage.baseRows();
    const auto Width = MagickImage.baseColumns();

    auto PurviewImage = std::make_shared<Image>(Width, Height);

    // Iterate over the pixels to convert them into our vector-based format.
    for (unsigned X = 0; X < Width; ++X) {
        for (unsigned Y = 0; Y < Height; ++Y) {
            Magick::ColorRGB PixelColor = MagickImage.pixelColor(X, Y);
            Pixel P;
            P.R = (float)PixelColor.red();
            P.G = (float)PixelColor.green();
            P.B = (float)PixelColor.blue();
            (*PurviewImage)[{X, Y}] = P;
        }
    }

    return PurviewImage;
}

void ImageSource::saveImage(std::string Path, std::shared_ptr<Image> Img) {
    const auto Width = Img->getWidth();
    const auto Height = Img->getHeight();
    const auto Size = Magick::Geometry(Width, Height);

    Magick::Image MagickImage(Size, Magick::Color("white"));

    for (unsigned X = 0; X < Width; ++X) {
        for (unsigned Y = 0; Y < Height; ++Y) {
            Pixel P = (*Img)[{X, Y}];
            MagickImage.pixelColor(X, Y, Magick::ColorRGB(P.R, P.G, P.B));
        }
    }

    MagickImage.write(Path);
}
