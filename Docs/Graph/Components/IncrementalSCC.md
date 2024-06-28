---
title: offline incremental SCC
documentation_of: //Src/Graph/Components/IncrementalSCC.hpp
---

## 概要

$M$ 要素からなる有向辺の列 $E = ((u_{1}, v_{1}), (u_{2}, v_{2}), \dots, (u_{M}, v_{M}))$ が与えられる。

$N$ 頂点 $0$ 辺のグラフ $G$ に対して $E$ の辺をこの順に追加していく。

$E$ の各辺 $(u_{i}, v_{i})$ についてその辺の両端点が強連結になる時間を計算する。

## 使い方

#### コンストラクタ

```cpp
(1) IncrementalSCC() = default;
(2) IncrementalSCC(usize n)
```

(2) $n$ 頂点 $0$ 辺のグラフを用意する。 $E = ()$ とする。

<br />

#### size

```cpp
inline u32 size() const noexcept
```

グラフの頂点数を返す。

<br />

#### addEdge

```cpp
u32 addEdge(VType u, VType v)
```

`VType = u32`

$E$ の末尾に $u$ から $v$ へ伸びる辺を追加する。この辺が何番目に追加された辺かを0-indexedで返す。

<br />

#### getEdge

```cpp
std::pair<VType, VType> getEdge(TimeType t) const
```

0-indexedで $t$ 番目に追加された辺を返す。firstからsecondへ向けて張られた辺である。

<br />

#### build

```cpp
IncrementalSCCResponse build() const
```

$E$ の各辺 $(u_{i}, v_{i})$ について、頂点 $u_{i}, v_{i}$ が強連結になる時間を計算する。

**計算量**: $O(|E|\log |E|)$

#### IncrementalSCCResponse

#### invalid

```cpp
static constexpr TimeType invalid() noexcept
```

最後まで強連結にならないことを示す特別な値を返す。


#### operator[]

```cpp
TimeType operator[](u32 i) const noexcept
```

$(u_{i}, v_{i})$ について頂点 $u_{i}, v_{i}$ が強連結になる時間を返す。

厳密には、 $E$ の $0$ 番目から $t$ 番目までの辺を追加すると $u_{i}, v_{i}$ が強連結になるような最小の $t$ を返す。

そのような $t$ が存在しなければ`invalid()`を返す。

**計算量**: $O(1)$

<br />

#### same

```cpp
bool same(u32 i) const noexcept
```

$(u_{i}, v_{i})$ が最終的に強連結になるかを返す。

<br />

## メモ

$(u_{i}, v_{i})$ が強連結になる時間を $T_{i}$ とする。

頂点 $u_{i}, v_{i}$ にコスト $T_{i}$ の無向辺を張ったグラフを考える。

このグラフ上で最小全域木を張る。 木上の $u-v$ パスに含まれるコスト最大の辺のコスト $T$ が頂点 $u, v$ が強連結になる時間と一致する。

## 参考

- [My own algorithm -- offline incremental strongly connected components in O(mlog(m))](https://codeforces.com/blog/entry/91608)

