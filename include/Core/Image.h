#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <vector>

struct Pixel {
    unsigned char R,G,B;
};

namespace purview {
    class Image {
        std::vector<Pixel> Data;
        unsigned Cols;

    public:
        Image(int Rows, int Cols)
        : Data(Rows * Cols)
        , Cols(Cols)
        {}

        auto begin() { return Data.begin(); }
        auto end() { return Data.end(); }

        struct IndexType { unsigned Row; unsigned Col; };

        Pixel &operator[](const IndexType I) {
            return Data[I.Row * Cols + I.Col];
        }

        unsigned getRowCount() const { return Data.size()/Cols; }
        unsigned getColCount() const { return Cols; }
    };
};

#endif // _IMAGE_H_
