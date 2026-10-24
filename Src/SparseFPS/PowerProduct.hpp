#pragma once

#include "../Template/TypeAlias.hpp"
#include "SparseFPS.hpp"
#include "Differential.hpp"

#include <algorithm>
#include <cassert>
#include <utility>

namespace zawa {

namespace SparseFPS {

template <std::integral Degree,class Coef>
std::vector<Coef> PowProduct(Series<Degree,Coef> f,Series<Degree,Coef> g,i64 n,i64 m,usize N) {
    if (N==0)
        return {};
    std::erase_if(f,[](const auto& t) -> bool { return t.coef==Coef{0}; });
    std::erase_if(g,[](const auto& t) -> bool { return t.coef==Coef{0}; });
    if (n==0)
        f=Series<Degree,Coef>{{Degree{0},Coef{1}}};
    if (m==0)
        g=Series<Degree,Coef>{{Degree{0},Coef{1}}};
    assert(f.size() or n >= 0);
    assert(g.size() or m >= 0);
    if (f.empty() and n > 0)
        return std::vector<Coef>(N,Coef{0});
    if (g.empty() and m > 0)
        return std::vector<Coef>(N,Coef{0});
    auto power=[](Coef x,i64 exp) -> Coef {
        Coef res=1;
        u64 e=exp<0?static_cast<u64>(-(exp+1))+1:static_cast<u64>(exp);
        Coef val=exp<0?(Coef{1}/x):x;
        for (u64 cur = e ; cur ; cur >>= 1) {
            if (cur & 1)
                res*=val;
            val*=val;
        }
        return res;
    };
    auto normalize=[power](Series<Degree,Coef>& f,i64 n) -> std::pair<Degree,Coef> {
        auto [s,c]=f[0];
        Coef invc=Coef{1}/c;
        for  (auto& t : f) {
            t.degree-=s;
            t.coef*=invc;
        }
        return {s,power(c,n)};
    };
    auto [a1,b1]=normalize(f,n);
    auto [a2,b2]=normalize(g,m);
    const i128 p=static_cast<i128>(a1)*n;
    const i128 q=static_cast<i128>(a2)*m;
    // p+q<0なら、負冪を許さないと定義できないので、assert落ち
    assert(p >= 0 ? q >= -p : (q >= 0 and p >= -q));
    if ([&]() {
            const i128 len=static_cast<i128>(N);
            return p >= 0 ? q >= len-p : (q >= 0 and p >= len-q);
            }())
    return std::vector<Coef>(N,Coef{0});
    const usize shift=static_cast<usize>(p+q);
    std::vector<Coef> res(N),P(N),Q(N);
    P[0]=Q[0]=Coef{1};
    res[shift]=b1*b2;
    auto df=Differential(f),dg=Differential(g);
    usize idx_df=0,idx_dg=0,idx_f=0,idx_g=0;
    for (usize i = 1 ; i + shift < N ; i++) {
        const auto h=[&]{// [x^{i-1}] equation of dH=n(df)P+m(dg)Q 
            while (idx_df<df.size() and std::cmp_less(df[idx_df].degree,i))
                idx_df++;
            while (idx_dg<dg.size() and std::cmp_less(dg[idx_dg].degree,i))
                idx_dg++;
            Coef val=0;
            for (usize j = 0 ; j < idx_df ; j++)
                val+=Coef{n}*df[j].coef*P[i-1-df[j].degree];
            for (usize j = 0 ; j < idx_dg ; j++)
                val+=Coef{m}*dg[j].coef*Q[i-1-dg[j].degree];
            return val/Coef{i};
        }();
        res[i+shift]=b1*b2*h;
        { // [x^i] equation of fP=H
            while (idx_f<f.size() and std::cmp_less_equal(f[idx_f].degree,i))
                idx_f++;
            Coef val=h;
            for (usize j = 0 ; j < idx_f ; j++)
                val-=f[j].coef*P[i-f[j].degree];
            P[i]=val;
        }
        { // [x^i] equation of gQ=H
            while (idx_g<g.size() and std::cmp_less_equal(g[idx_g].degree,i))
                idx_g++;
            Coef val=h;
            for (usize j = 0 ; j < idx_g ; j++)
                val-=g[j].coef*Q[i-g[j].degree];
            Q[i]=val;
        }
    }
    return res;
}

} // namespace SparseFPS

} // namespace zawa
