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
    auto print = [&](std::string name, const FPS& f, usize nx, usize ny) {
        std::cout << name << " | ";
        for (usize y = 0 ; y < ny ; y++)
            for (usize x = 0 ; x < nx ; x++) {
                if (f[y * nx + x] == Element{})
                    continue;
                std::cout << f.at(y * nx + x).val();
                if (x) {
                    std::cout << "x" << (x == 1 ? "" : "^" + std::to_string(x));
                }
                if (y) {
                    std::cout << "y" << (y == 1 ? "" : "^" + std::to_string(y));
                }
                std::cout << " + ";
            }
        std::cout << std::endl;
    };
    usize n = std::bit_ceil(W.size());
    W.resize(n);
    F.resize(n);
    usize nx = n, ny = 2;
    std::ranges::reverse(W);
    // bostan mori [x^{n-1}](g(x)/(1-yf(x)))
    FPS P(2 * nx * ny), Q(2 * nx * ny);
    for (usize x = 0 ; x < n ; x++) {
        P[x] = W[x];
        Q[x] = -F[x];
    }
    Q[2 * nx] = 1;
    while (n > 1) {
        std::cout << nx << ' ' << ny << "iterate" << std::endl;
        FPS R = Q;
        for (usize x = 1 ; x < nx ; x += 2)
            for (usize y = 0 ; y < ny ; y++)
                R[y * nx + x] *= Element{-1};
        // print("P", P, nx << 1, ny);
        // print("Q", Q, nx << 1, ny);
        // print("R", R, nx << 1, ny);
        auto PR = convolution(P, R), QR = convolution(Q, R);
        PR.resize(4 * nx * ny);
        QR.resize(4 * nx * ny);
        // print("PR", PR, nx << 1, ny << 1);
        // print("QR", QR, nx << 1, ny << 1);
        std::ranges::fill(P, Element{0});
        std::ranges::fill(Q, Element{0});
        for (usize x = 1 ; x < nx ; x += 2)
            for (usize y = 0 ; y < (ny << 1) ; y++)
                P[y * nx + (x >> 1)] = PR[y * (nx << 1) + x];
        for (usize x = 0 ; x < nx ; x += 2)
            for (usize y = 0 ; y < (ny << 1) ; y++) 
                Q[y * nx + (x >> 1)] = QR[y * (nx << 1) + x];
        nx >>= 1;
        n >>= 1;
        ny <<= 1;
    }
    // std::cout << "result P(x, y) = " << P << std::endl;
    // print("P", P, 2, ny);
    std::vector<Element> res(ny >> 1);
    for (usize i = 0 ; i < (ny >> 1) ; i++)
        res[i] = P[i << 1];
    std::ranges::reverse(res);
    res.resize(m);
    return res;
}

} // namespace zawa
