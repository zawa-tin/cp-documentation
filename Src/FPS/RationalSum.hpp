#pragma once

#include "FPS.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

template <concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
std::pair<FPS, FPS> RationalSum(std::vector<FPS> num, std::vector<FPS> den, Conv conv = {}) {
    assert(num.size() == den.size());
    if (num.empty())
        return std::pair<FPS, FPS>{{0}, {1}};
    auto rec = [&](auto rec, usize l, usize r) -> void {
        if (l + 1 >= r)
            return;
        const usize md = (l + r) >> 1;
        rec(rec, l, md);
        rec(rec, md, r);
        num[l] = conv(num[l], den[md]) + conv(num[md], den[l]);
        den[l] = conv(den[l], den[md]);
    };
    rec(rec, 0u, num.size());
    return std::pair{num[0], den[0]};
}

} // namespace zawa
