#pragma once

#include "./PointCloud.hpp"
#include "./Polygon.hpp"
#include "./Zahlen.hpp"
#include "./Relation.hpp"

#include <algorithm>
#include <cassert>
#include <iterator>
#include <type_traits>
#include <vector>

namespace zawa {

namespace geometryZ2 {

template <bool strictly>
Polygon ConvexHull(const PointCloud& p) {
    PointCloud cp{p};
    std::sort(cp.begin(), cp.end());
    cp.erase(std::unique(cp.begin(), cp.end()), cp.end());
    if (cp.size() <= 2u) {
        return Polygon{cp};
    }
    PointCloud lower;
    lower.reserve(p.size());
    for (auto it{cp.begin()} ; it != cp.end() ; it++) {
        lower.push_back(*it);
        while (lower.size() >= 3u) {
            if (Relation(lower[lower.size() - 3], lower[lower.size() - 2], lower[lower.size() - 1]) == COUNTER_CLOCKWISE) {
                break;
            }
            if constexpr (!strictly) {
                if (Relation(lower[lower.size() - 3], lower[lower.size() - 2], lower[lower.size() - 1]) == ONLINE_FRONT) {
                    break;
                }
            }
            std::swap(lower[lower.size() - 2], lower[lower.size() - 1]);
            lower.pop_back();
        }
    }
    PointCloud upper;
    upper.reserve(p.size());
    for (auto it{cp.rbegin()} ; it != cp.rend() ; it++) {
        upper.push_back(*it);
        while (upper.size() >= 3u) {
            if (Relation(upper[upper.size() - 3], upper[upper.size() - 2], upper[upper.size() - 1]) == COUNTER_CLOCKWISE) {
                break;
            }
            if constexpr (!strictly) {
                if (Relation(upper[upper.size() - 3], upper[upper.size() - 2], upper[upper.size() - 1]) == ONLINE_FRONT) {
                    break;
                }
            }
            std::swap(upper[upper.size() - 2], upper[upper.size() - 1]);
            upper.pop_back();
        }
    }

    Polygon res;
    res.reserve(lower.size() + upper.size() - 2);
    res.insert(res.size(), lower.begin(), lower.end());
    res.insert(res.size(), std::next(upper.begin()), std::prev(upper.end()));
    return res;
}

} // namespace geometryZ2

} // namespace zawa
