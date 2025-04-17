#pragma once

#include "../Semigroup/SemigroupConcept.hpp"

#include <concepts>

namespace zawa {

namespace concepts {

template <class T>
concept Identitiable = requires {
    typename T::Element;
    { T::identity() } -> std::same_as<typename T::Element>;
};

template <class T>
concept Monoid = Semigroup<T> and Identitiable<T>;

} // namespace

} // namespace zawa
