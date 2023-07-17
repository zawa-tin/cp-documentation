---
title: 無向グラフの連結成分分解
documentation_of: //Src/Graph/ConnectedComponents.hpp
---

## 概要

無向グラフ $G = (V, E)$ を構築し、各頂点、各辺がどの連結成分に属するかを管理します。

## ライブラリの使い方

#### コンストラクタ

```cpp
ConnectedComponents(usize n)
```

$V$ を $V = \\{ 0, 1, \dots, n - 1 \\}$ で初期化する。この時点で辺は存在していないものとする。

**計算量**: $O(n)$

<br />

#### addEdge

```cpp
void addEdge(u32 u, u32 v)
```

無向辺 $(u, v)$ を追加する。

**制約**: 

- $0\ \le\ u, v\ <\ \mid V\mid$
- 以前に`build`を呼び出していないこと

**計算量**: 定数時間

<br />

#### edge

```cpp
Edge edge(u32 e) const
```

$e$ 番目に追加された辺を返す。

返り値のEdgeは以下のようなstructである
```cpp
struct Edge {
    u32 u; // 辺の端点
    u32 v; // もう一方の端点
    u32 id; // 引数eと等しい
};
```

**制約**: $0\ \le\ e\ <\ \mid E\mid$ (`addEdge`を呼び出した回数よりも小さい値であること)

**計算量**: 定数時間

<br />

#### build

```cpp
void build()
```

現在の $(V, E)$ について各頂点、各辺を連結成分毎に番号を振り分ける。

連結成分の番号は以下のルールで決められる。

1. 頂点 $0$ を含む連結成分を $0$ 番とする
2. $0$ 番目から $i - 1$ 番目の連結成分に属していない頂点の中で、番号が最小の頂点を $v$ とする。 $v$ が含まれる連結成分を $i$ 番とする

**制約**: `build`をそれ以前に呼び出していない

**計算量**: $O(\mid V\mid + \mid E\mid)$

(複数回`build`を呼び出さないといけないような状況ではdisjoint set unionを使うべきだと考えているため、`build`を一度しか呼び出せないようにしています。不都合が生じた場合、修正します。)

<br />

#### size

```cpp
inline usize size() const noexcept
```

連結成分の数を返す。

**制約**: `build`を既に呼び出している

**計算量**: 定数時間

#### n

```cpp
(1) inline usize n() const noexcept
(2) inline usize n(u32 c) const noexcept
```

(1) 頂点数 $\mid V\mid$ を返す

**計算量**: 定数時間

(2) $c$ 番目の連結成分の頂点数を返す

**制約**: 

- `build`を既に呼び出している
- $c$ は連結成分の数より小さい整数である

**計算量**: 定数時間

<br />

#### m

```cpp
(1) inline usize m() const noexcept
(2) inline usize m(u32 c) const noexcept
```

(1) 辺数 $\mid E\mid$ を返す(`addEdge`が呼び出された回数)

**計算量**: 定数時間

(2) $c$ 番目の連結成分の辺数を返す

**制約**:

- `build`を既に呼び出している
- $c$ は連結成分の数より小さい整数である

**計算量**: 定数時間

<br />

#### operator[]

```cpp
inline u32 operator[](const u32 v) const noexcept
```

頂点 $v$ を含む連結成分の番号を返す。

**制約**:

- `build`を既に呼び出している
- $0\ \le\ v\ <\ \mid V\mid$

**計算量**: 定数時間

<br />

#### colorV

```cpp
inline u32 colorV(u32 v) const noexcept
```

`operator[]`と同じ

<br />

#### colorE

```cpp
inline u32 colorE(u32 e) const noexcept
```

$e$ 番目に追加された辺を含む連結成分の番号を返す。

**制約**: 

- `build`を既に呼び出している
- $0\ \le\ e\ <\ \mid E\mid$

<br />

#### same

```cpp
inline u32 same(u32 u, u32 v) const noexcept
```

頂点 $u, v$ が同じ連結成分に属しているなら`true`、そうで無い時`false`を返す。

**制約**

- `build`を既に呼び出している
- $0\ \le\ u, v\ <\ \mid V\mid$

<br />

#### vs

```cpp
inline std::vector<u32> vs(u32 c) const noexcept
```

`c`番目の連結成分が属する頂点の列を返します。返り値の列は頂点番号に対して昇順に並んでいます。

**制約**

- `build`を既に呼び出している
- `c`は連結成分の数より小さい整数

**計算量**: 連結成分に含まれる頂点数に比例する

<br />

#### es

```cpp
inline std::vector<u32> es(u32 c) const noexcept
```

`c`番目の連結成分が属する辺の列を返します。それぞれの辺の追加された番号のみを返します。

**制約**

- `build`を既に呼び出している
- `c`は連結成分の数より小さい整数

**計算量**: 連結成分に含まれる辺数に比例する

<br />

#### hasCycle

```cpp
inline bool hasCycle(u32 c) const
```

`c`番目の連結成分がサイクルを有しているか判定します。

自己ループや多重辺もサイクルとみなしていることに注意してください。

**制約**

- `build`を既に呼び出している
- `c`は連結成分の数より小さい整数

<br />

#### アルゴリズム

DFS(Depth First Search)によって実装されています。
