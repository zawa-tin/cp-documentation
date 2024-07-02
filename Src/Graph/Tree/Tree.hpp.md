---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/Tree.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Tree/Tree.hpp\"\n\n#include <vector>\n\
    \nnamespace zawa {\n\nusing Tree = std::vector<std::vector<u32>>;\n\nvoid AddEdge(Tree&\
    \ T, u32 u, u32 v) {\n    T[u].emplace_back(v);\n    T[v].emplace_back(u);\n}\n\
    \nvoid AddDirectedEdge(Tree& T, u32 from, u32 to) {\n    T[from].emplace_back(to);\n\
    }\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <vector>\n\
    \nnamespace zawa {\n\nusing Tree = std::vector<std::vector<u32>>;\n\nvoid AddEdge(Tree&\
    \ T, u32 u, u32 v) {\n    T[u].emplace_back(v);\n    T[v].emplace_back(u);\n}\n\
    \nvoid AddDirectedEdge(Tree& T, u32 from, u32 to) {\n    T[from].emplace_back(to);\n\
    }\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/Tree.hpp
  requiredBy: []
  timestamp: '2024-07-02 09:13:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Src/Graph/Tree/Tree.hpp
layout: document
redirect_from:
- /library/Src/Graph/Tree/Tree.hpp
- /library/Src/Graph/Tree/Tree.hpp.html
title: Src/Graph/Tree/Tree.hpp
---
