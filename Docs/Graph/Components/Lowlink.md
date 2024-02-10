---
title: Lowlink (橋・関節点)
documentation_of: //Src/Graph/Components/Lowlink.hpp
---

## 概要

与えられた無向グラフに対して各頂点が関節点か、各辺が橋かを判定します。

## ライブラリの使い方

#### コンストラクタ

```cpp
(1) Lowlink()
(2) Lowkink(u32 n)
```

(1) 使用を想定していない
(2) 頂点集合を $\\{ 0, 1, 2, \dots, n - 1 \\}$ で初期化する。

<br />

#### addEdge

```cpp
u32 addEdge(u32 u, u32 v)
```

辺 $\\{ u, v \\}$ を追加する。この辺が何番目(0-indexed)に追加された辺かを返す。

<br />

#### size

```cpp
constexpr usize size() const noexcept
```

頂点集合のサイズを返す。

<br />

#### edgeSize

```cpp
constexpr usize edgeSize() const noexcept
```

現在の辺集合のサイズを返す。

<br />

#### build

```cpp
void build()
```

現在のグラフで橋・関節点を列挙する。

(このメンバを複数回呼ぶことを想定していないことに注意)

**計算量**: $O(|V| + |E|)$

<br />

#### operator[]

```cpp
const std::vector<std::pair<u32, u32>>& operator[](u32 v) cnost noexcept
```

現在のグラフの頂点 $v$ と接続している辺のリストを返す。
- `first`が隣接している頂点
- `second`がその辺が何番目に`addEdge`によって追加されたかの番号(0-indexed)

<br />

#### edge

```cpp
const std::pair<u32, u32>& edge(u32 i) const noexcept
```

$i$ 番目(0-indexed)に`addEdge`によって追加された辺を返す。

<br />

以降のメンバは`build()`を呼んだ後に呼ばれることが想定されている。

#### articular

```cpp
bool articular(u32 v) const noexcept
```

$v$ が関節点なら`true`を、そうでないなら`false`を返す。

**計算量**: $O(1)$

<br />

#### cut

```cpp
u32 cut(u32 v) const noexcept
```

頂点 $v$ をグラフから取り除いた時、 もともと $v$ を含んでいた連結成分が何個の連結成分に分かれるかを返す。
- $v$ が関節点で無い場合は $1$ である。

**計算量**: $O(1)$

<br />

#### bridge

```cpp
bool bridge(u32 i) const noexcept
```

$i$ 番目に追加された辺が橋なら`true`をそうでないなら`false`を返す。

<br />

## 参考

T.コメルン, C.ライザーソン, R.リベスト, C.シュタイン, アルゴリズムイントロダクション第３版 第2巻 第22章
