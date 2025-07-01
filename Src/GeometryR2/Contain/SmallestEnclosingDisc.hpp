#pragma once

#include "../Circle.hpp"
#include "../PointCloud.hpp"
#include "../CircumscribedCircle.hpp"
#include "./CircleContainsPoint.hpp"

#include <algorithm>
#include <cassert>
#include <ranges>
#include <random>

namespace zawa {

namespace geometryR2 {

namespace internal {

Circle SmallestEnclosingDisc(PointCloud&& P, usize seed = 42) {
    assert(P.size());
    if (std::ssize(P) == 1) return Circle{P[0], 0};
    std::mt19937 mt{seed};
    std::ranges::shuffle(P, mt);
    auto disc_with_two_point = [&](usize n, const Point& q1, const Point& q2) -> Circle {
        Circle res{q1, q2}; 
        for (usize i = 0 ; i < n ; i++) if (CircleContainsPoint(res, P[i]) == ContainState::OUTSIDE) {
            res = CircumscribedCircle(P[i], q1, q2).value();
        }
        return res;
    };
    auto disc_with_point = [&](usize n, const Point& q) -> Circle {
        Circle res{P[0], q};
        for (usize i = 1 ; i < n ; i++) if (CircleContainsPoint(res, P[i]) == ContainState::OUTSIDE) {
            res = disc_with_two_point(i, q, P[i]);
        }
        return res;
    };
    Circle res{P[0], P[1]};
    for (usize i = 2 ; i < P.size() ; i++) if (CircleContainsPoint(res, P[i]) == ContainState::OUTSIDE) {
        res = disc_with_point(i, P[i]);
    }
    return res;
}

} // namespace internal

Circle SmallestEnclosingDisc(PointCloud P) {
    return internal::SmallestEnclosingDisc(std::move(P), std::random_device{}());
}

Circle SmallestEnclosingDisc(PointCloud P, usize seed) {
    return internal::SmallestEnclosingDisc(std::move(P), seed);
}

} // namespace geometryR2

} // namespace zawa
