#include "app.h"
#include <boost/program_options.hpp>
#include <boost/exception/info.hpp>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include <execinfo.h>

#include "Core/Analyser.h"
#include "Core/ImageSource.h"

using namespace std;
using namespace purview;
namespace po = boost::program_options;

po::options_description getDescription()
{
    po::options_description desc("Options");
    desc.add_options()("help,h", "Display this message")("file,f", po::value<string>(), "Load image from file")("version,v", "Display the version number");

    return desc;
}

void runAnalysis(Analyser& a)
{
    // Run the analysis.
    a.init();
    a.runAnalysis();

    // Get analysis result and save.
    const auto& analysisResult = a.getAnalysisResult();
    // Get analysis result and downcast.
    // FIXME: Figure out an interface or pattern to avoid casting.
    analysisResult->save();
}

void handler()
{
    void* trace_elems[20];
    int trace_elem_count(backtrace(trace_elems, 20));
    char** stack_syms(backtrace_symbols(trace_elems, trace_elem_count));
    for (int i = 0; i < trace_elem_count; ++i)
    {
        std::cout << stack_syms[i] << "\n";
    }
    free(stack_syms);

    exit(1);
}

int main(int argc, char* argv[])
{
    std::set_terminate(handler);

    po::options_description desc = getDescription();
    po::variables_map varmap;

    try
    {
        store(po::command_line_parser(argc, argv).options(desc).run(), varmap);
        notify(varmap);
    }
    catch (po::error& error)
    {
        cerr << error.what() << endl;
        return EXIT_FAILURE;
    }

    if (varmap.count("help"))
    {
        cout << desc << endl;
    }

    if (varmap.count("version"))
    {
        App app;
        cout << app.getProjectVersion() << endl;
    }

    if (varmap.count("file"))
    {
        try
        {
            ImageSource imgSource;
            imgSource.init(*argv);

            string path = varmap["file"].as<string>();
            const auto img = imgSource.loadImage(path);
            cout << "Loaded Image (" << path << "): " << img->getWidth() << "x"
                 << img->getHeight() << endl;

            LuminanceGradientAnalyser lga(img);
            runAnalysis(lga);
        }
        catch (const std::exception& e)
        {
            cout << e.what();
        }
    }

    return EXIT_SUCCESS;
}
