#pragma once

#include "../../Template/TypeAlias.hpp"

#include <cassert>
#include <concepts>
#include <ranges>
#include <vector>

namespace zawa {

template <std::integral T>
class BridgeTreeBuilder {

    class BridgeTree {
    public:

        BridgeTree(const std::vector<std::vector<std::pair<T,usize>>>& g,const std::vector<std::pair<T,T>>& edge) 
            : m_isBridge(edge.size()), m_id(g.size()), m_comps{}, m_g{} {
            const usize n = g.size();
            const usize m = edge.size();
            std::vector<u32> low(n),ord(n);
            std::vector<T> remain;
            u32 time = 1;
            auto dfs = [&](auto dfs,usize v,usize pe) -> void {
                ord[v] = low[v] = time++;
                for (auto [x,id] : g[v])
                    if (pe != id) {
                        if (ord[x]) {
                            low[v] = std::min(low[v],ord[x]);
                        }
                        else {
                            dfs(dfs,x,id);
                            low[v] = std::min(low[v],low[x]);
                            if (ord[v] < low[x]) {
                                m_isBridge[id] = 1;
                                std::vector<T> cur;
                                const T id = static_cast<T>(m_comps.size());
                                while (remain.size() and ord[v] < low[remain.back()]) {
                                    cur.push_back(remain.back());
                                    m_id[remain.back()] = id;
                                    remain.pop_back();
                                }
                                m_comps.push_back(std::move(cur));
                            }
                        }
                    }
                remain.push_back(v);
            };
            for (usize i = 0 ; i < n ; i++)
                if (!ord[i]) {
                    remain.clear();
                    dfs(dfs,i,edge.size());
                    for (T j : remain)
                        m_id[j] = static_cast<T>(m_comps.size());
                    m_comps.push_back(remain);
                }
            m_g.resize(m_comps.size());
            for (usize i = 0 ; i < m ; i++) 
                if (m_isBridge[i]) {
                    auto [u,v] = edge[i];
                    m_g[m_id[u]].push_back({m_id[v],i});
                    m_g[m_id[v]].push_back({m_id[u],i});
                }
        }

        inline usize size() const {
            return m_g.size();
        }

        T id(T v) const {
            assert(static_cast<usize>(v) < m_id.size());
            return m_id[v];
        }

        bool isBridge(usize i) const {
            assert(i < m_isBridge.size());
            return m_isBridge[i];
        }

        const std::vector<T>& component(T i) const {
            assert(static_cast<usize>(i) < size());
            return m_comps[i];
        }

        const std::vector<std::vector<T>>& components() const {
            return m_comps;
        }

        const std::vector<std::pair<T,usize>>& operator[](T i) const {
            assert(static_cast<usize>(i) < size());
            return m_g[i];
        }

    private:
        
        std::vector<bool> m_isBridge;

        std::vector<T> m_id;
        
        std::vector<std::vector<T>> m_comps;

        std::vector<std::vector<std::pair<T,usize>>> m_g;
    };

public:

    BridgeTreeBuilder() = default;

    explicit BridgeTreeBuilder(usize n) : m_n{n}, m_g(n) {}

    inline usize size() const {
        return m_n;
    }

    inline usize edgeSize() const {
        return m_edge.size();
    }

    usize addEdge(T u,T v) {
        assert(static_cast<usize>(u) < size());
        assert(static_cast<usize>(v) < size());
        usize res = m_edge.size();
        m_g[u].push_back({v,res});
        m_g[v].push_back({u,res});
        m_edge.push_back({u,v});
        return res;
    }

    std::pair<T,T> getEdge(usize i) const {
        assert(i < m_edge.size());
        return m_edge[i];
    }

    BridgeTree build() const {
        return BridgeTree{m_g,m_edge};
    }

private:

    usize m_n;

    std::vector<std::vector<std::pair<T,usize>>> m_g;

    std::vector<std::pair<T,T>> m_edge;

};

} // namespace zawa
