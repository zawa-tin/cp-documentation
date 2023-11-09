#pragma once

#include <cmath>
#include <cassert>

namespace zawa {

namespace geometryR2 {

using Real = long double;
constexpr Real EPS{1e-12};

namespace internal {

constexpr int negative{-1};
constexpr int zero{};
constexpr int positive{1};

} // namespace internal

constexpr int Sign(Real value) {
    if (value < -EPS) return internal::negative;
    if (value > EPS) return internal::positive;
    return internal::zero;
}

constexpr bool Zero(Real value) {
    return Sign(value) == internal::zero;
}

constexpr bool Positive(Real value) {
    return Sign(value) == internal::positive;
}

constexpr bool Negative(Real value) {
    return Sign(value) == internal::negative;
}

constexpr bool Equal(Real a, Real b) {
    return Zero(a - b);
}

constexpr bool Smaller(Real a, Real b) {
    return Negative(a - b);
}

constexpr bool Bigger(Real a, Real b) {
    return Positive(a - b);
}

constexpr Real Square(Real value) {
    return value * value;
}

constexpr Real Sqrt(Real value) {
    assert(!Negative(value));
    return (Zero(value) ? value : sqrtl(value));
}

constexpr Real Abs(Real value) {
    return (Negative(value) ? -value : value);
}

} // namespace geometryR2
 
} // namespace zawa
