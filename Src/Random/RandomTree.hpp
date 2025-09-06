#pragma once

#include "./RandomPermutation.hpp"
#include "./RandomBalancedParenthesis.hpp"

#include <cassert>
#include <concepts>
#include <utility>
#include <vector>
#include <random>
#include <string>

namespace zawa {

namespace Random {

template <std::integral T>
std::vector<std::pair<T, T>> Tree(usize n, bool verify = true) {
    if (n == 0)
        return {};
    const std::string gen = BalancedParenthesis(n - 1, verify);
    std::vector<T> stk{0};
    usize cur = 1;
    std::vector<std::pair<T, T>> res;
    for (u8 c : gen) {
        if (c == '(') {
            const usize v = cur++;
            res.push_back({stk.back(), v});
            stk.push_back(v);
        }
        else {
            stk.pop_back();
        }
    }
    auto perm = Permutation<usize>(n);
    for (auto& [u, v] : res) {
        u = perm[u];
        v = perm[v];
    }
    if (verify) {
        assert(res.size() == n - 1);
        std::vector<bool> vis(n);
        std::vector<std::vector<T>> g(n);
        for (auto [u, v] : res) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        std::vector<std::pair<T, T>> que{std::pair{0, n + 1}};
        for (usize t = 0 ; t < que.size() ; t++) {
            auto [v, p] = que[t];
            for (T x : g[v])
                if (x != p) {
                    assert(!vis[x]);
                    vis[x] = 1;
                    que.push_back({x, v});
                }
        } 
    }
    return res;
}

} // namespace Random

} // namespace zawa
