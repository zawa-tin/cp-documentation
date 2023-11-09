#pragma once

#include "../Template/TypeAlias.hpp"
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
    friend u32 NumberCommonTangent(const Circle& lhs, const Circle& rhs) {
        Real dist{DistanceSquare(lhs.center(), rhs.center())};
        Real down{Square(Abs(lhs.radius() - rhs.radius()))};
        if (Smaller(dist, down)) return 0;
        if (Equal(dist, down)) return 1;
        Real up{Square(lhs.radius() + rhs.radius())};
        if (Smaller(dist, up)) return 2;
        if (Equal(dist, up)) return 3;
        return 4;
    }
    friend bool Intersect(const Circle& lhs, const Circle& rhs) {
        u32 numberCommonTangent{NumberCommonTangent(lhs, rhs)};
        return 0u < numberCommonTangent and numberCommonTangent < 4u;
    }
    friend std::pair<Point, Point> CrossPoint(const Circle& lhs, const Circle& rhs) {
        assert(lhs.center() != rhs.center());
        assert(Intersect(lhs, rhs));
        assert(!Zero(lhs.radius()) or !Zero(rhs.radius()));
        if (Zero(lhs.radius())) return {lhs.center(), lhs.center()};
        if (Zero(rhs.radius())) return {rhs.center(), rhs.center()};
        Real d{Distance(lhs.center(), rhs.center())};
        Real cosine{(Square(lhs.radius()) + Square(d) - Square(rhs.radius()))
            / (static_cast<Real>(2)*lhs.radius()*d)};
        Real rc{lhs.radius()*cosine};
        Real rs{Sqrt(Square(lhs.radius()) - Square(rc))};
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
