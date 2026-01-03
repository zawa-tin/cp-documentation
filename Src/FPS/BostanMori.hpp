#pragma once

#include "FPS.hpp"

namespace zawa {

template <concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
typename FPS::value_type BostanMori(usize N, FPS P, FPS Q, Conv conv = {}) {
    assert(P.size());
    assert(Q.size() and Q[0] != 0); 
    auto takeParity = [&](const FPS& f, usize p) {
        FPS res;
        res.reserve(f.size() / 2);
        for (usize i = p ; i < f.size() ; i += 2)
            res.push_back(f[i]);
        return res;
    };
    while (N) {
        FPS Qm(Q.size());
        for (usize i = 0 ; i < Q.size() ; i++)
            Qm[i] = i % 2 ? -Q[i] : Q[i];
        P = takeParity(conv(P, Qm), N % 2);
        Q = takeParity(conv(Q, Qm), 0);
        N >>= 1;
    }
    return P[0] / Q[0];
}

} // namespace zawa
