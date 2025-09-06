#pragma once

#include "../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <concepts>
#include <numeric>
#include <vector>
#include <random>

namespace zawa {

namespace Random {

// [0 .. n)
template <std::integral T>
std::vector<T> Permutation(usize n) {
    std::mt19937_64 mt{std::random_device{}()};
    std::vector<T> res(n);
    std::iota(res.begin(), res.end(), T{0});
    std::ranges::shuffle(res, mt);
    return res;
}

} // namespace Random

} // namespace zawa
