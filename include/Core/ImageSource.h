#ifndef _IMAGE_SOURCE_H_
#define _IMAGE_SOURCE_H_

#include "Core/Image.h"

namespace purview {
    class ImageSource {

    public:
        void init(char *argv);
        Image loadImage(char *path);
    };

};
#endif // _IMAGE_SOURCE_H_
