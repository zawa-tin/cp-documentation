#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Monoid/ChminMonoid.hpp"
#include "../../DataStructure/SparseTable/SparseTable.hpp"

#include <cassert>
#include <vector>

namespace zawa {

template <class V>
class LowestCommonAncestor {
private:
    using Monoid = ChminMonoid<u32, V>;

public:
    LowestCommonAncestor() = default;

    LowestCommonAncestor(const std::vector<std::vector<V>>& tree, V r = V{}) 
        : n_{tree.size()}, depth_(tree.size()), L_(tree.size()), R_(tree.size()), st_{} {
            std::vector<typename Monoid::Element> init;
            init.reserve(2 * size());
            auto dfs{[&](auto dfs, V v, V p) -> void {
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

    V operator()(V u, V v) const {
        assert(verify(u));
        assert(verify(v));
        if (L_[u] > L_[v]) {
            std::swap(u, v);
        }
        return u == v ? u : st_.product(L_[u], R_[v]).value();
    }

    V lca(V u, V v) const {
        return (*this)(u, v);
    }

    inline u32 depth(V v) const noexcept {
        assert(verify(v));
        return depth_[v];
    }

    u32 distance(V u, V v) const {
        assert(verify(u));
        assert(verify(v));
        return depth(u) + depth(v) - 2u * depth((*this)(u, v));
    }

    bool isAncestor(V p, V v) const {
        assert(verify(p));
        assert(verify(v));
        return L_[p] <= L_[v] and R_[v] <= R_[p];
    }

protected:
    u32 left(V v) const noexcept {
        return L_[v];
    }

    inline usize size() const {
        return n_;
    }

    inline bool verify(V v) const {
        return v < (V)size();
    }

private:
    static constexpr V INVALID{static_cast<V>(-1)};
    usize n_{};
    std::vector<u32> depth_, L_, R_;
    SparseTable<Monoid> st_;
};

} // namespace zawa
