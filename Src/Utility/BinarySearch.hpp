#pragma once

#include "../Template/TypeAlias.hpp"

#include <cmath>
#include <functional>
#include <type_traits>
#include <utility>

namespace zawa {

namespace internal {

template <class T>
T MidPoint(T a, T b) {
    if (a > b) std::swap(a, b);
    return a + ((b - a) >> 1);
}

template <class T>
T Abs(T a, T b) {
    return (a >= b ? a - b : b - a);
}

} // namespace zawa::internal

template <class T, class Function>
T BinarySearch(T ok, T ng, const Function& f) {
    static_assert(std::is_integral_v<T>, "T must be integral type");
    static_assert(std::is_convertible_v<Function, std::function<bool(T)>>, "f must be function bool(T)");
    while (internal::Abs(ok, ng) > 1) {
        T mid{ internal::MidPoint(ok, ng) };
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}

template <class T, class Function>
T BinarySearch(T ok, T ng, const Function& f, u32 upperLimit) {
    static_assert(std::is_signed_v<T>, "T must be signed arithmetic type");
    static_assert(std::is_convertible_v<Function, std::function<bool(T)>>, "f must be function bool(T)");
    for (u32 _{} ; _ < upperLimit ; _++) {
        T mid{ (ok + ng) / (T)2 };
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}

} // namespace zawa
