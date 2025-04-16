#pragma once

#include <concepts>

namespace zawa {

namespace concepts {

template <class T>
concept Semigroup = requires {
    typename T::Element;
    { T::operation(std::declval<typename T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename T::Element>;
};

} // namespace concepts

} // namespace zawa
