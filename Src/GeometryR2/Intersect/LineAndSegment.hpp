#pragma once

#include "../Line.hpp"
#include "../Segment.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

bool Intersect(const Line& l, const Segment& s) {
    assert(l.valid());
    assert(s.valid());
    const i32 sl = Sign(Cross(l.p1() - l.p0(), s.p0() - l.p0()));
    const i32 sr = Sign(Cross(l.p1() - l.p0(), s.p1() - l.p0()));
    return sl * sr <= 0; 
}

} // namespace geometryR2

} // namespace zawa
