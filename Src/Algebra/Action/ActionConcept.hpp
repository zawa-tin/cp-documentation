#pragma once

#include <concepts>

namespace zawa {

namespace concepts {

template <class G, class X>
concept Action = requires {
    typename G::Element;
    { G::action(std::declval<typename G::Element>(), std::declval<X>()) } -> std::same_as<X>;
};

// Is appropriate name X-set?
template <class G, class X>
concept Acted = requires {
    typename G::Element;
    { G::acted(std::declval<typename G::Element>(), std::declval<X>()) } -> std::same_as<typename G::Element>;
};

} // namespace concepts

} // namespace zawa
