#pragma once

namespace zawa {

template <class T>
struct AdditionMonoid {
    using Element = T;
    static T identity() noexcept {
        return T{};
    }
    static T operation(const T& a, const T& b) noexcept {
        return a + b;
    }
};

} // namespace zawa
