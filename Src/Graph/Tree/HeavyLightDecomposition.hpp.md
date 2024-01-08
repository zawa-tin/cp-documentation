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
    path: Test/LC/vertex_add_path_sum.test.cpp
    title: Test/LC/vertex_add_path_sum.test.cpp
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
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Utility/U32Pair.hpp\"\
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
    \ 5 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <iterator>\n#include <limits>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace zawa {\n\nclass HeavyLightDecomposition {\nprivate:\n\
    \    usize n_;\n    std::vector<std::vector<u32>> g_;\n    std::vector<u32> index_,\
    \ top_, depth_, par_;\n    std::vector<u32> subtree_;\n\n    static constexpr\
    \ u32 invalid() noexcept {\n        return std::numeric_limits<u32>::max();\n\
    \    }\n\n    u32 dfsInit(u32 v, u32 p) {\n        par_[v] = p;\n        for (auto\
    \ it{g_[v].begin()} ; it != g_[v].end() ; ) {\n            if (*it == p) {\n \
    \               it = g_[v].erase(it);\n            }\n            else {\n   \
    \             subtree_[v] += dfsInit(*it, v);\n                it++;\n       \
    \     }\n        }\n        return ++subtree_[v];\n    }\n    void dfs(u32 v,\
    \ u32 p, u32 tp, u32& t) {\n        top_[v] = tp;\n        index_[v] = t;\n  \
    \      depth_[v] = (p == invalid() ? u32{} : depth_[p] + 1);\n        if (g_[v].empty())\
    \ return;\n        auto max{std::distance(g_[v].begin(), std::max_element(g_[v].begin(),\
    \ g_[v].end(), [&](const auto& i, const auto& j) {\n                    return\
    \ subtree_[i] < subtree_[j];\n                }))};\n        if (max) std::swap(g_[v][0],\
    \ g_[v][max]);\n        dfs(g_[v][0], v, tp, ++t);\n        for (u32 i{1u} ; i\
    \ < g_[v].size() ; i++) {\n            dfs(g_[v][i], v, g_[v][i], ++t);\n    \
    \    }\n    }\n\npublic:\n    constexpr usize size() const noexcept {\n      \
    \  return n_;\n    }\n    HeavyLightDecomposition() = default;\n    HeavyLightDecomposition(usize\
    \ n) \n        : n_{n}, g_(n), index_(n), top_(n), depth_(n), par_(n, invalid()),\
    \ subtree_(n) {\n        g_.shrink_to_fit();\n        index_.shrink_to_fit();\n\
    \        top_.shrink_to_fit();\n        depth_.shrink_to_fit();\n        par_.shrink_to_fit();\n\
    \        subtree_.shrink_to_fit();\n    } \n    void addEdge(u32 u, u32 v) {\n\
    \        assert(u < size());\n        assert(v < size());\n        g_[u].emplace_back(v);\n\
    \        g_[v].emplace_back(u);\n    }\n    void build(u32 r) {\n        assert(r\
    \ < size()); \n        dfsInit(r, invalid());\n        u32 t{};\n        dfs(r,\
    \ invalid(), r, t);\n    }\n\n    const u32& operator[](u32 i) const noexcept\
    \ {\n        assert(i < size());\n        return index_[i];\n    }\n\n    std::vector<U32Pair>\
    \ operator()(u32 s, u32 t) const {\n        assert(s < size());\n        assert(t\
    \ < size());\n        std::vector<U32Pair> res, ser; \n        while (top_[s]\
    \ != top_[t]) {\n            if (depth_[top_[s]] <= depth_[top_[t]]) {\n     \
    \           ser.emplace_back(index_[top_[t]], index_[t] + 1);\n              \
    \  t = top_[t];\n                t = (par_[t] == invalid() ? t : par_[t]);\n \
    \           }\n            else {\n                res.emplace_back(index_[top_[s]],\
    \ index_[s] + 1);\n                s = top_[s];\n                s = (par_[s]\
    \ == invalid() ? s : par_[s]);\n            }\n        }\n        res.emplace_back(std::min(index_[s],\
    \ index_[t]), std::max(index_[s], index_[t]) + 1u);\n        res.insert(res.end(),\
    \ ser.begin(), ser.end());\n        return res;\n    }\n\n    u32 lca(u32 u, u32\
    \ v) {\n        assert(u < size());\n        assert(v < size());\n        while\
    \ (top_[u] != top_[v]) {\n            if (depth_[top_[u]] <= depth_[top_[v]])\
    \ {\n                v = top_[v];\n                v = (par_[v] == invalid() ?\
    \ v : par_[v]);\n            }\n            else {\n                u = top_[u];\n\
    \                u = (par_[u] == invalid() ? u : par_[u]);\n            }\n  \
    \      }\n        return (depth_[u] <= depth_[v] ? u : v);\n    }\n};\n\n} //\
    \ namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Utility/U32Pair.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include <limits>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\nclass HeavyLightDecomposition\
    \ {\nprivate:\n    usize n_;\n    std::vector<std::vector<u32>> g_;\n    std::vector<u32>\
    \ index_, top_, depth_, par_;\n    std::vector<u32> subtree_;\n\n    static constexpr\
    \ u32 invalid() noexcept {\n        return std::numeric_limits<u32>::max();\n\
    \    }\n\n    u32 dfsInit(u32 v, u32 p) {\n        par_[v] = p;\n        for (auto\
    \ it{g_[v].begin()} ; it != g_[v].end() ; ) {\n            if (*it == p) {\n \
    \               it = g_[v].erase(it);\n            }\n            else {\n   \
    \             subtree_[v] += dfsInit(*it, v);\n                it++;\n       \
    \     }\n        }\n        return ++subtree_[v];\n    }\n    void dfs(u32 v,\
    \ u32 p, u32 tp, u32& t) {\n        top_[v] = tp;\n        index_[v] = t;\n  \
    \      depth_[v] = (p == invalid() ? u32{} : depth_[p] + 1);\n        if (g_[v].empty())\
    \ return;\n        auto max{std::distance(g_[v].begin(), std::max_element(g_[v].begin(),\
    \ g_[v].end(), [&](const auto& i, const auto& j) {\n                    return\
    \ subtree_[i] < subtree_[j];\n                }))};\n        if (max) std::swap(g_[v][0],\
    \ g_[v][max]);\n        dfs(g_[v][0], v, tp, ++t);\n        for (u32 i{1u} ; i\
    \ < g_[v].size() ; i++) {\n            dfs(g_[v][i], v, g_[v][i], ++t);\n    \
    \    }\n    }\n\npublic:\n    constexpr usize size() const noexcept {\n      \
    \  return n_;\n    }\n    HeavyLightDecomposition() = default;\n    HeavyLightDecomposition(usize\
    \ n) \n        : n_{n}, g_(n), index_(n), top_(n), depth_(n), par_(n, invalid()),\
    \ subtree_(n) {\n        g_.shrink_to_fit();\n        index_.shrink_to_fit();\n\
    \        top_.shrink_to_fit();\n        depth_.shrink_to_fit();\n        par_.shrink_to_fit();\n\
    \        subtree_.shrink_to_fit();\n    } \n    void addEdge(u32 u, u32 v) {\n\
    \        assert(u < size());\n        assert(v < size());\n        g_[u].emplace_back(v);\n\
    \        g_[v].emplace_back(u);\n    }\n    void build(u32 r) {\n        assert(r\
    \ < size()); \n        dfsInit(r, invalid());\n        u32 t{};\n        dfs(r,\
    \ invalid(), r, t);\n    }\n\n    const u32& operator[](u32 i) const noexcept\
    \ {\n        assert(i < size());\n        return index_[i];\n    }\n\n    std::vector<U32Pair>\
    \ operator()(u32 s, u32 t) const {\n        assert(s < size());\n        assert(t\
    \ < size());\n        std::vector<U32Pair> res, ser; \n        while (top_[s]\
    \ != top_[t]) {\n            if (depth_[top_[s]] <= depth_[top_[t]]) {\n     \
    \           ser.emplace_back(index_[top_[t]], index_[t] + 1);\n              \
    \  t = top_[t];\n                t = (par_[t] == invalid() ? t : par_[t]);\n \
    \           }\n            else {\n                res.emplace_back(index_[top_[s]],\
    \ index_[s] + 1);\n                s = top_[s];\n                s = (par_[s]\
    \ == invalid() ? s : par_[s]);\n            }\n        }\n        res.emplace_back(std::min(index_[s],\
    \ index_[t]), std::max(index_[s], index_[t]) + 1u);\n        res.insert(res.end(),\
    \ ser.begin(), ser.end());\n        return res;\n    }\n\n    u32 lca(u32 u, u32\
    \ v) {\n        assert(u < size());\n        assert(v < size());\n        while\
    \ (top_[u] != top_[v]) {\n            if (depth_[top_[u]] <= depth_[top_[v]])\
    \ {\n                v = top_[v];\n                v = (par_[v] == invalid() ?\
    \ v : par_[v]);\n            }\n            else {\n                u = top_[u];\n\
    \                u = (par_[u] == invalid() ? u : par_[u]);\n            }\n  \
    \      }\n        return (depth_[u] <= depth_[v] ? u : v);\n    }\n};\n\n} //\
    \ namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Utility/U32Pair.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2024-01-09 00:25:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/vertex_add_path_sum.test.cpp
documentation_of: Src/Graph/Tree/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/Src/Graph/Tree/HeavyLightDecomposition.hpp
- /library/Src/Graph/Tree/HeavyLightDecomposition.hpp.html
title: Src/Graph/Tree/HeavyLightDecomposition.hpp
---
