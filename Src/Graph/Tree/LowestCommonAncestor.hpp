#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Monoid/ChminMonoid.hpp"
#include "../../DataStructure/SparseTable/SparseTable.hpp"
#include "./Tree.hpp"

#include <cassert>
#include <vector>

namespace zawa {

class LowestCommonAncestor {
private:
    using Monoid = ChminMonoid<u32, u32>;

public:
    LowestCommonAncestor() = default;

    LowestCommonAncestor(const Tree& tree, u32 r = 0u) 
        : n_{tree.size()}, depth_(tree.size()), L_(tree.size()), R_(tree.size()), st_{} {
            std::vector<Monoid::Element> init;
            init.reserve(2 * size());
            auto dfs{[&](auto dfs, u32 v, u32 p) -> void {
                depth_[v] = (p == INVALID ? 0u : depth_[p] + 1);
                L_[v] = (u32)init.size();
                for (auto x : tree[v]) {
                    if (x == p) {
                        continue;
                    }
                    init.emplace_back(depth_[v], v);
                    dfs(dfs, x, v);
                }
                R_[v] = (u32)init.size();
            }};
            dfs(dfs, r, INVALID);
            st_ = SparseTable<Monoid>(init);
    }

    u32 operator()(u32 u, u32 v) const {
        assert(verify(u));
        assert(verify(v));
        if (L_[u] > L_[v]) {
            std::swap(u, v);
        }
        return st_.product(L_[u], R_[v]).value();
    }

    inline u32 depth(u32 v) const noexcept {
        assert(verify(v));
        return depth_[v];
    }

    u32 distance(u32 u, u32 v) const {
        assert(verify(u));
        assert(verify(v));
        return depth(u) + depth(v) - 2u * depth((*this)(u, v));
    }

    bool isAncestor(u32 p, u32 v) const {
        assert(verify(p));
        assert(verify(v));
        return L_[p] <= L_[v] and R_[v] <= R_[p];
    }

private:
    static constexpr u32 INVALID{static_cast<u32>(-1)};
    usize n_{};
    std::vector<u32> depth_, L_, R_;
    SparseTable<Monoid> st_;

    inline usize size() const {
        return n_;
    }

    inline bool verify(u32 v) const {
        return v < size();
    }
};

} // namespace zawa
