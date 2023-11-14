#pragma once

#include "../Real.hpp"
#include "../Circle.hpp"
#include "../Distance/LineAndPoint.hpp"

#include <cassert>

namespace zawa {
    
namespace geometryR2 {

bool Intersect(const Circle& c, const Line& l) {
    assert(l.valid());
    return !Bigger(Distance(l, c.center()), c.radius());
}
    
} // namespace geometryR2

} // namespace zawa
