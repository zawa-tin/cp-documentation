#pragma once

#include "../Point.hpp"
#include "../Line.hpp"
#include "../Intersect/LineAndLine.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

Point CrossPoint(const Line& l0, const Line& l1) {
    assert(l0.valid());
    assert(l1.valid());
    assert(Intersect(l0, l1));
    assert(l0 != l1);
    return l0.p0() + (l0.p1() - l0.p0()) * 
        (Cross(l1.p0() - l0.p0(), l1.p1() - l1.p0()) / Cross(l0.p1() - l0.p0(), l1.p1() - l1.p0()));
}

} // namespace geometryR2

} // namespace zawa
