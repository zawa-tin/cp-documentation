#pragma once

#include <cassert>
#include <iterator>
#include <set>
#include <utility>

#include "../../Template/TypeAlias.hpp"

namespace zawa {

template <class S>
class SortedAdjacentProduct {
public:
    using V = typename S::Element;
    using Iterator = typename std::multiset<V>::const_iterator;

    SortedAdjacentProduct() = default;

    SortedAdjacentProduct(const SortedAdjacentProduct<S>& sap) 
        : set_{sap.set_}, adj_{sap.adj_} {}

    SortedAdjacentProduct(SortedAdjacentProduct<S>&& sap)
        : set_{std::move(sap.set_)}, adj_{std::move(sap.adj_)} {}

    inline usize size() const noexcept {
        return set_.size();
    }

    inline bool empty() const noexcept {
        return set_.empty();
    }

    const std::multiset<V>& set() const noexcept {
        return set_;
    }

    const std::multiset<V>& adjacents() const noexcept {
        return adj_;
    }

    V min() const noexcept {
        assert(size() >= usize{2});
        return *adj_.cbegin();
    }

    V max() const noexcept {
        assert(size() >= usize(2));
        return *adj_.crbegin();
    }

    void insert(const V& v) {
        Iterator it{set_.lower_bound(v)};
        if (it != set_.end() and it != set_.begin()) {
            V val{S::operation(*std::prev(it), *it)};
            assert(eraseAdj(val));
        }
        if (it != set_.end()) {
            adj_.insert(S::operation(v, *it));
        }
        if (it != set_.begin()) {
            adj_.insert(S::operation(*std::prev(it), v));
        }
        set_.insert(v);
    }

    void erase(const V& v) {
        auto it{set_.lower_bound(v)};
        assert(it != set_.end() and *it == v);
        if (it != set_.begin()) {
            V val{S::operation(*std::prev(it), *it)};
            assert(eraseAdj(val));
        }
        if (std::next(it) != set_.end()) {
            V val{S::operation(*it, *std::next(it))};
            assert(eraseAdj(val));
        }
        if (it != set_.begin() and std::next(it) != set_.end()) {
            V val{S::operation(*std::prev(it), *std::next(it))};
            adj_.insert(val);
        }
        set_.erase(it);
    }

    bool contains(const V& v) {
        return set_.find(v) != set_.end();
    }

private:
    std::multiset<V> set_, adj_;

    bool eraseAdj(const V& v) {
        auto it{adj_.find(v)};
        bool res{it != adj_.end()};
        if (res) adj_.erase(it);
        return res;
    }
};

} // namespace zawa
