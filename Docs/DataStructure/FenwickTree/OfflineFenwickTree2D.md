---
title: Fenwick Tree 2D (Offline Query)
documentation_of: //Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp
---

## 概要

二次元FenwickTree!!

## ライブラリの使い方

#### テンプレート引数

```cpp
template <class T, class G>
```

`T`: 座標の型

`G`: データ構造に乗せる代数的構造

#### operation

```cpp
u32 operation(T x, T y, const V& v)
```

$(x, y)$ に $v$ を加算する。これが何番目のクエリかを返す。

<br />

#### product

```cpp
u32 product(T lx, T ly, T rx, T ry)
```

$\sum_{x = lx}^{rx - 1} \sum_{y = ly}^{ry - 1} A_{x, y}$ を計算する。

一度も`operation`で呼ばれていない場所からは`G::identity()`が加算される。

これが何番目のクエリかを返す。

<br />

#### execute

```cpp
std::vector<std::pair<V, u32>> execute() const
```

`operation`と`product`で登録されたクエリを登録された順に処理する。

`product`の解が登録された順番に保管された列を返す。

- first: 解
- second: それが何番目に呼び出されたクエリか？
