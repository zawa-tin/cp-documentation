#pragma once

#include <concepts>

namespace zawa {

template <class T,class U>
concept Powerable = requires {
    typename T::Element;
    { T::power(std::declval<typename T::Element>(), std::declval<U>()) }
        -> std::same_as<typename T::Element>;
};

} // namespace zawa
