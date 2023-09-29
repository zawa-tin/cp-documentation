---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp
    title: "\u9759\u7684\u306A\u5217\u4E0A\u306E\u533A\u9593\u548C\u30AF\u30A8\u30EA"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_B.test.cpp
    title: Test/AOJ/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc172_c.test.cpp
    title: ABC172-C Tsundoku
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc229_d.test.cpp
    title: ABC229-D Longest X
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc276_f.test.cpp
    title: Test/AtCoder/abc276_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/agc023_a.test.cpp
    title: AGC023-A Zero-Sum Ranges
  - icon: ':heavy_check_mark:'
    path: Test/LC/aplusb.test.cpp
    title: Test/LC/aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_range_sum.test.cpp
    title: Test/LC/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/static_range_sum.test.cpp
    title: Test/LC/static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n    using Element =\
    \ T;\n    static constexpr T identity() noexcept {\n        return T{};\n    }\n\
    \    static constexpr T operation(const T& l, const T& r) noexcept {\n       \
    \ return l + r;\n    }\n    static constexpr T inverse(const T& v) noexcept {\n\
    \        return -v;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup\
    \ {\npublic:\n    using Element = T;\n    static constexpr T identity() noexcept\
    \ {\n        return T{};\n    }\n    static constexpr T operation(const T& l,\
    \ const T& r) noexcept {\n        return l + r;\n    }\n    static constexpr T\
    \ inverse(const T& v) noexcept {\n        return -v;\n    }\n};\n\n} // namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Group/AdditiveGroup.hpp
  requiredBy:
  - Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp
  timestamp: '2023-07-17 03:16:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/DSL_2_B.test.cpp
  - Test/AtCoder/abc229_d.test.cpp
  - Test/AtCoder/abc276_f.test.cpp
  - Test/AtCoder/abc172_c.test.cpp
  - Test/AtCoder/agc023_a.test.cpp
  - Test/LC/aplusb.test.cpp
  - Test/LC/static_range_sum.test.cpp
  - Test/LC/point_add_range_sum.test.cpp
documentation_of: Src/Algebra/Group/AdditiveGroup.hpp
layout: document
title: "\u52A0\u6CD5\u7FA4"
---

# 概要

本ライブラリの群を要求するデータ構造で加法を扱いたい時に使用します。

<br />

## 機能

実装の詳細は[本ライブラリでの群の実装について](https://zawa-tin.github.io/cp-documentation/Docs/Appendix/Group.html)を確認してください。

<br />

## 制約

テンプレート引数に入れる型、クラスが以下の条件を満たす必要があります。
- デフォルトコンストラクタが加法の単位元である。
- 加算の二項演算子`+`が定義されている。
- 単項否定演算子`-`の`operator`が定義されていて、加法の逆元を返すものになっている。
- 演算が群の条件を満たす。
