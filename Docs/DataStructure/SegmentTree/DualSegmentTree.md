---
title: Dual Segment Tree (非可換対応)
documentation_of: //Src/DataStructure/SegmentTree/DualSegmentTree.hpp
---

ドキュメントを書く気力が行方不明！

[テンプレート引数](https://zawa-tin.github.io/cp-documentation/Docs/Appendix/Monoid.html)

`CommutativeDualSegmentTree`より定数倍が若干悪い。

`Operator = Monoid::Element`

`operation(u32 l, u32 r, const Operator& v)` 半開区間 $[l, r)$ に $v$ を合成(ACLでいう`composition`)
- $O(\log n)$

`set(u32 i, const Operator& v)` $i$ 番目の要素に $v$ を「代入」
- $O(\log n)$

`Operator operator[](u32 i)`
- $i$ 番目の要素を取得
- $O(\log n)$
