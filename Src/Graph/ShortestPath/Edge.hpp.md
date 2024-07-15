---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/ShortestPath/BFS.hpp
    title: Src/Graph/ShortestPath/BFS.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Graph/ShortestPath/Dijkstra.hpp
    title: Src/Graph/ShortestPath/Dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Graph/ShortestPath/ShortestPathTree.hpp
    title: Src/Graph/ShortestPath/ShortestPathTree.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Graph/ShortestPath/WeightedShortestPathTree.hpp
    title: Src/Graph/ShortestPath/WeightedShortestPathTree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2872.test.cpp
    title: "AOJ2872 \u6700\u77ED\u8DDD\u96E2\u3092\u4F38\u3070\u3059\u3048\u3073\u3061\
      \u3083\u3093"
  - icon: ':heavy_check_mark:'
    path: Test/LC/shortest_path.test.cpp
    title: Test/LC/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc168_d.test.cpp
    title: Test/Manual/abc168_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc252_e.test.cpp
    title: Test/Manual/abc252_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc271_d.test.cpp
    title: Test/Manual/abc271_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/ShortestPath/Edge.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/ShortestPath/Edge.hpp\"\n\nnamespace\
    \ zawa {\n\nnamespace internal {\n\nclass Edge {\nprotected:\n    static constexpr\
    \ u32 INVALID{static_cast<u32>(-1)};\npublic:\n    u32 parent{INVALID}; \n   \
    \ u32 id{INVALID};\n    Edge() = default;\n    Edge(u32 parent, u32 id) : parent{parent},\
    \ id{id} {}\n    Edge& operator=(const Edge& edge) {\n        parent = edge.parent;\n\
    \        id = edge.id;\n        return *this;\n    }\n    inline bool exist()\
    \ const noexcept {\n        return parent != INVALID;\n    }\n    static constexpr\
    \ u32 invalid() noexcept {\n        return INVALID; \n    }\n};\n\ntemplate <class\
    \ Weight>\nclass WeightedEdge : public Edge {\npublic:\n    Weight weight{INVALID};\n\
    \    WeightedEdge() = default;\n    WeightedEdge(u32 parent, const Weight& weight,\
    \ u32 id)\n        : Edge{parent, id}, weight{weight} {}\n\n    WeightedEdge&\
    \ operator=(const WeightedEdge& edge) {\n        parent = edge.parent;\n     \
    \   id = edge.id;\n        weight = edge.weight;\n        return *this;\n    }\n\
    \n};\n\n} // namespace internal\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\nnamespace zawa\
    \ {\n\nnamespace internal {\n\nclass Edge {\nprotected:\n    static constexpr\
    \ u32 INVALID{static_cast<u32>(-1)};\npublic:\n    u32 parent{INVALID}; \n   \
    \ u32 id{INVALID};\n    Edge() = default;\n    Edge(u32 parent, u32 id) : parent{parent},\
    \ id{id} {}\n    Edge& operator=(const Edge& edge) {\n        parent = edge.parent;\n\
    \        id = edge.id;\n        return *this;\n    }\n    inline bool exist()\
    \ const noexcept {\n        return parent != INVALID;\n    }\n    static constexpr\
    \ u32 invalid() noexcept {\n        return INVALID; \n    }\n};\n\ntemplate <class\
    \ Weight>\nclass WeightedEdge : public Edge {\npublic:\n    Weight weight{INVALID};\n\
    \    WeightedEdge() = default;\n    WeightedEdge(u32 parent, const Weight& weight,\
    \ u32 id)\n        : Edge{parent, id}, weight{weight} {}\n\n    WeightedEdge&\
    \ operator=(const WeightedEdge& edge) {\n        parent = edge.parent;\n     \
    \   id = edge.id;\n        weight = edge.weight;\n        return *this;\n    }\n\
    \n};\n\n} // namespace internal\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/ShortestPath/Edge.hpp
  requiredBy:
  - Src/Graph/ShortestPath/WeightedShortestPathTree.hpp
  - Src/Graph/ShortestPath/BFS.hpp
  - Src/Graph/ShortestPath/Dijkstra.hpp
  - Src/Graph/ShortestPath/ShortestPathTree.hpp
  timestamp: '2023-12-14 22:32:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/2872.test.cpp
  - Test/LC/shortest_path.test.cpp
  - Test/Manual/abc252_e.test.cpp
  - Test/Manual/abc168_d.test.cpp
  - Test/Manual/abc271_d.test.cpp
documentation_of: Src/Graph/ShortestPath/Edge.hpp
layout: document
redirect_from:
- /library/Src/Graph/ShortestPath/Edge.hpp
- /library/Src/Graph/ShortestPath/Edge.hpp.html
title: Src/Graph/ShortestPath/Edge.hpp
---
