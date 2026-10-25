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
    path: Test/LC/pow_of_formal_power_series_sparse.test.cpp
    title: Test/LC/pow_of_formal_power_series_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/SparseFPS/Power.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
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
    \ 6 \"Src/SparseFPS/Power.hpp\"\n\n#include <algorithm>\n#line 9 \"Src/SparseFPS/Power.hpp\"\
    \n#include <utility>\n\nnamespace zawa {\n\nnamespace SparseFPS {\n\ntemplate\
    \ <std::integral Degree,class Coef>\nstd::vector<Coef> Pow(Series<Degree,Coef>\
    \ f,usize m,usize n) {\n    std::erase_if(f,[](const auto& t) -> bool { return\
    \ t.coef==Coef{0}; });\n    std::vector<Coef> res(n);\n    if (!n)\n        return\
    \ {};\n    if (f.empty() or !m) {\n        res[0]=m==0;\n        return res;\n\
    \    }\n    const auto [a,c] = f[0];\n    if (std::cmp_greater(a,(n-1)/m))\n \
    \       return res;\n    const Coef invc=Coef{1}/c;\n    const Coef powc=[&](){\n\
    \        Coef res=1,cur=c;\n        for (usize exp = m ; exp ; exp>>=1) {\n  \
    \          if (exp & 1)\n                res*=cur;\n            cur*=cur;\n  \
    \      }\n        return res;\n    }();\n    for (auto& t : f) {\n        t.degree-=a;\n\
    \        t.coef*=invc;\n    }\n    auto df=Differential(f);\n    std::vector<Coef>\
    \ F(n),DF(n-1);\n    usize idx=0,jdx=0;\n    F[0]=Coef{1};\n    res[m*a]=powc;\n\
    \    for (usize i = 1 ; i < n-m*a ; i++) {\n        // equation of [x^{i-1}]\n\
    \        while (idx < f.size() and std::cmp_less(f[idx].degree,i))\n         \
    \   idx++;\n        while (jdx < df.size() and std::cmp_less(df[jdx].degree,i))\n\
    \            jdx++;\n        Coef left=0,right=0;\n        for (usize j = 0 ;\
    \ j < idx ; j++)\n            left+=f[j].coef*DF[i-1-f[j].degree];\n        for\
    \ (usize j = 0 ; j < jdx ; j++)\n            right+=df[j].coef*F[i-1-df[j].degree];\n\
    \        right*=Coef{m};\n        DF[i-1]=right-left;\n        F[i]=DF[i-1]/Coef{i};\
    \ \n        res[i+m*a]=F[i]*powc;\n    }\n    return res;\n}\n\n} // namespace\
    \ SparseFPS\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"SparseFPS.hpp\"\
    \n#include \"Differential.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n\nnamespace zawa {\n\nnamespace SparseFPS {\n\ntemplate <std::integral\
    \ Degree,class Coef>\nstd::vector<Coef> Pow(Series<Degree,Coef> f,usize m,usize\
    \ n) {\n    std::erase_if(f,[](const auto& t) -> bool { return t.coef==Coef{0};\
    \ });\n    std::vector<Coef> res(n);\n    if (!n)\n        return {};\n    if\
    \ (f.empty() or !m) {\n        res[0]=m==0;\n        return res;\n    }\n    const\
    \ auto [a,c] = f[0];\n    if (std::cmp_greater(a,(n-1)/m))\n        return res;\n\
    \    const Coef invc=Coef{1}/c;\n    const Coef powc=[&](){\n        Coef res=1,cur=c;\n\
    \        for (usize exp = m ; exp ; exp>>=1) {\n            if (exp & 1)\n   \
    \             res*=cur;\n            cur*=cur;\n        }\n        return res;\n\
    \    }();\n    for (auto& t : f) {\n        t.degree-=a;\n        t.coef*=invc;\n\
    \    }\n    auto df=Differential(f);\n    std::vector<Coef> F(n),DF(n-1);\n  \
    \  usize idx=0,jdx=0;\n    F[0]=Coef{1};\n    res[m*a]=powc;\n    for (usize i\
    \ = 1 ; i < n-m*a ; i++) {\n        // equation of [x^{i-1}]\n        while (idx\
    \ < f.size() and std::cmp_less(f[idx].degree,i))\n            idx++;\n       \
    \ while (jdx < df.size() and std::cmp_less(df[jdx].degree,i))\n            jdx++;\n\
    \        Coef left=0,right=0;\n        for (usize j = 0 ; j < idx ; j++)\n   \
    \         left+=f[j].coef*DF[i-1-f[j].degree];\n        for (usize j = 0 ; j <\
    \ jdx ; j++)\n            right+=df[j].coef*F[i-1-df[j].degree];\n        right*=Coef{m};\n\
    \        DF[i-1]=right-left;\n        F[i]=DF[i-1]/Coef{i}; \n        res[i+m*a]=F[i]*powc;\n\
    \    }\n    return res;\n}\n\n} // namespace SparseFPS\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/SparseFPS/SparseFPS.hpp
  - Src/SparseFPS/Differential.hpp
  isVerificationFile: false
  path: Src/SparseFPS/Power.hpp
  requiredBy: []
  timestamp: '2026-10-24 19:19:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/pow_of_formal_power_series_sparse.test.cpp
documentation_of: Src/SparseFPS/Power.hpp
layout: document
title: SparseFPS::Pow
---

## 概要

```cpp
template <std::integral Degree,class Coef>
std::vector<Coef> Pow(Series<Degree,Coef> f,usize m,usize n)
```

非零な係数の個数が十分に少ない形式的冪級数 $f$ に関して、非負整数 $m$ に対する $f^m$ の $\mod{x^n}$ を計算する。

返り値は長さ $n$ の列であり、 $0\le i<n$ について、 $i$ 番目の要素が $[x^i]f^m$ に対応している。 $n=0$ の場合は、空の列を返す。

$m=0$ の場合は、零級数を含めて $f^0=1$ として扱う。 $f$ が零級数で $m>0$ の場合は、零の列を返す。空の列も零級数として扱う。

$f$ が零級数でない場合、係数が非零である最低次を $a$ 、その係数を $c$ とする。 $f=cx^aF$ と分解し、定数項が $1$ の $F$ に対する累乗を計算した後、 $c^m x^{am}$ を掛ける。 $m>0$ かつ $am\ge n$ の場合は、零の列を返す。

$G=F^m$ に対して $FG'=mF'G$ が成り立つことを用い、 $[x^0]G=1$ から順に係数を求める。

## 制約

入力は`Series<Degree,Coef>`の共通の制約を満たすこと。零係数の項は内部で除去する。

$n>0$ 、 $m>0$ 、 $f\ne 0$ 、 $am<n$ のすべてを満たす場合は、さらに次を満たすこと。

- 最低次の非零係数 $c$ に乗法逆元が存在すること。
- 係数型における整数 $1,2,\dots,n-am-1$ に乗法逆元が存在すること。 $n-am=1$ の場合、この条件は不要である。

特に、素数 $p$ を法とするmodintでは、 $c$ は非零なので逆元を持ち、整数に関する条件は $n-am\le p$ であればよい。

早期終了する $n=0$ 、 $m=0$ 、 $f=0$ 、 $am\ge n$ の場合、係数の乗法逆元は不要である( $a$ は $f\ne 0$ の場合に定義する)。

## 計算量

計算量は、入力 $f$ の要素数を $k$ として $O((n+1)(k+1)+\log(m+1))$ 。ただし、係数の演算を $O(1)$ とする。

乗法逆元の計算を $O(\log MOD)$ 、それ以外の係数の演算を $O(1)$ とする場合、全体の計算量は

$$
O((n+1)(k+1)+n\log MOD+\log(m+1))
$$

である。ここで、 $MOD$ は係数の法である。早期終了しない場合、正規化で $c$ の逆元を一度、係数の漸化式で整数 $1,2,\dots,n-am-1$ の逆元をそれぞれ計算するため、逆元計算の合計は $O((n-am)\log MOD)$ となる。 $c^m$ は繰り返し二乗法で計算する。

$n=0$ の場合も、零係数の項を除去するため $O(k+1)$ かかる。この場合は逆元を計算しない。

## 更新履歴

- 2026/10/24: 作成
- 2026/10/25: 乗法逆元の計算量を含む解析を追記
