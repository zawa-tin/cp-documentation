---
title: SuccessiveShortestPath (最小費用流、最短路反復法)
documentation_of: //Src/Graph/Flow/SuccessiveShortestPath.hpp
---

## 概要

## ライブラリの使い方

最小費用流は色々ゴニョゴニョしたいことが多いので、全メンバがpublicに置かれている。思う存分ゴニョゴニョすることができる。

#### テンプレート引数

```cpp
template <class Cap, class Cost>
```

- `Cap`: 容量の型
- `Cost`: コストの型 (逆辺を張る都合上、符号付きの算術型しか許容しない)

<br />

#### コンストラクタ

```cpp
(1) SuccessiveShortestPath() = default (1)
(2) SuccessiveShortestPath(usize n, usize m = usize{}) (2)
```

(2) $n$ は頂点数 (**正**整数)、 $m$ は辺数 (指定すると内部のコンテナを`reserve`する。普段使いでは無視して良いパラメータ)

**計算量**: $O(n + m)$

<br />


#### addEdge

```cpp
u32 addEdge(u32 from, u32 to, const Cap& cap, const Cost& cost)
```

ネットワーク上に頂点`from`から頂点`to`への、容量`cap`コスト`cost`の辺を張る。

逆辺も張られる。

この辺に振られた一意なidが返る。逆辺のidは $\text{id} + 1$ である(使う上で覚える必要は無い)

**計算量**: $O(1)$

<br />

#### reverseId

```cpp
static constexpr u32 reverseId(u32 i) noexcept
```

$i$ 番のidが振られた辺の逆辺のidを返す。

<br />

#### from

```cpp
inline u32 from(u32 i) const noexcept
```

$i$ 番のidが振られた辺の湧き出し元の頂点番号を返す。

<br />

#### to

```cpp
inline u32 to(u32 i) const noexcept
```

$i$ 番のidが振られた辺の湧き出し先の頂点番号を返す。

<br />

#### residual

```cpp
inline const Cap& residual(u32 i) const noexcept
```

$i$ 番のidが振られた辺の残余容量を返す。

<br />

#### cost

```cpp
inline const Cost& cost(u32 i) const noexcept
```

$i$ 番のidが振られた辺のコストを返す。

<br />

#### flowed

```cpp
inline const Cap& flowed(u32 i) const noexcept
```

$i$ 番のidが振られた辺に流れた水の量を返す。

<br />

#### capacity

```cpp
inline const Cap& capcacity(u32 i) const noexcept
```

$i$ 番のidが振られた辺の元々の容量を返す。

<br />

#### flow

```cpp
bool flow(u32 s, u32 t, Cap flow)
```

$s$ から $t$ へ水を $\text{flow}$ だけ流す。 $\text{flow}$ 流せたら `true` を返す。

**計算量**: $O(\text{flow} \times |E|\log (|V|))$

負辺を`addEdge`していると遅い。こういう時は`bellmanford`、`dagdp` -> `updatePotential` でポテンシャルを予め計算しておくと正常に動作する。
- `bellmanford`は $O(|V||E|)$ で動作することに注意

#### maxflow

```cpp
Cap maxflow(u32 s, u32 t)
```

$s$ から $t$ へ流せるだけ水を流す (最小費用最大流問題)

**計算量**: 最大流を $F$ として $O(F \times |E|\log (|V|))$

<br />

#### minCost

```cpp
Cost minCost() const noexcept
```

現在のフローのコストを返す。

<br />

#### slope

```cpp
std::vector<Cap> slope(u32 s, u32 t)
```

$s$ から $t$ への最大流を $F$ とする。 $s$ から $t$ へ水を $0$ 流した時、 $1$ 流した時、 .... 、 $F$ 流した時のフローの最小コストを`std::vector<Cost>`で返す。

**計算量**: 最大流を $F$ として $O(F \times |E|\log (|V|))$

<br />

#### slopeACL

```cpp
struct Line {
    Cap dn, up;
    Cost cost;
};
std::vector<Line> slopeACL(u32 s, u32 t)
```

`atcoder::mcf_graph`の`slope`と似たやつを返す。最大流がでかい場合は`slope`よりこっちを使った方が良さそう。

<br />

基本的にはここまでのメンバを使うことで事足りる。アドホックに色々したい、どうしても内部のメンバを呼び出したい時は下記のメンバも使えるかもしれない

#### edgeCost

```cpp
inline Cost edgeCost(u32 i) const noexcept
```

$i$ 番のidが振られた辺の現在のポテンシャルを加味した辺のコストを返す。

<br />

#### relax

```cpp
bool relax(u32 i)
```

$i$ 番目の辺でネットワークを緩和する。緩和されて最短経路が更新されたら`true`を返す。

現在の辺容量が $0$ ならば必ず緩和は失敗する


<br />

#### dijkstra

```cpp
bool dijkstra(u32 s, u32 t)
```

始点 $s$ 、終点 $t$ でネットワークにダイクストラ法を適用する。容量が正の辺のみを考慮する。(終点 $t$ に到達したらループから抜けるみたいな枝刈りは入って**いない**)

始点から終点へ到達可能なら`true`を返す。

<br />

#### dagdp

```cpp
bool dagdp(u32 s, u32 t)
```

始点 $s$ 、終点 $t$ でネットワークにdpで最短経路を更新する。容量が正の辺のみを考慮する。(終点 $t$ に到達したらループから抜けるみたいな枝刈りは入って**いない**)

始点から終点へ到達可能なら`true`を返す。

当然だが、ネットワークがDAGで無い場合の挙動は知らん。
- 全ての逆辺の辺容量が $0$ の時以外呼び出すべきで無いと思うが..

<br />

#### bellmanford

```cpp
bool bellmanford(u32 s, u32 t)
```

始点 $s$ 、終点 $t$ でネットワークにベルマンフォード法を適用する。容量が正の辺のみを考慮する。

始点から終点へ到達可能なら`true`を返す。

<br />

#### updatePotential

```cpp
void updatePotential()
```

ポテンシャルを更新する。

#### flush

```cpp
Cap flush(u32 s, u32 t, Cap up = std::numeric_limits<Cap>::max())
```

始点 $s$ から 終点 $t$ のパスで現在発見している最短経路へ、最大`up`の水を流す。

流せた水の量を返す。

`dijkstra(s, t)`、`dagdp(s, t)`、`bellmanford(s, t)`などを呼び最短経路を求めておくこと。

<br />

#### emplace

```cpp
void emplace(u32 from, u32 to, const Cap& cap, const Cost& cost)
```

コンテナに頂点`from`から頂点`to`への、辺容量`cap`、辺コスト`cost`の辺を直接挿入する。

大体の場合では`addEdge`メンバで事足りる。こいつを直接呼び出す必要がある状況をあまり想定できていない

<br />
