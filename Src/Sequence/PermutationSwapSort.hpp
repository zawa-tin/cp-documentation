#pragma once

#include <cassert>
#include <concepts>
#include <iterator>
#include <utility>
#include <vector>

#include "../Template/TypeAlias.hpp"

namespace zawa {

namespace internal {

// Is A permutation of (0,1,...,|A|-1) ?
template <std::integral T>
bool IsPermutation(const std::vector<T>& A) {
    std::vector<bool> app(A.size());
    for (T v : A) {
        if (v < 0 or v >= (T)A.size()) return false;
        if (app[v]) return false;
        app[v] = true;
    }
    return true;
}

} // namespace internal

template <std::input_iterator It>
std::vector<std::pair<usize, usize>> PermutationSwapSort(It first, It last) {
    std::vector P(first, last);
    assert(internal::IsPermutation(P));
    std::vector<std::pair<usize, usize>> res;
    for (usize i = 0 ; i < P.size() ; i++) while ((usize)P[i] != i) {
        res.push_back({i, P[i]});
        std::swap(P[i], P[P[i]]);
    }
    return res;
}

} // namespace zawa
