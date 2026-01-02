#pragma once

#include <cassert>
#include <vector>

#include "FPSNTTFriendly.hpp"
#include "BostanMori.hpp"

namespace zawa {

template <concepts::IndexedFPS FPS, class Conv = FPSMult>
typename FPS::value_type KthTerm(u64 K, FPS A, FPS C, Conv conv = {}) {
    assert(C.size() >= 2 and C[0] == 0);
    assert(A.size() >= C.size() - 1);
    if (K < A.size()) 
        return A[K];
    for (auto& v : C)
        v = -v;
    C[0] = 1;
    FPS multed = conv(A, C);
    multed.resize(C.size() - 1);
    return BostanMori(K, multed, C, conv);
}

} // namespace zawa
