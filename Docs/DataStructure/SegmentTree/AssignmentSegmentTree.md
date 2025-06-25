---
title: Assignment Segment Tree
documentation_of: //Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp
---

## 概要

区間**代入**区間総積に特化したセグ木。特に、 $x^{p}$ が効率的に計算できない (二分累乗法を使って $\Theta(\log p)$ 回演算をする必要がある)場合は遅延セグ木よりもオーダーレベルで高速化する。

$x^{p}$ が効率的に計算できる場合(例: 加法 $xp$ なので、 $O(1)$ )でも、遅延セグ木じゃなくて普通のセグ木を使っている分定数倍が良い...気がする。

## ライブラリの使い方

#### テンプレート引数要件、Monoid

```
template <Concept::Monoid Monoid>
```

普通のセグ木と同じものを使えば、コンパイルが通って問題なく使える。

`Monoid::Element power(M::Element x, u64 p)`というstaticメンバを定義すると、定数倍や場合によっては計算量が改善する実装に分岐する。中身は $x$ を`operation`で $p$ 乗した値を返すようにする。

`power`が無い場合は二分累乗法によって計算する。

**雛形**

```
struct M {
    using Element = ;
    static Element identity() {
    }
    static Element operation(Element l, Element r) {
    }
    static Element power(Element v, u64 exp) {
    }
};
```

#### コンストラクタ

```cpp
AssignmentSegmentTree()  // (1)
AssignmentSegmentTree(usize n) // (2)
AssignmentSegmentTree(std::vector<V> dat) // (3)
```

(2) 長さ $n$ 、各要素が単位元列で初期化する。

(3) 列`dat`で初期化する。`V`とは`M::Element`のことである。`V`に`operator==`が定義されていると、若干定数倍が良い(多分)実装に分岐する。この分岐は、同じ値が多く連なっているような列は特に嬉しい。 [ABC237](https://atcoder.jp/contests/abc237/tasks/abc237_g) についてはコンストラクタの計算量が $O(N)$ に改善する。実際40msくらい早くなった。

**計算量**

(2): $O(N)$

(3): $O(N\log N)$ 

#### size

```cpp
inline usize size() const noexcept
```

列の長さを返す。 $O(1)$

#### product

```
V product(usize l, usize r) const;
```

$l$ 番目から $r - 1$ 番目までの総積を返す。

**計算量:**  $O(\log N)$

#### assign

```
V assign(usize l, usize r, V v)
```

$l$ 番目から $r - 1$ 番目の要素を $v$ にする。

**計算量**

`assign`を合計 $Q$ 回呼んだとすると

- $O(Q\log N)$
- 加えて`M::power`が $O(Q)$ 回呼ばれる。定義されていないときは、 `M::operation`が $O(Q\log N)$ 回呼ばれる。

## 参考

- [\[Library Checker\] Range Set Range Composite](https://maspypy.com/library-checker-range-set-range-composite)
