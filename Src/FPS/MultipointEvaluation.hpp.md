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
    path: Src/FPS/SubproductTree.hpp
    title: Subproduct Tree
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/PolynomialInterpolationFast.hpp
    title: "\u591A\u9805\u5F0F\u88DC\u9593 $O(N\\log^2N)$"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/fps_24_p.test.cpp
    title: Test/AtCoder/fps_24_p.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/multipoint_evaluation.test.cpp
    title: Test/LC/multipoint_evaluation.test.cpp
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
  code: "#pragma once\n\n#include \"FPSNTTFriendly.hpp\"\n#include \"SubproductTree.hpp\"\
    \n#include \"DivisionOfPolynomials.hpp\"\n\n#include <vector>\n\nnamespace zawa\
    \ {\n\nnamespace internal {\n\ntemplate <usize MOD = 998244353>\nstd::vector<typename\
    \ FPSNTTFriendly<MOD>::V> MultipointEvaluation(const FPSNTTFriendly<MOD>& f,const\
    \ SubproductTree<FPSNTTFriendly<MOD>>& tree) {\n    using fps = FPSNTTFriendly<MOD>;\n\
    \    using mint = fps::V;\n    const usize n=tree.innerSize();\n    std::vector<fps>\
    \ rem(n<<1);\n    rem[1] = DivisionOfPolynomials(f,tree[1]).second;\n    for (usize\
    \ i = 1 ; i < n ; i++) {\n        rem[i<<1|0] = DivisionOfPolynomials(rem[i],tree[i<<1|0]).second;\n\
    \        rem[i<<1|1] = DivisionOfPolynomials(rem[i],tree[i<<1|1]).second;\n  \
    \  }\n    std::vector<mint> res(tree.size());\n    for (usize i = 0 ; i < tree.size()\
    \ ; i++)\n        res[i]=rem[n+i].empty()?mint{0}:rem[n+i][0];\n    return res;\n\
    }\n\n} // namespace internal\n\ntemplate <usize MOD = 998244353>\nstd::vector<typename\
    \ FPSNTTFriendly<MOD>::V> MultipointEvaluation(const FPSNTTFriendly<MOD>& f,const\
    \ std::vector<typename FPSNTTFriendly<MOD>::V>& xs) {\n    using fps = FPSNTTFriendly<MOD>;\n\
    \    using mint = fps::V;\n    if (f.empty() or xs.empty())\n        return std::vector(xs.size(),mint{0});\n\
    \    SubproductTree prod([&]() -> std::vector<fps> {\n                std::vector<fps>\
    \ res(xs.size());\n                for (usize i = 0 ; i < xs.size() ; i++)\n \
    \                   res[i]={-xs[i],mint::raw(1)};\n                return res;\n\
    \            }());\n    return internal::MultipointEvaluation(f,prod);\n}\n\n\
    } // namespace zawa\n"
  dependsOn:
  - Src/FPS/FPSNTTFriendly.hpp
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  - Src/FPS/SubproductTree.hpp
  - Src/FPS/DivisionOfPolynomials.hpp
  isVerificationFile: false
  path: Src/FPS/MultipointEvaluation.hpp
  requiredBy:
  - Src/FPS/PolynomialInterpolationFast.hpp
  timestamp: '2026-10-26 13:52:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/fps_24_p.test.cpp
  - Test/LC/multipoint_evaluation.test.cpp
  - Test/LC/polynomial_interpolation/fast.test.cpp
documentation_of: Src/FPS/MultipointEvaluation.hpp
layout: document
title: "\u591A\u70B9\u8A55\u4FA1(Multipoint Evaluation)"
---

## 概要

多項式 $f$ 及び $n$ 個の点 $x_0,x_1,\dots,x_{n-1}$ が与えられたとき、 $f(x_0),f(x_1),\dots,f(x_{n-1})$ を列挙する。

ただし、使用しているアルゴリズムと自分のライブラリ不足の都合により、 $f$ は`FPSNTTFriendly<MOD>`であることが要求される。

## ライブラリの使い方

```cpp 
template <usize MOD = 998244353>
std::vector<typename FPSNTTFriendly<MOD>::V> MultipointEvaluation(const FPSNTTFriendly<MOD>& f,const std::vector<typename FPSNTTFriendly<MOD>::V>& xs)
```

`f`が $f$ に、 `xs` が $(x_0,x_1,\dots,x_{n-1})$ に対応している。

返り値は長さ $n$ の`vector<mint>`であり、 $i$ 番目の要素が $f(x_{i})$ である。

## 計算量

$f$ が $m$ 次多項式であるとして、 $O(m\log m+n\log^2 n)$

## 更新履歴

- 2026/05/06: 作成
- 2026/10/26: SubproductTreeを利用する実装に変更。構築済みの木を受け取る内部関数を切り出した
- 2026/10/26: ドキュメントを作成
