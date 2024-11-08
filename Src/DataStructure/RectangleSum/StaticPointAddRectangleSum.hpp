#pragma once

#include "./RSType.hpp"

#include <algorithm>
#include <utility>
#include <vector>
#include <type_traits>

namespace zawa {

// P...座標の型
// W...重みの型
template <class P, class W>
std::vector<W> StaticPointAddRectangleSum(std::vector<RSPoint<P, W>> ps, std::vector<RSQuery<P>> qs) {
    static_assert(std::is_integral_v<W>, "W must be signed");
    usize n{ps.size()}, q{qs.size()};
    std::vector<P> xs(n);
    for (usize i{} ; i < n ; i++) xs[i] = ps[i].x;
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    std::sort(ps.begin(), ps.end(), [&](const auto& L, const auto& R) -> bool {
            return L.y < R.y;
            });
    using Q = std::pair<P, usize>;
    std::vector<Q> query(2 * qs.size());
    for (usize i{} ; i < qs.size() ; i++) {
        qs[i].l = (P)std::distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(), qs[i].l));
        qs[i].r = (P)std::distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(), qs[i].r));
        query[i] = std::pair{qs[i].d, i};
        query[i + q] = std::pair{qs[i].u, i + q};
    }
    std::sort(query.begin(), query.end());
    std::vector<W> fen(xs.size() + 1), res(qs.size());
    auto pref{[&](i32 r) -> W {
        W sum{};
        for ( ; r ; r -= r & -r) sum += fen[r];
        return sum;
    }};
    for (usize i{}, j{} ; i < query.size() ; i++) {
        while (j < n and ps[j].y < query[i].first) {
            i32 x{(i32)std::distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(), ps[j].x))}; 
            for ( x++ ; (usize)x < fen.size() ; x += x & -x) fen[x] += ps[j].w;
            j++;
        }
        usize idx{query[i].second};
        if (idx < q) {
            res[idx] += pref(qs[idx].l) - pref(qs[idx].r);
        }
        else {
            idx -= q;
            res[idx] += -pref(qs[idx].l) + pref(qs[idx].r);
        }
    } 
    return res;
}

} // namespace zawa
