#pragma once

#include "./State.hpp"
#include "../Line.hpp"
#include "../Point.hpp"

namespace zawa {

namespace geometryZ2 {

ContainState LineContainsPoint(const Line& l, const Point& p) {
    return Cross(p - l.p0(), l.p1() - l.p0()) == 0 ? ONLINE : OUTSIDE;
}

} // namespace geometryZ2

} // namespace zawa
