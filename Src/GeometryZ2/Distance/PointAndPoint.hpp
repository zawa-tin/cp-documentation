#pragma once

#include "../Zahlen.hpp"
#include "../Point.hpp"

namespace zawa {

namespace geometryZ2 {

Zahlen DistanceSquare(const Point& p0, const Point& p1) {
    return Vector{p1 - p0}.normSquare();
}

} // namespace geometryZ2

} // namespace zawa
