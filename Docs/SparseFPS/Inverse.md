---
title: SparseFPS::Inv
documentation_of: //Src/SparseFPS/Inverse.hpp
---

## 概要

```cpp
template <std::integral Degree,class Coef>
std::vector<Coef> Inv(const Series<Degree,Coef>& f,usize n)
```

非零な係数の個数が十分に少ない形式的冪級数 $f$ に関して、 $fg=1$ を満たす $g$ の $\mod{x^n}$ を計算する。

返り値は長さ $n$ の列であり、 $i$ 番目の要素が $[x^i]g$ に対応している。

## 制約

形式的冪級数 $f$ は $[x^0]f$ が乗法逆元を持つときに、自身の逆元が定義される。これを本ライブラリの言葉で書くと次の通りとなる。

- $f$ は空ではなく、`f[0].degree`が $0$ であること。
- `f[0].coef`に乗法逆元が存在すること(特に、`atcoder::modint998244353`下では、単に $0$ でないこと)

## 計算量

計算量は、 $f$ の要素数を $k$ として $O(nk)$  。

## 更新履歴

- 2026/10/24: 作成
