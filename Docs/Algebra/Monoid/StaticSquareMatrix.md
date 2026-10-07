---
title: 正方行列の行列積モノイド
documentation_of: //Src/Algebra/Monoid/StaticSquareMatrix.hpp
---

# 概要

```
template <class Semiring,usize N>
class SquareMatrix
```

`Semiring`の雛形は↓↓。各種staticメンバには`constexpr`がついていることが望ましい。

```
struct Addition {
    using Element = ;
    static constexpr Element identity() {
    }
    static constexpr Element operation(const Element&, const Element&) {
    }
};

struct Multiplication {
    using Element = ;
    static constexpr Element identity() {
    }
    static constexpr Element operation(const Element&, const Element&) {
    }
};

template <class T>
struct UsualRing {
    using Element = T;
    using Addition = Addition;
    using Multiplication = Multiplication;
};
```
