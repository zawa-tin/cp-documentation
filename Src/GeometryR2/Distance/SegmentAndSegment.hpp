#pragma once

#include "../Real.hpp"
#include "../Segment.hpp"
#include "../Intersect/SegmentAndSegment.hpp"
#include "./PointAndSegment.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

Real Distance(const Segment& s0, const Segment& s1) {
    assert(s0.valid());
    assert(s1.valid());
    if (Intersect(s0, s1)) {
        return static_cast<Real>(0);
    }
    else {
        return std::min({ 
                Distance(s1.p0(), s0), 
                Distance(s1.p1(), s0),
                Distance(s0.p0(), s1),
                Distance(s0.p1(), s1) });
    }
}

} // namespace geometryR2

} // namespace zawa
