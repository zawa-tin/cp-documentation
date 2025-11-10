#pragma once

#include "./RandomTree.hpp"

#include <algorithm>
#include <cassert>
#include <concepts>
#include <utility>
#include <vector>
#include <random>
#include <set>

namespace zawa {

namespace Random {

template <std::integral T>
std::vector<std::pair<T, T>> ConnectedGraph(usize n, usize m, bool verify = true) {
    if (n == 0)
        return {};
    assert(n - 1 <= m and (u64)m <= (u64)n * (n - 1) / 2);
    std::vector<std::pair<T, T>> res = Tree<T>(n, verify);
    std::set<std::pair<T, T>> st;
    for (auto [u, v] : res)
        st.insert(std::minmax({u, v}));
    std::mt19937 mt{std::random_device{}()};
    while (res.size() < m) {
        T u = mt() % n, v = mt() % n;
        if (u == v)
            continue;
        if (st.contains(std::minmax({u, v})))
            continue;
        st.insert(std::minmax({u, v}));
        res.push_back({u, v});
    }
    if (verify) {
        std::set<std::pair<T, T>> used;
        for (auto [u, v] : res) {
            assert(0 <= u and u < static_cast<T>(n));
            assert(0 <= v and v < static_cast<T>(n));
            assert(u != v);
            used.insert(std::minmax({u, v}));
        }
        assert(used.size() == m);
    }
    return res;
}

} // namespace Random

} // namespace zawa
