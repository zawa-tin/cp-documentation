---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/Differential.hpp
    title: SparseFPS::Differential
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/SparseFPS.hpp
    title: "\u975E\u96F6\u306E\u4FC2\u6570\u306E\u500B\u6570\u304C\u5341\u5206\u5C11\
      \u306A\u3044FPS"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/exp_of_formal_power_series_sparse.test.cpp
    title: Test/LC/exp_of_formal_power_series_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/SparseFPS/Exp.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/SparseFPS/SparseFPS.hpp\"\n\n#include <concepts>\n\
    #include <vector>\n\nnamespace zawa {\n\nnamespace SparseFPS {\n\ntemplate <std::integral\
    \ Degree,class Coef>\nstruct Term {\n    Degree degree;\n    Coef coef;\n};\n\n\
    template <std::integral Degree,class Coef>\nusing Series = std::vector<Term<Degree,Coef>>;\n\
    \n} // namespace SparseFPS\n\n} // namespace zawa\n#line 2 \"Src/SparseFPS/Differential.hpp\"\
    \n\n#line 5 \"Src/SparseFPS/Differential.hpp\"\n\n#include <cassert>\n\nnamespace\
    \ zawa {\n\nnamespace SparseFPS {\n\ntemplate <std::integral Degree,class Coef>\n\
    Series<Degree,Coef> Differential(const Series<Degree,Coef>& f) {\n    Series<Degree,Coef>\
    \ res;\n    res.reserve(f.size());\n    for (const auto& term : f)\n        if\
    \ (term.degree!=Degree{0})\n            res.emplace_back(term.degree-1,term.coef*term.degree);\n\
    \    return res;\n}\n\n} // namespace SparseFPS\n\n} // namespace zawa\n#line\
    \ 6 \"Src/SparseFPS/Exp.hpp\"\n\n#line 8 \"Src/SparseFPS/Exp.hpp\"\n#include <utility>\n\
    \nnamespace zawa {\n\nnamespace SparseFPS {\n\ntemplate <std::integral Degree,class\
    \ Coef>\nstd::vector<Coef> Exp(const Series<Degree,Coef>& f,usize n) {\n    std::vector<Coef>\
    \ res(n);\n    if (f.empty()) {\n        if (n)\n            res[0]=1;\n     \
    \   return res;\n    }\n    assert(f[0].degree!=0 or f[0].coef==0);\n    if (!n)\n\
    \        return res;\n    auto diff=Differential(f);\n    res[0]=1;\n    usize\
    \ idx=0;\n    for (usize i = 1 ; i < n ; i++) {\n        while (idx < diff.size()\
    \ and std::cmp_less(diff[idx].degree,i))\n            idx++;\n        Coef val=0;\n\
    \        for (usize j = 0 ; j < idx ; j++)\n            val+=diff[j].coef*res[i-1-diff[j].degree];\n\
    \        res[i]=val/Coef{i};\n    }\n    return res;\n}\n\n} // namespace SparseFPS\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"SparseFPS.hpp\"\
    \n#include \"Differential.hpp\"\n\n#include <cassert>\n#include <utility>\n\n\
    namespace zawa {\n\nnamespace SparseFPS {\n\ntemplate <std::integral Degree,class\
    \ Coef>\nstd::vector<Coef> Exp(const Series<Degree,Coef>& f,usize n) {\n    std::vector<Coef>\
    \ res(n);\n    if (f.empty()) {\n        if (n)\n            res[0]=1;\n     \
    \   return res;\n    }\n    assert(f[0].degree!=0 or f[0].coef==0);\n    if (!n)\n\
    \        return res;\n    auto diff=Differential(f);\n    res[0]=1;\n    usize\
    \ idx=0;\n    for (usize i = 1 ; i < n ; i++) {\n        while (idx < diff.size()\
    \ and std::cmp_less(diff[idx].degree,i))\n            idx++;\n        Coef val=0;\n\
    \        for (usize j = 0 ; j < idx ; j++)\n            val+=diff[j].coef*res[i-1-diff[j].degree];\n\
    \        res[i]=val/Coef{i};\n    }\n    return res;\n}\n\n} // namespace SparseFPS\n\
    \n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/SparseFPS/SparseFPS.hpp
  - Src/SparseFPS/Differential.hpp
  isVerificationFile: false
  path: Src/SparseFPS/Exp.hpp
  requiredBy: []
  timestamp: '2026-10-24 18:04:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/exp_of_formal_power_series_sparse.test.cpp
documentation_of: Src/SparseFPS/Exp.hpp
layout: document
title: SparseFPS::Exp
---

## 概要

```cpp
template <std::integral Degree,class Coef>
std::vector<Coef> Exp(const Series<Degree,Coef>& f,usize n)
```

非零な係数の個数が十分に少ない形式的冪級数 $f$ に関して、 $\exp f$ の $\mod{x^n}$ を計算する。具体的に、 $[x^0]f=0$ なる $f$ に対して、 $\exp f$ とは次のように定義される。

$$
\exp f = \sum_{n=0}^{\infty}\frac{f^n}{n!}
$$

返り値は長さ $n$ の列であり、 $0\le i<n$ について、 $i$ 番目の要素が $[x^i]\exp f$ に対応している。 $n=0$ の場合は、空の列を返す。

## 制約

入力は`Series<Degree,Coef>`の共通の制約に加えて、次を満たすこと。

- $[x^0]f$ が $0$ であること。
- 係数型における整数 $1,2,\dots,n-1$ に乗法逆元が存在すること(特に、素数 $p$ を法とするmodintでは、 $n\le p$ であればよい)。 $n\le 1$ の場合、この条件は不要である。

$n=0$ の場合も、 $f$ の定数項に関する制約を満たす必要がある。

## 計算量

計算量は、 $f$ の要素数を $k$ として $O(n(k+1))$ 。ただし、 $n=0$ の場合は $O(1)$ であり、係数の演算を $O(1)$ とする。

乗法逆元の計算を $O(\log MOD)$ 、それ以外の係数の演算を $O(1)$ とする場合、 $n>0$ では全体で $O(n(k+1+\log MOD))$ かかる。ここで、 $MOD$ は係数の法である。 $f$ が空でなければ、微分と漸化式の計算に加えて、 $i=1,2,\dots,n-1$ ごとに $i$ の逆元を計算する。 $f$ が空の場合は逆元を計算せず、 $O(n+1)$ であり、 $n=0$ の場合は入力によらず $O(1)$ である。

## 更新履歴

- 2026/10/24: 作成
- 2026/10/25: 乗法逆元の計算量を含む解析を追記
