#pragma once

namespace zawa {

template <class T>
class AdditiveGroup {
public:
    using Element = T;
    static constexpr T identity() noexcept {
        return T{};
    }
    static constexpr T operation(T l,T r) noexcept {
        return l + r;
    }
    static constexpr T inverse(T v) noexcept {
        return -v;
    }
    template <class U>
    static constexpr T power(T v,U exp) noexcept {
        return v * static_cast<T>(exp);
    }
};

} // namespace zawa
