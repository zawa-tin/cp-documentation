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
    std::vector<mint> W = [&]() { // den
        std::vector<FPS> ps(n);
        for (usize i = 0 ; i < n ; i++)
            ps[i]={-xs[i],mint::raw(1)};
        auto poly=PolynomialProducts(ps).differential();
        return MultipointEvaluation(std::move(poly),xs); 
    }();
    auto rec=[&](auto rec,usize l,usize r)->std::pair<FPS,FPS> {
        if (l==r)
            return std::pair{FPS{1},FPS{1}};
        if (l+1==r) 
            return std::pair{
                FPS{ys[l]/W[l]},
                FPS{-xs[l],mint::raw(1)}
            };
        usize m=(l+r)/2;
        auto [lhs1,lhs2]=rec(rec,l,m);
        auto [rhs1,rhs2]=rec(rec,m,r);
        auto res1=lhs1*rhs2+lhs2*rhs1;
        auto res2=lhs2*rhs2;
        return {std::move(res1),std::move(res2)};
    };
    return rec(rec,0,n).first;
}

} // namespace zawa
