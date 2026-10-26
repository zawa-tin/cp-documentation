#pragma once

#include "FPSNTTFriendly.hpp"
#include "SubproductTree.hpp"
#include "DivisionOfPolynomials.hpp"

#include <vector>

namespace zawa {

namespace internal {

template <usize MOD = 998244353>
std::vector<typename FPSNTTFriendly<MOD>::V> MultipointEvaluation(const FPSNTTFriendly<MOD>& f,const SubproductTree<FPSNTTFriendly<MOD>>& tree) {
    using fps = FPSNTTFriendly<MOD>;
    using mint = fps::V;
    const usize n=tree.innerSize();
    std::vector<fps> rem(n<<1);
    rem[1] = DivisionOfPolynomials(f,tree[1]).second;
    for (usize i = 1 ; i < n ; i++) {
        rem[i<<1|0] = DivisionOfPolynomials(rem[i],tree[i<<1|0]).second;
        rem[i<<1|1] = DivisionOfPolynomials(rem[i],tree[i<<1|1]).second;
    }
    std::vector<mint> res(tree.size());
    for (usize i = 0 ; i < tree.size() ; i++)
        res[i]=rem[n+i].empty()?mint{0}:rem[n+i][0];
    return res;
}

} // namespace internal

template <usize MOD = 998244353>
std::vector<typename FPSNTTFriendly<MOD>::V> MultipointEvaluation(const FPSNTTFriendly<MOD>& f,const std::vector<typename FPSNTTFriendly<MOD>::V>& xs) {
    using fps = FPSNTTFriendly<MOD>;
    using mint = fps::V;
    if (f.empty() or xs.empty())
        return std::vector(xs.size(),mint{0});
    SubproductTree prod([&]() -> std::vector<fps> {
                std::vector<fps> res(xs.size());
                for (usize i = 0 ; i < xs.size() ; i++)
                    res[i]={-xs[i],mint::raw(1)};
                return res;
            }());
    return internal::MultipointEvaluation(f,prod);
}

} // namespace zawa
