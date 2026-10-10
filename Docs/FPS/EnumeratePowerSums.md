---
title: $(\sum_{j=1}^{N} A_{j}^{i})$ を $i=0,1,\dots,K$ について列挙する
documentation_of: //Src/FPS/EnumeratePowerSums.hpp
---

## 概要

```cpp
template <concepts::IndexedFPS FPS,class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
FPS EnumeratePowerSums(std::vector<typename FPS::value_type> A,usize K,Conv conv={})
```

表題の通り、 $A_{1},A_{2},\dots,A_{N}\in \mathbb{F}_{p}$ について値 $(\sum_{j=1}^{N} A_{j}^{i})$ を $i=0,1,\dots,K$ について列挙してかえす。

現在の自分のライブラリでは、`FPS`に該当する型は`FPSNTTFriendly`しか存在しない。よってmod $p$ もNTT-Friendlyである必要がある。

## 何をしているのか？

形式的冪級数で定式化すると、

$$
\sum_{i=1}^{N}\frac{1}{1-A_ix}\pmod{x^{K+1}}
$$

を求めればよい。

そのまま有理式の総和を計算してもよいが、今回は

$$
\sum_{i=1}^{N}\frac{1}{1-A_ix}
=N-x\frac{d}{dx}\log\left(\prod_{i=1}^{N}(1-A_ix)\right)
$$

という対数微分の関係式を利用する。

`FPSNTTFriendly` と `PolynomialProducts` を用いた場合、計算量は $O(N\log^2 N+K\log K)$ である。

## 更新履歴

- 2026/10/10 作成
