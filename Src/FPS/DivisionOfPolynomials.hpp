#pragma once

#include "FPSNTTFriendly.hpp"

#include <algorithm>
#include <ranges>
#include <utility>

namespace zawa {

// f = gq + r
// first... q
// second... r
template <usize MOD = 998244353>
std::pair<FPSNTTFriendly<MOD>, FPSNTTFriendly<MOD>> DivisionOfPolynomials(FPSNTTFriendly<MOD> f, FPSNTTFriendly<MOD> g) {
    while (g.size() and g.back() == 0)
        g.pop_back();
    while (f.size() and f.back() == 0)
        f.pop_back();
    assert(g.size());
    const usize n = f.size(), m = g.size();
    if (n == 0 or n < m)
        return {FPSNTTFriendly<MOD>{}, f};
    std::ranges::reverse(f);
    std::ranges::reverse(g);
    auto q = f * g.inv(n);
    if (q.size() > n - m + 1)
        q.resize(n - m + 1);
    std::ranges::reverse(f);
    std::ranges::reverse(g);
    std::ranges::reverse(q);
    auto r = f - g * q;
    while (r.size() and r.back() == 0)
        r.pop_back();
    return {q, r};
}

} // namespace zawa
