---
title: Set Operator
documentation_of: //Src/Algebra/Action/SetOperator.hpp
---

example

```cpp
struct OP {
    using Element = long long;
    static Element identity() {
        return 0;
    }
    static void add(Element& s, int v) {
        s += v;
    }
    static void remove(Element& s, int v) {
        s -= v;
    }
};
```

`remove(s, v)`の前には(まだ`remove`されていない)`add(s, v)`と丁度一つ対応させることができる時に使う。
