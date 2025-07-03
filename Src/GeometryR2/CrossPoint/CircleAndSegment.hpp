#pragma once

#include "../Circle.hpp"
#include "../Segment.hpp"
#include "../Point.hpp"
#include "../Line.hpp"
#include "../Distance/PointAndPoint.hpp"
#include "../Projection.hpp"
#include "../Relation.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

namespace geometryR2 {

std::vector<Point> CrossPoint(const Circle& c, const Segment& s) {
    assert(s.valid());
    Point pr{Projection(c.center(), Line{s.p0(), s.p1()})};
    if (Bigger(DistanceSquare(c.center(), pr), Square(c.radius()))) return {};
    const Vector e = (s.p1() - s.p0()) / Distance(s.p0(), s.p1());
    const Real l = Sqrt(
            Square(c.radius()) - DistanceSquare(pr, c.center())
            );
    std::vector<Point> res;
    // s0に近い方からresに入る
    for (Point p : {pr - e * l, pr + e * l}) {
        if (Relation(s.p0(), s.p1(), p) == RELATION::ON_SEGMENT) {
            res.push_back(p);
        } 
    }
    return res;
}

} // namespace geometryR2

} // namespace zawa
