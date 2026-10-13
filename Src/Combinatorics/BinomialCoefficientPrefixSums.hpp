#pragma once

#include "../Utility/Mo.hpp"

#include <algorithm>
#include <cassert>
#include <concepts>
#include <utility>
#include <vector>

namespace zawa {

template <class T,std::signed_integral U>
std::vector<T> BinomialCoefficientPrefixSums(std::vector<std::pair<U,U>> P) {
    U maxN = 0;
    for (auto& [n,k] : P) {
        assert(n >= 0);
        k = std::clamp(k,U{-1},n);
        maxN = std::max(maxN,n);
    }
    auto ord = Mo(P);
    std::vector<T> res(P.size(),T{0}),fac(maxN+1),ifac(maxN+1);
    fac[0] = 1;
    for (U i = 1 ; i <= maxN ; i++)
        fac[i] = fac[i-1] * T{i};
    ifac[maxN] = T{1} / fac[maxN];
    for (U i = maxN ; i >= 1 ; i--)
        ifac[i-1] = ifac[i] * T{i};
    auto comb = [&](U n,U k) -> T {
        return fac[n] * ifac[k] * ifac[n-k];
    };
    U n = 0, k = 0;
    const T inv2 = T{1} / T{2};
    T cur = T{1};
    for (auto idx : ord) {
        auto [N,K] = P[idx];
        if (K == -1)
            continue;
        while (n < N) {
            cur = T{2} * cur - comb(n,k);
            n++;
        }
        while (k < K) {
            cur += comb(n,k+1);
            k++;
        }
        while (k > K) {
            cur -= comb(n,k);
            k--;
        }
        while (n > N) {
            cur = inv2 * (cur + comb(n-1,k));
            n--;
        }
        res[idx] = cur;
    }
    return res;
}

} // namespace zawa
