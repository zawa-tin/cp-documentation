#pragma once

#include <type_traits>
#include <cassert>

namespace zawa {

template <class T>
constexpr T DivFloor(T a, T b) {
    static_assert(std::is_integral_v<T>, "DivFloor argument must be Integer");
    assert(b != T{});
    if constexpr (std::is_unsigned_v<T>) {
        return a / b;
    }
    else {
        if (b < 0) {
            a *= -1;
            b *= -1;
        }
        return (a >= 0 ? a / b : (a - b + 1) / b);
    }
}

template <class T>
constexpr T DivCeil(T a, T b) {
    static_assert(std::is_integral_v<T>, "DivCeil argument must be Integer");
    assert(b != T{});
    if constexpr (std::is_unsigned_v<T>) {
        return (a + b - 1) / b;
    }
    else {
        if (b < 0) {
            a *= -1;
            b *= -1;
        }
        return (a >= 0 ? (a + b - 1) / b : a / b);
    }
}

} // namespace zawa
