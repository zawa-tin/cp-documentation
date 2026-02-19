---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/BostanMori.hpp
    title: "$[x^{N}]\\frac{P(x)}{Q(x)}$ \u306E\u9AD8\u901F\u8A08\u7B97 (Bostan-Mori\
      \ \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)"
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPS.hpp
    title: Src/FPS/FPS.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPSNTTFriendly.hpp
    title: Src/FPS/FPSNTTFriendly.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/tdpc_fibonacci.test.cpp
    title: Test/AtCoder/tdpc_fibonacci.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/3044.test.cpp
    title: Test/yukicoder/3044.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"FPSNTTFriendly.hpp\"\
    \n#include \"BostanMori.hpp\"\n\nnamespace zawa {\n\ntemplate <concepts::IndexedFPS\
    \ FPS, class Conv = FPSMult>\ntypename FPS::value_type KthTerm(u64 K, FPS A, FPS\
    \ C, Conv conv = {}) {\n    assert(C.size() >= 2 and C[0] == 0);\n    assert(A.size()\
    \ >= C.size() - 1);\n    if (K < A.size()) \n        return A[K];\n    for (auto&\
    \ v : C)\n        v = -v;\n    C[0] = 1;\n    FPS multed = conv(A, C);\n    multed.resize(C.size()\
    \ - 1);\n    return BostanMori(K, multed, C, conv);\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/FPS/FPSNTTFriendly.hpp
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  - Src/FPS/BostanMori.hpp
  isVerificationFile: false
  path: Src/FPS/KthTerm.hpp
  requiredBy: []
  timestamp: '2026-01-03 22:37:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
  - Test/yukicoder/3044.test.cpp
  - Test/AtCoder/tdpc_fibonacci.test.cpp
documentation_of: Src/FPS/KthTerm.hpp
layout: document
title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u306EK\u9805\u76EE\u3092\u8A08\u7B97\u3059\u308B"
---

## 概要

漸化式 $a_{n} = \sum_{i = 1}^{d} c_{i}a_{n - i}$ の $K$ 項目を計算する。

## ライブラリ

```
template <concepts::IndexedFPS FPS, class Conv = FPSMult>
typename FPS::value_type KthTerm(u64 K, FPS A, FPS C, Conv conv = {}) {
```

$C$ は1-indexedですよ！

- $\mid C\mid \ge 2$
- $C_{0} = 0$
- $\mid A\mid \ge d$

`conv`は`FPSNTTFriendly`のときは何も指定しなくても良い。それ以外のときは畳み込みをする関数オブジェクトを与える。

$\Theta O(NM)$ の畳み込みは`FPS.hpp`の`NaiveConvolution`を与えると良い。

## アルゴリズム

$a$ の母関数を $A(x)$ 、 $Q(x) = 1 - \sum_{i = 1}^{d} c_{i}x^{i}$ とすると、 $A(x)Q(x)$ の $d$ 次以上の係数は $0$ になる。 これを $P(x)$ とおくと $[x^{K}]\frac{P(x)}{Q(x)}$ を計算することに帰着していて、Bostan-Moriアルゴリズムを使うと良い。

## 参考

- [線形漸化式のN項目の計算](https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a)
