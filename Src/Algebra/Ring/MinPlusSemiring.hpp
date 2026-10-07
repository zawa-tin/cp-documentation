#pragma once

#include "../Group/AdditiveGroup.hpp"

#include <algorithm>
#include <concepts>

namespace zawa {

namespace internal {

template <std::totally_ordered T, T INF>
struct Min {

    using Element = T; 

    static Element identity() {
        return INF;
    }

    static Element operation(Element L,Element R) {
        return std::min(L,R);
    }
    
};

} // namespace internal

template <std::totally_ordered T,T INF>
struct MinPlusSemiring {

    using Element = T;

    using Addition = internal::Min<T,INF>;

    using Multiplication = AdditiveGroup<T>;

};

} // namespace zawa
