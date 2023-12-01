#pragma once

#include "../Segment.hpp"
#include "../Relation.hpp"

namespace zawa {

namespace geometryZ2 {

bool Intersect(const Segment& s0, const Segment& s1) {
    assert(s0.valid());
    assert(s1.valid());
    return s0.straddle(s1) and s1.straddle(s0);
}

} // namespace geometryZ2

} // namespace zawa
