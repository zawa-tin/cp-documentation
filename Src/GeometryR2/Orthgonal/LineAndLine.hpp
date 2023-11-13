#pragma once

#include "../Line.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

bool Orthgonal(const Line& l0, const Line& l1) {
    assert(l0.valid());
    assert(l1.valid());
    return Zero(Dot(l0.p1() - l0.p0(), l1.p1() - l1.p0()));
}

} // namespace zawa

} // namespace zawa
