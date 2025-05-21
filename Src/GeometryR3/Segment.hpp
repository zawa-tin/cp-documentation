#pragma once

#include "./Point.hpp"

#include <algorithm>
#include <concepts>

namespace zawa {

namespace geometryR3 {

template <std::floating_point T>
class Segment {
public:
    
    Segment() = default;

    Segment(const Point<T>& p, const Point<T>& q) : m_p{p}, m_q{q} {}

    Segment(Point<T>&& p, Point<T>&& q) : m_p{std::move(p)}, m_q{std::move(q)} {}

    const Point<T>& p() const {
        return m_p;
    }

    Point<T>& p() {
        return m_p;
    }

    const Point<T>& q() const {
        return m_q;
    }

    Point<T>& q() {
        return m_q;
    }

    Vector<T> direction() const {
        return m_q - m_p;
    }

    Vector<T> unitDirection() const {
        return Vector<T>{m_q - m_p}.normalized();
    }

    Point<T> dividingPoint(T ratio) const {
        return m_p + ratio * direction();
    }

private:

    Point<T> m_p{}, m_q{};
};

template <std::floating_point T>
T Distance(const Point<T>& p, const Segment<T>& s) {
    const Vector<T> d = s.direction();
    const T k = std::clamp(DotProduct(d, p - s.p()) / d.normSquare(), T{0}, T{1});
    return Distance(s.dividingPoint(k), p);
}

} // namespace geometryR3

} // namespace zawa
