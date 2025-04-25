---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/GRL_3_A.test.cpp
    title: Test/AOJ/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/GRL_3_B.test.cpp
    title: Test/AOJ/GRL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc334_g.test.cpp
    title: Test/AtCoder/abc334_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF923-F.test.cpp
    title: CF923(Div. 3)-F Microcycle
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Components/Lowlink.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Components/Lowlink.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ zawa {\n\nclass LowlinkResponse {\npublic:\n    LowlinkResponse() = default;\n\
    \n    LowlinkResponse(const std::vector<u32>& articulation, const std::vector<bool>&\
    \ bridge)\n        : articulation_{articulation}, bridge_{bridge} {}\n\n    inline\
    \ bool isArticulation(u32 v) const {\n        assert(v < articulation_.size());\n\
    \        return articulation_[v] > 1u;\n    }\n\n    inline u32 cut(u32 v) const\
    \ {\n        assert(v < articulation_.size());\n        return articulation_[v];\n\
    \    }\n\n    inline bool isBridge(u32 i) const {\n        assert(i < bridge_.size());\n\
    \        return bridge_[i];\n    }\n\nprivate:\n    std::vector<u32> articulation_;\n\
    \    std::vector<bool> bridge_;\n};\n\nclass Lowlink {\nprivate:\n    static constexpr\
    \ u32 INVALID{static_cast<u32>(-1)};\n    usize n_{}, m_{};\n    std::vector<std::vector<std::pair<u32,\
    \ u32>>> g_;\n    std::vector<std::pair<u32, u32>> e_;\n\n    void dfs(u32 v,\
    \ u32 p, u32& t, std::vector<u32>& articulation, \n            std::vector<bool>&\
    \ bridge, std::vector<u32>& in, std::vector<u32>& low) const {\n        low[v]\
    \ = in[v] = t++;\n        u32 deg{}; \n        for (const auto& [x, i] : g_[v])\
    \ {\n            if (in[x] == INVALID) {\n                deg++;\n           \
    \     dfs(x, v, t, articulation, bridge, in, low);\n                low[v] = std::min(low[v],\
    \ low[x]);\n                if (p != INVALID and low[x] >= in[v]) {\n        \
    \            articulation[v]++;\n                }\n                if (low[x]\
    \ > in[v]) {\n                    bridge[i] = true;\n                }\n     \
    \       }\n            else if (x != p) {\n                low[v] = std::min(low[v],\
    \ in[x]);\n            }\n        }\n        if (p == INVALID) {\n           \
    \ articulation[v] = deg;\n        }\n    }\n\npublic:\n    constexpr usize size()\
    \ const noexcept {\n        return n_;\n    }\n\n    constexpr usize edgeSize()\
    \ const noexcept {\n        return m_;\n    }\n\n    Lowlink() = default;\n\n\
    \    Lowlink(usize n) \n        : n_{n}, m_{}, g_(n) {\n        g_.shrink_to_fit();\n\
    \    }\n    \n    usize addEdge(u32 u, u32 v) {\n        usize res{m_++};\n  \
    \      e_.emplace_back(u, v);\n        g_[u].emplace_back(v, res);\n        g_[v].emplace_back(u,\
    \ res);\n        return res;\n    }\n\n    const std::vector<std::pair<u32, u32>>&\
    \ operator[](u32 v) const noexcept {\n        assert(v < size());\n        return\
    \ g_[v];\n    }\n    const std::pair<u32, u32>& edge(u32 i) const noexcept {\n\
    \        assert(i < edgeSize());\n        return e_[i];\n    }\n\n    LowlinkResponse\
    \ build() const {\n        u32 t{};\n        std::vector<u32> articulation(size(),\
    \ 1u), in(size(), INVALID), low(size());\n        std::vector<bool> bridge(edgeSize());\n\
    \        for (u32 v{} ; v < size() ; v++) if (in[v] == INVALID) {\n          \
    \  dfs(v, INVALID, t, articulation, bridge, in, low);\n        }\n        return\
    \ LowlinkResponse{ articulation, bridge };\n    }\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace zawa {\n\
    \nclass LowlinkResponse {\npublic:\n    LowlinkResponse() = default;\n\n    LowlinkResponse(const\
    \ std::vector<u32>& articulation, const std::vector<bool>& bridge)\n        :\
    \ articulation_{articulation}, bridge_{bridge} {}\n\n    inline bool isArticulation(u32\
    \ v) const {\n        assert(v < articulation_.size());\n        return articulation_[v]\
    \ > 1u;\n    }\n\n    inline u32 cut(u32 v) const {\n        assert(v < articulation_.size());\n\
    \        return articulation_[v];\n    }\n\n    inline bool isBridge(u32 i) const\
    \ {\n        assert(i < bridge_.size());\n        return bridge_[i];\n    }\n\n\
    private:\n    std::vector<u32> articulation_;\n    std::vector<bool> bridge_;\n\
    };\n\nclass Lowlink {\nprivate:\n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n\
    \    usize n_{}, m_{};\n    std::vector<std::vector<std::pair<u32, u32>>> g_;\n\
    \    std::vector<std::pair<u32, u32>> e_;\n\n    void dfs(u32 v, u32 p, u32& t,\
    \ std::vector<u32>& articulation, \n            std::vector<bool>& bridge, std::vector<u32>&\
    \ in, std::vector<u32>& low) const {\n        low[v] = in[v] = t++;\n        u32\
    \ deg{}; \n        for (const auto& [x, i] : g_[v]) {\n            if (in[x] ==\
    \ INVALID) {\n                deg++;\n                dfs(x, v, t, articulation,\
    \ bridge, in, low);\n                low[v] = std::min(low[v], low[x]);\n    \
    \            if (p != INVALID and low[x] >= in[v]) {\n                    articulation[v]++;\n\
    \                }\n                if (low[x] > in[v]) {\n                  \
    \  bridge[i] = true;\n                }\n            }\n            else if (x\
    \ != p) {\n                low[v] = std::min(low[v], in[x]);\n            }\n\
    \        }\n        if (p == INVALID) {\n            articulation[v] = deg;\n\
    \        }\n    }\n\npublic:\n    constexpr usize size() const noexcept {\n  \
    \      return n_;\n    }\n\n    constexpr usize edgeSize() const noexcept {\n\
    \        return m_;\n    }\n\n    Lowlink() = default;\n\n    Lowlink(usize n)\
    \ \n        : n_{n}, m_{}, g_(n) {\n        g_.shrink_to_fit();\n    }\n    \n\
    \    usize addEdge(u32 u, u32 v) {\n        usize res{m_++};\n        e_.emplace_back(u,\
    \ v);\n        g_[u].emplace_back(v, res);\n        g_[v].emplace_back(u, res);\n\
    \        return res;\n    }\n\n    const std::vector<std::pair<u32, u32>>& operator[](u32\
    \ v) const noexcept {\n        assert(v < size());\n        return g_[v];\n  \
    \  }\n    const std::pair<u32, u32>& edge(u32 i) const noexcept {\n        assert(i\
    \ < edgeSize());\n        return e_[i];\n    }\n\n    LowlinkResponse build()\
    \ const {\n        u32 t{};\n        std::vector<u32> articulation(size(), 1u),\
    \ in(size(), INVALID), low(size());\n        std::vector<bool> bridge(edgeSize());\n\
    \        for (u32 v{} ; v < size() ; v++) if (in[v] == INVALID) {\n          \
    \  dfs(v, INVALID, t, articulation, bridge, in, low);\n        }\n        return\
    \ LowlinkResponse{ articulation, bridge };\n    }\n\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Components/Lowlink.hpp
  requiredBy: []
  timestamp: '2024-06-30 15:57:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/GRL_3_B.test.cpp
  - Test/AOJ/GRL_3_A.test.cpp
  - Test/CF/CF923-F.test.cpp
  - Test/AtCoder/abc334_g.test.cpp
documentation_of: Src/Graph/Components/Lowlink.hpp
layout: document
title: "Lowlink (\u6A4B\u30FB\u95A2\u7BC0\u70B9)"
---

## 概要

与えられた無向グラフに対して各頂点が関節点か、各辺が橋かを判定します。

## ライブラリの使い方

#### コンストラクタ

```cpp
(1) Lowlink()
(2) Lowkink(u32 n)
```

(1) 使用を想定していない
(2) 頂点集合を $\\{ 0, 1, 2, \dots, n - 1 \\}$ で初期化する。

<br />

#### addEdge

```cpp
u32 addEdge(u32 u, u32 v)
```

辺 $\\{ u, v \\}$ を追加する。この辺が何番目(0-indexed)に追加された辺かを返す。

<br />

#### size

```cpp
constexpr usize size() const noexcept
```

頂点集合のサイズを返す。

<br />

#### edgeSize

```cpp
constexpr usize edgeSize() const noexcept
```

現在の辺集合のサイズを返す。

<br />


#### operator[]

```cpp
const std::vector<std::pair<u32, u32>>& operator[](u32 v) cnost noexcept
```

現在のグラフの頂点 $v$ と接続している辺のリストを返す。
- `first`が隣接している頂点
- `second`がその辺が何番目に`addEdge`によって追加されたかの番号(0-indexed)

<br />

#### edge

```cpp
const std::pair<u32, u32>& edge(u32 i) const noexcept
```

$i$ 番目(0-indexed)に`addEdge`によって追加された辺を返す。

<br />

以降のメンバは`build()`を呼んだ後に呼ばれることが想定されている。

#### build

```cpp
LowlinkResponse build() const
```

現在のグラフで橋・関節点を列挙する。

**計算量**: $O(|V| + |E|)$

#### LowlinkResponse

#### isArticulation

```cpp
inline bool isArticulation(u32 v) const 
```

頂点 $v$ が関節点かどうかを判定する。

#### isBridge

```cpp
inline bool isBridge(u32 i) const
```

$i$ 番目の辺が橋かどうか判定する。


#### cut

```cpp
inline u32 cut(u32 v) const
```

頂点 $v$ と $v$ を端点に持つ辺を削除したとき、グラフが何個の連結成分に分かれるかを返す。

<br />

## 参考

T.コメルン, C.ライザーソン, R.リベスト, C.シュタイン, アルゴリズムイントロダクション第３版 第2巻 第22章
