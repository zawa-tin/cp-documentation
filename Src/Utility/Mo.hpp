#pragma once

#include "../Template/TypeAlias.hpp"

#include <algorithm>
#include <cmath>
#include <ranges>
#include <utility>
#include <numeric>
#include <limits>
#include <vector>

namespace zawa {

template <class T>
std::vector<usize> Mo(const std::vector<std::pair<T,T>>& P) {
    if (P.empty())
        return {};
    T minY = std::numeric_limits<T>::max();
    const u64 W = [&]() {
        T minX = std::numeric_limits<T>::max();
        T maxX = std::numeric_limits<T>::min(), maxY = std::numeric_limits<T>::min();
        for (auto [x,y] : P) {
            minX = std::min(minX,x);
            maxX = std::max(maxX,x);
            minY = std::min(minY,y);
            maxY = std::max(maxY,y);
        }
        return std::max<u64>({1,u64(maxX-minX),u64(maxY-minY)});
    }();
    const usize B = [&]() {
        u64 sq = std::max<u64>(1,sqrt(P.size()));
        return (W + sq - 1) / sq;
    }();
    std::vector<usize> ord1(P.size()), ord2(P.size());
    std::iota(ord1.begin(),ord1.end(),0);
    std::iota(ord2.begin(),ord2.end(),0);
    T sub = minY;
    auto comp = [&](usize i, usize j) {
                auto [xi,yi] = P[i];
                auto [xj,yj] = P[j];
                yi -= sub;
                yj -= sub;
                if (yi/B != yj/B)
                    return yi/B < yj/B;
                else if ((yi/B)&1)
                    return xi>xj;
                else
                    return xi<xj;
    };
    std::ranges::sort(ord1,comp);
    sub -= B / 2;
    std::ranges::sort(ord2,comp);
    auto cost = [&](const std::vector<usize>& ord) {
        u64 res = 0;
        for (usize i = 0 ; i + 1 < ord.size() ; i++) {
            res += abs(P[ord[i+1]].first-P[ord[i]].first);
            res += abs(P[ord[i+1]].second-P[ord[i]].second);
        }
        return res;
    };
    return cost(ord1) <= cost(ord2) ? ord1 : ord2;
}

} // namespace zawa
