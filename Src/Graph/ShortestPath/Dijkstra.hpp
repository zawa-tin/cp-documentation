#pragma once

#include "../../Template/TypeAlias.hpp"
#include "./WeightedShortestPathTree.hpp"

#include <cassert>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

namespace zawa {

template <class Weight>
class Dijkstra {
public:
    using ShortestPathTree = internal::WeightedShortestPathTree<Weight>;
private:
    usize n_;
    std::vector<std::vector<std::tuple<u32, Weight, u32>>> adj_;

    static constexpr u32 invalid() noexcept {
        return ShortestPathTree::invalid();
    }

public:
    Dijkstra() = default;
    Dijkstra(usize n) : n_{n}, adj_(n) {
        adj_.shrink_to_fit();
    }
    usize size() const noexcept {
        return n_;
    }
    Dijkstra(const std::vector<std::pair<u32, Weight>>& g) : n_{g.size()}, adj_(g.size()) {
        adj_.shrink_to_fit();
        for (u32 v{} ; v < size() ; v++) {
            for (auto [x, w] : g[v]) {
                adj_[v].emplace_back(x, w, invalid);
            }
        }
    }
    void addDirectedEdge(u32 from, u32 to, const Weight& weight, u32 id = invalid()) {
        assert(from < size());
        assert(to < size());
        adj_[from].emplace_back(to, weight, id);
    }
    void addUndirectedEdge(u32 u, u32 v, const Weight& weight, u32 id = invalid()) {
        assert(u < size());
        assert(v < size());
        adj_[u].emplace_back(v, weight, id);
        adj_[v].emplace_back(u, weight, id);
    }

    ShortestPathTree build(u32 start) {
        using QueueData = std::pair<Weight, u32>;
        std::priority_queue<QueueData, std::vector<QueueData>, std::greater<QueueData>> queue;
        queue.emplace(Weight{}, start);
        ShortestPathTree res(n_, start);
        while (queue.size()) {
            auto [w, v]{queue.top()};
            queue.pop();
            if (res.dist(v) < w) {
                continue;
            }
            for (auto [x, w, id] : adj_[v]) {
                if (res.relax(v, x, w, id)) {
                    queue.emplace(res.dist(x), x);
                }
            } 
        }
        return res;
    }
};

} // namespace zawa
