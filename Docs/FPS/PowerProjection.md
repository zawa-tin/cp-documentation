---
title: FPS Power Projection
documentation_of: //Src/FPS/PowerProjection.hpp
---

## 概要

長さ $n$ の数列 $W = (W_0, W_1, \dots, W_{n - 1})$ 、正整数 $m$ 、 FPS $F(x)$ に対して

$$
\sum_{i = 0}^{n - 1} w_{i}([x^i]F(x)^{j})
$$

を $j = 0, 1, 2, \dots, m - 1$ に対して列挙する。

## ライブラリの使い方

```cpp
template <concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
std::vector<typename FPS::value_type> PowerProjection(usize m, FPS W, FPS F, Conv convolution = {}) {
```

`FPS=FPSNTTFriendly<MOD>`の場合、`convolution`は自動的に`operator*`が使われる。それ以外の場合は自分で`convolution`を指定する必要がある。

- $2$ 乗かけて愚直にやる畳み込みは`FPS.hpp`の`NaiveConvolution`を使うと良い。

**計算量**
- $N$ を `bit_ceil<usize>(n)` とする。
- 長さ $2N$ の列同士の畳み込みを $\log_{2}N$ 回行う
- 長さ $m$ の列同士の畳み込みを高々 $1$ 回行う
- $+O(N\log N + m)$
- つまるところ、`FPSNTTFriendly<MOD>`では $O(n\log^2 n + m\log m)$
