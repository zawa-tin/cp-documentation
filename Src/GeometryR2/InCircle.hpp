#pragma once

#include "./Point.hpp"
#include "./Circle.hpp"
#include "./Segment.hpp"
#include "./Bisector/AngleBisector.hpp"
#include "./CrossPoint/LineAndLine.hpp"
#include "./Distance/LineAndPoint.hpp"

#include <optional>

namespace zawa {

namespace geometryR2 {

std::optional<Circle> InCircle(const Point& p0, const Point& p1, const Point& p2) {
    if (Zero(Cross(p1 - p0, p2 - p0))) return std::nullopt;
    const Point center = CrossPoint(
            AngleBisector(p0, p1, p2),
            AngleBisector(p1, p0, p2)
            );
    const Real radius = Distance(Line{p0, p1}, center);
    return Circle{center, radius};
}

} // namespace geometryR2

} // namespace zawa
