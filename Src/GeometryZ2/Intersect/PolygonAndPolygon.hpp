#pragma once

#include "../Polygon.hpp"
#include "../Segment.hpp"
#include "./SegmentAndSegment.hpp"

#include <cassert>

namespace zawa {

namespace geometryZ2 {

// !!!!!! naive algorithm !!!!!!
bool Intersect(const Polygon& p0, const Polygon& p1) {
    assert(p0.size() >= 2u);
    assert(p1.size() >= 2u);
    for (size_t i{} ; i < p0.size() ; i++) {
        for (size_t j{} ; j + 1 < p1.size() ; j++) {
            Segment s0{p0[i], p0[i+1==p0.size()?0u:i+1]};
            Segment s1{p1[j], p1[j+1==p1.size()?0u:j+1]};
            if (Intersect(s0, s1)) return true;
        }
    }
    return false;
}

} // namespace geometryZ2

} // namespace zawa
