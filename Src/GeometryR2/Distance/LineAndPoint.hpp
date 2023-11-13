#pragma once

#include "../Real.hpp"
#include "../Point.hpp"
#include "../Line.hpp"
#include "./PointAndPoint.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

Real Distance(const Line& l, const Point& p) {
    assert(l.valid());
    return Abs(Cross(p - l.p0(), l.p1() - l.p0())) / Distance(l.p1(), l.p0());
}

bool PointOnLine(const Line& l, const Point& p) {
    assert(l.valid());
    return Zero(Distance(l, p));
}

} // namespace geometryR2

} // namespace zawa
