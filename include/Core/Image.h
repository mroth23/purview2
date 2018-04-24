#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <vector>

struct Pixel {
    float R,G,B;
};

typedef std::vector<Pixel>::size_type size_type;

namespace purview {
    class Image {
        std::vector<Pixel> Data;
        size_type Height;

    public:
        Image(size_type Width, size_type Height)
        : Data(Width * Height)
        , Height(Height)
        {}

        auto begin() { return Data.begin(); }
        auto end() { return Data.end(); }

        struct IndexType { size_type X; size_type Y; };

        Pixel &operator[](const IndexType I) {
            return Data[I.X * Height + I.Y];
        }

        size_type getWidth() const { return Data.size()/Height; }
        size_type getHeight() const { return Height; }
    };
};

#endif // _IMAGE_H_
