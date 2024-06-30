---
title: 二項係数(素数mod)
documentation_of: //Src/Number/BinomalCoefficients.hpp
---

## 概要

素数 $P$ と $i = 0, 1, \dots, n$ について $i!$ と $x_{i}\times i!\equiv 1\pmod{P}$ なる $x_{i}$ を列挙する。

これによって素数 $P$ に対して $\binom{n}{r}$ 等が高速に求めることができる。

## ライブラリの使い方

#### 型

```cpp
using Value = atcoder::modint
```

dynamic_modintだからちょっと遅いんだよな。うーーーん。流石にAt, ICPCでこれが原因で完数落とすことは無いと信じたいが....

#### コンストラクタ

```cpp
(1) BinomalCoefficients(u32 M)
```

modを $M$ として初期化する。 $M$ が素数でないとき`assert`に引っかかる。

<br />

#### reserve

```cpp
void reserve(u32 n)
```

内部のコンテナのサイズを $n$ にする。現在のコンテナのサイズが $n$ より大きいときは何もしない。

<br />

#### F

```cpp
Value F(i32 n)
```

$n$ が非負ならば $n!$ を、 $n$ が負ならば $(-n)!$ の乗法逆元を返す。

<br />

#### P

```cpp
Value P(i32 p, i32 q)
```

$p$ 個の区別可能なボールから $q$ 個取り出し、それを一列に並べる通り数を返す。

<br />

#### C

```cpp
Value C(i32 p, i32 q)
```

$p$ 個の区別可能なボールから $q$ 個取り出す通り数を返す。すなわち $\binom{p}{q}$ を返す。

<br />

#### H

```cpp
Value H(i32 p, i32 q)
```

$p$ 種類のボールがそれぞれ無数にあるなかで、 $q$ 個取り出す通り数を返す。

いわゆる 「 $p - 1$ 個の仕切りと $q$ 個のボールの並べ方」である。

<br />

#### B

```cpp
Value B(const std::vector<i32>& b)
```

色 $0$ のボールが $b_0$ 個、色 $1$ のボールが $b_{1}$ 個.....

とあるなかで、それらすべてを一列に並べる通り数。ただし、同じ色のボールは区別がつかないとする。
