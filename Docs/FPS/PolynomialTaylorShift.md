---
title: Polynomial Taylor Shift
documentation_of: //Src/FPS/PolynomialTaylorShift.hpp
---

## 概要

多項式 $f(x)$ 及び整数 $c$ に対して $f(x+c) = g(x)$ を満たす多項式 $g(x)$ の係数列を $\Theta (N\log N)$ で計算する。

## ライブラリの使い方

```cpp
template <class C, concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
FPS PolynomialTaylorShift(FPS a, C c, Conv conv = {})
```

`conv`は畳み込みの関数。`FPSNTTFriendly`を使う際は何も指定しなくて良い。

$\Theta(NM)$ かけてやる愚直な畳み込みは `FPS.hpp` の `NaiveConvolution` の実体を与えると良い。
