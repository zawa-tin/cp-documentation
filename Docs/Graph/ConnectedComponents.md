---
title: グラフの連結成分分解
documentation_of: //Src/Graph/ConnectedComponents.hpp
---

## 概要

**無向グラフ** $G = (V, E)$ に対してその連結成分に番号を振り、各頂点・辺がどの連結成分に属するかを記録します。
- 有向グラフである場合、うまく動作しないです。

<br />

## ライブラリの使い方

#### テンプレート引数CostType

グラフ構造体`AdjacentList`の辺のコストのタイプです。

<br />

#### コンストラクタ
```
(1) ConnectedComponents() = default
(2) ConnectedComponents(const Graph<CostType& graph_)
```

(1) デフォルトコンストラクタ

(2) 引数に与えた`graph_`でビルドします。

具体的には、グラフにある連結成分を以下のように番号付けします。
- 頂点 $0$ を含む連結成分を $0$ 番とする
- $0$ 番の連結成分に含まれていない頂点のうち、番号最小のものを $i_1$ とする。 頂点 $i_1$ を含む連結成分を $1$ 番とする
- $0, 1$ 番の連結成分に含まれていない頂点のうち、番号最小のものを $i_2$ とする。 頂点 $i_2$ を含む連結成分を $2$ 番とする
- $\vdots$

**制約**: `graph_`が無向グラフであること

**計算量:** $O(\mid V\mid + \mid E\mid)$

<br />

#### size
```
inline usize size() const
```

連結成分の個数を返します。

**計算量:** 定数時間

<br />

#### sizeV
```
inline usize sizeV(u32 i) const
```

$i$ 番目の連結成分の頂点数を返します。

**制約:** $i <$ 連結成分の個数 `= connectedComponents::size()`

**制約:** 定数時間

<br />

#### sizeE
```
inline usize sizeE(u32 i) const
```

$i$ 番目の連結成分の辺数を返します。

**制約:** $i <$ 連結成分の個数 `= connectedComponents::size()`

**制約:** 定数時間

<br />

#### operator[]
```
inline u32 operator[](u32 v) const
```

頂点 $v$ が何番の連結成分に属するかを返します。

なぜこれが`operator[]`なんですか？ -> 筆者の手癖だからです。

**制約:** $v\ \le\ \mid V\mid$

**計算量:** 定数時間

<br />

#### getVId
```
inline u32 getVId(u32 v) const
```

頂点 $v$ が何番の連結成分に属するかを返します。

`operator[]`と等価です。

**制約:** $0\ \le\ v\ \le\ \mid V\mid$

**計算量:** 定数時間

<br />

#### getEId
```
inline u32 getEId(u32 v) const
```

`graph_`構築時に $v$ 番目に追加された辺が何番目の連結成分に属するかを返します。

**制約:** $0\ \le v\ \le\ \mid E\mid$

**計算量:** 定数時間

<br />

#### same
```
inline bool same(u32 u, u32 v) const
```

頂点 $u$ と頂点 $v$ が同じ連結成分に属するかを判定します。

**制約:** $0\ \le\ u, v\ <\ \mid V\mid$

**計算量:** 定数時間

<br />

#### enumerateV
```
(1) inline std::vector<std::vector<u32>> enumerateV() const
(2) inline std::vector<u32> enumerateV(u32 i) const
```

(1)各連結成分に対して、属する頂点の番号を昇順にならべた`std::vector<u32>`を並べた`std::vector`を返します。

$i$ 番目の連結成分の列は`i`行目にあります。

**計算量:** $O(\mid V\mid)$


(2) $i$ 番目の連結成分に属する頂点の番号を昇順に並べた`std::vector`を返します。

**計算量:** $i$ 番目の連結成分の大きさに対して線形に比例します。

<br />

#### enumerateE
```
(1) inline std::vector<std::vector<Edge<CostType>>> enumerateE() const
(2) inline std::vector<Edge<CostType>> const
```

(1)各連結成分に対して、属する辺を辺の番号(辺の追加順)に対して昇順にならべた`std::vector<Edge<CostType>>`を並べた`std::vector`を返します。

$i$ 番目の連結成分の列は`i`行目にあります。

**計算量:** $O(\mid E\mid)$


(2) $i$ 番目の連結成分に属する辺を辺の番号(辺の追加順)に対して昇順に並べた`std::vector`を返します。

**計算量:** $i$ 番目の連結成分の辺の数に対して線形に比例します。

<br />

#### hasCycle
```
inline bool hasCycle(u32 i) const
```

$i$ 番目の連結成分が辺素なサイクルを持つか判定します。
- 自己ループはサイズ $1$ のサイクル、多重辺はサイズ $2$ のサイクルと判定されていることに注意してください。

**制約:** $i <$ 連結成分の個数 `= connectedComponents::size()`

**計算量:** 定数時間

<br />

## アルゴリズム

ある頂点 $v$ からDFSを行うと $v$ を含む連結成分に属する頂点全てを記録することができます。これを利用して連結成分に分解しています。

`hasCycle`の判定は単純に `辺の個数 + 1 > 頂点の個数` で判定しています。

<br />

## unionfind vs ConnectedComponents


しばしば`unionfind`でも`DFS`による連結成分分解でもどちらを使っても解ける問題に遭遇します。ここではそのような時に`zawa::DisjointSetUnion`と`zawa::ConnectedComponents`のどちらを使うべきなのかを考えます。
  
(`zawa::DisjointSetUnion`はまだ実装されていません)

`ConnectedComponents` の利点
- 計算量に $\alpha(m, n)$ みたいなのがくっつかない
- 辺数や、サイクル判定等を書く必要が無い(メソッドを呼び出すだけ)

`ConnectedComponents`の欠点
- グラフを構築する必要が無くてもグラフを構築する必要がある
   - グラフ構造体の定数倍が重く、`unionfind`に実測で劣る時も多い
- コード行数が長い
- 辺追加のクエリに対処できない
   - それはそう

`unionfind`だとTLEしてDFSによる連結成分分解だとACするというケースはあるのでしょうか？
- 結局そのようなケースだと、定数倍が重い`ConnectedComponents`は死んでしまうと思います。

UFで通らない心配をするならDFSを直書きするべきで、そのような心配をしないなら早く実装を終えて問題をACできると思う方を選ぶべきでしょう。
- グラフ問題である場合は`ConnectedComponents`のメソッドが上手く使えるかもしれません

また、UFでも $\alpha(m, n)$ みたいなものがくっつかない解析になるケース・問題もあるそうです。
- [例](https://atcoder.jp/contests/abc304/editorial/6520)
