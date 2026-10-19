---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/0465.test.cpp
    title: Test/AOJ/0465.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/0478.test.cpp
    title: Test/AOJ/0478.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2450.test.cpp
    title: Test/AOJ/2450.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2559.test.cpp
    title: Test/AOJ/2559.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc298_h.test.cpp
    title: Test/AtCoder/abc298_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc479_e.test.cpp
    title: Test/AtCoder/abc479_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/jump_on_tree.test.cpp
    title: Test/LC/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/lca/HeavyLightDecomposition.test.cpp
    title: Test/LC/lca/HeavyLightDecomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_add_path_sum.test.cpp
    title: Test/LC/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/3189.test.cpp
    title: Test/yukicoder/3189.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\n\n#line 2\
    \ \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\n\
    namespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <concepts>\n#include <cmath>\n\
    #include <limits>\n#include <optional>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <std::integral V>\nclass HeavyLightDecomposition\
    \ {\npublic:\n\n    HeavyLightDecomposition() = default;\n\n    HeavyLightDecomposition(std::vector<std::vector<V>>\
    \ T, V root = 0u) \n        : m_n{T.size()}, m_par(m_n), m_top(m_n), m_idx(m_n),\
    \ m_out(m_n),\n        m_inv(m_n), m_bottom(m_n),  m_size(m_n, usize{1}), m_dep(m_n)\
    \ {\n\n            auto dfs1 = [&](auto dfs, V v, V p, usize d) -> usize {\n \
    \               m_par[v] = p;\n                m_dep[v] = d;\n               \
    \ if (p != INVALID) {\n                    for (usize i = 0 ; i + 1 < T[v].size()\
    \ ; i++) \n                        if (T[v][i] == p) {\n                     \
    \       std::swap(T[v][i], T[v].back());\n                            break;\n\
    \                        }\n                    assert(T[v].back() == p);\n  \
    \                  T[v].pop_back();\n                }\n                for (V\
    \ x : T[v])\n                    m_size[v] += dfs(dfs, x, v, d + 1);\n       \
    \         for (usize i = 1 ; i < T[v].size() ; i++) \n                    if (m_size[T[v][0]]\
    \ < m_size[T[v][i]])\n                        std::swap(T[v][0], T[v][i]);\n \
    \               return m_size[v];\n            };\n\n            auto dfs2 = [&](auto\
    \ dfs, V v, V idx, V top) -> V {\n                m_idx[v] = idx++;\n        \
    \        m_inv[m_idx[v]] = v;\n                m_top[v] = top;\n             \
    \   if (T[v].size()) {\n                    idx = dfs(dfs, T[v][0], idx, top);\n\
    \                    for (usize i = 1 ; i < T[v].size() ; i++)\n             \
    \           idx = dfs(dfs, T[v][i], idx, T[v][i]);\n                }\n      \
    \          return m_out[v] = idx;\n            };\n\n            dfs1(dfs1, root,\
    \ INVALID, 0u);\n            dfs2(dfs2, root, 0u, root);\n\n            for (usize\
    \ i = 0 ; i < m_n ; i++)\n                if (m_dep[m_bottom[m_top[i]]] < m_dep[i])\n\
    \                    m_bottom[m_top[i]] = i;\n        }\n\n    inline usize size()\
    \ const noexcept {\n        return m_n;\n    }\n\n    usize size(V v) const noexcept\
    \ {\n        assert(v < (V)size());\n        return m_size[v];\n    }\n\n    usize\
    \ depth(V v) const noexcept {\n        assert(v < (V)size());\n        return\
    \ m_dep[v];\n    }\n\n    V parent(V v) const noexcept {\n        assert(v < (V)size());\n\
    \        return m_par[v];\n    }\n\n    V index(V v) const noexcept {\n      \
    \  assert(v < (V)size());\n        return m_idx[v];\n    }\n\n    V operator[](V\
    \ v) const noexcept {\n        assert(v < (V)size());\n        return m_idx[v];\n\
    \    }\n\n    V top(V v) const noexcept {\n        assert(v < (V)size());\n  \
    \      return m_top[v];\n    }\n\n    V bottom(V v) const noexcept {\n       \
    \ assert(v < (V)size());\n        return m_bottom[m_top[v]];\n    }\n\n    std::pair<V,\
    \ V> heavyPath(V v) const {\n        assert(v < (V)size());\n        return {top(v),\
    \ bottom(v)};\n    }\n\n    std::vector<std::pair<V, V>> decomp(V s, V t) const\
    \ {\n        assert(s < (V)size());\n        assert(t < (V)size());\n        std::vector<std::pair<V,\
    \ V>> res, ser;\n        while (m_top[s] != m_top[t]) {\n            if (m_dep[m_top[s]]\
    \ >= m_dep[m_top[t]]) {\n                res.emplace_back(s, m_top[s]);\n    \
    \            s = m_top[s];\n                if (m_par[s] != INVALID) s = m_par[s];\n\
    \            }\n            else {\n                ser.emplace_back(m_top[t],\
    \ t);\n                t = m_top[t];\n                if (m_par[t] != INVALID)\
    \ t = m_par[t];\n            }\n        }\n        res.emplace_back(s, t);\n \
    \       std::reverse(ser.begin(), ser.end());\n        res.insert(res.end(), ser.begin(),\
    \ ser.end()); \n        return res;\n    }\n\n    std::vector<std::pair<V, V>>\
    \ operator()(V s, V t) const {\n        return decomp(s, t);\n    }\n\n    //\
    \ first > second\u306E\u3068\u304D\u306F\u9006\u5411\u304D\u306E\u30D1\u30B9\n\
    \    // \u9006\u5411\u304D\u306B\u306A\u308B\u53EF\u80FD\u6027\u304C\u3042\u308B\
    \u90FD\u5408\u4E0A\u3001\u9589\u533A\u9593\u3067\u8FD4\u3055\u308C\u308B\u3002\
    \n    std::vector<std::pair<V,V>> pathQuery(V s, V t) const {\n        auto res\
    \ = decomp(s,t);\n        for (auto& [u,v] : res) {\n            u = m_idx[u];\n\
    \            v = m_idx[v];\n        }\n        return res;\n    }\n\n    std::pair<V,V>\
    \ subtreeQuery(V v) const {\n        assert(v < (V)size());\n        return {m_idx[v],m_out[v]};\n\
    \    }\n\n    V lca(V u, V v) const {\n        assert(u < (V)size());\n      \
    \  assert(v < (V)size());\n        while (m_top[u] != m_top[v]) {\n          \
    \  if (m_dep[m_top[u]] >= m_dep[m_top[v]]) {\n                u = m_top[u];\n\
    \                if (m_par[u] != INVALID) u = m_par[u];\n            }\n     \
    \       else {\n                v = m_top[v];\n                if (m_par[v] !=\
    \ INVALID) v = m_par[v];\n            }\n        }\n        return (m_dep[u] <=\
    \ m_dep[v] ? u : v);\n    }\n\n    // is p ancestor of v ?\n    bool isAncestor(V\
    \ v, V p) const {\n        assert(v < (V)size());\n        assert(p < (V)size());\n\
    \        return m_idx[p] <= m_idx[v] and m_out[v] <= m_out[p];\n    }\n\n    std::optional<V>\
    \ levelAncestor(V v, usize step) const {\n        assert(v < (V)size());\n   \
    \     if (step > m_dep[v]) return std::nullopt;\n        while (true) {\n    \
    \        usize dist{m_dep[v] - m_dep[m_top[v]]};\n            if (dist >= step)\
    \ break;\n            step -= dist + 1;\n            v = m_par[m_top[v]];\n  \
    \      }\n        step = (m_dep[v] - m_dep[m_top[v]]) - step;\n        return\
    \ m_inv[m_idx[m_top[v]] + step];\n    }\n\n    std::optional<V> jump(V s, V t,\
    \ usize step) const {\n        assert(s < (V)size());\n        assert(t < (V)size());\n\
    \        V uu{INVALID}, vv{INVALID};\n        usize d{};\n        for (auto [u,\
    \ v] : decomp(s, t)) {\n            usize dist{std::max(m_dep[u], m_dep[v]) -\
    \ std::min(m_dep[u], m_dep[v])};\n            if (dist >= step) {\n          \
    \      uu = u;\n                vv = v;\n                d = dist;\n         \
    \       break;\n            }\n            step -= dist + 1;\n        }\n    \
    \    if (uu == INVALID) \n            return std::nullopt;\n        if (m_dep[uu]\
    \ <= m_dep[vv])\n            return m_inv[m_idx[uu] + step];\n        else\n \
    \           return m_inv[m_idx[vv] + (d - step)];\n    }\n\n    usize distance(V\
    \ s, V t) const {\n        assert(s < (V)size());\n        assert(t < (V)size());\n\
    \        usize res{};\n        for (auto [u, v] : decomp(s, t)) {\n          \
    \  if (m_dep[u] > m_dep[v]) std::swap(u, v);\n            res += m_dep[v] - m_dep[u]\
    \ + 1;\n        }\n        return --res;\n    }\n\nprivate:\n\n    static constexpr\
    \ V INVALID{static_cast<V>(-1)};\n\n    usize m_n{};\n\n    std::vector<V> m_par{},\
    \ m_top{}, m_idx{}, m_out{}, m_inv{}, m_bottom{};\n\n    std::vector<usize> m_size{},\
    \ m_dep{};\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <concepts>\n#include <cmath>\n#include <limits>\n\
    #include <optional>\n#include <utility>\n#include <vector>\n\nnamespace zawa {\n\
    \ntemplate <std::integral V>\nclass HeavyLightDecomposition {\npublic:\n\n   \
    \ HeavyLightDecomposition() = default;\n\n    HeavyLightDecomposition(std::vector<std::vector<V>>\
    \ T, V root = 0u) \n        : m_n{T.size()}, m_par(m_n), m_top(m_n), m_idx(m_n),\
    \ m_out(m_n),\n        m_inv(m_n), m_bottom(m_n),  m_size(m_n, usize{1}), m_dep(m_n)\
    \ {\n\n            auto dfs1 = [&](auto dfs, V v, V p, usize d) -> usize {\n \
    \               m_par[v] = p;\n                m_dep[v] = d;\n               \
    \ if (p != INVALID) {\n                    for (usize i = 0 ; i + 1 < T[v].size()\
    \ ; i++) \n                        if (T[v][i] == p) {\n                     \
    \       std::swap(T[v][i], T[v].back());\n                            break;\n\
    \                        }\n                    assert(T[v].back() == p);\n  \
    \                  T[v].pop_back();\n                }\n                for (V\
    \ x : T[v])\n                    m_size[v] += dfs(dfs, x, v, d + 1);\n       \
    \         for (usize i = 1 ; i < T[v].size() ; i++) \n                    if (m_size[T[v][0]]\
    \ < m_size[T[v][i]])\n                        std::swap(T[v][0], T[v][i]);\n \
    \               return m_size[v];\n            };\n\n            auto dfs2 = [&](auto\
    \ dfs, V v, V idx, V top) -> V {\n                m_idx[v] = idx++;\n        \
    \        m_inv[m_idx[v]] = v;\n                m_top[v] = top;\n             \
    \   if (T[v].size()) {\n                    idx = dfs(dfs, T[v][0], idx, top);\n\
    \                    for (usize i = 1 ; i < T[v].size() ; i++)\n             \
    \           idx = dfs(dfs, T[v][i], idx, T[v][i]);\n                }\n      \
    \          return m_out[v] = idx;\n            };\n\n            dfs1(dfs1, root,\
    \ INVALID, 0u);\n            dfs2(dfs2, root, 0u, root);\n\n            for (usize\
    \ i = 0 ; i < m_n ; i++)\n                if (m_dep[m_bottom[m_top[i]]] < m_dep[i])\n\
    \                    m_bottom[m_top[i]] = i;\n        }\n\n    inline usize size()\
    \ const noexcept {\n        return m_n;\n    }\n\n    usize size(V v) const noexcept\
    \ {\n        assert(v < (V)size());\n        return m_size[v];\n    }\n\n    usize\
    \ depth(V v) const noexcept {\n        assert(v < (V)size());\n        return\
    \ m_dep[v];\n    }\n\n    V parent(V v) const noexcept {\n        assert(v < (V)size());\n\
    \        return m_par[v];\n    }\n\n    V index(V v) const noexcept {\n      \
    \  assert(v < (V)size());\n        return m_idx[v];\n    }\n\n    V operator[](V\
    \ v) const noexcept {\n        assert(v < (V)size());\n        return m_idx[v];\n\
    \    }\n\n    V top(V v) const noexcept {\n        assert(v < (V)size());\n  \
    \      return m_top[v];\n    }\n\n    V bottom(V v) const noexcept {\n       \
    \ assert(v < (V)size());\n        return m_bottom[m_top[v]];\n    }\n\n    std::pair<V,\
    \ V> heavyPath(V v) const {\n        assert(v < (V)size());\n        return {top(v),\
    \ bottom(v)};\n    }\n\n    std::vector<std::pair<V, V>> decomp(V s, V t) const\
    \ {\n        assert(s < (V)size());\n        assert(t < (V)size());\n        std::vector<std::pair<V,\
    \ V>> res, ser;\n        while (m_top[s] != m_top[t]) {\n            if (m_dep[m_top[s]]\
    \ >= m_dep[m_top[t]]) {\n                res.emplace_back(s, m_top[s]);\n    \
    \            s = m_top[s];\n                if (m_par[s] != INVALID) s = m_par[s];\n\
    \            }\n            else {\n                ser.emplace_back(m_top[t],\
    \ t);\n                t = m_top[t];\n                if (m_par[t] != INVALID)\
    \ t = m_par[t];\n            }\n        }\n        res.emplace_back(s, t);\n \
    \       std::reverse(ser.begin(), ser.end());\n        res.insert(res.end(), ser.begin(),\
    \ ser.end()); \n        return res;\n    }\n\n    std::vector<std::pair<V, V>>\
    \ operator()(V s, V t) const {\n        return decomp(s, t);\n    }\n\n    //\
    \ first > second\u306E\u3068\u304D\u306F\u9006\u5411\u304D\u306E\u30D1\u30B9\n\
    \    // \u9006\u5411\u304D\u306B\u306A\u308B\u53EF\u80FD\u6027\u304C\u3042\u308B\
    \u90FD\u5408\u4E0A\u3001\u9589\u533A\u9593\u3067\u8FD4\u3055\u308C\u308B\u3002\
    \n    std::vector<std::pair<V,V>> pathQuery(V s, V t) const {\n        auto res\
    \ = decomp(s,t);\n        for (auto& [u,v] : res) {\n            u = m_idx[u];\n\
    \            v = m_idx[v];\n        }\n        return res;\n    }\n\n    std::pair<V,V>\
    \ subtreeQuery(V v) const {\n        assert(v < (V)size());\n        return {m_idx[v],m_out[v]};\n\
    \    }\n\n    V lca(V u, V v) const {\n        assert(u < (V)size());\n      \
    \  assert(v < (V)size());\n        while (m_top[u] != m_top[v]) {\n          \
    \  if (m_dep[m_top[u]] >= m_dep[m_top[v]]) {\n                u = m_top[u];\n\
    \                if (m_par[u] != INVALID) u = m_par[u];\n            }\n     \
    \       else {\n                v = m_top[v];\n                if (m_par[v] !=\
    \ INVALID) v = m_par[v];\n            }\n        }\n        return (m_dep[u] <=\
    \ m_dep[v] ? u : v);\n    }\n\n    // is p ancestor of v ?\n    bool isAncestor(V\
    \ v, V p) const {\n        assert(v < (V)size());\n        assert(p < (V)size());\n\
    \        return m_idx[p] <= m_idx[v] and m_out[v] <= m_out[p];\n    }\n\n    std::optional<V>\
    \ levelAncestor(V v, usize step) const {\n        assert(v < (V)size());\n   \
    \     if (step > m_dep[v]) return std::nullopt;\n        while (true) {\n    \
    \        usize dist{m_dep[v] - m_dep[m_top[v]]};\n            if (dist >= step)\
    \ break;\n            step -= dist + 1;\n            v = m_par[m_top[v]];\n  \
    \      }\n        step = (m_dep[v] - m_dep[m_top[v]]) - step;\n        return\
    \ m_inv[m_idx[m_top[v]] + step];\n    }\n\n    std::optional<V> jump(V s, V t,\
    \ usize step) const {\n        assert(s < (V)size());\n        assert(t < (V)size());\n\
    \        V uu{INVALID}, vv{INVALID};\n        usize d{};\n        for (auto [u,\
    \ v] : decomp(s, t)) {\n            usize dist{std::max(m_dep[u], m_dep[v]) -\
    \ std::min(m_dep[u], m_dep[v])};\n            if (dist >= step) {\n          \
    \      uu = u;\n                vv = v;\n                d = dist;\n         \
    \       break;\n            }\n            step -= dist + 1;\n        }\n    \
    \    if (uu == INVALID) \n            return std::nullopt;\n        if (m_dep[uu]\
    \ <= m_dep[vv])\n            return m_inv[m_idx[uu] + step];\n        else\n \
    \           return m_inv[m_idx[vv] + (d - step)];\n    }\n\n    usize distance(V\
    \ s, V t) const {\n        assert(s < (V)size());\n        assert(t < (V)size());\n\
    \        usize res{};\n        for (auto [u, v] : decomp(s, t)) {\n          \
    \  if (m_dep[u] > m_dep[v]) std::swap(u, v);\n            res += m_dep[v] - m_dep[u]\
    \ + 1;\n        }\n        return --res;\n    }\n\nprivate:\n\n    static constexpr\
    \ V INVALID{static_cast<V>(-1)};\n\n    usize m_n{};\n\n    std::vector<V> m_par{},\
    \ m_top{}, m_idx{}, m_out{}, m_inv{}, m_bottom{};\n\n    std::vector<usize> m_size{},\
    \ m_dep{};\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2026-10-16 19:43:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/0465.test.cpp
  - Test/AOJ/0478.test.cpp
  - Test/AOJ/2450.test.cpp
  - Test/AOJ/2559.test.cpp
  - Test/AtCoder/abc479_e.test.cpp
  - Test/AtCoder/abc298_h.test.cpp
  - Test/LC/vertex_add_path_sum.test.cpp
  - Test/LC/lca/HeavyLightDecomposition.test.cpp
  - Test/LC/jump_on_tree.test.cpp
  - Test/yukicoder/3189.test.cpp
documentation_of: Src/Graph/Tree/HeavyLightDecomposition.hpp
layout: document
title: Heavy Light Decomposition
---

## 概要

与えられた木上でHLD、オイラーツアーを行い、木の古典的な操作を大抵行えるように機能を提供する。

一方、重心、直径まわりの機能はオーバーヘッドを嫌って提供しないこととしている。

### テンプレート引数

```
template <std::integral V>
class HeavyLightDecomposition
```

`V`は`int`または`unsigned`であることが強く推奨される。例えば`V=std::uint8_t`であって頂点数 $N$ が $256$ の場合、`subtreeQuery`などがオーバーフローすることが確認できる。

### コンストラクタ

```
HeavyLightDecomposition(std::vector<std::vector<V>> T, V root = 0u)
```

`T`はグラフの隣接リストを指定する。`root`は根頂点に該当し、何も指定しなかった場合は頂点 $0$ が自動的に根となる。

- 隣接リストは**無向木**である必要がある

暗黙的に木の頂点数 $N$ は正であることが仮定されている。特に、空グラフは木ではないという木の定義に従っているため、この仮定は正当だと思われる。

### メンバ

```cpp
inline usize size() const noexcept
```

頂点数 $N$ を返す。 $O(1)$

```cpp
usize size(V v) const noexcept
```

部分木 $v$ の頂点数を返す。 $O(1)$

```cpp
usize depth(V v) const noexcept
```

$v$ の深さ。 $O(1)$

```cpp
V parent(V v) const noexcept
```

$v$ の親頂点を返す。 $v$ が根のときは`static_cast<V>(-1)`が返される。 $O(1)$

```cpp
V index(V v) const noexcept
V operator[](V v) const noexcept
```

$v$ がオイラーツアー上で何番目か？を返す。 $O(1)$

ただオイラーツアー上に並んでいるだけでなく、Heavy Pathの並び順にも対応している。具体的には任意のHeavy Path $v_1,v_2,\dots,v_k$ に対して、ある整数 $l(0\le l\le N-k)$ が存在して $\text{index}(v_i)=l+i-1$ となる。

```cpp
V top(V v) const noexcept
```

$v$ が属するHeavy Path上の頂点であって、最も深さが小さいものを返す。 $O(1)$

```cpp
V bottom(V v) const noexcept
```

$v$ が属するHeavy Path上の頂点であって、最も深さが大きいものを返す。 $O(1)$

```cpp
std::pair<V,V> heavyPath(V v) const
```

$v$ が属するHeavy Pathの両端点を返す。 $O(1)$

```cpp
std::vector<std::pair<V,V>> decomp(V s,V t) const
std::vector<std::pair<V,V>> operator()(V s,V t) const
```

$s-t$ パスをいくつかのHeavy Pathの区間に分割する。 $s$ に近い順から区間の両端点の頂点を返す。 $O(\log N)$

```cpp
std::vector<std::pair<V,V>> pathQuery(V s,V t) const
```

$s-t$ パスがオイラー上で対応する**閉区間**の集合を返す。`first>second`のときは逆向きのパスのaggregationが必要であることを指す。 $O(\log N)$

```cpp
std::pair<V,V> subtreeQuery(V v) const
```

$v$ のオイラーツアーによって対応された半開区間を返す。 $O(1)$

```cpp
V lca(V u,V v) const
```

$u,v$ のLCAを返す。 $O(\log N)$

```cpp
bool isAncestor(V v,V p) const
```

$p$ が $v$ の祖先に存在するなら`true`、そうでないなら`false`を返す。 $O(1)$

- Is $p$ an ancestor of $v$ ? という英文で引数の順番を覚えると良い

```cpp
std::optional<V> levelAncestor(V v,usize step) const
```

$v$ から $\text{step}$ 回親を辿ったときにいる頂点を返す。そのような頂点が存在しないときは `std::nullopt` が返される。 $O(\log N)$

```cpp
std::optional<V> jump(V s,V t,usize step) const
```

$s-t$ パスにおいて、 $s$ から $\text{step}$ 回辺を辿ったときにいる頂点を返す。そのような頂点が存在しないときは `std::nullopt` が返される。 $O(\log N)$

```cpp
usize distance(V s,V t) const
```

$s-t$ パスに含まれる辺の数を返す。 $O(\log N)$

## 更新履歴


- 2024/01/09: 初回実装。
- 2024/07/17: 実装を全面的に書き直した。`size(v)`、`depth`、`parent`、`index`、`decomp`、`isAncestor`、`levelAncestor`、`jump`、`distance`を整備し、ドキュメントを追加した。
- 2024/12/06: `Tree`への依存を廃止しテンプレート引数`V`による隣接リストをコンストラクタで受け取る形式に変更した。
- 2025/09/18: テンプレート引数を`std::integral`で制約した。`top`、`bottom`、`heavyPath`を追加した。
- 2026/01/01: `isAncestor`を`const`メンバ関数に変更した。
- 2026/02/23: `distance`が複数のHeavy Pathをまたぐ場合に辺数を正しく計算できない不具合を修正した。`levelAncestor`と`jump`の戻り値を`std::optional<V>`に変更した。
- 2026/03/27: パスに対応するオイラーツアー上の閉区間列を返す`pathQuery`を追加した。
- 2026/10/16: `subtreeQuery`を追加した。`isAncestor`を $O(1)$ に改善し、構築時に各部分木のオイラーツアー上の右端を記録するようにした。
