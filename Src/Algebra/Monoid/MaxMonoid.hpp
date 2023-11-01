#pragma once

#include <limits>
#include <algorithm>

namespace zawa {

template <class T>
class MaxMonoid {
public:
    using Element = T;
    // CHECK!!!
    static constexpr Element identity() noexcept {
        return std::numeric_limits<Element>::min();
    }
    static constexpr Element operation(Element a, Element b) noexcept {
        return std::max(a, b);
    }
};

} // namespace zawa
