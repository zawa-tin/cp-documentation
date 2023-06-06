---
title: 1次元累積和
documentation_of: //Src/DataStructure/PrefixSum1D/PrefixSum1D.hpp
---

## 概要

群 $(S, \oplus)$ の上で列 $A$ 上のクエリ $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を処理することができる。ただし、 $A$ に値の変更があってはならない。

<br />

## ライブラリの使い方

#### テンプレート引数Group

[本ライブラリにおける群の実装について](https://zawa-tin.github.io/cp-documentation/Docs/Appendix/Group.html) をご確認ください。

以下、テンプレート引数の`ValueType`を`T`と略します。

<br />

#### コンストラクタ
```
(1) PrefixSum1D = default
(2) PrefixSum1D(const std::vector<T>& A)
```
(1) デフォルトコンストラクタ

(2) $A$ によって累積和 $S$ を構築します。処理する列 $A$ を`std::vector<T>`として引数に入れてください。以降、 $A$ の長さを $N$ とします。

**計算量:** $O(N)$

<br />

#### operator[]
```
inline T operator[](u32 i) const
```
$S_i$ を返します。(0-indexedです)

**制約:** $i\ \le\ N$

**計算量:** 定数時間

<br />

#### size
```
inline usize size() const
```
$S$ の長さを返します。すなわち $N + 1$ です。

**計算量:** 定数時間

<br />

#### product
```
T product(u32 l, u32 r) const
```

$\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を返します。(0-indexedです)

**制約:** $l\ \le\ r\ \le\ N$

**計算量:** 定数時間

<br />

#### maxRight
```cpp
u32 maxRight<F>(u32 l, const F& f) const
```
$S \to \\{ \text{true}, \text{false} \\}$ でありかつ単調性を持つ関数 $f$ に対して、 $\displaystyle f(\sum_{i = l}^{r - 1} A_i) = \text{true}$ を満たす最大の $r$ を返します。

`f`は関数オブジェクトを入れる必要があります。(ラムダ式とか`std::function<bool(T)>`とかを引数に入れることができる)

**制約:** 
- $e =$ `Group::identity()`として $f(e) = \text{true}$ を満たすこと
- $f$ に副作用が無いこと、あったとしても同じ値を引数に入れたのなら常に同じ結果を返すこと
- $l\ \le\ N$

<br />

#### minLeft

未テストでかつ実装に自信が無いです。

```cpp
u32 minLeft<F>(u32 r, const F& f) const
```
$S \to \\{ \text{true}, \text{false} \\}$ でありかつ単調性を持つ関数 $f$ に対して、 $\displaystyle f(\sum_{i = l}^{r - 1} A_i) = \text{true}$ を満たす最小の $l$ を返します。

`f`は関数オブジェクトを入れる必要があります。(ラムダ式とか`std::function<bool(T)>`とかを引数に入れることができる)

**制約:** 
- $e =$ `Group::identity()`として $f(e) = \text{true}$ を満たすこと
- $f$ に副作用が無いこと、あったとしても同じ値を引数に入れたのなら常に同じ結果を返すこと
- $l\ \le\ N$

<br />

## アルゴリズム

簡単のため、 $S = \mathbb{Z}$ 、 $\oplus = +$ で考えます。(群の条件を満たすなら他の $(S, \oplus)$ でも勿論なりたちます)

数列 $A$ に対して、 $\displaystyle S_i = A_0 + A_1 + \dots + A_{i - 1} = \sum_{j = 0}^{i - 1} A_{j}$ が成り立つ $S$ を $A$ の累積和(prefix sum、cumulative sum)と呼びます。

例えば、 $A = (1, 3, -2, 4, 3)$ ならば、 $S = (0, 1, 4, 2, 6, 9)$ です。

$\displaystyle \sum_{i = l}^{r - 1} A_i = \sum_{i = 0}^{r - 1} A_i - \sum_{i = 0}^{l - 1} A_i = S_{r} - S_{l}$ が成り立つので、愚直より高速に $\displaystyle \sum_{i = l}^{r - 1} A_i$ を求めることが可能です。

上の例で一つ区間和の例をとると、 $A_1 + A_2 + A_3 = 3 - 2 + 4 = 5, S_{4} - S_{1} = 6 - 1 = 5$ で確かに一致していることがわかります。他の例でも成り立つと思います。

なんか、不定積分と定積分を思い出しますね。似た概念なのかは知りませんが。

<br />

## メモ

可換でない群で累積和を構築する時は注意が必要です。例えば、可換で無い群上で列のSuffix Sumが欲しい時にこのライブラリを貼ると死にます。(`product(l, r)`の値が異なります)
- そもそもそのような実装に注意を払うべきであるような場合は、ライブラリを使うべきでは無いのかも?
