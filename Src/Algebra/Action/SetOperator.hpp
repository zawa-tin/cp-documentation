#pragma once

#include <concepts>

namespace zawa {

namespace concepts {

template <class S, class T>
concept SetOperator = requires {
    typename S::Element;
    { S::identity() } -> std::same_as<typename S::Element>;
    { S::add(std::declval<typename S::Element&>(), std::declval<T>()) } -> std::same_as<void>;
    { S::remove(std::declval<typename S::Element&>(), std::declval<T>()) } -> std::same_as<void>;
};

} // namespace concepts

} // namespace zawa
