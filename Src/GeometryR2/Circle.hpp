#pragma once

#include "../Template/TypeAlias.hpp"
#include "./Real.hpp"
#include "./Point.hpp"
#include "./Distance/PointAndPoint.hpp"

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
    friend u32 NumberCommonTangent(const Circle& c0, const Circle& c1) {
        Real dist{DistanceSquare(c0.center(), c1.center())};
        Real down{Square(Abs(c0.radius() - c1.radius()))};
        if (Smaller(dist, down)) return 0;
        if (Equal(dist, down)) return 1;
        Real up{Square(c0.radius() + c1.radius())};
        if (Smaller(dist, up)) return 2;
        if (Equal(dist, up)) return 3;
        return 4;
    }
};

} // namespace geometryR2

} // namespace zawa
