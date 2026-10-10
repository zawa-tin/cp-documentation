#pragma once

#include "../Template/TypeAlias.hpp"
#include "FPS.hpp"
#include "PolynomialProducts.hpp"

#include <vector>

namespace zawa {

template <concepts::IndexedFPS FPS,class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
FPS EnumeratePowerSums(std::vector<typename FPS::value_type> A,usize K,Conv conv={}) {
    using mint=typename FPS::value_type;
    std::vector<FPS> poly(std::ssize(A),FPS(2));
    for (usize i = 0 ; i < A.size() ; i++) {
        poly[i][0]=1;
        poly[i][1]=-mint{A[i]};
    }
    FPS prod=PolynomialProducts(poly);
    prod=prod.log(K+1).differential();
    FPS res(K+1);
    res[0]=std::ssize(A);
    for (usize i = 1 ; i <= K ; i++)
        res[i]=-prod[i-1];
    return res;
}

} // namespace zawa
