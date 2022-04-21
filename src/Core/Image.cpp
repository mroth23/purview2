#include "Core/Image.h"
#include "Core/Matrix.h"
#include <memory>

using namespace purview;
using namespace std;

std::shared_ptr<Matrix> Image::toGreyscale() const {
    return greyMap(0.2126f, 0.7152f, 0.0722f);
}

std::shared_ptr<Matrix> Image::greyMap(const float coeffR, const float coeffG, const float coeffB) const {
    const auto w = getWidth();
    const auto h = getHeight();

    const auto result = std::make_shared<Matrix>(w, h);

    for (unsigned x = 0; x < w; ++x) {
        for (unsigned y = 0; y < h; ++y) {
            Pixel p = getPixel(x, y);
            float pixelValue = p.R * coeffR + p.G * coeffG + p.B * coeffB;
            result->setValue(x, y, pixelValue);
        }
    }

    return result;
}
