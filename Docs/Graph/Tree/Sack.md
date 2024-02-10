---
title: Sack
documentation_of: //Src/Graph/Tree/Sack.hpp
---

## 概要

根付き木に対して、「各頂点を根とした部分木を考慮した場合のOOを求めよ」みたいな状況で汎用的に（？）使えるアルゴリズム。

## 使い方

#### コンストラクタ

```cpp
(1) Sack() = default
(2) Sack(usize n)
```
(1) 特に使用を想定していない

(2) 頂点集合を $\\{ 0, 1, 2, \dots, n - 1 \\}$ で初期化する。

- $n$ は正整数でないといけない

<br />

#### addEdge

```cpp
void addEdge(u32 u, u32 v)
```

辺 $\\{ u, v \\}$ を追加する。

<br />

#### operator[]

```cpp
const std::vector<u32>& operator[](u32 v) const noexcept
```

頂点 $v$ と隣接する頂点のリストを返す。

<br />

#### execute

```cpp
template <class ADD, class DEL, class QUERY, class RESET>
u32 execute(u32 root, const ADD& add, const DEL& del, const QUERY& query, const RESET& reset)
```

頂点 `root` を根とした根付き木として、Sackを実行する。`addEdge`によって追加された辺から構成されるグラフが木や森でない場合、正常に動作しない可能性がある。

**add**

```cpp
void add(u32 v)
```

頂点 $v$ を引数に取る関数オブジェクトである必要がある。頂点 $v$ の情報を反映する。

**del**

```cpp
void del(u32 v)
```

頂点 $v$ を引数に取る関数オブジェクトである必要がある。頂点 $v$ の情報を削除する。
- それ以前に`add(v)`が呼ばれていることが保証されるので、それを打ち消す操作を入れる

**query**

```cpp
void query(u32 v)
```

頂点 $v$ を引数に取る関数オブジェクトである必要がある。頂点 $v$ を根とした部分木に対するクエリを処理する。

この関数が呼ばれる時、 $v$ を根とした部分木に属する頂点 $x$ のみに`add(x)`が呼ばれた状態であることが保証される。

- 正確には、`del(x)`によって打ち消されていない`add(x)`が丁度一回ある。
- この部分木に含まれていない頂点は `add(x)`と`del(x)`の呼ばれた回数が同じであり、完全に打ち消されている。

**reset**

```cpp
void reset()
```

`del`によって打ち消せないものがある時、`reset`で処理する。

`root`を根とした根付き木の頂点数を返り値として返す。

- Sackを使える問題に木では無く森の場合を要求するものがあったため、本当に $n$ 要素に対して実行を行ったか確認できるようにする意図がある。

**計算量解析**

一般性を失わず、 連結グラフの場合を記す。

- `add` を $O(n\log n)$ 回呼び出す
- `del` を $O(n\log n)$ 回呼び出す
- `query` を丁度 $n$ 回呼び出す
- `reset` を $O(n)$ 回呼び出す

<br />

## 参考

- [Nyaan's Library](https://nyaannyaan.github.io/library/tree/dsu-on-tree.hpp.html)
- [CFのブログ](https://codeforces.com/blog/entry/44351)
