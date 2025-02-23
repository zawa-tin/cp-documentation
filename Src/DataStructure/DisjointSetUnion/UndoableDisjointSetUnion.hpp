#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../Undoable/UndoableValue.hpp"
#include "../Undoable/UndoableVector.hpp"

#include <algorithm>
#include <cassert>

namespace zawa {

class UndoableDisjointSetUnion {
public:
    UndoableDisjointSetUnion() = default;

    UndoableDisjointSetUnion(usize n) : n_{n}, comps_{n}, data_(n, -1) {}

    u32 leader(u32 v) const {
        return data_[v] < 0 ? v : leader(data_[v]);
    }

    inline usize size() const noexcept {
        return n_;
    }

    inline usize size(u32 v) const {
        assert(v < size());
        return static_cast<usize>(-data_[leader(v)]);
    }

    inline usize components() const noexcept {
        return comps_.value();
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
            comps_.assign(comps_.value());
            return false;
        }
        else {
            if (data_[u] > data_[v]) std::swap(u, v);
            data_.assign(u, data_[u] + data_[v]);
            data_.assign(v, u);
            comps_.assign(comps_.value() - 1);
            return true;
        }
    }

    void undo() {
        data_.undo();
        data_.undo();
        comps_.undo();
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
    UndoableValue<usize> comps_{};
    UndoableVector<i32> data_{};
};

} // namespace zawa
