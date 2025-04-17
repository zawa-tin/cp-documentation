#pragma once

#include "../../Algebra/Monoid/MonoidConcept.hpp"
#include "../../Algebra/Semigroup/SemigroupConcept.hpp"

#include <concepts>

namespace zawa {

namespace concepts {

template <class T>
concept SWAGable = requires {
    typename T::Element;
    typename T::Fold;
    typename T::Fold::Element;
    { T::convert(std::declval<typename T::Element>()) } -> std::same_as<typename T::Fold::Element>;
    { T::pushBack(std::declval<typename T::Fold::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename T::Fold::Element>;
    { T::pushFront(std::declval<typename T::Fold::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename T::Fold::Element>;
};

} // namespace concepts

template <concepts::Semigroup S>
class SemigroupSWAGable {
public:
    using Element = typename S::Element;
    using Fold = S;
    using F = Fold::Element;
    static F convert(Element v) {
        return v;
    }
    static F pushBack(F f, Element v) {
        return S::operation(f, v);
    }
    static F pushFront(F f, Element v) {
        return S::operation(v, f);
    }
    static F operation(F l, F r) {
        return S::operation(l, r);
    }
};

template <concepts::Monoid S>
class MonoidSWAGable {
public:
    using Element = typename S::Element;
    using Fold = S;
    using F = Fold::Element;
    static F convert(Element v) {
        return v;
    }
    static F pushBack(F f, Element v) {
        return S::operation(f, v);
    }
    static F pushFront(F f, Element v) {
        return S::operation(v, f);
    }
    static F identity() {
        return S::identity();
    }
    static F operation(F l, F r) {
        return S::operation(l, r);
    }
};

} // namespace zawa
