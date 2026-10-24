#pragma once

#include "../Template/TypeAlias.hpp"
#include "SparseFPS.hpp"

#include <cassert>
#include <utility>

namespace zawa {

namespace SparseFPS {

template <std::integral Degree,class Coef>
std::vector<Coef> Div(const Series<Degree,Coef>& f,const Series<Degree,Coef>& g,usize n) {
    assert(g.size());
    assert(g[0].degree==0);
    std::vector<Coef> res(n);
    if (!n)
        return res;
    const Coef inv=Coef{1}/g[0].coef;
    usize idx=0,jdx=0;
    for (usize i = 0 ; i < n ; i++) {
        Coef val=0;
        if (idx < f.size() and std::cmp_equal(f[idx].degree,i)) 
            val=f[idx++].coef;
        while (jdx < g.size() and std::cmp_less_equal(g[jdx].degree,i))
            jdx++;
        for (usize j = 1 ; j < jdx ; j++)
            val-=g[j].coef*res[i-g[j].degree];
        res[i]=val*inv;
    }
    return res;
}

} // namespace SparseFPS

} // namespace zawa
