#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <concepts>
#include <cmath>
#include <limits>
#include <utility>
#include <vector>

namespace zawa {

template <std::integral V>
class HeavyLightDecomposition {
public:

    static constexpr V Invalid() noexcept {
        return INVALID;
    }

    HeavyLightDecomposition() = default;

    HeavyLightDecomposition(std::vector<std::vector<V>> T, V root = 0u) 
        : m_n{T.size()}, m_par(m_n), m_top(m_n), m_idx(m_n), 
        m_inv(m_n), m_bottom(m_n),  m_size(m_n, usize{1}), m_dep(m_n) {

            auto dfs1 = [&](auto dfs, V v, V p, usize d) -> usize {
                m_par[v] = p;
                m_dep[v] = d;
                if (p != INVALID) {
                    for (usize i = 0 ; i + 1 < T[v].size() ; i++) 
                        if (T[v][i] == p) {
                            std::swap(T[v][i], T[v].back());
                            break;
                        }
                    assert(T[v].back() == p);
                    T[v].pop_back();
                }
                for (V x : T[v])
                    m_size[v] += dfs(dfs, x, v, d + 1);
                for (usize i = 1 ; i < T[v].size() ; i++) 
                    if (m_size[T[v][0]] < m_size[T[v][i]])
                        std::swap(T[v][0], T[v][i]);
                return m_size[v];
            };

            auto dfs2 = [&](auto dfs, V v, V idx, V top) -> V {
                m_idx[v] = idx++;
                m_inv[m_idx[v]] = v;
                m_top[v] = top;
                if (T[v].size()) {
                    idx = dfs(dfs, T[v][0], idx, top);
                    for (usize i = 1 ; i < T[v].size() ; i++)
                        idx = dfs(dfs, T[v][i], idx, T[v][i]);
                }
                return idx;
            };

            dfs1(dfs1, root, INVALID, 0u);
            dfs2(dfs2, root, 0u, root);

            for (usize i = 0 ; i < m_n ; i++)
                if (m_dep[m_bottom[m_top[i]]] < m_dep[i])
                    m_bottom[m_top[i]] = i;
        }

    inline usize size() const noexcept {
        return m_n;
    }

    usize size(V v) const noexcept {
        assert(v < (V)size());
        return m_size[v];
    }

    usize depth(V v) const noexcept {
        assert(v < (V)size());
        return m_dep[v];
    }

    V parent(V v) const noexcept {
        assert(v < (V)size());
        return m_par[v];
    }

    V index(V v) const noexcept {
        assert(v < (V)size());
        return m_idx[v];
    }

    V operator[](V v) const noexcept {
        assert(v < (V)size());
        return m_idx[v];
    }

    V top(V v) const noexcept {
        assert(v < (V)size());
        return m_top[v];
    }

    V bottom(V v) const noexcept {
        assert(v < (V)size());
        return m_bottom[m_top[v]];
    }

    std::pair<V, V> heavyPath(V v) const {
        assert(v < (V)size());
        return {top(v), bottom(v)};
    }

    std::vector<std::pair<V, V>> decomp(V s, V t) const {
        assert(s < (V)size());
        assert(t < (V)size());
        std::vector<std::pair<V, V>> res, ser;
        while (m_top[s] != m_top[t]) {
            if (m_dep[m_top[s]] >= m_dep[m_top[t]]) {
                res.emplace_back(s, m_top[s]);
                s = m_top[s];
                if (m_par[s] != INVALID) s = m_par[s];
            }
            else {
                ser.emplace_back(m_top[t], t);
                t = m_top[t];
                if (m_par[t] != INVALID) t = m_par[t];
            }
        }
        res.emplace_back(s, t);
        std::reverse(ser.begin(), ser.end());
        res.insert(res.end(), ser.begin(), ser.end()); 
        return res;
    }

    std::vector<std::pair<V, V>> operator()(V s, V t) const {
        return decomp(s, t);
    }

    V lca(V u, V v) const {
        assert(u < (V)size());
        assert(v < (V)size());
        while (m_top[u] != m_top[v]) {
            if (m_dep[m_top[u]] >= m_dep[m_top[v]]) {
                u = m_top[u];
                if (m_par[u] != INVALID) u = m_par[u];
            }
            else {
                v = m_top[v];
                if (m_par[v] != INVALID) v = m_par[v];
            }
        }
        return (m_dep[u] <= m_dep[v] ? u : v);
    }

    // is p ancestor of v ?
    bool isAncestor(V v, V p) const {
        assert(v < size());
        assert(p < size());
        if (m_dep[v] < m_dep[p]) return false;
        while (v != INVALID and m_top[v] != m_top[p]) {
            v = m_par[m_top[v]];
        }
        return v != INVALID;
    }

    V levelAncestor(V v, usize step) const {
        assert(v < (V)size());
        if (step > m_dep[v]) return INVALID;
        while (true) {
            usize dist{m_dep[v] - m_dep[m_top[v]]};
            if (dist >= step) break;
            step -= dist + 1;
            v = m_par[m_top[v]];
        }
        step = (m_dep[v] - m_dep[m_top[v]]) - step;
        return m_inv[m_idx[m_top[v]] + step];
    }

    V jump(V s, V t, usize step) const {
        assert(s < (V)size());
        assert(t < (V)size());
        V uu{INVALID}, vv{INVALID};
        usize d{};
        for (auto [u, v] : decomp(s, t)) {
            usize dist{std::max(m_dep[u], m_dep[v]) - std::min(m_dep[u], m_dep[v])};
            if (dist >= step) {
                uu = u;
                vv = v;
                d = dist;
                break;
            }
            step -= dist + 1;
        }
        if (uu == INVALID) return INVALID;
        if (m_dep[uu] <= m_dep[vv])
            return m_inv[m_idx[uu] + step];
        else
            return m_inv[m_idx[vv] + (d - step)];
    }

    usize distance(V s, V t) const {
        assert(s < (V)size());
        assert(t < (V)size());
        usize res{};
        for (auto [u, v] : decomp(s, t)) {
            if (m_dep[u] > m_dep[v]) std::swap(u, v);
            res += m_dep[v] - m_dep[u];
        }
        return res;
    }

private:

    static constexpr V INVALID{static_cast<V>(-1)};

    usize m_n{};

    std::vector<V> m_par{}, m_top{}, m_idx{}, m_inv{}, m_bottom{};

    std::vector<usize> m_size{}, m_dep{};
};

} // namespace zawa
