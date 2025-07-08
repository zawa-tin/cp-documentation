#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

class Lowlink {
public:

    using V = usize;

    using ID = usize;

private:

    class LowlinkResponse {
    public:

        LowlinkResponse() = default;

        LowlinkResponse(std::vector<u32>&& articulation, std::vector<bool>&& bridge)
            : m_articulation{std::move(articulation)}, m_bridge{std::move(bridge)} {}

        inline bool isArticulation(V v) const {
            assert(v < m_articulation.size());
            return m_articulation[v] > 1u;
        }

        inline u32 cut(V v) const {
            assert(v < m_articulation.size());
            return m_articulation[v];
        }

        inline bool isBridge(ID i) const {
            assert(i < m_bridge.size());
            return m_bridge[i];
        }

    private:

        std::vector<u32> m_articulation;

        std::vector<bool> m_bridge;

    };

    static constexpr usize INVALID{static_cast<ID>(-1)};

    usize m_n{}, m_m{};

    std::vector<std::vector<std::pair<V, ID>>> m_g;

    std::vector<std::pair<V, V>> m_e;

    void dfs(V v, ID p_edge, u32& t, std::vector<u32>& articulation, 
            std::vector<bool>& bridge, std::vector<usize>& in, std::vector<usize>& low) const {
        low[v] = in[v] = t++;
        u32 deg{}; 
        for (const auto& [x, i] : m_g[v]) {
            if (in[x] == INVALID) {
                deg++;
                dfs(x, i, t, articulation, bridge, in, low);
                low[v] = std::min(low[v], low[x]);
                if (p_edge != INVALID and low[x] >= in[v]) {
                    articulation[v]++;
                }
                if (low[x] > in[v]) {
                    bridge[i] = true;
                }
            }
            else if (p_edge != i) {
                low[v] = std::min(low[v], in[x]);
            }
        }
        if (p_edge == INVALID) {
            articulation[v] = deg;
        }
    }

public:

    constexpr usize size() const noexcept {
        return m_n;
    }

    constexpr usize edgeSize() const noexcept {
        return m_m;
    }

    Lowlink() = default;

    explicit Lowlink(usize n) 
        : m_n{n}, m_m{}, m_g(n) {
        m_g.shrink_to_fit();
    }
    
    ID addEdge(V u, V v) {
        ID res{m_m++};
        m_e.emplace_back(u, v);
        m_g[u].emplace_back(v, res);
        m_g[v].emplace_back(u, res);
        return res;
    }

    const std::vector<std::pair<V, ID>>& operator[](V v) const noexcept {
        assert(v < size());
        return m_g[v];
    }

    const std::pair<V, V>& edge(ID i) const noexcept {
        assert(i < edgeSize());
        return m_e[i];
    }

    LowlinkResponse build() const {
        u32 t{};
        std::vector<u32> articulation(size(), 1u);
        std::vector<usize> in(size(), INVALID), low(size());
        std::vector<bool> bridge(edgeSize());
        for (u32 v{} ; v < size() ; v++) if (in[v] == INVALID) {
            dfs(v, INVALID, t, articulation, bridge, in, low);
        }
        return LowlinkResponse{ std::move(articulation), std::move(bridge) };
    }

};

} // namespace zawa
