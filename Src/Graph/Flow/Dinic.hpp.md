---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/U32Pair.hpp
    title: Src/Utility/U32Pair.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Flow/BurnBury.hpp
    title: Src/Graph/Flow/BurnBury.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/1163.test.cpp
    title: Test/AOJ/1163.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2872.test.cpp
    title: "AOJ2872 \u6700\u77ED\u8DDD\u96E2\u3092\u4F38\u3070\u3059\u3048\u3073\u3061\
      \u3083\u3093"
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2943.test.cpp
    title: "AOJ2943 \u30A4\u30EB\u30DF\u30CD\u30FC\u30B7\u30E7\u30F3"
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
    path: Test/AtCoder/abc193_f.test.cpp
    title: ABC193-F Zebraness
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc205_f.test.cpp
    title: ABC205-F Grid and Tokens
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc263_g.test.cpp
    title: ABC263-G Erasing Prime Pairs
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc318_g.test.cpp
    title: ABC318-G Typical Path Problem
  - icon: ':heavy_check_mark:'
    path: Test/LC/bipartitematching.test.cpp
    title: Test/LC/bipartitematching.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: Test/Manual/typical90_an.test.cpp
    title: "\u7AF6\u30D7\u30ED\u5178\u578B90\u554F-040 Get More Money"
  - icon: ':heavy_check_mark:'
    path: Test/Manual/typical90_by.test.cpp
    title: Test/Manual/typical90_by.test.cpp
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
    \n} // namespace zawa\n#line 2 \"Src/Utility/U32Pair.hpp\"\n\n#line 4 \"Src/Utility/U32Pair.hpp\"\
    \n\n#include <functional>\n#include <iostream>\n\nnamespace zawa {\n\nclass U32Pair\
    \ {\nprivate:\n    static constexpr u32 SHIFT{32};\n    static constexpr u32 MASK{static_cast<u32>((1LL\
    \ << SHIFT) - 1)};\n    u64 value_{};\npublic:\n    constexpr U32Pair() {}\n \
    \   constexpr U32Pair(u32 first, u32 second) {\n        value_ = (static_cast<u64>(first)\
    \ << SHIFT) | second;\n    }\n    constexpr u32 first() const noexcept {\n   \
    \     return static_cast<u32>(value_ >> SHIFT);\n    }\n    constexpr u32 second()\
    \ const noexcept {\n        return static_cast<u32>(value_ & MASK);\n    }\n \
    \   constexpr u64 combined() const noexcept {\n        return value_;\n    }\n\
    \    constexpr U32Pair& operator=(const U32Pair& rhs) {\n        value_ = rhs.value_;\n\
    \        return *this;\n    }\n    friend constexpr bool operator==(const U32Pair&\
    \ lhs, const U32Pair& rhs) {\n        return lhs.value_ == rhs.value_;\n    }\n\
    \    friend constexpr bool operator!=(const U32Pair& lhs, const U32Pair& rhs)\
    \ {\n        return lhs.value_ != rhs.value_;\n    }\n    friend constexpr bool\
    \ operator<(const U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_\
    \ < rhs.value_;\n    }\n    friend constexpr bool operator<=(const U32Pair& lhs,\
    \ const U32Pair& rhs) {\n        return lhs.value_ <= rhs.value_;\n    }\n   \
    \ friend constexpr bool operator>(const U32Pair& lhs, const U32Pair& rhs) {\n\
    \        return lhs.value_ > rhs.value_;\n    }\n    friend constexpr bool operator>=(const\
    \ U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_ >= rhs.value_;\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& os, const U32Pair& pair)\
    \ {\n        os << '(' << pair.first() << ',' << pair.second() << ')';\n     \
    \   return os;\n    }\n};\n\nstruct U32PairHash {\n    usize operator()(const\
    \ U32Pair& pair) const noexcept {\n        return std::hash<u64>{}(pair.combined());\n\
    \    }\n};\n\n} // namespace zawa\n#line 5 \"Src/Graph/Flow/Dinic.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <limits>\n#include <type_traits>\n\
    #include <vector>\n#include <queue>\n\nnamespace zawa {\n\ntemplate <class Cap>\
    \ \nclass Dinic {\nprivate:\n    static_assert(std::is_signed_v<Cap>, \"Cap must\
    \ be signed\");\n    usize n_{}, m_{};\n    static constexpr u32 invalid() noexcept\
    \ {\n        return std::numeric_limits<u32>::max();\n    }\npublic:\n    inline\
    \ usize size() const noexcept {\n        return n_;\n    }\n    inline usize edgeNumber()\
    \ const noexcept {\n        return m_;\n    }\nprivate:\n    struct Edge {\n \
    \       u32 to{}, rev{};\n        Cap residual{};\n        Edge() = default;\n\
    \        Edge(u32 to, u32 rev, const Cap& residual) \n            : to{to}, rev{rev},\
    \ residual{residual} {}\n    };\n\n    std::vector<std::vector<Edge>> g_;\n  \
    \  std::vector<U32Pair> edges_;\n    std::vector<u32> label_, cur_;\n\n    bool\
    \ dualStep(u32 s, u32 t) {\n        std::fill(label_.begin(), label_.end(), invalid());\n\
    \        label_[s] = 0;\n        std::queue<u32> queue{ { s } };\n        while\
    \ (queue.size()) {\n            u32 v{queue.front()};\n            queue.pop();\n\
    \            for (const Edge& e : g_[v]) if (e.residual > 0) {\n             \
    \   if (label_[e.to] > label_[v] + 1) {\n                    label_[e.to] = label_[v]\
    \ + 1;\n                    if (e.to == t) return true;\n                    queue.emplace(e.to);\n\
    \                }\n            }\n        }\n        return false;\n    }\n\n\
    \    bool admissible(u32 v, const Edge& e) const noexcept {\n        return e.residual\
    \ > 0 and label_[v] + 1 == label_[e.to];\n    }\n\n    inline void flow(Edge&\
    \ e, Cap f) {\n        e.residual -= f;\n        g_[e.to][e.rev].residual += f;\n\
    \    }\n\n    Cap dfs(u32 v, u32 t, Cap up) {\n        if (v == t) return up;\n\
    \        Cap res{};\n        for (u32& i{cur_[v]} ; i < g_[v].size() ; i++) {\n\
    \            if (!admissible(v, g_[v][i])) continue;\n            Cap f{dfs(g_[v][i].to,\
    \ t, std::min(g_[v][i].residual, up - res))};\n            if (f == 0) continue;\n\
    \            flow(g_[v][i], f);\n            res += f;\n            if (res ==\
    \ up) return res;\n        }\n        return res;\n    }\n\n    Cap primalStep(u32\
    \ s, u32 t) {\n        std::fill(cur_.begin(), cur_.end(), 0u);\n        cur_[t]\
    \ = g_[t].size();\n        Cap res{};\n        while (true) {\n            Cap\
    \ f{dfs(s, t, std::numeric_limits<Cap>::max())};\n            if (f == 0) break;\n\
    \            res += f;\n        }\n        return res;\n    }\n\n    const Edge&\
    \ edge(u32 i) const noexcept {\n        return g_[edges_[i].first()][edges_[i].second()];\n\
    \    }\n    const Edge& reverse(u32 i) const noexcept {\n        const Edge& e{edge(i)};\n\
    \        return g_[e.to][e.rev];\n    }\n\npublic:\n    Dinic() = default;\n \
    \   Dinic(u32 n, u32 m = 0u) \n        : n_{n}, m_{m}, g_(n), edges_{}, label_(n),\
    \ cur_(n) {\n        g_.shrink_to_fit();\n        label_.shrink_to_fit();\n  \
    \      cur_.shrink_to_fit();\n        edges_.reserve(m);\n    }\n\n    u32 addEdge(u32\
    \ u, u32 v, const Cap& cap) {\n        assert(u < size());\n        assert(v <\
    \ size());\n        u32 id{static_cast<u32>(g_[u].size())};\n        u32 revId{u\
    \ == v ? id + 1 : static_cast<u32>(g_[v].size())};\n        u32 res{static_cast<u32>(edges_.size())};\n\
    \        edges_.emplace_back(u, id);\n        g_[u].emplace_back(v, revId, cap);\n\
    \        g_[v].emplace_back(u, id, Cap{});\n        m_++;\n        return res;\n\
    \    }\n\n    const Cap& flowed(u32 id) const noexcept {\n        assert(id <\
    \ edgeNumber());\n        return reverse(id).residual;\n    }\n    const Cap&\
    \ residual(u32 id) const noexcept {\n        assert(id < edgeNumber());\n    \
    \    return edge(id).residual;\n    }\n    const Cap& capacity(u32 id) const noexcept\
    \ {\n        assert(id < edgeNumber());\n        return edge(id).residual + reverse(id).residual;\n\
    \    }\n    const u32& from(u32 id) const noexcept {\n        assert(id < edgeNumber());\n\
    \        return edges_[id].first();\n    }\n    const u32& to(u32 id) const noexcept\
    \ {\n        assert(id < edgeNumber());\n        return edge(id).to;\n    }\n\n\
    \    Cap flow(u32 s, u32 t) {\n        assert(s < size());\n        assert(t <\
    \ size()); \n        Cap res{};\n        while (dualStep(s, t)) {\n          \
    \  res += primalStep(s, t);\n        }\n        return res;\n    }\n\n    std::vector<bool>\
    \ cut(u32 s) {\n        std::vector<bool> res(size());\n        res[s] = true;\n\
    \        std::queue<u32> queue{ { s } };\n        while (queue.size()) {\n   \
    \         u32 v{queue.front()};\n            queue.pop();\n            for (const\
    \ auto& e : g_[v]) if (e.residual > 0 and !res[e.to]) {\n                res[e.to]\
    \ = true;\n                queue.emplace(e.to);\n            }\n        }\n  \
    \      return res;\n    }    \n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Utility/U32Pair.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include <type_traits>\n\
    #include <vector>\n#include <queue>\n\nnamespace zawa {\n\ntemplate <class Cap>\
    \ \nclass Dinic {\nprivate:\n    static_assert(std::is_signed_v<Cap>, \"Cap must\
    \ be signed\");\n    usize n_{}, m_{};\n    static constexpr u32 invalid() noexcept\
    \ {\n        return std::numeric_limits<u32>::max();\n    }\npublic:\n    inline\
    \ usize size() const noexcept {\n        return n_;\n    }\n    inline usize edgeNumber()\
    \ const noexcept {\n        return m_;\n    }\nprivate:\n    struct Edge {\n \
    \       u32 to{}, rev{};\n        Cap residual{};\n        Edge() = default;\n\
    \        Edge(u32 to, u32 rev, const Cap& residual) \n            : to{to}, rev{rev},\
    \ residual{residual} {}\n    };\n\n    std::vector<std::vector<Edge>> g_;\n  \
    \  std::vector<U32Pair> edges_;\n    std::vector<u32> label_, cur_;\n\n    bool\
    \ dualStep(u32 s, u32 t) {\n        std::fill(label_.begin(), label_.end(), invalid());\n\
    \        label_[s] = 0;\n        std::queue<u32> queue{ { s } };\n        while\
    \ (queue.size()) {\n            u32 v{queue.front()};\n            queue.pop();\n\
    \            for (const Edge& e : g_[v]) if (e.residual > 0) {\n             \
    \   if (label_[e.to] > label_[v] + 1) {\n                    label_[e.to] = label_[v]\
    \ + 1;\n                    if (e.to == t) return true;\n                    queue.emplace(e.to);\n\
    \                }\n            }\n        }\n        return false;\n    }\n\n\
    \    bool admissible(u32 v, const Edge& e) const noexcept {\n        return e.residual\
    \ > 0 and label_[v] + 1 == label_[e.to];\n    }\n\n    inline void flow(Edge&\
    \ e, Cap f) {\n        e.residual -= f;\n        g_[e.to][e.rev].residual += f;\n\
    \    }\n\n    Cap dfs(u32 v, u32 t, Cap up) {\n        if (v == t) return up;\n\
    \        Cap res{};\n        for (u32& i{cur_[v]} ; i < g_[v].size() ; i++) {\n\
    \            if (!admissible(v, g_[v][i])) continue;\n            Cap f{dfs(g_[v][i].to,\
    \ t, std::min(g_[v][i].residual, up - res))};\n            if (f == 0) continue;\n\
    \            flow(g_[v][i], f);\n            res += f;\n            if (res ==\
    \ up) return res;\n        }\n        return res;\n    }\n\n    Cap primalStep(u32\
    \ s, u32 t) {\n        std::fill(cur_.begin(), cur_.end(), 0u);\n        cur_[t]\
    \ = g_[t].size();\n        Cap res{};\n        while (true) {\n            Cap\
    \ f{dfs(s, t, std::numeric_limits<Cap>::max())};\n            if (f == 0) break;\n\
    \            res += f;\n        }\n        return res;\n    }\n\n    const Edge&\
    \ edge(u32 i) const noexcept {\n        return g_[edges_[i].first()][edges_[i].second()];\n\
    \    }\n    const Edge& reverse(u32 i) const noexcept {\n        const Edge& e{edge(i)};\n\
    \        return g_[e.to][e.rev];\n    }\n\npublic:\n    Dinic() = default;\n \
    \   Dinic(u32 n, u32 m = 0u) \n        : n_{n}, m_{m}, g_(n), edges_{}, label_(n),\
    \ cur_(n) {\n        g_.shrink_to_fit();\n        label_.shrink_to_fit();\n  \
    \      cur_.shrink_to_fit();\n        edges_.reserve(m);\n    }\n\n    u32 addEdge(u32\
    \ u, u32 v, const Cap& cap) {\n        assert(u < size());\n        assert(v <\
    \ size());\n        u32 id{static_cast<u32>(g_[u].size())};\n        u32 revId{u\
    \ == v ? id + 1 : static_cast<u32>(g_[v].size())};\n        u32 res{static_cast<u32>(edges_.size())};\n\
    \        edges_.emplace_back(u, id);\n        g_[u].emplace_back(v, revId, cap);\n\
    \        g_[v].emplace_back(u, id, Cap{});\n        m_++;\n        return res;\n\
    \    }\n\n    const Cap& flowed(u32 id) const noexcept {\n        assert(id <\
    \ edgeNumber());\n        return reverse(id).residual;\n    }\n    const Cap&\
    \ residual(u32 id) const noexcept {\n        assert(id < edgeNumber());\n    \
    \    return edge(id).residual;\n    }\n    const Cap& capacity(u32 id) const noexcept\
    \ {\n        assert(id < edgeNumber());\n        return edge(id).residual + reverse(id).residual;\n\
    \    }\n    const u32& from(u32 id) const noexcept {\n        assert(id < edgeNumber());\n\
    \        return edges_[id].first();\n    }\n    const u32& to(u32 id) const noexcept\
    \ {\n        assert(id < edgeNumber());\n        return edge(id).to;\n    }\n\n\
    \    Cap flow(u32 s, u32 t) {\n        assert(s < size());\n        assert(t <\
    \ size()); \n        Cap res{};\n        while (dualStep(s, t)) {\n          \
    \  res += primalStep(s, t);\n        }\n        return res;\n    }\n\n    std::vector<bool>\
    \ cut(u32 s) {\n        std::vector<bool> res(size());\n        res[s] = true;\n\
    \        std::queue<u32> queue{ { s } };\n        while (queue.size()) {\n   \
    \         u32 v{queue.front()};\n            queue.pop();\n            for (const\
    \ auto& e : g_[v]) if (e.residual > 0 and !res[e.to]) {\n                res[e.to]\
    \ = true;\n                queue.emplace(e.to);\n            }\n        }\n  \
    \      return res;\n    }    \n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Utility/U32Pair.hpp
  isVerificationFile: false
  path: Src/Graph/Flow/Dinic.hpp
  requiredBy:
  - Src/Graph/Flow/BurnBury.hpp
  timestamp: '2023-12-28 22:17:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/bipartitematching.test.cpp
  - Test/AOJ/3168.test.cpp
  - Test/AOJ/2943.test.cpp
  - Test/AOJ/GRL_7_A.test.cpp
  - Test/AOJ/GRL_6_A.test.cpp
  - Test/AOJ/2872.test.cpp
  - Test/AOJ/1163.test.cpp
  - Test/Manual/kupc2016_e.test.cpp
  - Test/Manual/typical90_by.test.cpp
  - Test/Manual/practice2_d.test.cpp
  - Test/Manual/typical90_an.test.cpp
  - Test/Manual/abc239_g.test.cpp
  - Test/Manual/abc317_g.test.cpp
  - Test/AtCoder/abc205_f.test.cpp
  - Test/AtCoder/abc193_f.test.cpp
  - Test/AtCoder/abc263_g.test.cpp
  - Test/AtCoder/abc318_g.test.cpp
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
u32 addEdge(u32 from, u32 to, const Cap& cap)
```

頂点`from`から頂点`to`へ向けて辺容量`cap`の辺を貼ります。返り値としてこの辺が何番目に追加された辺かを返します。


計算量: 定数時間

<br />

#### from

```cpp
u32 from(u32 id) const noexcept
```

`id`番目に(`addEdge`で)追加された辺の接続元の頂点番号を返します。

計算量: 定数時間

<br />

#### to

```cpp
u32 to(u32 id) const noexcept 
```

`id`番目に(`addEdge`で)追加された辺の接続先の頂点番号を返します。

計算量: 定数時間

<br />

#### residual

```cpp
u32 residual(u32 id) const noexcept
```

`id`番目に(`addEdge`で)追加された辺の残余容量を返します。

計算量: 定数時間

<br />

#### flowed

```cpp
u32 flowed(u32 id) const noexcept
```

`id`番目に(`addEdge`で)追加された辺に流れた水の量を返します。

計算量: 定数時間

<br />

#### originCap

```cpp
u32 originCap(u32 id) const noexcept
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

