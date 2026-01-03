#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include <concepts>

#include "../Template/TypeAlias.hpp"
#include "FPS.hpp"

namespace zawa {

template <class C, concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
FPS PolynomialTaylorShift(FPS a, C c, Conv conv = {}) {
    assert(a.size());
    FPS invfact(a.size());
    using T = typename FPS::value_type;
    T f{1};
    for (usize i = 1 ; i < a.size() ; i++) {
        f *= i;
        a[i] *= f;
    }
    invfact.back() = T{1} / f;
    for (usize i = a.size() - 1 ; i >= 1 ; i--) 
        invfact[i - 1] = invfact[i] * T{i};
    FPS right(a.size());
    T powc = 1;
    for (usize i = 0 ; i < a.size() ; i++) {
        right[i] = invfact[i] * powc;
        powc *= T{c};
    }
    std::ranges::reverse(a);
    const usize n = a.size();
    FPS b = conv(std::move(a), std::move(right));
    b.resize(n);
    std::ranges::reverse(b);
    for (usize i = 0 ; i < b.size() ; i++) 
        b[i] *= invfact[i];
    return b;
}

} // namespace zawa
