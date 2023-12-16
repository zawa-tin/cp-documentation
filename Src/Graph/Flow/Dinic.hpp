#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Utility/U32Pair.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <type_traits>
#include <vector>
#include <queue>

namespace zawa {

template <class Cap>
class Dinic {
private:
    static_assert(std::is_signed_v<Cap>, "Cap must be signed");
    static constexpr u32 INVALID{static_cast<u32>(-1)};
    using EdgePointer = U32Pair;
public:
    static constexpr u32 invalid() noexcept {
        return INVALID;
    }
private:
    class ResidualGraph {
    public:
        struct Edge {
            u32 from{}, to{};
            Cap cap{};
            u32 rev{};
            Edge() = default;
            Edge(u32 from, u32 to, const Cap& cap, u32 rev)
                : from{from}, to{to}, cap{cap}, rev{rev} {}
        }; 
    private:
        usize n_{}, m_{};
        std::vector<std::vector<Edge>> g_{};
    public:
        ResidualGraph() = default;
        ResidualGraph(usize n) : n_{n}, m_{}, g_(n) {
            g_.shrink_to_fit();
        }

        inline usize size() const noexcept {
            return n_;
        }
        inline usize edgeNumber() const noexcept {
            return m_;
        }

        std::vector<Edge>& operator[](usize i) noexcept {
            return g_[i];
        }
        const std::vector<Edge>& operator[](usize i) const noexcept {
            return g_[i];
        }
        Edge& operator[](const EdgePointer& e) noexcept {
            return g_[e.first()][e.second()];
        }
        const Edge& operator[](const EdgePointer& e) const noexcept {
            return g_[e.first()][e.second()];
        }

        const Edge& reverseEdge(const EdgePointer& pos) const noexcept {
            const Edge& edge{g_[pos.first()][pos.second()]};
            return g_[edge.to][edge.rev];
        }
        
        u32 addEdge(u32 from, u32 to, const Cap& cap) {
            u32 i{static_cast<u32>(g_[from].size())};
            u32 j{static_cast<u32>(from == to ? i + 1 : g_[to].size())};
            g_[from].emplace_back(from, to, cap, j);
            g_[to].emplace_back(to, from, Cap{}, i);
            m_++;
            return i;
        }
        void update(Edge& e, const Cap& flow) {
            assert(e.cap >= flow);
            e.cap -= flow;
            g_[e.to][e.rev].cap += flow;
        }
    };

    using Edge = typename ResidualGraph::Edge;

    ResidualGraph graph_;
    std::vector<u32> label_;
    std::vector<EdgePointer> edges_;
    std::vector<u32> currentEdge_;

public:
    inline usize size() const noexcept {
        return graph_.size();
    }
    inline usize edgeNumber() const noexcept { 
        return graph_.edgeNumber();
    }
private:

    inline bool admissible(const Edge& e) const noexcept {
        return e.cap > 0 and label_[e.from] + 1 == label_[e.to];
    }

    bool dualStep(u32 s, u32 t) {
        std::fill(label_.begin(), label_.end(), invalid());
        label_[s] = 0;
        std::queue<u32> que{ { s } };
        while (que.size()) {
            u32 v{que.front()};
            que.pop();
            for (const auto& edge : graph_[v]) if (edge.cap > 0) {
                if (label_[edge.to] > label_[v] + 1) {
                    label_[edge.to] = label_[v] + 1;
                    if (edge.to == t) return true;
                    que.emplace(edge.to);
                }
            }
        }
        return label_[t] < size();
    }

    bool findAdmissiblePath(u32 s, u32 t, std::vector<EdgePointer>& path) {
        u32 v{path.empty() ? s : graph_[path.back()].to};
        while (true) {
            while (currentEdge_[v] < graph_[v].size()) {
                const Edge& now{graph_[v][currentEdge_[v]]};
                if (admissible(now)) {
                    path.emplace_back(v, currentEdge_[v]);
                    v = now.to;
                }
                else {
                    currentEdge_[v]++;
                }
            }
            if (v == s) return false;
            if (v == t) return true;
            v = path.back().first();
            path.pop_back();
            currentEdge_[v]++;
        }
        assert(false);
        return false;
    }

    Cap flow(std::vector<EdgePointer>& path) {
        Cap amount{graph_[*std::min_element(path.begin(), path.end(), [&](const EdgePointer& l, const EdgePointer& r) -> bool {
                return graph_[l].cap < graph_[r].cap;
            })].cap};
        assert(amount > 0);
        usize becomeZero{invalid()};
        for (usize i{path.size()} ; i-- ; ) {
            Edge& edge{graph_[path[i]]};
            graph_.update(edge, amount);
            if (edge.cap == 0) {
                currentEdge_[edge.from]++;
                becomeZero = i;
            }
        }
        path.erase(path.begin() + becomeZero, path.end());
        return amount;
    }

    Cap primalStep(u32 s, u32 t) {
        std::fill(currentEdge_.begin(), currentEdge_.end(), u32{});
        currentEdge_[t] = graph_[t].size();
        std::vector<EdgePointer> path;
        Cap res{};
        while (findAdmissiblePath(s, t, path)) {
            res += flow(path);
        }
        return res;
    }

public:

    Dinic() = default;
    // @param m: 辺数をここに入れるとreserveしてくれる
    Dinic(usize n, usize m = usize{}) 
        : graph_{n}, label_(n), currentEdge_(n) {
        label_.shrink_to_fit();
        currentEdge_.shrink_to_fit();
        edges_.reserve(m);
    }

    u32 addEdge(u32 from, u32 to, const Cap& cap) {
        assert(from < size());
        assert(to < size());
        u32 res{static_cast<u32>(edges_.size())};
        edges_.emplace_back(from, graph_.addEdge(from, to, cap));
        return res;
    }

    u32 from(u32 id) const noexcept {
        assert(id < edgeNumber());
        return graph_[edges_[id]].from;
    }

    u32 to(u32 id) const noexcept {
        assert(id < edgeNumber());
        return graph_[edges_[id]].to;
    }

    Cap residual(u32 id) const noexcept {
        assert(id < edgeNumber());
        return graph_[edges_[id]].cap;
    }

    Cap flowed(u32 id) const noexcept {
        assert(id < edgeNumber());
        return graph_.reverseEdge(edges_[id]).cap;
    }

    Cap originCap(u32 id) const noexcept {
        assert(id < edgeNumber());
        EdgePointer e{edges_[id]};
        return graph_[e].cap + graph_.reverseEdge(edges_[id]).cap;
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

    std::vector<bool> minCut(u32 s) const {
        std::vector<bool> res(size());
        std::queue<u32> que{ { s } };
        res[s] = true;
        while (que.size()) {
            u32 v{que.front()};
            que.pop();
            for (const auto& edge : graph_[v]) {
                if (edge.cap > 0 and !res[edge.to]) {
                    res[edge.to] = true;
                    que.emplace(edge.to);
                } 
            }
        }
        return res;
    }
};

} // namespace zawa
