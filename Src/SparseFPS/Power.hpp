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
std::vector<Coef> Pow(Series<Degree,Coef> f,usize m,usize n) {
    std::erase_if(f,[](const auto& t) -> bool { return t.coef==Coef{0}; });
    std::vector<Coef> res(n);
    if (!n)
        return {};
    if (f.empty() or !m) {
        res[0]=m==0;
        return res;
    }
    const auto [a,c] = f[0];
    if (std::cmp_greater(a,(n-1)/m))
        return res;
    const Coef invc=Coef{1}/c;
    const Coef powc=[&](){
        Coef res=1,cur=c;
        for (usize exp = m ; exp ; exp>>=1) {
            if (exp & 1)
                res*=cur;
            cur*=cur;
        }
        return res;
    }();
    for (auto& t : f) {
        t.degree-=a;
        t.coef*=invc;
    }
    auto df=Differential(f);
    std::vector<Coef> F(n),DF(n-1);
    usize idx=0,jdx=0;
    F[0]=Coef{1};
    res[m*a]=powc;
    for (usize i = 1 ; i < n-m*a ; i++) {
        // equation of [x^{i-1}]
        while (idx < f.size() and std::cmp_less(f[idx].degree,i))
            idx++;
        while (jdx < df.size() and std::cmp_less(df[jdx].degree,i))
            jdx++;
        Coef left=0,right=0;
        for (usize j = 0 ; j < idx ; j++)
            left+=f[j].coef*DF[i-1-f[j].degree];
        for (usize j = 0 ; j < jdx ; j++)
            right+=df[j].coef*F[i-1-df[j].degree];
        right*=Coef{m};
        DF[i-1]=right-left;
        F[i]=DF[i-1]/Coef{i}; 
        res[i+m*a]=F[i]*powc;
    }
    return res;
}

} // namespace SparseFPS

} // namespace zawa
