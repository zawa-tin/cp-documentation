#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

namespace zawa {

class DisjointSetUnion {
private:
    usize n_{};
    std::vector<u32> parent_{}, size_{};
public:
    DisjointSetUnion() = default;
    DisjointSetUnion(usize n) : n_{n}, parent_(n), size_(n, u32{1}) {
        parent_.shrink_to_fit();
        size_.shrink_to_fit();
        std::iota(parent_.begin(), parent_.end(), u32{});
    }

    u32 leader(u32 v) {
        assert(v < n_);
        return (v == parent_[v] ? v : parent_[v] = leader(parent_[v]));
    }

    bool same(u32 u, u32 v) {
        assert(u < n_);
        assert(v < n_);
        return leader(u) == leader(v);
    }

    void merge(u32 u, u32 v) {
        assert(u < n_);
        assert(v < n_);
        u = leader(u);
        v = leader(v);
        if (u == v) return;
        if (size_[u] < size_[v]) std::swap(u, v);
        size_[u] += size_[v];
        parent_[v] = u;
    }

    constexpr u32 size() const noexcept {
        return n_;
    }

    u32 size(u32 v) {
        assert(v < n_);
        return size_[leader(v)];
    }

    std::vector<std::vector<u32>> enumerate() {
        std::vector res(n_, std::vector<u32>{});
        for (u32 i{} ; i < n_ ; i++) {
            res[leader(i)].emplace_back(i);
        }
        res.erase(std::remove_if(res.begin(), res.end(),
                    [](const std::vector<u32>& array) { return array.empty(); }), res.end());
        return res;
    }
};

} // namespace zawa
