---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/SparseFPS.hpp
    title: "\u975E\u96F6\u306E\u4FC2\u6570\u306E\u500B\u6570\u304C\u5341\u5206\u5C11\
      \u306A\u3044FPS"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/Exp.hpp
    title: SparseFPS::Exp
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
  bundledCode: "#line 2 \"Src/SparseFPS/Differential.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/SparseFPS/SparseFPS.hpp\"\n\n#include <concepts>\n\
    #include <vector>\n\nnamespace zawa {\n\nnamespace SparseFPS {\n\ntemplate <std::integral\
    \ Degree,class Coef>\nstruct Term {\n    Degree degree;\n    Coef coef;\n};\n\n\
    template <std::integral Degree,class Coef>\nusing Series = std::vector<Term<Degree,Coef>>;\n\
    \n} // namespace SparseFPS\n\n} // namespace zawa\n#line 5 \"Src/SparseFPS/Differential.hpp\"\
    \n\n#include <cassert>\n\nnamespace zawa {\n\nnamespace SparseFPS {\n\ntemplate\
    \ <std::integral Degree,class Coef>\nSeries<Degree,Coef> Differential(const Series<Degree,Coef>&\
    \ f) {\n    Series<Degree,Coef> res;\n    res.reserve(f.size());\n    for (const\
    \ auto& term : f)\n        if (term.degree!=Degree{0})\n            res.emplace_back(term.degree-1,term.coef*term.degree);\n\
    \    return res;\n}\n\n} // namespace SparseFPS\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"SparseFPS.hpp\"\
    \n\n#include <cassert>\n\nnamespace zawa {\n\nnamespace SparseFPS {\n\ntemplate\
    \ <std::integral Degree,class Coef>\nSeries<Degree,Coef> Differential(const Series<Degree,Coef>&\
    \ f) {\n    Series<Degree,Coef> res;\n    res.reserve(f.size());\n    for (const\
    \ auto& term : f)\n        if (term.degree!=Degree{0})\n            res.emplace_back(term.degree-1,term.coef*term.degree);\n\
    \    return res;\n}\n\n} // namespace SparseFPS\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/SparseFPS/SparseFPS.hpp
  isVerificationFile: false
  path: Src/SparseFPS/Differential.hpp
  requiredBy:
  - Src/SparseFPS/Log.hpp
  - Src/SparseFPS/Power.hpp
  - Src/SparseFPS/PowerProduct.hpp
  - Src/SparseFPS/Exp.hpp
  timestamp: '2026-10-24 17:27:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc276_g.test.cpp
  - Test/LC/pow_of_formal_power_series_sparse.test.cpp
  - Test/LC/exp_of_formal_power_series_sparse.test.cpp
  - Test/LC/log_of_formal_power_series_sparse.test.cpp
documentation_of: Src/SparseFPS/Differential.hpp
layout: document
title: SparseFPS::Differential
---

## 概要

```cpp
template <std::integral Degree,class Coef>
Series<Degree,Coef> Differential(const Series<Degree,Coef>& f)
```

非零な係数の個数が十分に少ない形式的冪級数 $f$ に関して、微分 $f'$ を計算する。

返り値は疎な形式的冪級数であり、入力の各項 $cx^d$ のうち $d>0$ のものを $dcx^{d-1}$ に変換したものである。入力の定数項は取り除く。変換後の係数が零となった項は取り除かない。

空の列を渡した場合は、空の列を返す。

## 制約

入力は`Series<Degree,Coef>`の共通の制約を満たすこと。

## 計算量

計算量は、 $f$ の要素数を $k$ として $O(k)$ 。

## 更新履歴

- 2026/10/24: 作成
