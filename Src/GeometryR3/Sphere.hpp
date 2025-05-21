#pragma once

#include "./Point.hpp"

namespace zawa {

namespace geometryR3 {

template <std::floating_point T>
class Sphere {
public:

    Sphere() = default;

    Sphere(const Point<T>& c, T r) : m_c{c}, m_r{r} {}

    const Point<T>& center() const {
        return m_c;
    }

    Point<T>& center() {
        return m_c;
    }

    const T& radius() const {
        return m_r;
    }

    T& radius() {
        return m_r;
    }

private:

    Point<T> m_c{};

    T m_r{0};
};

} // namespace geometryR3

} // namespace zawa
