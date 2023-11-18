#pragma once

#include "./State.hpp"
#include "../Real.hpp"
#include "../Circle.hpp"
#include "../Point.hpp"
#include "../Distance/PointAndPoint.hpp"

namespace zawa {

namespace geometryR2 {

ContainState CircleContainsPoint(const Circle& circle, const Point& p) {
    Real dist{Distance(circle.center(), p)};
    if (Smaller(dist, circle.radius())) {
        return INSIDE;
    }
    else if (Equal(dist, circle.radius())) {
        return ONLINE;
    }
    else {
        return OUTSIDE;
    }
}

} // namespace geometryR2

} // namespace zawa
