#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Utility/U32Pair.hpp"

#include <algorithm>
#include <cassert>
#include <limits>
#include <type_traits>
#include <vector>
#include <queue>

namespace zawa {

template <class Cap> 
class Dinic {
private:
    static_assert(std::is_signed_v<Cap>, "Cap must be signed");
    usize n_{}, m_{};
    static constexpr u32 invalid() noexcept {
        return std::numeric_limits<u32>::max();
    }
public:
    inline usize size() const noexcept {
        return n_;
    }
    inline usize edgeNumber() const noexcept {
        return m_;
    }
private:
    struct Edge {
        u32 to{}, rev{};
        Cap residual{};
        Edge() = default;
        Edge(u32 to, u32 rev, const Cap& residual) 
            : to{to}, rev{rev}, residual{residual} {}
    };

    std::vector<std::vector<Edge>> g_;
    std::vector<U32Pair> edges_;
    std::vector<u32> label_, cur_;

    bool dualStep(u32 s, u32 t) {
        std::fill(label_.begin(), label_.end(), invalid());
        label_[s] = 0;
        std::queue<u32> queue{ { s } };
        while (queue.size()) {
            u32 v{queue.front()};
            queue.pop();
            for (const Edge& e : g_[v]) if (e.residual > 0) {
                if (label_[e.to] > label_[v] + 1) {
                    label_[e.to] = label_[v] + 1;
                    if (e.to == t) return true;
                    queue.emplace(e.to);
                }
            }
        }
        return false;
    }

    bool admissible(u32 v, const Edge& e) const noexcept {
        return e.residual > 0 and label_[v] + 1 == label_[e.to];
    }

    inline void flow(Edge& e, Cap f) {
        e.residual -= f;
        g_[e.to][e.rev].residual += f;
    }

    Cap dfs(u32 v, u32 t, Cap up) {
        if (v == t) return up;
        Cap res{};
        for (u32& i{cur_[v]} ; i < g_[v].size() ; i++) {
            if (!admissible(v, g_[v][i])) continue;
            Cap f{dfs(g_[v][i].to, t, std::min(g_[v][i].residual, up - res))};
            if (f == 0) continue;
            flow(g_[v][i], f);
            res += f;
            if (res == up) return res;
        }
        return res;
    }

    Cap primalStep(u32 s, u32 t) {
        std::fill(cur_.begin(), cur_.end(), 0u);
        cur_[t] = g_[t].size();
        Cap res{};
        while (true) {
            Cap f{dfs(s, t, std::numeric_limits<Cap>::max())};
            if (f == 0) break;
            res += f;
        }
        return res;
    }

    const Edge& edge(u32 i) const noexcept {
        return g_[edges_[i].first()][edges_[i].second()];
    }
    const Edge& reverse(u32 i) const noexcept {
        const Edge& e{edge(i)};
        return g_[e.to][e.rev];
    }

public:
    Dinic() = default;
    Dinic(u32 n, u32 m = 0u) 
        : n_{n}, m_{m}, g_(n), edges_{}, label_(n), cur_(n) {
        g_.shrink_to_fit();
        label_.shrink_to_fit();
        cur_.shrink_to_fit();
        edges_.reserve(m);
    }

    u32 addEdge(u32 u, u32 v, const Cap& cap) {
        assert(u < size());
        assert(v < size());
        u32 id{static_cast<u32>(g_[u].size())};
        u32 revId{u == v ? id + 1 : static_cast<u32>(g_[v].size())};
        u32 res{static_cast<u32>(edges_.size())};
        edges_.emplace_back(u, id);
        g_[u].emplace_back(v, revId, cap);
        g_[v].emplace_back(u, id, Cap{});
        m_++;
        return res;
    }

    const Cap& flowed(u32 id) const noexcept {
        assert(id < edgeNumber());
        return reverse(id).residual;
    }
    const Cap& residual(u32 id) const noexcept {
        assert(id < edgeNumber());
        return edge(id).residual;
    }
    const Cap& capacity(u32 id) const noexcept {
        assert(id < edgeNumber());
        return edge(id).residual + reverse(id).residual;
    }
    const u32& from(u32 id) const noexcept {
        assert(id < edgeNumber());
        return edges_[id].first();
    }
    const u32& to(u32 id) const noexcept {
        assert(id < edgeNumber());
        return edge(id).to;
    }

    Cap flow(u32 s, u32 t) {
        assert(s < size());
        assert(t < size()); 
        Cap res{};
        while (dualStep(s, t)) {
            res += primalStep(s, t);
        }
        return res;
    }

    std::vector<bool> cut(u32 s) {
        std::vector<bool> res(size());
        res[s] = true;
        std::queue<u32> queue{ { s } };
        while (queue.size()) {
            u32 v{queue.front()};
            queue.pop();
            for (const auto& e : g_[v]) if (e.residual > 0 and !res[e.to]) {
                res[e.to] = true;
                queue.emplace(e.to);
            }
        }
        return res;
    }    
};

} // namespace zawa
