#pragma once

#include "../Segment.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

bool Intersect(const Segment& s0, const Segment& s1) {
    assert(s0.valid());
    assert(s1.valid());
    return s0.straddle(s1) and s1.straddle(s0);
}

} // namespace geometryR2

} // namespace zawa
