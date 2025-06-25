---
title: Lazy Segment Tree
documentation_of: //Src/DataStructure/SegmentTree/LazySegmentTree.hpp
---

ドキュメントを書く気力が行方不明！

[テンプレート引数](https://zawa-tin.github.io/cp-documentation/Docs/Appendix/Monoid.html)

コンストラクタ: サイズ or `std::vector<V>` or 値に`V`を持つイテレータの範囲

`void operation(usize l, usize r, const O& o)`: $[l, r)$ に`o`を作用させる

`void operation(usize i, const O& o)`: (未verify)

`Value product(u32 l, u32 r)`: $[l, r)$ の総積

`Value operator[](u32 i)`: $i$ 番目の要素を取得

`Value get(usize i)`: $i$ 番目の要素を取得

`void assign(usize i, const V& v)`: $i$ 番目の要素に $v$ を代入 (未verify)

`usize maxRight(usize l, F f)`: $f(\text{prod}(a_l, \dots, a_{r-1}))$ が`true`であるような最大の $r$ を返す(単調性を仮定)

`usize minLeft(usize r, F f)`: $f(\text{prod}(a_l, \dots, a_{r-1}))$ が`true`であるような最小の $l$ を返す(単調性を仮定)

## 更新情報

2023/11/08: `operator[]`にWarningがでていたのを解消

2025/6/25: 書き直した
