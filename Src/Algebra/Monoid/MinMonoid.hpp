#pragma once

#include <limits>
#include <algorithm>

namespace zawa {

template <class T>
class MinMonoid {
public:
    using Element = T;
    static constexpr T identity() noexcept {
        return std::numeric_limits<T>::max();
    }
    static constexpr T operation(T a, T b) noexcept {
        return std::min(a, b);
    }
};

} // namespace zawa
