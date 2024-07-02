---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/ChminMonoid.hpp
    title: Src/Algebra/Monoid/ChminMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SparseTable/SparseTable.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/Tree.hpp
    title: Src/Graph/Tree/Tree.hpp
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
    using usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/ChminMonoid.hpp\"\
    \n\n#line 4 \"Src/Algebra/Monoid/ChminMonoid.hpp\"\n\n#include <algorithm>\n#include\
    \ <optional>\n\nnamespace zawa {\n\ntemplate <class T, class U>\nclass ChminMonoidData\
    \ {\nprivate:\n    std::optional<T> priority_{};\n    U value_{};\npublic:\n \
    \   ChminMonoidData() = default;\n    ChminMonoidData(const U& value)\n      \
    \  : priority_{std::nullopt}, value_{value} {}\n    ChminMonoidData(const T& priority,\
    \ const U& value)\n        : priority_{priority}, value_{value} {}\n\n    constexpr\
    \ bool infty() const noexcept {\n        return !priority_.has_value();\n    }\n\
    \    constexpr const T& priority() const noexcept {\n        return priority_.value();\n\
    \    }\n    constexpr const U& value() const noexcept {\n        return value_;\n\
    \    }\n    friend constexpr bool operator<(const ChminMonoidData& l, const ChminMonoidData&\
    \ r) {\n        if (l.infty()) return false;\n        else if (r.infty()) return\
    \ true;\n        else return l.priority() < r.priority();\n    }\n};\n\ntemplate\
    \ <class T, class U>\nstruct ChminMonoid {\n    using Element = ChminMonoidData<T,\
    \ U>;\n    static Element identity() noexcept {\n        return Element{};\n \
    \   }\n    // \u30BF\u30A4\u30D6\u30EC\u30FC\u30AF\u306Fl\u5074\u3092\u512A\u5148\
    \u3059\u308B\u3088\u3046\u306B\u306A\u3063\u3066\u3044\u308B\u3002\n    static\
    \ Element operation(const Element& l, const Element& r) noexcept {\n        return\
    \ (r < l ? r : l);\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\
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
    #line 2 \"Src/Graph/Tree/Tree.hpp\"\n\n#line 4 \"Src/Graph/Tree/Tree.hpp\"\n\n\
    #line 6 \"Src/Graph/Tree/Tree.hpp\"\n\nnamespace zawa {\n\nusing Tree = std::vector<std::vector<u32>>;\n\
    \nvoid AddEdge(Tree& T, u32 u, u32 v) {\n    T[u].emplace_back(v);\n    T[v].emplace_back(u);\n\
    }\n\nvoid AddDirectedEdge(Tree& T, u32 from, u32 to) {\n    T[from].emplace_back(to);\n\
    }\n\n} // namespace zawa\n#line 7 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\n\
    \n#line 10 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\n\nnamespace zawa {\n\n\
    class LowestCommonAncestor {\nprivate:\n    using Monoid = ChminMonoid<u32, u32>;\n\
    \npublic:\n    LowestCommonAncestor() = default;\n\n    LowestCommonAncestor(const\
    \ Tree& tree, u32 r = 0u) \n        : n_{tree.size()}, depth_(tree.size()), L_(tree.size()),\
    \ R_(tree.size()), st_{} {\n            std::vector<Monoid::Element> init;\n \
    \           init.reserve(2 * size());\n            auto dfs{[&](auto dfs, u32\
    \ v, u32 p) -> void {\n                depth_[v] = (p == INVALID ? 0u : depth_[p]\
    \ + 1);\n                L_[v] = (u32)init.size();\n                for (auto\
    \ x : tree[v]) {\n                    if (x == p) {\n                        continue;\n\
    \                    }\n                    init.emplace_back(depth_[v], v);\n\
    \                    dfs(dfs, x, v);\n                }\n                R_[v]\
    \ = (u32)init.size();\n            }};\n            dfs(dfs, r, INVALID);\n  \
    \          st_ = SparseTable<Monoid>(init);\n    }\n\n    u32 operator()(u32 u,\
    \ u32 v) const {\n        assert(verify(u));\n        assert(verify(v));\n   \
    \     if (L_[u] > L_[v]) {\n            std::swap(u, v);\n        }\n        return\
    \ st_.product(L_[u], R_[v]).value();\n    }\n\n    inline u32 depth(u32 v) const\
    \ noexcept {\n        assert(verify(v));\n        return depth_[v];\n    }\n\n\
    \    u32 distance(u32 u, u32 v) const {\n        assert(verify(u));\n        assert(verify(v));\n\
    \        return depth(u) + depth(v) - 2u * depth((*this)(u, v));\n    }\n\n  \
    \  bool isAncestor(u32 p, u32 v) const {\n        assert(verify(p));\n       \
    \ assert(verify(v));\n        return L_[p] <= L_[v] and R_[v] <= R_[p];\n    }\n\
    \nprivate:\n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n    usize\
    \ n_{};\n    std::vector<u32> depth_, L_, R_;\n    SparseTable<Monoid> st_;\n\n\
    \    inline usize size() const {\n        return n_;\n    }\n\n    inline bool\
    \ verify(u32 v) const {\n        return v < size();\n    }\n};\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Monoid/ChminMonoid.hpp\"\
    \n#include \"../../DataStructure/SparseTable/SparseTable.hpp\"\n#include \"./Tree.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\nnamespace zawa {\n\nclass LowestCommonAncestor\
    \ {\nprivate:\n    using Monoid = ChminMonoid<u32, u32>;\n\npublic:\n    LowestCommonAncestor()\
    \ = default;\n\n    LowestCommonAncestor(const Tree& tree, u32 r = 0u) \n    \
    \    : n_{tree.size()}, depth_(tree.size()), L_(tree.size()), R_(tree.size()),\
    \ st_{} {\n            std::vector<Monoid::Element> init;\n            init.reserve(2\
    \ * size());\n            auto dfs{[&](auto dfs, u32 v, u32 p) -> void {\n   \
    \             depth_[v] = (p == INVALID ? 0u : depth_[p] + 1);\n             \
    \   L_[v] = (u32)init.size();\n                for (auto x : tree[v]) {\n    \
    \                if (x == p) {\n                        continue;\n          \
    \          }\n                    init.emplace_back(depth_[v], v);\n         \
    \           dfs(dfs, x, v);\n                }\n                R_[v] = (u32)init.size();\n\
    \            }};\n            dfs(dfs, r, INVALID);\n            st_ = SparseTable<Monoid>(init);\n\
    \    }\n\n    u32 operator()(u32 u, u32 v) const {\n        assert(verify(u));\n\
    \        assert(verify(v));\n        if (L_[u] > L_[v]) {\n            std::swap(u,\
    \ v);\n        }\n        return st_.product(L_[u], R_[v]).value();\n    }\n\n\
    \    inline u32 depth(u32 v) const noexcept {\n        assert(verify(v));\n  \
    \      return depth_[v];\n    }\n\n    u32 distance(u32 u, u32 v) const {\n  \
    \      assert(verify(u));\n        assert(verify(v));\n        return depth(u)\
    \ + depth(v) - 2u * depth((*this)(u, v));\n    }\n\n    bool isAncestor(u32 p,\
    \ u32 v) const {\n        assert(verify(p));\n        assert(verify(v));\n   \
    \     return L_[p] <= L_[v] and R_[v] <= R_[p];\n    }\n\nprivate:\n    static\
    \ constexpr u32 INVALID{static_cast<u32>(-1)};\n    usize n_{};\n    std::vector<u32>\
    \ depth_, L_, R_;\n    SparseTable<Monoid> st_;\n\n    inline usize size() const\
    \ {\n        return n_;\n    }\n\n    inline bool verify(u32 v) const {\n    \
    \    return v < size();\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/ChminMonoid.hpp
  - Src/DataStructure/SparseTable/SparseTable.hpp
  - Src/Graph/Tree/Tree.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/LowestCommonAncestor.hpp
  requiredBy: []
  timestamp: '2024-07-02 09:57:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/lca.test.cpp
documentation_of: Src/Graph/Tree/LowestCommonAncestor.hpp
layout: document
title: Lowest Common Ancestor
---

## 概要

関数オブジェクトの様になっています。 `operator()(usize u, usize v)`で`u`と`v`のLCAが求まります。

## ライブラリの使い方

コンストラクタで `Tree` と根の頂点番号を与えること。頂点番号を指定しなかった場合は頂点 $0$ を根として構築する。
