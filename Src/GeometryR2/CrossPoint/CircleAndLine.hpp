#pragma once

#include "../Circle.hpp"
#include "../Line.hpp"
#include "../Point.hpp"
#include "../Distance/PointAndPoint.hpp"
#include "../Intersect/CircleAndLine.hpp"
#include "../Projection.hpp"

#include <cassert>
#include <utility>

namespace zawa {

namespace geometryR2 {

std::pair<Point, Point> CrossPoint(const Circle& c, const Line& l) {
    assert(l.valid());
    assert(Intersect(c, l));
    Point pr{Projection(c.center(), l)};
    Vector e{(l.p1() - l.p0()) / Distance(l.p0(), l.p1())};
    Real len{Sqrt(Square(c.radius()) - DistanceSquare(pr, c.center()))};
    return std::pair<Point, Point>{
        pr + e * len,
        pr - e * len
    };
}

} // namespace geometryR2

} // namespace zawa
