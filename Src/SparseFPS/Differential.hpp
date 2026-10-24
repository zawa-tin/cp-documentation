#pragma once

#include "../Template/TypeAlias.hpp"
#include "SparseFPS.hpp"

#include <cassert>

namespace zawa {

namespace SparseFPS {

template <std::integral Degree,class Coef>
Series<Degree,Coef> Differential(const Series<Degree,Coef>& f) {
    Series<Degree,Coef> res;
    res.reserve(f.size());
    for (const auto& term : f)
        if (term.degree!=Degree{0})
            res.emplace_back(term.degree-1,term.coef*term.degree);
    return res;
}

} // namespace SparseFPS

} // namespace zawa
