#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Utility/BinarySearch.hpp"
#include "../Zahlen.hpp"
#include "../Point.hpp"
#include "../Polygon.hpp"
#include "./State.hpp"

#include <cassert>

namespace zawa {

namespace geometryZ2 {

namespace internal {

bool TriangleContainsPoint(const Point& p0, const Point& p1, const Point& p2, const Point& p) {
    Zahlen area{Abs(Cross(p1 - p0, p2 - p0))};
    Zahlen value{};
    value += Abs(Cross(p0 - p, p1 - p));
    value += Abs(Cross(p1 - p, p2 - p));
    value += Abs(Cross(p2 - p, p0 - p));
    return area == value;
}

} // namespace internal

// note: 凸多角形であることを確認してください。
// note: normal formにしておいてください
ContainState ConvexPolygonContainsPoint(const Polygon& polygon, const Point& p) {
    usize n{polygon.size()};
    assert(n >= static_cast<usize>(3));
    if (polygon[0] == p or polygon[1] == p or polygon[n - 1] == p) {
        return ONLINE;
    }
    if (Relation(polygon[0], polygon[1], p) == ON_SEGMENT) {
        return ONLINE;
    }
    if (Relation(polygon[0], polygon[n - 1], p) == ON_SEGMENT) {
        return ONLINE;
    }
    if (Zero(Cross(polygon[1] - polygon[0], p - polygon[0]))) {
        return OUTSIDE;
    }
    if (Zero(Cross(polygon[n - 1] - polygon[0], p - polygon[0]))) {
        return OUTSIDE;
    }
    if (!(Relation(polygon[0], polygon[1], p) == COUNTER_CLOCKWISE and Relation(polygon[0], p, polygon[n - 1]) == COUNTER_CLOCKWISE)) {
        return OUTSIDE;
    }

    auto f{[&](usize i) -> bool {
        return Relation(polygon[0], polygon[i], p) == COUNTER_CLOCKWISE;
    }};

    usize pos{BinarySearch(usize{0}, usize{n - 1}, f)};
    if (p == polygon[pos]) return ONLINE;
    if (p == polygon[pos + 1]) return ONLINE;
    if (Relation(polygon[pos], polygon[pos + 1], p) == ON_SEGMENT) return ONLINE;

    if (internal::TriangleContainsPoint(polygon[0], polygon[pos], polygon[pos + 1], p)) {
        return INSIDE;
    }
    else {
        return OUTSIDE;
    }
}

} // namespace geometryZ2

} // namespace zawa
