#include "Core/Analyser.h"
#include "Core/Image.h"
#include <cmath>
#include <iostream>
#include <memory>

using namespace std;
using namespace purview;

const float SobelX[3][3] = { { -1, 0, 1 }, { -2, 0, 2 }, { -1, 0, 1 } };
const float SobelY[3][3] = { { -1, -2, -1 }, { 0, 0, 0 }, { 1, 2, 1 } };

void LuminanceGradientAnalyser::init() { }

void LuminanceGradientAnalyser::runAnalysis()
{
    const auto Width = SourceImage->getWidth();
    const auto Height = SourceImage->getHeight();
    const auto ResultImage = std::make_shared<Image>(Width, Height);

    // Step 1: Convert the image to greyscale.
    auto GreyscaleImage = SourceImage->toGreyscale();

    cout << "Starting LG\n";

    // Step 2: Convolve the 3x3 region around each pixel with SobelX and SobelY
    // to get the local luminance gradient.
    for (unsigned X = 0; X < Width; ++X)
    {
        for (unsigned Y = 0; Y < Height; ++Y)
        {
            float GradientX = 0.0, GradientY = 0.0;

            // Compute gradient by convolving with Sobel kernel.
            for (unsigned Dx = 0; Dx < 3; ++Dx)
            {
                for (unsigned Dy = 0; Dy < 3; ++Dy)
                {
                    float SXCoefficient = SobelX[Dx][Dy];
                    float SYCoefficient = SobelY[Dx][Dy];

                    // Check if pixel is in range. If not, use 0.
                    float PixelValue = 0.0;
                    if (X + Dx > 0 && X + Dx <= Width && Y + Dy > 0 && Y + Dy <= Height)
                    {
                        PixelValue = GreyscaleImage->getValue(X + Dx - 1, Y + Dy - 1);
                    }

                    GradientX += SXCoefficient * PixelValue;
                    GradientY += SYCoefficient * PixelValue;
                }
            }

            float Angle = std::atan2(GradientY, GradientX);

            Pixel P;
            P.R = -std::sin(Angle) / 2.0f + 0.5f; // Map sin result to [0..1]
            P.G = -std::cos(Angle) / 2.0f + 0.5f; // Map cos result to [0..1]
            P.B = std::sqrt(GradientX * GradientX + GradientY * GradientY);

            ResultImage->setPixel(X, Y, P);
        }
    }

    cout << "Finished LG\n";

    AnalysisResult = std::make_shared<ImageReport>(ResultImage);
}

void LuminanceGradientAnalyser::dispose() { }
