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
            : articulation_{std::move(articulation)}, bridge_{std::move(bridge)} {}

        inline bool isArticulation(V v) const {
            assert(v < articulation_.size());
            return articulation_[v] > 1u;
        }

        inline u32 cut(V v) const {
            assert(v < articulation_.size());
            return articulation_[v];
        }

        inline bool isBridge(ID i) const {
            assert(i < bridge_.size());
            return bridge_[i];
        }

    private:

        std::vector<u32> articulation_;

        std::vector<bool> bridge_;

    };

    static constexpr usize INVALID{static_cast<usize>(-1)};

    usize n_{}, m_{};

    std::vector<std::vector<std::pair<V, ID>>> g_;

    std::vector<std::pair<V, V>> e_;

    void dfs(V v, V p, u32& t, std::vector<u32>& articulation, 
            std::vector<bool>& bridge, std::vector<usize>& in, std::vector<usize>& low) const {
        low[v] = in[v] = t++;
        u32 deg{}; 
        for (const auto& [x, i] : g_[v]) {
            if (in[x] == INVALID) {
                deg++;
                dfs(x, v, t, articulation, bridge, in, low);
                low[v] = std::min(low[v], low[x]);
                if (p != INVALID and low[x] >= in[v]) {
                    articulation[v]++;
                }
                if (low[x] > in[v]) {
                    bridge[i] = true;
                }
            }
            else if (x != p) {
                low[v] = std::min(low[v], in[x]);
            }
        }
        if (p == INVALID) {
            articulation[v] = deg;
        }
    }

public:

    constexpr usize size() const noexcept {
        return n_;
    }

    constexpr usize edgeSize() const noexcept {
        return m_;
    }

    Lowlink() = default;

    explicit Lowlink(usize n) 
        : n_{n}, m_{}, g_(n) {
        g_.shrink_to_fit();
    }
    
    ID addEdge(V u, V v) {
        ID res{m_++};
        e_.emplace_back(u, v);
        g_[u].emplace_back(v, res);
        g_[v].emplace_back(u, res);
        return res;
    }

    const std::vector<std::pair<V, ID>>& operator[](V v) const noexcept {
        assert(v < size());
        return g_[v];
    }
    const std::pair<V, V>& edge(ID i) const noexcept {
        assert(i < edgeSize());
        return e_[i];
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
