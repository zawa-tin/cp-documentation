#pragma once

#include "../../Template/TypeAlias.hpp"

#include <limits>
#include <algorithm>

namespace zawa {

template <class T>
class MinWithIndexMonoidData {
private:
    // CHECK!! LIMIT
    T value_{std::numeric_limits<T>::max()};
    usize index_{}; 
public:
    constexpr MinWithIndexMonoidData() {}
    constexpr MinWithIndexMonoidData(const T& value, usize index) : value_{value}, index_{index} {}

    constexpr const T& value() const noexcept {
        return value_;
    } 
    T& value() noexcept {
        return value_;
    }
    constexpr const usize& index() const noexcept {
        return index_;
    }
    usize& index() noexcept {
        return index_;
    }
};

template <class T>
struct MinWithIndexMonoid {
    using Element = MinWithIndexMonoidData<T>;
    static constexpr Element identity() noexcept {
        return Element{};
    }
    // CHECK!!! tie break
    static constexpr Element operation(const Element& lhs, const Element& rhs) noexcept {
        return (rhs.value() < lhs.value() ? rhs : lhs);
    }
};

} // namespace zawa
