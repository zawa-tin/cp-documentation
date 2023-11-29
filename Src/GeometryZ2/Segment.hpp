#pragma once

#include "./Zahlen.hpp"
#include "./Point.hpp"

namespace zawa {

namespace geometryZ2 {

class Segment {
private:
    Point p0_{}, p1_{};
public:
    /* constructor */
    Segment() = default;
    Segment(const Segment& s) : p0_{s.p0_}, p1_{s.p1_} {}
    Segment(const Point& p0, const Point& p1) : p0_{p0}, p1_{p1} {}

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
    Segment& operator=(const Segment& s) {
        p0_ = s.p0();
        p1_ = s.p1();
        return *this;
    }
    friend bool operator==(const Segment& s0, const Segment& s1) {
        return (s0.p0() == s1.p0() and s0.p1() == s1.p1())
            or (s0.p1() == s1.p1() and s0.p1() == s1.p0());
    }
    friend bool operator!=(const Segment& s0, const Segment& s1) {
        return !(s0 == s1);
    }
};

} // namespace geometryZ2

} // namespace zawa
