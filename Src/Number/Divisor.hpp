#pragma once

#include "../Template/TypeAlias.hpp"

#include <cassert>
#include <type_traits>
#include <vector>

namespace zawa {

// @remark: 約数はソートされていない
template <class T>
std::vector<T> Divisor(T v) {
    assert(v > static_cast<T>(0));
    std::vector<T> res;
    for (T i{1} ; i * i <= v ; i++) {
        if (v % i) continue;
        res.emplace_back(i);
        if (i * i != v) {
            res.emplace_back(v / i);
        }
    }
    return res;
}

} // namespace zawa
