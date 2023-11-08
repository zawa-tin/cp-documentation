#pragma once

#include "./Point.hpp"

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
};

} // namespace geometryR2

} // namespace zawa
