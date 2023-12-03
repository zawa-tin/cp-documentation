---
title: Fenwick Tree
documentation_of: //Src/DataStructure/FenwickTree/FenwickTree.hpp
---

## 概要

可換群 $G = (S, \circ)$ 上で列上の一点更新、区間積クエリに答えることができるデータ構造です。
- 以後、管理する列を $A$ とします。

## ライブラリの使い方

#### テンプレート引数

```cpp
template <class Group>
```

群 $G$ を指定します。

詳細は、[本ライブラリにおける群の実装について](https://zawa-tin.github.io/cp-documentation/Docs/Appendix/Group.html) を確認してください。

以下、`Group::Element` を `Value` と訳します。

<br />

#### コンストラクタ

```cpp
(1) FenwickTree()
(2) FenwickTree(usize n)
(3) FenwickTree(const std::vector<Value>& a)
```

(1) $A$ を空列で初期化します

**計算量**: 定数時間

(2) $A$ を長さ $n$ で各要素が `Group::identity` である列で初期化します

**計算量**: $O(n)$

(3) $A$ を `a` で初期化します

**計算量**: `a`の長さを $n$ として $O(n\log n)$

<br />

#### get

```cpp
const Value& get(usize i) const noexcept
```

$A_i$ を返します。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: 定数時間

<br/>

#### operator[]

```cpp
const Value& operator[](usize i) const noexcept
```
$A_i$ を返します。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: 定数時間

<br />

#### size

```cpp
usize size() const noexcept
```

$A$ の要素数を返します。

**計算量**: 定数時間

<br />

#### operation

```cpp
void operation(usize i, const Value& v)
```

$A_i$ を $A_i \circ v$ に置き換えます。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: $O(\log n)$

<br />

#### set

```cpp
void set(usize i, const Value& v)
```
$A_i$ を $v$ を置き換えます。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: $O(\log n)$

<br />

#### prefixProduct

```cpp
Value prefixProduct(usize r) const;
```

$\displaystyle \prod_{i = 0}^{r - 1} A_{i}$ を求め、返します。

このメンバは`Group::inverse`を呼ばないので、`inverse`が定義されていない`Group`でも呼び出すことができます。

- 可換モノイドならok

<br />

#### product

```cpp
Value product(usize l, usize r) const
```

$\displaystyle \prod_{i = l}^{r - 1} A_i$ を求めます。

**制約**: $0\ \le\ l\ \le\ r\ \le\ n$

**計算量**: $O(\log n)$

<br />

#### maxRight

```cpp
template <class Function>
u32 maxRight(u32 l, const Function& f) const
```

ある$l$ 以上の整数 $m$ が存在して、 $l$ 以上 $m$ 未満の整数 $i$ について $\displaystyle f(\prod_{j = l}^{i} A_{j}) = \text{true}$ かつ $m$ 以上の整数 $i$ について $f(\displaystyle\prod_{j = l}^{i} A_{j}) = \text{false}$ であることを仮定します。

そのような状況で、 $m$ を発見して返します。

ただし、 $f(\displaystyle \prod_{i = l}^{n - 1} A_{i}) = \text{true}$ の時は $n$ を返します。

**制約**

- $0\ \le\ l\ <\ n$
- $f$ は`Value`から`bool`への写像
- 上記の仮定を満たす

**計算量**: $O(\log n)$

<br />

#### minLeft

```cpp
template <class Function>
u32 minLeft(u32 l, const Function& f) const
```

ある$r$ 以下の整数 $m$ が存在して、 $0$ 以上 $m$ 以下の整数 $i$ について $f(\displaystyle \prod_{j = i}^{r - 1} A_{j}) = \text{false}$ かつ $m + 1$ 以上 $r$ 以下の整数 $i$ について $f(\displaystyle \prod_{j = i}^{r - 1} A_{j}) = \text{true}$ であることを仮定します。

そのような状況で、 $m$ を発見して返します。

ただし、 $f(\displaystyle \prod_{i = 0}^{r - 1} A_{i}) = \text{true}$ の時は $0$ を返します。

実装に自信が無い。バグっているかも...

**制約**

- $0\ \le\ r\ \le\ n$
- $f$ は`Value`から`bool`への写像
- 上記の仮定を満たす

**計算量**: $O(\log n)$

<br />

#### operator<<

```cpp
friend std::ostream& operator<<(std::ostream& os, const FenwickTree& ft)
```

$n + 1$ 要素空白区切りで出力します。 $i$ 要素目は $\displaystyle \prod_{j = 0}^{i} A_{j}$ を出力します。

<br />

#### update

2023/12/03: prefixProductメンバを作成

2023/12/03: 一部のメンバの引数の型`u32`を`usize`へ変更
