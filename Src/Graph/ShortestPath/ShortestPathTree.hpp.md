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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc168_d.test.cpp
    title: Test/Manual/abc168_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc271_d.test.cpp
    title: Test/Manual/abc271_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/ShortestPath/ShortestPathTree.hpp\"\n\n#line 2\
    \ \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\n\
    namespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Graph/ShortestPath/ShortestPathTree.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace zawa\
    \ {\n\nnamespace internal {\n\nclass Edge {\nprotected:\n    static constexpr\
    \ u32 INVALID{static_cast<u32>(-1)};\npublic:\n    u32 parent{INVALID}; \n   \
    \ u32 id{INVALID};\n    Edge() = default;\n    Edge(u32 parent, u32 id) : parent{parent},\
    \ id{id} {}\n    Edge& operator=(const Edge& edge) {\n        parent = edge.parent;\n\
    \        id = edge.id;\n        return *this;\n    }\n    inline bool exist()\
    \ const noexcept {\n        return parent != INVALID;\n    }\n    static constexpr\
    \ u32 invalid() noexcept {\n        return INVALID; \n    }\n};\n\nclass ShortestPathTree\
    \ {\npublic:\n    using E = internal::Edge;\n    static constexpr u32 invalid()\
    \ noexcept {\n        return E::invalid();\n    }\nprotected:\n    static constexpr\
    \ u32 INVALID{E::invalid()};\n    usize n_;\n    u32 root_;\n    std::vector<E>\
    \ tree_;\n    std::vector<u32> dist_;\npublic:\n    ShortestPathTree() = default;\n\
    \    ShortestPathTree(usize n, u32 root) : n_{n}, root_{root}, tree_(n), dist_(n,\
    \ INVALID) {\n        assert(root < n);\n        tree_.shrink_to_fit();\n    \
    \    dist_.shrink_to_fit();\n        dist_[root] = 0;\n    }\n\n    inline usize\
    \ size() const noexcept {\n        return n_;\n    }\n    inline u32 parent(u32\
    \ v) const noexcept {\n        assert(v < size());\n        return tree_[v].parent;\n\
    \    }\n    inline u32 id(u32 v) const noexcept {\n        assert(v < size());\n\
    \        return tree_[v].id;\n    }\n    inline bool connect(u32 v) const noexcept\
    \ {\n        assert(v < size());\n        return tree_[v].exist();\n    }\n  \
    \  inline u32 dist(u32 v) const noexcept {\n        assert(v < size());\n    \
    \    return dist_[v];\n    }\n\n    u32 operator[](u32 v) const noexcept {\n \
    \       assert(v < size());\n        return dist_[v];\n    }\n\n    bool relax(u32\
    \ from, u32 to, u32 id) {\n        if (dist_[to] > dist_[from] + 1) {\n      \
    \      dist_[to] = dist_[from] + 1;\n            tree_[to].parent = from;\n  \
    \          tree_[to].id = id;\n            return true;\n        }\n        return\
    \ false;\n    }\n\n    std::vector<u32> pathV(u32 v) {\n        assert(v < size());\n\
    \        assert(connect(v));\n        std::vector<u32> res(dist(v) + 1);\n   \
    \     res[dist(v)] = v;\n        for (u32 i{dist(v)} ; i-- ; ) {\n           \
    \ v = parent(v);\n            res[i] = v;\n        }\n        return res;\n  \
    \  }\n    \n    std::vector<E> pathE(u32 v) {\n        assert(v < size());\n \
    \       assert(connect(v));\n        std::vector<E> res(dist(v));\n        for\
    \ (u32 i{dist(v)} ; i-- ; ) {\n            res[i] = tree_[v];\n            v =\
    \ parent(v);\n        }\n        return res;\n    }\n};\n\n} // namespace internal\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\nnamespace zawa {\n\nnamespace internal\
    \ {\n\nclass Edge {\nprotected:\n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n\
    public:\n    u32 parent{INVALID}; \n    u32 id{INVALID};\n    Edge() = default;\n\
    \    Edge(u32 parent, u32 id) : parent{parent}, id{id} {}\n    Edge& operator=(const\
    \ Edge& edge) {\n        parent = edge.parent;\n        id = edge.id;\n      \
    \  return *this;\n    }\n    inline bool exist() const noexcept {\n        return\
    \ parent != INVALID;\n    }\n    static constexpr u32 invalid() noexcept {\n \
    \       return INVALID; \n    }\n};\n\nclass ShortestPathTree {\npublic:\n   \
    \ using E = internal::Edge;\n    static constexpr u32 invalid() noexcept {\n \
    \       return E::invalid();\n    }\nprotected:\n    static constexpr u32 INVALID{E::invalid()};\n\
    \    usize n_;\n    u32 root_;\n    std::vector<E> tree_;\n    std::vector<u32>\
    \ dist_;\npublic:\n    ShortestPathTree() = default;\n    ShortestPathTree(usize\
    \ n, u32 root) : n_{n}, root_{root}, tree_(n), dist_(n, INVALID) {\n        assert(root\
    \ < n);\n        tree_.shrink_to_fit();\n        dist_.shrink_to_fit();\n    \
    \    dist_[root] = 0;\n    }\n\n    inline usize size() const noexcept {\n   \
    \     return n_;\n    }\n    inline u32 parent(u32 v) const noexcept {\n     \
    \   assert(v < size());\n        return tree_[v].parent;\n    }\n    inline u32\
    \ id(u32 v) const noexcept {\n        assert(v < size());\n        return tree_[v].id;\n\
    \    }\n    inline bool connect(u32 v) const noexcept {\n        assert(v < size());\n\
    \        return tree_[v].exist();\n    }\n    inline u32 dist(u32 v) const noexcept\
    \ {\n        assert(v < size());\n        return dist_[v];\n    }\n\n    u32 operator[](u32\
    \ v) const noexcept {\n        assert(v < size());\n        return dist_[v];\n\
    \    }\n\n    bool relax(u32 from, u32 to, u32 id) {\n        if (dist_[to] >\
    \ dist_[from] + 1) {\n            dist_[to] = dist_[from] + 1;\n            tree_[to].parent\
    \ = from;\n            tree_[to].id = id;\n            return true;\n        }\n\
    \        return false;\n    }\n\n    std::vector<u32> pathV(u32 v) {\n       \
    \ assert(v < size());\n        assert(connect(v));\n        std::vector<u32> res(dist(v)\
    \ + 1);\n        res[dist(v)] = v;\n        for (u32 i{dist(v)} ; i-- ; ) {\n\
    \            v = parent(v);\n            res[i] = v;\n        }\n        return\
    \ res;\n    }\n    \n    std::vector<E> pathE(u32 v) {\n        assert(v < size());\n\
    \        assert(connect(v));\n        std::vector<E> res(dist(v));\n        for\
    \ (u32 i{dist(v)} ; i-- ; ) {\n            res[i] = tree_[v];\n            v =\
    \ parent(v);\n        }\n        return res;\n    }\n};\n\n} // namespace internal\n\
    \n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/ShortestPath/ShortestPathTree.hpp
  requiredBy:
  - Src/Graph/ShortestPath/BFS.hpp
  timestamp: '2023-12-14 17:56:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Manual/abc168_d.test.cpp
  - Test/Manual/abc271_d.test.cpp
documentation_of: Src/Graph/ShortestPath/ShortestPathTree.hpp
layout: document
redirect_from:
- /library/Src/Graph/ShortestPath/ShortestPathTree.hpp
- /library/Src/Graph/ShortestPath/ShortestPathTree.hpp.html
title: Src/Graph/ShortestPath/ShortestPathTree.hpp
---
