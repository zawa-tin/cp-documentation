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
  bundledCode: "#line 2 \"Src/SparseFPS/Divide.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/SparseFPS/SparseFPS.hpp\"\n\n#include <concepts>\n\
    #include <vector>\n\nnamespace zawa {\n\nnamespace SparseFPS {\n\ntemplate <std::integral\
    \ Degree,class Coef>\nstruct Term {\n    Degree degree;\n    Coef coef;\n};\n\n\
    template <std::integral Degree,class Coef>\nusing Series = std::vector<Term<Degree,Coef>>;\n\
    \n} // namespace SparseFPS\n\n} // namespace zawa\n#line 5 \"Src/SparseFPS/Divide.hpp\"\
    \n\n#include <cassert>\n#include <utility>\n\nnamespace zawa {\n\nnamespace SparseFPS\
    \ {\n\ntemplate <std::integral Degree,class Coef>\nstd::vector<Coef> Div(const\
    \ Series<Degree,Coef>& f,const Series<Degree,Coef>& g,usize n) {\n    assert(g.size());\n\
    \    assert(g[0].degree==0);\n    std::vector<Coef> res(n);\n    if (!n)\n   \
    \     return res;\n    const Coef inv=Coef{1}/g[0].coef;\n    usize idx=0,jdx=0;\n\
    \    for (usize i = 0 ; i < n ; i++) {\n        Coef val=0;\n        if (idx <\
    \ f.size() and std::cmp_equal(f[idx].degree,i)) \n            val=f[idx++].coef;\n\
    \        while (jdx < g.size() and std::cmp_less_equal(g[jdx].degree,i))\n   \
    \         jdx++;\n        for (usize j = 1 ; j < jdx ; j++)\n            val-=g[j].coef*res[i-g[j].degree];\n\
    \        res[i]=val*inv;\n    }\n    return res;\n}\n\n} // namespace SparseFPS\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"SparseFPS.hpp\"\
    \n\n#include <cassert>\n#include <utility>\n\nnamespace zawa {\n\nnamespace SparseFPS\
    \ {\n\ntemplate <std::integral Degree,class Coef>\nstd::vector<Coef> Div(const\
    \ Series<Degree,Coef>& f,const Series<Degree,Coef>& g,usize n) {\n    assert(g.size());\n\
    \    assert(g[0].degree==0);\n    std::vector<Coef> res(n);\n    if (!n)\n   \
    \     return res;\n    const Coef inv=Coef{1}/g[0].coef;\n    usize idx=0,jdx=0;\n\
    \    for (usize i = 0 ; i < n ; i++) {\n        Coef val=0;\n        if (idx <\
    \ f.size() and std::cmp_equal(f[idx].degree,i)) \n            val=f[idx++].coef;\n\
    \        while (jdx < g.size() and std::cmp_less_equal(g[jdx].degree,i))\n   \
    \         jdx++;\n        for (usize j = 1 ; j < jdx ; j++)\n            val-=g[j].coef*res[i-g[j].degree];\n\
    \        res[i]=val*inv;\n    }\n    return res;\n}\n\n} // namespace SparseFPS\n\
    \n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/SparseFPS/SparseFPS.hpp
  isVerificationFile: false
  path: Src/SparseFPS/Divide.hpp
  requiredBy:
  - Src/SparseFPS/Log.hpp
  timestamp: '2026-10-24 17:27:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/log_of_formal_power_series_sparse.test.cpp
documentation_of: Src/SparseFPS/Divide.hpp
layout: document
title: SparseFPS::Div
---

## 概要

```cpp
template <std::integral Degree,class Coef>
std::vector<Coef> Div(const Series<Degree,Coef>& f,const Series<Degree,Coef>& g,usize n)
```

非零な係数の個数が十分に少ない形式的冪級数 $f,g$ に関して、 $gh=f$ を満たす $h=f/g$ の $\mod{x^n}$ を計算する。

返り値は長さ $n$ の列であり、 $0\le i<n$ について、 $i$ 番目の要素が $[x^i]h$ に対応している。 $n=0$ の場合は、空の列を返す。 $f$ が空の場合は零級数として扱い、零の列を返す。

$gh=f$ の係数を比較して得られる漸化式

$$
[x^i]h=\frac{[x^i]f-\sum_{j=1}^{i}([x^j]g)([x^{i-j}]h)}{[x^0]g}
$$

を用いて、低次から順に係数を求める。和の計算では、 $g$ に格納された次数 $1$ 以上 $i$ 以下の項だけを参照する。 $[x^0]g$ の逆元は一度だけ計算して使い回す。

## 制約

入力は`Series<Degree,Coef>`の共通の制約に加えて、次を満たすこと。

- $g$ は空ではなく、`g[0].degree`が $0$ であること。
- $n>0$ の場合、`g[0].coef`に乗法逆元が存在すること(特に、素数 $p$ を法とするmodintでは、非零であればよい)。

$n=0$ の場合も、 $g$ が空でなく、`g[0].degree`が $0$ である必要がある。ただし、この場合は係数の乗法逆元を計算しないため、逆元の存在は不要である。

## 計算量

計算量は、 $g$ の要素数を $k_g$ として $O(nk_g)$ 。ただし、 $n=0$ の場合は $O(1)$ であり、係数の演算を $O(1)$ とする。 $f$ は低次から順に参照し、次数 $n$ 未満の項だけを処理するため、 $f$ の要素数全体に比例する走査は行わない。

乗法逆元の計算を $O(\log MOD)$ 、それ以外の係数の演算を $O(1)$ とする場合、 $n>0$ では全体で $O(nk_g+\log MOD)$ かかる。ここで、 $MOD$ は係数の法である。 $[x^0]g$ の逆元を一度だけ計算するため、逆元計算のコストは $O(\log MOD)$ となる。 $n=0$ の場合は $O(1)$ である。

## 更新履歴

- 2026/10/24: 作成
- 2026/10/25: ドキュメントを作成
