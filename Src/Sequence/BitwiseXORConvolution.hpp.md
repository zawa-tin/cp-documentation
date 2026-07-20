---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc396_g.test.cpp
    title: ABC396-G Flip Row or Col
  - icon: ':heavy_check_mark:'
    path: Test/LC/bitwise_xor_convolution.test.cpp
    title: Test/LC/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/BitwiseXORConvolution.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/BitwiseXORConvolution.hpp\"\n\n\
    #include <bit>\n#include <concepts>\n#include <cassert>\n#include <vector>\n\n\
    namespace zawa {\n\n// note: each values are multed by 2^{k/2} than truth value\n\
    template <class T>\nvoid FastWalshHadamardTransform(std::vector<T>& A) {\n   \
    \ if (A.empty()) return;\n    while (!std::has_single_bit(A.size())) A.push_back(T{0});\n\
    \    const usize k = std::bit_width(A.size()) - 1, n = A.size();\n    for (usize\
    \ i = 0 ; i < k ; i++) {\n        const usize bit = 1 << i;\n        for (usize\
    \ j = 0 ; j < n ; j += bit << 1) {\n            for (usize k = 0 ; k < bit ; k++)\
    \ {\n                const T p = A[j + k], q = A[j + k + bit];\n             \
    \   A[j + k] = p + q;\n                A[j + k + bit] = p - q;\n            }\n\
    \        }\n    }\n}\n\ntemplate <class T>\nstd::vector<T> BitwiseXORConvolution(std::vector<T>\
    \ A, std::vector<T> B) {\n    FastWalshHadamardTransform(A);\n    FastWalshHadamardTransform(B);\n\
    \    if (A.size() > B.size()) std::swap(A, B);\n    for (usize i = 0 ; i < A.size()\
    \ ; i++) A[i] *= B[i];\n    FastWalshHadamardTransform(A);\n    if (A.empty())\
    \ return A;\n    assert(std::has_single_bit(A.size()));\n    if constexpr (std::integral<T>)\
    \ {\n        const usize d = std::bit_width(A.size()) - 1;\n        for (auto&\
    \ a : A) a >>= d;\n    }\n    else {\n        const T d = [&]() {\n          \
    \  assert(std::has_single_bit(A.size()));\n            usize exp = std::bit_width(A.size())\
    \ - 1;\n            T v = T{1} / T{2}, res = T{1};\n            while (exp) {\n\
    \                if (exp & 1) res = res * v;\n                v = v * v;\n   \
    \             exp >>= 1;\n            }\n            return res;\n        }();\n\
    \        for (T& a : A) a *= d;\n    }\n    return A;\n}\n\ntemplate <class T,\
    \ class U>\nrequires (!std::same_as<T, U> and std::convertible_to<U, T>)\nstd::vector<T>\
    \ BitwiseXORConvolution(std::vector<U> A, std::vector<U> B) {\n    std::vector<T>\
    \ a(A.size()), b(B.size());\n    for (usize i = 0 ; i < A.size() ; i++) a[i] =\
    \ static_cast<T>(std::move(A[i]));\n    for (usize i = 0 ; i < B.size() ; i++)\
    \ b[i] = static_cast<T>(std::move(B[i]));\n    return BitwiseXORConvolution<T>(a,\
    \ b);\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <bit>\n\
    #include <concepts>\n#include <cassert>\n#include <vector>\n\nnamespace zawa {\n\
    \n// note: each values are multed by 2^{k/2} than truth value\ntemplate <class\
    \ T>\nvoid FastWalshHadamardTransform(std::vector<T>& A) {\n    if (A.empty())\
    \ return;\n    while (!std::has_single_bit(A.size())) A.push_back(T{0});\n   \
    \ const usize k = std::bit_width(A.size()) - 1, n = A.size();\n    for (usize\
    \ i = 0 ; i < k ; i++) {\n        const usize bit = 1 << i;\n        for (usize\
    \ j = 0 ; j < n ; j += bit << 1) {\n            for (usize k = 0 ; k < bit ; k++)\
    \ {\n                const T p = A[j + k], q = A[j + k + bit];\n             \
    \   A[j + k] = p + q;\n                A[j + k + bit] = p - q;\n            }\n\
    \        }\n    }\n}\n\ntemplate <class T>\nstd::vector<T> BitwiseXORConvolution(std::vector<T>\
    \ A, std::vector<T> B) {\n    FastWalshHadamardTransform(A);\n    FastWalshHadamardTransform(B);\n\
    \    if (A.size() > B.size()) std::swap(A, B);\n    for (usize i = 0 ; i < A.size()\
    \ ; i++) A[i] *= B[i];\n    FastWalshHadamardTransform(A);\n    if (A.empty())\
    \ return A;\n    assert(std::has_single_bit(A.size()));\n    if constexpr (std::integral<T>)\
    \ {\n        const usize d = std::bit_width(A.size()) - 1;\n        for (auto&\
    \ a : A) a >>= d;\n    }\n    else {\n        const T d = [&]() {\n          \
    \  assert(std::has_single_bit(A.size()));\n            usize exp = std::bit_width(A.size())\
    \ - 1;\n            T v = T{1} / T{2}, res = T{1};\n            while (exp) {\n\
    \                if (exp & 1) res = res * v;\n                v = v * v;\n   \
    \             exp >>= 1;\n            }\n            return res;\n        }();\n\
    \        for (T& a : A) a *= d;\n    }\n    return A;\n}\n\ntemplate <class T,\
    \ class U>\nrequires (!std::same_as<T, U> and std::convertible_to<U, T>)\nstd::vector<T>\
    \ BitwiseXORConvolution(std::vector<U> A, std::vector<U> B) {\n    std::vector<T>\
    \ a(A.size()), b(B.size());\n    for (usize i = 0 ; i < A.size() ; i++) a[i] =\
    \ static_cast<T>(std::move(A[i]));\n    for (usize i = 0 ; i < B.size() ; i++)\
    \ b[i] = static_cast<T>(std::move(B[i]));\n    return BitwiseXORConvolution<T>(a,\
    \ b);\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/BitwiseXORConvolution.hpp
  requiredBy: []
  timestamp: '2025-10-17 20:47:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/bitwise_xor_convolution.test.cpp
  - Test/AtCoder/abc396_g.test.cpp
documentation_of: Src/Sequence/BitwiseXORConvolution.hpp
layout: document
title: Bitwise XOR Convolution
---

## 概要

長さ $N = 2^{K}$ の数列 $a, b$ に対して $\displaystyle c_{i} = \sum_{p, q, p\oplus q = i} a_{p}\times b_{q}$ を $O(N\log N)$ で計算する。

内部でWalsh-Hadamard Transformというものを用いている。愚直なTransformは低速で、これを用いても畳み込みの計算量は $\Theta (N^{2})$ から改善しない。しかし、Transformの式をぐっと睨むことにより高速化に成功する(俗に高速アダマール変換と呼ばれる)。

計算結果の値が小さいと見積もることができても、計算途中でオーバーフローする場合があるので、返り値の型には注意すること(例: ABC396-G)

## 参考

- [xor畳み込みと高速Hadamard変換](https://qiita.com/izu_nori/items/7810fc2bc0423c8d407f)
- [Fast Walsh Hadamard Transform (高速ウォルシュアダマール変換)](https://ei1333.github.io/library/math/fft/fast-walsh-hadamard-transform.hpp.html)
