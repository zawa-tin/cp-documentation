---
title: 定数サイズの正方行列(モノイド管理)
documentation_of: //Src/Algebra/Monoid/ConstantSquareMatrix.hpp
---

## 概要

```
template <class Semiring,usize N>
class ConstantSquareMatrix
```

`Semiring`は行列の各成分が属する半環を表します。

$N$ は行列の一辺のサイズを表し、 $N\gt 0$ が必要です。

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

また、 $N$ 行 $1$ 列のベクトルを表す`std::array<T,N>`に行列を左から掛けるstaticメンバ関数`leftAction`が提供されています。

## 更新履歴

- 2026/10/07: 作成
- 2026/10/13: `leftAction`を追加、AALC001-Oによるverifyを追加した
