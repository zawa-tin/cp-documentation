---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/1163.test.cpp
    title: Test/AOJ/1163.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/3168.test.cpp
    title: Test/AOJ/3168.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/GRL_6_A.test.cpp
    title: Test/AOJ/GRL_6_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/GRL_7_A.test.cpp
    title: Test/AOJ/GRL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc239_g.test.cpp
    title: ABC239-G Builder Takahashi
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc317_g.test.cpp
    title: ABC317-G Rearranging
  - icon: ':heavy_check_mark:'
    path: Test/Manual/kupc2016_e.test.cpp
    title: "Kyoto University Programming Contest 2016-E \u67F5"
  - icon: ':heavy_check_mark:'
    path: Test/Manual/practice2_d.test.cpp
    title: AtCoder Library Practice Contest - D Maxflow
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Flow/Dinic.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Flow/Dinic.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class Cap>\nclass Dinic {\nprivate:\n    static_assert(std::is_signed_v<Cap>,\
    \ \"Cap must be signed\");\n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n\
    \    using EdgePointer = std::pair<u32, u32>;\npublic:\n    static constexpr u32\
    \ invalid() noexcept {\n        return INVALID;\n    }\nprivate:\n    class ResidualGraph\
    \ {\n    public:\n        struct Edge {\n            u32 from{}, to{};\n     \
    \       Cap cap{};\n            u32 rev{}, id{};\n            Edge() = default;\n\
    \            Edge(u32 from, u32 to, const Cap& cap, u32 rev, u32 id)\n       \
    \         : from{from}, to{to}, cap{cap}, rev{rev}, id{id} {}\n            EdgePointer\
    \ reverseEdgePointer() const {\n                return EdgePointer{to, rev};\n\
    \            }\n        }; \n    private:\n        usize n_{}, m_{};\n       \
    \ std::vector<std::vector<Edge>> g_{};\n    public:\n        ResidualGraph() =\
    \ default;\n        ResidualGraph(usize n) : n_{n}, m_{}, g_(n) {\n          \
    \  g_.shrink_to_fit();\n        }\n\n        inline usize size() const noexcept\
    \ {\n            return n_;\n        }\n        inline usize edgeNumber() const\
    \ noexcept {\n            return m_;\n        }\n        u32 invalidEdgePointer(u32\
    \ v) const noexcept {\n            return g_[v].size();\n        }\n\n       \
    \ std::vector<Edge>& operator[](usize i) noexcept {\n            return g_[i];\n\
    \        }\n        const std::vector<Edge>& operator[](usize i) const noexcept\
    \ {\n            return g_[i];\n        }\n        Edge& operator[](const EdgePointer&\
    \ e) noexcept {\n            return g_[e.first][e.second];\n        }\n      \
    \  const Edge& operator[](const EdgePointer& e) const noexcept {\n           \
    \ return g_[e.first][e.second];\n        }\n\n        const Edge& reverseEdge(const\
    \ EdgePointer& pos) {\n            return (*this)[(*this)[pos].reverseEdgePointer()];\n\
    \        }\n        \n        u32 addEdge(u32 from, u32 to, const Cap& cap, u32\
    \ id) {\n            u32 i{static_cast<u32>(g_[from].size())};\n            u32\
    \ j{static_cast<u32>(from == to ? i + 1 : g_[to].size())};\n            g_[from].emplace_back(from,\
    \ to, cap, j, id);\n            g_[to].emplace_back(to, from, Cap{}, i, id);\n\
    \            m_++;\n            return i;\n        }\n        void update(Edge&\
    \ e, const Cap& flow) {\n            assert(e.cap >= flow);\n            e.cap\
    \ -= flow;\n            (*this)[e.reverseEdgePointer()].cap += flow;\n       \
    \ }\n    };\n\n    using Edge = typename ResidualGraph::Edge;\n\n    ResidualGraph\
    \ graph_;\n    std::vector<u32> label_;\n    std::vector<EdgePointer> edges_;\n\
    \npublic:\n    inline usize size() const noexcept {\n        return graph_.size();\n\
    \    }\n    inline usize edgeNumber() const noexcept { \n        return graph_.edgeNumber();\n\
    \    }\nprivate:\n\n    bool admissible(const Edge& e) {\n        return e.cap\
    \ > 0 and label_[e.from] + 1 == label_[e.to];\n    }\n\n    bool dualStep(u32\
    \ s, u32 t) {\n        std::fill(label_.begin(), label_.end(), invalid());\n \
    \       label_[s] = 0;\n        std::vector<u32> queue;\n        queue.reserve(size());\n\
    \        queue.emplace_back(s);\n        for (u32 topQ{} ; topQ < queue.size()\
    \ ; topQ++) {\n            u32 v{queue[topQ]};\n            for (const auto& e\
    \ : graph_[v]) if (e.cap > 0) {\n                if (label_[e.to] > label_[v]\
    \ + 1) {\n                    label_[e.to] = label_[v] + 1;\n                \
    \    queue.emplace_back(e.to);\n                }\n            }\n        }\n\
    \        return label_[t] < size();\n    }\n\n    bool findAdmissiblePath(u32\
    \ s, u32 t, std::vector<EdgePointer>& path) {\n        std::vector<u32> currentEdge(size());\n\
    \        currentEdge[t] = graph_.invalidEdgePointer(t);\n        u32 v{s};\n \
    \       while (true) {\n            while (currentEdge[v] != graph_.invalidEdgePointer(v))\
    \ {\n                const Edge& now{graph_[v][currentEdge[v]]};\n           \
    \     if (admissible(now)) {\n                    path.emplace_back(v, currentEdge[v]);\n\
    \                    v = now.to;\n                }\n                else {\n\
    \                    currentEdge[v]++;\n                }\n            }\n   \
    \         if (v == s) return false;\n            if (v == t) return true;\n  \
    \          if (v != t) {\n                v = path.back().first;\n           \
    \     path.pop_back();\n                currentEdge[v]++;\n            }\n   \
    \     }\n        assert(false);\n        return false;\n    }\n\n    Cap flow(const\
    \ std::vector<EdgePointer>& path) {\n        auto min{std::min_element(path.begin(),\
    \ path.end(), [&](const EdgePointer& l, const EdgePointer& r) -> bool {\n    \
    \            return graph_[l].cap < graph_[r].cap;\n            })};\n       \
    \ Cap amount{graph_[*min].cap};\n        assert(amount > 0);\n        for (const\
    \ auto& pos : path) {\n            Edge& e{graph_[pos]};\n            graph_.update(e,\
    \ amount);\n        }\n        return amount;\n    }\n\n    Cap primalStep(u32\
    \ s, u32 t) {\n        std::vector<EdgePointer> path;\n        Cap res{};\n  \
    \      while (findAdmissiblePath(s, t, path)) {\n            res += flow(path);\n\
    \            path.clear();\n        }\n        return res;\n    }\n\npublic:\n\
    \n    Dinic() = default;\n    // @param m: \u8FBA\u6570\u3092\u3053\u3053\u306B\
    \u5165\u308C\u308B\u3068reserve\u3057\u3066\u304F\u308C\u308B\n    Dinic(usize\
    \ n, usize m = usize{}) : graph_{n}, label_(n) {\n        label_.shrink_to_fit();\n\
    \        edges_.reserve(m);\n    }\n\n    u32 addEdge(u32 from, u32 to, const\
    \ Cap& cap, u32 id = invalid()) {\n        assert(from < size());\n        assert(to\
    \ < size());\n        u32 res{static_cast<u32>(edges_.size())};\n        edges_.emplace_back(from,\
    \ graph_.addEdge(from, to, cap, id));\n        return res;\n    }\n\n    u32 from(u32\
    \ id) {\n        assert(id < edgeNumber());\n        return graph_[edges_[id]].from;\n\
    \    }\n\n    u32 to(u32 id) {\n        assert(id < edgeNumber());\n        return\
    \ graph_[edges_[id]].to;\n    }\n\n    Cap residual(u32 id) {\n        assert(id\
    \ < edgeNumber());\n        return graph_[edges_[id]].cap;\n    }\n\n    Cap flowed(u32\
    \ id) {\n        assert(id < edgeNumber());\n        return graph_.reverseEdge(edges_[id]).cap;\n\
    \    }\n\n    Cap originCap(u32 id) {\n        assert(id < edgeNumber());\n  \
    \      EdgePointer e{edges_[id]};\n        return graph_[e].cap + graph_.reverseEdge(edges_[id]).cap;\n\
    \    }\n\n    Cap flow(u32 s, u32 t) {\n        assert(s < size());\n        assert(t\
    \ < size());\n        Cap res{};\n        while (dualStep(s, t)) {\n         \
    \   res += primalStep(s, t);\n        }\n        return res;\n    }\n\n    std::vector<bool>\
    \ minCut(u32 s) const {\n        std::vector<bool> res(size());\n        std::vector<u32>\
    \ queue;\n        queue.reserve(size());\n        queue.emplace_back(s);\n   \
    \     res[s] = true;\n        for (u32 topQ{} ; topQ < queue.size() ; topQ++)\
    \ {\n            u32 v{queue[topQ]};\n            for (const auto& e : graph_[v])\
    \ {\n                if (e.cap > 0 and !res[e.to]) {\n                    res[e.to]\
    \ = true;\n                    queue.emplace_back(e.to);\n                } \n\
    \            }\n        }\n        return res;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class Cap>\nclass Dinic {\nprivate:\n    static_assert(std::is_signed_v<Cap>,\
    \ \"Cap must be signed\");\n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n\
    \    using EdgePointer = std::pair<u32, u32>;\npublic:\n    static constexpr u32\
    \ invalid() noexcept {\n        return INVALID;\n    }\nprivate:\n    class ResidualGraph\
    \ {\n    public:\n        struct Edge {\n            u32 from{}, to{};\n     \
    \       Cap cap{};\n            u32 rev{}, id{};\n            Edge() = default;\n\
    \            Edge(u32 from, u32 to, const Cap& cap, u32 rev, u32 id)\n       \
    \         : from{from}, to{to}, cap{cap}, rev{rev}, id{id} {}\n            EdgePointer\
    \ reverseEdgePointer() const {\n                return EdgePointer{to, rev};\n\
    \            }\n        }; \n    private:\n        usize n_{}, m_{};\n       \
    \ std::vector<std::vector<Edge>> g_{};\n    public:\n        ResidualGraph() =\
    \ default;\n        ResidualGraph(usize n) : n_{n}, m_{}, g_(n) {\n          \
    \  g_.shrink_to_fit();\n        }\n\n        inline usize size() const noexcept\
    \ {\n            return n_;\n        }\n        inline usize edgeNumber() const\
    \ noexcept {\n            return m_;\n        }\n        u32 invalidEdgePointer(u32\
    \ v) const noexcept {\n            return g_[v].size();\n        }\n\n       \
    \ std::vector<Edge>& operator[](usize i) noexcept {\n            return g_[i];\n\
    \        }\n        const std::vector<Edge>& operator[](usize i) const noexcept\
    \ {\n            return g_[i];\n        }\n        Edge& operator[](const EdgePointer&\
    \ e) noexcept {\n            return g_[e.first][e.second];\n        }\n      \
    \  const Edge& operator[](const EdgePointer& e) const noexcept {\n           \
    \ return g_[e.first][e.second];\n        }\n\n        const Edge& reverseEdge(const\
    \ EdgePointer& pos) {\n            return (*this)[(*this)[pos].reverseEdgePointer()];\n\
    \        }\n        \n        u32 addEdge(u32 from, u32 to, const Cap& cap, u32\
    \ id) {\n            u32 i{static_cast<u32>(g_[from].size())};\n            u32\
    \ j{static_cast<u32>(from == to ? i + 1 : g_[to].size())};\n            g_[from].emplace_back(from,\
    \ to, cap, j, id);\n            g_[to].emplace_back(to, from, Cap{}, i, id);\n\
    \            m_++;\n            return i;\n        }\n        void update(Edge&\
    \ e, const Cap& flow) {\n            assert(e.cap >= flow);\n            e.cap\
    \ -= flow;\n            (*this)[e.reverseEdgePointer()].cap += flow;\n       \
    \ }\n    };\n\n    using Edge = typename ResidualGraph::Edge;\n\n    ResidualGraph\
    \ graph_;\n    std::vector<u32> label_;\n    std::vector<EdgePointer> edges_;\n\
    \npublic:\n    inline usize size() const noexcept {\n        return graph_.size();\n\
    \    }\n    inline usize edgeNumber() const noexcept { \n        return graph_.edgeNumber();\n\
    \    }\nprivate:\n\n    bool admissible(const Edge& e) {\n        return e.cap\
    \ > 0 and label_[e.from] + 1 == label_[e.to];\n    }\n\n    bool dualStep(u32\
    \ s, u32 t) {\n        std::fill(label_.begin(), label_.end(), invalid());\n \
    \       label_[s] = 0;\n        std::vector<u32> queue;\n        queue.reserve(size());\n\
    \        queue.emplace_back(s);\n        for (u32 topQ{} ; topQ < queue.size()\
    \ ; topQ++) {\n            u32 v{queue[topQ]};\n            for (const auto& e\
    \ : graph_[v]) if (e.cap > 0) {\n                if (label_[e.to] > label_[v]\
    \ + 1) {\n                    label_[e.to] = label_[v] + 1;\n                \
    \    queue.emplace_back(e.to);\n                }\n            }\n        }\n\
    \        return label_[t] < size();\n    }\n\n    bool findAdmissiblePath(u32\
    \ s, u32 t, std::vector<EdgePointer>& path) {\n        std::vector<u32> currentEdge(size());\n\
    \        currentEdge[t] = graph_.invalidEdgePointer(t);\n        u32 v{s};\n \
    \       while (true) {\n            while (currentEdge[v] != graph_.invalidEdgePointer(v))\
    \ {\n                const Edge& now{graph_[v][currentEdge[v]]};\n           \
    \     if (admissible(now)) {\n                    path.emplace_back(v, currentEdge[v]);\n\
    \                    v = now.to;\n                }\n                else {\n\
    \                    currentEdge[v]++;\n                }\n            }\n   \
    \         if (v == s) return false;\n            if (v == t) return true;\n  \
    \          if (v != t) {\n                v = path.back().first;\n           \
    \     path.pop_back();\n                currentEdge[v]++;\n            }\n   \
    \     }\n        assert(false);\n        return false;\n    }\n\n    Cap flow(const\
    \ std::vector<EdgePointer>& path) {\n        auto min{std::min_element(path.begin(),\
    \ path.end(), [&](const EdgePointer& l, const EdgePointer& r) -> bool {\n    \
    \            return graph_[l].cap < graph_[r].cap;\n            })};\n       \
    \ Cap amount{graph_[*min].cap};\n        assert(amount > 0);\n        for (const\
    \ auto& pos : path) {\n            Edge& e{graph_[pos]};\n            graph_.update(e,\
    \ amount);\n        }\n        return amount;\n    }\n\n    Cap primalStep(u32\
    \ s, u32 t) {\n        std::vector<EdgePointer> path;\n        Cap res{};\n  \
    \      while (findAdmissiblePath(s, t, path)) {\n            res += flow(path);\n\
    \            path.clear();\n        }\n        return res;\n    }\n\npublic:\n\
    \n    Dinic() = default;\n    // @param m: \u8FBA\u6570\u3092\u3053\u3053\u306B\
    \u5165\u308C\u308B\u3068reserve\u3057\u3066\u304F\u308C\u308B\n    Dinic(usize\
    \ n, usize m = usize{}) : graph_{n}, label_(n) {\n        label_.shrink_to_fit();\n\
    \        edges_.reserve(m);\n    }\n\n    u32 addEdge(u32 from, u32 to, const\
    \ Cap& cap, u32 id = invalid()) {\n        assert(from < size());\n        assert(to\
    \ < size());\n        u32 res{static_cast<u32>(edges_.size())};\n        edges_.emplace_back(from,\
    \ graph_.addEdge(from, to, cap, id));\n        return res;\n    }\n\n    u32 from(u32\
    \ id) {\n        assert(id < edgeNumber());\n        return graph_[edges_[id]].from;\n\
    \    }\n\n    u32 to(u32 id) {\n        assert(id < edgeNumber());\n        return\
    \ graph_[edges_[id]].to;\n    }\n\n    Cap residual(u32 id) {\n        assert(id\
    \ < edgeNumber());\n        return graph_[edges_[id]].cap;\n    }\n\n    Cap flowed(u32\
    \ id) {\n        assert(id < edgeNumber());\n        return graph_.reverseEdge(edges_[id]).cap;\n\
    \    }\n\n    Cap originCap(u32 id) {\n        assert(id < edgeNumber());\n  \
    \      EdgePointer e{edges_[id]};\n        return graph_[e].cap + graph_.reverseEdge(edges_[id]).cap;\n\
    \    }\n\n    Cap flow(u32 s, u32 t) {\n        assert(s < size());\n        assert(t\
    \ < size());\n        Cap res{};\n        while (dualStep(s, t)) {\n         \
    \   res += primalStep(s, t);\n        }\n        return res;\n    }\n\n    std::vector<bool>\
    \ minCut(u32 s) const {\n        std::vector<bool> res(size());\n        std::vector<u32>\
    \ queue;\n        queue.reserve(size());\n        queue.emplace_back(s);\n   \
    \     res[s] = true;\n        for (u32 topQ{} ; topQ < queue.size() ; topQ++)\
    \ {\n            u32 v{queue[topQ]};\n            for (const auto& e : graph_[v])\
    \ {\n                if (e.cap > 0 and !res[e.to]) {\n                    res[e.to]\
    \ = true;\n                    queue.emplace_back(e.to);\n                } \n\
    \            }\n        }\n        return res;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Flow/Dinic.hpp
  requiredBy: []
  timestamp: '2023-12-16 16:17:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/GRL_7_A.test.cpp
  - Test/AOJ/3168.test.cpp
  - Test/AOJ/1163.test.cpp
  - Test/AOJ/GRL_6_A.test.cpp
  - Test/Manual/abc239_g.test.cpp
  - Test/Manual/practice2_d.test.cpp
  - Test/Manual/kupc2016_e.test.cpp
  - Test/Manual/abc317_g.test.cpp
documentation_of: Src/Graph/Flow/Dinic.hpp
layout: document
title: "Dinic (\u6700\u5927\u6D41\u30FB\u6700\u5C0F\u30AB\u30C3\u30C8)"
---

## 概要

## ライブラリの使い方

#### テンプレート引数

```cpp
template <class Cap>
```

容量・流量の型を`Cap`で指定します。残余ネットワークを構築する都合上、`signed`な型のみを受け付けます。


#### コンストラクタ

```cpp
Dinic() = default; (1)
Dinic(usize n, usize m = usize{}) (2)
```

(1) 特に使用を想定していない

(2) 頂点数 $n$ の辺が存在しないネットワークを構築する

$m$ は想定される辺数を与えることで内部の`std::vector`が`std::vector::reserve`を呼び、ちょっと早くなるかもしれません(検証はしていません)。デフォルトで0が指定されています

計算量: $O(n + m)$

<br />

#### size

```cpp
inline usize size() const noexcept
```

頂点数を返します。

計算量: 定数時間

<br />

#### edgeNumber

```cpp
inline usize edgeNumber() const noexcept
```

(ユーザーが追加した)辺数を返します。逆辺は考慮されていません

計算量: 定数時間

<br />

#### addEdge

```cpp
u32 addEdge(u32 from, u32 to, const Cap& cap , u32 id = -1)
```

頂点`from`から頂点`to`へ向けて辺容量`cap`の辺を貼ります。返り値としてこの辺が何番目に追加された辺かを返します。

この返り値とは別に識別番号がほしい時様に、`id`を指定することができます。(デフォルトでは-1 = `std::numeric_limits<u32>::max()`が指定されています。

計算量: 定数時間

<br />

#### from

```cpp
u32 from(u32 id)
```

`id`番目に(`addEdge`で)追加された辺の接続元の頂点番号を返します。

計算量: 定数時間

<br />

#### to

```cpp
u32 to(u32 id)
```

`id`番目に(`addEdge`で)追加された辺の接続先の頂点番号を返します。

計算量: 定数時間

<br />

#### residual

```cpp
u32 residual(u32 id)
```

`id`番目に(`addEdge`で)追加された辺の残余容量を返します。

計算量: 定数時間

<br />

#### flowed

```cpp
u32 flowed(u32 id)
```

`id`番目に(`addEdge`で)追加された辺に流れた水の量を返します。

計算量: 定数時間

<br />

#### originCap

```cpp
u32 originCap(u32 id)
```

`id`番目に(`addEdge`で)追加された辺の元々の容量を返します。

計算量: 定数時間

<br />

#### flow

```cpp
Cap flow(u32 s, u32 t)
```

ネットワーク $(V, E, s, t)$ 上の最大フロー $f$ を求めます。

内部で持っている残余ネットワークは $f$ で誘導される残余ネットワークになります。

返り値は $|f|$ です。

計算量: $O(n^{2}m)$

(ネットワークによってはもっとタイトに見積もれる場合があります。)

<br />

#### minCut

```cpp
std::vector<bool> minCut(u32 s) const
```

現在の残余ネットワーク上で`s`から正の残余容量の辺のみを伝って到達できる頂点に`true`が入った`std::vector<bool>`を返します。

計算量: $O(n + m)$

<br />

## 参考

- [https://misawa.github.io/others/flow/dinic_time_complexity.html](https://misawa.github.io/others/flow/dinic_time_complexity.html)
   - 内部の変数・メンバ名はこの記事に準じている(つもりである)
- [http://hos.ac/slides/20150319_flow.pdf](http://hos.ac/slides/20150319_flow.pdf)

