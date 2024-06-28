#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Monoid/ChminMonoid.hpp"
#include "../../DataStructure/SparseTable/SparseTable.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

class LowestCommonAncestor {
private:
    using Monoid = ChminMonoid<u32, usize>;
    using SptValue = Monoid::Element;
    using Spt = SparseTable<Monoid>;
    static constexpr u32 invalid{static_cast<u32>(-1)};
    Spt spt_{};
    usize n_{}, root_{};
    std::vector<std::vector<u32>> tree_{};
    std::vector<SptValue> euler_{};
    std::vector<u32> first_{}, depth_{};

    void dfs(u32 v, u32 p) {
        first_[v] = euler_.size();
        depth_[v] = (p == invalid ? invalid : depth_[p]) + 1;
        euler_.emplace_back(depth_[v], v);
        for (auto x : tree_[v]) if (x != p) {
            assert(first_[x] == invalid or !"given graph is not tree");
            dfs(x, v);
            euler_.emplace_back(depth_[v], v);
        }
    }

public:
    LowestCommonAncestor() = default;
    LowestCommonAncestor(u32 n, u32 root) 
        : n_{n}, root_{root}, tree_(n), euler_{}, first_(n, invalid), depth_(n) {
        assert(n or !"empty graph is not allowed");
        assert(root < n);
        euler_.reserve(2 * n - 1);
        first_.shrink_to_fit();
        depth_.shrink_to_fit();
    }

    constexpr u32 size() const noexcept {
        return n_;
    }

    void addEdge(usize u, usize v) {
        assert(u < size());
        assert(v < size());
        tree_[u].emplace_back(v);
        tree_[v].emplace_back(u);
    }

    const std::vector<u32>& operator[](u32 v) const {
        return tree_[v];
    }

    void build() {
        dfs(root_, invalid);
        spt_ = Spt(euler_);
    }

    u32 operator()(u32 u, u32 v) const {
        assert(u < size());
        assert(v < size());
        if (first_[u] > first_[v]) std::swap(u, v);
        return spt_.product(first_[u], first_[v] + 1).value();
    }

    u32 depth(u32 v) const noexcept {
        assert(v < size());
        return depth_[v];
    }

    u32 distance(u32 u, u32 v) const {
        assert(u < size());
        assert(v < size());
        return depth_[u] + depth_[v] - 2u * depth_[(*this)(u, v)];
    }

    bool isAncestor(u32 anc, u32 child) const {
        return (*this)(anc, child) == anc;
    }
};

} // namespace zawa
