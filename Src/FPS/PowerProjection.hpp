#pragma once

#include "FPS.hpp"

#include <algorithm>
#include <cassert>
#include <bit>
#include <vector>
#include <ranges>

namespace zawa {

// i = 0, 1, 2, \dots, M - 1
// res[i] = \sum_{j} W([x^j]F(x)^i)
template <concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
std::vector<typename FPS::value_type> PowerProjection(usize m, FPS W, FPS F, Conv convolution = {}) {
    using Element = typename FPS::value_type;
    assert(W.size());
    if (!m)
        return {};
    F.resize(W.size());
    if (F[0] != Element{0}) {
        std::vector<Element> fact(m, 1), invFact(m);
        for (usize i = 1 ; i < m ; i++)
            fact[i] = fact[i - 1] * Element{i};
        invFact[m - 1] = Element{1} / fact[m - 1];
        for (usize i = m ; --i ; )
            invFact[i - 1] = invFact[i] * Element{i};
        const Element c = F[0];
        F[0] = 0;
        FPS cur{PowerProjection(m, W, F, convolution)};
        FPS op(m);
        Element pw = 1;
        for (usize i = 0 ; i < m ; i++, pw *= c) {
            op[i] = pw * invFact[i];
            cur[i] *= invFact[i];
        }
        auto res = convolution(cur, op);
        res.resize(m);
        for (usize i = 0 ; i < m ; i++)
            res[i] *= fact[i];
        return res;
    }
    usize n = std::bit_ceil(W.size()), nx = n * 2, ny = 2;
    W.resize(n);
    F.resize(n);
    std::ranges::reverse(W);
    // bostan mori [x^{n-1}](g(x)/(1-yf(x)))
    FPS P(nx * ny), Q(nx * ny);
    Q[0] = 1;
    for (usize x = 0 ; x < n ; x++) {
        P[x] = W[x];
        Q[nx + x] = -F[x];
    }
    while (n > 1) {
        FPS R(nx * ny);
        for (usize x = 0 ; x < nx ; x++)
            for (usize y = 0 ; y < ny ; y++)
                R[y * nx + x] = Q[y * nx + x] * Element{x % 2 ? -1 : 1};
        auto PR = convolution(P, R), QR = convolution(Q, R);
        PR.emplace_back();
        QR.emplace_back();
        std::ranges::fill(P, Element{0});
        std::ranges::fill(Q, Element{0});
        for (usize x = 1 ; x < (nx >> 1) ; x += 2)
            for (usize y = 0 ; y < (2 * ny) ; y++)
                P[y * (nx >> 1) + (x >> 1)] = PR.at(y * nx + x);
        for (usize x = 0 ; x < (nx >> 1) ; x += 2)
            for (usize y = 0 ; y < (2 * ny) ; y++) 
                Q[y * (nx >> 1) + (x >> 1)] = QR[y * nx + x];
        nx >>= 1;
        n >>= 1;
        ny <<= 1;
    }
    P.resize(2 * m);
    for (usize i = 0 ; i < m ; i++)
        P[i] = P[i << 1];
    P.resize(m);
    return P;
}

} // namespace zawa
