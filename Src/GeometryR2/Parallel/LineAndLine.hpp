#pragma once

#include "../Line.hpp"

#include <cassert>

namespace zawa {

namespace geometryR2 {

bool Parallel(const Line& l0, const Line& l1) {
    assert(l0.valid());
    assert(l1.valid());
    return Zero(Cross(l0.p1() - l0.p0(), l1.p1() - l1.p0()));
}

}

} // namespace zawa
