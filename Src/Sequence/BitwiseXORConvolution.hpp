#pragma once

#include "../Template/TypeAlias.hpp"

#include <bit>
#include <concepts>
#include <cassert>
#include <vector>

namespace zawa {

// note: 返り値の各点の値は真の値より(2^{k/2})倍されている
template <class T>
void FastWalshHadamardTransform(std::vector<T>& A) {
    if (A.empty()) return;
    while (!std::has_single_bit(A.size())) A.push_back(T{0});
    const usize k = std::bit_width(A.size()) - 1, n = A.size();
    for (usize i = 0 ; i < k ; i++) {
        const usize bit = 1 << i;
        for (usize j = 0 ; j < n ; j += bit << 1) {
            for (usize k = 0 ; k < bit ; k++) {
                const T p = A[j + k], q = A[j + k + bit];
                A[j + k] = p + q;
                A[j + k + bit] = p - q;
            }
        }
    }
}

template <class T>
std::vector<T> BitwiseXORConvolution(std::vector<T> A, std::vector<T> B) {
    FastWalshHadamardTransform(A);
    FastWalshHadamardTransform(B);
    if (A.size() > B.size()) std::swap(A, B);
    for (usize i = 0 ; i < A.size() ; i++) A[i] *= B[i];
    FastWalshHadamardTransform(A);
    if (A.empty()) return A;
    assert(std::has_single_bit(A.size()));
    if constexpr (std::integral<T>) {
        const usize d = std::bit_width(A.size()) - 1;
        for (auto& a : A) a >>= d;
    }
    else {
        const T d = [&]() {
            assert(std::has_single_bit(A.size()));
            usize exp = std::bit_width(A.size()) - 1;
            T v = T{1} / T{2}, res = T{1};
            while (exp) {
                if (exp & 1) res = res * v;
                v = v * v;
                exp >>= 1;
            }
            return res;
        }();
        for (T& a : A) a *= d;
    }
    return A;
}

template <class T, class U>
requires (!std::same_as<T, U> and std::convertible_to<U, T>)
std::vector<T> BitwiseXORConvolution(std::vector<U> A, std::vector<U> B) {
    std::vector<T> a(A.size()), b(B.size());
    for (usize i = 0 ; i < A.size() ; i++) a[i] = static_cast<T>(std::move(A[i]));
    for (usize i = 0 ; i < B.size() ; i++) b[i] = static_cast<T>(std::move(B[i]));
    return BitwiseXORConvolution<T>(a, b);
}

} // namespace zawa
