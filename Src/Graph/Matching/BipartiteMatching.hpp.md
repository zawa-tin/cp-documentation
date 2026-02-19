---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/bipartitematching.test.cpp
    title: Test/LC/bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Matching/BipartiteMatching.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Graph/Matching/BipartiteMatching.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include <optional>\n\
    #include <vector>\n#include <ranges>\n\nnamespace zawa {\n\ntemplate <class V>\n\
    std::vector<std::pair<V,V>> BipartiteMatching(usize N, usize M, std::vector<std::pair<V,V>>\
    \ E) {\n    std::vector<std::vector<std::pair<V,usize>>> g(N+M);\n    for (usize\
    \ i = 0 ; i < E.size() ; i++) {\n        auto [u, v] = E[i];\n        assert(0\
    \ <= u and u < (V)N);\n        assert(0 <= v and v < (V)M);\n        g[u].push_back({N+v,i});\n\
    \        g[N+v].push_back({u,i});\n    }\n    std::vector<bool> free(N+M,1), used(E.size()),\
    \ cur(N+M);\n    std::vector<i32> dist(N+M,-1);\n    std::vector<V> match(N,(V)N),\
    \ que;\n    while (1) {\n        std::ranges::fill(dist,-1);\n        fill(cur.begin(),cur.end(),0);\n\
    \        que.clear();\n        for (usize i = 0 ; i < N ; i++)\n            if\
    \ (free[i]) {\n                que.push_back(i);\n                dist[i] = 0;\n\
    \            }\n        for (usize t = 0 ; t < que.size() ; t++) {\n         \
    \   const V v = que[t];\n            for (auto [x, i] : g[v]) {\n            \
    \    if (dist[x] != -1)\n                    continue;\n                if (v\
    \ < (V)N and used[i])\n                    continue;\n                if (v >=\
    \ (V)N and !used[i])\n                    continue;\n                dist[x] =\
    \ dist[v] + 1;\n                que.push_back(x);\n            }\n        }\n\
    \        const i32 minDist = [&]() {\n            i32 res = N + M;\n         \
    \   for (usize i = N ; i < N + M ; i++)\n                if (free[i] and dist[i]\
    \ != -1)\n                    res = std::min(res,dist[i]);\n            return\
    \ res;\n        }();\n        if ((usize)minDist == N + M)\n            break;\n\
    \        auto dfs = [&](auto dfs,V v) -> bool {\n            cur[v] = 1;\n   \
    \         if (v >= (V)N and free[v]) {\n                free[v] = 0;\n       \
    \         return 1;\n            }\n            if (dist[v] >= minDist)\n    \
    \            return 0;\n            for (auto [x, i] : g[v]) {\n             \
    \   if (cur[x])\n                    continue;\n                if (dist[v] +\
    \ 1 != dist[x])\n                    continue;\n                if (v < (V)N and\
    \ used[i])\n                    continue;\n                if (v >= (V)N and !used[i])\n\
    \                    continue;\n                if (dfs(dfs,x)) {\n          \
    \          free[v] = 0;\n                    used[i] = !used[i];\n           \
    \         return 1;\n                }\n            }\n            return 0;\n\
    \        };\n        for (usize i = 0 ; i < N ; i++)\n            if (free[i]\
    \ and !cur[i])\n                dfs(dfs,i);\n    }\n    std::vector<std::pair<V,V>>\
    \ res;\n    for (usize i = 0 ; i < E.size() ; i++)\n        if (used[i])\n   \
    \         res.push_back(E[i]);\n    return res;\n}\n\ntemplate <class V>\nstd::optional<std::vector<std::pair<V,V>>>\
    \ BipartiteMatching(usize N,std::vector<std::pair<usize,usize>> E) {\n    std::vector<std::vector<V>>\
    \ g(N); \n    for (auto [u, v] : E) {\n        assert(0 <= u and u < N);\n   \
    \     assert(0 <= v and v < N);\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n    std::vector<i32> col(N,-1);\n    auto dfs = [&](auto dfs,V v,i32 c)\
    \ -> bool {\n        col[v] = c;\n        for (V x : g[v]) {\n            if (col[x]\
    \ == -1 and !dfs(dfs,x,c^1))\n                return false;\n            else\
    \ if (col[v] == col[x])\n                return false;\n        }\n        return\
    \ true;\n    };\n    for (usize i = 0 ; i < N ; i++)\n        if (col[i] == -1)\n\
    \            if (!dfs(dfs,i,0))\n                return std::nullopt;\n    std::vector<V>\
    \ id(N), L, R;\n    for (usize i = 0 ; i < N ; i++)\n        (col[i] == 0 ? L\
    \ : R).push_back(i);\n    for (usize i = 0 ; i < L.size() ; i++)\n        id[L[i]]\
    \ = i;\n    for (usize i = 0 ; i < R.size() ; i++)\n        id[R[i]] = L.size()\
    \ + i;\n    for (auto& [u, v] : E) {\n        u = id[u];\n        v = id[v];\n\
    \        if (u >= L.size())\n            std::swap(u,v);\n        v -= L.size();\n\
    \    }\n    auto ans = BipartiteMatching(L.size(),R.size(),E);\n    for (auto&\
    \ [u, v] : ans) {\n        u = L[u];\n        v = R[v];\n    }\n    return ans;\n\
    }\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <optional>\n#include <vector>\n\
    #include <ranges>\n\nnamespace zawa {\n\ntemplate <class V>\nstd::vector<std::pair<V,V>>\
    \ BipartiteMatching(usize N, usize M, std::vector<std::pair<V,V>> E) {\n    std::vector<std::vector<std::pair<V,usize>>>\
    \ g(N+M);\n    for (usize i = 0 ; i < E.size() ; i++) {\n        auto [u, v] =\
    \ E[i];\n        assert(0 <= u and u < (V)N);\n        assert(0 <= v and v < (V)M);\n\
    \        g[u].push_back({N+v,i});\n        g[N+v].push_back({u,i});\n    }\n \
    \   std::vector<bool> free(N+M,1), used(E.size()), cur(N+M);\n    std::vector<i32>\
    \ dist(N+M,-1);\n    std::vector<V> match(N,(V)N), que;\n    while (1) {\n   \
    \     std::ranges::fill(dist,-1);\n        fill(cur.begin(),cur.end(),0);\n  \
    \      que.clear();\n        for (usize i = 0 ; i < N ; i++)\n            if (free[i])\
    \ {\n                que.push_back(i);\n                dist[i] = 0;\n       \
    \     }\n        for (usize t = 0 ; t < que.size() ; t++) {\n            const\
    \ V v = que[t];\n            for (auto [x, i] : g[v]) {\n                if (dist[x]\
    \ != -1)\n                    continue;\n                if (v < (V)N and used[i])\n\
    \                    continue;\n                if (v >= (V)N and !used[i])\n\
    \                    continue;\n                dist[x] = dist[v] + 1;\n     \
    \           que.push_back(x);\n            }\n        }\n        const i32 minDist\
    \ = [&]() {\n            i32 res = N + M;\n            for (usize i = N ; i <\
    \ N + M ; i++)\n                if (free[i] and dist[i] != -1)\n             \
    \       res = std::min(res,dist[i]);\n            return res;\n        }();\n\
    \        if ((usize)minDist == N + M)\n            break;\n        auto dfs =\
    \ [&](auto dfs,V v) -> bool {\n            cur[v] = 1;\n            if (v >= (V)N\
    \ and free[v]) {\n                free[v] = 0;\n                return 1;\n  \
    \          }\n            if (dist[v] >= minDist)\n                return 0;\n\
    \            for (auto [x, i] : g[v]) {\n                if (cur[x])\n       \
    \             continue;\n                if (dist[v] + 1 != dist[x])\n       \
    \             continue;\n                if (v < (V)N and used[i])\n         \
    \           continue;\n                if (v >= (V)N and !used[i])\n         \
    \           continue;\n                if (dfs(dfs,x)) {\n                   \
    \ free[v] = 0;\n                    used[i] = !used[i];\n                    return\
    \ 1;\n                }\n            }\n            return 0;\n        };\n  \
    \      for (usize i = 0 ; i < N ; i++)\n            if (free[i] and !cur[i])\n\
    \                dfs(dfs,i);\n    }\n    std::vector<std::pair<V,V>> res;\n  \
    \  for (usize i = 0 ; i < E.size() ; i++)\n        if (used[i])\n            res.push_back(E[i]);\n\
    \    return res;\n}\n\ntemplate <class V>\nstd::optional<std::vector<std::pair<V,V>>>\
    \ BipartiteMatching(usize N,std::vector<std::pair<usize,usize>> E) {\n    std::vector<std::vector<V>>\
    \ g(N); \n    for (auto [u, v] : E) {\n        assert(0 <= u and u < N);\n   \
    \     assert(0 <= v and v < N);\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n    std::vector<i32> col(N,-1);\n    auto dfs = [&](auto dfs,V v,i32 c)\
    \ -> bool {\n        col[v] = c;\n        for (V x : g[v]) {\n            if (col[x]\
    \ == -1 and !dfs(dfs,x,c^1))\n                return false;\n            else\
    \ if (col[v] == col[x])\n                return false;\n        }\n        return\
    \ true;\n    };\n    for (usize i = 0 ; i < N ; i++)\n        if (col[i] == -1)\n\
    \            if (!dfs(dfs,i,0))\n                return std::nullopt;\n    std::vector<V>\
    \ id(N), L, R;\n    for (usize i = 0 ; i < N ; i++)\n        (col[i] == 0 ? L\
    \ : R).push_back(i);\n    for (usize i = 0 ; i < L.size() ; i++)\n        id[L[i]]\
    \ = i;\n    for (usize i = 0 ; i < R.size() ; i++)\n        id[R[i]] = L.size()\
    \ + i;\n    for (auto& [u, v] : E) {\n        u = id[u];\n        v = id[v];\n\
    \        if (u >= L.size())\n            std::swap(u,v);\n        v -= L.size();\n\
    \    }\n    auto ans = BipartiteMatching(L.size(),R.size(),E);\n    for (auto&\
    \ [u, v] : ans) {\n        u = L[u];\n        v = R[v];\n    }\n    return ans;\n\
    }\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Matching/BipartiteMatching.hpp
  requiredBy: []
  timestamp: '2026-02-19 21:14:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/bipartitematching.test.cpp
documentation_of: Src/Graph/Matching/BipartiteMatching.hpp
layout: document
title: Bipartite Matching
---

## 概要

二部グラフの最大マッチングを計算する。内部でHopcroft-Karpのアルゴリズムを用いている。

計算量 $O((E+V)\sqrt{V})$

## メモ: 最大マッチング-最小被覆定理

最大フローで二部グラフの最大マッチングを計算するときのことを思い出す。

このときのフローと任意のマッチングは一対一対応する(それはそう)

頂点被覆を一つ取る。左側の採用した/しないをflipしてsourceを追加すると、カットに対応する(反対方向にやるとカットから頂点被覆を取得できる)

最大流・最小カット定理を思い出すと辺被覆とマッチングは一対一対応している。また、最大マッチングから最小頂点被覆を構築できる(逆もしかり)

(頂点被覆は頂点集合であって、任意の辺の少なくとも一方の端点が含まれるもの。辺被覆と逆に覚えていて任意の資料が読めなかった時期があったなぁ)

頂点被覆の補集合を取ると、独立集合になる。
