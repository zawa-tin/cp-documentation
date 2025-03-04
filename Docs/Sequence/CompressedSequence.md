---
title: 座標圧縮
documentation_of: //Src/Sequence/CompressedSequence.hpp
---

## 概要

長さ $N$ の列 $A$ を座標圧縮して、これを管理します。 $A$ の要素の種類数を $M$ 、すなわち $\mid \\{\ x \mid \exists i_{1\le i\le N}\ x = A_i\ \\}\mid = M$ とします。

<br />

## 使い方

#### テンプレート引数T

圧縮する対象の $A$ は`std::vector<T>`である必要があります。

**制約:** `operator<` と `operator==`が定義されている型・クラスであること(無いとコンパイルエラーになります)

<br />

#### コンストラクタ
```
(1) CompressedSequence() = default;
(2) CompressedSequence(const std::vector<T>& A)
(3) CompressedSequence(InputIterator first, InputIterator last)
```

(1) デフォルトコンストラクタ

(2) 引数に与えた $A$ で座標圧縮した列を構築します。

(3) イテレータfirst, last間で構築します。

**計算量:** $O(N\log N)$

<br />

#### size
```cpp
inline usize size() const noexcept
```
$M$ を返します。

**計算量:** 定数時間


<br />

#### operator[]
```cpp
u32 operator[](const T& v) const
```

集合 $\\{\ x \mid \exists i_{1\le i\le N}\ x = A_i\ \\}$ 上で`v`で`lower_bound`します。

`lower_bound - begin()`を返します。

**計算量:** $O(\log N)$

<br />

#### upper_bound

```cpp
u32 upper_bound(const T& v) const
```

集合 $\\{\ x \mid \exists i_{1\le i\le N}\ x = A_i\ \\}$ 上で`v`で`upper_bound`します。

`upper_bound - begin()`を返します。

**計算量:** $O(\log N)$

#### at

```cpp
u32 at(const T& v) const
```

operator[]と一緒ですが、 $v$ が $\\{\ x \mid \exists i_{1\le i\le N}\ x = A_i\ \\}$ に存在しない場合assertに引っかかる

<br />

#### contains

```cpp
bool contains(const T& v) const
```

$v$ が含まれるか判定します。

**計算量:** $O(\log N)$

<br />

#### find

```cpp
u32 find(const T& v) const
```

$v$ が含まれるなら`(*self)[v]`を、そうでないなら`CompressedSequence<T>::NotFound`を返します。

`CompressedSequence<T>::NotFound`は`std::numeric_limits<u32>::max()`と同じ値です。

**計算量:** $O(\log N)$

<br />


#### map
```cpp
inline u32 map(u32 i) const noexcept
```

引数で与えた非負整数$i$ に対して、 $A_i$ の座標圧縮後の値を返します。

**制約:** $i\ <\ N$

**計算量:** 定数時間

<br />

#### inverse

```cpp
inline T inverse(u32 i) const noexcept
```
集合 $\\{\ x \mid \exists i_{1\le i\le N}\ x = A_i\ \\}$ で $i$ 番目に小さい要素を返します。

**制約**: $0\ \le\ i\ <\ \text{size()}$

**計算量**: 定数時間

<br />


#### comped

```cpp
inline std::vector<T> comped() const noexcept
```

集合 $\\{\ x \mid \exists i_{1\le i\le N}\ x = A_i\ \\}$ に属する値を小さい順に入れたvectorを返します。

**計算量**: 集合サイズ

## アルゴリズム、そもそも座標圧縮とは

長さ $N$ の整数列 $B$ は、次の条件を満たす時に「 $A$ を座標圧縮した列」であると(私を含む多くの競プロerが)呼びます。
- $B$ の各要素が $0$ 以上 $M$ 未満の整数である[^1]。
- $A_i = A_j$ を満たす時、またその時に限り $B_i = B_j$ である。
- $A_i < A_j$ を満たす時、またその時に限り $B_i < B_j$ である。

このような $B$ は $A$ に対して一意に定まることが知られています。

例1: $(3, 2, 15, 3, 13, 15)$ を座標圧縮した列は $(1, 0, 3, 1, 2, 3)$ です。

例2: $(0, 0, 0)$ を座標圧縮した列は $(0, 0, 0)$ です。

例3: トランプの役の列 $(\text{A}, \text{Q}, \text{4}, \text{2})$ を大小関係を「大富豪で強い方が大きい」と定めて座標圧縮した列は $(2, 1, 0, 3)$ です。

<br />

座標圧縮した列の構築のオーソドックスなやり方として、以下の $2$ つのやり方が有名です。
- 本質は $1$ も $2$ も同じです。

1. ソートして重複要素を取り除いた列を用意して、その列上で二分探索することで自身より小さい値の種類数を得る。

2. 連想配列に $A$ を押し込んで、小さい順に番号を振る。

本ライブラリでは $1$ のやり方を採用しています。

<br />

[^1]: $1$ 以上 $M$ 以下とする人もいると思います。0-indexedか1-indexedかの違いだけです。
