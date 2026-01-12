#pragma once

#include "FPS.hpp"

#include <vector>

namespace zawa {

template <concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
FPS PolynomialProducts(std::vector<FPS> F, Conv convolution = {}) {
    if (F.empty())
        return {1};
    auto rec = [&](auto rec, usize l, usize r) -> void {
        if (l + 1 >= r)
            return;
        const usize md = (l + r) >> 1;
        rec(rec, l, md);
        rec(rec, md, r);
        F[l] = convolution(F[l], F[md]);
    };
    rec(rec, 0u, F.size());
    return F[0];
}

} // namespace zawa
