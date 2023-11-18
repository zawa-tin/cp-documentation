#pragma once

#include "./State.hpp"
#include "../Zahlen.hpp"
#include "../Circle.hpp"

namespace zawa {

namespace geometryZ2 {

ContainState CircleContainsPoint(const Circle& c, const Point& p) {
    Zahlen dist{DistanceSquare(c.center(), p)};
    if (dist < c.radiusSquare()) {
        return INSIDE;
    }
    else if (dist == c.radiusSquare()) {
        return ONLINE;
    }
    else {
        return OUTSIDE;
    }
}

} // namespace geometryZ2

} // namespace zawa
