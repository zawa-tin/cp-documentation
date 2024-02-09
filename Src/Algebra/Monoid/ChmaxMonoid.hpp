#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <optional>

namespace zawa {

template <class T, class U>
class ChmaxMonoidData {
private:
    std::optional<T> priority_{};
    U value_{};
public:
    ChmaxMonoidData() = default;
    ChmaxMonoidData(const U& value)
        : priority_{std::nullopt}, value_{value} {}
    ChmaxMonoidData(const T& priority, const U& value)
        : priority_{priority}, value_{value} {}

    constexpr bool infty() const noexcept {
        return !priority_.has_value();
    }
    constexpr const T& priority() const noexcept {
        return priority_.value();
    }
    constexpr const U& value() const noexcept {
        return value_;
    }
    friend constexpr bool operator>(const ChmaxMonoidData& l, const ChmaxMonoidData& r) {
        if (l.infty()) return false;
        else if (r.infty()) return true;
        else return l.priority() > r.priority();
    }
};

template <class T, class U>
struct ChmaxMonoid {
    using Element = ChmaxMonoidData<T, U>;
    static Element identity() noexcept {
        return Element{};
    }
    // タイブレークはl側を優先するようになっている。
    static Element operation(const Element& l, const Element& r) noexcept {
        return (r > l ? r : l);
    }
};

} // namespace zawa
