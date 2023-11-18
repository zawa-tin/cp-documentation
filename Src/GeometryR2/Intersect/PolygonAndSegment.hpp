#pragma once

#include "../../Template/TypeAlias.hpp"
#include "./SegmentAndSegment.hpp"
#include "../Polygon.hpp"
#include "../Segment.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

bool Intersect(const Polygon& polygon, const Segment& segment) {
    usize n{polygon.size()};
    assert(n >= static_cast<usize>(3));
    assert(segment.valid());
    for (usize i{} ; i < n ; i++) {
        Segment edge{polygon[i], polygon[i+1==n?0:i+1]};
        if (Intersect(edge, segment)) {
            return true;
        }
    }
    return false;
}

} // namespace geometryR2

} // namespace zawa
