#pragma once

#include "../../Template/TypeAlias.hpp"

#include <vector>
#include <cassert>
#include <concepts>
#include <limits>

namespace zawa {

namespace concepts {

template <class T>
concept TreeDP = requires {
    typename T::Tree;
    typename T::Cluster;
    typename T::Edge;
    typename T::Vertex;
    { T::Convert(std::declval<typename T::Vertex>()) } -> std::same_as<typename T::Tree>;
    { T::AddEdge(std::declval<typename T::Tree>(), std::declval<typename T::Edge>()) } -> std::same_as<typename T::Cluster>;
    { T::Merge(std::declval<typename T::Cluster>(), std::declval<typename T::Cluster>()) } -> std::same_as<typename T::Cluster>;
    { T::AddVertex(std::declval<typename T::Cluster>(), std::declval<typename T::Vertex>()) } -> std::same_as<typename T::Tree>;
};

}

template <concepts::TreeDP T>
using TreeDPGraph = std::vector<std::vector<std::pair<usize, typename T::Edge>>>;

template <concepts::TreeDP T>
std::vector<typename T::Tree> TreeDP(const TreeDPGraph<T>& g, const std::vector<typename T::Vertex>& vs, usize root) {
    using Tree = typename T::Tree;
    using Cluster = typename T::Cluster;
    // using Edge = typename T::Edge;
    // using Vertex = typename T::Vertex;
    assert(g.size() == vs.size());
    const usize n = g.size();
    std::vector<Tree> res(n);
    auto rec = [&](auto rec, usize v, usize p) -> Tree {
        if (ssize(g[v]) == 1 and g[v][0].first == p)
            return res[v] = T::Convert(vs[v]);
        usize idx = g[v][0].first == p ? 1 : 0;
        assert(idx < g[v].size());
        Cluster cluster = T::AddEdge(rec(rec, g[v][idx].first, v), g[v][idx].second);
        idx++;
        for ( ; idx < g[v].size() ; idx++) {
            Cluster cur = T::AddEdge(rec(rec, g[v][idx].first, v), g[v][idx].second);
            cluster = T::Merge(cluster, cur);
        }
        return res[v] = T::AddVertex(cluster, vs[v]);
    };
    rec(rec, root, g.size());
    return res;
}

template <concepts::TreeDP T>
std::vector<typename T::Tree> Rerooting(const TreeDPGraph<T>& g, const std::vector<typename T::Vertex>& vs) {
    using Tree = typename T::Tree;
    using Cluster = typename T::Cluster;
    // using Edge = typename T::Edge;
    // using Vertex = typename T::Vertex;
    assert(g.size() == vs.size());
    const usize n = g.size();
    if (n <= 2) {
        std::vector<Tree> res(n);
        for (usize i = 0 ; i < n ; i++)
            res[i] = TreeDP<T>(g, vs, i)[i];
        return res;
    }
    std::vector<Cluster> dp(n);
    auto rec1 = [&](auto rec, usize v, usize p) -> Tree {
        if (ssize(g[v]) == 1 and g[v][0].first == p)
            return T::Convert(vs[v]);
        usize idx = g[v][0].first == p ? 1 : 0;
        assert(idx < g[v].size());
        dp[v] = T::AddEdge(rec(rec, g[v][idx].first, v), g[v][idx].second);
        idx++;
        for ( ; idx < g[v].size() ; idx++)
            if (g[v][idx].first != p) {
                Cluster cur = T::AddEdge(rec(rec, g[v][idx].first, v), g[v][idx].second);
                dp[v] = T::Merge(dp[v], cur);
            }
        return T::AddVertex(dp[v], vs[v]);
    };
    usize root = 0;
    while (root < g.size() and g[root].size() <= 1)
        root++;
    assert(root < g.size());
    std::vector<Tree> res(n);
    res[root] = rec1(rec1, root, g.size());
    auto rec2 = [&](auto rec, usize v, usize p, Cluster pv) -> void {
        if (ssize(g[v]) == 1) {
            assert(g[v][0].first == p);
            res[v] = T::AddVertex(pv, vs[v]);
            return;
        }
        assert(ssize(g[v]) >= 2);
        std::vector<Cluster> pref(g[v].size()), suf(g[v].size());
        pref[0] = g[v][0].first == p ? pv : T::AddEdge(dp[g[v][0].first], g[v][0].second);
        for (usize i = 1 ; i < g[v].size() ; i++) {
            Cluster cur = g[v][i].first == p ? pv : T::AddEdge(dp[g[v][i].first], g[v][i].second);
            pref[i] = T::Merge(pref[i - 1], cur);
        }
        suf[g[v].size() - 1] = g[v].back().first == p ? pv : T::AddEdge(dp[g[v].back().first], g[v].back().second);
        for (usize i = g[v].size() - 1 ; i-- ; ) {
            Cluster cur = g[v][i].first == p ? pv : T::AddEdge(dp[g[v][i].first], g[v][i].second);
            suf[i] = T::Merge(cur, suf[i + 1]);
        }
        res[v] = T::AddVertex(pref.back(), vs[v]);
        for (usize i = 0 ; i < g[v].size() ; i++)
            if (g[v][i].first != p) {
                Cluster pc = i == 0 ? suf[1] : (i + 1 == g[v].size() ? pref[i - 1] : T::Merge(pref[i - 1], suf[i + 1]));
                rec(rec, g[v][i].first, v, T::AddEdge(T::AddVertex(pc, vs[v]), g[v][i].second));
            }
    };
    rec2(rec2, root, g.size(), Cluster{});
    return res;
}

} // namespace zawa
