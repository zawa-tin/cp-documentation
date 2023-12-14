#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <vector>

namespace zawa {

namespace internal {

class Edge {
protected:
    static constexpr u32 INVALID{static_cast<u32>(-1)};
public:
    u32 parent{INVALID}; 
    u32 id{INVALID};
    Edge() = default;
    Edge(u32 parent, u32 id) : parent{parent}, id{id} {}
    Edge& operator=(const Edge& edge) {
        parent = edge.parent;
        id = edge.id;
        return *this;
    }
    inline bool exist() const noexcept {
        return parent != INVALID;
    }
    static constexpr u32 invalid() noexcept {
        return INVALID; 
    }
};

class ShortestPathTree {
public:
    using E = internal::Edge;
    static constexpr u32 invalid() noexcept {
        return E::invalid();
    }
protected:
    static constexpr u32 INVALID{E::invalid()};
    usize n_;
    u32 root_;
    std::vector<E> tree_;
    std::vector<u32> dist_;
public:
    ShortestPathTree() = default;
    ShortestPathTree(usize n, u32 root) : n_{n}, root_{root}, tree_(n), dist_(n, INVALID) {
        assert(root < n);
        tree_.shrink_to_fit();
        dist_.shrink_to_fit();
        dist_[root] = 0;
    }

    inline usize size() const noexcept {
        return n_;
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
        return tree_[v].exist();
    }
    inline u32 dist(u32 v) const noexcept {
        assert(v < size());
        return dist_[v];
    }

    u32 operator[](u32 v) const noexcept {
        assert(v < size());
        return dist_[v];
    }

    bool relax(u32 from, u32 to, u32 id) {
        if (dist_[to] > dist_[from] + 1) {
            dist_[to] = dist_[from] + 1;
            tree_[to].parent = from;
            tree_[to].id = id;
            return true;
        }
        return false;
    }

    std::vector<u32> pathV(u32 v) {
        assert(v < size());
        assert(connect(v));
        std::vector<u32> res(dist(v) + 1);
        res[dist(v)] = v;
        for (u32 i{dist(v)} ; i-- ; ) {
            v = parent(v);
            res[i] = v;
        }
        return res;
    }
    
    std::vector<E> pathE(u32 v) {
        assert(v < size());
        assert(connect(v));
        std::vector<E> res(dist(v));
        for (u32 i{dist(v)} ; i-- ; ) {
            res[i] = tree_[v];
            v = parent(v);
        }
        return res;
    }
};

} // namespace internal

} // namespace zawa
