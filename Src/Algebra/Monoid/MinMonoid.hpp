#pragma once

#include <limits>
#include <algorithm>

namespace zawa {

template <class T>
class MinMonoid {
public:
    using Element = T;
    // CHECK!!!
    static constexpr Element identity() noexcept {
        return std::numeric_limits<Element>::max() >> 1;
    }
    static constexpr Element operation(Element a, Element b) noexcept {
        return std::min(a, b);
    }
};

} // namespace zawa
