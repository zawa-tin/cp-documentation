#pragma once

#include <cassert>
#include <vector>

#include "../Template/TypeAlias.hpp"

namespace zawa {

namespace internal {

// compute [x^K] P(x) / Q(x)
template <class T, class F>
T BostanMori(u64 K, std::vector<T> P, std::vector<T> Q, F mult) {
    assert(P.size());
    assert(Q.size() and Q[0] != T(0));

    // compute p(-x)
    auto minus_x{[](const std::vector<T>& p) -> std::vector<T> {
        std::vector<T> res(p.size()); 
        for (usize i{} ; i < p.size() ; i++) res[i] = (i % 2 ? T{-1} * p[i] : p[i]);
        return res;
    }};
    // pick up coef of odd degree
    auto odd{[](const std::vector<T>& p) -> std::vector<T> {
        std::vector<T> res;
        res.reserve(p.size() >> 1);
        for (usize i{1} ; i < p.size() ; i += 2u) res.push_back(p[i]);
        return res;
    }};
    // pick up coef of even degree
    auto even{[](const std::vector<T>& p) -> std::vector<T> {
        std::vector<T> res;
        res.reserve((p.size() & 1) + (p.size() >> 1));
        for (usize i{} ; i < p.size() ; i += 2u) res.push_back(p[i]);
        return res;
    }};

    while (K) {
        auto Qm{minus_x(Q)};
        auto U{mult(P, Qm)};
        P = (K & 1 ? odd(U) : even(U));
        Q = even(mult(Q, Qm));
        K >>= 1;
    }
    return (Q[0] == T{1} ? P[0] : P[0] / Q[0]);
}

} // namespace internal

template <class T, class F>
T KthTerm(u64 K, std::vector<T> A, std::vector<T> C, F mult) {
    assert(A.size() + 1u >= C.size());
    if (K < A.size()) return A[K];
    std::vector<T> tmp(C.size() + 1, T{1});
    for (usize i{} ; i < C.size() ; i++) {
        tmp[i + 1] = -C[i];
    }
    C = std::move(tmp);
    A.resize(C.size() - 1);
    A = mult(A, C);
    A.resize(C.size() - 1);
    return internal::BostanMori(K, A, C, mult);
}

} // namespace zawa
