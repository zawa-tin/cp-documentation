#pragma once

#include "FPSNTTFriendly.hpp"
#include "MultipointEvaluation.hpp"
#include "PolynomialProducts.hpp"

#include <utility>
#include <vector>

namespace zawa {

template <usize MOD = 998244353>
FPSNTTFriendly<MOD> PolynomialInterpolationFast(const std::vector<typename FPSNTTFriendly<MOD>::V>& xs,const std::vector<typename FPSNTTFriendly<MOD>::V>& ys) {
    assert(xs.size());
    assert(xs.size() == ys.size());
    using FPS=FPSNTTFriendly<MOD>;
    using mint=typename FPS::V;
    const usize n=xs.size();
    std::vector<FPS> prodTree(4*n);
    auto rec=[&](auto rec,usize l,usize r,usize id)->const FPS&{
        if (l+1==r) 
            return prodTree[id]={-xs[l],mint::raw(1)};
        const usize m=(l+r)/2;
        return prodTree[id]=rec(rec,l,m,id<<1|0)*rec(rec,m,r,id<<1|1);
    };
    std::vector<mint> W=MultipointEvaluation(rec(rec,0,n,1).differential(),xs);
    std::vector<mint> prodW(n+1,mint::raw(1));
    for (usize i = 0 ; i < n ; i++)
        prodW[i+1]=prodW[i]*W[i];
    mint inv=prodW[n].inv();
    for (usize i = n ; i >= 1 ; i--) {
        mint cur=W[i-1];
        W[i-1]=inv*prodW[i-1];
        inv*=cur;
    }
    auto rec2=[&](auto rec,usize l,usize r,usize id)->FPS {
        if (l+1==r) 
            return FPS{ys[l]*W[l]};
        usize m=(l+r)/2;
        auto lhs=rec(rec,l,m,id<<1|0);
        auto rhs=rec(rec,m,r,id<<1|1);
        auto res=lhs*prodTree[id<<1|1];
        res+=prodTree[id<<1|0]*rhs;
        return res;
    };
    return rec2(rec2,0,n,1);
}

} // namespace zawa
