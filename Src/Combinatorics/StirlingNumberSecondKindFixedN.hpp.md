---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/stirling_number_of_the_second_kind.test.cpp
    title: Test/LC/stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/TUNA/HUPC2025-K.test.cpp
    title: Test/TUNA/HUPC2025-K.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"atcoder/modint\"\
    \n#include \"atcoder/convolution\"\n\n#include <vector>\n\nnamespace zawa {\n\n\
    template <usize MOD = 998244353>\nstd::vector<atcoder::static_modint<MOD>> StirlingNumberSecondKindFixedN(usize\
    \ n) {\n    using mint = atcoder::static_modint<MOD>;\n    std::vector<mint> ifac(n+1);\n\
    \    mint fac=1;\n    for (usize i=2 ; i<=n ; i++)\n        fac*=mint::raw(i);\n\
    \    ifac[n]=fac.inv();\n    for (usize i=n ; i>=1 ; i--)\n        ifac[i-1]=ifac[i]*mint::raw(i);\n\
    \    std::vector<mint> a(n+1),b(n+1);\n    for (usize i=0 ; i<=n ; i++) {\n  \
    \      a[i]=mint::raw(i).pow(n)*ifac[i];\n        b[i]=(i&1?mint{-1}:mint{1})*ifac[i];\n\
    \    }\n    auto pd=atcoder::convolution(a,b);\n    pd.resize(n+1);\n    return\
    \ pd;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Combinatorics/StirlingNumberSecondKindFixedN.hpp
  requiredBy: []
  timestamp: '2026-10-01 22:30:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/stirling_number_of_the_second_kind.test.cpp
  - Test/TUNA/HUPC2025-K.test.cpp
documentation_of: Src/Combinatorics/StirlingNumberSecondKindFixedN.hpp
layout: document
title: "\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306B\u95A2\u3059\u308B\u30E1\u30E2"
---

# 第一種スターリング数

第一種スターリング数 $c(n,k)$ は $n$ 要素の順列であって、巡回置換に分解すると $k$ 個のサイクルに分かれるものの個数。特に $s(n,k)=(-1)^{n-k}c(n,k)$ を符号付き第一種スターリング数と呼ぶことがある。

## 性質

$$
c(n,k)=c(n-1,k-1)+(n-1)c(n-1,k)
$$

$$
s(n,k)=s(n-1,k-1)-(n-1)s(n-1,k)
$$

はじめにこの式が成り立つ。これは $N-1$ 要素の並べかたを決めた上で最後の一要素をどう挿入するか？を考えると自然に成り立つことがわかる。

$$
\sum_{k=0}^{n}c(n,k)x^k=x(x+1)\cdots (x+n-1)
$$


$$
\sum_{k=0}^{n}s(n,k)x^k=x(x-1)\cdots (x-n+1)
$$

である。

$c(n,k)$ に関する証明だけ証明を与える。 $P_{n}(x) = \sum_{k=0}^{n}c(n,k)x^k$ と多項式 $P_{n}(x)$ を置く。

$$
P_{n}(x)&=\sum_{k=0}^{n}(c(n-1,k-1)+(n-1)c(n-1,k))x^{k}
&= xP_{n-1}(x)+(n-1)P_{n-1}(x)
&= (x+n-1)P_{n-1}(x)
$$

が成り立つ。特に、 $P_{0}(x)=1$ であるため、帰納法が回る。 $\square$

ライブラリ化していないが、分割統治とpolynomial taylor shiftで $n$ を固定したときの $k$ に関する列挙ができることがわかる。

# 第二種スターリング数

$n$ 要素を非空(かつdisjoint)な $k$ 個の部分集合に分ける通り数 $s(n,k)$

- 写像12相でいうと、 $n$ 個の区別できるボールを $k$ 個の区別できない箱に各箱に $1$ 個以上のボールが入るように入れる通り数
- 特に、箱に区別をつけるだけなら $s(n,k)k!$ となる。
- $s(n,0)+s(n,1)+\cdots+s(n,k)$ はベル数 $B(n,k)$ に一致する

包除原理を考えることで

$$
s(n,k) = \frac{1}{k!}\sum_{i=0}^{k} (-1)^{k-i}\binom{k}{i}i^n
$$

である。

理屈はよくわかってないが、第二種スターリング数の指数型母関数は以下の通りのようだ

- [https://www.nomuramath.com/q0szm60a/](https://www.nomuramath.com/q0szm60a/) に一覧が証明つきでのっている

$$
\sum_{n=k}^{\infty}S(n,k)\frac{x^n}{n!}=\frac{(e^{x}-1)^k}{k!}
$$

# このライブラリ

$n$ が与えられて $S(n,0),S(n,1),\dots,S(n,n)$ を畳み込みを利用して $O(n\log n)$ で列挙している。
