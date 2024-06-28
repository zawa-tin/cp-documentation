---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/CF/ECR167-F.test.cpp
    title: Test/CF/ECR167-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/unionfind.test.cpp
    title: Test/LC/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n#include <vector>\n\
    \nnamespace zawa {\n\nclass DisjointSetUnion {\nprivate:\n    usize n_{};\n  \
    \  std::vector<u32> parent_{}, size_{};\npublic:\n    DisjointSetUnion() = default;\n\
    \    DisjointSetUnion(usize n) : n_{n}, parent_(n), size_(n, u32{1}) {\n     \
    \   parent_.shrink_to_fit();\n        size_.shrink_to_fit();\n        std::iota(parent_.begin(),\
    \ parent_.end(), u32{});\n    }\n\n    u32 leader(u32 v) {\n        assert(v <\
    \ n_);\n        return (v == parent_[v] ? v : parent_[v] = leader(parent_[v]));\n\
    \    }\n\n    bool same(u32 u, u32 v) {\n        assert(u < n_);\n        assert(v\
    \ < n_);\n        return leader(u) == leader(v);\n    }\n\n    void merge(u32\
    \ u, u32 v) {\n        assert(u < n_);\n        assert(v < n_);\n        u = leader(u);\n\
    \        v = leader(v);\n        if (u == v) return;\n        if (size_[u] < size_[v])\
    \ std::swap(u, v);\n        size_[u] += size_[v];\n        parent_[v] = u;\n \
    \   }\n\n    constexpr u32 size() const noexcept {\n        return n_;\n    }\n\
    \n    u32 size(u32 v) {\n        assert(v < n_);\n        return size_[leader(v)];\n\
    \    }\n\n    std::vector<std::vector<u32>> enumerate() {\n        std::vector\
    \ res(n_, std::vector<u32>{});\n        for (u32 i{} ; i < n_ ; i++) {\n     \
    \       res[leader(i)].emplace_back(i);\n        }\n        res.erase(std::remove_if(res.begin(),\
    \ res.end(),\n                    [](const std::vector<u32>& array) { return array.empty();\
    \ }), res.end());\n        return res;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <numeric>\n#include <vector>\n\nnamespace zawa {\n\
    \nclass DisjointSetUnion {\nprivate:\n    usize n_{};\n    std::vector<u32> parent_{},\
    \ size_{};\npublic:\n    DisjointSetUnion() = default;\n    DisjointSetUnion(usize\
    \ n) : n_{n}, parent_(n), size_(n, u32{1}) {\n        parent_.shrink_to_fit();\n\
    \        size_.shrink_to_fit();\n        std::iota(parent_.begin(), parent_.end(),\
    \ u32{});\n    }\n\n    u32 leader(u32 v) {\n        assert(v < n_);\n       \
    \ return (v == parent_[v] ? v : parent_[v] = leader(parent_[v]));\n    }\n\n \
    \   bool same(u32 u, u32 v) {\n        assert(u < n_);\n        assert(v < n_);\n\
    \        return leader(u) == leader(v);\n    }\n\n    void merge(u32 u, u32 v)\
    \ {\n        assert(u < n_);\n        assert(v < n_);\n        u = leader(u);\n\
    \        v = leader(v);\n        if (u == v) return;\n        if (size_[u] < size_[v])\
    \ std::swap(u, v);\n        size_[u] += size_[v];\n        parent_[v] = u;\n \
    \   }\n\n    constexpr u32 size() const noexcept {\n        return n_;\n    }\n\
    \n    u32 size(u32 v) {\n        assert(v < n_);\n        return size_[leader(v)];\n\
    \    }\n\n    std::vector<std::vector<u32>> enumerate() {\n        std::vector\
    \ res(n_, std::vector<u32>{});\n        for (u32 i{} ; i < n_ ; i++) {\n     \
    \       res[leader(i)].emplace_back(i);\n        }\n        res.erase(std::remove_if(res.begin(),\
    \ res.end(),\n                    [](const std::vector<u32>& array) { return array.empty();\
    \ }), res.end());\n        return res;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  requiredBy: []
  timestamp: '2023-11-13 10:16:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/unionfind.test.cpp
  - Test/CF/ECR167-F.test.cpp
documentation_of: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
- /library/Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp.html
title: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
---
