---
title: Foldable Queue
documentation_of: //Src/DataStructure/SWAG/FoldableQueue.hpp
---

## 概要

**半群**の積が取れるQueue

- モノイドじゃなくて半群だから、単位元がいらない！すごい？

参考の名称に従い、SWAGでは無く「Foldable Queue」という呼び名を使用しているが、ライブラリの総積を取得するメンバの名前は`product()`

雛形
```cpp
struct S {
    using Fold = struct {
        using Element = ;
        /*
        static Element identity() {
        }
        static Element operation(Element, Element) {
        }
        */
    };
    using Element = std::pair<int, int>;
    using F = typename Fold::Element;
    static F convert(Element v) {
    }
    static F pushBack(F dp, Element v) {
    }
    static F pushFront(F dp, Element v) {
    }
};
```

または、`concepts::Semigroup, concepts::Monoid`を満たすクラスを`SWAGable`に変換するラッパー`SemigroupSWAGable<S>`, `MonoidSWAGable<S>`が提供されている。

意味合いを説明する。SWAGは以下の条件を満たす集合の二つ組 $(S, F)$ を要求する。前者が実装における`Element`、後者が`Fold`である

- $s\in S$ を $f\in F$ に変換する関数 $f: S\rightarrow F$ が定義されている (convert)
- 関数 $g: (F, S) \rightarrow F$ が定義されている (pushBack)
- 関数 $h: (S, F) \rightarrow F$ が定義されている (pushFront)

dequeに挿入する各要素は $S$ の元であり、積を取った値が $F$ の元になる。

- 一要素からなる $s\in S$ の総積を取るために $f$ が必要
- SWAGに値を追加したときの総積の更新に $g, h$ が必要

ここで、 $F$ 上の二項演算演算(operation)が結合律を満たすとき盆栽から直接`product()`を取得できるようになる。

更に、 $F$ とその二項演算がモノイドを成すとき、空列からproduct()を取得できるようになる。

## 参考

- [https://motsu-xe.hatenablog.com/entry/2021/05/13/224016](https://motsu-xe.hatenablog.com/entry/2021/05/13/224016)
- [https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1](https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1)
