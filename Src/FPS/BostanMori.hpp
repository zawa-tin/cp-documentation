#pragma once

#include "FPSNTTFriendly.hpp"

namespace zawa {

template <usize MOD = 998244353>
typename FPSNTTFriendly<MOD>::V BostanMori(usize N, FPSNTTFriendly<MOD> P, FPSNTTFriendly<MOD> Q) {
    assert(P.size());
    assert(Q.size() and Q[0] != 0); 
    auto takeParity = [&](const FPSNTTFriendly<MOD>& f, usize p) {
        FPSNTTFriendly<MOD> res;
        res.reserve(f.size() / 2);
        for (usize i = p ; i < f.size() ; i += 2)
            res.push_back(f[i]);
        return res;
    };
    while (N) {
        FPSNTTFriendly<MOD> Qm(Q.size());
        for (usize i = 0 ; i < Q.size() ; i++)
            Qm[i] = i % 2 ? -Q[i] : Q[i];
        P = takeParity(P * Qm, N % 2);
        Q = takeParity(Q * Qm, 0);
        N >>= 1;
    }
    return P[0] / Q[0];
}

} // namespace zawa
