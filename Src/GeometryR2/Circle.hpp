#pragma once

#include "./Real.hpp"
#include "./Point.hpp"

#include <cassert>
#include <utility>

namespace zawa {

namespace geometryR2 {

class Circle {
private:
    Point center_{};
    Real radius_{};
public:
    /* constructor */
    Circle() = default;
    Circle(const Point& center, Real radius) : center_{center}, radius_{radius} {
        assert(!Negative(radius));
    }
    Circle(Real x, Real y, Real r) : center_{x, y}, radius_{r} {
        assert(!Negative(r));
    }

    /* getter setter */
    const Point& center() const {
        return center_;
    }
    Point& center() {
        return center_;
    }
    Real radius() const {
        return radius_;
    }
    Real& radius() {
        return radius_;
    }

    /* operator */
    friend bool operator==(const Circle& lhs, const Circle& rhs) {
        return lhs.center() == rhs.center() and Equal(lhs.radius(), rhs.radius());
    }
    friend bool operator!=(const Circle& lhs, const Circle& rhs) {
        return lhs.center() != rhs.center() or !Equal(lhs.radius(), rhs.radius());
    }

    /* friend function */
    friend bool Intersect(const Circle& lhs, const Circle& rhs) {
        Real centerDist{DistanceSquare(lhs.center(), rhs.center())};
        Real down{std::abs(lhs.radius() - rhs.radius())};
        down = down * down;
        if (Smaller(centerDist, down)) return false;
        Real up{lhs.radius() + rhs.radius()};
        up = up * up;
        if (Bigger(centerDist, up)) return false;
        return true;
    }
    friend std::pair<Point, Point> CrossPoint(const Circle& lhs, const Circle& rhs) {
        assert(lhs.center() != rhs.center());
        assert(Intersect(lhs, rhs));
        assert(!Zero(lhs.radius()) or !Zero(rhs.radius()));
        if (Zero(lhs.radius())) return {lhs.center(), lhs.center()};
        if (Zero(rhs.radius())) return {rhs.center(), rhs.center()};
        Real d{Distance(lhs.center(), rhs.center())};
        Real cosine{(lhs.radius()*lhs.radius() + d*d - rhs.radius()*rhs.radius())
            / (static_cast<Real>(2)*lhs.radius()*d)};
        Real rc{lhs.radius()*cosine};
        Real rs{sqrtl(lhs.radius()*lhs.radius() - rc*rc)};
        Vector lr{Vector{rhs.center() - lhs.center()}.normalized()};
        Vector h{lhs.center() + lr*rc};
        std::pair<Point, Point> res;
        res.first = h + lr.rotatedByArc(90) * rs;
        res.second = h + lr.rotatedByArc(-90) * rs;
        return res;
    }
};

} // namespace geometryR2

} // namespace zawa
