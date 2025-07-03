#pragma once

#include "../Point.hpp"
#include "../Line.hpp"

#include <utility>

namespace zawa {

namespace geometryR2 {

// bisector of \angle {p1 p0 p2}
Line AngleBisector(const Point& p0, const Point& p1, const Point& p2) {
    const Vector p{p1 - p0}, q{p2 - p0};    
    const Point op = p0 + p.rotated(-Argument(q, p) / 2);
    return {p0, op};
}

} // namespace geometryR2

} // namespace zawa
