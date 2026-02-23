#pragma once

#include <algorithm>
#include <cassert>
#include <optional>
#include <utility>
#include <vector>

#include "../Template/TypeAlias.hpp"

namespace zawa {

// first: vertices, second: edge id
template <class T>
std::optional<std::pair<std::vector<T>, std::vector<usize>>> EulerianTrail(T n, const std::vector<std::pair<T, T>>& edges, bool directed, T start = -1) {
    if (start != static_cast<T>(-1))
        assert(start < n);
    std::vector<std::vector<std::pair<T, usize>>> g(n);
    for (usize i = 0 ; auto [u, v] : edges) {
        assert(u < n and v < n);
        g[u].push_back({v, i});
        if (!directed) 
            g[v].push_back({u, i});
        i++;
    }
    T st = edges.empty() ? T{0} : edges[0].first, go = st;
    if (directed) {
        std::vector<i32> deg(n);
        for (auto [u, v] : edges) {
            deg[u]++;
            deg[v]--;
        }
        bool fnst = false, fngo = false;
        for (T i = 0 ; i < n ; i++) {
            if (deg[i] == 1) {
                if (fnst) 
                    return std::nullopt;
                fnst = true;
                st = i;
            }
            else if (deg[i] == -1) {
                if (fngo) 
                    return std::nullopt;
                fngo = true;
                go = i;
            }
            else if (deg[i]) 
                return std::nullopt;
        }
        if (start != static_cast<T>(-1)) {
            if (fnst and st != start)
                return std::nullopt;
            if (!fnst)
                st = go = start;
        }
    }
    else {
        usize cntOdd = 0;
        for (T i = 0 ; i < n ; i++) 
            if (g[i].size() & 1)
                (cntOdd++ ? go : st) = i;
        if (cntOdd != 0 and cntOdd != 2) 
            return std::nullopt;
        if (start != static_cast<T>(-1)) {
            if (cntOdd == 0)
                st = go = start;
            else if (go == start)
                std::swap(st,go);
            else if (st != start)
                return std::nullopt;
        }
    }
    std::vector<bool> used(edges.size());
    std::vector<usize> cur(n), es;
    std::vector<T> vs;
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
    dfs(dfs, st);
    std::ranges::reverse(vs);
    vs.push_back(go);
    std::ranges::reverse(es);
    if (edges.size() != es.size()) 
        return std::nullopt;
    return std::make_pair(vs, es);
}

} // namespace zawa
