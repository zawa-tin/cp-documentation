---
title: $p^k$に対する離散対数問題
documentation_of: //Src/Number/DiscreteLogarithmPrimeLift.hpp
---

## 概要

$a^{x}\equiv b\pmod{p^k}$ を満たす $x$ を一つ発見するか、存在しないことを報告する。

発見した場合は最小値を返す。
- 本当に最小値を返しているかは未verify

$p$は素数であり、ある程度小さい必要がある。

## ライブラリの使い方

```cpp
std::optional<u64> DiscreteLogarithmPrimeLift(u64 a, u64 b, u64 p, u64 k)
```

$p$ が素数、 $p^k$ が $2^{64}$ 以下である必要がある。

**計算量:** $O(p + k\log p)$

さぼっているだけで、ちゃんと実装すると $O(\sqrt{p} + k)$ になるはず。

## 参考

- [Efficient Lifting of Discrete Logarithms Modulo Prime Powers](https://arxiv.org/pdf/2505.07434)
- [上記論文の読解メモ(自分用: 非公開)](https://scrapbox.io/zawatin/Efficient_Lifting_of_Discrete_Logarithms_Modulo_Prime_Powers)
