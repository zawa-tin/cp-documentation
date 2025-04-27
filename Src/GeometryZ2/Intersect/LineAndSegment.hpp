#pragma once

#include "../Line.hpp"
#include "../Segment.hpp"
#include "../Relation.hpp"

#include <cassert>

namespace zawa {

namespace geometryZ2 {

bool Intersect(const Line& l, const Segment& s, bool straddle = false) {
    assert(l.valid());
    assert(s.valid());
    RELATION r0 = Relation(l.p0(), l.p1(), s.p0());
    if (Abs(r0) != 1) return !straddle;
    RELATION r1 = Relation(l.p0(), l.p1(), s.p1());
    if (Abs(r1) != 1) return !straddle;
    return r0 != r1;
}

}

} // namespace zawa
