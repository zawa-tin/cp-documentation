---
title: SparseFPS::Integral
documentation_of: //Src/SparseFPS/Integral.hpp
---

## 概要

```cpp
template <std::integral Degree,class Coef>
Series<Degree,Coef> Integral(const Series<Degree,Coef>& f)
```

非零な係数の個数が十分に少ない形式的冪級数 $f$ に関して、積分定数を零として積分を計算する。

返り値は疎な形式的冪級数であり、入力の各項 $cx^d$ を $\frac{c}{d+1}x^{d+1}$ に変換したものである。返り値の要素数は $f$ の要素数と等しく、定数項は格納しない。

空の列を渡した場合は、空の列を返す。

## 制約

入力は`Series<Degree,Coef>`の共通の制約に加えて、各項の次数 $d$ について次を満たすこと。

- $d+1$ を計算する際にオーバーフローせず、`Degree`型で表現できること。
- 係数型における $d+1$ に乗法逆元が存在すること(特に、素数 $p$ を法とするmodintでは、 $d+1$ が $p$ の倍数でないこと)。

## 計算量

計算量は、 $f$ の要素数を $k$ として $O(k)$ 。ただし、係数の除算を $O(1)$ とする。

乗法逆元の計算を $O(\log MOD)$ 、それ以外の係数の演算を $O(1)$ とする場合、各項について $d+1$ の逆元を計算するため、全体で $O(k\log MOD)$ かかる。ここで、 $MOD$ は係数の法である。

## 更新履歴

- 2026/10/24: 作成
- 2026/10/25: 乗法逆元の計算量を含む解析を追記
