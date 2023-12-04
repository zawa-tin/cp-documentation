#pragma once

#include "../../Template/TypeAlias.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

class LevelAncestor {
private:
    usize n_{};
    u32 root_{};
    std::vector<std::vector<u32>> tree_;
    std::vector<std::vector<u32>> jump_;
    std::vector<u32> depth_;

    static constexpr u32 invalid_{static_cast<u32>(-1)};
    static constexpr u32 ceilLog2(u32 n) noexcept {
        assert(n or !"empty graph is not allowed");
        return 32 - __builtin_clz(n);
    }

public:
    constexpr usize size() const noexcept {
        return n_;
    }

    u32 log() const noexcept {
        return jump_.size();
    }

    const u32& depth(u32 v) const noexcept {
        assert(v < size());
        return depth_[v];
    }

    static constexpr u32 invalid() noexcept {
        return invalid_;
    }

    static constexpr bool invalid(usize v) noexcept {
        return v == invalid_;
    }

    constexpr u32 root() const noexcept {
        return root_;
    }

private:

    void dfs(u32 v, u32 p) {
        depth_[v] = (invalid(p) ? invalid_ : depth_[p]) + 1;
        jump_[0][v] = (invalid(p) ? v : p);
        for (u32 i{} ; i + 1 < log() ; i++) {
            jump_[i + 1][v] = jump_[i][jump_[i][v]];
        }
        for (auto x : tree_[v]) if (x != p) {
            assert(invalid(depth_[x]) or !"given graph is not tree");
            dfs(x, v);
        }
    }

public:
    LevelAncestor() = default;
    LevelAncestor(usize n, u32 root = 0)
        : n_{n}, root_{root}, tree_(n), jump_(ceilLog2(n), std::vector<u32>(n)), depth_(n, invalid_) {}
    LevelAncestor(const std::vector<std::vector<u32>>& tree, u32 root = 0) 
        : n_{tree.size()}, root_{root}, tree_{tree}, jump_(ceilLog2(n_), std::vector<u32>(n_)), depth_(n_, invalid_) {
        build();
    }

    void addEdge(usize u, usize v) {
        assert(u < size());
        assert(v < size());
        tree_[u].emplace_back(v);
        tree_[v].emplace_back(u);
    }

    void build() {
        dfs(root(), invalid_);
    }

    usize lca(usize u, usize v) const {
        if (depth(u) > depth(v)) std::swap(u, v);
        for (u32 i{log()} ; i-- ; ) {
            if ((depth(v) - depth(u)) & (1u << i)) {
                v = jump_[i][v];
            }
        }
        if (u == v) return u;
        for (u32 i{log()} ; i-- ; ) {
            if (jump_[i][u] != jump_[i][v]) {
                u = jump_[i][u];
                v = jump_[i][v];
            }
        }
        return jump_[0][u];
    }

    u32 operator()(u32 v, u32 up) const {
        assert(v < size());
        if (depth(v) < up) return invalid();
        if (depth(v) == up) return root();
        for (u32 i{log()} ; i-- ; ) {
            if (up & (1u << i)) {
                up ^= (1u << i);
                v = jump_[i][v];
            }
        }
        return v;
    }

};

} // namespace zawa
