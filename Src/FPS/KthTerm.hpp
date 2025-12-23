#pragma once

#include <cassert>
#include <vector>

#include "FPSNTTFriendly.hpp"
#include "BostanMori.hpp"

namespace zawa {


template <usize MOD = 998244353>
typename FPSNTTFriendly<MOD>::V KthTerm(u64 K, FPSNTTFriendly<MOD> A, FPSNTTFriendly<MOD> C) {
    assert(C.size() >= 2 and C[0] == 0);
    assert(A.size() >= C.size() - 1);
    if (K < A.size()) 
        return A[K];
    for (auto& v : C)
        v = -v;
    C[0] = 1;
    return BostanMori(K, (A * C).resized(C.size() - 1), C);
}

} // namespace zawa
