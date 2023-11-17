#pragma once

#include "./Point.hpp"
#include "./Line.hpp"
#include "./Distance/PointAndPoint.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

Point Projection(const Point& point, const Line& line) {
    assert(line.valid());
    Real coeff{Dot(line.p1() - line.p0(), point - line.p0()) / DistanceSquare(line.p0(), line.p1())};
    return coeff * line.p1() + (static_cast<Real>(1) - coeff) * line.p0();
}

} // namespace geometryR2

} // namespace zawa
