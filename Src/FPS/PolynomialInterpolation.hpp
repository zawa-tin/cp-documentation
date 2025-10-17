#pragma once

#include "../Template/TypeAlias.hpp"
#include "atcoder/internal_math.hpp"

#include <cassert>
#include <concepts>
#include <utility>
#include <vector>

namespace zawa {

template <class mint>
std::vector<mint> PolynomialInterpolation(const std::vector<mint>& xs, const std::vector<mint>& ys) {
    assert(xs.size());
    assert(xs.size() == ys.size());
    assert(atcoder::internal::is_prime_constexpr(mint::mod()));
    std::vector<mint> dp(1, 1); 
    for (mint x : xs) {
        std::vector<mint> next(dp.size() + 1);
        for (usize i = 0 ; i < dp.size() ; i++) {
            next[i + 1] += dp[i];
            next[i] += dp[i] * -x;
        }
        dp = std::move(next);
    }
    std::vector<mint> ans(xs.size());
    for (usize idx = 0 ; mint x : xs) {
        // num -> modosu dp
        std::vector<mint> num(xs.size());  
        if (x == mint{0}) {
            for (usize i = 0 ; i < num.size() ; i++)
                num[i] = dp[i + 1];
        }
        else {
            const mint ix = mint{1} / x;
            num[0] = -dp[0] * ix;
            for (usize i = 1 ; i < num.size() ; i++) 
                num[i] = (num[i - 1] - dp[i]) * ix;
        }
        // den -> nene chang!
        mint den = 1;
        for (usize i = 0 ; i < xs.size() ; i++)
            if (i != idx)
                den *= x - xs[i];
        den = mint{1} / den;
        for (usize i = 0 ; i < xs.size() ; i++)
            ans[i] += ys[idx] * num[i] * den;
        idx++;
    } 
    return ans;
}

} // namespace zawa
