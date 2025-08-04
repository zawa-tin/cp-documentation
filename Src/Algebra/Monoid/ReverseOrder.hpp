#pragma once

#include "./MonoidConcept.hpp"

namespace zawa {

template <concepts::Monoid M>
struct ReverseOrder {

    using Element = M::Element;
    
    static Element identity() {
        return M::identity();
    }

    static Element operation(const Element& L, const Element& R) {
        return M::operation(R, L);
    }

};

} // namespace zawa
