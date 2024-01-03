#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Utility/U32Pair.hpp"

#include <cassert>
#include <limits>
#include <queue>
#include <type_traits>
#include <utility>
#include <vector>

namespace zawa {

template <class Cap, class Cost>
class SuccessiveShortestPath {
public:
    static_assert(std::is_signed_v<Cost>, U"Cost must be signed");
    static constexpr Cost invalid{(std::numeric_limits<Cost>::max() >> 1) - 1};
    static constexpr u32 reverseId(u32 i) noexcept {
        return i ^ 1;
    }

    struct Edge {
        u32 from{}, to{};
        Cap residual{};
        Cost cost{};
        Edge() = default;
        Edge(u32 from, u32 to, const Cap& cap, const Cost& cost)
            : from{from}, to{to}, residual{cap}, cost{cost} {}
    };

    usize n_{}, m_{};
    std::vector<Edge> edges_;
    std::vector<std::vector<u32>> g_;
    std::vector<Cost> dist_, potential_;
    std::vector<U32Pair> prev_;
    Cost mcf_{};

    constexpr usize size() const noexcept {
        return n_;
    }
    constexpr usize edgeSize() const noexcept {
        return m_;
    }
    
    SuccessiveShortestPath() = default;
    SuccessiveShortestPath(usize n, usize m = usize{}) 
        : n_{n}, m_{}, edges_{}, g_(n), dist_(n), potential_(n), prev_(n), mcf_{} {
        g_.shrink_to_fit();
        dist_.shrink_to_fit();
        potential_.shrink_to_fit();
        prev_.shrink_to_fit();
        edges_.reserve(2 * m);
    }

    void emplace(u32 from, u32 to, const Cap& cap, const Cost& cost) {
        g_[from].emplace_back(m_);
        edges_.emplace_back(from, to, cap, cost);
        m_++;
    }

    u32 addEdge(u32 from, u32 to, const Cap& cap, const Cost& cost) {
        assert(from < size());
        assert(to < size());
        u32 res{static_cast<u32>(m_)};
        emplace(from, to, cap, cost);
        emplace(to, from, Cap{}, -cost);
        return res;
    }

    inline u32 from(u32 i) const noexcept {
        return edges_[i].from;
    }
    inline u32 to(u32 i) const noexcept {
        return edges_[i].to;
    }
    inline const Cap& residual(u32 i) const noexcept {
        return edges_[i].residual;
    }
    inline const Cost& cost(u32 i) const noexcept {
        return edges_[i].cost;
    }
    inline const Cap& flowed(u32 i) const noexcept {
        assert(i < edgeSize());
        return residual(i ^ 1);
    }
    inline const Cap& capcacity(u32 i) const noexcept {
        assert(i < edgeSize());
        return residual(i) + flowed(i);
    }

    inline Cost edgeCost(u32 i) const noexcept {
        return potential_[from(i)] + cost(i) - potential_[to(i)];
    }
    bool relax(u32 i) {
        if (residual(i) > 0 and dist_[to(i)] > dist_[from(i)] + edgeCost(i)) {
            dist_[to(i)] = dist_[from(i)] + edgeCost(i);
            prev_[to(i)] = U32Pair{from(i), i};
            return true;
        }
        return false;
    }

    bool dijkstra(u32 s, u32 t) {
        assert(s < size());
        assert(t < size());
        std::fill(dist_.begin(), dist_.end(), invalid);
        dist_[s] = Cost{};
        using qt = std::pair<Cost, u32>;
        std::priority_queue<qt, std::vector<qt>, std::greater<qt>> que;
        que.emplace(dist_[s], s);
        while (que.size()) {
            auto [d, v]{que.top()};
            que.pop();
            if (dist_[v] < d) continue;
            for (u32 i : g_[v]) {
                if (relax(i)) {
                    que.emplace(dist_[to(i)], to(i));
                }
            }
        }
        return dist_[t] < invalid;
    }

    bool dagdp(u32 s, u32 t) {
        assert(s < size());
        assert(t < size());
        std::fill(dist_.begin(), dist_.end(), invalid);
        dist_[s] = Cost{};
        std::vector<u32> ord;
        ord.reserve(size());
        std::vector<bool> vis(size());
        vis[s] = true;
        ord.push_back(s);
        for (u32 i{} ; i < ord.size() ; i++) {
            u32 v{ord[i]};
            for (auto e : g_[v]) {
                if (!vis[to(e)]) {
                    ord.push_back(to(e));
                    vis[to(e)] = true;
                }
                relax(e);
            }
        }
        return dist_[t] < invalid;
    }

    bool bellmanford(u32 s, u32 t) {
        assert(s < size());
        assert(t < size());
        std::fill(dist_.begin(), dist_.end(), invalid);
        dist_[s] = Cost{};
        for (u32 i{} ; i + 1 < size() ; i++) {
            for (u32 j{} ; j < edgeSize() ; j++) {
                relax(j);
            }
        }
        return dist_[t] < invalid;
    }

    void updatePotential() {
        for (u32 v{} ; v < size() ; v++) {
            potential_[v] = potential_[v] + (dist_[v] == invalid ? Cost{} : dist_[v]);
        }
    }

    Cap flush(u32 s, u32 t, Cap up = std::numeric_limits<Cap>::max()) {
        for (u32 v{t} ; v != s ; v = prev_[v].first()) {
            up = std::min(up, residual(prev_[v].second()));
        }
        for (u32 v{t} ; v != s ; v = prev_[v].first()) {
            edges_[prev_[v].second()].residual -= up;
            edges_[prev_[v].second() ^ 1].residual += up;
        }
        return up;
    }

    bool flow(u32 s, u32 t, Cap flow) {
        assert(s < size());
        assert(t < size());
        while (flow > 0 and dijkstra(s, t)) {
            updatePotential();
            Cap water{flush(s, t, flow)};
            mcf_ += potential_[t] * water;
            flow -= water;
        }
        return flow == 0;
    }

    Cap maxflow(u32 s, u32 t) {
        assert(s < size());
        assert(t < size());
        Cap flow{};
        while (dijkstra(s, t)) {
            updatePotential();
            Cap water{flush(s, t)};
            mcf_ += potential_[t] * water;
            flow += water;
        }
        return flow;
    }

    std::vector<Cost> slope(u32 s, u32 t) {
        assert(s < size());
        assert(t < size());
        Cap flow{};
        std::vector<Cost> res;
        while (dijkstra(s, t)) {
            updatePotential();
            Cap water{flush(s, t)};
            for (u32 i{} ; i < water ; i++) {
                res.emplace_back(mcf_);
                mcf_ += potential_[t];
                flow++;
            }
        }
        res.emplace_back(mcf_);
        return res;
    }

    struct Line {
        Cap dn{}, up{};
        Cost slope{};
        Line() = default;
        Line(Cap dn, Cap up, Cost slope) : dn{dn}, up{up}, slope{slope} {}
    };
    std::vector<Line> slopeACL(u32 s, u32 t) {
        assert(s < size());
        assert(t < size()); 
        Cap flow{};
        std::vector<Line> res;
        while (dijkstra(s, t)) {
            updatePotential();
            Cap water{flush(s, t)};
            mcf_ += potential_[t] * water;
            res.emplace_back(flow, flow + water, potential_[t]);
            flow += water;
        }
        return res;
    }

    Cost minCost() const noexcept {
        return mcf_;
    }
};

} // namespace zawa
