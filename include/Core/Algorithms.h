#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

#include <vector>

namespace purview {
    std::vector<std::vector<float>> convolve(std::vector<const float[][]>, std::vector<std::vector<float>>, unsigned long, unsigned long);
}

#endif // _ALGORITHMS_H_
