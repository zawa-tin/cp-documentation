#pragma once

#include <cassert>
#include <concepts>
#include <utility>

namespace zawa {

template <class F, std::integral T>
requires std::predicate<F, T, T>
std::pair<std::pair<T, T>, std::pair<T, T>> RationalBinarySearch(F f, T n) {
    assert(f(0, 1) and !f(1, 0));
    auto dfs = [&](auto dfs, bool cur, T& p, T& q, T pp, T pq) -> void {
        if (p + pp > n or q + pq > n) return;
        if (f(p + pp, q + pq) == cur) {
            p += pp;
            q += pq;
            dfs(dfs, cur, p, q, pp << 1, pq << 1);
        }
        if (p + pp <= n and q + pq <= n and f(p + pp, q + pq) == cur) {
            p += pp;
            q += pq;
        }
    };
    T pl = 0, ql = 1, pr = 1, qr = 0;
    while (pl + pr <= n and ql + qr <= n) {
        dfs(dfs, true, pl, ql, pr, qr);
        dfs(dfs, false, pr, qr, pl, ql);
    }
    return std::pair{std::pair{pl, ql}, std::pair{pr, qr}};
}

} // namespace zawa
