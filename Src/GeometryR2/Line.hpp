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

    /* operator */
    friend bool operator==(const Line& l0, const Line& l1) {
        return Zero(Cross(l0.p1() - l0.p0(), l1.p1() - l1.p0())) and Zero(Cross(l0.p1() - l0.p0(), l1.p1() - l0.p0()));
    }
    friend bool operator!=(const Line& l0, const Line& l1) {
        return !Zero(Cross(l0.p1() - l0.p0(), l1.p1() - l1.p0())) or !Zero(Cross(l0.p1() - l0.p0(), l1.p1() - l0.p0()));
    }

    /* member function */
    bool valid() const {
        return p0_ != p1_;
    }
    Vector slope() const {
        assert(valid());
        return Vector{p1() - p0()}.normalized();
    }
};

} // namespace geometryR2

} // namespace zawa
