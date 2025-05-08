---
title: Polynomial Taylor Shift
documentation_of: //Src/FPS/PolynomialTaylorShift.hpp
---

## 概要

多項式 $f(x)$ 及び整数 $c$ に対して $f(x+c) = g(x)$ を満たす多項式 $g(x)$ の係数列を $\Theta (N\log N)$ で計算する。

## ライブラリの使い方

```cpp
template <class T, std::integral C, class F>
std::vector<T> PolynomialTaylorShift(std::vector<T> a, C c, F convolution) {
```

`convolution`は畳み込み計算をする関数を渡す。`atcoder::convolution<atcoder::modint998244353>`を渡しておけば今の所は大丈夫そう？
