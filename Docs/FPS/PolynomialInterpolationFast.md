---
title: 多項式補間 $O(N\log^2N)$
documentation_of: //Src/FPS/PolynomialInterpolationFast.hpp
---

## 概要

$N$ は正整数とする。NTT-Friendlyな素数 $p$ について $\mathbb{F}_{p}$ 上の長さ $N$ の数列 $x=(x_1,x_2,\dots,x_N),y=(y_1,y_2,\dots,y_N)$ が与えられたとする。ただし、 $x$ の各要素は相異なる必要がある。

このとき、 $\forall_{i} f(x_i)=y_i$ を満たすような次数が $N-1$ 以下の多項式を $O(N\log^2 N)$ で構築し、`FPSNTTFriendly<MOD>`として返す。

アルゴリズムは[https://ei1333.hateblo.jp/entry/2021/07/08/221742](https://ei1333.hateblo.jp/entry/2021/07/08/221742)の内容を素直に実装したものとなっている。

## ライブラリの使い方

```cpp
template <usize MOD = 998244353>
FPSNTTFriendly<MOD> PolynomialInterpolationFast(const std::vector<typename FPSNTTFriendly<MOD>::V>& xs,const std::vector<typename FPSNTTFriendly<MOD>::V>& ys)
```

`MOD`が上記の $p$ と対応する。

`xs`が $x$ 、`ys`が $y$ に対応する。`xs,ys`に対応する型は両者とも`std::vector<atcoder::static_modint<MOD>>`である。`xs.size()>0 and xs.size()==ys.size()`が満たされる必要がある。

`xs`に同じ要素が複数含まれている場合、その動作は保証されない。

返り値は上位の項が $0$ であるかに関わらず、長さ $N$ である。添え字 $i$ の要素が $x^i$ の係数に対応する。

## 更新履歴

- 2026/10/25: 作成
- 2026/10/26: SubproductTreeを切り出した実装に変更。LCで150msほど改善
