#pragma once

#include "../../DataStructure/DisjointSetUnion/DisjointSetUnion.hpp"

#include <cassert>
#include <concepts>
#include <utility>
#include <vector>

namespace zawa {

template <std::integral T>
std::vector<T> OfflineLowestCommonAncestor(const std::vector<std::vector<T>>& g,const std::vector<std::pair<T,T>>& qs) {
    const T n = static_cast<T>(g.size()), q = static_cast<T>(qs.size());
    if (!n) {
        assert(!q);
        return {};
    }
    DisjointSetUnion dsu(n);
    std::vector<bool> visited(n);
    std::vector<T> anc(n),ans(q),sum(n+1);
    for (auto [u,v] : qs) {
        sum[u+1]++;
        sum[v+1]++;
    }
    for (T i = 0 ; i < n ; i++)
        sum[i+1]+=sum[i];
    std::vector<std::pair<T,u32>> query(sum[n]);
    {
        std::vector<T> cur(n);
        for (T i = 0 ; i < q ; i++) {
            auto [u,v] = qs[i];
            query[sum[u]+cur[u]++] = {v,i};
            query[sum[v]+cur[v]++] = {u,i};
        }
    }
    auto dfs=[&](auto dfs,T v,T p) -> void {
        anc[v]=v;
        visited[v]=1;
        for (T x : g[v])
            if (x!=p) {
                dfs(dfs,x,v);
                anc[dsu.mergeAndLeader(x,v).value()] = v;
            }
        for (T i = sum[v] ; i < sum[v+1] ; i++) {
            auto [u,id] = query[i];
            if (visited[u])
                ans[id] = anc[dsu.leader(u)];
        }
    };
    dfs(dfs,static_cast<T>(0),static_cast<T>(-1));
    return ans;
}

} // namespace zawa
