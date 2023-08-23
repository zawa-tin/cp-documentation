---
title: Fenwick Tree
documentation_of: //Src/DataStructure/FenwickTree/FenwickTree.hpp
---

## 概要

群 $G = (S, \circ)$ 上で列上の一点更新、区間積クエリに答えることができるデータ構造です。
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
Value get(u32 i) const noexcept
```

$A_i$ を返します。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: 定数時間

<br/>

#### size

```cpp
usize size() const noexcept
```

$A$ の要素数を返します。

**計算量**: 定数時間

<br />

#### add

```cpp
void add(u32 i, const Value& v)
```

$A_i$ を $A_i \circ v$ に置き換えます。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: $O(\log n)$

<br />

#### set

```cpp
void set(u32 i, const Value& v)
```
$A_i$ を $v$ を置き換えます。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: $O(\log n)$

<br />

#### product

```cpp
Value product(u32 l, u32 r) const
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
template <class Group>
std::ostream &operator<<(std::ostream& os, const FenwickTree<Group>& ft)
```

$n + 1$ 要素Prefix Productを空白区切りで出力します。
