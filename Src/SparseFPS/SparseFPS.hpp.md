---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/Differential.hpp
    title: SparseFPS::Differential
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/Divide.hpp
    title: SparseFPS::Div
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/Exp.hpp
    title: SparseFPS::Exp
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/Integral.hpp
    title: SparseFPS::Integral
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/Inverse.hpp
    title: SparseFPS::Inv
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/Log.hpp
    title: SparseFPS::Log
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/Power.hpp
    title: SparseFPS::Pow
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/PowerProduct.hpp
    title: "\u758E\u306AFPS $f,g$ \u306E $f^ng^m$ \u306E\u4FC2\u6570\u5217\u6319"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc276_g.test.cpp
    title: ABC276-G Count Sequences
  - icon: ':heavy_check_mark:'
    path: Test/LC/exp_of_formal_power_series_sparse.test.cpp
    title: Test/LC/exp_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/inv_of_formal_power_series_sparse.test.cpp
    title: Test/LC/inv_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/log_of_formal_power_series_sparse.test.cpp
    title: Test/LC/log_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/pow_of_formal_power_series_sparse.test.cpp
    title: Test/LC/pow_of_formal_power_series_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/SparseFPS/SparseFPS.hpp\"\n\n#include <concepts>\n#include\
    \ <vector>\n\nnamespace zawa {\n\nnamespace SparseFPS {\n\ntemplate <std::integral\
    \ Degree,class Coef>\nstruct Term {\n    Degree degree;\n    Coef coef;\n};\n\n\
    template <std::integral Degree,class Coef>\nusing Series = std::vector<Term<Degree,Coef>>;\n\
    \n} // namespace SparseFPS\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <concepts>\n#include <vector>\n\nnamespace zawa\
    \ {\n\nnamespace SparseFPS {\n\ntemplate <std::integral Degree,class Coef>\nstruct\
    \ Term {\n    Degree degree;\n    Coef coef;\n};\n\ntemplate <std::integral Degree,class\
    \ Coef>\nusing Series = std::vector<Term<Degree,Coef>>;\n\n} // namespace SparseFPS\n\
    \n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/SparseFPS/SparseFPS.hpp
  requiredBy:
  - Src/SparseFPS/Log.hpp
  - Src/SparseFPS/Power.hpp
  - Src/SparseFPS/PowerProduct.hpp
  - Src/SparseFPS/Differential.hpp
  - Src/SparseFPS/Exp.hpp
  - Src/SparseFPS/Inverse.hpp
  - Src/SparseFPS/Integral.hpp
  - Src/SparseFPS/Divide.hpp
  timestamp: '2026-10-24 16:26:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc276_g.test.cpp
  - Test/LC/inv_of_formal_power_series_sparse.test.cpp
  - Test/LC/pow_of_formal_power_series_sparse.test.cpp
  - Test/LC/exp_of_formal_power_series_sparse.test.cpp
  - Test/LC/log_of_formal_power_series_sparse.test.cpp
documentation_of: Src/SparseFPS/SparseFPS.hpp
layout: document
title: "\u975E\u96F6\u306E\u4FC2\u6570\u306E\u500B\u6570\u304C\u5341\u5206\u5C11\u306A\
  \u3044FPS"
---

## 概要

係数が非零であるような項の個数が十分に少ないような形式的冪級数の各演算を提供するライブラリ。

```cpp
template <std::integral Degree,class Coef>
struct Term {
    Degree degree;
    Coef coef;
};

template <std::integral Degree,class Coef>
using Series = std::vector<Term<Degree,Coef>>;
```

`SparseFPS`という名前空間上に上記の実装がある。コンテナとして`Series<Degree,Coef>`を用いることができる。

非負整数 $n$ に対して`SparseFPS::Series<Degree,Coef> f(n)`は次が満たされている必要がある。

- `Degree`は通常の符号付き、符号なし整数型を想定し、`bool`や`char`などは対象外
- $i=0,1,\dots,n-1$ について、 `f[i]`のdegreeは非負
- 各`degree`は狭義単調増加に並んでいる必要がある

各`coef`が必ずしも非零である必要はない。ただし、「非零の係数の個数」が計算量に関わる解析では、本ライブラリの実装では `f.size()` に対応することになる。よって、`coef`に大量の $0$ があると計算量が壊れる場合がある。

また、空の`Series<Degree,Coef>`は $0$ として扱われる。

## 更新履歴

- 2026/10/24: 作成
