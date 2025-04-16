---
title: Foldable Deque
documentation_of: //Src/DataStructure/SWAG/FoldableDeque.hpp
---

## 概要

**半群**の積が取れるDeque

- モノイドじゃなくて半群だから、単位元がいらない！すごい？
- 空のdequeに対して`product()`を呼ぶ際は`S::identity()`を要求する(無いときは実行時エラー)

雛形
```cpp
struct S {
    using Element = ;
    static Element operation(Element, Element) {
    }
    /*
    static Element identity() {
    }
    */
};
```

## 参考

- [https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1](https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1)
