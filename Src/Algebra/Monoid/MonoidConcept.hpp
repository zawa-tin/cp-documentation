#pragma once

#include <concepts>

namespace zawa {

namespace Concept {

template <class T>
concept Monoid = requires {
    typename T::Element;
    { T::identity() } -> std::same_as<typename T::Element>;
    { T::operation(std::declval<typename T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename T::Element>;
};

} // namespace

} // namespace zawa
