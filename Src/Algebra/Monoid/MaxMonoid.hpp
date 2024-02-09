#pragma once

#include <algorithm>
#include <limits>
#include <optional>

namespace zawa {

template <class T>
class MaxMonoid {
public:
    using Element = std::optional<T>;
    static constexpr Element identity() noexcept {
        return std::nullopt;
    }
    static constexpr Element operation(const Element& l, const Element& r) noexcept {
        if (l and r) {
            return std::max(l, r);
        }
        else if (l) {
            return l;
        }
        else if (r) {
            return r;
        }
        else {
            return std::nullopt;
        }
    }
};

} // namespace zawa
