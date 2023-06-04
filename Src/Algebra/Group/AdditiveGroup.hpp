#pragma once

namespace zawa {

template <class T>
class AdditiveGroup {
public:
    using value_type = T;
    static constexpr T identity() noexcept {
        return T{};
    }
    static constexpr T operation(const T& l, const T& r) noexcept {
        return l + r;
    }
    static constexpr T inverse(const T& v) noexcept {
        return -v;
    }
};

} // namespace zawa
