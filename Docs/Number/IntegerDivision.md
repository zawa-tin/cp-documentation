---
title: 整数同士の切り捨て/切り上げ除算
documentation_of: //Src/Number/IntegerDivision.hpp
---

## 概要

整数同士の除算を行い、その結果に床関数や天井関数を適用したものを返す。

## ライブラリの使い方

#### DivFloor

```cpp
template <class T>
constexpr T DivFloor(T a, T b) 
```

$\lfloor \frac{a}{b} \rfloor$ を計算する。

**制約**

- `T`は整数型であること
- $b \ne 0$

<br />

#### DivCeil

```cpp
template <class T>
constexpr T DivCeil(T a, T b)
```

$\lceil \frac{a}{b} \rceil$ を計算する。

**制約**

- `T`は整数型であること
- $b \ne 0$
