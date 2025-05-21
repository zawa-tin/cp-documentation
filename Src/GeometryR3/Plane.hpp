#pragma once

#include "./Point.hpp"

#include <concepts>

namespace zawa {

namespace geometryR3 {

template <std::floating_point T>
class Plane {
public: 

    Plane() = default;

    Plane(const Vector<T>& p, const Vector<T>& q) : m_p{p}, m_q{q} {}

    Plane(const Point<T>& p, const Point<T>& q, const Point<T>& r) : m_p{q - p}, m_q{r - p} {}

    Vector<T> normalVector() const {
        return CrossProduct(m_p, m_q).normalized();
    }

private:

    Vector<T> m_p, m_q;
};

} // namespace geometryR3

} // namespace zawa
