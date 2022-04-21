#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <vector>

typedef std::vector<float>::size_type size_type;

namespace purview
{
class Matrix
{
protected:
    std::vector<float> Data;
    size_type Height;

public:
    Matrix(size_type Width, size_type Height)
        : Data(Width * Height)
        , Height(Height)
    {
    }

    auto begin() { return Data.begin(); }
    auto end() { return Data.end(); }

    struct IndexType
    {
        size_type X;
        size_type Y;
    };

    auto& operator[](const IndexType I) { return Data[I.X * Height + I.Y]; }

    float getValue(size_type X, size_type Y) const { return Data[X * Height + Y]; }
    void setValue(size_type X, size_type Y, float P) { Data[X * Height + Y] = P; }

    size_type getWidth() const { return Data.size() / Height; }
    size_type getHeight() const { return Height; }
};

}; // namespace purview

#endif // _MATRIX_H_
