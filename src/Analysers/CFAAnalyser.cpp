#include "Core/Analyser.h"
#include "Core/Image.h"

using namespace purview;

const float HighpassFilter[3][3] = {{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}};

void CFAAnalyser::init() {}

void CFAAnalyser::runAnalysis() {
    const auto Width = SourceImage->getWidth();
    const auto Height = SourceImage->getHeight();
    Image ResultImage(Width, Height);

    // auto GreenChannel = SourceImage->greyMap(0.0, 255.0, 0.0);
}

void CFAAnalyser::dispose() {}
