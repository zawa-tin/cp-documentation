---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/ConnectedComponents.hpp
    title: "\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/ALDS1_11_B.test.cpp
    title: Test/AOJ/ALDS1_11_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/ALDS1_11_D.test.cpp
    title: Test/AOJ/ALDS1_11_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc288_c.test.cpp
    title: Test/AtCoder/abc288_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc292_d.test.cpp
    title: Test/AtCoder/abc292_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc293_d.test.cpp
    title: Test/AtCoder/abc293_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Basis/AdjacentList.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Basis/AdjacentList.hpp\"\n\n#include\
    \ <vector>\n#include <cassert>\n\nnamespace zawa {\n\ntemplate <class CostType>\n\
    struct Edge {\n    u32 from, to;\n    CostType weight;\n    u32 id;\n\n    Edge()\
    \ = default;\n    Edge(u32 from_, u32 to_, const CostType& weight_, u32 id = -1)\n\
    \        : from{ from_ }, to{ to_ }, weight{ weight_ }, id{ id } {}\n};\n\ntemplate\
    \ <class CostType>\nclass AdjacentList {\nprivate:\n    using E = Edge<CostType>;\n\
    \n    usize n, m;\n    std::vector<E> edges;\n    std::vector<std::vector<E>>\
    \ g;\n\npublic:\n    AdjacentList() = default;\n    AdjacentList(usize n_) : n{\
    \ n_ }, m{}, g(n_) {}\n\n    void addDirectedEdge(u32 from, u32 to, const CostType&\
    \ weight = 1) {\n        edges.emplace_back(from, to, weight, m);\n        g[from].emplace_back(from,\
    \ to, weight, m++);\n    }\n\n    void addUndirectedEdge(u32 u, u32 v, const CostType&\
    \ weight = 1) {\n        edges.emplace_back(u, v, weight, m);\n        g[u].emplace_back(u,\
    \ v, weight, m);\n        g[v].emplace_back(v, u, weight, m++);\n    }\n\n   \
    \ inline std::vector<E> operator[](u32 v) {\n        assert(v < n);\n        return\
    \ g[v];\n    }\n\n    inline const std::vector<E>& operator[](u32 v) const {\n\
    \        assert(v < n);\n        return g[v];\n    }\n\n    inline usize sizeV()\
    \ const {\n        return n;\n    }\n\n    inline usize sizeE() const {\n    \
    \    return m;\n    }\n\n    inline std::vector<E> enumerateEdges() const {\n\
    \        return edges;\n    }\n\n    inline E getEdge(u32 i) const {\n       \
    \ assert(i < m);\n        return edges[i];\n    }\n};\n\ntemplate <class CostType>\n\
    using Graph = AdjacentList<CostType>;\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n\nnamespace zawa {\n\ntemplate <class CostType>\nstruct Edge\
    \ {\n    u32 from, to;\n    CostType weight;\n    u32 id;\n\n    Edge() = default;\n\
    \    Edge(u32 from_, u32 to_, const CostType& weight_, u32 id = -1)\n        :\
    \ from{ from_ }, to{ to_ }, weight{ weight_ }, id{ id } {}\n};\n\ntemplate <class\
    \ CostType>\nclass AdjacentList {\nprivate:\n    using E = Edge<CostType>;\n\n\
    \    usize n, m;\n    std::vector<E> edges;\n    std::vector<std::vector<E>> g;\n\
    \npublic:\n    AdjacentList() = default;\n    AdjacentList(usize n_) : n{ n_ },\
    \ m{}, g(n_) {}\n\n    void addDirectedEdge(u32 from, u32 to, const CostType&\
    \ weight = 1) {\n        edges.emplace_back(from, to, weight, m);\n        g[from].emplace_back(from,\
    \ to, weight, m++);\n    }\n\n    void addUndirectedEdge(u32 u, u32 v, const CostType&\
    \ weight = 1) {\n        edges.emplace_back(u, v, weight, m);\n        g[u].emplace_back(u,\
    \ v, weight, m);\n        g[v].emplace_back(v, u, weight, m++);\n    }\n\n   \
    \ inline std::vector<E> operator[](u32 v) {\n        assert(v < n);\n        return\
    \ g[v];\n    }\n\n    inline const std::vector<E>& operator[](u32 v) const {\n\
    \        assert(v < n);\n        return g[v];\n    }\n\n    inline usize sizeV()\
    \ const {\n        return n;\n    }\n\n    inline usize sizeE() const {\n    \
    \    return m;\n    }\n\n    inline std::vector<E> enumerateEdges() const {\n\
    \        return edges;\n    }\n\n    inline E getEdge(u32 i) const {\n       \
    \ assert(i < m);\n        return edges[i];\n    }\n};\n\ntemplate <class CostType>\n\
    using Graph = AdjacentList<CostType>;\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Basis/AdjacentList.hpp
  requiredBy:
  - Src/Graph/ConnectedComponents.hpp
  timestamp: '2023-06-11 22:24:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/ALDS1_11_B.test.cpp
  - Test/AOJ/ALDS1_11_D.test.cpp
  - Test/AtCoder/abc293_d.test.cpp
  - Test/AtCoder/abc292_d.test.cpp
  - Test/AtCoder/abc288_c.test.cpp
documentation_of: Src/Graph/Basis/AdjacentList.hpp
layout: document
title: "\u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8"
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
