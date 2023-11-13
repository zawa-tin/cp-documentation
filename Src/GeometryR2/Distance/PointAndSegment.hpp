#pragma once

#include "../Real.hpp"
#include "../Segment.hpp"
#include "../Point.hpp"
#include "./PointAndPoint.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

Real Distance(const Point& p, const Segment& s) {
    assert(s.valid());
    if (Negative(Dot(s.p1() - s.p0(), p - s.p0()))) {
        return Distance(p, s.p0());
    }
    if (Negative(Dot(s.p0() - s.p1(), p - s.p1()))) {
        return Distance(p, s.p1());
    }
    return Abs(Cross(s.p1() - s.p0(), p - s.p0())) / s.length();
}

bool PointOnSegment(const Point& p, const Segment& s) {
    assert(s.valid());
    return Zero(Distance(p, s));
}

} // namespace geometryR2

} // namespace zawa
