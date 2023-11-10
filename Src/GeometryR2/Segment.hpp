#pragma once

#include "./Point.hpp"
#include "./Relation.hpp"

#include <algorithm>

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
    bool valid() const {
        return p0_ != p1_;
    }
    bool straddle(const Segment& s) const {
        return Relation(p0_, p1_, s.p0()) * Relation(p0_, p1_, s.p1()) <= 0;
    }
    Real length() const {
        return Vector{p1_ - p0_}.norm();
    }
    Real distance(const Point& p) const {
        assert(valid());
        if (Negative(Dot(p1_ - p0_, p - p0_))) return Vector{p - p0_}.norm();
        if (Negative(Dot(p0_ - p1_, p - p1_))) return Vector{p - p1_}.norm();
        return Abs(Cross(p1_ - p0_, p - p0_) / length());
    }

    /* friend function */
    friend bool Intersect(const Segment& s0, const Segment& s1) {
        return s0.straddle(s1) and s1.straddle(s0); 
    }
    friend Real Distance(const Segment& s0, const Segment& s1) {
        if (Intersect(s0, s1)) return static_cast<Real>(0);
        return std::min({
                s0.distance(s1.p0()),
                s0.distance(s1.p1()),
                s1.distance(s0.p0()),
                s1.distance(s0.p1())
                });
    }
};

} // namespace geometryR2

} // namespace zawa
