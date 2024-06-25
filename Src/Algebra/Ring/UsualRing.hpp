#pragma once

#include <type_traits>

namespace zawa {

namespace internal {

template <class T>
struct Addition {
    using Element = T;
    static Element identity() {
        return static_cast<Element>(0);
    }
    static Element operation(const Element& lhs, const Element& rhs) {
        return lhs + rhs;
    }
    static Element inverse(const Element& v) {
        return -v;
    }
};

template <class T>
struct Multiplication {
    using Element = T;
    static Element identity() {
        return static_cast<Element>(1);
    }
    static Element operation(const Element& lhs, const Element& rhs) {
        return lhs * rhs;
    }
    static Element inverse(const Element& value) {
        return identity() / value;
    }
};

} // namespace internal

template <class T>
struct UsualRing {
    using Element = T;
    using Addition = typename internal::Addition<T>;
    using Multiplication = typename internal::Multiplication<T>;
};

} // namespace zawa
