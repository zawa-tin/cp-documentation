#pragma once

#include "../Point.hpp"

namespace zawa {

namespace geometryR2 {

Real Distance(const Point& p0, const Point& p1) {
    return Point{p1 - p0}.norm();
}

Real DistanceSquare(const Point& p0, const Point& p1) {
    return Point{p1 - p0}.normSquare();
}

} // namespace geometryR2

} // namespace zawa
