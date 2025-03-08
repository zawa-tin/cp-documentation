---
title: Fenwick Tree 2D (Offline Query)
documentation_of: //Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp
---

## 概要

二次元FenwickTree!!

一点加算が行われる点がどこか、先に要求される。(オフライン)

## ライブラリの使い方

#### テンプレート引数

```cpp
template <class T, class G>
```

`T`: 座標の型

`G`: データ構造に乗せる代数的構造。雛形は下から

```cpp
class G {
public:
    using Element = ;
    static T identity() noexcept {
    }
    static T operation(const T& l, const T& r) noexcept {
    }
    static T inverse(const T& v) noexcept {
    }
};
```

#### operation

```cpp
void operation(T x, T y)
```

$(x, y)$ に点が加算されることを知らせる。

**計算量:** $O(1)$

<br />

以下、登録された点の数が $N$ 個であるとする。

#### build

```cpp
[[nodiscard]] internal::FenwickTree2D<T, G> build()
```

二次元FenwickTreeを構築する。構築されたFenwickTreeを返す。

**計算量:** $O(N\log N)$

以下で説明するものは、`build`の返り値が持つメンバである。

#### operation

```cpp
void operation(const T& x, const T& y, const V& v);
```

$(x, y)$ に $v$ を加算する。x, yは`OfflineFenwickTree2D`のoperationで登録された点である必要がある。

**計算量:** $O(\log^2 N)$

<br />

#### product

```cpp
[[nodiscard]] V product(const T& lx, const T& ly, const T& rx, const T& ry)
```

$\displaystyle \sum_{i=lx}^{rx-1}\sum_{j=ly}^{ry-1} A_{ij}$ を計算する。

**計算量:** $O(\log^2 N)$
