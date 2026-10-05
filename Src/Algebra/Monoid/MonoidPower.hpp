#pragma once

#include "../PowerableConcept.hpp"
#include "./MonoidConcept.hpp"

#include <concepts>

namespace zawa {

template <concepts::Monoid M,std::unsigned_integral U>
typename M::Element MonoidPower(const typename M::Element& x,U exp) {
    if constexpr (concepts::Powerable<M,U>) 
        return M::power(x,exp);
    else {
        auto a = x;
        auto res = M::identity();
        while (exp) {
            if (exp & 1)
                res = M::operation(res,a);
            a = M::operation(a,a);
            exp >>= 1;
        }
        return res;
    }
}

} // namespace zawa
