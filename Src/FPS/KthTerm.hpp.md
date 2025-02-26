---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/tdpc_fibonacci.test.cpp
    title: Test/Manual/tdpc_fibonacci.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/FPS/KthTerm.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 7 \"Src/FPS/KthTerm.hpp\"\
    \n\nnamespace zawa {\n\nnamespace internal {\n\n// [x^K] P(x) / Q(x)\u3092\u8A08\
    \u7B97\u3059\u308B\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\ntemplate <class T, class\
    \ F>\nT BostanMori(u64 K, std::vector<T> P, std::vector<T> Q, F mult) {\n    assert(P.size());\n\
    \    assert(Q.size() and Q[0] != T(0));\n\n    // p(-x)\u3092\u8A08\u7B97\n  \
    \  auto minus_x{[](const std::vector<T>& p) -> std::vector<T> {\n        std::vector<T>\
    \ res(p.size()); \n        for (usize i{} ; i < p.size() ; i++) res[i] = (i %\
    \ 2 ? T{-1} * p[i] : p[i]);\n        return res;\n    }};\n    // \u5947\u6570\
    \u6B21\u6570\u306E\u4FC2\u6570\u306E\u307F\u3092\u53D6\u308A\u51FA\u3059\n   \
    \ auto odd{[](const std::vector<T>& p) -> std::vector<T> {\n        std::vector<T>\
    \ res;\n        res.reserve(p.size() >> 1);\n        for (usize i{1} ; i < p.size()\
    \ ; i += 2u) res.push_back(p[i]);\n        return res;\n    }};\n    // \u5076\
    \u6570\u6B21\u6570\u306E\u4FC2\u6570\u306E\u307F\u3092\u53D6\u308A\u51FA\u3059\
    \n    auto even{[](const std::vector<T>& p) -> std::vector<T> {\n        std::vector<T>\
    \ res;\n        res.reserve((p.size() & 1) + (p.size() >> 1));\n        for (usize\
    \ i{} ; i < p.size() ; i += 2u) res.push_back(p[i]);\n        return res;\n  \
    \  }};\n\n    while (K) {\n        auto Qm{minus_x(Q)};\n        auto U{mult(P,\
    \ Qm)};\n        P = (K & 1 ? odd(U) : even(U));\n        Q = even(mult(Q, Qm));\n\
    \        K >>= 1;\n    }\n    return (Q[0] == T{1} ? P[0] : P[0] / Q[0]);\n}\n\
    \n} // namespace internal\n\ntemplate <class T, class F>\nT KthTerm(u64 K, std::vector<T>\
    \ A, std::vector<T> C, F mult) {\n    assert(A.size() + 1u >= C.size());\n   \
    \ if (K < A.size()) return A[K];\n    std::vector<T> tmp(C.size() + 1, T{1});\n\
    \    for (usize i{} ; i < C.size() ; i++) {\n        tmp[i + 1] = -C[i];\n   \
    \ }\n    C = std::move(tmp);\n    A.resize(C.size() - 1);\n    A = mult(A, C);\n\
    \    A.resize(C.size() - 1);\n    return internal::BostanMori(K, A, C, mult);\n\
    }\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../Template/TypeAlias.hpp\"\
    \n\nnamespace zawa {\n\nnamespace internal {\n\n// [x^K] P(x) / Q(x)\u3092\u8A08\
    \u7B97\u3059\u308B\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\ntemplate <class T, class\
    \ F>\nT BostanMori(u64 K, std::vector<T> P, std::vector<T> Q, F mult) {\n    assert(P.size());\n\
    \    assert(Q.size() and Q[0] != T(0));\n\n    // p(-x)\u3092\u8A08\u7B97\n  \
    \  auto minus_x{[](const std::vector<T>& p) -> std::vector<T> {\n        std::vector<T>\
    \ res(p.size()); \n        for (usize i{} ; i < p.size() ; i++) res[i] = (i %\
    \ 2 ? T{-1} * p[i] : p[i]);\n        return res;\n    }};\n    // \u5947\u6570\
    \u6B21\u6570\u306E\u4FC2\u6570\u306E\u307F\u3092\u53D6\u308A\u51FA\u3059\n   \
    \ auto odd{[](const std::vector<T>& p) -> std::vector<T> {\n        std::vector<T>\
    \ res;\n        res.reserve(p.size() >> 1);\n        for (usize i{1} ; i < p.size()\
    \ ; i += 2u) res.push_back(p[i]);\n        return res;\n    }};\n    // \u5076\
    \u6570\u6B21\u6570\u306E\u4FC2\u6570\u306E\u307F\u3092\u53D6\u308A\u51FA\u3059\
    \n    auto even{[](const std::vector<T>& p) -> std::vector<T> {\n        std::vector<T>\
    \ res;\n        res.reserve((p.size() & 1) + (p.size() >> 1));\n        for (usize\
    \ i{} ; i < p.size() ; i += 2u) res.push_back(p[i]);\n        return res;\n  \
    \  }};\n\n    while (K) {\n        auto Qm{minus_x(Q)};\n        auto U{mult(P,\
    \ Qm)};\n        P = (K & 1 ? odd(U) : even(U));\n        Q = even(mult(Q, Qm));\n\
    \        K >>= 1;\n    }\n    return (Q[0] == T{1} ? P[0] : P[0] / Q[0]);\n}\n\
    \n} // namespace internal\n\ntemplate <class T, class F>\nT KthTerm(u64 K, std::vector<T>\
    \ A, std::vector<T> C, F mult) {\n    assert(A.size() + 1u >= C.size());\n   \
    \ if (K < A.size()) return A[K];\n    std::vector<T> tmp(C.size() + 1, T{1});\n\
    \    for (usize i{} ; i < C.size() ; i++) {\n        tmp[i + 1] = -C[i];\n   \
    \ }\n    C = std::move(tmp);\n    A.resize(C.size() - 1);\n    A = mult(A, C);\n\
    \    A.resize(C.size() - 1);\n    return internal::BostanMori(K, A, C, mult);\n\
    }\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/FPS/KthTerm.hpp
  requiredBy: []
  timestamp: '2024-11-13 00:58:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Manual/tdpc_fibonacci.test.cpp
  - Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: Src/FPS/KthTerm.hpp
layout: document
title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u306EK\u9805\u76EE\u3092\u8A08\u7B97\u3059\u308B"
---

## 概要

漸化式 $a_{n} = \sum_{i = 1}^{d} c_{i}a_{n - i}$ の $K$ 項目を計算する。

## ライブラリの使い方

```
template <class T, class F>
T KthTerm(u64 K, std::vector<T> A, std::vector<T> C, F mult)
```

#### T (template)

基本的にはmintを入れることになるだろう。

コピペ禁止コンテストなどでmintを使えない場合は、**中身のライブラリの演算をmodを取るように書き換える**必要がある。

#### K

求めたい項、非負整数。

#### A

漸化式の始め $d$ 項 $(A_{0}, A_{1}, \dots, A_{d - 1})$ 、 $A_{d}$ 以降が混じっていても問題ないが、反対に項数が足りないとassertにひっかかる。

#### C

線形漸化式の係数

#### mult

多項式の掛け算を行い、結果を返す関数。

```cpp
[](const auto& L, const auto& R) {
    return atcoder::convolution(L, R);
}
```

```cpp
[](const auto& L, const auto& R) {
    if (L.empty() or R.empty()) return std::vector<mint>{};
    std::vector<mint> res(L.size() + R.size() - 1);
    for (size_t i{} ; i < L.size() ; i++) for (size_t j{} ; j < R.size() ; j++) {
        res[i + j] += L[i] * R[j];
    }
    return res;
}
```

基本的には以上のどちらかで事足りるハズ。

## 計算量解析

`mult`を $\Theta(\log K)$ 回呼び出すのがボトルネック

- `mult`で前者の例を使うと $\Theta (d\log d\log K)$ 
- `mult`で後者の例を使うと $\Theta (d^2 \log K)$

## 補足

内部で[Bostan-Moriアルゴリズム](https://q.c.titech.ac.jp/docs/progs/polynomial_division.html)が走っている。

線形漸化式の $K$ 番目を求めるアルゴリズムとして、

$$ \begin{pmatrix}
0, 1, 0, \cdots, 0 \\
0, 0, 1, \cdots, 0 \\
\vdots \\
0, 0, 0, \cdots, 1 \\
C_{d}, C_{d - 1}, C_{d - 2}, \cdots, C{1} \\
\end{pmatrix} $$

の $K$ 乗を計算する方法(行列累乗)が有名だが、これの時間計算量は $\Theta (d^3 \log K)$ と見積もれる。

このライブラリの`mult`に愚直を使ったやつよりも計算量が劣っていることに注意(貼れるときはちゃんと貼ろう)

勉強不足故、[定数倍の良い実装の方針](https://qiita.com/ryuhe1/items/c18ddbb834eed724a42b)をまだ採用していない。定数倍バトルになったらおとなしく別ライブラリを探そう...
