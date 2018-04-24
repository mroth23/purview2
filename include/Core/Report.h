#ifndef _REPORT_H_
#define _REPORT_H_

#include "Core/Image.h"
#include <memory>

namespace purview {

    class Report {
    public:
        static constexpr const char* ReportType = "Report";
        virtual ~Report() {}
    };

    class ImageReport : public Report {
    private:
        std::shared_ptr<Image> ResultImage;
    public:
        ImageReport(std::shared_ptr<Image> ResultImage): ResultImage(ResultImage) {}
        static constexpr const char* ReportType = "Image Report";
        std::shared_ptr<Image> getResultImage() { return ResultImage; }
        ~ImageReport() {}
    };
}

#endif // _REPORT_H_
