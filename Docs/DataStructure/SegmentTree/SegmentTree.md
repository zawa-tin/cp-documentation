---
title: Segment Tree
documentation_of: //Src/DataStructure/SegmentTree/SegmentTree.hpp
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
};
```

`get` 0-indexed

`operator[]` 0-indexed

`assign` 1点更新(代入) 0-indexed

`operation` 1点更新

`product`: 半開区間

`maxRight`

`minLeft`: 引数`r`は探索範囲に含まない
