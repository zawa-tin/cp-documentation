---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc267_f.test.cpp
    title: Test/Manual/abc267_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/LevelAncestor.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Tree/LevelAncestor.hpp\"\n\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n\nnamespace zawa {\n\nclass\
    \ LevelAncestor {\nprivate:\n    usize n_{};\n    u32 root_{};\n    std::vector<std::vector<u32>>\
    \ tree_;\n    std::vector<std::vector<u32>> jump_;\n    std::vector<u32> depth_;\n\
    \n    static constexpr u32 invalid_{static_cast<u32>(-1)};\n    static constexpr\
    \ u32 ceilLog2(u32 n) noexcept {\n        assert(n or !\"empty graph is not allowed\"\
    );\n        return 32 - __builtin_clz(n);\n    }\n\npublic:\n    constexpr usize\
    \ size() const noexcept {\n        return n_;\n    }\n\n    u32 log() const noexcept\
    \ {\n        return jump_.size();\n    }\n\n    const u32& depth(u32 v) const\
    \ noexcept {\n        assert(v < size());\n        return depth_[v];\n    }\n\n\
    \    static constexpr u32 invalid() noexcept {\n        return invalid_;\n   \
    \ }\n\n    static constexpr bool invalid(usize v) noexcept {\n        return v\
    \ == invalid_;\n    }\n\n    constexpr u32 root() const noexcept {\n        return\
    \ root_;\n    }\n\nprivate:\n\n    void dfs(u32 v, u32 p) {\n        depth_[v]\
    \ = (invalid(p) ? invalid_ : depth_[p]) + 1;\n        jump_[0][v] = (invalid(p)\
    \ ? v : p);\n        for (u32 i{} ; i + 1 < log() ; i++) {\n            jump_[i\
    \ + 1][v] = jump_[i][jump_[i][v]];\n        }\n        for (auto x : tree_[v])\
    \ if (x != p) {\n            assert(invalid(depth_[x]) or !\"given graph is not\
    \ tree\");\n            dfs(x, v);\n        }\n    }\n\npublic:\n    LevelAncestor()\
    \ = default;\n    LevelAncestor(usize n, u32 root = 0)\n        : n_{n}, root_{root},\
    \ tree_(n), jump_(ceilLog2(n), std::vector<u32>(n)), depth_(n, invalid_) {}\n\
    \    LevelAncestor(const std::vector<std::vector<u32>>& tree, u32 root = 0) \n\
    \        : n_{tree.size()}, root_{root}, tree_{tree}, jump_(ceilLog2(n_), std::vector<u32>(n_)),\
    \ depth_(n_, invalid_) {\n        build();\n    }\n\n    void addEdge(usize u,\
    \ usize v) {\n        assert(u < size());\n        assert(v < size());\n     \
    \   tree_[u].emplace_back(v);\n        tree_[v].emplace_back(u);\n    }\n\n  \
    \  void build() {\n        dfs(root(), invalid_);\n    }\n\n    usize lca(usize\
    \ u, usize v) const {\n        if (depth(u) > depth(v)) std::swap(u, v);\n   \
    \     for (u32 i{log()} ; i-- ; ) {\n            if ((depth(v) - depth(u)) & (1u\
    \ << i)) {\n                v = jump_[i][v];\n            }\n        }\n     \
    \   if (u == v) return u;\n        for (u32 i{log()} ; i-- ; ) {\n           \
    \ if (jump_[i][u] != jump_[i][v]) {\n                u = jump_[i][u];\n      \
    \          v = jump_[i][v];\n            }\n        }\n        return jump_[0][u];\n\
    \    }\n\n    u32 operator()(u32 v, u32 up) const {\n        assert(v < size());\n\
    \        if (depth(v) < up) return invalid();\n        if (depth(v) == up) return\
    \ root();\n        for (u32 i{log()} ; i-- ; ) {\n            if (up & (1u <<\
    \ i)) {\n                up ^= (1u << i);\n                v = jump_[i][v];\n\
    \            }\n        }\n        return v;\n    }\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\nclass LevelAncestor\
    \ {\nprivate:\n    usize n_{};\n    u32 root_{};\n    std::vector<std::vector<u32>>\
    \ tree_;\n    std::vector<std::vector<u32>> jump_;\n    std::vector<u32> depth_;\n\
    \n    static constexpr u32 invalid_{static_cast<u32>(-1)};\n    static constexpr\
    \ u32 ceilLog2(u32 n) noexcept {\n        assert(n or !\"empty graph is not allowed\"\
    );\n        return 32 - __builtin_clz(n);\n    }\n\npublic:\n    constexpr usize\
    \ size() const noexcept {\n        return n_;\n    }\n\n    u32 log() const noexcept\
    \ {\n        return jump_.size();\n    }\n\n    const u32& depth(u32 v) const\
    \ noexcept {\n        assert(v < size());\n        return depth_[v];\n    }\n\n\
    \    static constexpr u32 invalid() noexcept {\n        return invalid_;\n   \
    \ }\n\n    static constexpr bool invalid(usize v) noexcept {\n        return v\
    \ == invalid_;\n    }\n\n    constexpr u32 root() const noexcept {\n        return\
    \ root_;\n    }\n\nprivate:\n\n    void dfs(u32 v, u32 p) {\n        depth_[v]\
    \ = (invalid(p) ? invalid_ : depth_[p]) + 1;\n        jump_[0][v] = (invalid(p)\
    \ ? v : p);\n        for (u32 i{} ; i + 1 < log() ; i++) {\n            jump_[i\
    \ + 1][v] = jump_[i][jump_[i][v]];\n        }\n        for (auto x : tree_[v])\
    \ if (x != p) {\n            assert(invalid(depth_[x]) or !\"given graph is not\
    \ tree\");\n            dfs(x, v);\n        }\n    }\n\npublic:\n    LevelAncestor()\
    \ = default;\n    LevelAncestor(usize n, u32 root = 0)\n        : n_{n}, root_{root},\
    \ tree_(n), jump_(ceilLog2(n), std::vector<u32>(n)), depth_(n, invalid_) {}\n\
    \    LevelAncestor(const std::vector<std::vector<u32>>& tree, u32 root = 0) \n\
    \        : n_{tree.size()}, root_{root}, tree_{tree}, jump_(ceilLog2(n_), std::vector<u32>(n_)),\
    \ depth_(n_, invalid_) {\n        build();\n    }\n\n    void addEdge(usize u,\
    \ usize v) {\n        assert(u < size());\n        assert(v < size());\n     \
    \   tree_[u].emplace_back(v);\n        tree_[v].emplace_back(u);\n    }\n\n  \
    \  void build() {\n        dfs(root(), invalid_);\n    }\n\n    usize lca(usize\
    \ u, usize v) const {\n        if (depth(u) > depth(v)) std::swap(u, v);\n   \
    \     for (u32 i{log()} ; i-- ; ) {\n            if ((depth(v) - depth(u)) & (1u\
    \ << i)) {\n                v = jump_[i][v];\n            }\n        }\n     \
    \   if (u == v) return u;\n        for (u32 i{log()} ; i-- ; ) {\n           \
    \ if (jump_[i][u] != jump_[i][v]) {\n                u = jump_[i][u];\n      \
    \          v = jump_[i][v];\n            }\n        }\n        return jump_[0][u];\n\
    \    }\n\n    u32 operator()(u32 v, u32 up) const {\n        assert(v < size());\n\
    \        if (depth(v) < up) return invalid();\n        if (depth(v) == up) return\
    \ root();\n        for (u32 i{log()} ; i-- ; ) {\n            if (up & (1u <<\
    \ i)) {\n                up ^= (1u << i);\n                v = jump_[i][v];\n\
    \            }\n        }\n        return v;\n    }\n\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/LevelAncestor.hpp
  requiredBy: []
  timestamp: '2023-12-05 04:56:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Manual/abc267_f.test.cpp
documentation_of: Src/Graph/Tree/LevelAncestor.hpp
layout: document
redirect_from:
- /library/Src/Graph/Tree/LevelAncestor.hpp
- /library/Src/Graph/Tree/LevelAncestor.hpp.html
title: Src/Graph/Tree/LevelAncestor.hpp
---
