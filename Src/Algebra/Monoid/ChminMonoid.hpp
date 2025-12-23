#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <optional>

namespace zawa {

template <class T, class U>
class ChminMonoidData {
private:
    std::optional<T> priority_{};
    U value_{};
public:
    ChminMonoidData() = default;
    ChminMonoidData(const U& value)
        : priority_{std::nullopt}, value_{value} {}
    ChminMonoidData(const T& priority, const U& value)
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
    friend constexpr bool operator<(const ChminMonoidData& l, const ChminMonoidData& r) {
        if (l.infty()) return false;
        else if (r.infty()) return true;
        else return l.priority() < r.priority();
    }
};

template <class T, class U>
struct ChminMonoid {
    using Element = ChminMonoidData<T, U>;
    static Element identity() noexcept {
        return Element{};
    }
    static Element operation(const Element& l, const Element& r) noexcept {
        return (r < l ? r : l);
    }
};

} // namespace zawa
