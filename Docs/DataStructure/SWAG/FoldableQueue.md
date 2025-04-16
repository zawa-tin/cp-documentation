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
    using Element = ;
    static Element operation(Element, Element) {
    }
};
```

## 参考

- [https://motsu-xe.hatenablog.com/entry/2021/05/13/224016](https://motsu-xe.hatenablog.com/entry/2021/05/13/224016)
- [https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1](https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1)
