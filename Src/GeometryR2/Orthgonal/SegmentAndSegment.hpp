#pragma once

#include "../Point.hpp"
#include "../Segment.hpp"
#include "../Intersect/SegmentAndSegment.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

bool Orthgonal(const Segment& s0, const Segment& s1) {
    return Zero(Dot(s0.p1() - s0.p0(), s1.p1() - s1.p0())) and Intersect(s0, s1);
}

} // namespace geometryR2

} // namespace zawa
