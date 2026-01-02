---
title: 線形漸化式のK項目を計算する
documentation_of: //Src/FPS/KthTerm.hpp
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
