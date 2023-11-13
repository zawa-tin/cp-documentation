#pragma once

#include "../Segment.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

bool Parallel(const Segment& s0, const Segment& s1) {
    assert(s0.valid());
    assert(s1.valid());
    return Zero(Cross(s0.p1() - s0.p0(), s1.p1() - s1.p0()));
}

} // namespace geometryR2

} // namespace zawa
