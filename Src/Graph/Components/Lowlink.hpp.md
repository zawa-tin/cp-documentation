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
    \ zawa {\n\nclass Lowlink {\nprivate:\n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n\
    \    usize n_{}, m_{};\n    std::vector<std::vector<std::pair<u32, u32>>> g_;\n\
    \    std::vector<std::pair<u32, u32>> e_;\n    std::vector<u32> in_, low_;\n \
    \   std::vector<u32> articulation_;\n    std::vector<bool> bridge_;\n\n    void\
    \ dfs(u32 v, u32 p, u32& t) {\n        low_[v] = in_[v] = t++;\n        u32 deg{};\
    \ \n        for (const auto& [x, i] : g_[v]) {\n            if (in_[x] == INVALID)\
    \ {\n                deg++;\n                dfs(x, v, t);\n                low_[v]\
    \ = std::min(low_[v], low_[x]);\n                if (p != INVALID and low_[x]\
    \ >= in_[v]) {\n                    articulation_[v]++;\n                }\n \
    \               if (low_[x] > in_[v]) {\n                    bridge_[i] = true;\n\
    \                }\n            }\n            else if (x != p) {\n          \
    \      low_[v] = std::min(low_[v], in_[x]);\n            }\n        }\n      \
    \  if (p == INVALID) {\n            articulation_[v] = deg;\n        }\n    }\n\
    \npublic:\n    constexpr usize size() const noexcept {\n        return n_;\n \
    \   }\n    constexpr usize edgeSize() const noexcept {\n        return m_;\n \
    \   }\n\n    Lowlink() = default;\n    Lowlink(usize n) \n        : n_{n}, m_{},\
    \ g_(n), in_(n, INVALID), low_(n), articulation_(n, u32{1}), bridge_{} {\n   \
    \     g_.shrink_to_fit();\n        in_.shrink_to_fit();\n        low_.shrink_to_fit();\n\
    \        articulation_.shrink_to_fit();\n    }\n    \n    usize addEdge(u32 u,\
    \ u32 v) {\n        usize res{m_++};\n        e_.emplace_back(u, v);\n       \
    \ g_[u].emplace_back(v, res);\n        g_[v].emplace_back(u, res);\n        return\
    \ res;\n    }\n\n    const std::vector<std::pair<u32, u32>>& operator[](u32 v)\
    \ const noexcept {\n        assert(v < size());\n        return g_[v];\n    }\n\
    \    const std::pair<u32, u32>& edge(u32 i) const noexcept {\n        assert(i\
    \ < edgeSize());\n        return e_[i];\n    }\n\n    void build() {\n       \
    \ bridge_.resize(edgeSize());\n        u32 t{};\n        for (u32 v{} ; v < size()\
    \ ; v++) if (in_[v] == INVALID) {\n            dfs(v, INVALID, t);\n        }\n\
    \    }\n\n    bool articular(u32 v) const noexcept {\n        assert(v < size());\n\
    \        return articulation_[v] > 1u;\n    }\n    u32 cut(u32 v) const noexcept\
    \ {\n        assert(v < size());\n        return articulation_[v];\n    }\n  \
    \  bool bridge(u32 i) const noexcept {\n        assert(i < edgeSize());\n    \
    \    return bridge_[i];\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace zawa {\n\
    \nclass Lowlink {\nprivate:\n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n\
    \    usize n_{}, m_{};\n    std::vector<std::vector<std::pair<u32, u32>>> g_;\n\
    \    std::vector<std::pair<u32, u32>> e_;\n    std::vector<u32> in_, low_;\n \
    \   std::vector<u32> articulation_;\n    std::vector<bool> bridge_;\n\n    void\
    \ dfs(u32 v, u32 p, u32& t) {\n        low_[v] = in_[v] = t++;\n        u32 deg{};\
    \ \n        for (const auto& [x, i] : g_[v]) {\n            if (in_[x] == INVALID)\
    \ {\n                deg++;\n                dfs(x, v, t);\n                low_[v]\
    \ = std::min(low_[v], low_[x]);\n                if (p != INVALID and low_[x]\
    \ >= in_[v]) {\n                    articulation_[v]++;\n                }\n \
    \               if (low_[x] > in_[v]) {\n                    bridge_[i] = true;\n\
    \                }\n            }\n            else if (x != p) {\n          \
    \      low_[v] = std::min(low_[v], in_[x]);\n            }\n        }\n      \
    \  if (p == INVALID) {\n            articulation_[v] = deg;\n        }\n    }\n\
    \npublic:\n    constexpr usize size() const noexcept {\n        return n_;\n \
    \   }\n    constexpr usize edgeSize() const noexcept {\n        return m_;\n \
    \   }\n\n    Lowlink() = default;\n    Lowlink(usize n) \n        : n_{n}, m_{},\
    \ g_(n), in_(n, INVALID), low_(n), articulation_(n, u32{1}), bridge_{} {\n   \
    \     g_.shrink_to_fit();\n        in_.shrink_to_fit();\n        low_.shrink_to_fit();\n\
    \        articulation_.shrink_to_fit();\n    }\n    \n    usize addEdge(u32 u,\
    \ u32 v) {\n        usize res{m_++};\n        e_.emplace_back(u, v);\n       \
    \ g_[u].emplace_back(v, res);\n        g_[v].emplace_back(u, res);\n        return\
    \ res;\n    }\n\n    const std::vector<std::pair<u32, u32>>& operator[](u32 v)\
    \ const noexcept {\n        assert(v < size());\n        return g_[v];\n    }\n\
    \    const std::pair<u32, u32>& edge(u32 i) const noexcept {\n        assert(i\
    \ < edgeSize());\n        return e_[i];\n    }\n\n    void build() {\n       \
    \ bridge_.resize(edgeSize());\n        u32 t{};\n        for (u32 v{} ; v < size()\
    \ ; v++) if (in_[v] == INVALID) {\n            dfs(v, INVALID, t);\n        }\n\
    \    }\n\n    bool articular(u32 v) const noexcept {\n        assert(v < size());\n\
    \        return articulation_[v] > 1u;\n    }\n    u32 cut(u32 v) const noexcept\
    \ {\n        assert(v < size());\n        return articulation_[v];\n    }\n  \
    \  bool bridge(u32 i) const noexcept {\n        assert(i < edgeSize());\n    \
    \    return bridge_[i];\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Components/Lowlink.hpp
  requiredBy: []
  timestamp: '2024-02-10 12:22:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/CF923-F.test.cpp
  - Test/AtCoder/abc334_g.test.cpp
  - Test/AOJ/GRL_3_A.test.cpp
  - Test/AOJ/GRL_3_B.test.cpp
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

#### build

```cpp
void build()
```

現在のグラフで橋・関節点を列挙する。

(このメンバを複数回呼ぶことを想定していないことに注意)

**計算量**: $O(|V| + |E|)$

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

#### articular

```cpp
bool articular(u32 v) const noexcept
```

$v$ が関節点なら`true`を、そうでないなら`false`を返す。

**計算量**: $O(1)$

<br />

#### cut

```cpp
u32 cut(u32 v) const noexcept
```

頂点 $v$ をグラフから取り除いた時、 もともと $v$ を含んでいた連結成分が何個の連結成分に分かれるかを返す。
- $v$ が関節点で無い場合は $1$ である。

**計算量**: $O(1)$

<br />

#### bridge

```cpp
bool bridge(u32 i) const noexcept
```

$i$ 番目に追加された辺が橋なら`true`をそうでないなら`false`を返す。

<br />

## 参考

T.コメルン, C.ライザーソン, R.リベスト, C.シュタイン, アルゴリズムイントロダクション第３版 第2巻 第22章
