---
title: Dual Segment Tree (可換モノイド)
documentation_of: //Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp
---

ドキュメントを書く気力が行方不明！

[テンプレート引数](https://zawa-tin.github.io/cp-documentation/Docs/Appendix/Monoid.html)

```cpp
struct M {
    using Element = ;
    static Element identity() {
    }
    static Element operation(Element L, Element R) {
    }
    static Element acted(Element x, O o) {
    }
};
```

`using O = Monoid::Element`

`operation(u32 l, u32 r, const O& v)` 半開区間 $[l, r)$ に $v$ を作用
- $O(\log n)$

`operation(u32 i, const O& v)` 
- $O(\log n)$
- 未verify

`assign(u32 i, const O& v)` $i$ 番目の要素に $v$ を「代入」
- $O(\log n)$
- 未verify

`Operator operator[](u32 i)`
- $i$ 番目の要素を取得
- $O(\log n)$
