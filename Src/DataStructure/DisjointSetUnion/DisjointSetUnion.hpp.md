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
    path: Test/LC/incremental_scc.test.cpp
    title: Test/LC/incremental_scc.test.cpp
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
    \nnamespace zawa {\n\nclass DisjointSetUnion {\npublic:\n    DisjointSetUnion()\
    \ = default;\n\n    DisjointSetUnion(usize n) : n_{n}, data_(n, -1) {\n      \
    \  data_.shrink_to_fit();\n    }\n    \n    u32 leader(u32 v) {\n        return\
    \ data_[v] < 0 ? v : static_cast<u32>(data_[v] = leader(data_[v]));\n    }\n\n\
    \    bool same(u32 u, u32 v) {\n        return leader(u) == leader(v);\n    }\n\
    \n    bool merge(u32 u, u32 v) {\n        assert(u < n_);\n        assert(v <\
    \ n_);\n        u = leader(u);\n        v = leader(v);\n        if (u == v) return\
    \ false;\n        if (data_[u] > data_[v]) std::swap(u, v);\n        data_[u]\
    \ += data_[v];\n        data_[v] = u;\n        return true;\n    }\n\n    inline\
    \ usize size() const noexcept {\n        return n_;\n    }\n\n    usize size(u32\
    \ v) {\n        assert(v < n_);\n        return static_cast<usize>(-data_[leader(v)]);\n\
    \    }\n\n    std::vector<std::vector<u32>> enumerate() {\n        std::vector<std::vector<u32>>\
    \ res(n_);\n        for (u32 v{} ; v < n_ ; v++) {\n            res[leader(v)].push_back(v);\n\
    \        }\n        res.erase(std::remove_if(res.begin(), res.end(),\n       \
    \             [](const auto& arr) -> bool { return arr.empty(); }), res.end());\n\
    \        return res;\n    }\n\nprivate:\n    usize n_{};\n    std::vector<i32>\
    \ data_;\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <numeric>\n#include <vector>\n\nnamespace zawa {\n\
    \nclass DisjointSetUnion {\npublic:\n    DisjointSetUnion() = default;\n\n   \
    \ DisjointSetUnion(usize n) : n_{n}, data_(n, -1) {\n        data_.shrink_to_fit();\n\
    \    }\n    \n    u32 leader(u32 v) {\n        return data_[v] < 0 ? v : static_cast<u32>(data_[v]\
    \ = leader(data_[v]));\n    }\n\n    bool same(u32 u, u32 v) {\n        return\
    \ leader(u) == leader(v);\n    }\n\n    bool merge(u32 u, u32 v) {\n        assert(u\
    \ < n_);\n        assert(v < n_);\n        u = leader(u);\n        v = leader(v);\n\
    \        if (u == v) return false;\n        if (data_[u] > data_[v]) std::swap(u,\
    \ v);\n        data_[u] += data_[v];\n        data_[v] = u;\n        return true;\n\
    \    }\n\n    inline usize size() const noexcept {\n        return n_;\n    }\n\
    \n    usize size(u32 v) {\n        assert(v < n_);\n        return static_cast<usize>(-data_[leader(v)]);\n\
    \    }\n\n    std::vector<std::vector<u32>> enumerate() {\n        std::vector<std::vector<u32>>\
    \ res(n_);\n        for (u32 v{} ; v < n_ ; v++) {\n            res[leader(v)].push_back(v);\n\
    \        }\n        res.erase(std::remove_if(res.begin(), res.end(),\n       \
    \             [](const auto& arr) -> bool { return arr.empty(); }), res.end());\n\
    \        return res;\n    }\n\nprivate:\n    usize n_{};\n    std::vector<i32>\
    \ data_;\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  requiredBy: []
  timestamp: '2024-07-07 02:41:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/incremental_scc.test.cpp
  - Test/LC/unionfind.test.cpp
  - Test/CF/ECR167-F.test.cpp
documentation_of: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
- /library/Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp.html
title: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
---
