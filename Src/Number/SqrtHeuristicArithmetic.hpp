#pragma once

#include "../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <concepts>
#include <ranges>
#include <tuple>
#include <vector>
#include <numeric>

namespace zawa {

// ax + b
template <std::integral T>
struct Arithmetic {
    T a, b;
    usize n;
    // original sequence f(l), f(l + gap), f(l + 2gap), ..., f(l + (n-1)gap)
    usize l, gap;
    T operator()(usize i) const {
        assert(i < n);
        return a * i + b;
    }
    usize originIndex(usize i) const {
        assert(i < n);
        return gap * i + l;
    }
};

// { B, A + B, 2A + B, 3A + B, ..., (N-1)A + B } (each values are mod M)
// require: 0 <= N < M, gcd(A, M) = 1
// reference: https://codeforces.com/blog/entry/141889
// reference: https://atcoder.jp/contests/abc429/submissions/70468550
// response: get<0> * get<1>[i](j) + get<2> = B + A * get<1>[i].origin_index(j)
// memo: if gcd(A, M) = g > 1, transform to g((A/g)x + (B/g) (mod M)) + B%g
// memo: if N >= M, reduce to gcd(A, M) = 1 and partition to {0, 1, 2, ..., M - 1} (N/M times), {B, A+B, ..., A*(N%M)+B} mod M
template <std::integral T>
std::vector<Arithmetic<T>> SqrtHeuristicArithmetic(T A, T B, usize M, usize N) {
    assert(M > usize{0});
    assert(N < M);
    A %= M;
    B %= M;
    if (N == 0)
        return {};
    if (N == 1)
        return {Arithmetic{A, B, N, 0, 0}};
    assert(std::gcd(A, M) == 1);
    // floor(sqrt(M)) + 1
    const usize n = [&]() {
        usize res = static_cast<usize>(sqrtl(M));
        while (res * res > M)
            res--;
        while (res * res <= M)
            res++;
        return res;
    }();
    assert(std::min(n, M) >= 2);
    std::vector<std::pair<T, usize>> app;
    app.reserve(std::min(n, N));
    for (usize i = 0 ; i < std::min(n, N) ; i++)
        app.emplace_back((A * i + B) % M, i);
    std::ranges::sort(app);
    T minDiff = M;
    usize idx = 0;
    for (usize i = 1 ; i < app.size() ; i++) {
        if (minDiff > std::abs(app[i].first - app[i - 1].first)) {
            minDiff = std::abs(app[i].first - app[i - 1].first);
            idx = i;
        }
    }
    const usize gap = std::max(app[idx].second, app[idx - 1].second) - std::min(app[idx].second, app[idx - 1].second);
    assert(minDiff > 0); 
    assert(gap > 0);
    std::vector<Arithmetic<T>> res;
    const T a = 
        ((A * std::max(app[idx].second, app[idx - 1].second) + B) % M)
        -
        ((A * std::min(app[idx].second, app[idx - 1].second) + B) % M);
    assert(a != 0);
    for (usize i = 0 ; i < gap ; i++)
        for (usize j = i ; j < N ; ) {
            const T stVal = (A * j + B) % M;
            const T n = std::min<usize>(
                    (N - j + gap - 1) / gap - 1, 
                    a > 0 ? ((M - stVal + a - 1) / a - 1) : stVal / (-a));
            assert(stVal + n * a < static_cast<T>(M) and stVal + n * a >= 0);
            assert(j + n * gap < N);
            res.emplace_back(a, stVal, n + 1, j, gap);
            j += gap * (n + 1);
        }
    return res;
}

} // namespace zawa
