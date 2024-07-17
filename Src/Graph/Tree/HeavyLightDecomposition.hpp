#pragma once

#include "../../Template/TypeAlias.hpp"
#include "./Tree.hpp"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <limits>
#include <utility>
#include <vector>

namespace zawa {

class HeavyLightDecomposition {
public:
    using Vertex = u32;

    static constexpr Vertex Invalid() noexcept {
        return INVALID;
    }

    HeavyLightDecomposition() = default;

    HeavyLightDecomposition(Tree T, Vertex root = 0u) 
        : n_{T.size()}, par_(n_), top_(n_), idx_(n_), 
        inv_(n_), size_(n_, usize{1}), dep_(n_) {

            auto dfs1{[&](auto dfs, Vertex v, Vertex p, usize d) -> usize {
                par_[v] = p;
                dep_[v] = d;
                if (p != INVALID) {
                    for (u32 i{} ; i + 1 < T[v].size() ; i++) if (T[v][i] == p) {
                        std::swap(T[v][i], T[v].back());
                        break;
                    }
                    assert(T[v].back() == p);
                    T[v].pop_back();
                }
                for (Vertex x : T[v]) {
                    size_[v] += dfs(dfs, x, v, d + 1);
                }
                for (u32 i{1} ; i < T[v].size() ; i++) if (size_[T[v][0]] < size_[T[v][i]]) {
                    std::swap(T[v][0], T[v][i]);
                }
                return size_[v];
            }};

            auto dfs2{[&](auto dfs, Vertex v, Vertex idx, Vertex top) -> Vertex {
                idx_[v] = idx++;
                inv_[idx_[v]] = v;
                top_[v] = top;
                if (T[v].size()) {
                    idx = dfs(dfs, T[v][0], idx, top);
                    for (u32 i{1} ; i < T[v].size() ; i++) {
                        idx = dfs(dfs, T[v][i], idx, T[v][i]);
                    }
                }
                return idx;
            }};

            dfs1(dfs1, root, INVALID, 0u);
            dfs2(dfs2, root, 0u, root);
        }

    inline usize size() const noexcept {
        return n_;
    }

    usize size(Vertex v) const noexcept {
        assert(v < size());
        return size_[v];
    }

    usize depth(Vertex v) const noexcept {
        assert(v < size());
        return dep_[v];
    }

    Vertex parent(Vertex v) const noexcept {
        assert(v < size());
        return par_[v];
    }

    Vertex index(Vertex v) const noexcept {
        assert(v < size());
        return idx_[v];
    }

    Vertex operator[](Vertex v) const noexcept {
        assert(v < size());
        return idx_[v];
    }


    std::vector<std::pair<Vertex, Vertex>> decomp(Vertex s, Vertex t) const {
        assert(s < size());
        assert(t < size());
        std::vector<std::pair<Vertex, Vertex>> res, ser;
        while (top_[s] != top_[t]) {
            if (dep_[top_[s]] >= dep_[top_[t]]) {
                res.emplace_back(s, top_[s]);
                s = top_[s];
                if (par_[s] != INVALID) s = par_[s];
            }
            else {
                ser.emplace_back(top_[t], t);
                t = top_[t];
                if (par_[t] != INVALID) t = par_[t];
            }
        }
        res.emplace_back(s, t);
        std::reverse(ser.begin(), ser.end());
        res.insert(res.end(), ser.begin(), ser.end()); 
        return res;
    }

    std::vector<std::pair<Vertex, Vertex>> operator()(Vertex s, Vertex t) const {
        return decomp(s, t);
    }

    Vertex lca(u32 u, u32 v) const {
        assert(u < size());
        assert(v < size());
        while (top_[u] != top_[v]) {
            if (dep_[top_[u]] >= dep_[top_[v]]) {
                u = top_[u];
                if (par_[u] != INVALID) u = par_[u];
            }
            else {
                v = top_[v];
                if (par_[v] != INVALID) v = par_[v];
            }
        }
        return (dep_[u] <= dep_[v] ? u : v);
    }

    // pはvの祖先か？
    bool isAncestor(Vertex v, Vertex p) {
        assert(v < size());
        assert(p < size());
        if (dep_[v] < dep_[p]) return false;
        while (v != INVALID and top_[v] != top_[p]) {
            v = par_[top_[v]];
        }
        return v != INVALID;
    }

    Vertex levelAncestor(Vertex v, usize step) const {
        assert(v < size());
        if (step > dep_[v]) return INVALID;
        while (true) {
            usize dist{dep_[v] - dep_[top_[v]]};
            if (dist >= step) break;
            step -= dist + 1;
            v = par_[top_[v]];
        }
        step = (dep_[v] - dep_[top_[v]]) - step;
        return inv_[idx_[top_[v]] + step];
    }

    Vertex jump(Vertex s, Vertex t, usize step) const {
        assert(s < size());
        assert(t < size());
        Vertex uu{INVALID}, vv{INVALID};
        usize d{};
        for (auto [u, v] : decomp(s, t)) {
            usize dist{std::max(dep_[u], dep_[v]) - std::min(dep_[u], dep_[v])};
            if (dist >= step) {
                uu = u;
                vv = v;
                d = dist;
                break;
            }
            step -= dist + 1;
        }
        if (uu == INVALID) return INVALID;
        if (dep_[uu] <= dep_[vv]) {
            return inv_[idx_[uu] + step];
        }
        else {
            return inv_[idx_[vv] + (d - step)];
        }
    }

    usize distance(Vertex s, Vertex t) const {
        assert(s < size());
        assert(t < size());
        usize res{};
        for (auto [u, v] : decomp(s, t)) {
            if (dep_[u] > dep_[v]) std::swap(u, v);
            res += dep_[v] - dep_[u];
        }
        return res;
    }

private:
    static constexpr Vertex INVALID{static_cast<Vertex>(-1)};
    usize n_{};
    std::vector<Vertex> par_{}, top_{}, idx_{}, inv_{};
    std::vector<usize> size_{}, dep_{};
};

} // namespace zawa
