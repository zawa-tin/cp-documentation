#pragma once

#include "../PointCloud.hpp"
#include "./PointAndPoint.hpp"

#include <algorithm>
#include <cassert>
#include <concepts>
#include <ranges>
#include <utility>
#include <vector>

namespace zawa {

namespace geometryZ2 {

template <std::integral T = usize>
std::pair<T, T> ClosestPairOfPoints(PointCloud P) {
    assert(std::ssize(P) >= 2);
    std::vector<std::pair<Point, T>> ps(P.size());
    for (usize i = 0 ; i < P.size() ; i++) {
        ps[i].first = std::move(P[i]);
        ps[i].second = i;
    }
    std::ranges::sort(ps);
    usize mini = ps[0].second, minj = ps[1].second;
    Zahlen mind = DistanceSquare(ps[0].first, ps[1].first);
    auto rec = [&](auto rec, usize l, usize r) -> void {
        if (r - l <= 1) return;
        const usize m = (l + r) >> 1;
        const Zahlen midx = ps[m].first.x();
        rec(rec, l, m);
        rec(rec, m, r);
        std::inplace_merge(ps.begin() + l, ps.begin() + m, ps.begin() + r,
                [](const auto& i, const auto& j) { return i.first.y() < j.first.y(); });
        std::vector<usize> near;
        near.reserve(r - l);
        for (usize i = l ; i < r ; i++) {
            const Zahlen ix = ps[i].first.x(), iy = ps[i].first.y();
            const T idx = ps[i].second;
            if (Square(ix - midx) > mind) continue;
            for (usize j : near | std::views::reverse) {
                const Zahlen jx = ps[j].first.x(), jy = ps[j].first.y();
                const T jdx = ps[j].second;
                if (Square(iy - jy) >= mind) break;
                if (Square(ix - jx) + Square(iy - jy) < mind) {
                    mini = idx;
                    minj = jdx;
                    mind = Square(ix - jx) + Square(iy - jy);
                }
            }
            near.push_back(i);
        }
    };
    rec(rec, 0, ps.size());
    return {mini, minj};
}

} // namespace geometryZ2

} // namespace zawa
