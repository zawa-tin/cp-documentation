#pragma once

#include "../Template/TypeAlias.hpp"
#include "./Zahlen.hpp"

#include <iostream>
#include <cassert>

namespace zawa {

namespace geometryZ2 {

class Point {
private:
    Zahlen x_{}, y_{};
    static constexpr u32 origin{0};
    static constexpr u32 firstQuadrant{1};
    static constexpr u32 secondQuadrant{1};
    static constexpr u32 thirdQuadrant{1};
    static constexpr u32 forthQuadrant{1};

    u32 area() const {
        if (x_ == 0 and y_ == 0) return origin;
        if (x_ > 0 and y_ >= 0) return firstQuadrant;
        if (x_ <= 0 and y_ > 0) return secondQuadrant;
        if (x_ < 0 and y_ <= 0) return thirdQuadrant;
        return forthQuadrant;
    }
public:
    /* constructor */
    Point() = default;
    Point(const Point& p) : x_{p.x()}, y_{p.y()} {}
    Point(Zahlen x, Zahlen y) : x_{x}, y_{y} {}

    /* getter setter */
    Zahlen& x() {
        return x_;
    }
    const Zahlen& x() const {
        return x_;
    }
    Zahlen& y() {
        return y_;
    }
    const Zahlen& y() const {
        return y_;
    }

    /* operator */
    Point& operator=(const Point& p) {
        x() = p.x();
        y() = p.y();
        return *this;
    }
    Point& operator+=(const Point& p) {
        x() += p.x();
        y() += p.y();
        return *this;
    }
    friend Point operator+(const Point& p0, const Point& p1) {
        return Point{p0} += p1;
    }
    Point& operator-=(const Point& p) {
        x() -= p.x();
        y() -= p.y();
        return *this;
    }
    friend Point operator-(const Point& p0, const Point& p1) {
        return Point{p0} -= p1;
    }
    Point& operator*=(Zahlen k) {
        x() *= k;
        y() *= k;
        return *this;
    }
    friend Point operator*(const Point& p, Zahlen k) {
        return Point{p} *= k;
    }
    friend Point operator*(Zahlen k, const Point& p) {
        return Point{p} *= k;
    }
    Point& operator/=(Zahlen k) {
        assert(k);
        assert(x() % k == 0);
        assert(y() % k == 0);
        x() /= k;
        y() /= k;
        return *this;
    }
    friend Point operator/(const Point& p, Zahlen k) {
        return Point{p} /= k;
    }
    friend bool operator==(const Point& p0, const Point& p1) {
        return p0.x() == p1.x() and p0.y() == p1.y();
    }
    friend bool operator!=(const Point& p0, const Point& p1) {
        return p0.x() != p1.x() or p0.y() != p1.y();
    }
    friend bool operator<(const Point& p0, const Point& p1) {
        if (p0.x() != p1.x()) return p0.x() < p1.x();
        else return p0.y() < p1.y();
    }
    friend bool operator<=(const Point& p0, const Point& p1) {
        return (p0 < p1) or (p0 == p1);
    }
    friend bool operator>(const Point& p0, const Point& p1) {
        if (p0.x() != p1.x()) return p0.x() > p1.x();
        else return p0.y() > p1.y();
    }
    friend bool operator>=(const Point& p0, const Point& p1) {
        return (p0 > p1) or (p0 == p1);
    }
    friend std::istream& operator>>(std::istream& is, Point& p) {
        is >> p.x() >> p.y();
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << '(' << p.x() << ',' << p.y() << ')';
        return os;
    }

    /* member function */
    Zahlen normSquare() const {
        return Square(x()) + Square(y());
    }

    /* friend function */
    friend Zahlen Dot(const Point& p0, const Point& p1) {
        return p0.x() * p1.x() + p0.y() * p1.y();
    }
    friend Zahlen Cross(const Point& p0, const Point& p1) {
        return p0.x() * p1.y() - p0.y() * p1.x();
    }
    friend bool ArgComp(const Point& p0, const Point& p1) {
        if (p0.area() != p1.area()) return p0.area() < p1.area();
        Zahlen cross{Cross(p0, p1)};
        return (!Zero(cross) ? Positive(cross) : p0.normSquare() < p1.normSquare());
    }
};
using Vector = Point;

} // namespace geometryZ2

} // namespace zawa
