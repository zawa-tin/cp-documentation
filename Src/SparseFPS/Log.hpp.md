---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/Differential.hpp
    title: SparseFPS::Differential
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/Divide.hpp
    title: Src/SparseFPS/Divide.hpp
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/Integral.hpp
    title: SparseFPS::Integral
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
    path: Test/LC/log_of_formal_power_series_sparse.test.cpp
    title: Test/LC/log_of_formal_power_series_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/SparseFPS/Log.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
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
    \ 2 \"Src/SparseFPS/Integral.hpp\"\n\n#line 5 \"Src/SparseFPS/Integral.hpp\"\n\
    \n#line 7 \"Src/SparseFPS/Integral.hpp\"\n#include <utility>\n\nnamespace zawa\
    \ {\n\nnamespace SparseFPS {\n\ntemplate <std::integral Degree,class Coef>\nSeries<Degree,Coef>\
    \ Integral(const Series<Degree,Coef>& f) {\n    Series<Degree,Coef> res(f.size());\n\
    \    for (usize i = 0 ; i < f.size() ; i++) \n        res[i]={f[i].degree+1,f[i].coef/(f[i].degree+1)};\n\
    \    return res;\n}\n\n} // namespace SparseFPS\n\n} // namespace zawa\n#line\
    \ 2 \"Src/SparseFPS/Divide.hpp\"\n\n#line 5 \"Src/SparseFPS/Divide.hpp\"\n\n#line\
    \ 8 \"Src/SparseFPS/Divide.hpp\"\n\nnamespace zawa {\n\nnamespace SparseFPS {\n\
    \ntemplate <std::integral Degree,class Coef>\nstd::vector<Coef> Div(const Series<Degree,Coef>&\
    \ f,const Series<Degree,Coef>& g,usize n) {\n    assert(g.size());\n    assert(g[0].degree==0);\n\
    \    std::vector<Coef> res(n);\n    if (!n)\n        return res;\n    const Coef\
    \ inv=Coef{1}/g[0].coef;\n    usize idx=0,jdx=0;\n    for (usize i = 0 ; i < n\
    \ ; i++) {\n        Coef val=0;\n        if (idx < f.size() and std::cmp_equal(f[idx].degree,i))\
    \ \n            val=f[idx++].coef;\n        while (jdx < g.size() and std::cmp_less_equal(g[jdx].degree,i))\n\
    \            jdx++;\n        for (usize j = 1 ; j < jdx ; j++)\n            val-=g[j].coef*res[i-g[j].degree];\n\
    \        res[i]=val*inv;\n    }\n    return res;\n}\n\n} // namespace SparseFPS\n\
    \n} // namespace zawa\n#line 8 \"Src/SparseFPS/Log.hpp\"\n\n#line 10 \"Src/SparseFPS/Log.hpp\"\
    \n\nnamespace zawa {\n\nnamespace SparseFPS {\n\ntemplate <std::integral Degree,class\
    \ Coef>\nstd::vector<Coef> Log(const Series<Degree,Coef>& f,usize n) {\n    assert(f.size()\
    \ and f[0].degree==0 and f[0].coef==Coef{1});\n    std::vector<Coef> res(n);\n\
    \    if (!n)\n        return res;\n    auto dif=Div(Differential(f),f,n-1);\n\
    \    for (usize i = 0 ; i + 1 < n ; i++)\n        res[i+1]=dif[i]/Coef{i+1};\n\
    \    return res;\n}\n\n} // namespace SparseFPS\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"SparseFPS.hpp\"\
    \n#include \"Differential.hpp\"\n#include \"Integral.hpp\"\n#include \"Divide.hpp\"\
    \n\n#include <cassert>\n\nnamespace zawa {\n\nnamespace SparseFPS {\n\ntemplate\
    \ <std::integral Degree,class Coef>\nstd::vector<Coef> Log(const Series<Degree,Coef>&\
    \ f,usize n) {\n    assert(f.size() and f[0].degree==0 and f[0].coef==Coef{1});\n\
    \    std::vector<Coef> res(n);\n    if (!n)\n        return res;\n    auto dif=Div(Differential(f),f,n-1);\n\
    \    for (usize i = 0 ; i + 1 < n ; i++)\n        res[i+1]=dif[i]/Coef{i+1};\n\
    \    return res;\n}\n\n} // namespace SparseFPS\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/SparseFPS/SparseFPS.hpp
  - Src/SparseFPS/Differential.hpp
  - Src/SparseFPS/Integral.hpp
  - Src/SparseFPS/Divide.hpp
  isVerificationFile: false
  path: Src/SparseFPS/Log.hpp
  requiredBy: []
  timestamp: '2026-10-24 17:27:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/log_of_formal_power_series_sparse.test.cpp
documentation_of: Src/SparseFPS/Log.hpp
layout: document
title: SparseFPS::Log
---

## 概要

```cpp
template <std::integral Degree,class Coef>
std::vector<Coef> Log(const Series<Degree,Coef>& f,usize n)
```

非零な係数の個数が十分に少ない形式的冪級数 $f$ に関して、 $\log f$ の $\mod{x^n}$ を計算する。具体的に、 $[x^0]f=1$ なる $f$ に対して、 $\log f$ とは次のように定義される。

$$
\log f = -\sum_{n=1}^{\infty} \frac{(1-f)^n}{n}
$$

返り値は長さ $n$ の列であり、 $0\le i<n$ について、 $i$ 番目の要素が $[x^i]\log f$ に対応している。定数項は零である。 $n=0$ の場合は、空の列を返す。

微分と除算により $f'/f$ を $\mod{x^{n-1}}$ まで求め、積分定数を零として積分することで計算する( $n\ge 1$ の場合)。

## 制約

入力は`Series<Degree,Coef>`の共通の制約に加えて、次を満たすこと。

- $f$ は空ではなく、`f[0].degree`が $0$ であること。
- `f[0].coef`が $1$ であること。
- 係数型における整数 $1,2,\dots,n-1$ に乗法逆元が存在すること(特に、素数 $p$ を法とするmodintでは、 $n\le p$ であればよい)。 $n\le 1$ の場合、この条件は不要である。

$n=0$ の場合も、 $f$ の定数項に関する制約を満たす必要がある。

## 計算量

計算量は、 $f$ の要素数を $k$ として $O(nk)$ 。ただし、 $n=0$ の場合は $O(1)$ であり、係数の演算を $O(1)$ とする。

## 更新履歴

- 2026/10/24: 作成
