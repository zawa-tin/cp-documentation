#pragma once

#include <type_traits>

#include "../Group/AdditiveGroup.hpp"

namespace zawa {

namespace internal {

template <class T>
struct Multiplication {

    using Element = T;

    static constexpr Element identity() {
        return static_cast<Element>(1);
    }

    static constexpr Element operation(const Element& lhs, const Element& rhs) {
        return lhs * rhs;
    }

    static constexpr Element inverse(const Element& value) {
        return identity() / value;
    }
};

} // namespace internal

template <class T>
struct UsualRing {

    using Element = T;

    using Addition = AdditiveGroup<T>;

    using Multiplication = typename internal::Multiplication<T>;

};

} // namespace zawa
