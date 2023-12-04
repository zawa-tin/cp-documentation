---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MinWithIndexMonoid.hpp
    title: Src/Algebra/Monoid/MinWithIndexMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SparseTable/SparseTable.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/lca.test.cpp
    title: Test/LC/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MinWithIndexMonoid.hpp\"\
    \n\n#line 4 \"Src/Algebra/Monoid/MinWithIndexMonoid.hpp\"\n\n#include <limits>\n\
    #include <algorithm>\n\nnamespace zawa {\n\ntemplate <class T>\nclass MinWithIndexMonoidData\
    \ {\nprivate:\n    // CHECK!! LIMIT\n    T value_{std::numeric_limits<T>::max()};\n\
    \    usize index_{}; \npublic:\n    constexpr MinWithIndexMonoidData() {}\n  \
    \  constexpr MinWithIndexMonoidData(const T& value, usize index) : value_{value},\
    \ index_{index} {}\n\n    constexpr const T& value() const noexcept {\n      \
    \  return value_;\n    } \n    T& value() noexcept {\n        return value_;\n\
    \    }\n    constexpr const usize& index() const noexcept {\n        return index_;\n\
    \    }\n    usize& index() noexcept {\n        return index_;\n    }\n};\n\ntemplate\
    \ <class T>\nstruct MinWithIndexMonoid {\n    using Element = MinWithIndexMonoidData<T>;\n\
    \    static constexpr Element identity() noexcept {\n        return Element{};\n\
    \    }\n    // CHECK!!! tie break\n    static constexpr Element operation(const\
    \ Element& lhs, const Element& rhs) noexcept {\n        return (rhs.value() <\
    \ lhs.value() ? rhs : lhs);\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\
    \n\n#line 4 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n#include <ostream>\n\nnamespace zawa {\n\ntemplate <class\
    \ Structure>\nclass SparseTable {\nprivate:\n    using Value = typename Structure::Element;\n\
    \    std::vector<u32> L;\n    std::vector<std::vector<Value>> dat;\npublic:\n\n\
    \    SparseTable() : L{}, dat{} {}\n    SparseTable(const std::vector<Value>&\
    \ a) : L(a.size() + 1), dat{} {\n        for (u32 i{1} ; i < L.size() ; i++) {\n\
    \            L[i] = L[i - 1] + (i >> (L[i - 1] + 1));\n        }\n        dat.resize(L.back()\
    \ + 1);\n        dat[0] = a;\n        for (u32 i{1}, len{2} ; i < dat.size() ;\
    \ i++, len <<= 1) {\n            dat[i] = dat[i - 1];\n            for (u32 j{}\
    \ ; j + len - 1 < dat[i].size() ; j++) {\n                dat[i][j] = Structure::operation(dat[i\
    \ - 1][j], dat[i - 1][j + (len >> 1)]);\n            }\n        }\n    }\n\n \
    \   Value product(u32 l, u32 r) const {\n        assert(l <= r);\n        assert(l\
    \ < dat[0].size());\n        assert(r <= dat[0].size());\n        u32 now{L[r\
    \ - l]};\n        return Structure::operation(dat[now][l], dat[now][r - (1 <<\
    \ now)]);\n    }\n\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ SparseTable<Structure>& spt) {\n        for (u32 i{}, len{1} ; i < spt.dat.size()\
    \ ; i++, len <<= 1) {\n            os << \"length = \" << len << '\\n';\n    \
    \        for (u32 j{} ; j + len - 1 < spt.dat[i].size() ; j++) {\n           \
    \     os << spt.dat[i][j] << (j + len == spt.dat[i].size() ? '\\n' : ' ');\n \
    \           }\n        }\n        return os;\n    }\n};\n\n} // namespace zawa\n\
    #line 6 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\n\n#line 8 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\
    \n#include <utility>\n#line 10 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\n\n\
    namespace zawa {\n\nclass LowestCommonAncestor {\nprivate:\n    using SptValue\
    \ = MinWithIndexMonoidData<u32>;\n    using Spt = SparseTable<MinWithIndexMonoid<u32>>;\n\
    \    static constexpr u32 invalid{static_cast<u32>(-1)};\n    Spt spt_{};\n  \
    \  usize n_{}, root_{};\n    std::vector<std::vector<u32>> tree_{};\n    std::vector<SptValue>\
    \ euler_{};\n    std::vector<u32> first_{}, depth_{};\n\n    void dfs(u32 v, u32\
    \ p) {\n        first_[v] = euler_.size();\n        depth_[v] = (p == invalid\
    \ ? invalid : depth_[p]) + 1;\n        euler_.emplace_back(depth_[v], v);\n  \
    \      for (auto x : tree_[v]) if (x != p) {\n            assert(first_[x] ==\
    \ invalid or !\"given graph is not tree\");\n            dfs(x, v);\n        \
    \    euler_.emplace_back(depth_[v], v);\n        }\n    }\n\npublic:\n    LowestCommonAncestor()\
    \ = default;\n    LowestCommonAncestor(u32 n, u32 root) \n        : n_{n}, root_{root},\
    \ tree_(n), euler_{}, first_(n, invalid), depth_(n) {\n        assert(n or !\"\
    empty graph is not allowed\");\n        assert(root < n);\n        euler_.reserve(2\
    \ * n - 1);\n        first_.shrink_to_fit();\n        depth_.shrink_to_fit();\n\
    \    }\n\n    constexpr u32 size() const noexcept {\n        return n_;\n    }\n\
    \n    void addEdge(usize u, usize v) {\n        assert(u < size());\n        assert(v\
    \ < size());\n        tree_[u].emplace_back(v);\n        tree_[v].emplace_back(u);\n\
    \    }\n\n    void build() {\n        dfs(root_, invalid);\n        spt_ = Spt(euler_);\n\
    \    }\n\n    u32 operator()(u32 u, u32 v) const {\n        assert(u < size());\n\
    \        assert(v < size());\n        if (first_[u] > first_[v]) std::swap(u,\
    \ v);\n        return spt_.product(first_[u], first_[v] + 1).index();\n    }\n\
    \n    u32 depth(u32 v) const noexcept {\n        assert(v < size());\n       \
    \ return depth_[v];\n    }\n\n    bool isAncestor(u32 anc, u32 child) const {\n\
    \        return (*this)(anc, child) == anc;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Monoid/MinWithIndexMonoid.hpp\"\
    \n#include \"../../DataStructure/SparseTable/SparseTable.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\nclass LowestCommonAncestor\
    \ {\nprivate:\n    using SptValue = MinWithIndexMonoidData<u32>;\n    using Spt\
    \ = SparseTable<MinWithIndexMonoid<u32>>;\n    static constexpr u32 invalid{static_cast<u32>(-1)};\n\
    \    Spt spt_{};\n    usize n_{}, root_{};\n    std::vector<std::vector<u32>>\
    \ tree_{};\n    std::vector<SptValue> euler_{};\n    std::vector<u32> first_{},\
    \ depth_{};\n\n    void dfs(u32 v, u32 p) {\n        first_[v] = euler_.size();\n\
    \        depth_[v] = (p == invalid ? invalid : depth_[p]) + 1;\n        euler_.emplace_back(depth_[v],\
    \ v);\n        for (auto x : tree_[v]) if (x != p) {\n            assert(first_[x]\
    \ == invalid or !\"given graph is not tree\");\n            dfs(x, v);\n     \
    \       euler_.emplace_back(depth_[v], v);\n        }\n    }\n\npublic:\n    LowestCommonAncestor()\
    \ = default;\n    LowestCommonAncestor(u32 n, u32 root) \n        : n_{n}, root_{root},\
    \ tree_(n), euler_{}, first_(n, invalid), depth_(n) {\n        assert(n or !\"\
    empty graph is not allowed\");\n        assert(root < n);\n        euler_.reserve(2\
    \ * n - 1);\n        first_.shrink_to_fit();\n        depth_.shrink_to_fit();\n\
    \    }\n\n    constexpr u32 size() const noexcept {\n        return n_;\n    }\n\
    \n    void addEdge(usize u, usize v) {\n        assert(u < size());\n        assert(v\
    \ < size());\n        tree_[u].emplace_back(v);\n        tree_[v].emplace_back(u);\n\
    \    }\n\n    void build() {\n        dfs(root_, invalid);\n        spt_ = Spt(euler_);\n\
    \    }\n\n    u32 operator()(u32 u, u32 v) const {\n        assert(u < size());\n\
    \        assert(v < size());\n        if (first_[u] > first_[v]) std::swap(u,\
    \ v);\n        return spt_.product(first_[u], first_[v] + 1).index();\n    }\n\
    \n    u32 depth(u32 v) const noexcept {\n        assert(v < size());\n       \
    \ return depth_[v];\n    }\n\n    bool isAncestor(u32 anc, u32 child) const {\n\
    \        return (*this)(anc, child) == anc;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MinWithIndexMonoid.hpp
  - Src/DataStructure/SparseTable/SparseTable.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/LowestCommonAncestor.hpp
  requiredBy: []
  timestamp: '2023-12-05 01:10:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/lca.test.cpp
documentation_of: Src/Graph/Tree/LowestCommonAncestor.hpp
layout: document
title: Lowest Common Ancestor
---

## 概要

関数オブジェクトの様になっています。 `operator()(usize u, usize v)`で`u`と`v`のLCAが求まります。
