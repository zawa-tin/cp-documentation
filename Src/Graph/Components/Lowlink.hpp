#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

class LowlinkResponse {
public:
    LowlinkResponse() = default;

    LowlinkResponse(const std::vector<u32>& articulation, const std::vector<bool>& bridge)
        : articulation_{articulation}, bridge_{bridge} {}

    inline bool isArticulation(u32 v) const {
        assert(v < articulation_.size());
        return articulation_[v] > 1u;
    }

    inline u32 cut(u32 v) const {
        assert(v < articulation_.size());
        return articulation_[v];
    }

    inline bool isBridge(u32 i) const {
        assert(i < bridge_.size());
        return bridge_[i];
    }

private:
    std::vector<u32> articulation_;
    std::vector<bool> bridge_;
};

class Lowlink {
private:
    static constexpr u32 INVALID{static_cast<u32>(-1)};
    usize n_{}, m_{};
    std::vector<std::vector<std::pair<u32, u32>>> g_;
    std::vector<std::pair<u32, u32>> e_;

    void dfs(u32 v, u32 p, u32& t, std::vector<u32>& articulation, 
            std::vector<bool>& bridge, std::vector<u32>& in, std::vector<u32>& low) const {
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

    Lowlink(usize n) 
        : n_{n}, m_{}, g_(n) {
        g_.shrink_to_fit();
    }
    
    usize addEdge(u32 u, u32 v) {
        usize res{m_++};
        e_.emplace_back(u, v);
        g_[u].emplace_back(v, res);
        g_[v].emplace_back(u, res);
        return res;
    }

    const std::vector<std::pair<u32, u32>>& operator[](u32 v) const noexcept {
        assert(v < size());
        return g_[v];
    }
    const std::pair<u32, u32>& edge(u32 i) const noexcept {
        assert(i < edgeSize());
        return e_[i];
    }

    LowlinkResponse build() const {
        u32 t{};
        std::vector<u32> articulation(size(), 1u), in(size(), INVALID), low(size());
        std::vector<bool> bridge(edgeSize());
        for (u32 v{} ; v < size() ; v++) if (in[v] == INVALID) {
            dfs(v, INVALID, t, articulation, bridge, in, low);
        }
        return LowlinkResponse{ articulation, bridge };
    }

};

} // namespace zawa
