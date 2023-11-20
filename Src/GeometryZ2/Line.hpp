#pragma once

#include "./Zahlen.hpp"
#include "./Point.hpp"
#include "./Relation.hpp"

#include <cassert>

namespace zawa {

namespace geometryZ2 {

class Line {
private:
    Point p0_{}, p1_{};

    Vector positiveDir() const {
        Vector res{p1_ - p0_};
        if (Negative(res.x())) {
            res.x() *= -1;
            res.y() *= -1;
        }
        return res;
    }
public:
    /* constructor */
    Line() = default;
    Line(const Point& p0, const Point& p1) : p0_{p0}, p1_{p1} {}
    // y = ax + b
    Line(const Zahlen& a, const Zahlen& b) : p0_{Zahlen{}, b}, p1_{a, a + b} {}
    Line(const Line& l) : p0_{l.p0()}, p1_{l.p1()} {}

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
        return Zero(Cross(l0.p1() - l0.p0(), l1.p1() - l1.p0())) 
            and Zero(Cross(l1.p0() - l0.p0(), l0.p1() - l0.p0()));
    }
    friend bool operator!=(const Line& l0, const Line& l1) {
        return !(l0 == l1);
    }
    friend bool operator<(const Line& l0, const Line& l1) {
        if (Zero(Cross(l0.p1() - l0.p0(), l1.p1() - l1.p0()))) {
            return Relation(l0.p0(), l0.p1(), l1.p0()) == COUNTER_CLOCKWISE;
        }
        else {
            return ArgComp(l0.positiveDir(), l1.positiveDir());
        }
    }
    friend bool operator<=(const Line& l0, const Line& l1) {
        return (l0 == l1) or (l0 < l1);
    }
    friend bool operator>(const Line& l0, const Line& l1) {
        if (Zero(Cross(l0.p1() - l0.p0(), l1.p1() - l1.p0()))) {
            return Relation(l0.p0(), l0.p1(), l1.p0()) == CLOCKWISE;
        }
        else {
            return ArgComp(l0.positiveDir(), l1.positiveDir());
        }
    }
    friend bool operator>=(const Line& l0, const Line& l1) {
        return (l0 == l1) or (l0 > l1);
    }
};

} // namespace geometryZ2

} // namespace zawa

