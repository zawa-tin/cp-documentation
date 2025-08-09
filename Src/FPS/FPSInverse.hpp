#pragma once

#include "../Template/TypeAlias.hpp"
#include "atcoder/modint"
#include "atcoder/convolution"

#include <algorithm>
#include <concepts>
#include <vector>

namespace zawa {

template <class T = atcoder::static_modint<998244353>>
requires std::same_as<T, atcoder::static_modint<998244353>>
std::vector<T> FPSInverse(std::vector<T> F, usize n) {
    assert(F.size() and F[0] != T{0});
    std::vector<T> g{F[0].inv()};
    while (g.size() < n) {
        auto p = g;
        p.resize(g.size() << 1);
        auto fgg = [&]() {
            auto res = g;
            std::vector<T> f(g.size() << 1);
            for (usize i = 0 ; i < std::min(f.size(), F.size()) ; i++) f[i] = F[i];
            const usize m = res.size(), k = f.size(), s = (m + m - 1) + k - 1, z = atcoder::internal::bit_ceil(s);
            res.resize(z);
            f.resize(z);
            atcoder::internal::butterfly(res);
            atcoder::internal::butterfly(f);
            for (usize i = 0 ; i < z ; i++) res[i] *= res[i] * f[i];
            atcoder::internal::butterfly_inv(res);
            res.resize(s);
            const T iz = T{z}.inv();
            for (T& v : res) v *= iz;
            return res;
        }();
        // auto gg = atcoder::convolution(g, g);
        // std::vector<T> f(g.size() << 1);
        // for (usize i = 0 ; i < std::min(f.size(), F.size()) ; i++) f[i] = F[i];
        // auto fgg = atcoder::convolution(f, gg);
        fgg.resize(g.size() << 1);
        g.resize(g.size() << 1);
        for (usize i = 0 ; i < ssize(g) ; i++) g[i] = T::raw(2) * p[i] - fgg[i];
    }
    g.resize(n);
    return g;
}

} // namespace zawa
