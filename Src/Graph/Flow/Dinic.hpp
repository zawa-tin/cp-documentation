#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <type_traits>
#include <utility>
#include <vector>

namespace zawa {

template <class Cap>
class Dinic {
private:
    static_assert(std::is_signed_v<Cap>, "Cap must be signed");
    static constexpr u32 INVALID{static_cast<u32>(-1)};
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
            u32 rev{}, id{};
            Edge() = default;
            Edge(u32 from, u32 to, const Cap& cap, u32 rev, u32 id)
                : from{from}, to{to}, cap{cap}, rev{rev}, id{id} {}
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
            assert(i < size());
            return g_[i];
        }
        const std::vector<Edge>& operator[](usize i) const noexcept {
            assert(i < size());
            return g_[i];
        }

        void addEdge(u32 from, u32 to, const Cap& cap, u32 id) {
            u32 i{static_cast<u32>(g_[from].size())};
            u32 j{static_cast<u32>(from == to ? i + 1 : g_[to].size())};
            g_[from].emplace_back(from, to, cap, j, id);
            g_[to].emplace_back(to, from, Cap{}, i, id);
            m_++;
        }
        void update(Edge& e, const Cap& flow) {
            assert(e.cap >= flow);
            e.cap -= flow;
            g_[e.to][e.rev].cap += flow;
        }
        u32 invalidEdgePointer(u32 v) const noexcept {
            return g_[v].size();
        }
    };

    ResidualGraph graph_;
    std::vector<u32> label_;

public:
    using Edge = typename ResidualGraph::Edge;
    inline usize size() const noexcept {
        return graph_.size();
    }
private:

    bool admissible(const Edge& e) {
        return e.cap > 0 and label_[e.from] + 1 == label_[e.to];
    }

    bool dualStep(u32 s, u32 t) {
        std::fill(label_.begin(), label_.end(), invalid());
        label_[s] = 0;
        std::vector<u32> queue;
        queue.reserve(size());
        queue.emplace_back(s);
        for (u32 topQ{} ; topQ < queue.size() ; topQ++) {
            u32 v{queue[topQ]};
            for (const auto& e : graph_[v]) if (e.cap > 0) {
                if (label_[e.to] > label_[v] + 1) {
                    label_[e.to] = label_[v] + 1;
                    queue.emplace_back(e.to);
                }
            }
        }
        return label_[t] < size();
    }

    using EdgePointer = std::pair<u32, u32>;

    bool findAdmissiblePath(u32 s, u32 t, std::vector<EdgePointer>& path) {
        std::vector<u32> currentEdge(size());
        currentEdge[t] = graph_.invalidEdgePointer(t);
        u32 v{s};
        while (true) {
            while (currentEdge[v] != graph_.invalidEdgePointer(v)) {
                const Edge& now{graph_[v][currentEdge[v]]};
                if (admissible(now)) {
                    path.emplace_back(v, currentEdge[v]);
                    v = now.to;
                }
                else {
                    currentEdge[v]++;
                }
            }
            if (v == s) return false;
            if (v == t) return true;
            if (v != t) {
                v = path.back().first;
                path.pop_back();
                currentEdge[v]++;
            }
        }
        assert(false);
        return false;
    }

    Cap flow(const std::vector<EdgePointer>& path) {
        auto min{std::min_element(path.begin(), path.end(), [&](const EdgePointer& l, const EdgePointer& r) -> bool {
                return graph_[l.first][l.second].cap < graph_[r.first][r.second].cap;
            })};
        Cap amount{graph_[min->first][min->second].cap};
        assert(amount > 0);
        for (const auto& [x, y] : path) {
            Edge& e{graph_[x][y]};
            graph_.update(e, amount);
        }
        return amount;
    }

    Cap primalStep(u32 s, u32 t) {
        std::vector<EdgePointer> path;
        Cap res{};
        while (findAdmissiblePath(s, t, path)) {
            res += flow(path);
            path.clear();
        }
        return res;
    }

public:

    Dinic() = default;
    Dinic(usize n) : graph_{n}, label_(n) {
        label_.shrink_to_fit();
    }

    void addEdge(u32 from, u32 to, const Cap& cap, u32 id = invalid()) {
        assert(from < size());
        assert(to < size());
        graph_.addEdge(from, to, cap, id);
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
};

} // namespace zawa
