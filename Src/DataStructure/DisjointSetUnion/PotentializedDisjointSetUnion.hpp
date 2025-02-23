#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

namespace zawa {

template <class Group>
class PotentializedDisjointSetUnion {
public:
    using Value = typename Group::Element;
private:
    usize n_{}, comps_{};
    std::vector<u32> parent_{};
    std::vector<u32> size_{};
    std::vector<Value> potential_{};

    u32 leader(u32 v) {
        if (parent_[v] == v) {
            return v;
        }
        else {
            u32 res{leader(parent_[v])};
            potential_[v] = Group::operation(potential_[parent_[v]], potential_[v]);
            return parent_[v] = res;
        }
    }
    Value potential(u32 v) {
        leader(v);
        return potential_[v];
    }

public:

    PotentializedDisjointSetUnion() = default;

    PotentializedDisjointSetUnion(u32 n) 
        : n_{n}, comps_{n}, parent_(n), size_(n, u32{1}), potential_(n, Group::identity()) {
        std::iota(parent_.begin(), parent_.end(), u32{});
    }

    constexpr u32 size() const noexcept {
        return n_;
    }

    u32 size(u32 v) {
        leader(v);
        return size_[v];
    }

    inline u32 components() const noexcept {
        return comps_;
    }

    bool isDefined(u32 u, u32 v) {
        return leader(u) == leader(v);
    }

    Value distance(u32 u, u32 v) {
        assert(u < size());
        assert(v < size());
        return Group::operation(Group::inverse(potential(u)), potential(v));
    }

    bool merge(u32 u, u32 v, Value value) {
        if (isDefined(u, v)) {
            return distance(u, v) == value;
        }
        comps_--;
        value = Group::operation(potential(u), value);
        value = Group::operation(Group::inverse(potential(v)), value);
        u = leader(u);
        v = leader(v);
        if (size_[u] > size_[v]) {
            value = Group::inverse(value);
            std::swap(u, v);
        }
        size_[u] += size_[v];
        parent_[v] = u;
        potential_[v] = value;
        return true;
    }
};

} // namespace zawa
