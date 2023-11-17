#pragma once

#include "../Segment.hpp"
#include "../Line.hpp"
#include "../Point.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

Line PerpendicularBisector(const Segment& s) {
    assert(s.valid());
    Point midpoint{s.midpoint()}; 
    Vector vertical{Vector{s.p1() - s.p0()}.rotatedByArc(90)};
    return Line{midpoint, midpoint + vertical};
}

} // namespace geometryR2

} // namespace zawa
