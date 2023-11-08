#pragma once

#include "./Point.hpp"

namespace zawa {

namespace geometryR2 {

class Line {
private:
    Point p1_{}, p2_{};
public:
    /* constructor */
    Line() = default;
    Line(const Point& p1, const Point& p2) : p1_{p1}, p2_{p2} {}
    // y = ax + b 
    Line(Real a, Real b) : p1_{static_cast<Real>(0), b}, p2_{static_cast<Real>(1), a + b} {}

    /* getter, setter */
    const Point& p1() const {
        return p1_;
    }
    Point& p1() {
        return p1_;
    }
    const Point& p2() const {
        return p2_;
    }
    Point& p2() {
        return p2_;
    }

    /* member function */
    bool isValid() const {
        return p1_ != p2_;
    }
};

} // namespace geometryR2

} // namespace zawa
