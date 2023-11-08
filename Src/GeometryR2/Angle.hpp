#pragma once

#include "./Real.hpp"

#include <cmath>

namespace zawa {

namespace geometryR2 {

constexpr Real PI{acosl(-1)};
constexpr Real TAU{static_cast<Real>(2) * PI};

constexpr Real ArcToRadian(Real arc) {
    return (arc * PI) / static_cast<Real>(180);
}

constexpr Real RadianToArc(Real radian) {
    return (radian * static_cast<Real>(180)) / PI;
}

} // namespace geometryR2

} // namespace zawa
