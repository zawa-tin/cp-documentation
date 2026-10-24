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
    path: Test/AtCoder/abc276_g.test.cpp
    title: ABC276-G Count Sequences
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/SparseFPS/PowerProduct.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
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
    \ 6 \"Src/SparseFPS/PowerProduct.hpp\"\n\n#include <algorithm>\n#line 9 \"Src/SparseFPS/PowerProduct.hpp\"\
    \n#include <utility>\n\nnamespace zawa {\n\nnamespace SparseFPS {\n\ntemplate\
    \ <std::integral Degree,class Coef>\nstd::vector<Coef> PowProduct(Series<Degree,Coef>\
    \ f,Series<Degree,Coef> g,i64 n,i64 m,usize N) {\n    if (N==0)\n        return\
    \ {};\n    std::erase_if(f,[](const auto& t) -> bool { return t.coef==Coef{0};\
    \ });\n    std::erase_if(g,[](const auto& t) -> bool { return t.coef==Coef{0};\
    \ });\n    if (n==0)\n        f=Series<Degree,Coef>{{Degree{0},Coef{1}}};\n  \
    \  if (m==0)\n        g=Series<Degree,Coef>{{Degree{0},Coef{1}}};\n    assert(f.size()\
    \ or n >= 0);\n    assert(g.size() or m >= 0);\n    if (f.empty() and n > 0)\n\
    \        return std::vector<Coef>(N,Coef{0});\n    if (g.empty() and m > 0)\n\
    \        return std::vector<Coef>(N,Coef{0});\n    auto power=[](Coef x,i64 exp)\
    \ -> Coef {\n        Coef res=1;\n        u64 e=exp<0?static_cast<u64>(-(exp+1))+1:static_cast<u64>(exp);\n\
    \        Coef val=exp<0?(Coef{1}/x):x;\n        for (u64 cur = e ; cur ; cur >>=\
    \ 1) {\n            if (cur & 1)\n                res*=val;\n            val*=val;\n\
    \        }\n        return res;\n    };\n    auto normalize=[power](Series<Degree,Coef>&\
    \ f,i64 n) -> std::pair<Degree,Coef> {\n        auto [s,c]=f[0];\n        Coef\
    \ invc=Coef{1}/c;\n        for  (auto& t : f) {\n            t.degree-=s;\n  \
    \          t.coef*=invc;\n        }\n        return {s,power(c,n)};\n    };\n\
    \    auto [a1,b1]=normalize(f,n);\n    auto [a2,b2]=normalize(g,m);\n    const\
    \ i128 p=static_cast<i128>(a1)*n;\n    const i128 q=static_cast<i128>(a2)*m;\n\
    \    // p+q<0\u306A\u3089\u3001\u8CA0\u51AA\u3092\u8A31\u3055\u306A\u3044\u3068\
    \u5B9A\u7FA9\u3067\u304D\u306A\u3044\u306E\u3067\u3001assert\u843D\u3061\n   \
    \ assert(p >= 0 ? q >= -p : (q >= 0 and p >= -q));\n    if ([&]() {\n        \
    \    const i128 len=static_cast<i128>(N);\n            return p >= 0 ? q >= len-p\
    \ : (q >= 0 and p >= len-q);\n            }())\n    return std::vector<Coef>(N,Coef{0});\n\
    \    const usize shift=static_cast<usize>(p+q);\n    std::vector<Coef> res(N),P(N),Q(N);\n\
    \    P[0]=Q[0]=Coef{1};\n    res[shift]=b1*b2;\n    auto df=Differential(f),dg=Differential(g);\n\
    \    usize idx_df=0,idx_dg=0,idx_f=0,idx_g=0;\n    for (usize i = 1 ; i + shift\
    \ < N ; i++) {\n        const auto h=[&]{// [x^{i-1}] equation of dH=n(df)P+m(dg)Q\
    \ \n            while (idx_df<df.size() and std::cmp_less(df[idx_df].degree,i))\n\
    \                idx_df++;\n            while (idx_dg<dg.size() and std::cmp_less(dg[idx_dg].degree,i))\n\
    \                idx_dg++;\n            Coef val=0;\n            for (usize j\
    \ = 0 ; j < idx_df ; j++)\n                val+=Coef{n}*df[j].coef*P[i-1-df[j].degree];\n\
    \            for (usize j = 0 ; j < idx_dg ; j++)\n                val+=Coef{m}*dg[j].coef*Q[i-1-dg[j].degree];\n\
    \            return val/Coef{i};\n        }();\n        res[i+shift]=b1*b2*h;\n\
    \        { // [x^i] equation of fP=H\n            while (idx_f<f.size() and std::cmp_less_equal(f[idx_f].degree,i))\n\
    \                idx_f++;\n            Coef val=h;\n            for (usize j =\
    \ 0 ; j < idx_f ; j++)\n                val-=f[j].coef*P[i-f[j].degree];\n   \
    \         P[i]=val;\n        }\n        { // [x^i] equation of gQ=H\n        \
    \    while (idx_g<g.size() and std::cmp_less_equal(g[idx_g].degree,i))\n     \
    \           idx_g++;\n            Coef val=h;\n            for (usize j = 0 ;\
    \ j < idx_g ; j++)\n                val-=g[j].coef*Q[i-g[j].degree];\n       \
    \     Q[i]=val;\n        }\n    }\n    return res;\n}\n\n} // namespace SparseFPS\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"SparseFPS.hpp\"\
    \n#include \"Differential.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n\nnamespace zawa {\n\nnamespace SparseFPS {\n\ntemplate <std::integral\
    \ Degree,class Coef>\nstd::vector<Coef> PowProduct(Series<Degree,Coef> f,Series<Degree,Coef>\
    \ g,i64 n,i64 m,usize N) {\n    if (N==0)\n        return {};\n    std::erase_if(f,[](const\
    \ auto& t) -> bool { return t.coef==Coef{0}; });\n    std::erase_if(g,[](const\
    \ auto& t) -> bool { return t.coef==Coef{0}; });\n    if (n==0)\n        f=Series<Degree,Coef>{{Degree{0},Coef{1}}};\n\
    \    if (m==0)\n        g=Series<Degree,Coef>{{Degree{0},Coef{1}}};\n    assert(f.size()\
    \ or n >= 0);\n    assert(g.size() or m >= 0);\n    if (f.empty() and n > 0)\n\
    \        return std::vector<Coef>(N,Coef{0});\n    if (g.empty() and m > 0)\n\
    \        return std::vector<Coef>(N,Coef{0});\n    auto power=[](Coef x,i64 exp)\
    \ -> Coef {\n        Coef res=1;\n        u64 e=exp<0?static_cast<u64>(-(exp+1))+1:static_cast<u64>(exp);\n\
    \        Coef val=exp<0?(Coef{1}/x):x;\n        for (u64 cur = e ; cur ; cur >>=\
    \ 1) {\n            if (cur & 1)\n                res*=val;\n            val*=val;\n\
    \        }\n        return res;\n    };\n    auto normalize=[power](Series<Degree,Coef>&\
    \ f,i64 n) -> std::pair<Degree,Coef> {\n        auto [s,c]=f[0];\n        Coef\
    \ invc=Coef{1}/c;\n        for  (auto& t : f) {\n            t.degree-=s;\n  \
    \          t.coef*=invc;\n        }\n        return {s,power(c,n)};\n    };\n\
    \    auto [a1,b1]=normalize(f,n);\n    auto [a2,b2]=normalize(g,m);\n    const\
    \ i128 p=static_cast<i128>(a1)*n;\n    const i128 q=static_cast<i128>(a2)*m;\n\
    \    // p+q<0\u306A\u3089\u3001\u8CA0\u51AA\u3092\u8A31\u3055\u306A\u3044\u3068\
    \u5B9A\u7FA9\u3067\u304D\u306A\u3044\u306E\u3067\u3001assert\u843D\u3061\n   \
    \ assert(p >= 0 ? q >= -p : (q >= 0 and p >= -q));\n    if ([&]() {\n        \
    \    const i128 len=static_cast<i128>(N);\n            return p >= 0 ? q >= len-p\
    \ : (q >= 0 and p >= len-q);\n            }())\n    return std::vector<Coef>(N,Coef{0});\n\
    \    const usize shift=static_cast<usize>(p+q);\n    std::vector<Coef> res(N),P(N),Q(N);\n\
    \    P[0]=Q[0]=Coef{1};\n    res[shift]=b1*b2;\n    auto df=Differential(f),dg=Differential(g);\n\
    \    usize idx_df=0,idx_dg=0,idx_f=0,idx_g=0;\n    for (usize i = 1 ; i + shift\
    \ < N ; i++) {\n        const auto h=[&]{// [x^{i-1}] equation of dH=n(df)P+m(dg)Q\
    \ \n            while (idx_df<df.size() and std::cmp_less(df[idx_df].degree,i))\n\
    \                idx_df++;\n            while (idx_dg<dg.size() and std::cmp_less(dg[idx_dg].degree,i))\n\
    \                idx_dg++;\n            Coef val=0;\n            for (usize j\
    \ = 0 ; j < idx_df ; j++)\n                val+=Coef{n}*df[j].coef*P[i-1-df[j].degree];\n\
    \            for (usize j = 0 ; j < idx_dg ; j++)\n                val+=Coef{m}*dg[j].coef*Q[i-1-dg[j].degree];\n\
    \            return val/Coef{i};\n        }();\n        res[i+shift]=b1*b2*h;\n\
    \        { // [x^i] equation of fP=H\n            while (idx_f<f.size() and std::cmp_less_equal(f[idx_f].degree,i))\n\
    \                idx_f++;\n            Coef val=h;\n            for (usize j =\
    \ 0 ; j < idx_f ; j++)\n                val-=f[j].coef*P[i-f[j].degree];\n   \
    \         P[i]=val;\n        }\n        { // [x^i] equation of gQ=H\n        \
    \    while (idx_g<g.size() and std::cmp_less_equal(g[idx_g].degree,i))\n     \
    \           idx_g++;\n            Coef val=h;\n            for (usize j = 0 ;\
    \ j < idx_g ; j++)\n                val-=g[j].coef*Q[i-g[j].degree];\n       \
    \     Q[i]=val;\n        }\n    }\n    return res;\n}\n\n} // namespace SparseFPS\n\
    \n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/SparseFPS/SparseFPS.hpp
  - Src/SparseFPS/Differential.hpp
  isVerificationFile: false
  path: Src/SparseFPS/PowerProduct.hpp
  requiredBy: []
  timestamp: '2026-10-24 20:40:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc276_g.test.cpp
documentation_of: Src/SparseFPS/PowerProduct.hpp
layout: document
title: "\u758E\u306AFPS $f,g$ \u306E $f^ng^m$ \u306E\u4FC2\u6570\u5217\u6319"
---

## 概要

```cpp
template <std::integral Degree,class Coef>
std::vector<Coef> PowProduct(Series<Degree,Coef> f,Series<Degree,Coef> g,i64 n,i64 m,usize N)
```

非零な係数の個数が十分に少ない形式的冪級数 $f,g$ に関して、整数 $n,m$ に対する $f^ng^m$ の $\mod{x^N}$ を計算する。 $n,m$ は負でもよい。例えば、 $(f/g)^n$ は指数を $n,-n$ とすることで計算できる。

返り値は長さ $N$ の列であり、 $0\le i<N$ について、 $i$ 番目の要素が $[x^i]f^ng^m$ に対応している。 $N=0$ の場合は、入力によらず空の列を返す。

指数が零の因子は、零級数を含めて $f^0=g^0=1$ として扱う。空の列は零級数として扱い、零級数の負乗は禁止する。零級数の負乗がなく、零級数の正乗が含まれる場合は、零の列を返す。

上記の場合分けの後、指数が零の因子を $1$ に置き換え、最低次の非零項を取り出して

$$
f=c_1x^{a_1}F,\qquad g=c_2x^{a_2}G,\qquad [x^0]F=[x^0]G=1
$$

と分解する。 $s=a_1n+a_2m$ とすると、

$$
f^ng^m=c_1^nc_2^m x^sF^nG^m
$$

である。 $s<0$ の場合は対象外とする。各因子に負冪が現れる場合でも、積全体の最低次数 $s$ が非負ならば扱える。 $s\ge N$ の場合は、零の列を返す。

$0\le s<N$ の場合は、 $H=F^nG^m$ を $\mod{x^{N-s}}$ まで求め、係数倍とシフトにより答えを構築する。補助列 $P=H/F$ 、 $Q=H/G$ を用いて、

$$
H'=nF'P+mG'Q,\qquad FP=H,\qquad GQ=H
$$

を満たす係数を低次から順に計算する。初期値は $[x^0]H=[x^0]P=[x^0]Q=1$ である。

## 制約

入力は`Series<Degree,Coef>`の共通の制約を満たし、`Degree`は64ビット以下の整数型とする。零係数の項は内部で除去する。

$N>0$ の場合は、次を満たすこと。

- $f=0$ ならば $n\ge 0$ 、 $g=0$ ならば $m\ge 0$ であること。指数零の因子は $1$ として扱う。
- 零級数の正乗による早期終了をしない場合、正規化に使う $c_1,c_2$ に乗法逆元が存在し、 $s=a_1n+a_2m\ge 0$ であること。 $s\ge N$ の場合も、先頭係数の逆元は必要である。
- さらに $s<N$ の場合、係数型における整数 $1,2,\dots,N-s-1$ に乗法逆元が存在すること。 $N-s=1$ の場合、この条件は不要である。

特に、素数 $p$ を法とするmodintでは、非零の先頭係数は逆元を持ち、整数に関する条件は $N-s\le p$ であればよい。

## 計算量

計算量は、入力 $f,g$ の要素数をそれぞれ $K_f,K_g$ として $O((N+1)(K_f+K_g+1)+\log(|n|+1)+\log(|m|+1))$ 。ただし、係数の演算を $O(1)$ とする。

係数を列挙する漸化式の部分は $O((N-s)(K_f+K_g+1))$ で計算する。

## 更新履歴

- 2026/10/24: 作成
