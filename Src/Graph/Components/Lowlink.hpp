#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

class Lowlink {
private:
    static constexpr u32 INVALID{static_cast<u32>(-1)};
    usize n_{}, m_{};
    std::vector<std::vector<std::pair<u32, u32>>> g_;
    std::vector<std::pair<u32, u32>> e_;
    std::vector<u32> in_, low_;
    std::vector<u32> articulation_;
    std::vector<bool> bridge_;

    void dfs(u32 v, u32 p, u32& t) {
        low_[v] = in_[v] = t++;
        u32 deg{}; 
        for (const auto& [x, i] : g_[v]) {
            if (in_[x] == INVALID) {
                deg++;
                dfs(x, v, t);
                low_[v] = std::min(low_[v], low_[x]);
                if (p != INVALID and low_[x] >= in_[v]) {
                    articulation_[v]++;
                }
                if (low_[x] > in_[v]) {
                    bridge_[i] = true;
                }
            }
            else if (x != p) {
                low_[v] = std::min(low_[v], in_[x]);
            }
        }
        if (p == INVALID) {
            articulation_[v] = deg;
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
        : n_{n}, m_{}, g_(n), in_(n, INVALID), low_(n), articulation_(n, u32{1}), bridge_{} {
        g_.shrink_to_fit();
        in_.shrink_to_fit();
        low_.shrink_to_fit();
        articulation_.shrink_to_fit();
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

    void build() {
        bridge_.resize(edgeSize());
        u32 t{};
        for (u32 v{} ; v < size() ; v++) if (in_[v] == INVALID) {
            dfs(v, INVALID, t);
        }
    }

    bool articular(u32 v) const noexcept {
        assert(v < size());
        return articulation_[v] > 1u;
    }
    u32 cut(u32 v) const noexcept {
        assert(v < size());
        return articulation_[v];
    }
    bool bridge(u32 i) const noexcept {
        assert(i < edgeSize());
        return bridge_[i];
    }
};

} // namespace zawa
