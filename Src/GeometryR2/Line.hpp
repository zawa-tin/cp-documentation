#pragma once

#include "./Point.hpp"
#include "./Relation.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

class Line {
private:
    Point p0_{}, p1_{};
public:
    /* constructor */
    Line() = default;
    Line(const Point& p0, const Point& p1) : p0_{p0}, p1_{p1} {}
    // y = ax + b 
    Line(Real a, Real b) : p0_{static_cast<Real>(0), b}, p1_{static_cast<Real>(1), a + b} {}

    /* getter, setter */
    const Point& p0() const {
        return p0_;
    }
    Point& p0() {
        return p0_;
    }
    const Point& p1() const {
        return p1_;
    }
    Point& p1() {
        return p1_;
    }

    /* member function */
    bool isValid() const {
        return p0_ != p1_;
    }

    /* friend function */
    friend bool Parallel(const Line& lhs, const Line& rhs) {
        assert(lhs.isValid());
        assert(rhs.isValid());
        Vector lVector{lhs.p1() - lhs.p0()};
        Vector rVector{rhs.p1() - rhs.p0()};
        return Zero(Cross(lVector, rVector));
    }
    friend bool Orthgonal(const Line& lhs, const Line& rhs) {
        assert(lhs.isValid());
        assert(rhs.isValid());
        Vector lVector{lhs.p1() - lhs.p0()};
        Vector rVector{rhs.p1() - rhs.p0()};
        return Zero(Dot(lVector, rVector));
    }
};

} // namespace geometryR2

} // namespace zawa
