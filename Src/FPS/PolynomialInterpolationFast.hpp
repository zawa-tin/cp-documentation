#pragma once

#include "FPSNTTFriendly.hpp"
#include "MultipointEvaluation.hpp"
#include "SubproductTree.hpp"
#include "PolynomialProducts.hpp"

#include <utility>
#include <vector>

namespace zawa {

template <usize MOD = 998244353>
FPSNTTFriendly<MOD> PolynomialInterpolationFast(const std::vector<typename FPSNTTFriendly<MOD>::V>& xs,const std::vector<typename FPSNTTFriendly<MOD>::V>& ys) {
    assert(xs.size());
    assert(xs.size() == ys.size());
    using fps=FPSNTTFriendly<MOD>;
    using mint=typename fps::V;
    const usize n=xs.size();
    std::vector<fps> leafs(n);
    for (usize i = 0 ; i < n ; i++)
        leafs[i]={-xs[i],mint::raw(1)};
    SubproductTree tree(std::move(leafs));
    std::vector<mint> W=internal::MultipointEvaluation(tree.root().differential(),tree);
    std::vector<mint> prodW(n+1,mint::raw(1));
    for (usize i = 0 ; i < n ; i++)
        prodW[i+1]=prodW[i]*W[i];
    mint inv=prodW[n].inv();
    for (usize i = n ; i >= 1 ; i--) {
        mint cur=W[i-1];
        W[i-1]=inv*prodW[i-1];
        inv*=cur;
    }
    std::vector<fps> res(tree.innerSize()<<1);
    for (usize i = 0 ; i < n ; i++)
        res[tree.innerSize()+i]=fps{ys[i]*W[i]};
    for (usize i = tree.innerSize() ; --i ; ) {
        res[i]=std::move(res[i<<1|0])*tree[i<<1|1];
        res[i]+=tree[i<<1|0]*std::move(res[i<<1|1]);
    }
    return res[1];
}

} // namespace zawa
