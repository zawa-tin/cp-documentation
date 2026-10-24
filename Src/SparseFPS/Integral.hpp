#pragma once

#include "../Template/TypeAlias.hpp"
#include "SparseFPS.hpp"

#include <cassert>
#include <utility>

namespace zawa {

namespace SparseFPS {

template <std::integral Degree,class Coef>
Series<Degree,Coef> Integral(const Series<Degree,Coef>& f) {
    Series<Degree,Coef> res(f.size());
    for (usize i = 0 ; i < f.size() ; i++) 
        res[i]={f[i].degree+1,f[i].coef/(f[i].degree+1)};
    return res;
}

} // namespace SparseFPS

} // namespace zawa
