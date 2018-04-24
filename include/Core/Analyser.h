#ifndef _ANALYSER_H_
#define _ANALYSER_H_

#include "Core/Image.h"
#include "Core/Report.h"
#include <memory>
#include <map>
#include <string>

namespace purview {

    class Analyser {
    protected:
        // The source image should not be modified by the analyser.
        const std::shared_ptr<Image> SourceImage;
        std::shared_ptr<Report> AnalysisResult;
    public:
        Analyser(std::shared_ptr<Image> SourceImage): SourceImage(SourceImage) {}
        std::shared_ptr<Report> getAnalysisResult() { return AnalysisResult; }
        virtual void init() = 0;
        virtual void runAnalysis() = 0;
        virtual void dispose() = 0;
        virtual ~Analyser() {};
    };

    class IdentityAnalyser : public Analyser {
    public:
        using Analyser::Analyser;
        void init();
        void runAnalysis();
        void dispose();
        ~IdentityAnalyser() {};
    };

    std::map<std::string, std::shared_ptr<Analyser>> getAnalysers(std::shared_ptr<Image> SourceImage);

}

#endif
