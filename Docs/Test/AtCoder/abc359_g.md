---
title: ABC359-G Sum of Tree Distance
documentation_of: //Test/AtCoder/abc359_g.test.cpp
---

$N$ 頂点からなる木について $\sum_{i = 1}^{N - 1} \sum_{j = i + 1}^{N} \text{dist}(i, j)$ を求める方法。

木dpを考える。頂点 $v$ を根とした部分木について以下の三つの情報を持つ。

- $K_{v}$ 部分木の頂点数
- $A_{v}$ 部分木の頂点集合を $C = (C_{1}, C_{2}, \dots, C_{K_{v}})$ としたときの $\sum_{i = 1}^{K_{v} - 1} \sum_{j = i + 1}^{K_{v}} \text{dist}(C_{i}, C_{j})$
- $B_{v}$ 部分木の各頂点について、その頂点から頂点 $v$ までの寄与の和。

$K_{v}$ はOK

$v$ に $x$ をマージするとき、 $A_{v}$ への寄与は $B_{v} \times K_{x} + B_{v} \times (K_{x} + B_{x})$ 。 $B_{v}$ への寄与は $B_{x} + K_{x}$

この問題では木を圧縮しているので、辺の長さが $1$ とは限らず、いくらかの係数をかけ合わせた値が寄与しているところがある。
