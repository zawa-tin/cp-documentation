#pragma once

#include "../Template/TypeAlias.hpp"
#include "SparseFPS.hpp"

#include <cassert>
#include <utility>

namespace zawa {

namespace SparseFPS {

template <std::integral Degree,class Coef>
std::vector<Coef> Inv(const Series<Degree,Coef>& f,usize n) {
    assert(f.size() and f[0].degree==0 and f[0].coef!=Coef{0});
    std::vector<Coef> res(n);
    if (!n)
        return res;
    res[0]=Coef{1}/f[0].coef;
    usize idx=0;
    for (usize i = 1 ; i < n ; i++) {
        while (idx < f.size() and std::cmp_less_equal(f[idx].degree,i))
            idx++;
        Coef val=0;
        for (usize j = 1 ; j < idx ; j++)
            val+=f[j].coef*res[i-f[j].degree];
        res[i]=-val*res[0];
    }
    return res;
}

} // namespace SparseFPS

} // namespace zawa
