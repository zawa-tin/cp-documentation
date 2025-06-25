#pragma once

#include "../../Algebra/Monoid/MonoidConcept.hpp"

namespace zawa {

namespace concepts {

template <class T>
concept MonoidWithAction = requires {
    requires Monoid<typename T::ValueMonoid>;
    requires Monoid<typename T::OperatorMonoid>;
    { T::mapping(
            std::declval<typename T::ValueMonoid::Element>(),
            std::declval<typename T::OperatorMonoid::Element>()
            ) } -> std::same_as<typename T::ValueMonoid::Element>; 
};

} // namespace concepts

} // namespace zawa
