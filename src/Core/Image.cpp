#include "Core/Image.h"

using namespace purview;
using namespace std;

vector<vector<float>> Image::toGreyscale() {
    const auto H = getHeight();
    const auto W = getWidth();

    vector<vector<float>> Result(W, vector<float>(H, 0));

    for (unsigned X = 0; X < W; ++X) {
        for (unsigned Y = 0; Y < H; ++Y) {
            Pixel P = (*this)[{X, Y}];
            Result[X][Y] = P.R * 0.2126f + P.G * 0.7152f + P.B * 0.0722f;
        }
    }

    return Result;
}
