#pragma once

#include "./Real.hpp"
#include "./Point.hpp"

namespace zawa {

namespace geometryR2 {

enum RELATION {
    // p0 -> p1 -> p2の順で直線上に並んでいる
    ONLINE_FRONT = -2,
    // (p1 - p0) -> (p2 - p0)が時計回りになっている
    CLOCKWISE,
    // p0 -> p2 -> p1の順で直線上に並んでいる
    ON_SEGMENT,
    // (p1 - p0) -> (p2 - p0)が反時計回りになっている
    COUNTER_CLOCKWISE,
    // p2 -> p0 -> p1、またはp1 -> p0 -> p2の順で直線上に並んでいる
    ONLINE_BACK
};

RELATION Relation(const Point& p0, const Point& p1, const Point& p2) {
    Point a{p1 - p0}, b{p2 - p0};
    if (Positive(Cross(a, b))) return COUNTER_CLOCKWISE;
    if (Negative(Cross(a, b))) return CLOCKWISE;
    if (Negative(Dot(a, b))) return ONLINE_BACK;
    if (Smaller(a.normSquare(), b.normSquare())) return ONLINE_FRONT;
    return ON_SEGMENT;
};

} // namespace geometryR2

} // namespace zawa
