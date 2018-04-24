#ifndef _IMAGE_SOURCE_H_
#define _IMAGE_SOURCE_H_

#include "Core/Image.h"

namespace purview {
class ImageSource {

  public:
    void init(char *argv);
    std::shared_ptr<Image> loadImage(std::string Path);
    void saveImage(std::string Path, std::shared_ptr<Image> Img);
};

};     // namespace purview
#endif // _IMAGE_SOURCE_H_
