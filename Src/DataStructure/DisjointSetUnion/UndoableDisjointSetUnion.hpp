#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../Undoable/UndoableVector.hpp"

#include <algorithm>
#include <cassert>

namespace zawa {

class UndoableDisjointSetUnion {
public:
    UndoableDisjointSetUnion() = default;

    UndoableDisjointSetUnion(usize n) : n_{n}, data_(n, -1) {}

    u32 leader(u32 v) const {
        return data_[v] < 0 ? v : leader(data_[v]);
    }

    inline usize size() const {
        return n_;
    }

    inline usize size(u32 v) const {
        assert(v < size());
        return static_cast<usize>(-data_[leader(v)]);
    }

    bool same(u32 u, u32 v) const {
        assert(u < size());
        assert(v < size());
        return leader(u) == leader(v);
    }

    bool merge(u32 u, u32 v) {
        u = leader(u);
        v = leader(v);
        if (u == v) {
            data_.assign(u, data_[u]);
            data_.assign(v, data_[v]);
            return false;
        }
        else {
            if (data_[u] > data_[v]) std::swap(u, v);
            data_.assign(u, data_[u] + data_[v]);
            data_.assign(v, u);
            return true;
        }
    }

    void undo() {
        data_.undo();
        data_.undo();
    }

    std::vector<std::vector<u32>> enumerate() const {
        std::vector<std::vector<u32>> res(n_);
        for (u32 v{} ; v < n_ ; v++) {
            res[leader(v)].push_back(v);
        }
        res.erase(std::remove_if(res.begin(), res.end(),
                    [](const auto& arr) -> bool { return arr.empty(); }), res.end());
        return res;
    }

private:
    usize n_{};
    UndoableVector<i32> data_{};
};

} // namespace zawa
