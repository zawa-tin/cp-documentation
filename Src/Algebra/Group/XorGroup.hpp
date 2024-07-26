#pragma once

namespace zawa {

template <class T>
class XorGroup {
public:
    using Element = T;
    static constexpr Element identity() noexcept {
        return Element{};
    }
    static constexpr Element operation(const Element& l, const Element& r) noexcept {
        return l ^ r;
    }
    static constexpr Element inverse(const Element& v) noexcept {
        return v;
    }
};

} // namespace zawa
