#pragma once

#include "../Monoid/MonoidConcept.hpp"

namespace zawa {

namespace Concept {

template <class T>
concept Inversible = requires {
    typename T::Element;
    { T::inverse(std::declval<typename T::Element>()) } -> std::same_as<typename T::Element>;
};

template <class T>
concept Group = Monoid<T> and Inversible<T>;

} // namespace Concept

} // namespace zawa
