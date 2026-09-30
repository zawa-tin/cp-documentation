---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
    title: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/MoonTree.hpp
    title: Src/Graph/Tree/MoonTree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc477_g.test.cpp
    title: Test/AtCoder/abc477_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/lca/OfflineLowestCommonAncestor.test.cpp
    title: Test/LC/lca/OfflineLowestCommonAncestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/OfflineLowestCommonAncestor.hpp\"\n\n#line\
    \ 2 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n#include <vector>\n\
    #include <concepts>\n#include <optional>\n\nnamespace zawa {\n\nclass DisjointSetUnion\
    \ {\npublic:\n\n    DisjointSetUnion() = default;\n\n    DisjointSetUnion(usize\
    \ n) : n_{n}, comps_{n}, data_(n, -1) {\n        data_.shrink_to_fit();\n    }\n\
    \    \n    u32 leader(u32 v) {\n        return data_[v] < 0 ? v : static_cast<u32>(data_[v]\
    \ = leader(data_[v]));\n    }\n\n    bool same(u32 u, u32 v) {\n        return\
    \ leader(u) == leader(v);\n    }\n\n    bool merge(u32 u, u32 v) {\n        assert(u\
    \ < n_);\n        assert(v < n_);\n        u = leader(u);\n        v = leader(v);\n\
    \        if (u == v) return false;\n        comps_--;\n        if (data_[u] >\
    \ data_[v]) std::swap(u, v);\n        data_[u] += data_[v];\n        data_[v]\
    \ = u;\n        return true;\n    }\n\n    std::optional<u32> mergeAndLeader(u32\
    \ u,u32 v) {\n        assert(u < n_);\n        assert(v < n_);\n        u = leader(u);\n\
    \        v = leader(v);\n        if (u == v) \n            return std::nullopt;\n\
    \        comps_--;\n        if (data_[u] > data_[v]) std::swap(u, v);\n      \
    \  data_[u] += data_[v];\n        data_[v] = u;\n        return u;\n    }\n\n\
    \    inline usize size() const noexcept {\n        return n_;\n    }\n\n    usize\
    \ size(u32 v) {\n        assert(v < n_);\n        return static_cast<usize>(-data_[leader(v)]);\n\
    \    }\n\n    inline usize components() const noexcept {\n        return comps_;\n\
    \    }\n\n    template <class T = usize>\n    std::vector<std::vector<T>> enumerate()\
    \ requires std::convertible_to<usize, T> {\n        std::vector<std::vector<T>>\
    \ res(n_);\n        for (usize v{} ; v < n_ ; v++) {\n            res[leader(v)].push_back(static_cast<T>(v));\n\
    \        }\n        std::erase_if(res, [](const auto& arr) -> bool { return arr.empty();\
    \ });\n        return res;\n    }\n\nprivate:\n    usize n_{}, comps_{};\n   \
    \ std::vector<i32> data_;\n};\n\n} // namespace zawa\n#line 4 \"Src/Graph/Tree/OfflineLowestCommonAncestor.hpp\"\
    \n\n#line 7 \"Src/Graph/Tree/OfflineLowestCommonAncestor.hpp\"\n#include <utility>\n\
    #line 9 \"Src/Graph/Tree/OfflineLowestCommonAncestor.hpp\"\n\nnamespace zawa {\n\
    \ntemplate <std::integral T>\nstd::vector<T> OfflineLowestCommonAncestor(const\
    \ std::vector<std::vector<T>>& g,const std::vector<std::pair<T,T>>& qs) {\n  \
    \  const T n = static_cast<T>(g.size()), q = static_cast<T>(qs.size());\n    if\
    \ (!n) {\n        assert(!q);\n        return {};\n    }\n    DisjointSetUnion\
    \ dsu(n);\n    std::vector<bool> visited(n);\n    std::vector<T> anc(n),ans(q),sum(n+1);\n\
    \    for (auto [u,v] : qs) {\n        sum[u+1]++;\n        sum[v+1]++;\n    }\n\
    \    for (T i = 0 ; i < n ; i++)\n        sum[i+1]+=sum[i];\n    std::vector<std::pair<T,u32>>\
    \ query(sum[n]);\n    {\n        std::vector<T> cur(n);\n        for (T i = 0\
    \ ; i < q ; i++) {\n            auto [u,v] = qs[i];\n            query[sum[u]+cur[u]++]\
    \ = {v,i};\n            query[sum[v]+cur[v]++] = {u,i};\n        }\n    }\n  \
    \  auto dfs=[&](auto dfs,T v,T p) -> void {\n        anc[v]=v;\n        visited[v]=1;\n\
    \        for (T x : g[v])\n            if (x!=p) {\n                dfs(dfs,x,v);\n\
    \                anc[dsu.mergeAndLeader(x,v).value()] = v;\n            }\n  \
    \      for (T i = sum[v] ; i < sum[v+1] ; i++) {\n            auto [u,id] = query[i];\n\
    \            if (visited[u])\n                ans[id] = anc[dsu.leader(u)];\n\
    \        }\n    };\n    dfs(dfs,static_cast<T>(0),static_cast<T>(-1));\n    return\
    \ ans;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\
    \n\n#include <cassert>\n#include <concepts>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <std::integral T>\nstd::vector<T> OfflineLowestCommonAncestor(const\
    \ std::vector<std::vector<T>>& g,const std::vector<std::pair<T,T>>& qs) {\n  \
    \  const T n = static_cast<T>(g.size()), q = static_cast<T>(qs.size());\n    if\
    \ (!n) {\n        assert(!q);\n        return {};\n    }\n    DisjointSetUnion\
    \ dsu(n);\n    std::vector<bool> visited(n);\n    std::vector<T> anc(n),ans(q),sum(n+1);\n\
    \    for (auto [u,v] : qs) {\n        sum[u+1]++;\n        sum[v+1]++;\n    }\n\
    \    for (T i = 0 ; i < n ; i++)\n        sum[i+1]+=sum[i];\n    std::vector<std::pair<T,u32>>\
    \ query(sum[n]);\n    {\n        std::vector<T> cur(n);\n        for (T i = 0\
    \ ; i < q ; i++) {\n            auto [u,v] = qs[i];\n            query[sum[u]+cur[u]++]\
    \ = {v,i};\n            query[sum[v]+cur[v]++] = {u,i};\n        }\n    }\n  \
    \  auto dfs=[&](auto dfs,T v,T p) -> void {\n        anc[v]=v;\n        visited[v]=1;\n\
    \        for (T x : g[v])\n            if (x!=p) {\n                dfs(dfs,x,v);\n\
    \                anc[dsu.mergeAndLeader(x,v).value()] = v;\n            }\n  \
    \      for (T i = sum[v] ; i < sum[v+1] ; i++) {\n            auto [u,id] = query[i];\n\
    \            if (visited[u])\n                ans[id] = anc[dsu.leader(u)];\n\
    \        }\n    };\n    dfs(dfs,static_cast<T>(0),static_cast<T>(-1));\n    return\
    \ ans;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/OfflineLowestCommonAncestor.hpp
  requiredBy:
  - Src/Graph/Tree/MoonTree.hpp
  timestamp: '2026-09-30 13:13:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc477_g.test.cpp
  - Test/LC/lca/OfflineLowestCommonAncestor.test.cpp
documentation_of: Src/Graph/Tree/OfflineLowestCommonAncestor.hpp
layout: document
redirect_from:
- /library/Src/Graph/Tree/OfflineLowestCommonAncestor.hpp
- /library/Src/Graph/Tree/OfflineLowestCommonAncestor.hpp.html
title: Src/Graph/Tree/OfflineLowestCommonAncestor.hpp
---
