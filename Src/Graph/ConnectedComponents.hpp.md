---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Basis/AdjacentList.hpp
    title: "\u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  bundledCode: "#line 2 \"Src/Graph/ConnectedComponents.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Graph/Basis/AdjacentList.hpp\"\n\n#line 4\
    \ \"Src/Graph/Basis/AdjacentList.hpp\"\n\n#include <vector>\n#include <cassert>\n\
    \nnamespace zawa {\n\ntemplate <class CostType>\nstruct Edge {\n    u32 from,\
    \ to;\n    CostType weight;\n    u32 id;\n\n    Edge() = default;\n    Edge(u32\
    \ from_, u32 to_, const CostType& weight_, u32 id = -1)\n        : from{ from_\
    \ }, to{ to_ }, weight{ weight_ }, id{ id } {}\n};\n\ntemplate <class CostType>\n\
    class AdjacentList {\nprivate:\n    using E = Edge<CostType>;\n\n    usize n,\
    \ m;\n    std::vector<E> edges;\n    std::vector<std::vector<E>> g;\n\npublic:\n\
    \    AdjacentList() = default;\n    AdjacentList(usize n_) : n{ n_ }, m{}, g(n_)\
    \ {}\n\n    void addDirectedEdge(u32 from, u32 to, const CostType& weight = 1)\
    \ {\n        edges.emplace_back(from, to, weight, m);\n        g[from].emplace_back(from,\
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
    using Graph = AdjacentList<CostType>;\n\n} // namespace zawa\n#line 5 \"Src/Graph/ConnectedComponents.hpp\"\
    \n\n#line 8 \"Src/Graph/ConnectedComponents.hpp\"\n#include <limits>\n#include\
    \ <algorithm>\n#include <utility>\n#include <stack>\n\nnamespace zawa {\n\ntemplate\
    \ <class CostType = u32>\nclass ConnectedComponents {\nprivate:\n    Graph<CostType>\
    \ graph;\n    std::vector<u32> id;\n    usize countComponents;\n\n    std::vector<std::vector<u32>>\
    \ componentsV, componentsE;\n\n\npublic:\n    ConnectedComponents() = default;\n\
    \    ConnectedComponents(const Graph<CostType>& graph_) \n        : graph(graph_),\
    \ id(graph_.sizeV()), countComponents{}, componentsV{}, componentsE{} {\n\n  \
    \      const u32 inf = std::numeric_limits<u32>::max();\n\n        std::fill(id.begin(),\
    \ id.end(), inf);\n        id.shrink_to_fit();\n\n\n        auto search = [&](u32\
    \ s) -> void {\n            std::stack<std::pair<u32, u32>> stk;\n           \
    \ stk.push({ s, inf }); \n            while (stk.size()) {\n                auto\
    \ [v, eid] = stk.top();\n                stk.pop();\n                id[v] = countComponents;\n\
    \                for (const auto& e : graph[v]) {\n                    if (id[e.to]\
    \ == inf) {\n                        stk.push({ e.to, e.id });\n             \
    \       }\n                }\n            }\n        };\n\n        for (u32 i\
    \ = 0 ; i < graph.sizeV() ; i++) {\n            if (id[i] < inf) continue;\n \
    \           search(i);\n            countComponents++;\n        }\n\n        componentsV.resize(countComponents);\n\
    \        for (u32 i = 0 ; i < graph.sizeV() ; i++) {\n            componentsV[id[i]].push_back(i);\n\
    \        }\n        componentsV.shrink_to_fit();\n        for (auto& comp : componentsV)\
    \ {\n            comp.shrink_to_fit();\n        }\n\n        componentsE.resize(countComponents);\n\
    \        for (u32 i = 0 ; i < graph.sizeE() ; i++) {\n            componentsE[id[graph.getEdge(i).from]].push_back(i);\n\
    \        }\n        componentsE.shrink_to_fit();\n        for (auto& comp : componentsE)\
    \ {\n            comp.shrink_to_fit();\n        }\n    }\n\n    inline usize size()\
    \ const {\n        return countComponents;\n    }\n\n    inline usize sizeV(u32\
    \ i) const {\n        assert(i < countComponents);\n        return componentsV[i].size();\n\
    \    }\n\n    inline usize sizeE(u32 i) const {\n        assert(i < countComponents);\n\
    \        return componentsE[i].size();\n    }\n\n    inline u32 operator[](u32\
    \ v) const {\n        assert(v < graph.sizeV());\n        return id[v];\n    }\n\
    \n    inline u32 getVId(u32 v) const {\n        assert(v < graph.sizeV());\n \
    \       return id[v];\n    }   \n\n    inline u32 getEId(u32 v) const {\n    \
    \    assert(v < graph.sizeE());\n        return id[graph.getEdge(v).from];\n \
    \   }   \n\n    inline bool same(u32 u, u32 v) const {\n        assert(u < graph.sizeV());\n\
    \        assert(v < graph.sizeV());\n        return id[u] == id[v];\n    }\n\n\
    \    inline std::vector<std::vector<u32>> enumerateV() const {\n        return\
    \ componentsV;\n    }\n\n    inline std::vector<u32> enumerateV(u32 i) const {\n\
    \        assert(i < countComponents);\n        return componentsV[i];\n    }\n\
    \n    inline std::vector<std::vector<Edge<CostType>>> enumerateE() const {\n \
    \       std::vector res(countComponents, std::vector<Edge<CostType>>());\n   \
    \     for (u32 i = 0 ; i < countComponents ; i++) {\n            for (auto eid\
    \ : componentsE[i]) {\n                res[i].push_back(graph.getEdge(eid));\n\
    \            }\n        }\n        return res;\n    }\n\n    inline std::vector<Edge<CostType>>\
    \ enumerateE(u32 i) const {\n        assert(i < countComponents);\n        std::vector<CostType>\
    \ res(componentsE[i].size());\n        for (u32 j = 0 ; j < componentsE[i].size()\
    \ ; j++) {\n            res[j] = graph.getEdge(componentsE[i][j]);\n        }\n\
    \        return res;\n    }\n\n    inline bool hasCycle(u32 i) const {\n     \
    \   assert(i < countComponents);\n        return sizeE(i) + 1 > sizeV(i);\n  \
    \  }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"./Basis/AdjacentList.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n#include <limits>\n#include <algorithm>\n\
    #include <utility>\n#include <stack>\n\nnamespace zawa {\n\ntemplate <class CostType\
    \ = u32>\nclass ConnectedComponents {\nprivate:\n    Graph<CostType> graph;\n\
    \    std::vector<u32> id;\n    usize countComponents;\n\n    std::vector<std::vector<u32>>\
    \ componentsV, componentsE;\n\n\npublic:\n    ConnectedComponents() = default;\n\
    \    ConnectedComponents(const Graph<CostType>& graph_) \n        : graph(graph_),\
    \ id(graph_.sizeV()), countComponents{}, componentsV{}, componentsE{} {\n\n  \
    \      const u32 inf = std::numeric_limits<u32>::max();\n\n        std::fill(id.begin(),\
    \ id.end(), inf);\n        id.shrink_to_fit();\n\n\n        auto search = [&](u32\
    \ s) -> void {\n            std::stack<std::pair<u32, u32>> stk;\n           \
    \ stk.push({ s, inf }); \n            while (stk.size()) {\n                auto\
    \ [v, eid] = stk.top();\n                stk.pop();\n                id[v] = countComponents;\n\
    \                for (const auto& e : graph[v]) {\n                    if (id[e.to]\
    \ == inf) {\n                        stk.push({ e.to, e.id });\n             \
    \       }\n                }\n            }\n        };\n\n        for (u32 i\
    \ = 0 ; i < graph.sizeV() ; i++) {\n            if (id[i] < inf) continue;\n \
    \           search(i);\n            countComponents++;\n        }\n\n        componentsV.resize(countComponents);\n\
    \        for (u32 i = 0 ; i < graph.sizeV() ; i++) {\n            componentsV[id[i]].push_back(i);\n\
    \        }\n        componentsV.shrink_to_fit();\n        for (auto& comp : componentsV)\
    \ {\n            comp.shrink_to_fit();\n        }\n\n        componentsE.resize(countComponents);\n\
    \        for (u32 i = 0 ; i < graph.sizeE() ; i++) {\n            componentsE[id[graph.getEdge(i).from]].push_back(i);\n\
    \        }\n        componentsE.shrink_to_fit();\n        for (auto& comp : componentsE)\
    \ {\n            comp.shrink_to_fit();\n        }\n    }\n\n    inline usize size()\
    \ const {\n        return countComponents;\n    }\n\n    inline usize sizeV(u32\
    \ i) const {\n        assert(i < countComponents);\n        return componentsV[i].size();\n\
    \    }\n\n    inline usize sizeE(u32 i) const {\n        assert(i < countComponents);\n\
    \        return componentsE[i].size();\n    }\n\n    inline u32 operator[](u32\
    \ v) const {\n        assert(v < graph.sizeV());\n        return id[v];\n    }\n\
    \n    inline u32 getVId(u32 v) const {\n        assert(v < graph.sizeV());\n \
    \       return id[v];\n    }   \n\n    inline u32 getEId(u32 v) const {\n    \
    \    assert(v < graph.sizeE());\n        return id[graph.getEdge(v).from];\n \
    \   }   \n\n    inline bool same(u32 u, u32 v) const {\n        assert(u < graph.sizeV());\n\
    \        assert(v < graph.sizeV());\n        return id[u] == id[v];\n    }\n\n\
    \    inline std::vector<std::vector<u32>> enumerateV() const {\n        return\
    \ componentsV;\n    }\n\n    inline std::vector<u32> enumerateV(u32 i) const {\n\
    \        assert(i < countComponents);\n        return componentsV[i];\n    }\n\
    \n    inline std::vector<std::vector<Edge<CostType>>> enumerateE() const {\n \
    \       std::vector res(countComponents, std::vector<Edge<CostType>>());\n   \
    \     for (u32 i = 0 ; i < countComponents ; i++) {\n            for (auto eid\
    \ : componentsE[i]) {\n                res[i].push_back(graph.getEdge(eid));\n\
    \            }\n        }\n        return res;\n    }\n\n    inline std::vector<Edge<CostType>>\
    \ enumerateE(u32 i) const {\n        assert(i < countComponents);\n        std::vector<CostType>\
    \ res(componentsE[i].size());\n        for (u32 j = 0 ; j < componentsE[i].size()\
    \ ; j++) {\n            res[j] = graph.getEdge(componentsE[i][j]);\n        }\n\
    \        return res;\n    }\n\n    inline bool hasCycle(u32 i) const {\n     \
    \   assert(i < countComponents);\n        return sizeE(i) + 1 > sizeV(i);\n  \
    \  }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Basis/AdjacentList.hpp
  isVerificationFile: false
  path: Src/Graph/ConnectedComponents.hpp
  requiredBy: []
  timestamp: '2023-06-11 23:05:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/ALDS1_11_D.test.cpp
  - Test/AtCoder/abc293_d.test.cpp
  - Test/AtCoder/abc292_d.test.cpp
  - Test/AtCoder/abc288_c.test.cpp
documentation_of: Src/Graph/ConnectedComponents.hpp
layout: document
title: "\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
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
