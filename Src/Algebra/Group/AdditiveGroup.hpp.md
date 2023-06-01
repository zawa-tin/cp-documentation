---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/aplusb.test.cpp
    title: Test/LC/aplusb.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n    using valueType\
    \ = T;\n    static constexpr T identity() noexcept {\n        return T{};\n  \
    \  }\n    static constexpr T operation(const T& l, const T& r) noexcept {\n  \
    \      return l + r;\n    }\n    static constexpr T inverse(const T& v) noexcept\
    \ {\n        return -v;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup\
    \ {\npublic:\n    using valueType = T;\n    static constexpr T identity() noexcept\
    \ {\n        return T{};\n    }\n    static constexpr T operation(const T& l,\
    \ const T& r) noexcept {\n        return l + r;\n    }\n    static constexpr T\
    \ inverse(const T& v) noexcept {\n        return -v;\n    }\n};\n\n} // namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Group/AdditiveGroup.hpp
  requiredBy: []
  timestamp: '2023-06-02 02:19:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/aplusb.test.cpp
documentation_of: Src/Algebra/Group/AdditiveGroup.hpp
layout: document
title: "\u52A0\u6CD5\u7FA4"
---

# 概要

本ライブラリの群を要求するデータ構造で加法を扱いたい時に使用します。

<br />

## 機能

実装の詳細は[本ライブラリでの群の実装について]({ site.baseurl }}/Docs/Appendix/Group.md)を確認してください。

<br />

## 制約

テンプレート引数に入れる型、クラスが以下の条件を満たす必要があります。
- デフォルトコンストラクタが加法の単位元である。
- 加算の二項演算子`+`が定義されている。
- 単項否定演算子`-`の`operator`が定義されていて、加法の逆元を返すものになっている。
- 演算が群の条件を満たす。
