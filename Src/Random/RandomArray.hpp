#pragma once

#include "../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <concepts>
#include <vector>
#include <random>

namespace zawa {

namespace Random {

template <std::integral T>
std::vector<T> Array(usize n, T min, T max, bool verify = true) {
    assert(min <= max);
    std::mt19937_64 mt{std::random_device{}()};
    std::vector<T> res(n);
    for (T& v : res) {
        v = static_cast<T>(mt() % (max - min + 1)) + min;
    }
    if (verify)
        std::ranges::all_of(res, [&](T v) { return min <= v and v <= max; });
    return res;
}

} // namespace Random

} // namespace zawa
