---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF316-D.test.cpp
    title: Test/CF/CF316-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/EC2-E.test.cpp
    title: Test/CF/EC2-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_add_subtree_sum.test.cpp
    title: Test/LC/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/Sack.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Tree/Sack.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\nclass Sack {\nprivate:\
    \    \n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n    usize n_{};\n\
    \    std::vector<std::vector<u32>> g_;\n    std::vector<u32> sz_, euler_, L_,\
    \ R_;\n\n    u32 dfsHLD(u32 v, u32 p) {\n        sz_[v] = 1;\n        usize m{g_[v].size()};\n\
    \        usize max{};\n        if (m > 1u and g_[v][0] == p) std::swap(g_[v][0],\
    \ g_[v][1]);\n        for (u32 i{} ; i < m ; i++) if (g_[v][i] != p) {\n     \
    \       sz_[v] += dfsHLD(g_[v][i], v);\n            if (max < sz_[g_[v][i]]) {\n\
    \                max = sz_[g_[v][i]];\n                if (i) std::swap(g_[v][0],\
    \ g_[v][i]);\n            }\n        }\n        return sz_[v];\n    }\n\n    void\
    \ dfsEuler(u32 v, u32 p, u32& t) {\n        euler_[t] = v;\n        L_[v] = t++;\n\
    \        for (auto x : g_[v]) if (x != p) {\n            dfsEuler(x, v, t);\n\
    \        }\n        R_[v] = t;\n    }\n\npublic:\n    constexpr usize size() const\
    \ noexcept {\n        return n_;\n    }\n\n    Sack() = default;\n    Sack(u32\
    \ n) \n        : n_{n}, g_(n), sz_(n), euler_(n), L_(n), R_(n) {\n        assert(n);\n\
    \        g_.shrink_to_fit();\n        sz_.shrink_to_fit();\n        euler_.shrink_to_fit();\n\
    \        L_.shrink_to_fit();\n        R_.shrink_to_fit();\n    }\n    void addEdge(u32\
    \ u, u32 v) {\n        assert(u < size());\n        assert(v < size());\n    \
    \    g_[u].emplace_back(v);\n        g_[v].emplace_back(u);\n    }\n\n    const\
    \ std::vector<u32>& operator[](u32 v) const noexcept {\n        assert(v < size());\n\
    \        return g_[v];\n    }\n\n    template <class ADD, class DEL, class QUERY,\
    \ class RESET>\n    u32 execute(u32 root, const ADD& add, const DEL& del, const\
    \ QUERY& query, const RESET& reset) {\n        dfsHLD(root, INVALID);\n      \
    \  u32 t{};\n        dfsEuler(root, INVALID, t);\n        \n        auto sack{[&](auto\
    \ dfs, u32 v, u32 p, bool keep) -> void {\n            usize m{g_[v].size()};\n\
    \            for (u32 i{1} ; i < m ; i++) if (g_[v][i] != p) {\n             \
    \   dfs(dfs, g_[v][i], v, false);\n            }\n            if (sz_[v] > 1u)\
    \ dfs(dfs, g_[v][0], v, true);\n            if (sz_[v] > 1u) {\n             \
    \   for (u32 i{R_[g_[v][0]]} ; i < R_[v] ; i++) {\n                    add(euler_[i]);\n\
    \                }\n            }\n            add(v);\n            query(v);\n\
    \            if (!keep) {\n                for (u32 i{L_[v]} ; i < R_[v] ; i++)\
    \ {\n                    del(euler_[i]);\n                }\n                reset();\n\
    \            }\n        }};\n        sack(sack, root, INVALID, false);\n\n   \
    \     return sz_[root];\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\nclass Sack {\nprivate:\
    \    \n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n    usize n_{};\n\
    \    std::vector<std::vector<u32>> g_;\n    std::vector<u32> sz_, euler_, L_,\
    \ R_;\n\n    u32 dfsHLD(u32 v, u32 p) {\n        sz_[v] = 1;\n        usize m{g_[v].size()};\n\
    \        usize max{};\n        if (m > 1u and g_[v][0] == p) std::swap(g_[v][0],\
    \ g_[v][1]);\n        for (u32 i{} ; i < m ; i++) if (g_[v][i] != p) {\n     \
    \       sz_[v] += dfsHLD(g_[v][i], v);\n            if (max < sz_[g_[v][i]]) {\n\
    \                max = sz_[g_[v][i]];\n                if (i) std::swap(g_[v][0],\
    \ g_[v][i]);\n            }\n        }\n        return sz_[v];\n    }\n\n    void\
    \ dfsEuler(u32 v, u32 p, u32& t) {\n        euler_[t] = v;\n        L_[v] = t++;\n\
    \        for (auto x : g_[v]) if (x != p) {\n            dfsEuler(x, v, t);\n\
    \        }\n        R_[v] = t;\n    }\n\npublic:\n    constexpr usize size() const\
    \ noexcept {\n        return n_;\n    }\n\n    Sack() = default;\n    Sack(u32\
    \ n) \n        : n_{n}, g_(n), sz_(n), euler_(n), L_(n), R_(n) {\n        assert(n);\n\
    \        g_.shrink_to_fit();\n        sz_.shrink_to_fit();\n        euler_.shrink_to_fit();\n\
    \        L_.shrink_to_fit();\n        R_.shrink_to_fit();\n    }\n    void addEdge(u32\
    \ u, u32 v) {\n        assert(u < size());\n        assert(v < size());\n    \
    \    g_[u].emplace_back(v);\n        g_[v].emplace_back(u);\n    }\n\n    const\
    \ std::vector<u32>& operator[](u32 v) const noexcept {\n        assert(v < size());\n\
    \        return g_[v];\n    }\n\n    template <class ADD, class DEL, class QUERY,\
    \ class RESET>\n    u32 execute(u32 root, const ADD& add, const DEL& del, const\
    \ QUERY& query, const RESET& reset) {\n        dfsHLD(root, INVALID);\n      \
    \  u32 t{};\n        dfsEuler(root, INVALID, t);\n        \n        auto sack{[&](auto\
    \ dfs, u32 v, u32 p, bool keep) -> void {\n            usize m{g_[v].size()};\n\
    \            for (u32 i{1} ; i < m ; i++) if (g_[v][i] != p) {\n             \
    \   dfs(dfs, g_[v][i], v, false);\n            }\n            if (sz_[v] > 1u)\
    \ dfs(dfs, g_[v][0], v, true);\n            if (sz_[v] > 1u) {\n             \
    \   for (u32 i{R_[g_[v][0]]} ; i < R_[v] ; i++) {\n                    add(euler_[i]);\n\
    \                }\n            }\n            add(v);\n            query(v);\n\
    \            if (!keep) {\n                for (u32 i{L_[v]} ; i < R_[v] ; i++)\
    \ {\n                    del(euler_[i]);\n                }\n                reset();\n\
    \            }\n        }};\n        sack(sack, root, INVALID, false);\n\n   \
    \     return sz_[root];\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/Sack.hpp
  requiredBy: []
  timestamp: '2024-02-11 01:31:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/CF316-D.test.cpp
  - Test/CF/EC2-E.test.cpp
  - Test/LC/vertex_add_subtree_sum.test.cpp
documentation_of: Src/Graph/Tree/Sack.hpp
layout: document
title: Sack
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
