#pragma once

#include "../Template/TypeAlias.hpp"

#include <cassert>

namespace zawa {

namespace geometryZ2 {

using Zahlen = i64;

namespace internal {

constexpr i32 positive{1};
constexpr i32 zero{0};
constexpr i32 negative{-1};

} // namespace internal

constexpr i32 Sign(Zahlen value) {
    if (value < 0) return internal::negative;
    if (value > 0) return internal::positive;
    return internal::zero;
}

constexpr bool Positive(Zahlen value) {
    return Sign(value) == internal::positive;
}

constexpr bool Zero(Zahlen value) {
    return Sign(value) == internal::zero;
}

constexpr bool Negative(Zahlen value) {
    return Sign(value) == internal::negative;
}

constexpr Zahlen Abs(Zahlen value) {
    return (value > 0 ? value : -value);
}

} // namespace geometryZ2

} // namespace zawa
