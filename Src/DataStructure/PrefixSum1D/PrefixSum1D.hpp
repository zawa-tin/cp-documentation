#pragma once

#include "../../Template/TypeAlias.hpp"

#include <cmath>
#include <vector>
#include <cassert>

namespace zawa {

template <class Group>
class PrefixSum1D {
private:
    using T = typename Group::ValueType;
    std::vector<T> dat;

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
        assert(l <= r);
        assert(r < dat.size());
        return Group::operation(Group::inverse(dat[l]), dat[r]);
    }

    template <class F>
    T maxRight(u32 l, const F& f) const {
        assert(l < dat.size());
        assert(f(Group::identity()));
        u32 itr = std::__lg(dat.size() - l) + 1;
        u32 res = l;
        for (i32 p = itr ; p >= 0 ; p--) {
            u32 r = res + (1 << p);
            if (r >= dat.size()) continue;
            if (not f(product(l, r))) continue;
            res = r;
        }
        return res;
    }

    template <class F>
    T minLeft(u32 r, const F& f) const {
        assert(r < dat.size());
        assert(f(Group::identity()));
        u32 itr = std::__lg(r) + 1;
        u32 res = r;
        for (i32 p = itr ; p >= 0 ; p--) {
            if ((1 << p) > res) continue;
            u32 l = res - (1 << p);
            if (not f(product(l, r))) continue;
            res = l;
        }
        return res;
    }
};

} // namespace zawa
