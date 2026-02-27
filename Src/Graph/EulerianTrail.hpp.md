---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF1026-E.test.cpp
    title: Test/CF/CF1026-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/eulerian_trail_directed.test.cpp
    title: Test/LC/eulerian_trail_directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/eulerian_trail_undirected.test.cpp
    title: Test/LC/eulerian_trail_undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/UC/4-17-K.test.cpp
    title: Test/UC/4-17-K.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/EulerianTrail.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <optional>\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 10 \"Src/Graph/EulerianTrail.hpp\"\
    \n\nnamespace zawa {\n\n// first: vertices, second: edge id\ntemplate <class T>\n\
    std::optional<std::pair<std::vector<T>, std::vector<usize>>> EulerianTrail(T n,\
    \ const std::vector<std::pair<T, T>>& edges, bool directed, T start = -1) {\n\
    \    if (start != static_cast<T>(-1))\n        assert(start < n);\n    std::vector<std::vector<std::pair<T,\
    \ usize>>> g(n);\n    for (usize i = 0 ; auto [u, v] : edges) {\n        assert(u\
    \ < n and v < n);\n        g[u].push_back({v, i});\n        if (!directed) \n\
    \            g[v].push_back({u, i});\n        i++;\n    }\n    T st = edges.empty()\
    \ ? T{0} : edges[0].first, go = st;\n    if (directed) {\n        std::vector<i32>\
    \ deg(n);\n        for (auto [u, v] : edges) {\n            deg[u]++;\n      \
    \      deg[v]--;\n        }\n        bool fnst = false, fngo = false;\n      \
    \  for (T i = 0 ; i < n ; i++) {\n            if (deg[i] == 1) {\n           \
    \     if (fnst) \n                    return std::nullopt;\n                fnst\
    \ = true;\n                st = i;\n            }\n            else if (deg[i]\
    \ == -1) {\n                if (fngo) \n                    return std::nullopt;\n\
    \                fngo = true;\n                go = i;\n            }\n      \
    \      else if (deg[i]) \n                return std::nullopt;\n        }\n  \
    \      if (start != static_cast<T>(-1)) {\n            if (fnst and st != start)\n\
    \                return std::nullopt;\n            if (!fnst)\n              \
    \  st = go = start;\n        }\n    }\n    else {\n        usize cntOdd = 0;\n\
    \        for (T i = 0 ; i < n ; i++) \n            if (g[i].size() & 1)\n    \
    \            (cntOdd++ ? go : st) = i;\n        if (cntOdd != 0 and cntOdd !=\
    \ 2) \n            return std::nullopt;\n        if (start != static_cast<T>(-1))\
    \ {\n            if (cntOdd == 0)\n                st = go = start;\n        \
    \    else if (go == start)\n                std::swap(st,go);\n            else\
    \ if (st != start)\n                return std::nullopt;\n        }\n    }\n \
    \   std::vector<bool> used(edges.size());\n    std::vector<usize> cur(n), es;\n\
    \    std::vector<T> vs;\n    auto dfs = [&](auto dfs, const T v) -> void {\n \
    \       while (cur[v] < g[v].size()) {\n            auto [x, i] = g[v][cur[v]++];\n\
    \            if (!used[i]) {\n                used[i] = true;\n              \
    \  dfs(dfs, x);\n                es.push_back(i);\n                vs.push_back(v);\n\
    \            }\n        }\n    };\n    dfs(dfs, st);\n    std::ranges::reverse(vs);\n\
    \    vs.push_back(go);\n    std::ranges::reverse(es);\n    if (edges.size() !=\
    \ es.size()) \n        return std::nullopt;\n    return std::make_pair(vs, es);\n\
    }\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <optional>\n\
    #include <utility>\n#include <vector>\n\n#include \"../Template/TypeAlias.hpp\"\
    \n\nnamespace zawa {\n\n// first: vertices, second: edge id\ntemplate <class T>\n\
    std::optional<std::pair<std::vector<T>, std::vector<usize>>> EulerianTrail(T n,\
    \ const std::vector<std::pair<T, T>>& edges, bool directed, T start = -1) {\n\
    \    if (start != static_cast<T>(-1))\n        assert(start < n);\n    std::vector<std::vector<std::pair<T,\
    \ usize>>> g(n);\n    for (usize i = 0 ; auto [u, v] : edges) {\n        assert(u\
    \ < n and v < n);\n        g[u].push_back({v, i});\n        if (!directed) \n\
    \            g[v].push_back({u, i});\n        i++;\n    }\n    T st = edges.empty()\
    \ ? T{0} : edges[0].first, go = st;\n    if (directed) {\n        std::vector<i32>\
    \ deg(n);\n        for (auto [u, v] : edges) {\n            deg[u]++;\n      \
    \      deg[v]--;\n        }\n        bool fnst = false, fngo = false;\n      \
    \  for (T i = 0 ; i < n ; i++) {\n            if (deg[i] == 1) {\n           \
    \     if (fnst) \n                    return std::nullopt;\n                fnst\
    \ = true;\n                st = i;\n            }\n            else if (deg[i]\
    \ == -1) {\n                if (fngo) \n                    return std::nullopt;\n\
    \                fngo = true;\n                go = i;\n            }\n      \
    \      else if (deg[i]) \n                return std::nullopt;\n        }\n  \
    \      if (start != static_cast<T>(-1)) {\n            if (fnst and st != start)\n\
    \                return std::nullopt;\n            if (!fnst)\n              \
    \  st = go = start;\n        }\n    }\n    else {\n        usize cntOdd = 0;\n\
    \        for (T i = 0 ; i < n ; i++) \n            if (g[i].size() & 1)\n    \
    \            (cntOdd++ ? go : st) = i;\n        if (cntOdd != 0 and cntOdd !=\
    \ 2) \n            return std::nullopt;\n        if (start != static_cast<T>(-1))\
    \ {\n            if (cntOdd == 0)\n                st = go = start;\n        \
    \    else if (go == start)\n                std::swap(st,go);\n            else\
    \ if (st != start)\n                return std::nullopt;\n        }\n    }\n \
    \   std::vector<bool> used(edges.size());\n    std::vector<usize> cur(n), es;\n\
    \    std::vector<T> vs;\n    auto dfs = [&](auto dfs, const T v) -> void {\n \
    \       while (cur[v] < g[v].size()) {\n            auto [x, i] = g[v][cur[v]++];\n\
    \            if (!used[i]) {\n                used[i] = true;\n              \
    \  dfs(dfs, x);\n                es.push_back(i);\n                vs.push_back(v);\n\
    \            }\n        }\n    };\n    dfs(dfs, st);\n    std::ranges::reverse(vs);\n\
    \    vs.push_back(go);\n    std::ranges::reverse(es);\n    if (edges.size() !=\
    \ es.size()) \n        return std::nullopt;\n    return std::make_pair(vs, es);\n\
    }\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/EulerianTrail.hpp
  requiredBy: []
  timestamp: '2026-02-22 16:34:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/eulerian_trail_directed.test.cpp
  - Test/LC/eulerian_trail_undirected.test.cpp
  - Test/UC/4-17-K.test.cpp
  - Test/CF/CF1026-E.test.cpp
documentation_of: Src/Graph/EulerianTrail.hpp
layout: document
title: "Eulerian Trail (\u30AA\u30A4\u30E9\u30FC\u8DEF)"
---

## 概要

オイラー路が存在するなら構築する。オイラー路とは全ての辺を丁度一回ずつ通るようなtrailを指す。

無向グラフ $(V, E)$ において以下の条件を満たすとき、またそのときに限りオイラー路が存在する。

1. 次数 $0$ の頂点を削除したとき、連結である
2. 次数が奇数の頂点が丁度二つ、またはひとつも存在しない

特に条件2で後者を満たすとき、オイラー路の始点と終点が一致する。

有向グラフ $(V, E)$ において以下の条件を満たすとき、またそのときに限りオイラー路が存在する。

1. 次数 $0$ の頂点を削除したとき、連結である
2. 以下のいずれか片方を満たす(両方を同時に満たすことはありえない)

    - 入次数-出次数=1である頂点がちょうど一つ、-1である頂点がちょうど一つ、残りの頂点は0である
    - 全ての頂点について入次数と出次数が等しい

## ライブラリの使い方

```cpp
temlplate <class T>
std::optional<std::pair<std::vector<T>, std::vector<usize>>> EulerianTrail(T n, const std::vector<std::pair<T, T>>& edges, bool directed, T start = -1)
```

`n`は頂点数、`edges`は辺の列、`directed`は有向グラフなら`true`、無向グラフなら`false`を入れる。

`start`は始点を固定する。たとえグラフがオイラーグラフであったとしても、`start`を始点としたオイラー路が無ければ`std::nullopt`を返す。

返り値が`std::nullopt`のとき、入力に対してオイラー路は存在しない。

`first`にはオイラー路の頂点列、`second`には辺番号の列が順に入っている。
