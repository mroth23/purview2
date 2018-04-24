#include "Core/Analyser.h"
#include <memory>

using namespace purview;

// The Identity analyser does nothing and simply returns the input image.

void IdentityAnalyser::init() {}

void IdentityAnalyser::runAnalysis() {
    this->AnalysisResult = std::make_shared<ImageReport>(SourceImage);
}

void IdentityAnalyser::dispose() {}
