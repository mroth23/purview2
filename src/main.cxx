#include <boost/program_options.hpp>
#include <cstdlib>
#include <iostream>
#include "app.h"

#include "Core/ImageSource.h"
#include "Core/Analyser.h"

using namespace std;
using namespace purview;
namespace po = boost::program_options;

po::options_description getDescription() {
    po::options_description desc("Options");
    desc.add_options()
        ("help,h", "Display this message")
        ("file,f", po::value<string>(), "Load image from file")
        ("version,v", "Display the version number");

    return desc;
}

int main(int argc, char *argv[]) {
    po::options_description desc = getDescription();
    po::variables_map varmap;

    try {
        store(po::command_line_parser(argc, argv).options(desc).run(), varmap);
        notify(varmap);
    } catch (po::error &error) {
        cerr << error.what() << endl;
        return EXIT_FAILURE;
    }

    if (varmap.count("help")) {
        cout << desc << endl;
    }

    if (varmap.count("version")) {
        App app;
        cout << app.getProjectVersion() << endl;
    }

    if (varmap.count("file")) {
        ImageSource ImgSource;
        ImgSource.init(*argv);

        string Path = varmap["file"].as<string>();
        auto Img = ImgSource.loadImage(Path);
        cout << "Loaded Image (" << Path << "): " << Img->getColCount() << "x" << Img->getRowCount() << endl;

        auto Analysers = getAnalysers(Img);

        for (const auto &Analyser : Analysers) {
            auto AnalyserInst = Analyser.second;
            AnalyserInst->init();
            AnalyserInst->runAnalysis();
            auto AnalysisResult = AnalyserInst->getAnalysisResult();
        }
    }

    return EXIT_SUCCESS;
}
