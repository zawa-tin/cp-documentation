#pragma once

#include "./Point.hpp"
#include "./Line.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

Point Projection(const Point& p, const Line& l) {
    assert(l.isValid());
    Real coeff{dot(l.p2() - l.p1(), p - l.p1()) / Point{l.p2() - l.p1()}.normSquare()};
    return coeff * l.p2() + (static_cast<Real>(1) - coeff) * l.p1();
}

} // namespace geometryR2

} // namespace zawa
