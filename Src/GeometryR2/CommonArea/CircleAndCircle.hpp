#pragma once

#include "../Angle.hpp"
#include "../Circle.hpp"
#include "../Polygon.hpp"
#include "../Distance/PointAndPoint.hpp"
#include "../CrossPoint/CircleAndCircle.hpp"

namespace zawa {

namespace geometryR2 {

// ref: https://tjkendev.github.io/procon-library/python/geometry/circles_intersection_area.html
Real CommonArea(const Circle& c0, const Circle& c1) {
    const u32 cnt = NumberCommonTangent(c0, c1);
    if (cnt == 0u or cnt == 1u) { // 一方が他方に内包
        return std::min(c0.area(), c1.area());
    }
    else if (cnt == 2) { // いい感じに交わってて困る
        const auto [P, Q] = CrossPoint(c0, c1);
        const Real d = Distance(c0.center(), c1.center());
        const Real a0 = acosl((Square(c0.radius()) + Square(d) - Square(c1.radius())) / (2*d*c0.radius()));
        const Real a1 = acosl((Square(c1.radius()) + Square(d) - Square(c0.radius())) / (2*d*c1.radius()));
        Real res = 0;
        res += c0.sectorArea(2 * a0);
        res += c1.sectorArea(2 * a1);
        res -= Polygon{{P, c0.center(), Q, c1.center()}}.area();
        return res;
    }
    else { // 交わってない
        return 0;
    }
}

} // namespace geometryR2

} // namespace zawa
