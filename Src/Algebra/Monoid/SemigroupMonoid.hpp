#pragma once

#include <optional>

namespace zawa {

template <class Semigroup>
struct SemigroupMonoid {
    using Element = std::optional<typename Semigroup::Element>;
    static Element identity() noexcept {
        return std::nullopt;
    }
    static Element operation(const Element& a, const Element& b) noexcept {
        if (!a) return b;
        else if (!b) return a;
        else return Semigroup::operation(a.value(), b.value());
    }
};

} // namespace zawa
