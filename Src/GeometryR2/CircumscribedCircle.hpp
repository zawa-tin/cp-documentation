#pragma once

#include "./Circle.hpp"
#include "./Segment.hpp"
#include "./Bisector/PerpendicularBisector.hpp"
#include "./CrossPoint/LineAndLine.hpp"
#include "./Distance/PointAndPoint.hpp"

#include <optional>

namespace zawa {

namespace geometryR2 {

std::optional<Circle> CircumscribedCircle(const Point& p0, const Point& p1, const Point& p2) {
    if (Zero(Cross(p1 - p0, p2 - p0))) return std::nullopt;
    const Point c = CrossPoint(
           PerpendicularBisector(Segment{p0, p1}),
           PerpendicularBisector(Segment{p0, p2})
           );
    const Real r = Distance(p0, c);
    return Circle{c, r};
}

} // namespace geometryR2

} // namespace zawa
