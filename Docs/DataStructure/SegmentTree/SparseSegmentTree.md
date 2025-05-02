---
title: 単位元で無い要素が疎なセグメント木
documentation_of: //Src/DataStructure/SegmentTree/SparseSegmentTree.hpp
---

## 概要

$N$ がめっちゃでかいセグ木をオンラインで要求されて座圧できないときにどうぞ。

コンストラクタの第二引数にメモリプールのサイズを指定できます(メモリプール(大嘘)で、vectorをreserveするだけです)

モノイドの雛形はこちらから。

```cpp
struct M {
    using Element = ;
    static Element identity() {
        return ;
    }
    static Element operation(Element L, Element R) {

        return ;
    }
};
```

## TODO

- maxRightやminLeftを実装する
- ノードを作りすぎない工夫をする

## 参考

- [Dynamic Segment Tree の ACL 風実装](https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644)
- [動的な Segment Tree のテクニック](https://kazuma8128.hatenablog.com/entry/2018/11/29/093827)
