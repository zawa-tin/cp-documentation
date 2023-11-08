#pragma once

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

constexpr bool IsZero(Real value) {
    return Sign(value) == internal::zero;
}

constexpr bool IsPositive(Real value) {
    return Sign(value) == internal::positive;
}

constexpr bool IsNegative(Real value) {
    return Sign(value) == internal::negative;
}

constexpr bool Equal(Real a, Real b) {
    return IsZero(a - b);
}

constexpr bool Smaller(Real a, Real b) {
    return IsNegative(a - b);
}

constexpr bool Bigger(Real a, Real b) {
    return IsPositive(a - b);
}

} // namespace geometryR2
 
} // namespace zawa
