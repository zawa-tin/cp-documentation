#pragma once

#include "./Polygon.hpp"

#include <algorithm>
#include <utility>
#include <vector>

namespace zawa {

namespace geometryZ2 {

Polygon operator+(const Polygon& P,const Polygon& Q) {
    if (P.empty() or Q.empty())
        return Polygon{};
    const usize N = P.size(),M = Q.size();
    std::vector<std::pair<Point,Point>> p(N),q(M),ord(N+M);
    for (usize i = 0 ; i < N ; i++)
        p[i] = std::pair{P[i],P[(i+1)%N]};
    for (usize i = 0 ; i < M ; i++)
        q[i] = std::pair{Q[i],Q[(i+1)%M]};
    auto comp = [&](const auto& i,const auto& j) -> bool {
        return Point::ArgComp(i.second-i.first,j.second-j.first);
    };
    std::ranges::rotate(p,std::ranges::min_element(p,comp));
    std::ranges::rotate(q,std::ranges::min_element(q,comp));
    std::ranges::merge(p,q,ord.begin(),comp);
    auto straight = [&](const Point& p,const Point& q,const Point& r) -> bool {
        return q == r or Relation(p,q,r) == ONLINE_FRONT;
    };
    Polygon res;
    res.reserve(N+M);
    res.pushBack(p[0].first+q[0].first);
    for (const auto& [a,b] : ord) {
        Vector cur = res[res.size()-1]+b-a;
        while (res.size() >= 2 and straight(res[res.size()-2],res[res.size()-1],cur))
            res.popBack();
        res.pushBack(cur);
    }
    if (res.size() >= 2 and res[0] == res[res.size()-1])
        res.popBack();
    return res;
}

} // namespace geometryZ2

} // namespace zawa
