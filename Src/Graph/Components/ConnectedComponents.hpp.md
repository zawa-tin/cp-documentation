---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/ALDS1_11_D.test.cpp
    title: Test/AOJ/ALDS1_11_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc247_f.test.cpp
    title: Test/AtCoder/abc247_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc288_c.test.cpp
    title: Test/AtCoder/abc288_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc292_d.test.cpp
    title: Test/AtCoder/abc292_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc293_d.test.cpp
    title: Test/AtCoder/abc293_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc334_g.test.cpp
    title: Test/AtCoder/abc334_g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Components/ConnectedComponents.hpp\"\n\n#line\
    \ 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Graph/Components/ConnectedComponents.hpp\"\
    \n\n#include <limits>\n#include <vector>\n#include <utility>\n#include <stack>\n\
    #include <algorithm>\n#include <cassert>\n\nnamespace zawa {\n\nclass ConnectedComponents\
    \ {\npublic:\n    struct Edge {\n    private:\n        u32 u_, v_, id_;\n    public:\n\
    \        Edge(u32 u, u32 v, u32 id) : u_{ u }, v_{ v }, id_{ id } {}\n\n     \
    \   inline u32 u() const noexcept {\n            return u_;\n        }\n     \
    \   inline u32 v() const noexcept {\n            return v_;\n        }\n     \
    \   inline u32 id() const noexcept {\n            return id_;\n        }\n   \
    \ };\n\nprivate:\n    class Component {\n    private:\n        std::vector<u32>\
    \ vs_, es_;\n    public:\n        Component() = default;\n        Component(const\
    \ std::vector<u32>& vs, const std::vector<u32>& es) : vs_{ vs }, es_{ es } {\n\
    \            vs_.shrink_to_fit();\n            es_.shrink_to_fit();\n        }\n\
    \        \n        inline usize n() const noexcept {\n            return vs_.size();\n\
    \        }\n        inline usize m() const noexcept {\n            return es_.size();\n\
    \        }\n        const std::vector<u32>& vs() const noexcept {\n          \
    \  return vs_;\n        }\n        const std::vector<u32>& es() const noexcept\
    \ {\n            return es_;\n        }\n        bool hasCycle() const {\n   \
    \         return not (n() == m() + 1);\n        }\n    };\n\n    constexpr static\
    \ u32 INVALID_{ std::numeric_limits<u32>::max() };\n\n    std::vector<std::vector<u32>>\
    \ graph_;\n    std::vector<std::pair<u32, u32>> edges_;\n\n    std::vector<u32>\
    \ indexV_, indexE_;\n    std::vector<Component> components_;\n\n    bool isBuilt;\n\
    \n    void dfs(u32 s) {\n        indexV_[s] = components_.size();\n        std::stack<u32>\
    \ stk{ { s } };\n        while (stk.size()) {\n            u32 v{ stk.top() };\n\
    \            stk.pop();\n            for (auto x : graph_[v]) {\n            \
    \    if (indexV_[x] == INVALID_) {\n                    indexV_[x] = components_.size();\n\
    \                    stk.push(x);\n                }\n            }\n        }\n\
    \    }\n\n    void buildComponents() {\n        std::vector<std::vector<u32>>\
    \ vs(components_.size()), es(components_.size());\n        for (u32 v{} ; v <\
    \ n() ; v++) {\n            vs[indexV_[v]].emplace_back(v);\n        }\n     \
    \   for (u32 e{} ; e < m() ; e++) {\n            es[indexE_[e]].emplace_back(e);\n\
    \        }\n        for (u32 i{} ; i < components_.size() ; i++) {\n         \
    \   components_[i] = Component(vs[i], es[i]);\n        }\n        components_.shrink_to_fit();\n\
    \    }\n\npublic:\n    ConnectedComponents() = default;\n\n    ConnectedComponents(usize\
    \ n) \n        : graph_(n), edges_{}, indexV_(n, INVALID_), indexE_{}, components_{},\
    \ isBuilt{} {\n        graph_.shrink_to_fit();\n    }\n    \n    void addEdge(u32\
    \ u, u32 v) {\n        assert(not isBuilt);\n        graph_[u].emplace_back(v);\n\
    \        graph_[v].emplace_back(u);\n        edges_.emplace_back(u, v);\n    }\n\
    \n    inline usize n() const noexcept {\n        return graph_.size();\n    }\n\
    \n    inline usize m() const noexcept {\n        return edges_.size();\n    }\n\
    \n    Edge edge(u32 e) const {\n        assert(e < m());\n        return Edge{\
    \ edges_[e].first, edges_[e].second, e };\n    }\n\n    void build() {\n     \
    \   assert(not isBuilt);\n        edges_.shrink_to_fit();\n        indexV_.shrink_to_fit();\n\
    \        for (u32 v{} ; v < n() ; v++) {\n            if (indexV_[v] == INVALID_)\
    \ {\n                dfs(v);\n                components_.emplace_back();\n  \
    \          }\n        }\n        indexE_.resize(m());\n        indexE_.shrink_to_fit();\n\
    \        for (u32 e{} ; e < m() ; e++) {\n            indexE_[e] = indexV_[edges_[e].first];\n\
    \        }\n        buildComponents();\n        isBuilt = true;\n    }\n\n   \
    \ inline u32 operator[](const u32 v) const noexcept {\n        assert(isBuilt);\n\
    \        assert(v < n());\n        return indexV_[v];\n    }\n\n    inline u32\
    \ indexV(u32 v) const noexcept {\n        assert(isBuilt);\n        assert(v <\
    \ n());\n        return indexV_[v];\n    }\n\n    inline u32 indexE(u32 e) const\
    \ noexcept {\n        assert(isBuilt);\n        assert(e < m());\n        return\
    \ indexE_[e];\n    }\n\n    inline bool same(u32 u, u32 v) const noexcept {\n\
    \        assert(isBuilt);\n        assert(u < n());\n        assert(v < n());\n\
    \        return indexV_[u] == indexV_[v];\n    }\n\n    inline usize size() const\
    \ noexcept {\n        assert(isBuilt);\n        return components_.size();\n \
    \   }\n\n    inline usize n(u32 c) const noexcept {\n        assert(isBuilt);\n\
    \        assert(c < size());\n        return components_[c].n();\n    }\n\n  \
    \  inline const std::vector<u32>& vs(u32 c) const noexcept {\n        assert(isBuilt);\n\
    \        assert(c < size());\n        return components_[c].vs();\n    }\n\n \
    \   inline usize m(u32 c) const noexcept {\n        assert(isBuilt);\n       \
    \ assert(c < size());\n        return components_[c].m();\n    }\n\n    inline\
    \ const std::vector<u32>& es(u32 c) const noexcept {\n        assert(isBuilt);\n\
    \        assert(c < size());\n        return components_[c].es();\n    }\n\n \
    \   inline bool hasCycle(u32 c) const {\n        assert(isBuilt);\n        assert(c\
    \ < size());\n        return components_[c].hasCycle();\n    }\n\n};\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <limits>\n\
    #include <vector>\n#include <utility>\n#include <stack>\n#include <algorithm>\n\
    #include <cassert>\n\nnamespace zawa {\n\nclass ConnectedComponents {\npublic:\n\
    \    struct Edge {\n    private:\n        u32 u_, v_, id_;\n    public:\n    \
    \    Edge(u32 u, u32 v, u32 id) : u_{ u }, v_{ v }, id_{ id } {}\n\n        inline\
    \ u32 u() const noexcept {\n            return u_;\n        }\n        inline\
    \ u32 v() const noexcept {\n            return v_;\n        }\n        inline\
    \ u32 id() const noexcept {\n            return id_;\n        }\n    };\n\nprivate:\n\
    \    class Component {\n    private:\n        std::vector<u32> vs_, es_;\n   \
    \ public:\n        Component() = default;\n        Component(const std::vector<u32>&\
    \ vs, const std::vector<u32>& es) : vs_{ vs }, es_{ es } {\n            vs_.shrink_to_fit();\n\
    \            es_.shrink_to_fit();\n        }\n        \n        inline usize n()\
    \ const noexcept {\n            return vs_.size();\n        }\n        inline\
    \ usize m() const noexcept {\n            return es_.size();\n        }\n    \
    \    const std::vector<u32>& vs() const noexcept {\n            return vs_;\n\
    \        }\n        const std::vector<u32>& es() const noexcept {\n          \
    \  return es_;\n        }\n        bool hasCycle() const {\n            return\
    \ not (n() == m() + 1);\n        }\n    };\n\n    constexpr static u32 INVALID_{\
    \ std::numeric_limits<u32>::max() };\n\n    std::vector<std::vector<u32>> graph_;\n\
    \    std::vector<std::pair<u32, u32>> edges_;\n\n    std::vector<u32> indexV_,\
    \ indexE_;\n    std::vector<Component> components_;\n\n    bool isBuilt;\n\n \
    \   void dfs(u32 s) {\n        indexV_[s] = components_.size();\n        std::stack<u32>\
    \ stk{ { s } };\n        while (stk.size()) {\n            u32 v{ stk.top() };\n\
    \            stk.pop();\n            for (auto x : graph_[v]) {\n            \
    \    if (indexV_[x] == INVALID_) {\n                    indexV_[x] = components_.size();\n\
    \                    stk.push(x);\n                }\n            }\n        }\n\
    \    }\n\n    void buildComponents() {\n        std::vector<std::vector<u32>>\
    \ vs(components_.size()), es(components_.size());\n        for (u32 v{} ; v <\
    \ n() ; v++) {\n            vs[indexV_[v]].emplace_back(v);\n        }\n     \
    \   for (u32 e{} ; e < m() ; e++) {\n            es[indexE_[e]].emplace_back(e);\n\
    \        }\n        for (u32 i{} ; i < components_.size() ; i++) {\n         \
    \   components_[i] = Component(vs[i], es[i]);\n        }\n        components_.shrink_to_fit();\n\
    \    }\n\npublic:\n    ConnectedComponents() = default;\n\n    ConnectedComponents(usize\
    \ n) \n        : graph_(n), edges_{}, indexV_(n, INVALID_), indexE_{}, components_{},\
    \ isBuilt{} {\n        graph_.shrink_to_fit();\n    }\n    \n    void addEdge(u32\
    \ u, u32 v) {\n        assert(not isBuilt);\n        graph_[u].emplace_back(v);\n\
    \        graph_[v].emplace_back(u);\n        edges_.emplace_back(u, v);\n    }\n\
    \n    inline usize n() const noexcept {\n        return graph_.size();\n    }\n\
    \n    inline usize m() const noexcept {\n        return edges_.size();\n    }\n\
    \n    Edge edge(u32 e) const {\n        assert(e < m());\n        return Edge{\
    \ edges_[e].first, edges_[e].second, e };\n    }\n\n    void build() {\n     \
    \   assert(not isBuilt);\n        edges_.shrink_to_fit();\n        indexV_.shrink_to_fit();\n\
    \        for (u32 v{} ; v < n() ; v++) {\n            if (indexV_[v] == INVALID_)\
    \ {\n                dfs(v);\n                components_.emplace_back();\n  \
    \          }\n        }\n        indexE_.resize(m());\n        indexE_.shrink_to_fit();\n\
    \        for (u32 e{} ; e < m() ; e++) {\n            indexE_[e] = indexV_[edges_[e].first];\n\
    \        }\n        buildComponents();\n        isBuilt = true;\n    }\n\n   \
    \ inline u32 operator[](const u32 v) const noexcept {\n        assert(isBuilt);\n\
    \        assert(v < n());\n        return indexV_[v];\n    }\n\n    inline u32\
    \ indexV(u32 v) const noexcept {\n        assert(isBuilt);\n        assert(v <\
    \ n());\n        return indexV_[v];\n    }\n\n    inline u32 indexE(u32 e) const\
    \ noexcept {\n        assert(isBuilt);\n        assert(e < m());\n        return\
    \ indexE_[e];\n    }\n\n    inline bool same(u32 u, u32 v) const noexcept {\n\
    \        assert(isBuilt);\n        assert(u < n());\n        assert(v < n());\n\
    \        return indexV_[u] == indexV_[v];\n    }\n\n    inline usize size() const\
    \ noexcept {\n        assert(isBuilt);\n        return components_.size();\n \
    \   }\n\n    inline usize n(u32 c) const noexcept {\n        assert(isBuilt);\n\
    \        assert(c < size());\n        return components_[c].n();\n    }\n\n  \
    \  inline const std::vector<u32>& vs(u32 c) const noexcept {\n        assert(isBuilt);\n\
    \        assert(c < size());\n        return components_[c].vs();\n    }\n\n \
    \   inline usize m(u32 c) const noexcept {\n        assert(isBuilt);\n       \
    \ assert(c < size());\n        return components_[c].m();\n    }\n\n    inline\
    \ const std::vector<u32>& es(u32 c) const noexcept {\n        assert(isBuilt);\n\
    \        assert(c < size());\n        return components_[c].es();\n    }\n\n \
    \   inline bool hasCycle(u32 c) const {\n        assert(isBuilt);\n        assert(c\
    \ < size());\n        return components_[c].hasCycle();\n    }\n\n};\n\n} // namespace\
    \ zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Components/ConnectedComponents.hpp
  requiredBy: []
  timestamp: '2023-07-19 15:15:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/ALDS1_11_D.test.cpp
  - Test/AtCoder/abc292_d.test.cpp
  - Test/AtCoder/abc247_f.test.cpp
  - Test/AtCoder/abc288_c.test.cpp
  - Test/AtCoder/abc293_d.test.cpp
  - Test/AtCoder/abc334_g.test.cpp
documentation_of: Src/Graph/Components/ConnectedComponents.hpp
layout: document
title: "\u7121\u5411\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
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

**計算量**: ならし定数時間

<br />

#### edge

```cpp
Edge edge(u32 e) const
```

$e$ 番目に追加された辺を返す。

返り値のEdgeは以下のようなclassです。
```cpp
class Edge {
public:
    inline u32 u() const noexcept // 辺の端点の頂点を返す。
    inline u32 v() const noexcept // uとは別の端点の頂点を返す。
    inline u32 id() const noexcept // edgeの引数eを返す。
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

#### indexV

```cpp
inline u32 indexV(u32 v) const noexcept
```

`operator[]`と同じ

<br />

#### indexE

```cpp
inline u32 indexE(u32 e) const noexcept
```

$e$ 番目に追加された辺を含む連結成分の番号を返す。

**制約**: 

- `build`を既に呼び出している
- $0\ \le\ e\ <\ \mid E\mid$

**計算量**: 定数時間

<br />

#### same

```cpp
inline bool same(u32 u, u32 v) const noexcept
```

頂点 $u, v$ が同じ連結成分に属しているなら`true`、そうで無い時`false`を返す。

**制約**

- `build`を既に呼び出している
- $0\ \le\ u, v\ <\ \mid V\mid$

<br />

#### vs

```cpp
inline const std::vector<u32>& vs(u32 c) const noexcept
```

`c`番目の連結成分が属する頂点の列を返します。返り値の列は頂点番号に対して昇順に並んでいます。

**制約**

- `build`を既に呼び出している
- `c`は連結成分の数より小さい整数

**計算量**: 連結成分に含まれる頂点数に比例する

<br />

#### es

```cpp
inline const std::vector<u32>& es(u32 c) const noexcept
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

**計算量**: 定数時間

<br />

#### アルゴリズム

DFS(Depth First Search)によって実装されています。
