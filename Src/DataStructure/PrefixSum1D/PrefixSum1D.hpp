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
    std::vector<T> dat;

    constexpr bool rangeCheck(u32 l, u32 r) const {
        return (l <= r and r < dat.size());
    }

public:
    PrefixSum1D() = default; 
    PrefixSum1D(const std::vector<T>& A) : dat(A.size() + 1, Group::identity()) {
        dat.shrink_to_fit();
        for (u32 i = 0 ; i < A.size() ; i++) {
            dat[i + 1] = Group::operation(dat[i], A[i]);
        }
    }

    inline T operator[](u32 i) const {
        assert(i < dat.size());
        return dat[i];
    }

    inline usize size() const {
        return dat.size();
    }

    T product(u32 l, u32 r) const {
        assert(rangeCheck(l, r));
        return Group::operation(Group::inverse(dat[l]), dat[r]);
    }

    u32 lowerBound(u32 l, u32 r, const T& v) const {
        assert(rangeCheck(l, r));
        T value = Group::operation(v, dat[l]);
        return std::lower_bound(dat.begin() + l, dat.begin() + r, value) - dat.begin();
    }

    u32 upperBound(u32 l, u32 r, const T& v) const {
        assert(rangeCheck(l, r));
        T value = Group::operation(v, dat[l]);
        return std::upper_bound(dat.begin() + l, dat.begin() + r, value) - dat.begin();
    }

    template <class F>
    u32 maxRight(u32 l, const F& f) const {
        static_assert(std::is_same_v<bool, std::invoke_result_t<decltype(f), T>> == true, "result type must be bool");
        assert(l < dat.size());
        assert(f(Group::identity()));
        auto f_ = [&](const T& v) -> bool {
            return f(Group::operation(v, Group::inverse(dat[l])));
        };
        return std::partition_point(dat.begin() + l, dat.end(), f_) - dat.begin();
    }

    template <class F>
    u32 minLeft(u32 r, const F& f) const {
        static_assert(std::is_same_v<bool, std::invoke_result_t<decltype(f), T>> == true, "result type must be bool");
        assert(r < dat.size());
        assert(f(Group::identity()));
        auto f_ = [&](const T& v) -> bool {
            return f(Group::operation(Group::inverse(v), dat[r]));
        };
        return dat.rend() - std::partition_point(dat.rbegin() + (dat.size() - r - 1), dat.rend(), f_) - 1;
    }
};

} // namespace zawa
