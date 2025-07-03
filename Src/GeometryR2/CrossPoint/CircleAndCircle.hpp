#pragma once

#include "../Circle.hpp"
#include "../Point.hpp"
#include "../Intersect/CircleAndCircle.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

std::pair<Point, Point> CrossPoint(const Circle& lhs, const Circle& rhs) {
    assert(lhs.center() != rhs.center());
    assert(Intersect(lhs, rhs));
    assert(!Zero(lhs.radius()) or !Zero(rhs.radius()));
    if (Zero(lhs.radius())) return {lhs.center(), lhs.center()};
    if (Zero(rhs.radius())) return {rhs.center(), rhs.center()};
    Real d{Distance(lhs.center(), rhs.center())};
    Real cosine{(Square(lhs.radius()) + Square(d) - Square(rhs.radius()))
        / (static_cast<Real>(2)*lhs.radius()*d)};
    Real rc{lhs.radius()*cosine};
    Real rs{Sqrt(Square(lhs.radius()) - Square(rc))};
    Vector lr{Vector{rhs.center() - lhs.center()}.normalized()};
    Vector h{lhs.center() + lr*rc};
    std::pair<Point, Point> res;
    res.first = h + lr.rotatedByArc(90) * rs;
    res.second = h + lr.rotatedByArc(-90) * rs;
    return res;
}

} // namespace geometryR2
    
} // namespace zawa
