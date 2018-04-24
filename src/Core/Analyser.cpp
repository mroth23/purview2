#include "Core/Analyser.h"

using namespace purview;
using namespace std;

map<string, shared_ptr<Analyser>>
purview::getAnalysers(shared_ptr<Image> SourceImage) {
    map<string, shared_ptr<Analyser>> Analysers;
    Analysers["id-analyser"] = make_shared<IdentityAnalyser>(SourceImage);
    Analysers["luminance-gradient"] =
        make_shared<LuminanceGradientAnalyser>(SourceImage);
    return Analysers;
}
