#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Utility/U32Pair.hpp"

#include <algorithm>
#include <cassert>
#include <iterator>
#include <limits>
#include <utility>
#include <vector>

namespace zawa {

class HeavyLightDecomposition {
private:
    usize n_;
    std::vector<std::vector<u32>> g_;
    std::vector<u32> index_, top_, depth_, par_;
    std::vector<u32> subtree_;

    static constexpr u32 invalid() noexcept {
        return std::numeric_limits<u32>::max();
    }

    u32 dfsInit(u32 v, u32 p) {
        par_[v] = p;
        for (auto it{g_[v].begin()} ; it != g_[v].end() ; ) {
            if (*it == p) {
                it = g_[v].erase(it);
            }
            else {
                subtree_[v] += dfsInit(*it, v);
                it++;
            }
        }
        return ++subtree_[v];
    }
    void dfs(u32 v, u32 p, u32 tp, u32& t) {
        top_[v] = tp;
        index_[v] = t;
        depth_[v] = (p == invalid() ? u32{} : depth_[p] + 1);
        if (g_[v].empty()) return;
        auto max{std::distance(g_[v].begin(), std::max_element(g_[v].begin(), g_[v].end(), [&](const auto& i, const auto& j) {
                    return subtree_[i] < subtree_[j];
                }))};
        if (max) std::swap(g_[v][0], g_[v][max]);
        dfs(g_[v][0], v, tp, ++t);
        for (u32 i{1u} ; i < g_[v].size() ; i++) {
            dfs(g_[v][i], v, g_[v][i], ++t);
        }
    }

public:
    constexpr usize size() const noexcept {
        return n_;
    }
    HeavyLightDecomposition() = default;
    HeavyLightDecomposition(usize n) 
        : n_{n}, g_(n), index_(n), top_(n), depth_(n), par_(n, invalid()), subtree_(n) {
        g_.shrink_to_fit();
        index_.shrink_to_fit();
        top_.shrink_to_fit();
        depth_.shrink_to_fit();
        par_.shrink_to_fit();
        subtree_.shrink_to_fit();
    } 
    void addEdge(u32 u, u32 v) {
        assert(u < size());
        assert(v < size());
        g_[u].emplace_back(v);
        g_[v].emplace_back(u);
    }
    void build(u32 r) {
        assert(r < size()); 
        dfsInit(r, invalid());
        u32 t{};
        dfs(r, invalid(), r, t);
    }

    const u32& operator[](u32 i) const noexcept {
        assert(i < size());
        return index_[i];
    }

    std::vector<U32Pair> operator()(u32 s, u32 t) const {
        assert(s < size());
        assert(t < size());
        std::vector<U32Pair> res, ser; 
        while (top_[s] != top_[t]) {
            if (depth_[top_[s]] <= depth_[top_[t]]) {
                ser.emplace_back(index_[top_[t]], index_[t] + 1);
                t = top_[t];
                t = (par_[t] == invalid() ? t : par_[t]);
            }
            else {
                res.emplace_back(index_[top_[s]], index_[s] + 1);
                s = top_[s];
                s = (par_[s] == invalid() ? s : par_[s]);
            }
        }
        res.emplace_back(std::min(index_[s], index_[t]), std::max(index_[s], index_[t]) + 1u);
        res.insert(res.end(), ser.begin(), ser.end());
        return res;
    }

    u32 lca(u32 u, u32 v) {
        assert(u < size());
        assert(v < size());
        while (top_[u] != top_[v]) {
            if (depth_[top_[u]] <= depth_[top_[v]]) {
                v = top_[v];
                v = (par_[v] == invalid() ? v : par_[v]);
            }
            else {
                u = top_[u];
                u = (par_[u] == invalid() ? u : par_[u]);
            }
        }
        return (depth_[u] <= depth_[v] ? u : v);
    }
};

} // namespace zawa
