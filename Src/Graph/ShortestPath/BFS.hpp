#pragma once

#include "../../Template/TypeAlias.hpp"
#include "./ShortestPathTree.hpp"

#include <utility>
#include <vector>

namespace zawa {

class BFS {
public:
    using ShortestPathTree = internal::ShortestPathTree;
private:
    usize n_;
    std::vector<std::vector<std::pair<u32, u32>>> adj_;

    static constexpr u32 invalid() noexcept {
        return ShortestPathTree::invalid();
    }

public:
    BFS() = default;
    BFS(usize n) : n_{n}, adj_(n) {
        adj_.shrink_to_fit();
    }

    usize size() const noexcept {
        return n_;
    }
    void addDirectedEdge(u32 from, u32 to, u32 id = invalid()) {
        assert(from < size());
        assert(to < size());
        adj_[from].emplace_back(to, id);
    }
    void addUndirectedEdge(u32 u, u32 v, u32 id = invalid()) {
        assert(u < size());
        assert(v < size());
        adj_[u].emplace_back(v, id);
        adj_[v].emplace_back(u, id);
    }

    BFS(const std::vector<std::vector<u32>>& g) : n_{g.size()}, adj_(g.size()) {
        adj_.shrink_to_fit();
        for (u32 v{} ; v < size() ; v++) {
            for (u32 x : g[v]) {
                adj_[v].emplace_back(x, invalid());
            }
        }
    }

    ShortestPathTree build(u32 start) {
        std::vector<u32> queue;
        queue.reserve(n_);
        ShortestPathTree res(n_, start);
        queue.emplace_back(start);
        for (u32 head{} ; head < queue.size() ; head++) {
            u32 v{queue[head]};
            for (auto [x, id] : adj_[v]) {
                if (res.relax(v, x, id)) {
                    queue.emplace_back(x);
                }
            }
        }
        return res;
    }
};

} // namespace zawa
