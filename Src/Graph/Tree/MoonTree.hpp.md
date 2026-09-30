---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
    title: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/OfflineLowestCommonAncestor.hpp
    title: Src/Graph/Tree/OfflineLowestCommonAncestor.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/Mo.hpp
    title: Src/Utility/Mo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc477_g.test.cpp
    title: Test/AtCoder/abc477_g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/MoonTree.hpp\"\n\n#line 2 \"Src/Utility/Mo.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Utility/Mo.hpp\"\
    \n\n#include <algorithm>\n#include <cmath>\n#include <concepts>\n#include <ranges>\n\
    #include <utility>\n#include <numeric>\n#include <limits>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <std::signed_integral T>\nstd::vector<usize> Mo(const\
    \ std::vector<std::pair<T,T>>& P) {\n    if (P.empty())\n        return {};\n\
    \    T minY = std::numeric_limits<T>::max();\n    const u64 W = [&]() {\n    \
    \    T minX = std::numeric_limits<T>::max();\n        T maxX = std::numeric_limits<T>::min(),\
    \ maxY = std::numeric_limits<T>::min();\n        for (auto [x,y] : P) {\n    \
    \        minX = std::min(minX,x);\n            maxX = std::max(maxX,x);\n    \
    \        minY = std::min(minY,y);\n            maxY = std::max(maxY,y);\n    \
    \    }\n        return std::max<u64>({1,u64(maxX-minX),u64(maxY-minY)});\n   \
    \ }();\n    const usize B = [&]() {\n        u64 sq = std::max<u64>(1,sqrt(P.size()));\n\
    \        return (W + sq - 1) / sq;\n    }();\n    T sub = minY;\n    auto makeRank\
    \ = [&]() -> std::vector<std::pair<T,T>> {\n        std::vector<std::pair<T,T>>\
    \ res(P.size());\n        for (usize i = 0 ; i < P.size() ; i++) {\n         \
    \   res[i].first = (P[i].second - sub) / B;\n            res[i].second = (res[i].first\
    \ & 1 ? -1 : 1) * P[i].first;\n        }\n        return res;\n    };\n    std::vector<usize>\
    \ ord1(P.size()), ord2(P.size());\n    std::iota(ord1.begin(),ord1.end(),0);\n\
    \    std::iota(ord2.begin(),ord2.end(),0);\n    auto rank = makeRank();\n    std::ranges::sort(ord1,[&](usize\
    \ i, usize j) { return rank[i] < rank[j]; });\n    sub -= B / 2;\n    rank = makeRank();\n\
    \    std::ranges::sort(ord2,[&](usize i, usize j) { return rank[i] < rank[j];\
    \ });\n    auto cost = [&](const std::vector<usize>& ord) {\n        u64 res =\
    \ 0;\n        for (usize i = 0 ; i + 1 < ord.size() ; i++) {\n            res\
    \ += abs(P[ord[i+1]].first-P[ord[i]].first);\n            res += abs(P[ord[i+1]].second-P[ord[i]].second);\n\
    \        }\n        return res;\n    };\n    return cost(ord1) <= cost(ord2) ?\
    \ ord1 : ord2;\n}\n\n} // namespace zawa\n#line 2 \"Src/Graph/Tree/OfflineLowestCommonAncestor.hpp\"\
    \n\n#line 2 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\n\n#line\
    \ 4 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\n\n#line 6 \"\
    Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\n#include <cassert>\n\
    #line 10 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\n#include\
    \ <optional>\n\nnamespace zawa {\n\nclass DisjointSetUnion {\npublic:\n\n    DisjointSetUnion()\
    \ = default;\n\n    DisjointSetUnion(usize n) : n_{n}, comps_{n}, data_(n, -1)\
    \ {\n        data_.shrink_to_fit();\n    }\n    \n    u32 leader(u32 v) {\n  \
    \      return data_[v] < 0 ? v : static_cast<u32>(data_[v] = leader(data_[v]));\n\
    \    }\n\n    bool same(u32 u, u32 v) {\n        return leader(u) == leader(v);\n\
    \    }\n\n    bool merge(u32 u, u32 v) {\n        assert(u < n_);\n        assert(v\
    \ < n_);\n        u = leader(u);\n        v = leader(v);\n        if (u == v)\
    \ return false;\n        comps_--;\n        if (data_[u] > data_[v]) std::swap(u,\
    \ v);\n        data_[u] += data_[v];\n        data_[v] = u;\n        return true;\n\
    \    }\n\n    std::optional<u32> mergeAndLeader(u32 u,u32 v) {\n        assert(u\
    \ < n_);\n        assert(v < n_);\n        u = leader(u);\n        v = leader(v);\n\
    \        if (u == v) \n            return std::nullopt;\n        comps_--;\n \
    \       if (data_[u] > data_[v]) std::swap(u, v);\n        data_[u] += data_[v];\n\
    \        data_[v] = u;\n        return u;\n    }\n\n    inline usize size() const\
    \ noexcept {\n        return n_;\n    }\n\n    usize size(u32 v) {\n        assert(v\
    \ < n_);\n        return static_cast<usize>(-data_[leader(v)]);\n    }\n\n   \
    \ inline usize components() const noexcept {\n        return comps_;\n    }\n\n\
    \    template <class T = usize>\n    std::vector<std::vector<T>> enumerate() requires\
    \ std::convertible_to<usize, T> {\n        std::vector<std::vector<T>> res(n_);\n\
    \        for (usize v{} ; v < n_ ; v++) {\n            res[leader(v)].push_back(static_cast<T>(v));\n\
    \        }\n        std::erase_if(res, [](const auto& arr) -> bool { return arr.empty();\
    \ });\n        return res;\n    }\n\nprivate:\n    usize n_{}, comps_{};\n   \
    \ std::vector<i32> data_;\n};\n\n} // namespace zawa\n#line 4 \"Src/Graph/Tree/OfflineLowestCommonAncestor.hpp\"\
    \n\n#line 9 \"Src/Graph/Tree/OfflineLowestCommonAncestor.hpp\"\n\nnamespace zawa\
    \ {\n\ntemplate <std::integral T>\nstd::vector<T> OfflineLowestCommonAncestor(const\
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
    \ ans;\n}\n\n} // namespace zawa\n#line 5 \"Src/Graph/Tree/MoonTree.hpp\"\n\n\
    #line 9 \"Src/Graph/Tree/MoonTree.hpp\"\n\nnamespace zawa {\n\ntemplate <std::signed_integral\
    \ T, class Add,class Del, class Eval>\nstd::vector<typename std::invoke_result_t<Eval,\
    \ usize>> MoonTree(const std::vector<std::vector<T>>& G,const std::vector<std::pair<T,T>>&\
    \ qs, Add add, Del del, Eval eval, bool reset = false) {\n    const T n = static_cast<T>(G.size());\n\
    \    if (!n) {\n        assert(qs.empty());\n        return {};\n    }\n    std::vector<T>\
    \ in(n),out(n),euler;\n    euler.reserve(2*n);\n    auto dfs=[&](auto dfs,T v,T\
    \ p) -> void {\n        in[v] = static_cast<T>(euler.size());\n        euler.push_back(v);\n\
    \        for (T x : G[v])\n            if (x != p)\n                dfs(dfs,x,v);\n\
    \        out[v] = static_cast<T>(euler.size());\n        euler.push_back(v);\n\
    \    };\n    dfs(dfs,static_cast<T>(0),static_cast<T>(-1));\n    std::vector<std::pair<T,T>>\
    \ path;\n    path.reserve(qs.size());\n    std::vector<T> extra;\n    extra.reserve(qs.size());\n\
    \    std::vector<T> lcas = OfflineLowestCommonAncestor(G,qs);\n    // for (auto\
    \ [u,v] : qs) {\n    for (u32 idx = 0 ; idx < qs.size() ; idx++) {\n        auto\
    \ [u,v] = qs[idx];\n        T l=lcas[idx];\n        T i=in[u],j=in[v];\n     \
    \   if (i>j) {\n            std::swap(i,j);\n            std::swap(u,v);\n   \
    \     }\n        if (u!=l) {\n            i=out[u];\n            extra.push_back(l);\n\
    \        }\n        else\n            extra.push_back(n);\n        path.push_back({i,j+1});\n\
    \    }\n    T L=0,R=0;\n    std::vector<typename std::invoke_result_t<Eval, usize>>\
    \ res(qs.size());\n    std::vector<bool> parity(n);\n    auto toggle=[&](T v)\
    \ -> void {\n        parity[v] ? del(v) : add(v);\n        parity[v] = !parity[v];\n\
    \    };\n    for (usize i : Mo(path)) {\n        const auto [l,r] = path[i];\n\
    \        while (R<r) \n            toggle(euler[R++]);\n        while (L>l)\n\
    \            toggle(euler[--L]);\n        while (R>r)\n            toggle(euler[--R]);\n\
    \        while (L<l) \n            toggle(euler[L++]);\n        if (extra[i]<n)\n\
    \            toggle(extra[i]);\n        res[i] = eval(i);\n        if (extra[i]<n)\n\
    \            toggle(extra[i]);\n    }\n    if (reset)\n        while (R>L) \n\
    \            toggle(euler[--R]);\n    return res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Utility/Mo.hpp\"\n#include \"./OfflineLowestCommonAncestor.hpp\"\
    \n\n#include <concepts>\n#include <utility>\n#include <vector>\n\nnamespace zawa\
    \ {\n\ntemplate <std::signed_integral T, class Add,class Del, class Eval>\nstd::vector<typename\
    \ std::invoke_result_t<Eval, usize>> MoonTree(const std::vector<std::vector<T>>&\
    \ G,const std::vector<std::pair<T,T>>& qs, Add add, Del del, Eval eval, bool reset\
    \ = false) {\n    const T n = static_cast<T>(G.size());\n    if (!n) {\n     \
    \   assert(qs.empty());\n        return {};\n    }\n    std::vector<T> in(n),out(n),euler;\n\
    \    euler.reserve(2*n);\n    auto dfs=[&](auto dfs,T v,T p) -> void {\n     \
    \   in[v] = static_cast<T>(euler.size());\n        euler.push_back(v);\n     \
    \   for (T x : G[v])\n            if (x != p)\n                dfs(dfs,x,v);\n\
    \        out[v] = static_cast<T>(euler.size());\n        euler.push_back(v);\n\
    \    };\n    dfs(dfs,static_cast<T>(0),static_cast<T>(-1));\n    std::vector<std::pair<T,T>>\
    \ path;\n    path.reserve(qs.size());\n    std::vector<T> extra;\n    extra.reserve(qs.size());\n\
    \    std::vector<T> lcas = OfflineLowestCommonAncestor(G,qs);\n    // for (auto\
    \ [u,v] : qs) {\n    for (u32 idx = 0 ; idx < qs.size() ; idx++) {\n        auto\
    \ [u,v] = qs[idx];\n        T l=lcas[idx];\n        T i=in[u],j=in[v];\n     \
    \   if (i>j) {\n            std::swap(i,j);\n            std::swap(u,v);\n   \
    \     }\n        if (u!=l) {\n            i=out[u];\n            extra.push_back(l);\n\
    \        }\n        else\n            extra.push_back(n);\n        path.push_back({i,j+1});\n\
    \    }\n    T L=0,R=0;\n    std::vector<typename std::invoke_result_t<Eval, usize>>\
    \ res(qs.size());\n    std::vector<bool> parity(n);\n    auto toggle=[&](T v)\
    \ -> void {\n        parity[v] ? del(v) : add(v);\n        parity[v] = !parity[v];\n\
    \    };\n    for (usize i : Mo(path)) {\n        const auto [l,r] = path[i];\n\
    \        while (R<r) \n            toggle(euler[R++]);\n        while (L>l)\n\
    \            toggle(euler[--L]);\n        while (R>r)\n            toggle(euler[--R]);\n\
    \        while (L<l) \n            toggle(euler[L++]);\n        if (extra[i]<n)\n\
    \            toggle(extra[i]);\n        res[i] = eval(i);\n        if (extra[i]<n)\n\
    \            toggle(extra[i]);\n    }\n    if (reset)\n        while (R>L) \n\
    \            toggle(euler[--R]);\n    return res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Utility/Mo.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Tree/OfflineLowestCommonAncestor.hpp
  - Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/MoonTree.hpp
  requiredBy: []
  timestamp: '2026-09-30 13:13:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc477_g.test.cpp
documentation_of: Src/Graph/Tree/MoonTree.hpp
layout: document
redirect_from:
- /library/Src/Graph/Tree/MoonTree.hpp
- /library/Src/Graph/Tree/MoonTree.hpp.html
title: Src/Graph/Tree/MoonTree.hpp
---
