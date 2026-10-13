---
title: 二項係数prefix sum $(\sum_{i=0}^{k}\binom{n}{i})$
documentation_of: //Src/Combinatorics/BinomialCoefficientPrefixSums.hpp
---

## 概要

```cpp
template <class T,std::signed_integral U>
std::vector<T> BinomialCoefficientPrefixSums(std::vector<std::pair<U,U>> P)
```

$Q$ クエリ与えられる。 $i$ 番目のクエリでは $\sum_{j=0}^{k_{i}}\binom{n_i}{j}$ を求めよ

という問題をMo's Algorithmでオフライン処理する。 クエリ $(n,k)$ に対する答えを $f(n,k)$ とすると...

$$
\begin{aligned}
f(n+1,k) &= 2f(n,k)-\binom{n}{k} \\
\frac{1}{2}(f(n+1,k)+\binom{n}{k}) &= f(n,k)
\end{aligned}
$$

という関係式が成り立つので、 $n$ を $1$ 動かす差分更新が高速にできる。 $k$ に対する差分更新は自明。

クエリの $n$ の最大値を $N$ として、計算量は $O(N\sqrt{Q} + Q\log Q)$ である。

## 制約

`T`として基本的に $\mathbb{F}_{p}$ を用いることが暗黙に仮定されている。このときの`T`は $2,N!$ の乗法逆元が定義できることが必要であることに注意せよ。

クエリで与える $n,k$ はどちらも非負であることを仮定している。なお、内部で用いるMo's Algorithmの都合上、 $n,k$ の型である`U`は符号付である必要がある。

## 更新履歴

- 2026/10/13: 作成
