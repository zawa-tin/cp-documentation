---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/ShortestPath/Edge.hpp
    title: Src/Graph/ShortestPath/Edge.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/ShortestPath/Dijkstra.hpp
    title: Src/Graph/ShortestPath/Dijkstra.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2872.test.cpp
    title: "AOJ2872 \u6700\u77ED\u8DDD\u96E2\u3092\u4F38\u3070\u3059\u3048\u3073\u3061\
      \u3083\u3093"
  - icon: ':heavy_check_mark:'
    path: Test/LC/shortest_path.test.cpp
    title: Test/LC/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc252_e.test.cpp
    title: Test/Manual/abc252_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/ShortestPath/WeightedShortestPathTree.hpp\"\n\n\
    #line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Graph/ShortestPath/Edge.hpp\"\
    \n\n#line 4 \"Src/Graph/ShortestPath/Edge.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ internal {\n\nclass Edge {\nprotected:\n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n\
    public:\n    u32 parent{INVALID}; \n    u32 id{INVALID};\n    Edge() = default;\n\
    \    Edge(u32 parent, u32 id) : parent{parent}, id{id} {}\n    Edge& operator=(const\
    \ Edge& edge) {\n        parent = edge.parent;\n        id = edge.id;\n      \
    \  return *this;\n    }\n    inline bool exist() const noexcept {\n        return\
    \ parent != INVALID;\n    }\n    static constexpr u32 invalid() noexcept {\n \
    \       return INVALID; \n    }\n};\n\ntemplate <class Weight>\nclass WeightedEdge\
    \ : public Edge {\npublic:\n    Weight weight{INVALID};\n    WeightedEdge() =\
    \ default;\n    WeightedEdge(u32 parent, const Weight& weight, u32 id)\n     \
    \   : Edge{parent, id}, weight{weight} {}\n\n    WeightedEdge& operator=(const\
    \ WeightedEdge& edge) {\n        parent = edge.parent;\n        id = edge.id;\n\
    \        weight = edge.weight;\n        return *this;\n    }\n\n};\n\n} // namespace\
    \ internal\n\n} // namespace zawa\n#line 5 \"Src/Graph/ShortestPath/WeightedShortestPathTree.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <type_traits>\n#include\
    \ <vector>\n\nnamespace zawa {\n\nnamespace internal {\n\ntemplate <class Weight>\n\
    class WeightedShortestPathTree {\npublic:\n    static_assert(std::is_unsigned_v<Weight>,\
    \ \"Dijkstra's Algorithm only be work well by unsigned weight\");\n    using E\
    \ = WeightedEdge<Weight>;\n    static constexpr u32 invalid() noexcept {\n   \
    \     return E::invalid();\n    }\nprivate:\n    static constexpr u32 INVALID{E::invalid()};\n\
    \    usize n_;\n    u32 root_;\n    std::vector<E> tree_;\n    std::vector<Weight>\
    \ dist_;\npublic:\n    WeightedShortestPathTree() = default;\n    WeightedShortestPathTree(u32\
    \ n, u32 root) \n        : n_{n}, root_{root}, tree_(n), dist_(n, static_cast<Weight>(-1))\
    \ {\n        assert(root < n);\n        tree_.shrink_to_fit();\n        dist_.shrink_to_fit();\n\
    \        dist_[root] = Weight{};\n    }\n\n    inline usize size() const noexcept\
    \ {\n        return n_;\n    }\n    inline u32 root() const noexcept {\n     \
    \   return root_;\n    }\n    inline u32 parent(u32 v) const noexcept {\n    \
    \    assert(v < size());\n        return tree_[v].parent;\n    }\n    inline u32\
    \ id(u32 v) const noexcept {\n        assert(v < size());\n        return tree_[v].id;\n\
    \    }\n    inline bool connect(u32 v) const noexcept {\n        assert(v < size());\n\
    \        return v == root_ or tree_[v].exist();\n    }\n    inline const Weight&\
    \ dist(u32 v) const noexcept {\n        assert(v < size());\n        return dist_[v];\n\
    \    }\n\n    const Weight& operator[](u32 v) const noexcept {\n        assert(v\
    \ < size());\n        return dist_[v];\n    }\n\n    bool relax(u32 from, u32\
    \ to, const Weight& weight, u32 id) {\n        if (dist_[to] > dist_[from] + weight)\
    \ {\n            dist_[to] = dist_[from] + weight;\n            tree_[to].parent\
    \ = from;\n            tree_[to].id = id;\n            return true;\n        }\n\
    \        return false;\n    }\n\n    std::vector<u32> pathV(u32 v) {\n       \
    \ assert(v < size());\n        assert(connect(v));\n        std::vector<u32> res(1);\n\
    \        res[0] = v;\n        while (parent(v) != invalid()) {\n            v\
    \ = parent(v);\n            res.emplace_back(v);\n        }\n        std::reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n\n    std::vector<E> pathE(u32 v) {\n\
    \        assert(v < size());\n        assert(connect(v));\n        std::vector<E>\
    \ res;\n        while (v != root()) {\n            res.emplace_back(tree_[v]);\n\
    \            v = parent(v);\n        }\n        std::reverse(res.begin(), res.end());\n\
    \        return res;\n    }\n};\n\n} // namespace internal\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"./Edge.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <type_traits>\n#include\
    \ <vector>\n\nnamespace zawa {\n\nnamespace internal {\n\ntemplate <class Weight>\n\
    class WeightedShortestPathTree {\npublic:\n    static_assert(std::is_unsigned_v<Weight>,\
    \ \"Dijkstra's Algorithm only be work well by unsigned weight\");\n    using E\
    \ = WeightedEdge<Weight>;\n    static constexpr u32 invalid() noexcept {\n   \
    \     return E::invalid();\n    }\nprivate:\n    static constexpr u32 INVALID{E::invalid()};\n\
    \    usize n_;\n    u32 root_;\n    std::vector<E> tree_;\n    std::vector<Weight>\
    \ dist_;\npublic:\n    WeightedShortestPathTree() = default;\n    WeightedShortestPathTree(u32\
    \ n, u32 root) \n        : n_{n}, root_{root}, tree_(n), dist_(n, static_cast<Weight>(-1))\
    \ {\n        assert(root < n);\n        tree_.shrink_to_fit();\n        dist_.shrink_to_fit();\n\
    \        dist_[root] = Weight{};\n    }\n\n    inline usize size() const noexcept\
    \ {\n        return n_;\n    }\n    inline u32 root() const noexcept {\n     \
    \   return root_;\n    }\n    inline u32 parent(u32 v) const noexcept {\n    \
    \    assert(v < size());\n        return tree_[v].parent;\n    }\n    inline u32\
    \ id(u32 v) const noexcept {\n        assert(v < size());\n        return tree_[v].id;\n\
    \    }\n    inline bool connect(u32 v) const noexcept {\n        assert(v < size());\n\
    \        return v == root_ or tree_[v].exist();\n    }\n    inline const Weight&\
    \ dist(u32 v) const noexcept {\n        assert(v < size());\n        return dist_[v];\n\
    \    }\n\n    const Weight& operator[](u32 v) const noexcept {\n        assert(v\
    \ < size());\n        return dist_[v];\n    }\n\n    bool relax(u32 from, u32\
    \ to, const Weight& weight, u32 id) {\n        if (dist_[to] > dist_[from] + weight)\
    \ {\n            dist_[to] = dist_[from] + weight;\n            tree_[to].parent\
    \ = from;\n            tree_[to].id = id;\n            return true;\n        }\n\
    \        return false;\n    }\n\n    std::vector<u32> pathV(u32 v) {\n       \
    \ assert(v < size());\n        assert(connect(v));\n        std::vector<u32> res(1);\n\
    \        res[0] = v;\n        while (parent(v) != invalid()) {\n            v\
    \ = parent(v);\n            res.emplace_back(v);\n        }\n        std::reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n\n    std::vector<E> pathE(u32 v) {\n\
    \        assert(v < size());\n        assert(connect(v));\n        std::vector<E>\
    \ res;\n        while (v != root()) {\n            res.emplace_back(tree_[v]);\n\
    \            v = parent(v);\n        }\n        std::reverse(res.begin(), res.end());\n\
    \        return res;\n    }\n};\n\n} // namespace internal\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Graph/ShortestPath/Edge.hpp
  isVerificationFile: false
  path: Src/Graph/ShortestPath/WeightedShortestPathTree.hpp
  requiredBy:
  - Src/Graph/ShortestPath/Dijkstra.hpp
  timestamp: '2023-12-14 22:32:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/2872.test.cpp
  - Test/Manual/abc252_e.test.cpp
  - Test/LC/shortest_path.test.cpp
documentation_of: Src/Graph/ShortestPath/WeightedShortestPathTree.hpp
layout: document
redirect_from:
- /library/Src/Graph/ShortestPath/WeightedShortestPathTree.hpp
- /library/Src/Graph/ShortestPath/WeightedShortestPathTree.hpp.html
title: Src/Graph/ShortestPath/WeightedShortestPathTree.hpp
---