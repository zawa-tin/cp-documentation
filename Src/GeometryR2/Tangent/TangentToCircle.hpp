#pragma once

#include "../Real.hpp"
#include "../Point.hpp"
#include "../Line.hpp"
#include "../Circle.hpp"
#include "../Distance/PointAndPoint.hpp"
#include "../Contain/CircleContainsPoint.hpp"

#include <utility>

namespace zawa {

namespace geometryR2 {

// p0に接点が代入されます
std::pair<Line, Line> TangentToCircle(const Circle& c, const Point& p) {
    ContainState state{CircleContainsPoint(c, p)};
    assert(state != INSIDE);
    if (state == ONLINE) {
        Vector dir{Vector{p - c.center()}.rotatedByArc(90)};
        return {Line{p, p + dir}, Line{p, p + dir}};
    }
    else {
        Vector dir{c.center() - p};
        Real theta{asinl(c.radius() / dir.norm())};
        Real len{Sqrt(dir.normSquare() - Square(c.radius()))};
        dir.normalize();
        return {Line{p + dir.rotated(theta) * len, p}, Line{p + dir.rotated(-theta) * len, p}};
    }
}

} // namespace geometryR2

} // namespace zawa
