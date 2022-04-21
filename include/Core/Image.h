#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "Core/Matrix.h"
#include <memory>
#include <vector>

struct Pixel
{
    float R, G, B;
};

typedef std::vector<Pixel>::size_type size_type;

namespace purview
{
class Image
{
protected:
    std::vector<Pixel> Data;
    size_type Width;
    size_type Height;

public:
    Image(size_type Width, size_type Height)
        : Data(Width * Height)
        , Width(Width)
        , Height(Height)
    {
    }

    auto begin() const { return Data.begin(); }
    auto end() const { return Data.end(); }

    struct IndexType
    {
        size_type X;
        size_type Y;
    };

    auto& operator[](const IndexType I) { return Data[I.X * Height + I.Y]; }

    size_type getWidth() const { return Width; }
    size_type getHeight() const { return Height; }

    Pixel getPixel(size_type X, size_type Y) const { return Data[X * Height + Y]; }
    void setPixel(size_type X, size_type Y, Pixel P) { Data[X * Height + Y] = P; }

    std::shared_ptr<Matrix> toGreyscale() const;
    std::shared_ptr<Matrix> greyMap(const float, const float, const float) const;
};

}; // namespace purview

#endif // _IMAGE_H_
