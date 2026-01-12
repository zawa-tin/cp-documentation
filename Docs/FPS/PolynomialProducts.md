---
title: 次数の総和が抑えられている多項式の列の総積
documentation_of: //Src/FPS/PolynomialProducts.hpp
---

## 概要

## ライブラリの説明

```
template <concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
FPS PolynomialProducts(std::vector<FPS> F, Conv convolution = {}) {
```

`conv`は`FPSNTTFriendly`のときは何も指定しなくても良い。それ以外のときは畳み込みをする関数オブジェクトを与える。

$\Theta O(NM)$ の畳み込みは`FPS.hpp`の`NaiveConvolution`を与えると良い。

**計算量:** 次数の総和を $N$ として $O(N\log^2 N)$ (畳み込みが $O(n\log n)$ であることを前提)
