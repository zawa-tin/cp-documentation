#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Utility/BinarySearch.hpp"
#include "../Zahlen.hpp"
#include "../Point.hpp"
#include "../Polygon.hpp"
#include "./State.hpp"

#include <cassert>

namespace zawa {

namespace geometryZ2 {

// note: 凸多角形であることを確認してください。
// note: normal formにしておいてください
ContainState ConvexPolygonContainsPoint(const Polygon& S, const Point& p) {
    const usize n = S.size();
    assert(n >= 3);
    if (RELATION state = Relation(S[0],p,S[1]) ; state != CLOCKWISE)
        return p == S[0] or p == S[1] or state == ONLINE_FRONT ? ONLINE : OUTSIDE;
    if (RELATION state = Relation(S[0],p,S[n-1]); state != COUNTER_CLOCKWISE)
        return p == S[n-1] or state == ONLINE_FRONT ? ONLINE : OUTSIDE;
    const usize i = BinarySearch<usize>(1,n-1,[&](usize x) { return Cross(S[x]-S[0],p-S[0]) >= 0; });
    RELATION state = Relation(S[i],S[i+1],p);
    if (state == COUNTER_CLOCKWISE)
        return INSIDE;
    else if (S[i] == p or S[i+1] == p or state == ON_SEGMENT)
        return ONLINE;
    else
        return OUTSIDE;
}

} // namespace geometryZ2

} // namespace zawa
