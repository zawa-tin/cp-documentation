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
    path: Src/SparseFPS/Log.hpp
    title: SparseFPS::Log
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/log_of_formal_power_series_sparse.test.cpp
    title: Test/LC/log_of_formal_power_series_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/SparseFPS/Integral.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/SparseFPS/SparseFPS.hpp\"\n\n#include <concepts>\n\
    #include <vector>\n\nnamespace zawa {\n\nnamespace SparseFPS {\n\ntemplate <std::integral\
    \ Degree,class Coef>\nstruct Term {\n    Degree degree;\n    Coef coef;\n};\n\n\
    template <std::integral Degree,class Coef>\nusing Series = std::vector<Term<Degree,Coef>>;\n\
    \n} // namespace SparseFPS\n\n} // namespace zawa\n#line 5 \"Src/SparseFPS/Integral.hpp\"\
    \n\n#include <cassert>\n#include <utility>\n\nnamespace zawa {\n\nnamespace SparseFPS\
    \ {\n\ntemplate <std::integral Degree,class Coef>\nSeries<Degree,Coef> Integral(const\
    \ Series<Degree,Coef>& f) {\n    Series<Degree,Coef> res(f.size());\n    for (usize\
    \ i = 0 ; i < f.size() ; i++) \n        res[i]={f[i].degree+1,f[i].coef/(f[i].degree+1)};\n\
    \    return res;\n}\n\n} // namespace SparseFPS\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"SparseFPS.hpp\"\
    \n\n#include <cassert>\n#include <utility>\n\nnamespace zawa {\n\nnamespace SparseFPS\
    \ {\n\ntemplate <std::integral Degree,class Coef>\nSeries<Degree,Coef> Integral(const\
    \ Series<Degree,Coef>& f) {\n    Series<Degree,Coef> res(f.size());\n    for (usize\
    \ i = 0 ; i < f.size() ; i++) \n        res[i]={f[i].degree+1,f[i].coef/(f[i].degree+1)};\n\
    \    return res;\n}\n\n} // namespace SparseFPS\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/SparseFPS/SparseFPS.hpp
  isVerificationFile: false
  path: Src/SparseFPS/Integral.hpp
  requiredBy:
  - Src/SparseFPS/Log.hpp
  timestamp: '2026-10-24 17:27:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/log_of_formal_power_series_sparse.test.cpp
documentation_of: Src/SparseFPS/Integral.hpp
layout: document
title: SparseFPS::Integral
---

## 概要

```cpp
template <std::integral Degree,class Coef>
Series<Degree,Coef> Integral(const Series<Degree,Coef>& f)
```

非零な係数の個数が十分に少ない形式的冪級数 $f$ に関して、積分定数を零として積分を計算する。

返り値は疎な形式的冪級数であり、入力の各項 $cx^d$ を $\frac{c}{d+1}x^{d+1}$ に変換したものである。返り値の要素数は $f$ の要素数と等しく、定数項は格納しない。

空の列を渡した場合は、空の列を返す。

## 制約

入力は`Series<Degree,Coef>`の共通の制約に加えて、各項の次数 $d$ について次を満たすこと。

- $d+1$ を計算する際にオーバーフローせず、`Degree`型で表現できること。
- 係数型における $d+1$ に乗法逆元が存在すること(特に、素数 $p$ を法とするmodintでは、 $d+1$ が $p$ の倍数でないこと)。

## 計算量

計算量は、 $f$ の要素数を $k$ として $O(k)$ 。ただし、係数の除算を $O(1)$ とする。

乗法逆元の計算を $O(\log MOD)$ 、それ以外の係数の演算を $O(1)$ とする場合、各項について $d+1$ の逆元を計算するため、全体で $O(k\log MOD)$ かかる。ここで、 $MOD$ は係数の法である。

## 更新履歴

- 2026/10/24: 作成
- 2026/10/25: 乗法逆元の計算量を含む解析を追記
