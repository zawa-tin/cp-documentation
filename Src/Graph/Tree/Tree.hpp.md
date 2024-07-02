---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/AuxiliaryTree.hpp
    title: "Auxiliary Tree (\u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\
      \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\
      \u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\
      \u6728)"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc340_g.test.cpp
    title: Test/AtCoder/abc340_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/lca.test.cpp
    title: Test/LC/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc359_g.test.cpp
    title: ABC359-F Sum of Tree Distance
  - icon: ':heavy_check_mark:'
    path: Test/Manual/typical90_ai.test.cpp
    title: Test/Manual/typical90_ai.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/Tree.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Tree/Tree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace zawa {\n\nusing Tree = std::vector<std::vector<u32>>;\n\
    \nvoid AddEdge(Tree& T, u32 u, u32 v) {\n    assert(u < T.size());\n    assert(v\
    \ < T.size());\n    T[u].emplace_back(v);\n    T[v].emplace_back(u);\n}\n\nvoid\
    \ AddDirectedEdge(Tree& T, u32 from, u32 to) {\n    assert(from < T.size());\n\
    \    assert(to < T.size());\n    T[from].emplace_back(to);\n}\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace zawa {\n\nusing Tree = std::vector<std::vector<u32>>;\n\
    \nvoid AddEdge(Tree& T, u32 u, u32 v) {\n    assert(u < T.size());\n    assert(v\
    \ < T.size());\n    T[u].emplace_back(v);\n    T[v].emplace_back(u);\n}\n\nvoid\
    \ AddDirectedEdge(Tree& T, u32 from, u32 to) {\n    assert(from < T.size());\n\
    \    assert(to < T.size());\n    T[from].emplace_back(to);\n}\n\n} // namespace\
    \ zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/Tree.hpp
  requiredBy:
  - Src/Graph/Tree/AuxiliaryTree.hpp
  - Src/Graph/Tree/LowestCommonAncestor.hpp
  timestamp: '2024-07-02 11:54:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc340_g.test.cpp
  - Test/LC/lca.test.cpp
  - Test/Manual/typical90_ai.test.cpp
  - Test/Manual/abc359_g.test.cpp
documentation_of: Src/Graph/Tree/Tree.hpp
layout: document
redirect_from:
- /library/Src/Graph/Tree/Tree.hpp
- /library/Src/Graph/Tree/Tree.hpp.html
title: Src/Graph/Tree/Tree.hpp
---
