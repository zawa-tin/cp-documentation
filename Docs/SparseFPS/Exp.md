---
title: SparseFPS::Exp
documentation_of: //Src/SparseFPS/Exp.hpp
---

## 概要

```cpp
template <std::integral Degree,class Coef>
std::vector<Coef> Exp(const Series<Degree,Coef>& f,usize n)
```

非零な係数の個数が十分に少ない形式的冪級数 $f$ に関して、 $\exp f$ の $\mod{x^n}$ を計算する。具体的に、 $[x^0]f=0$ なる $f$ に対して、 $\exp f$ とは次のように定義される。

$$
\exp f = \sum_{n=0}^{\infty}\frac{f^n}{n!}
$$

返り値は長さ $n$ の列であり、 $0\le i<n$ について、 $i$ 番目の要素が $[x^i]\exp f$ に対応している。 $n=0$ の場合は、空の列を返す。

## 制約

入力は`Series<Degree,Coef>`の共通の制約に加えて、次を満たすこと。

- $[x^0]f$ が $0$ であること。
- 係数型における整数 $1,2,\dots,n-1$ に乗法逆元が存在すること(特に、素数 $p$ を法とするmodintでは、 $n\le p$ であればよい)。 $n\le 1$ の場合、この条件は不要である。

$n=0$ の場合も、 $f$ の定数項に関する制約を満たす必要がある。

## 計算量

計算量は、 $f$ の要素数を $k$ として $O(n(k+1))$ 。ただし、 $n=0$ の場合は $O(1)$ であり、係数の演算を $O(1)$ とする。

## 更新履歴

- 2026/10/24: 作成
