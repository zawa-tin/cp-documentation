#pragma once

#include <concepts>
#include <vector>

namespace zawa {

namespace SparseFPS {

template <std::integral Degree,class Coef>
struct Term {
    Degree degree;
    Coef coef;
};

template <std::integral Degree,class Coef>
using Series = std::vector<Term<Degree,Coef>>;

} // namespace SparseFPS

} // namespace zawa
