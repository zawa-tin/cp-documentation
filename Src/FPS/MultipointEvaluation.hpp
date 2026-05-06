#pragma once

#include "FPSNTTFriendly.hpp"
#include "DivisionOfPolynomials.hpp"

#include <bit>

namespace zawa {

template <usize MOD = 998244353>
std::vector<typename FPSNTTFriendly<MOD>::V> MultipointEvaluation(const FPSNTTFriendly<MOD>& f,const std::vector<typename FPSNTTFriendly<MOD>::V>& xs) {
    using fps = FPSNTTFriendly<MOD>;
    using mint = fps::V;
    if (f.empty() or xs.empty())
        return std::vector(xs.size(),mint{0});
    const usize n = std::bit_ceil(xs.size());
    std::vector<fps> prod(2*n,fps{std::vector<mint>{1}});
    for (usize i = 0 ; i < xs.size() ; i++)
        prod[n+i] = std::vector<mint>{-xs[i],1};
    for (usize i = n ; --i ; )
        prod[i] = prod[i<<1|0]*prod[i<<1|1];
    std::vector<fps> rem(2*n);
    rem[1] = DivisionOfPolynomials(f,prod[1]).second;
    for (usize i = 1 ; i < n ; i++) {
        rem[i<<1|0] = DivisionOfPolynomials(rem[i],prod[i<<1|0]).second;
        rem[i<<1|1] = DivisionOfPolynomials(rem[i],prod[i<<1|1]).second;
    }
    std::vector<mint> res(xs.size());
    for (usize i = 0 ; i < xs.size() ; i++)
        res[i] = rem[n+i].empty() ? mint{0} : rem[n+i][0];
    return res;
}

} // namespace zawa
