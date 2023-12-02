#pragma once

#include "./Point.hpp"

#include <algorithm>
#include <vector>

namespace zawa {

namespace geometryZ2 {

using PointCloud = std::vector<Point>;

void ArgSort(PointCloud& p) {
    std::sort(p.begin(), p.end(), Point::ArgComp);
}

} // namespace geometryZ2 

} // namespace zawa
