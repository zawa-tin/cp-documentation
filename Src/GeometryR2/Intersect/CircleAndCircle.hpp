#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../Circle.hpp"

namespace zawa {

namespace geometryR2 {

bool Intersect(const Circle& c0, const Circle& c1) {
    u32 number{NumberCommonTangent(c0, c1)};
    return 0u < number and number < 4u;
}

} // namespace geometryR2

} // namespace zawa
