#pragma once

#include "./Point.hpp"
#include "./Relation.hpp"

namespace zawa {

namespace geometryR2 {

class Segment {
private:
    Point p0_{}, p1_{};
public:
    /* constructor */
    Segment() = default;
    Segment(const Point& p0, const Point& p1) : p0_{p0}, p1_{p1} {}
    Segment(Real x0, Real y0, Real x1, Real y1) : p0_{x0, y0}, p1_{x1, y1} {}

    /* getter setter */
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
    bool Straddle(const Segment& s) const {
        return Relation(p0_, p1_, s.p0()) * Relation(p0_, p1_, s.p1()) <= 0;
    }

    /* friend function */
    friend bool Intersect(const Segment& s0, const Segment& s1) {
        return s0.Straddle(s1) and s1.Straddle(s0); 
    }
};

} // namespace geometryR2

} // namespace zawa
