#pragma once

#include "../Line.hpp"
#include "../Point.hpp"

namespace zawa {

namespace geometryR2 {

bool LineContainsPoint(const Line& l, const Point& p) {
    assert(l.valid());
    return Zero(Cross(l.p0(), l.p1(), p));
}

} // namespace geometryR2

} // namespace zawa
