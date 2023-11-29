#pragma once

#include "../Segment.hpp"

namespace zawa {

namespace geometryZ2 {

bool Parallel(const Segment& s0, const Segment& s1) {
    return Zero(Cross(s0.p1() - s0.p0(), s1.p1() - s1.p0()));
}

} // namespace geometryZ2

} // namespace zawa
