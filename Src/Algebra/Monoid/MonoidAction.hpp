#pragma once

#include "./MonoidConcept.hpp"

namespace zawa {

template <concepts::Monoid M>
struct AddSelfAction : public M {
    static M::Element action(M::Element a, M::Element b) {
        return M::operation(a, b);
    }
    static M::Element acted(M::Element a, M::Element b) {
        return M::operation(a, b);
    }
};

} // namespace zawa
