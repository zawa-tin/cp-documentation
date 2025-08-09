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
        auto gg = atcoder::convolution(g, g);
        std::vector<T> f(g.size() << 1);
        for (usize i = 0 ; i < std::min(f.size(), F.size()) ; i++) f[i] = F[i];
        auto fgg = atcoder::convolution(f, gg);
        fgg.resize(g.size() << 1);
        g.resize(g.size() << 1);
        for (usize i = 0 ; i < ssize(g) ; i++) g[i] = T::raw(2) * p[i] - fgg[i];
    }
    g.resize(n);
    return g;
}

} // namespace zawa
