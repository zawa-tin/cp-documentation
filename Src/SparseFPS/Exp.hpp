#pragma once

#include "../Template/TypeAlias.hpp"
#include "SparseFPS.hpp"
#include "Differential.hpp"

#include <cassert>
#include <utility>

namespace zawa {

namespace SparseFPS {

template <std::integral Degree,class Coef>
std::vector<Coef> Exp(const Series<Degree,Coef>& f,usize n) {
    std::vector<Coef> res(n);
    if (f.empty()) {
        if (n)
            res[0]=1;
        return res;
    }
    assert(f[0].degree!=0 or f[0].coef==0);
    if (!n)
        return res;
    auto diff=Differential(f);
    res[0]=1;
    usize idx=0;
    for (usize i = 1 ; i < n ; i++) {
        while (idx < diff.size() and std::cmp_less(diff[idx].degree,i))
            idx++;
        Coef val=0;
        for (usize j = 0 ; j < idx ; j++)
            val+=diff[j].coef*res[i-1-diff[j].degree];
        res[i]=val/Coef{i};
    }
    return res;
}

} // namespace SparseFPS

} // namespace zawa
