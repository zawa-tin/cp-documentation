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

#### build

```cpp
LowlinkResponse build() const
```

現在のグラフで橋・関節点を列挙する。

**計算量**: $O(|V| + |E|)$

#### LowlinkResponse

#### isArticulation

```cpp
inline bool isArticulation(u32 v) const 
```

頂点 $v$ が関節点かどうかを判定する。

#### isBridge

```cpp
inline bool isBridge(u32 i) const
```

$i$ 番目の辺が橋かどうか判定する。


#### cut

```cpp
inline u32 cut(u32 v) const
```

頂点 $v$ と $v$ を端点に持つ辺を削除したとき、グラフが何個の連結成分に分かれるかを返す。

<br />

## 参考

T.コメルン, C.ライザーソン, R.リベスト, C.シュタイン, アルゴリズムイントロダクション第３版 第2巻 第22章
