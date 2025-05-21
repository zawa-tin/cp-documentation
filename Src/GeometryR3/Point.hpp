#pragma once

#include <array>
#include <cassert>
#include <cmath>
#include <concepts>
#include <iostream>
#include <utility>

#include "../Template/TypeAlias.hpp"

namespace zawa {

namespace geometryR3 {

template <std::floating_point T>
class Point {
public:

    Point() = default;

    Point(T x, T y, T z) : m_p{x, y, z} {}

    explicit Point(const std::array<T, 3>& p) : m_p{p} {}

    explicit Point(std::array<T, 3>&& p) : m_p{std::move(p)} {}

    const T& x() const {
        return m_p[0];
    }

    T& x() {
        return m_p[0];
    }

    const T& y() const {
        return m_p[1];
    }

    T& y() {
        return m_p[1];
    }

    const T& z() const {
        return m_p[2];
    }

    T& z() {
        return m_p[2];
    }

    const T& operator[](usize i) const {
        assert(i < 3);
        return m_p[i];
    }

    T& operator[](usize i) {
        assert(i < 3);
        return m_p[i];
    }

    Point<T>& operator+=(const Point<T>& p) {
        m_p[0] += p[0];
        m_p[1] += p[1];
        m_p[2] += p[2];
        return *this;
    }

    Point<T>& operator-=(const Point<T>& p) {
        m_p[0] -= p[0];
        m_p[1] -= p[1];
        m_p[2] -= p[2];
        return *this;
    }

    Point<T>& operator*=(T k) {
        m_p[0] *= k;
        m_p[1] *= k;
        m_p[2] *= k;
        return *this;
    }

    Point<T>& operator/=(T k) {
        m_p[0] /= k;
        m_p[1] /= k;
        m_p[2] /= k;
        return *this;
    }

    T normSquare() const {
        return m_p[0]*m_p[0] + m_p[1]*m_p[1] + m_p[2]*m_p[2];
    }

    T norm() const {
        return sqrtl(normSquare());
    }

    Point<T> normalized() const {
        return Point<T>{*this} /= norm();
    }

    // ロドリゲスの回転公式 https://manabitimes.jp/math/2649
    Point<T> rotated(const Point<T>& axis, T theta) const {
        const T cosT = cosl(theta), sinT = sinl(theta);
        const Point<T> cp{*this};
        return cosT * cp + (1 - cosT) * DotProduct(axis, cp) * axis + sinT * CrossProduct(axis, cp);
    }

private:

    std::array<T, 3> m_p{T{0}, T{0}, T{0}};

};

template <std::floating_point T>
Point<T> operator+(const Point<T>& lhs, const Point<T>& rhs) {
    return Point<T>{lhs} += rhs;
}

template <std::floating_point T>
Point<T> operator-(const Point<T>& lhs, const Point<T>& rhs) {
    return Point<T>{lhs} -= rhs;
}

template <std::floating_point T>
Point<T> operator*(const T k, const Point<T>& p) {
    return Point<T>{p} *= k;
}

template <std::floating_point T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
    os << '(' << p[0] << ',' << p[1] << ',' << p[2] << ')';
    return os;
}

template <std::floating_point T>
std::istream& operator>>(std::istream& is, Point<T>& p) {
    is >> p[0] >> p[1] >> p[2];
    return is;
}

template <std::floating_point T>
T DistanceSquare(const Point<T>& lhs, const Point<T>& rhs) {
    return Point{lhs - rhs}.normSquare();
}

template <std::floating_point T>
T Distance(const Point<T>& lhs, const Point<T>& rhs) {
    return sqrtl(DistanceSquare(lhs, rhs));
}

template <std::floating_point T>
T DotProduct(const Point<T>& lhs, const Point<T>& rhs) {
    return lhs[0]*rhs[0] + lhs[1]*rhs[1] + lhs[2]*rhs[2];
}

template <std::floating_point T>
Point<T> CrossProduct(const Point<T>& lhs, const Point<T>& rhs) {
    return {
        lhs[1]*rhs[2]-lhs[2]*rhs[1],
        lhs[2]*rhs[0]-lhs[0]*rhs[2],
        lhs[0]*rhs[1]-lhs[1]*rhs[0],
    };
}

template <std::floating_point T>
using Vector = Point<T>;

} // namespace geometryR3

} // namespace zawa
