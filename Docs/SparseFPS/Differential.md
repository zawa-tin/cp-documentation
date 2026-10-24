---
title: SparseFPS::Differential
documentation_of: //Src/SparseFPS/Differential.hpp
---

## 概要

```cpp
template <std::integral Degree,class Coef>
Series<Degree,Coef> Differential(const Series<Degree,Coef>& f)
```

非零な係数の個数が十分に少ない形式的冪級数 $f$ に関して、微分 $f'$ を計算する。

返り値は疎な形式的冪級数であり、入力の各項 $cx^d$ のうち $d>0$ のものを $dcx^{d-1}$ に変換したものである。入力の定数項は取り除く。変換後の係数が零となった項は取り除かない。

空の列を渡した場合は、空の列を返す。

## 制約

入力は`Series<Degree,Coef>`の共通の制約を満たすこと。

## 計算量

計算量は、 $f$ の要素数を $k$ として $O(k)$ 。

## 更新履歴

- 2026/10/24: 作成
