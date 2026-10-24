#pragma once

#include "../Template/TypeAlias.hpp"
#include "SparseFPS.hpp"
#include "Differential.hpp"
#include "Integral.hpp"
#include "Divide.hpp"

#include <cassert>

namespace zawa {

namespace SparseFPS {

template <std::integral Degree,class Coef>
std::vector<Coef> Log(const Series<Degree,Coef>& f,usize n) {
    assert(f.size() and f[0].degree==0 and f[0].coef==Coef{1});
    std::vector<Coef> res(n);
    if (!n)
        return res;
    auto dif=Div(Differential(f),f,n-1);
    for (usize i = 0 ; i + 1 < n ; i++)
        res[i+1]=dif[i]/Coef{i+1};
    return res;
}

} // namespace SparseFPS

} // namespace zawa
