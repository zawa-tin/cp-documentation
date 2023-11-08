#pragma once

#include "./Point.hpp"
#include "./Line.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

Point Projection(const Point& point, const Line& line) {
    assert(line.isValid());
    Real coeff{Dot(line.p1() - line.p0(), point - line.p0()) / Point{line.p1() - line.p0()}.normSquare()};
    return coeff * line.p1() + (static_cast<Real>(1) - coeff) * line.p0();
}

} // namespace geometryR2

} // namespace zawa
