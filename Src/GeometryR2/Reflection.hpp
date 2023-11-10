#pragma once

#include "./Point.hpp"
#include "./Line.hpp"
#include "./Projection.hpp"

namespace zawa {

namespace geometryR2 {

Point Reflection(const Point& point, const Line& line) {
    assert(line.valid());
    return -point + static_cast<Real>(2) * Projection(point, line);
}

} // namespace geometryR2

} // namespace zawa
