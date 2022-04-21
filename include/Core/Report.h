#ifndef _REPORT_H_
#define _REPORT_H_

#include "Core/Image.h"
#include "Core/ImageSource.h"
#include <memory>
#include <string>

namespace purview
{

class Report
{
public:
    static constexpr const char* ReportType = "Report";
    virtual ~Report() { }
    virtual void save() = 0;
};

class ImageReport : public Report
{
private:
    std::shared_ptr<Image> ResultImage;

public:
    ImageReport(std::shared_ptr<Image> ResultImage)
        : ResultImage(ResultImage)
    {
    }

    static constexpr const char* ReportType = "Image Report";

    const Image& getResultImage() const { return *ResultImage; }

    void save()
    {
        ImageSource imgSource;
        imgSource.init({});
        imgSource.saveImage("output.png", *ResultImage);
    }

    ~ImageReport() { }
};
} // namespace purview

#endif // _REPORT_H_
