#pragma once

#include "../Line.hpp"
#include "../Segment.hpp"
#include "./LineAndLine.hpp"

namespace zawa {

namespace geometryR2 {

Point CrossPoint(const Line& l, const Segment& s) {
    assert(l.valid());
    assert(s.valid());
    const i32 sl = Sign(Cross(l.p1() - l.p0(), s.p0() - l.p0()));
    const i32 sr = Sign(Cross(l.p1() - l.p0(), s.p1() - l.p0()));
    assert(sl * sr <= 0);
    assert(sl != 0 or sr != 0);
    return CrossPoint(l, Line{s.p0(), s.p1()});
}

} // namespace geometryR2

} // namespace zawa
