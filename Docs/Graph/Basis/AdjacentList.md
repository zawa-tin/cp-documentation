---
title: グラフの隣接リスト
documentation_of: //Src/Graph/Basis/AdjacentList.hpp
---

## 概要

グラフを隣接リスト表現によって管理するものです。

<br />

## ライブラリの使い方

#### テンプレート引数 CostType

グラフの辺コストの型を指定してください。辺コストが無い場合は`u16`とかメモリをあまり食べないものを適当に選べば良いと思います。

<br />


#### エイリアス
```
using Graph = AdjacentList<CostType>;
```

`Graph`という名前で隣接リストを利用できます。


#### コンストラクタ
```
(1) AdjacentList() = default;
(2) AdjacentList(usize N)
```

(2) $N$ 頂点 $0$ 辺のグラフを構築します。

**計算量** $O(N)$

<br />

#### addDirectedEdge
```
void addDirectedEdge(u32 from, u32 to, const CostType& weight = 1)
```

有向辺 $(\text{from}, \text{to})$ を辺コスト $\text{weight}$ で追加します。 $\text{weight}$ を指定しなかった場合、 辺コストは $1$ になります。

**制約:** $\text{from}, \text{to} < N$

**計算量:** 定数時間

<br />

#### addUndirectedEdge 
```
void addUndirectedEdge(u32 u, u32 v, const CostType& weight = 1)
```

無向辺 $(u, v)$ を辺コスト $\text{weight}$ で追加します。 $\text{weight}$ を指定しなかった場合、辺コストは $0$ になります。

**制約:** $0\ \le\ u, v\ <\  N$

**計算量:** 定数時間

<br />

#### operator[]
```
(1) inline std::vector<Edge<CostType>> operator[](const u32 v) 
(2) inline std::vector<Edge<CostType>> operator[](const u32 v) const
```

頂点 $v$ を始点とする隣接リストを返します。

**制約:** $0\ \le\ v\ \le\ N$

**計算量:** 頂点 $v$ を始点とする辺の数に依存する

<br />

#### sizeV
```
inline usize sizeV() const
```

頂点数を返します。本ライブラリではグラフの頂点集合を $V$ と表記することが(多分)多いです。それに則って`sizeV`になっています。

**計算量:** 定数時間

<br />

#### sizeE
```
inline usize sizeE() const
```

辺数を返します。より厳密には `addDirectedEdge`と`addUndirectedEdge`が呼ばれた回数の合計回数を返します。

本ライブラリではグラフの辺集合を $E$ と表記することが(多分)多いです。それに則って`sizeE`になっています。

<br />

#### enumerateEdges
```
inline std::vector<Edge<CostType>> enumerateEdges() const
```

今までに追加した辺のリストを`std::vector`で返します。
- `addUndirectedEdge`で作られた辺と`addDirectedEdge`で作られた辺は区別されていません。

**計算量:** $O(\mid E\mid)$

<br />

#### getEdge
```
inline std::vector<E> getEdge(u32 i) const
```

$i$ 番目に追加した辺を`Edge`構造体で返します。`addUndirectedEdge`で追加された辺と`addDirectedEdge`で追加された辺は区別されません。

**制約:** $0\ \le\ i\ <\ \mid E\mid$

**計算量:** 定数時間

## Edge構造体について

以下のようなメンバ変数を持つ構造体です。

```cpp
struct Edge {
    u32 from, to;
    CostType weight;
    u32 id;
};
```

ここで`id`は`addDirectedEdge`や`addUndirectedEdge`の時に自動的に割り当てられます。
- $0$ から昇順にユニークになるように割り当てられます。
- 無向辺に関しては、 $(u, v)$ と $(v, u)$ に同じ`id`が割り当てられます。その後に`add*Edge`で $(u, v)$ を追加すると、その辺に対しては別の`id`が割り当てられます。
