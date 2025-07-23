---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/NTL_1_E.test.cpp
    title: Test/AOJ/NTL_1_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc340_f.test.cpp
    title: ABC340-F S = 1
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Number/ExtendGCD.hpp\"\n\n#include <utility>\n\nnamespace\
    \ zawa {\n\ntemplate <class T>\nstd::pair<T, T> ExtendGCD(T a, T b) {\n    if\
    \ (a == 0) return { T{0}, 1 };\n    if (b == 0) return { T{1}, 0 };\n    T px{1},\
    \ py{0}, x{0}, y{1};\n    while (a % b) {\n        T d{a / b}, r{a % b};\n   \
    \     T nx{px - d*x}, ny{py - d*y};\n        px = x;\n        py = y;\n      \
    \  x = nx;\n        y = ny;\n        a = b;\n        b = r;\n    }\n    return\
    \ {x, y};\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <utility>\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nstd::pair<T, T> ExtendGCD(T a, T b) {\n    if (a == 0) return { T{0}, 1\
    \ };\n    if (b == 0) return { T{1}, 0 };\n    T px{1}, py{0}, x{0}, y{1};\n \
    \   while (a % b) {\n        T d{a / b}, r{a % b};\n        T nx{px - d*x}, ny{py\
    \ - d*y};\n        px = x;\n        py = y;\n        x = nx;\n        y = ny;\n\
    \        a = b;\n        b = r;\n    }\n    return {x, y};\n}\n\n} // namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Number/ExtendGCD.hpp
  requiredBy: []
  timestamp: '2024-11-29 05:08:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Manual/abc340_f.test.cpp
  - Test/AOJ/NTL_1_E.test.cpp
documentation_of: Src/Number/ExtendGCD.hpp
layout: document
title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
---

## 概要

整数 $a, b$ に対して、 $as + bt = \gcd(a, b)$ または $as + bt = -\gcd(a, b)$ を満たす $s, t$ の組を一つ返す。

## ライブラリの使い方

```cpp
template<class T>
std::pair<T, T> ExtendGCD(T a, T b)
```

firstに $s$ , secondに $b$ が入る。

整数であることが要求される。

## アルゴリズム

毎回わかんなくなるので、詳しめに書いておく。

### ユークリッドの互除法

通常のユークリッドの互除法から振り返る。

$x_{0} = a, x_{1} = b$ として、 $n = 2, 3, \dots$ と $x_{n}\leftarrow$ $x_{n - 2}$ を $x_{n - 1}$ で割ったあまりとしていく。

$x_{N + 1} = 0$ であるとき、 $\gcd(a, b) = x_{N}$ であるとして、操作を打ち切る。

**定理1**

$x_{N} = \gcd(a, b)$ である

**証明.**

$a = 0$ や $b = 0$ のときは簡単である。 $a \gt0, b \gt 0$ を仮定する。

まず、 $x_{i} \gt x_{i - 1}, x_{i - 2}$ が成り立つので、 $i \ge 2$ で $x_{i}$ は単調減少である。よって $x_{N + 1} = 0$ となる $N$ が必ず存在する。

$\gcd(x_{i - 2}, x_{i - 1}) = \gcd(x_{i - 1}, x_{i})$ であることを示す。これが示せたら $\gcd(a, b) = \gcd(x_0, x_1) = \gcd(x_N, x_{N + 1}) = \gcd(x_N, 0) = x_N$ であるため、目標も示される。

$x_{i - 2}, x_{i - 1}$ の公約数を一つとって $d$ とする。ある整数 $p, q$ が存在して $x_{i - 2} = dp, x_{i - 1} = dq$ である。また、定義よりある整数 $y$ が存在して $x_{i - 2} = x_{i - 1}y + x_{i}$ である。式変形により $x_{i} = x_{i - 2} - x_{i - 1}y$ を得る。

この式に $x_{i - 2}, x_{i - 1}$ に関する等式を代入すると、 $x_{i} = dp - dqy = d(p - qy)$ を得る。 $p - qy$ は整数であるため、 $x_{i}$ は $d$ の倍数である。すなわち $x_{i}, x_{i - 1}$ の公約数に $d$ を持つ。

このことから $x_{i - 2}, x_{i - 1}$ の公約数であるとき、またそのときに限り $x_{i - 1}, x_{i}$ の公約数でもあることがわかる。よって最大公約数も一致する $\square$

実装上は $x$ を数列として持つ必要は無い。なぜなら $x_{i}$ は $x_{i - 2}, x_{i - 1}$ のみから特定できるためである。

```cpp
T gcd(T a, T b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}
```

### 一次不定方程式を解く

**定理2**

$as + bt = \gcd(a, b)$ を満たす $s, t$ が必ず存在する。

**証明.**

$as + bt = x_{i}$ を満たすような $s, t$ が各 $i$ について示す。これが示されれば、 $x_{N} = \gcd(a, b)$ であるため、目標も示される。

帰納法を用いる。

$n = 0$ のとき、 $s = 1, t = 0$ が条件を満たす。

$n = 1$ のとき、 $s = 0, t = 1$ が条件を満たす。

$n = 0, 1, \dots k - 1$ のとき条件を満たすと仮定する。

$n = k$ のとき、

定理1の証明から、ある整数 $y$ が存在して　$x_{k} = x_{k - 2} - x_{k - 1}y$ を満たす。

仮定より、 $x_{k - 2} = as_{k - 2} + bt_{k - 2}, x_{k - 1} = as_{k - 1} + bt_{k - 1}$ を満たす $s_{k - 2}, s_{k - 1}, t_{k - 2}, t_{k - 1}$ が存在する。

これを代入して式を整理すると $x_{k} = a(s_{k - 2} - ys_{k - 1}) + b(t_{k - 2} - yt_{k - 1})$ を得る。 $s_{k - 2} - ys_{k - 1}, t_{k - 2} - yt_{k - 1}$ は整数である。 $\square$

この $x_{k} = a(s_{k - 2} - ys_{k - 1}) + b(t_{k - 2} - yt_{k - 1})$ から(非再帰の)拡張ユークリッドの互除法を得ることができる。

## 参考

木田雅成.連分数.近代科学社,2022,[大学数学 スポットライト・シリーズ]
