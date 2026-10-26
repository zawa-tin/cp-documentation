---
title: 多点評価(Multipoint Evaluation)
documentation_of: //Src/FPS/MultipointEvaluation.hpp
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
