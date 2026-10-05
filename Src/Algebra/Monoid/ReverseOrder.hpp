#pragma once

#include "./MonoidConcept.hpp"
#include "../PowerableConcept.hpp"

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

    template <class U>
    static Element power(const Element& x,U exp) requires concepts::Powerable<M,U> {
        return M::power(x,exp);
    }

};

} // namespace zawa
