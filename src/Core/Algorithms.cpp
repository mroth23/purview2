#include "Core/Algorithms.h"
#include "Core/Image.h"
#include "Core/Matrix.h"
#include <memory>
#include <vector>

using namespace std;
using namespace purview;

Image& convolve(
    vector<Matrix> &Kernels,
    Image &Image,
    unsigned long Width,
    unsigned long Height)
{
    // auto NumKernels = Kernels.size();
    // vector<vector<vector<float>>> Result;

    // for (unsigned X = 0; X < Width; ++X)
    // {
    //     for (unsigned Y = 0; Y < Height; ++Y)
    //     {
    //         // Create a vector to aggregate the results for each kernel.
    //         vector<float> Sum(Kernels.size(), 0.0);
    //         // Compute gradient by convolving with Sobel kernel.
    //         for (unsigned Dx = 0; Dx < 3; ++Dx)
    //         {
    //             for (unsigned Dy = 0; Dy < 3; ++Dy)
    //             {

    //                 // Check if pixel is in range. If not, use 0.
    //                 float PixelValue = 0.0;
    //                 if (X + Dx > 0 && X + Dx <= Width && Y + Dy > 0 && Y + Dy <= Height)
    //                 {
    //                     PixelValue = GreyscaleImage[X + Dx - 1][Y + Dy - 1];
    //                 }

    //                 for (unsigned K = 0; K < NumKernels; ++K)
    //                 {
    //                     Sum[K] += PixelValue * Kernels[K][Dx][Dy];
    //                 }
    //             }
    //         }

    //         [{ X, Y }] = P;
    //     }
    // }
}
