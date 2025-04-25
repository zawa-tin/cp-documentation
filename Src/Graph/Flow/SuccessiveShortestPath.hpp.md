---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/U32Pair.hpp
    title: Src/Utility/U32Pair.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2828.test.cpp
    title: "AOJ2828 \u30DE\u30C8\u30EA\u30E7\u30FC\u30B7\u30AB"
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/GRL_6_B.test.cpp
    title: Test/AOJ/GRL_6_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc247_g.test.cpp
    title: ABC247-G Dream Team
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc004_d.test.cpp
    title: Test/Manual/abc004_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/practice2_e.test.cpp
    title: AtCoder Library Practice Contest - E MinCostFlow
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Flow/SuccessiveShortestPath.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Utility/U32Pair.hpp\"\
    \n\n#line 4 \"Src/Utility/U32Pair.hpp\"\n\n#include <functional>\n#include <iostream>\n\
    \nnamespace zawa {\n\nclass U32Pair {\nprivate:\n    static constexpr u32 SHIFT{32};\n\
    \    static constexpr u32 MASK{static_cast<u32>((1LL << SHIFT) - 1)};\n    u64\
    \ value_{};\npublic:\n    constexpr U32Pair() {}\n    constexpr U32Pair(u32 first,\
    \ u32 second) {\n        value_ = (static_cast<u64>(first) << SHIFT) | second;\n\
    \    }\n    constexpr u32 first() const noexcept {\n        return static_cast<u32>(value_\
    \ >> SHIFT);\n    }\n    constexpr u32 second() const noexcept {\n        return\
    \ static_cast<u32>(value_ & MASK);\n    }\n    constexpr u64 combined() const\
    \ noexcept {\n        return value_;\n    }\n    constexpr U32Pair& operator=(const\
    \ U32Pair& rhs) {\n        value_ = rhs.value_;\n        return *this;\n    }\n\
    \    friend constexpr bool operator==(const U32Pair& lhs, const U32Pair& rhs)\
    \ {\n        return lhs.value_ == rhs.value_;\n    }\n    friend constexpr bool\
    \ operator!=(const U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_\
    \ != rhs.value_;\n    }\n    friend constexpr bool operator<(const U32Pair& lhs,\
    \ const U32Pair& rhs) {\n        return lhs.value_ < rhs.value_;\n    }\n    friend\
    \ constexpr bool operator<=(const U32Pair& lhs, const U32Pair& rhs) {\n      \
    \  return lhs.value_ <= rhs.value_;\n    }\n    friend constexpr bool operator>(const\
    \ U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_ > rhs.value_;\n\
    \    }\n    friend constexpr bool operator>=(const U32Pair& lhs, const U32Pair&\
    \ rhs) {\n        return lhs.value_ >= rhs.value_;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const U32Pair& pair) {\n        os << '(' << pair.first()\
    \ << ',' << pair.second() << ')';\n        return os;\n    }\n};\n\nstruct U32PairHash\
    \ {\n    usize operator()(const U32Pair& pair) const noexcept {\n        return\
    \ std::hash<u64>{}(pair.combined());\n    }\n};\n\n} // namespace zawa\n#line\
    \ 5 \"Src/Graph/Flow/SuccessiveShortestPath.hpp\"\n\n#include <cassert>\n#include\
    \ <limits>\n#include <queue>\n#include <type_traits>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace zawa {\n\ntemplate <class Cap, class Cost>\nclass SuccessiveShortestPath\
    \ {\npublic:\n    static_assert(std::is_signed_v<Cost>, U\"Cost must be signed\"\
    );\n    static constexpr Cost invalid{(std::numeric_limits<Cost>::max() >> 1)\
    \ - 1};\n    static constexpr u32 reverseId(u32 i) noexcept {\n        return\
    \ i ^ 1;\n    }\n\n    struct Edge {\n        u32 from{}, to{};\n        Cap residual{};\n\
    \        Cost cost{};\n        Edge() = default;\n        Edge(u32 from, u32 to,\
    \ const Cap& cap, const Cost& cost)\n            : from{from}, to{to}, residual{cap},\
    \ cost{cost} {}\n    };\n\n    usize n_{}, m_{};\n    std::vector<Edge> edges_;\n\
    \    std::vector<std::vector<u32>> g_;\n    std::vector<Cost> dist_, potential_;\n\
    \    std::vector<U32Pair> prev_;\n    Cost mcf_{};\n\n    constexpr usize size()\
    \ const noexcept {\n        return n_;\n    }\n    constexpr usize edgeSize()\
    \ const noexcept {\n        return m_;\n    }\n    \n    SuccessiveShortestPath()\
    \ = default;\n    SuccessiveShortestPath(usize n, usize m = usize{}) \n      \
    \  : n_{n}, m_{}, edges_{}, g_(n), dist_(n), potential_(n), prev_(n), mcf_{} {\n\
    \        g_.shrink_to_fit();\n        dist_.shrink_to_fit();\n        potential_.shrink_to_fit();\n\
    \        prev_.shrink_to_fit();\n        edges_.reserve(2 * m);\n    }\n\n   \
    \ void emplace(u32 from, u32 to, const Cap& cap, const Cost& cost) {\n       \
    \ g_[from].emplace_back(m_);\n        edges_.emplace_back(from, to, cap, cost);\n\
    \        m_++;\n    }\n\n    u32 addEdge(u32 from, u32 to, const Cap& cap, const\
    \ Cost& cost) {\n        assert(from < size());\n        assert(to < size());\n\
    \        u32 res{static_cast<u32>(m_)};\n        emplace(from, to, cap, cost);\n\
    \        emplace(to, from, Cap{}, -cost);\n        return res;\n    }\n\n    inline\
    \ u32 from(u32 i) const noexcept {\n        return edges_[i].from;\n    }\n  \
    \  inline u32 to(u32 i) const noexcept {\n        return edges_[i].to;\n    }\n\
    \    inline const Cap& residual(u32 i) const noexcept {\n        return edges_[i].residual;\n\
    \    }\n    inline const Cost& cost(u32 i) const noexcept {\n        return edges_[i].cost;\n\
    \    }\n    inline const Cap& flowed(u32 i) const noexcept {\n        assert(i\
    \ < edgeSize());\n        return residual(i ^ 1);\n    }\n    inline const Cap&\
    \ capcacity(u32 i) const noexcept {\n        assert(i < edgeSize());\n       \
    \ return residual(i) + flowed(i);\n    }\n\n    inline Cost edgeCost(u32 i) const\
    \ noexcept {\n        return potential_[from(i)] + cost(i) - potential_[to(i)];\n\
    \    }\n    bool relax(u32 i) {\n        if (residual(i) > 0 and dist_[to(i)]\
    \ > dist_[from(i)] + edgeCost(i)) {\n            dist_[to(i)] = dist_[from(i)]\
    \ + edgeCost(i);\n            prev_[to(i)] = U32Pair{from(i), i};\n          \
    \  return true;\n        }\n        return false;\n    }\n\n    bool dijkstra(u32\
    \ s, u32 t) {\n        assert(s < size());\n        assert(t < size());\n    \
    \    std::fill(dist_.begin(), dist_.end(), invalid);\n        dist_[s] = Cost{};\n\
    \        using qt = std::pair<Cost, u32>;\n        std::priority_queue<qt, std::vector<qt>,\
    \ std::greater<qt>> que;\n        que.emplace(dist_[s], s);\n        while (que.size())\
    \ {\n            auto [d, v]{que.top()};\n            que.pop();\n           \
    \ if (dist_[v] < d) continue;\n            for (u32 i : g_[v]) {\n           \
    \     if (relax(i)) {\n                    que.emplace(dist_[to(i)], to(i));\n\
    \                }\n            }\n        }\n        return dist_[t] < invalid;\n\
    \    }\n\n    bool dagdp(u32 s, u32 t) {\n        assert(s < size());\n      \
    \  assert(t < size());\n        std::fill(dist_.begin(), dist_.end(), invalid);\n\
    \        dist_[s] = Cost{};\n        std::vector<u32> ord;\n        ord.reserve(size());\n\
    \        std::vector<bool> vis(size());\n        vis[s] = true;\n        ord.push_back(s);\n\
    \        for (u32 i{} ; i < ord.size() ; i++) {\n            u32 v{ord[i]};\n\
    \            for (auto e : g_[v]) {\n                if (!vis[to(e)]) {\n    \
    \                ord.push_back(to(e));\n                    vis[to(e)] = true;\n\
    \                }\n                relax(e);\n            }\n        }\n    \
    \    return dist_[t] < invalid;\n    }\n\n    bool bellmanford(u32 s, u32 t) {\n\
    \        assert(s < size());\n        assert(t < size());\n        std::fill(dist_.begin(),\
    \ dist_.end(), invalid);\n        dist_[s] = Cost{};\n        for (u32 i{} ; i\
    \ + 1 < size() ; i++) {\n            for (u32 j{} ; j < edgeSize() ; j++) {\n\
    \                relax(j);\n            }\n        }\n        return dist_[t]\
    \ < invalid;\n    }\n\n    void updatePotential() {\n        for (u32 v{} ; v\
    \ < size() ; v++) {\n            potential_[v] = potential_[v] + (dist_[v] ==\
    \ invalid ? Cost{} : dist_[v]);\n        }\n    }\n\n    Cap flush(u32 s, u32\
    \ t, Cap up = std::numeric_limits<Cap>::max()) {\n        for (u32 v{t} ; v !=\
    \ s ; v = prev_[v].first()) {\n            up = std::min(up, residual(prev_[v].second()));\n\
    \        }\n        for (u32 v{t} ; v != s ; v = prev_[v].first()) {\n       \
    \     edges_[prev_[v].second()].residual -= up;\n            edges_[prev_[v].second()\
    \ ^ 1].residual += up;\n        }\n        return up;\n    }\n\n    bool flow(u32\
    \ s, u32 t, Cap flow) {\n        assert(s < size());\n        assert(t < size());\n\
    \        while (flow > 0 and dijkstra(s, t)) {\n            updatePotential();\n\
    \            Cap water{flush(s, t, flow)};\n            mcf_ += potential_[t]\
    \ * water;\n            flow -= water;\n        }\n        return flow == 0;\n\
    \    }\n\n    Cap maxflow(u32 s, u32 t) {\n        assert(s < size());\n     \
    \   assert(t < size());\n        Cap flow{};\n        while (dijkstra(s, t)) {\n\
    \            updatePotential();\n            Cap water{flush(s, t)};\n       \
    \     mcf_ += potential_[t] * water;\n            flow += water;\n        }\n\
    \        return flow;\n    }\n\n    std::vector<Cost> slope(u32 s, u32 t) {\n\
    \        assert(s < size());\n        assert(t < size());\n        Cap flow{};\n\
    \        std::vector<Cost> res;\n        while (dijkstra(s, t)) {\n          \
    \  updatePotential();\n            Cap water{flush(s, t)};\n            for (u32\
    \ i{} ; i < water ; i++) {\n                res.emplace_back(mcf_);\n        \
    \        mcf_ += potential_[t];\n                flow++;\n            }\n    \
    \    }\n        res.emplace_back(mcf_);\n        return res;\n    }\n\n    struct\
    \ Line {\n        Cap dn{}, up{};\n        Cost slope{};\n        Line() = default;\n\
    \        Line(Cap dn, Cap up, Cost slope) : dn{dn}, up{up}, slope{slope} {}\n\
    \    };\n    std::vector<Line> slopeACL(u32 s, u32 t) {\n        assert(s < size());\n\
    \        assert(t < size()); \n        Cap flow{};\n        std::vector<Line>\
    \ res;\n        while (dijkstra(s, t)) {\n            updatePotential();\n   \
    \         Cap water{flush(s, t)};\n            mcf_ += potential_[t] * water;\n\
    \            res.emplace_back(flow, flow + water, potential_[t]);\n          \
    \  flow += water;\n        }\n        return res;\n    }\n\n    Cost minCost()\
    \ const noexcept {\n        return mcf_;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Utility/U32Pair.hpp\"\
    \n\n#include <cassert>\n#include <limits>\n#include <queue>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class Cap,\
    \ class Cost>\nclass SuccessiveShortestPath {\npublic:\n    static_assert(std::is_signed_v<Cost>,\
    \ U\"Cost must be signed\");\n    static constexpr Cost invalid{(std::numeric_limits<Cost>::max()\
    \ >> 1) - 1};\n    static constexpr u32 reverseId(u32 i) noexcept {\n        return\
    \ i ^ 1;\n    }\n\n    struct Edge {\n        u32 from{}, to{};\n        Cap residual{};\n\
    \        Cost cost{};\n        Edge() = default;\n        Edge(u32 from, u32 to,\
    \ const Cap& cap, const Cost& cost)\n            : from{from}, to{to}, residual{cap},\
    \ cost{cost} {}\n    };\n\n    usize n_{}, m_{};\n    std::vector<Edge> edges_;\n\
    \    std::vector<std::vector<u32>> g_;\n    std::vector<Cost> dist_, potential_;\n\
    \    std::vector<U32Pair> prev_;\n    Cost mcf_{};\n\n    constexpr usize size()\
    \ const noexcept {\n        return n_;\n    }\n    constexpr usize edgeSize()\
    \ const noexcept {\n        return m_;\n    }\n    \n    SuccessiveShortestPath()\
    \ = default;\n    SuccessiveShortestPath(usize n, usize m = usize{}) \n      \
    \  : n_{n}, m_{}, edges_{}, g_(n), dist_(n), potential_(n), prev_(n), mcf_{} {\n\
    \        g_.shrink_to_fit();\n        dist_.shrink_to_fit();\n        potential_.shrink_to_fit();\n\
    \        prev_.shrink_to_fit();\n        edges_.reserve(2 * m);\n    }\n\n   \
    \ void emplace(u32 from, u32 to, const Cap& cap, const Cost& cost) {\n       \
    \ g_[from].emplace_back(m_);\n        edges_.emplace_back(from, to, cap, cost);\n\
    \        m_++;\n    }\n\n    u32 addEdge(u32 from, u32 to, const Cap& cap, const\
    \ Cost& cost) {\n        assert(from < size());\n        assert(to < size());\n\
    \        u32 res{static_cast<u32>(m_)};\n        emplace(from, to, cap, cost);\n\
    \        emplace(to, from, Cap{}, -cost);\n        return res;\n    }\n\n    inline\
    \ u32 from(u32 i) const noexcept {\n        return edges_[i].from;\n    }\n  \
    \  inline u32 to(u32 i) const noexcept {\n        return edges_[i].to;\n    }\n\
    \    inline const Cap& residual(u32 i) const noexcept {\n        return edges_[i].residual;\n\
    \    }\n    inline const Cost& cost(u32 i) const noexcept {\n        return edges_[i].cost;\n\
    \    }\n    inline const Cap& flowed(u32 i) const noexcept {\n        assert(i\
    \ < edgeSize());\n        return residual(i ^ 1);\n    }\n    inline const Cap&\
    \ capcacity(u32 i) const noexcept {\n        assert(i < edgeSize());\n       \
    \ return residual(i) + flowed(i);\n    }\n\n    inline Cost edgeCost(u32 i) const\
    \ noexcept {\n        return potential_[from(i)] + cost(i) - potential_[to(i)];\n\
    \    }\n    bool relax(u32 i) {\n        if (residual(i) > 0 and dist_[to(i)]\
    \ > dist_[from(i)] + edgeCost(i)) {\n            dist_[to(i)] = dist_[from(i)]\
    \ + edgeCost(i);\n            prev_[to(i)] = U32Pair{from(i), i};\n          \
    \  return true;\n        }\n        return false;\n    }\n\n    bool dijkstra(u32\
    \ s, u32 t) {\n        assert(s < size());\n        assert(t < size());\n    \
    \    std::fill(dist_.begin(), dist_.end(), invalid);\n        dist_[s] = Cost{};\n\
    \        using qt = std::pair<Cost, u32>;\n        std::priority_queue<qt, std::vector<qt>,\
    \ std::greater<qt>> que;\n        que.emplace(dist_[s], s);\n        while (que.size())\
    \ {\n            auto [d, v]{que.top()};\n            que.pop();\n           \
    \ if (dist_[v] < d) continue;\n            for (u32 i : g_[v]) {\n           \
    \     if (relax(i)) {\n                    que.emplace(dist_[to(i)], to(i));\n\
    \                }\n            }\n        }\n        return dist_[t] < invalid;\n\
    \    }\n\n    bool dagdp(u32 s, u32 t) {\n        assert(s < size());\n      \
    \  assert(t < size());\n        std::fill(dist_.begin(), dist_.end(), invalid);\n\
    \        dist_[s] = Cost{};\n        std::vector<u32> ord;\n        ord.reserve(size());\n\
    \        std::vector<bool> vis(size());\n        vis[s] = true;\n        ord.push_back(s);\n\
    \        for (u32 i{} ; i < ord.size() ; i++) {\n            u32 v{ord[i]};\n\
    \            for (auto e : g_[v]) {\n                if (!vis[to(e)]) {\n    \
    \                ord.push_back(to(e));\n                    vis[to(e)] = true;\n\
    \                }\n                relax(e);\n            }\n        }\n    \
    \    return dist_[t] < invalid;\n    }\n\n    bool bellmanford(u32 s, u32 t) {\n\
    \        assert(s < size());\n        assert(t < size());\n        std::fill(dist_.begin(),\
    \ dist_.end(), invalid);\n        dist_[s] = Cost{};\n        for (u32 i{} ; i\
    \ + 1 < size() ; i++) {\n            for (u32 j{} ; j < edgeSize() ; j++) {\n\
    \                relax(j);\n            }\n        }\n        return dist_[t]\
    \ < invalid;\n    }\n\n    void updatePotential() {\n        for (u32 v{} ; v\
    \ < size() ; v++) {\n            potential_[v] = potential_[v] + (dist_[v] ==\
    \ invalid ? Cost{} : dist_[v]);\n        }\n    }\n\n    Cap flush(u32 s, u32\
    \ t, Cap up = std::numeric_limits<Cap>::max()) {\n        for (u32 v{t} ; v !=\
    \ s ; v = prev_[v].first()) {\n            up = std::min(up, residual(prev_[v].second()));\n\
    \        }\n        for (u32 v{t} ; v != s ; v = prev_[v].first()) {\n       \
    \     edges_[prev_[v].second()].residual -= up;\n            edges_[prev_[v].second()\
    \ ^ 1].residual += up;\n        }\n        return up;\n    }\n\n    bool flow(u32\
    \ s, u32 t, Cap flow) {\n        assert(s < size());\n        assert(t < size());\n\
    \        while (flow > 0 and dijkstra(s, t)) {\n            updatePotential();\n\
    \            Cap water{flush(s, t, flow)};\n            mcf_ += potential_[t]\
    \ * water;\n            flow -= water;\n        }\n        return flow == 0;\n\
    \    }\n\n    Cap maxflow(u32 s, u32 t) {\n        assert(s < size());\n     \
    \   assert(t < size());\n        Cap flow{};\n        while (dijkstra(s, t)) {\n\
    \            updatePotential();\n            Cap water{flush(s, t)};\n       \
    \     mcf_ += potential_[t] * water;\n            flow += water;\n        }\n\
    \        return flow;\n    }\n\n    std::vector<Cost> slope(u32 s, u32 t) {\n\
    \        assert(s < size());\n        assert(t < size());\n        Cap flow{};\n\
    \        std::vector<Cost> res;\n        while (dijkstra(s, t)) {\n          \
    \  updatePotential();\n            Cap water{flush(s, t)};\n            for (u32\
    \ i{} ; i < water ; i++) {\n                res.emplace_back(mcf_);\n        \
    \        mcf_ += potential_[t];\n                flow++;\n            }\n    \
    \    }\n        res.emplace_back(mcf_);\n        return res;\n    }\n\n    struct\
    \ Line {\n        Cap dn{}, up{};\n        Cost slope{};\n        Line() = default;\n\
    \        Line(Cap dn, Cap up, Cost slope) : dn{dn}, up{up}, slope{slope} {}\n\
    \    };\n    std::vector<Line> slopeACL(u32 s, u32 t) {\n        assert(s < size());\n\
    \        assert(t < size()); \n        Cap flow{};\n        std::vector<Line>\
    \ res;\n        while (dijkstra(s, t)) {\n            updatePotential();\n   \
    \         Cap water{flush(s, t)};\n            mcf_ += potential_[t] * water;\n\
    \            res.emplace_back(flow, flow + water, potential_[t]);\n          \
    \  flow += water;\n        }\n        return res;\n    }\n\n    Cost minCost()\
    \ const noexcept {\n        return mcf_;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Utility/U32Pair.hpp
  isVerificationFile: false
  path: Src/Graph/Flow/SuccessiveShortestPath.hpp
  requiredBy: []
  timestamp: '2024-01-04 02:51:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/2828.test.cpp
  - Test/AOJ/GRL_6_B.test.cpp
  - Test/AtCoder/abc247_g.test.cpp
  - Test/Manual/practice2_e.test.cpp
  - Test/Manual/abc004_d.test.cpp
documentation_of: Src/Graph/Flow/SuccessiveShortestPath.hpp
layout: document
title: "SuccessiveShortestPath (\u6700\u5C0F\u8CBB\u7528\u6D41\u3001\u6700\u77ED\u8DEF\
  \u53CD\u5FA9\u6CD5)"
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

**計算量**: $O(\text{flow} \times \mid E\mid\log (\mid V\mid))$

負辺を`addEdge`していると遅い。こういう時は`bellmanford`、`dagdp` -> `updatePotential` でポテンシャルを予め計算しておくと正常に動作する。
- `bellmanford`は $O(\midV\mid\midE\mid)$ で動作することに注意

#### maxflow

```cpp
Cap maxflow(u32 s, u32 t)
```

$s$ から $t$ へ流せるだけ水を流す (最小費用最大流問題)

**計算量**: 最大流を $F$ として $O(F \times \mid E\mid\log (\mid V\mid))$

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

**計算量**: 最大流を $F$ として $O(F \times \mid E\mid\log (\mid V\mid))$

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
