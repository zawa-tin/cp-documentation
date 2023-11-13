#pragma once

#include "./Point.hpp"
#include "./Relation.hpp"
#include "./Distance/PointAndPoint.hpp"

#include <algorithm>
#include <cassert>

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
        assert(valid());
        return Distance(p0_, p1_);
    }
};

} // namespace geometryR2

} // namespace zawa
