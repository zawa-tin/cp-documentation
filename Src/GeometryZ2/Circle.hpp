#pragma once

#include "../Template/TypeAlias.hpp"
#include "./Zahlen.hpp"
#include "./Point.hpp"
#include "./Distance/PointAndPoint.hpp"

#include <cassert>

namespace zawa {

namespace geometryZ2 {

class Circle {
private:
    Point center_{};
    Zahlen radius_{};
public:
    /* constructor */
    Circle() = default;
    Circle(const Point& center, const Zahlen radius) : center_{center}, radius_{radius} {
        assert(!Negative(radius_));
    }

    /* getter, setter */
    Point& center() {
        return center_;
    }
    const Point& center() const {
        return center_;
    }
    Zahlen& radius() {
        return radius_;
    }
    const Zahlen& radius() const {
        return radius_;
    }

    /* operator */
    Circle& operator=(const Circle& c) {
        radius_ = c.radius();
        center_ = c.center();
        return *this;
    }
    friend bool operator==(const Circle& c0, const Circle& c1) {
        return c0.radius() == c1.radius() and c0.center() == c1.center();
    }
    friend bool operator!=(const Circle& c0, const Circle& c1) {
        return c0.radius() != c1.radius() or c0.center() != c1.center();
    }

    /* member */
    
    Zahlen radiusSquare() const {
        return Square(radius_);
    }

    /* friend function */
    friend u32 NumberCommonTangent(const Circle& c0, const Circle& c1) {
        Zahlen dist{DistanceSquare(c0.center(), c1.center())};
        Zahlen down{Square(Abs(c0.radius() - c1.radius()))};
        if (dist < down) {
            return 0;
        }
        if (dist == down) {
            return 1;
        }
        Zahlen up{Square(c0.radius() + c1.radius())}; 
        if (dist < up) {
            return 2;
        }
        if (dist == up) {
            return 3;
        }
        return 4;
    }
};

} // namespace geometryZ2

} // namespace zawa
