#pragma once

#include "../Template/TypeAlias.hpp"

#include <cmath>
#include <functional>
#include <type_traits>

namespace zawa {

template <class T, class Function>
T BinarySearch(T ok, T ng, const Function& f) {
    static_assert(std::is_integral_v<T>, "T must be integral type");
    static_assert(std::is_signed_v<T>, "T must be signed arithmetic type");
    static_assert(std::is_convertible_v<Function, std::function<bool(T)>>, "f must be function bool(T)");
    while (std::abs(ok - ng) > 1) {
        T mid{ (ok + ng) >> 1 };
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
