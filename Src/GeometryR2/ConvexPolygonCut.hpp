#pragma once

#include "./Polygon.hpp"
#include "./Line.hpp"
#include "./CrossPoint/LineAndSegment.hpp"

#include <utility>

namespace zawa {

namespace geometryR2 {

std::pair<Polygon, Polygon> ConvexPolygonCut(const Polygon& p, const Line& l) {
    assert(p.isConvex());
    assert(l.valid());
    std::vector<i32> signs(p.size());
    for (usize i = 0 ; i < p.size() ; i++) signs[i] = Sign(Cross(l.p1() - l.p0(), l.p1() - p[i]));
    Polygon left, right;
    for (usize i = 0 ; i < p.size() ; i++) {
        usize j = i + 1 == p.size() ? 0u : i + 1;
        if (signs[i] >= 0) right.pushBack(p[i]);
        if (signs[i] <= 0) left.pushBack(p[i]);
        if (signs[i] * signs[j] < 0) {
            const Point& cp = CrossPoint(l, Segment{p[i], p[j]});
            right.pushBack(cp);
            left.pushBack(cp);
        }
    }
    return {left, right};
}

} // namespace geometryR2

} // namespace zawa
