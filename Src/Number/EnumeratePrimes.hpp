#pragma once

#include "../Template/TypeAlias.hpp"

#include <concepts>
#include <vector>
#include <bit>

namespace zawa {

template <std::integral T>
std::vector<T> EnumeratePrimes(usize N) {
    static constexpr u32 p[]{2,3,5,7,11,13,17,19,23,29,31};
    u32 w = 1;
    usize m = 0;
    for ( ; m < std::size(p) and static_cast<u64>(w) * w < N ; w *= p[m++]) ;
    std::vector<u32> R = [&]() {
        std::vector<bool> siv(w, true);
        for (usize i = 0 ; i < m ; i++) {
            for (u32 j = p[i] ; j < w ; j += p[i]) siv[j] = false;
        }
        std::vector<u32> res{1};
        for (u32 i = 2 ; i < w ; i++) if (siv[i]) res.push_back(i);
        return res;
    }();
    std::vector<T> res;
    res.reserve(N / (std::bit_width(N) + 1));
    std::vector<u32> S;
    S.reserve(N / 5u);
    for (u32 kw = 0 ; kw <= N ; kw += w) {
        for (u32 r = 0 ; r < R.size() and kw + R[r] <= N ; r++) {
            S.push_back(kw + R[r]);
        }
    }
    for (usize i = 0 ; i < m ; i++) res.push_back(static_cast<T>(p[i]));
    std::vector<bool> siv(N + 1, true);
    for (usize i = 1 ; i < S.size() ; i++) if (siv[S[i]]) {
        res.push_back(static_cast<T>(S[i])); 
        for (u32 j = i ; j < S.size() ; j++) {
            u64 p = static_cast<u64>(S[i]) * S[j];
            if (p > N) break;
            siv[p] = false;
        }
    }
    return res;
}

} // namespace zawa
