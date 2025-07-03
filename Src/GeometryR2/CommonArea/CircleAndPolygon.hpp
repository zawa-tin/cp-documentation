#pragma once

#include "../Circle.hpp"
#include "../Polygon.hpp"
#include "../CrossPoint/CircleAndSegment.hpp"
#include "../Distance/PointAndPoint.hpp"

namespace zawa {

namespace geometryR2 {

Real CommonArea(const Circle& c, const Polygon& poly) {
    auto theta = [&](const Point& p, const Point& q) -> Real {
        const Real cosT = (p.normSquare() + q.normSquare() - DistanceSquare(p, q)) / (2 * p.norm() * q.norm());
        return acosl(cosT);
    };
    // signed common area of c and triangle(c.center(), p, q)
    auto common_area = [&](Point p, Point q) -> Real {
        p -= c.center();
        q -= c.center(); 
        if (Zero(Cross(p, q))) return 0;
        const bool pin = Smaller(p.normSquare(), Square(c.radius())), qin = Smaller(q.normSquare(), Square(c.radius()));
        if (pin and qin) return Cross(p, q) / 2;
        const auto cps = CrossPoint(c, Segment{p, q});
        if (cps.empty()) return Sign(Cross(p, q)) * c.sectorArea(theta(p, q));
        Real res = 0;
        if (pin) res += Cross(p, cps.front()) / 2;
        else {
            const Vector dir = p.normalized();
            const Point v = c.center() + dir * c.radius();
            res += Sign(Cross(v, cps.front())) * c.sectorArea(theta(v, cps.front()));
        }
        if (qin) res += Cross(cps.back(), q) / 2;
        else {
            const Vector dir = q.normalized();
            const Point v = c.center() + dir * c.radius();
            res += Sign(Cross(cps.back(), v)) * c.sectorArea(theta(cps.back(), v));
        }
        if (std::ssize(cps) == 2) res += Cross(cps[0], cps[1]) / 2;
        return res;
    };
    Real res = 0;
    for (usize i = 0 ; i < poly.size() ; i++) {
        const Real kiyo = common_area(poly[i], poly[i+1==poly.size()?0u:i+1]);
        res += kiyo;
    }
    return res;
}

} // namespace geometryR2

} // namespace zawa
