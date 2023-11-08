#pragma once

#include "./Real.hpp"
#include "./Angle.hpp"

#include <cmath>
#include <iostream>

namespace zawa {

namespace geometryR2 {

class Point {
private:
    Real x_{}, y_{};
public:
    /* constructor */
    Point() = default;
    Point(Real x, Real y) : x_{x}, y_{y} {}

    /* getter, setter */
    Real x() const {
        return x_;
    }
    Real& x() {
        return x_;
    }
    Real y() const {
        return y_;
    }
    Real& y() {
        return y_;
    }

    /* operator */
    Point& operator+=(const Point& rhs) {
        x_ += rhs.x();
        y_ += rhs.y();
        return *this;
    }
    friend Point operator+(const Point& lhs, const Point& rhs) {
        return Point{lhs} += rhs;
    }
    Point operator+() const {
        return *this;
    }
    Point& operator-=(const Point& rhs) {
        x_ -= rhs.x();
        y_ -= rhs.y();
        return *this;
    }
    friend Point operator-(const Point& lhs, const Point& rhs) {
        return Point{lhs} -= rhs;
    }
    Point operator-() const {
        return Point{} - *this;
    }
    Point& operator*=(Real k) {
        x_ *= k;
        y_ *= k;
        return *this;
    }
    friend Point operator*(Real k, const Point& p) {
        return Point{p} *= k;
    }
    friend Point operator*(const Point& p, Real k) {
        return Point{p} *= k;
    }
    friend bool operator==(const Point& lhs, const Point& rhs) {
        return Equal(lhs.x(), rhs.x()) and Equal(lhs.y(), rhs.y());
    }
    friend bool operator!=(const Point& lhs, const Point& rhs) {
        return !Equal(lhs.x(), rhs.x()) or !Equal(lhs.y(), rhs.y());
    }
    friend bool operator<(const Point& lhs, const Point& rhs) {
        return Smaller(lhs.x(), rhs.x()) or 
            (Equal(lhs.x(), rhs.x()) and Smaller(lhs.y(), rhs.y()));
    }
    friend bool operator<=(const Point& lhs, const Point& rhs) {
        return Smaller(lhs.x(), rhs.x()) or 
            (Equal(lhs.x(), rhs.x()) and (Smaller(lhs.y(), rhs.y()) or Equal(lhs.y(), rhs.y())));
    }
    friend bool operator>(const Point& lhs, const Point& rhs) {
        return Bigger(lhs.x(), rhs.x()) or
            (Equal(lhs.x(), rhs.x()) and Bigger(lhs.y(), rhs.y()));
    }
    friend bool operator>=(const Point& lhs, const Point& rhs) {
        return Bigger(lhs.x(), rhs.x()) or
            (Equal(lhs.x(), rhs.x()) and (Bigger(lhs.y(), rhs.y()) or Equal(lhs.y(), rhs.y())));
    }
    friend std::istream& operator>>(std::istream& is, Point& p) {
        is >> p.x_ >> p.y_;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << '(' << p.x_ << ',' << p.y_ << ')';
        return os;
    }
    
    /* member function */
    Real normSquare() const {
        return x_ * x_ + y_ * y_;
    }
    Real norm() const {
        return sqrtl(normSquare());
    }
    Point rotated(Real radian) const {
        return Point{
            x_ * cosl(radian) - y_ * sinl(radian),
            x_ * sinl(radian) + y_ * cosl(radian)
        };
    }
    void rotate(Real radian) {
        *this = rotated(radian); 
    }
    Point rotatedByArc(Real arc) const {
        return rotated(ArcToRadian(arc));
    }
    void rotateByArc(Real arc) {
        *this = rotatedByArc(arc);
    }
    Real argument() const {
        return (IsNegative(y_) ? TAU : static_cast<Real>(0)) + atan2l(y_, x_);
    }
    Real argumentByArc() const {
        return RadianToArc(argument());
    }

    /* friend function */
    friend Real dot(const Point& lhs, const Point& rhs) {
        return lhs.x() * rhs.x() + lhs.y() * rhs.y();
    }
    friend Real DistanceSquare(const Point& lhs, const Point& rhs) {
        return Point{lhs - rhs}.normSquare();
    }
    friend Real Distance(const Point& lhs, const Point& rhs) {
        return Point{lhs - rhs}.norm();
    }
    friend Real Argument(const Point& lhs, const Point& rhs) {
        return rhs.argument() - lhs.argument();
    }
    friend bool ArgComp(const Point& lhs, const Point& rhs) {
        return Smaller(lhs.argument(), rhs.argument());
    }
};

} // namespace geomeryR2

} // namespace zawa
