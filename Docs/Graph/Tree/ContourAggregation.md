---
title: 木上の等高線クエリ
documentation_of: //Src/Graph/Tree/ContourAggregation.hpp
---

## 概要

木上の頂点 $v$ から距離 $l$ 以上 $r$ 未満の全ての頂点を $O(\log N)$ 個の区間にして表現する。

区間更新区間総積はできなくて、普通のセグ木か双対セグ木と合わせて使うことになるだろう。

## ライブラリの使い方

### コンストラクタ

```cpp
template <std::integral V>
ContourAggregation(std::vector<std::vector<V>> G)
```

隣接リスト、無向辺であること。

### size

```cpp
inline usize size() const
```

必要になるデータ構造の要素数

### point

```cpp
std::vector<usize> point(V v) const;
```

$v$ の一点取得に使う

### contour

```cpp
std::vector<std::pair<usize,usize>> contour(V v, usize l, usize r) const
std::vector<std::pair<usize,usize>> contour(V v, usize d) const {
```

頂点 $v$ の距離 $l$ 以上 $r$ 未満

頂点 $v$ の距離が丁度 $d$ に対応
