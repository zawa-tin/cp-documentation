#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

namespace zawa {

class DisjointSetUnion {
public:
    DisjointSetUnion() = default;

    DisjointSetUnion(usize n) : n_{n}, comps_{n}, data_(n, -1) {
        data_.shrink_to_fit();
    }
    
    u32 leader(u32 v) {
        return data_[v] < 0 ? v : static_cast<u32>(data_[v] = leader(data_[v]));
    }

    bool same(u32 u, u32 v) {
        return leader(u) == leader(v);
    }

    bool merge(u32 u, u32 v) {
        assert(u < n_);
        assert(v < n_);
        u = leader(u);
        v = leader(v);
        if (u == v) return false;
        comps_--;
        if (data_[u] > data_[v]) std::swap(u, v);
        data_[u] += data_[v];
        data_[v] = u;
        return true;
    }

    inline usize size() const noexcept {
        return n_;
    }

    usize size(u32 v) {
        assert(v < n_);
        return static_cast<usize>(-data_[leader(v)]);
    }

    inline usize components() const noexcept {
        return comps_;
    }

    std::vector<std::vector<u32>> enumerate() {
        std::vector<std::vector<u32>> res(n_);
        for (u32 v{} ; v < n_ ; v++) {
            res[leader(v)].push_back(v);
        }
        res.erase(std::remove_if(res.begin(), res.end(),
                    [](const auto& arr) -> bool { return arr.empty(); }), res.end());
        return res;
    }

private:
    usize n_{}, comps_{};
    std::vector<i32> data_;
};

} // namespace zawa
