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
Image ImageSource::loadImage(std::string Path) {
  Magick::Image MagickImage;
  MagickImage.read(Path);

  const auto RowCount = MagickImage.baseRows();
  const auto ColCount = MagickImage.baseColumns();

  Image PurviewImage(RowCount, ColCount);

  // Iterate over the pixels to convert them into our vector-based format.
  for (unsigned Row = 0; Row < RowCount; Row++) {
    for (unsigned Col = 0; Col < ColCount; Col++) {
      Magick::ColorRGB PixelColor = MagickImage.pixelColor(Row, Col);
      Pixel P;
      P.R = (float)PixelColor.red();
      P.G = (float)PixelColor.green();
      P.B = (float)PixelColor.blue();
      PurviewImage[{Row, Col}] = P;
    }
  }

  return PurviewImage;
}
