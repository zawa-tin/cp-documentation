#pragma once

#include "./State.hpp"
#include "../Real.hpp"
#include "../Relation.hpp"
#include "../Polygon.hpp"
#include "../Point.hpp"
#include "../../Template/TypeAlias.hpp"

#include <cassert>
#include <utility>

namespace zawa {

namespace geometryR2 {

ContainState PolygonContainsPoint(const Polygon& polygon, const Point& p) {
    usize n{polygon.size()};
    assert(n >= static_cast<usize>(3));
    bool odd{};
    for (usize i{} ; i < n ; i++) {
        if (polygon[i] == p) {
            return ONLINE;
        }
        if (Relation(polygon[i], polygon[i+1==n?0:i+1], p) == ON_SEGMENT) {
            return ONLINE;
        }
        Vector a{polygon[i] - p}, b{polygon[i+1==n?0:i+1] - p};
        if (Bigger(a.y(), b.y())) std::swap(a, b);
        odd ^= !Positive(a.y()) and Positive(b.y()) and Positive(Cross(a, b));
    }
    return (odd ? INSIDE : OUTSIDE);
}

} // namespace geometryR2

} // namespace zawa
