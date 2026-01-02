---
title: $[x^{N}]\frac{P(x)}{Q(x)}$ の高速計算 (Bostan-Mori アルゴリズム)
documentation_of: //Src/FPS/BostanMori.hpp
---

## 概要

## ライブラリの説明

```
template <concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
typename FPS::value_type BostanMori(usize N, FPS P, FPS Q, Conv conv = {})
```

$[x^N]\frac{P(x)}{Q(x)}$を計算する

`conv`は`FPSNTTFriendly`のときは何も指定しなくても良い。それ以外のときは畳み込みをする関数オブジェクトを与える。

$\Theta O(NM)$ の畳み込みは`FPS.hpp`の`NaiveConvolution`を与えると良い。

**計算量**

- 畳み込みを $2\times \lceil\log_{2}(N + 1)\rceil$ 回行うのがボトルネック
