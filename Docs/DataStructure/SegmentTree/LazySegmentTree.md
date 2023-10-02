---
title: Lazy Segment Tree
documentation_of: //Src/DataStructure/SegmentTree/LazySegmentTree.hpp
---

ドキュメントを書く気力が行方不明！

[テンプレート引数](https://zawa-tin.github.io/cp-documentation/Docs/Appendix/Monoid.html)

コンストラクタ: サイズ or `std::vector<Value>` or 値に`Value`を持つイテレータの範囲

`void operation(u32 l, u32 r, const Operator& o)`: $[l, r)$ に`o`を作用させる

`Value product(u32 l, u32 r)`: $[l, r)$ の総積

`Value operator[](u32 i)`: $i$ 番目の要素を取得

`void set(u32 i, const Value& v)`: $i$ 番目の要素に $v$ を代入

`operator[]`と`set`はうまくいっている自信がちょっと無い。verifyを増やさねば
- `operator[]`は未verify、`set`は`product`や`operation`と混ざるとどうなるか分からん
