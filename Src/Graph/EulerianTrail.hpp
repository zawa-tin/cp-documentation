#pragma once

#include <algorithm>
#include <cassert>
#include <optional>
#include <utility>
#include <vector>

#include "../Template/TypeAlias.hpp"

namespace zawa {

// first: 頂点列, second: 辺番号列
template <class T>
std::optional<std::pair<std::vector<T>, std::vector<usize>>> EulerianTrail(usize n, const std::vector<std::pair<T, T>>& edges, bool directed) {
    std::vector<std::vector<std::pair<T, usize>>> g(n);
    for (usize i = 0 ; auto [u, v] : edges) {
        assert(u < n);
        assert(v < n);
        g[u].push_back({v, i});
        if (!directed) g[v].push_back({u, i});
        i++;
    }
    std::vector<bool> used(edges.size());
    std::vector<usize> cur(n), es;
    std::vector<T> vs;
    es.reserve(edges.size());
    vs.reserve(edges.size() + 1);
    auto dfs = [&](auto dfs, const T v) -> void {
        while (cur[v] < g[v].size()) {
            auto [x, i] = g[v][cur[v]++];
            if (!used[i]) {
                used[i] = true;
                dfs(dfs, x);
                es.push_back(i);
                vs.push_back(v);
            }
        }
    };
    usize st = edges.size() ? edges[0].first : 0, go = st;
    if (directed) {
        std::vector<usize> deg(n);
        for (auto [u, v] : edges) {
            deg[u]++;
            deg[v]--;
        }
        const usize p1 = 1, m1 = static_cast<usize>(-1);
        bool fnst = false, fngo = false;
        for (usize i = 0 ; i < n ; i++) {
            if (deg[i] == p1) {
                if (fnst) return std::nullopt;
                fnst = true;
                st = i;
            }
            else if (deg[i] == m1) {
                if (fngo) return std::nullopt;
                fngo = true;
                go = i;
            }
            else if (deg[i]) return std::nullopt;
        }
    }
    else {
        usize cntOdd = 0;
        for (usize i = 0 ; i < n ; i++) if (g[i].size() & 1) {
            if (cntOdd++) go = i;
            else st = i;
        }
        if (cntOdd != 0 and cntOdd != 2) return std::nullopt;
    }
    if (n) {
        dfs(dfs, st);
        std::ranges::reverse(vs);
        vs.push_back(go);
        std::ranges::reverse(es);
    }
    if (edges.size() != es.size()) return std::nullopt;
    return std::make_pair(vs, es);
}

} // namespace zawa
