#pragma once

#include "../Template/TypeAlias.hpp"

#include <cmath>
#include <cassert>

namespace zawa {

namespace geometryR2 {

using Real = long double;

namespace internal {

Real EPS{1e-12};
constexpr i32 negative{-1};
constexpr i32 zero{};
constexpr i32 positive{1};

} // namespace internal

Real& Eps() {
    return internal::EPS;
}

i32 Sign(Real value) {
    if (value < -Eps()) return internal::negative;
    if (value > Eps()) return internal::positive;
    return internal::zero;
}

bool Zero(Real value) {
    return Sign(value) == internal::zero;
}

bool Positive(Real value) {
    return Sign(value) == internal::positive;
}

bool Negative(Real value) {
    return Sign(value) == internal::negative;
}

bool Equal(Real a, Real b) {
    return Zero(a - b);
}

bool Smaller(Real a, Real b) {
    return Negative(a - b);
}

bool Bigger(Real a, Real b) {
    return Positive(a - b);
}

Real Square(Real value) {
    return (Zero(value) ? value : value * value);
}

Real Sqrt(Real value) {
    assert(!Negative(value));
    return (Zero(value) ? value : sqrtl(value));
}

Real Abs(Real value) {
    return (Negative(value) ? -value : value);
}

} // namespace geometryR2
 
} // namespace zawa
