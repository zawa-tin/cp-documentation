#pragma once

#include "../../Template/TypeAlias.hpp"

#include <vector>
#include <cassert>

namespace zawa {

template <class Group>
class PrefixSums1D {
private:
    using T = typename Group::ValueType;
    std::vector<T> dat;

public:
    PrefixSums1D() = default; 
    PrefixSums1D(const std::vector<T>& A) : dat(A.size() + 1, Group::identity()) {
        dat.shrink_to_fit();
        for (u32 i = 0 ; i < A.size() ; i++) {
            dat[i + 1] = Group::operation(dat[i], A[i]);
        }
    }

    inline T operator[](u32 i) const {
        assert(i < dat.size());
        return dat[i];
    }

    T product(u32 l, u32 r) const {
        assert(l <= r and r < dat.size());
        return Group::operation(Group::inverse(dat[l]), dat[r]);
    }

    T maxRight(u32 l) const {

    }

    T minLeft(u32 r) const {

    }
};

} // namespace zawa
