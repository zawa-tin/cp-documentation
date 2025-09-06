#pragma once

#include "../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <concepts>
#include <vector>
#include <random>
#include <unordered_map>
#include <unordered_set>

#include <iostream>

namespace zawa {

namespace Random {

template <std::integral T>
std::vector<T> DistinctArray(usize n, T min, T max, bool verify = true) {
    assert(min <= max);
    assert(n <= static_cast<usize>(max - min + 1));
    std::mt19937_64 mt{std::random_device{}()};
    std::vector<T> res(n);
    std::unordered_map<T, T> mp;
    for (T& v : res) {
        T val = static_cast<T>(mt() % (max - min + 1)) + min;
        T replace = [&]() {
            auto it = mp.find(max);
            return it == mp.end() ? max : it->second;
        }();
        auto it = mp.find(val);
        if (it == mp.end()) {
            v = val;
            mp[val] = replace;
        }
        else {
            v = it->second;
            it->second = replace;
        }
        max--;
    }
    if (verify) {
        assert(std::ranges::all_of(res, [&](T v) { return min <= v and v <= static_cast<T>(max + n); }));
        assert(std::unordered_set<T>(res.begin(), res.end()).size() == n);
    }
    return res;
}

} // namespace Random

} // namespace zawa
