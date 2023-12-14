#pragma once

#include "../../Template/TypeAlias.hpp"
#include "./Edge.hpp"

#include <algorithm>
#include <cassert>
#include <type_traits>
#include <vector>

namespace zawa {

namespace internal {

template <class Weight>
class WeightedShortestPathTree {
public:
    static_assert(std::is_unsigned_v<Weight>, "Dijkstra's Algorithm only be work well by unsigned weight");
    using E = WeightedEdge<Weight>;
    static constexpr u32 invalid() noexcept {
        return E::invalid();
    }
private:
    static constexpr u32 INVALID{E::invalid()};
    usize n_;
    u32 root_;
    std::vector<E> tree_;
    std::vector<Weight> dist_;
public:
    WeightedShortestPathTree() = default;
    WeightedShortestPathTree(u32 n, u32 root) 
        : n_{n}, root_{root}, tree_(n), dist_(n, static_cast<Weight>(-1)) {
        assert(root < n);
        tree_.shrink_to_fit();
        dist_.shrink_to_fit();
        dist_[root] = Weight{};
    }

    inline usize size() const noexcept {
        return n_;
    }
    inline u32 root() const noexcept {
        return root_;
    }
    inline u32 parent(u32 v) const noexcept {
        assert(v < size());
        return tree_[v].parent;
    }
    inline u32 id(u32 v) const noexcept {
        assert(v < size());
        return tree_[v].id;
    }
    inline bool connect(u32 v) const noexcept {
        assert(v < size());
        return v == root_ or tree_[v].exist();
    }
    inline const Weight& dist(u32 v) const noexcept {
        assert(v < size());
        return dist_[v];
    }

    const Weight& operator[](u32 v) const noexcept {
        assert(v < size());
        return dist_[v];
    }

    bool relax(u32 from, u32 to, const Weight& weight, u32 id) {
        if (dist_[to] > dist_[from] + weight) {
            dist_[to] = dist_[from] + weight;
            tree_[to].parent = from;
            tree_[to].id = id;
            return true;
        }
        return false;
    }

    std::vector<u32> pathV(u32 v) {
        assert(v < size());
        assert(connect(v));
        std::vector<u32> res(1);
        res[0] = v;
        while (parent(v) != invalid()) {
            v = parent(v);
            res.emplace_back(v);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    std::vector<E> pathE(u32 v) {
        assert(v < size());
        assert(connect(v));
        std::vector<E> res;
        while (v != root()) {
            res.emplace_back(tree_[v]);
            v = parent(v);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

} // namespace internal

} // namespace zawa
