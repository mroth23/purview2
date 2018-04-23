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
        size_type Cols;

    public:
        Image(size_type Rows, size_type Cols)
        : Data(Rows * Cols)
        , Cols(Cols)
        {}

        auto begin() { return Data.begin(); }
        auto end() { return Data.end(); }

        struct IndexType { size_type Row; size_type Col; };

        Pixel &operator[](const IndexType I) {
            return Data[I.Row * Cols + I.Col];
        }

        size_type getRowCount() const { return Data.size()/Cols; }
        size_type getColCount() const { return Cols; }
    };
};

#endif // _IMAGE_H_
