#pragma once

#include "../PointCloud.hpp"
#include "../ConvexHull.hpp"
#include "../Distance/PointAndPoint.hpp"

#include <cassert>

namespace zawa {

namespace geometryZ2 {

template <class T = usize>
std::pair<T, T> FurthestPairOfPoints(const PointCloud& P) {
    assert(std::ssize(P) >= 2);
    const auto ch = ConvexHull<true>(P);
    if (std::ssize(ch) == 1) { // 全部の点が同じ所にある -> 何でも良い
        return {T{0}, T{1}};
    }
    usize mini = 0, minj = 1;
    Zahlen mind = DistanceSquare(ch[mini], ch[minj]);
    if (std::ssize(ch) > 2) {
        usize idx = 0, jdx = 0;
        for (usize i = 1 ; i < ch.size() ; i++) {
            if (ch[idx].x() > ch[i].x()) idx = i;
            if (ch[jdx].x() < ch[i].x()) jdx = i;
        }
        const usize sidx = idx, sjdx = jdx;
        while (idx != sjdx or jdx != sidx) {
            if (mind < DistanceSquare(ch[idx], ch[jdx])) {
                mind = DistanceSquare(ch[idx], ch[jdx]);
                mini = idx;
                minj = jdx;
            }
            if (Cross(ch[idx+1==ch.size()?0:idx+1] - ch[idx], ch[jdx+1==ch.size()?0:jdx+1] - ch[jdx]) < 0) {
                idx = idx+1==ch.size()?0:idx+1;
            }
            else {
                jdx = jdx+1==ch.size()?0:jdx+1;
            }
        }
    }
    const T n = static_cast<T>(P.size());
    T i = n, j = n;
    for (usize k = 0 ; k < P.size() ; k++) {
        if (i == n and P[k] == ch[mini]) i = k;
        if (j == n and P[k] == ch[minj]) j = k;
    }
    return {i, j};
}

} // namespace geometryZ2

} // namespace zawa
