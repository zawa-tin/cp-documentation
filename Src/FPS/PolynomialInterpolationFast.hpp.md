---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/DivisionOfPolynomials.hpp
    title: Src/FPS/DivisionOfPolynomials.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPS.hpp
    title: Src/FPS/FPS.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPSNTTFriendly.hpp
    title: Src/FPS/FPSNTTFriendly.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/MultipointEvaluation.hpp
    title: "\u591A\u70B9\u8A55\u4FA1(Multipoint Evaluation)"
  - icon: ':heavy_check_mark:'
    path: Src/FPS/PolynomialProducts.hpp
    title: "\u6B21\u6570\u306E\u7DCF\u548C\u304C\u6291\u3048\u3089\u308C\u3066\u3044\
      \u308B\u591A\u9805\u5F0F\u306E\u5217\u306E\u7DCF\u7A4D"
  - icon: ':heavy_check_mark:'
    path: Src/FPS/SubproductTree.hpp
    title: Subproduct Tree
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/polynomial_interpolation/fast.test.cpp
    title: Test/LC/polynomial_interpolation/fast.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"FPSNTTFriendly.hpp\"\n#include \"MultipointEvaluation.hpp\"\
    \n#include \"SubproductTree.hpp\"\n#include \"PolynomialProducts.hpp\"\n\n#include\
    \ <utility>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <usize MOD = 998244353>\n\
    FPSNTTFriendly<MOD> PolynomialInterpolationFast(const std::vector<typename FPSNTTFriendly<MOD>::V>&\
    \ xs,const std::vector<typename FPSNTTFriendly<MOD>::V>& ys) {\n    assert(xs.size());\n\
    \    assert(xs.size() == ys.size());\n    using fps=FPSNTTFriendly<MOD>;\n   \
    \ using mint=typename fps::V;\n    const usize n=xs.size();\n    std::vector<fps>\
    \ leafs(n);\n    for (usize i = 0 ; i < n ; i++)\n        leafs[i]={-xs[i],mint::raw(1)};\n\
    \    SubproductTree tree(std::move(leafs));\n    std::vector<mint> W=internal::MultipointEvaluation(tree.root().differential(),tree);\n\
    \    std::vector<mint> prodW(n+1,mint::raw(1));\n    for (usize i = 0 ; i < n\
    \ ; i++)\n        prodW[i+1]=prodW[i]*W[i];\n    mint inv=prodW[n].inv();\n  \
    \  for (usize i = n ; i >= 1 ; i--) {\n        mint cur=W[i-1];\n        W[i-1]=inv*prodW[i-1];\n\
    \        inv*=cur;\n    }\n    std::vector<fps> res(tree.innerSize()<<1);\n  \
    \  for (usize i = 0 ; i < n ; i++)\n        res[tree.innerSize()+i]=fps{ys[i]*W[i]};\n\
    \    for (usize i = tree.innerSize() ; --i ; ) {\n        res[i]=std::move(res[i<<1|0])*tree[i<<1|1];\n\
    \        res[i]+=tree[i<<1|0]*std::move(res[i<<1|1]);\n    }\n    return res[1];\n\
    }\n\n} // namespace zawa\n"
  dependsOn:
  - Src/FPS/FPSNTTFriendly.hpp
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  - Src/FPS/MultipointEvaluation.hpp
  - Src/FPS/SubproductTree.hpp
  - Src/FPS/DivisionOfPolynomials.hpp
  - Src/FPS/PolynomialProducts.hpp
  isVerificationFile: false
  path: Src/FPS/PolynomialInterpolationFast.hpp
  requiredBy: []
  timestamp: '2026-10-26 13:52:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/polynomial_interpolation/fast.test.cpp
documentation_of: Src/FPS/PolynomialInterpolationFast.hpp
layout: document
title: "\u591A\u9805\u5F0F\u88DC\u9593 $O(N\\log^2N)$"
---

## 概要

$N$ は正整数とする。NTT-Friendlyな素数 $p$ について $\mathbb{F}_{p}$ 上の長さ $N$ の数列 $x=(x_1,x_2,\dots,x_N),y=(y_1,y_2,\dots,y_N)$ が与えられたとする。ただし、 $x$ の各要素は相異なる必要がある。

このとき、 $\forall_{i} f(x_i)=y_i$ を満たすような次数が $N-1$ 以下の多項式を $O(N\log^2 N)$ で構築し、`FPSNTTFriendly<MOD>`として返す。

アルゴリズムは[https://ei1333.hateblo.jp/entry/2021/07/08/221742](https://ei1333.hateblo.jp/entry/2021/07/08/221742)の内容を素直に実装したものとなっている。

## ライブラリの使い方

```cpp
template <usize MOD = 998244353>
FPSNTTFriendly<MOD> PolynomialInterpolationFast(const std::vector<typename FPSNTTFriendly<MOD>::V>& xs,const std::vector<typename FPSNTTFriendly<MOD>::V>& ys)
```

`MOD`が上記の $p$ と対応する。

`xs`が $x$ 、`ys`が $y$ に対応する。`xs,ys`に対応する型は両者とも`std::vector<atcoder::static_modint<MOD>>`である。`xs.size()>0 and xs.size()==ys.size()`が満たされる必要がある。

`xs`に同じ要素が複数含まれている場合、その動作は保証されない。

返り値は上位の項が $0$ であるかに関わらず、長さ $N$ である。添え字 $i$ の要素が $x^i$ の係数に対応する。

## 更新履歴

- 2026/10/25: 作成
- 2026/10/26: SubproductTreeを切り出した実装に変更。LCで150msほど改善
