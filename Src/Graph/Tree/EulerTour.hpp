#pragma once

#include "../../Template/TypeAlias.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

class EulerTour {
private:
    u32 root{};
    std::vector<std::vector<u32>> tree;
    std::vector<u32> tour;
    std::vector<u32> in, out;
    static constexpr u32 invalid{static_cast<u32>(-1)};

    void dfs(u32 v, u32 p, u32& t) {
        in[v] = ++t;
        tour.emplace_back(v);
        for (auto x : tree[v]) if (x != p) {
            assert(in[x] == invalid or !"given graph is not tree");
            dfs(x, v, t);
            tour.emplace_back(v);
        }
        out[v] = ++t;
    }

public:
    EulerTour() = default;
    EulerTour(usize n, u32 r) : root{r}, tree(n), tour{}, in(n, invalid), out(n, invalid) {
        assert(n);
        assert(r < n or !"r must be (r < n)");
        tour.reserve(2 * n - 1);
    }

    usize size() const noexcept {
        return tree.size();
    }
    
    usize rangeSize() const noexcept {
        return (size() << 1) - 1;
    }

    void addEdge(usize u, usize v) {
        assert(u < size());
        assert(v < size());
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    void build() {
        u32 t{invalid};
        dfs(root, invalid, t);
        assert(tour.size() == rangeSize());
    }

    bool isAncestor(usize anc, usize child) const {
        assert(anc < size());
        assert(child < size());
        return in[anc] < in[child] and out[child] < in[child];
    }

    u32 pos(u32 v) const {
        assert(v < size());
        return in[v];
    }

    std::pair<usize, usize> subtree(usize v) const {
        assert(v < size());
        return std::pair<usize, usize>{ in[v], out[v] };
    }

    const u32& operator[](usize i) const noexcept {
        assert(i < rangeSize());
        return tour[i];
    }

};

} // namespace zawa
