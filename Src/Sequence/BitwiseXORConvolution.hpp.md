---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/3568.test.cpp
    title: Test/AOJ/3568.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc212_h.test.cpp
    title: Test/AtCoder/abc212_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc396_g.test.cpp
    title: ABC396-G Flip Row or Col
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc222_e.test.cpp
    title: Test/AtCoder/arc222_e.test.cpp
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
    \ b[i] = static_cast<T>(std::move(B[i]));\n    return BitwiseXORConvolution<T>(std::move(a),\
    \ std::move(b));\n}\n\ntemplate <class T>\nstd::vector<T> BitwiseXORConvolutionPower(std::vector<T>\
    \ A,usize K) {\n    FastWalshHadamardTransform(A);\n    auto mypow=[K](T x) ->\
    \ T {\n        T res = 1;\n        for (usize k = K ; k ; k >>= 1) {\n       \
    \     if (k & 1)\n                res *= x;\n            if (k > 1)\n        \
    \        x *= x;\n        }\n        return res;\n    };\n    for (usize i = 0\
    \ ; i < A.size() ; i++)\n        A[i] = mypow(A[i]);\n    FastWalshHadamardTransform(A);\n\
    \    if (A.empty()) \n        return A;\n    assert(std::has_single_bit(A.size()));\n\
    \    if constexpr (std::integral<T>) {\n        const usize d = std::bit_width(A.size())\
    \ - 1;\n        for (auto& a : A) \n            a >>= d;\n    }\n    else {\n\
    \        const T d = [&]() {\n            assert(std::has_single_bit(A.size()));\n\
    \            usize exp = std::bit_width(A.size()) - 1;\n            T v = T{1}\
    \ / T{2}, res = T{1};\n            while (exp) {\n                if (exp & 1)\
    \ \n                    res = res * v;\n                v = v * v;\n         \
    \       exp >>= 1;\n            }\n            return res;\n        }();\n   \
    \     for (T& a : A) \n            a *= d;\n    }\n    return A;\n}\n\ntemplate\
    \ <class T,class U>\nrequires (!std::same_as<T, U> and std::convertible_to<U,\
    \ T>)\nstd::vector<T> BitwiseXORConvolutionPower(std::vector<U> A,usize K) {\n\
    \    std::vector<T> a(A.size());\n    for (usize i = 0 ; i < A.size() ; i++)\n\
    \        a[i] = static_cast<T>(A[i]);\n    return BitwiseXORConvolutionPower(a,K);\n\
    }\n\n} // namespace zawa\n"
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
    \ b[i] = static_cast<T>(std::move(B[i]));\n    return BitwiseXORConvolution<T>(std::move(a),\
    \ std::move(b));\n}\n\ntemplate <class T>\nstd::vector<T> BitwiseXORConvolutionPower(std::vector<T>\
    \ A,usize K) {\n    FastWalshHadamardTransform(A);\n    auto mypow=[K](T x) ->\
    \ T {\n        T res = 1;\n        for (usize k = K ; k ; k >>= 1) {\n       \
    \     if (k & 1)\n                res *= x;\n            if (k > 1)\n        \
    \        x *= x;\n        }\n        return res;\n    };\n    for (usize i = 0\
    \ ; i < A.size() ; i++)\n        A[i] = mypow(A[i]);\n    FastWalshHadamardTransform(A);\n\
    \    if (A.empty()) \n        return A;\n    assert(std::has_single_bit(A.size()));\n\
    \    if constexpr (std::integral<T>) {\n        const usize d = std::bit_width(A.size())\
    \ - 1;\n        for (auto& a : A) \n            a >>= d;\n    }\n    else {\n\
    \        const T d = [&]() {\n            assert(std::has_single_bit(A.size()));\n\
    \            usize exp = std::bit_width(A.size()) - 1;\n            T v = T{1}\
    \ / T{2}, res = T{1};\n            while (exp) {\n                if (exp & 1)\
    \ \n                    res = res * v;\n                v = v * v;\n         \
    \       exp >>= 1;\n            }\n            return res;\n        }();\n   \
    \     for (T& a : A) \n            a *= d;\n    }\n    return A;\n}\n\ntemplate\
    \ <class T,class U>\nrequires (!std::same_as<T, U> and std::convertible_to<U,\
    \ T>)\nstd::vector<T> BitwiseXORConvolutionPower(std::vector<U> A,usize K) {\n\
    \    std::vector<T> a(A.size());\n    for (usize i = 0 ; i < A.size() ; i++)\n\
    \        a[i] = static_cast<T>(A[i]);\n    return BitwiseXORConvolutionPower(a,K);\n\
    }\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/BitwiseXORConvolution.hpp
  requiredBy: []
  timestamp: '2026-10-22 16:38:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/3568.test.cpp
  - Test/AtCoder/abc212_h.test.cpp
  - Test/AtCoder/arc222_e.test.cpp
  - Test/AtCoder/abc396_g.test.cpp
  - Test/LC/bitwise_xor_convolution.test.cpp
documentation_of: Src/Sequence/BitwiseXORConvolution.hpp
layout: document
title: Bitwise XOR Convolution
---

## 概要

### Bitwise XOR Convolution

```
template <class T>
std::vector<T> BitwiseXORConvolution(std::vector<T> A, std::vector<T> B) (1)

template <class T, class U>
requires (!std::same_as<T, U> and std::convertible_to<U, T>)
std::vector<T> BitwiseXORConvolution(std::vector<U> A, std::vector<U> B) (2)
```

長さ $2^N$ の(標数が $2$ でない)体上の列 $a,b$ に対して $c_{i}=\sum_{j\oplus k=i} a_{j}b_{k}$ を満たす列 $c$ を $O(N2^N)$ で計算する。

最終結果が型の範囲に収まっていても、計算途中でオーバフローする可能性が高い。**特に、`int`などの32bit整数の使用は推奨されない**

長さが $2^N$ でないときは、そのようなサイズになるまで後ろに $0$ 埋めがなされる。空列は空列のままかえす。

### XOR畳み込みの $K$ 乗

```
template <class T>
std::vector<T> BitwiseXORConvolutionPower(std::vector<T> A,usize K) (1)

template <class T,class U>
requires (!std::same_as<T, U> and std::convertible_to<U, T>)
std::vector<T> BitwiseXORConvolutionPower(std::vector<U> A,usize K)  (2)
```

$A$ をbitwise XOR 畳み込みで $K$ 乗する。なお $0$ 乗は(非空列のとき) $(1,0,0,0,\dots,0)$ と定義される。

こちらの計算量は $O((N+\log (K+1))2^N)$ 。

長さが $2^N$ でないときは、そのようなサイズになるまで後ろに $0$ 埋めがなされる。空列は空列のままかえす。

#### 高速Hadamard変換

```
// note: each values are multiplied by 2^{k/2} than truth value
template <class T>
void FastWalshHadamardTransform(std::vector<T>& A) 
```

XOR畳み込みは

1. $a,b$ をHadamard変換し、 $a',b'$ を得る。
2. $a',b'$ の各点積を取って $c'$ を得る。
3. $c'$ をHadamard変換して $c$ を得る。ただし実装上の都合で各点の値が $2^N$ 倍されている

という風に実装されている。

問題によってはこのHadamard変換を呼び出す回数を減らせたり、減らすことを要求してきたりする。例えば

- $K$ 乗する $\leftarrow$ $O(\log K)$ 回XOR畳み込みをするのではなく、$a'$ の各点を $K$ 乗して戻せば2回の変換で済む
- $a^0+a^1+ \cdots +a^K$ を求める( [ABC212-H](https://atcoder.jp/contests/abc212/tasks/abc212_h) ) $\leftarrow$ これも各点を等比数列の公式にしたがって変換すれば2回の変換で済む

といった例がある。

自分でそういったテクニックをする場合、`FastWalshHadamardTransform`を二回適用すると、各点の値が元の列の値の $2^N$ 倍になることに注意。変換 $\rightarrow$ 積を取る $\rightarrow$ 変換 の後は各点を $2^N$ で割る必要がある

## 参考

- [xor畳み込みと高速Hadamard変換](https://qiita.com/izu_nori/items/7810fc2bc0423c8d407f)
- [Fast Walsh Hadamard Transform (高速ウォルシュアダマール変換)](https://ei1333.github.io/library/math/fft/fast-walsh-hadamard-transform.hpp.html)

## 更新履歴

- 2025/06/02: 作成
- 2025/10/17: 日本語のコメントを英語にした
- 2026/10/22: verifyを増やした、 $K$ 乗専用の機能を作った、ドキュメントの刷新
