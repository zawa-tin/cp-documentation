---
title: Dual Fenwick Tree
documentation_of: //Src/DataStructure/FenwickTree/DualFenwickTree.hpp
---

## 概要

可換群 $G = (S, \circ)$ 上で列上の区間加算、一点取得クエリに答えることができるデータ構造です。

- 以後、管理する列を $A$ とします。

## ライブラリの使い方

#### テンプレート引数

```cpp
template <Concept::Group G>
```

いつもの。雛形は以下から

```cpp
class G {
public:
    using Element = ;
    static T identity() noexcept {
    }
    static T operation(const T& l, const T& r) noexcept {
    }
    static T inverse(const T& v) noexcept {
    }
};
```

以下、`G::Element`を`V`と略す。

<br />

#### コンストラクタ

```cpp
(1) FenwickTree()
(2) FenwickTree(usize n)
(3) FenwickTree(const std::vector<V>& d)
```

(2) $A$ を長さ $n$ で各要素が `Group::identity` である列で初期化します

**計算量**: $O(n)$

(3) $A$ を `d` で初期化します

**計算量**: `a`の長さを $n$ として $O(n\log n)$

<br />

#### get, operator[]

```cpp
V operator[](usize i) const
```

$A_i$ を返します。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: $O(\log n)$

<br/>

#### size

```cpp
usize size() const noexcept
```

$A$ の要素数を返します。

**計算量**: 定数時間

<br />

#### operation

```cpp
void operation(usize i, const Value& v) (1)
void operation(usize l, usize r, const Value& v) (2)
```

(1) $A_i$ を $A_i \circ v$ に置き換えます。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: $O(\log n)$

(2) $A_{l}, A_{l+1}, \dots, A_{r - 1}$ にそれぞれ $v$ を加算する。

**制約**: $0\ \le\ l\ \le r\ \le n$

**計算量**: $O(\log n)$

<br />

#### set

```cpp
void set(usize i, const Value& v)
```
$A_i$ を $v$ を置き換えます。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: $O(\log n)$
