#pragma once

#include "../../Template/TypeAlias.hpp"

#include <cmath>
#include <vector>
#include <cassert>
#include <algorithm>
#include <type_traits>

namespace zawa {

template <class Group>
class PrefixSum1D {
private:
    using T = typename Group::Element;
    std::vector<T> dat_;

    constexpr bool rangeCheck(u32 l, u32 r) const {
        return (l <= r and r < dat_.size());
    }

public:
    PrefixSum1D() = default; 
    PrefixSum1D(const std::vector<T>& A) : dat_(A.size() + 1, Group::identity()) {
        dat_.shrink_to_fit();
        for (u32 i = 0 ; i < A.size() ; i++) {
            dat_[i + 1] = Group::operation(dat_[i], A[i]);
        }
    }

    inline T operator[](u32 i) const {
        assert(i < dat_.size());
        return dat_[i];
    }

    inline usize size() const {
        return dat_.size();
    }

    T product(u32 l, u32 r) const {
        assert(rangeCheck(l, r));
        return Group::operation(Group::inverse(dat_[l]), dat_[r]);
    }

    u32 lowerBound(u32 l, u32 r, const T& v) const {
        assert(rangeCheck(l, r));
        T value = Group::operation(v, dat_[l]);
        return std::lower_bound(dat_.begin() + l, dat_.begin() + r, value) - dat_.begin();
    }

    u32 upperBound(u32 l, u32 r, const T& v) const {
        assert(rangeCheck(l, r));
        T value = Group::operation(v, dat_[l]);
        return std::upper_bound(dat_.begin() + l, dat_.begin() + r, value) - dat_.begin();
    }

    template <class F>
    u32 maxRight(u32 l, const F& f) const {
        static_assert(std::is_convertible_v<decltype(f), std::function<bool(T)>>, "f must work as bool(T)");
        assert(l < dat_.size());
        assert(f(Group::identity()));
        auto f_ = [&](const T& v) -> bool {
            return f(Group::operation(v, Group::inverse(dat_[l])));
        };
        return std::partition_point(dat_.begin() + l, dat_.end(), f_) - dat_.begin();
    }

    template <class F>
    u32 minLeft(u32 r, const F& f) const {
        static_assert(std::is_convertible_v<decltype(f), std::function<bool(T)>>, "f must work as bool(T)");
        assert(r < dat_.size());
        assert(f(Group::identity()));
        auto f_ = [&](const T& v) -> bool {
            return f(Group::operation(Group::inverse(v), dat_[r]));
        };
        return dat_.rend() - std::partition_point(dat_.rbegin() + (dat_.size() - r - 1), dat_.rend(), f_) - 1;
    }

    const auto begin() const {
        return dat_.begin();
    }

    const auto end() const {
        return dat_.end();
    }
};

} // namespace zawa
