#pragma once

#include "../Point.hpp"
#include "../Segment.hpp"
#include "../Parallel/SegmentAndSegment.hpp"
#include "../Intersect/SegmentAndSegment.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

Point CrossPoint(const Segment& s0, const Segment& s1) {
    assert(s0.valid());
    assert(s1.valid());
    assert(Intersect(s0, s1));
    if (Parallel(s0, s1)) {
        if (s0.p0() == s1.p0()) {
            if (Relation(s0.p0(), s0.p1(), s1.p1()) == ONLINE_BACK) {
                return s0.p0();
            }
            else {
                assert(false);
            }
        }
        else if (s0.p0() == s1.p1()) {
            if (Relation(s0.p0(), s0.p1(), s1.p0()) == ONLINE_BACK) {
                return s0.p0();
            }
            else {
                assert(false);
            }
        }
        else if (s0.p1() == s1.p0()) {
            if (Relation(s0.p1(), s0.p0(), s1.p1()) == ONLINE_BACK) {
                return s0.p1();
            }
            else {
                assert(false);
            }
        }
        else if (s0.p1() == s1.p1()) {
            if (Relation(s0.p1(), s0.p0(), s1.p0()) == ONLINE_BACK) {
                return s0.p1();
            }
            else {
                assert(false);
            }
        }
        else {
            assert(false);
        }
    }
    else {
        Vector base{s0.p1() - s0.p0()};
        Real baseNorm{base.norm()};
        Real r1{Abs(Cross(base, s1.p0() - s0.p0())) / baseNorm};
        Real r2{Abs(Cross(base, s1.p1() - s0.p0())) / baseNorm};
        return s1.p0() + (s1.p1() - s1.p0()) * (r1 / (r1 + r2));
    }
}

} // namespace geometryR2

} // namespace zawa
