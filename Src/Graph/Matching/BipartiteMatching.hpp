#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <utility>
#include <optional>
#include <vector>
#include <ranges>

namespace zawa {

template <class V>
std::vector<std::pair<V,V>> BipartiteMatching(usize N, usize M, std::vector<std::pair<V,V>> E) {
    std::vector<std::vector<std::pair<V,usize>>> g(N+M);
    for (usize i = 0 ; i < E.size() ; i++) {
        auto [u, v] = E[i];
        assert(0 <= u and u < (V)N);
        assert(0 <= v and v < (V)M);
        g[u].push_back({N+v,i});
        g[N+v].push_back({u,i});
    }
    std::vector<bool> free(N+M,1), used(E.size()), cur(N+M);
    std::vector<i32> dist(N+M,-1);
    std::vector<V> match(N,(V)N), que;
    while (1) {
        std::ranges::fill(dist,-1);
        fill(cur.begin(),cur.end(),0);
        que.clear();
        for (usize i = 0 ; i < N ; i++)
            if (free[i]) {
                que.push_back(i);
                dist[i] = 0;
            }
        for (usize t = 0 ; t < que.size() ; t++) {
            const V v = que[t];
            for (auto [x, i] : g[v]) {
                if (dist[x] != -1)
                    continue;
                if (v < (V)N and used[i])
                    continue;
                if (v >= (V)N and !used[i])
                    continue;
                dist[x] = dist[v] + 1;
                que.push_back(x);
            }
        }
        const i32 minDist = [&]() {
            i32 res = N + M;
            for (usize i = N ; i < N + M ; i++)
                if (free[i] and dist[i] != -1)
                    res = std::min(res,dist[i]);
            return res;
        }();
        if ((usize)minDist == N + M)
            break;
        auto dfs = [&](auto dfs,V v) -> bool {
            cur[v] = 1;
            if (v >= (V)N and free[v]) {
                free[v] = 0;
                return 1;
            }
            if (dist[v] >= minDist)
                return 0;
            for (auto [x, i] : g[v]) {
                if (cur[x])
                    continue;
                if (dist[v] + 1 != dist[x])
                    continue;
                if (v < (V)N and used[i])
                    continue;
                if (v >= (V)N and !used[i])
                    continue;
                if (dfs(dfs,x)) {
                    free[v] = 0;
                    used[i] = !used[i];
                    return 1;
                }
            }
            return 0;
        };
        for (usize i = 0 ; i < N ; i++)
            if (free[i] and !cur[i])
                dfs(dfs,i);
    }
    std::vector<std::pair<V,V>> res;
    for (usize i = 0 ; i < E.size() ; i++)
        if (used[i])
            res.push_back(E[i]);
    return res;
}

template <class V>
std::optional<std::vector<std::pair<V,V>>> BipartiteMatching(usize N,std::vector<std::pair<usize,usize>> E) {
    std::vector<std::vector<V>> g(N); 
    for (auto [u, v] : E) {
        assert(0 <= u and u < N);
        assert(0 <= v and v < N);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<i32> col(N,-1);
    auto dfs = [&](auto dfs,V v,i32 c) -> bool {
        col[v] = c;
        for (V x : g[v]) {
            if (col[x] == -1 and !dfs(dfs,x,c^1))
                return false;
            else if (col[v] == col[x])
                return false;
        }
        return true;
    };
    for (usize i = 0 ; i < N ; i++)
        if (col[i] == -1)
            if (!dfs(dfs,i,0))
                return std::nullopt;
    std::vector<V> id(N), L, R;
    for (usize i = 0 ; i < N ; i++)
        (col[i] == 0 ? L : R).push_back(i);
    for (usize i = 0 ; i < L.size() ; i++)
        id[L[i]] = i;
    for (usize i = 0 ; i < R.size() ; i++)
        id[R[i]] = L.size() + i;
    for (auto& [u, v] : E) {
        u = id[u];
        v = id[v];
        if (u >= L.size())
            std::swap(u,v);
        v -= L.size();
    }
    auto ans = BipartiteMatching(L.size(),R.size(),E);
    for (auto& [u, v] : ans) {
        u = L[u];
        v = R[v];
    }
    return ans;
}

} // namespace zawa
