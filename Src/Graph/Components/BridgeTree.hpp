#pragma once

#include "../../Template/TypeAlias.hpp"

#include <concepts>
#include <vector>
#include <unordered_map>

namespace zawa {

template <std::integral T>
class BridgeTree {
public:

    using V = usize;

    BridgeTree() = default;

    explicit BridgeTree(const std::vector<std::vector<T>>& g) : m_id(g.size()) {
        const usize n = g.size();
        std::vector<usize> low(n), ord(n);
        std::vector<T> vs;
        std::vector<std::pair<T, T>> bridge;
        usize time = 1, id = 0;
        auto dfs = [&](auto dfs, T v, T p) -> void {
            low[v] = ord[v] = time++;
            std::unordered_map<T, usize> cnt;
            for (T x : g[v]) cnt[x]++;
            for (auto [x, c] : cnt) if (x != p) {
                if (ord[x]) {
                    low[v] = std::min(low[v], ord[x]);
                }
                else {
                    dfs(dfs, x, v);
                    low[v] = std::min(low[v], low[x]);
                    if (c == 1u and ord[v] < low[x]) {
                        std::vector<T> cur; 
                        while (vs.size() and low[x] <= low[vs.back()]) {
                            cur.push_back(vs.back());
                            m_id[vs.back()] = m_comp.size();
                            vs.pop_back();
                        }
                        bridge.emplace_back(x, v);
                        m_comp.push_back(std::move(cur));
                    }
                }
            }
            vs.push_back(v);
        };
        for (usize v = 0 ; v < n ; v++) if (!ord[v]) {
            dfs(dfs, v, static_cast<T>(-1));
            if (vs.size()) {
                std::vector<T> cur;
                while (vs.size()) {
                    m_id[vs.back()] = m_comp.size();
                    cur.push_back(vs.back());
                    vs.pop_back();
                }
                m_comp.push_back(std::move(cur));
            }
        }
        m_g.resize(m_comp.size());
        for (auto [u, v] : bridge) {
            const V p = m_id[u], q = m_id[v];
            m_g[p].push_back(q);
            m_g[q].push_back(p);
        }
    }

    inline usize size() const noexcept {
        return m_g.size();
    }

    const std::vector<V>& operator[](V v) const {
        assert(v < size());
        return m_g[v];
    }

    const std::vector<std::vector<T>>& components() const {
        return m_comp;
    }

    const std::vector<T>& component(V v) const {
        assert(v < size());
        return m_comp[v];
    }

private:

    std::vector<V> m_id;

    std::vector<std::vector<T>> m_comp;

    std::vector<std::vector<V>> m_g;
};

} // namespace zawa
