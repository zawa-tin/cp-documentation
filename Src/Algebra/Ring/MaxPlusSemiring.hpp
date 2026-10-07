#pragma once

#include "../Group/AdditiveGroup.hpp"

#include <algorithm>
#include <concepts>

namespace zawa {

namespace internal {

template <std::totally_ordered T, T INF>
struct Max {

    using Element = T; 

    static Element identity() {
        return INF;
    }

    static Element operation(Element L,Element R) {
        return std::max(L,R);
    }
    
};

} // namespace internal

template <std::totally_ordered T,T INF>
struct MaxPlusSemiring {

    using Element = T;

    using Addition = internal::Max<T,INF>;

    using Multiplication = AdditiveGroup<T>;

};

} // namespace zawa
