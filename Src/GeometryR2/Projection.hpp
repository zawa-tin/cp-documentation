#pragma once

#include "./Point.hpp"
#include "./Line.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

Point Projection(const Point& point, const Line& line) {
    assert(line.isValid());
    Real coeff{dot(line.p2() - line.p1(), point - line.p1()) / Point{line.p2() - line.p1()}.normSquare()};
    return coeff * line.p2() + (static_cast<Real>(1) - coeff) * line.p1();
}

} // namespace geometryR2

} // namespace zawa
