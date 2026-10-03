#pragma once

#include <cassert>
#include <vector>

#include "FPS.hpp"
#include "BostanMori.hpp"

namespace zawa {

template <concepts::IndexedFPS FPS, class Conv = FPSMult>
typename FPS::value_type KthTerm(u64 K, FPS A, FPS C, Conv conv = {}) {
    if (K < A.size()) 
        return A[K];
    assert(C.size() >= 2 and C[0] == 0);
    assert(A.size() >= C.size() - 1);
    for (auto& v : C)
        v = -v;
    C[0] = 1;
    FPS multed = conv(A, C);
    multed.resize(C.size() - 1);
    return BostanMori(K, multed, C, conv);
}

} // namespace zawa
