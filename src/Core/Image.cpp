#include "Core/Image.h"

using namespace purview;
using namespace std;

vector<vector<float>> Image::toGreyscale() {
    return greyMap(0.2126f, 0.7152f, 0.0722f);
}

vector<vector<float>> Image::greyMap(float CoeffR, float CoeffG, float CoeffB) {
    const auto H = getHeight();
    const auto W = getWidth();

    vector<vector<float>> Result(W, vector<float>(H, 0));

    for (unsigned X = 0; X < W; ++X) {
        for (unsigned Y = 0; Y < H; ++Y) {
            Pixel P = (*this)[{X, Y}];
            Result[X][Y] = P.R * CoeffR + P.G * CoeffG + P.B * CoeffB;
        }
    }

    return Result;
}
