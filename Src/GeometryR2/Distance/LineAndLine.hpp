#pragma once

#include "../Real.hpp"
#include "../Line.hpp"
#include "../Intersect/LineAndLine.hpp"
#include "./PointAndPoint.hpp"
#include "./LineAndPoint.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

Real Distance(const Line& l0, const Line& l1) {
    assert(l0.valid());
    assert(l1.valid());
    if (Intersect(l0, l1)) {
        return static_cast<Real>(0);
    }
    else {
        return Distance(l0, l1.p0());
    }
}

} // namespace geometryR2

} // namespace zawa
