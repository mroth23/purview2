#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

#include "Core/Image.h"
#include <vector>

namespace purview
{

Image& convolve(
    std::vector<Matrix>&,
    Image&,
    unsigned long,
    unsigned long);

}

#endif // _ALGORITHMS_H_
