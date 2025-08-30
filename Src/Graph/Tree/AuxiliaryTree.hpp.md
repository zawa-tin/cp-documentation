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
    path: Src/Graph/Tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc340_g.test.cpp
    title: Test/AtCoder/abc340_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc359_g.test.cpp
    title: ABC359-G Sum of Tree Distance
  - icon: ':heavy_check_mark:'
    path: Test/Manual/typical90_ai.test.cpp
    title: Test/Manual/typical90_ai.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/AuxiliaryTree.hpp\"\n\n#line 2 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/ChminMonoid.hpp\"\
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
    #line 6 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\n\n#line 9 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class V>\nclass LowestCommonAncestor {\nprivate:\n\
    \    using Monoid = ChminMonoid<u32, V>;\n\npublic:\n    LowestCommonAncestor()\
    \ = default;\n\n    LowestCommonAncestor(const std::vector<std::vector<V>>& tree,\
    \ V r = V{}) \n        : n_{tree.size()}, depth_(tree.size()), L_(tree.size()),\
    \ R_(tree.size()), st_{} {\n            std::vector<typename Monoid::Element>\
    \ init;\n            init.reserve(2 * size());\n            auto dfs{[&](auto\
    \ dfs, V v, V p) -> void {\n                depth_[v] = (p == INVALID ? 0u : depth_[p]\
    \ + 1);\n                L_[v] = (u32)init.size();\n                for (auto\
    \ x : tree[v]) {\n                    if (x == p) {\n                        continue;\n\
    \                    }\n                    init.emplace_back(depth_[v], v);\n\
    \                    dfs(dfs, x, v);\n                }\n                R_[v]\
    \ = (u32)init.size();\n            }};\n            dfs(dfs, r, INVALID);\n  \
    \          st_ = SparseTable<Monoid>(init);\n    }\n\n    V operator()(V u, V\
    \ v) const {\n        assert(verify(u));\n        assert(verify(v));\n       \
    \ if (L_[u] > L_[v]) {\n            std::swap(u, v);\n        }\n        return\
    \ u == v ? u : st_.product(L_[u], R_[v]).value();\n    }\n\n    V lca(V u, V v)\
    \ const {\n        return (*this)(u, v);\n    }\n\n    inline u32 depth(V v) const\
    \ noexcept {\n        assert(verify(v));\n        return depth_[v];\n    }\n\n\
    \    u32 distance(V u, V v) const {\n        assert(verify(u));\n        assert(verify(v));\n\
    \        return depth(u) + depth(v) - 2u * depth((*this)(u, v));\n    }\n\n  \
    \  bool isAncestor(V p, V v) const {\n        assert(verify(p));\n        assert(verify(v));\n\
    \        return L_[p] <= L_[v] and R_[v] <= R_[p];\n    }\n\nprotected:\n    u32\
    \ left(V v) const noexcept {\n        return L_[v];\n    }\n\n    inline usize\
    \ size() const {\n        return n_;\n    }\n\n    inline bool verify(V v) const\
    \ {\n        return v < (V)size();\n    }\n\nprivate:\n    static constexpr V\
    \ INVALID{static_cast<V>(-1)};\n    usize n_{};\n    std::vector<u32> depth_,\
    \ L_, R_;\n    SparseTable<Monoid> st_;\n};\n\n} // namespace zawa\n#line 4 \"\
    Src/Graph/Tree/AuxiliaryTree.hpp\"\n\n#line 6 \"Src/Graph/Tree/AuxiliaryTree.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class V>\nclass AuxiliaryTree : public LowestCommonAncestor<V>\
    \ {\npublic:\n    using Super = LowestCommonAncestor<V>;\n\n    AuxiliaryTree()\
    \ = default;\n    AuxiliaryTree(const std::vector<std::vector<V>>& T, V r = 0u)\
    \ \n        : Super{ T, r }, T_(T.size()), dist_(T.size()), used_(T.size()) {}\n\
    \n    V construct(const std::vector<V>& vs) {\n        assert(vs.size());\n  \
    \      clear();\n        vs_ = vs;\n        return build();\n    }\n\n    const\
    \ std::vector<V>& operator[](V v) const {\n        assert(Super::verify(v));\n\
    \        return T_[v];\n    }\n\n    inline bool contains(V v) const {\n     \
    \   assert(Super::verify(v));\n        return used_[v];\n    }\n\n    inline u32\
    \ parentEdgeLength(V v) const {\n        assert(contains(v));\n        return\
    \ dist_[v];\n    }\n\n    std::vector<V> current() const {\n        return vs_;\n\
    \    }\n\nprivate:\n    std::vector<std::vector<V>> T_{}; \n    std::vector<V>\
    \ vs_{};\n    std::vector<u32> dist_{};\n    std::vector<bool> used_{};\n\n  \
    \  void addEdge(V p, V v) {\n        assert(Super::depth(p) < Super::depth(v));\n\
    \        T_[p].push_back(v);\n        T_[v].push_back(p);\n        dist_[v] =\
    \ Super::depth(v) - Super::depth(p);\n    }\n\n    V build() {\n        std::sort(vs_.begin(),\
    \ vs_.end(), [&](V u, V v) -> bool {\n                return Super::left(u) <\
    \ Super::left(v);\n                });\n        vs_.erase(std::unique(vs_.begin(),\
    \ vs_.end()), vs_.end());\n        usize k{vs_.size()};\n        std::vector<V>\
    \ stack;\n        stack.reserve(2u * vs_.size());\n        stack.emplace_back(vs_[0]);\n\
    \        for (usize i{} ; i + 1 < k ; i++) {\n            if (!Super::isAncestor(vs_[i],\
    \ vs_[i + 1])) {\n                V w{Super::lca(vs_[i], vs_[i + 1])};\n     \
    \           V l{stack.back()};\n                stack.pop_back();\n          \
    \      while (stack.size() and LowestCommonAncestor<V>::depth(w) < LowestCommonAncestor<V>::depth(stack.back()))\
    \ {\n                    addEdge(stack.back(), l);\n                    l = stack.back();\n\
    \                    stack.pop_back();\n                }\n                if\
    \ (stack.empty() or stack.back() != w) {\n                    stack.emplace_back(w);\n\
    \                    vs_.emplace_back(w);\n                }\n               \
    \ addEdge(w, l);\n            }\n            stack.emplace_back(vs_[i + 1]);\n\
    \        }\n        while (stack.size() > 1u) {\n            V l{stack.back()};\n\
    \            stack.pop_back();\n            addEdge(stack.back(), l);\n      \
    \  }\n        for (V v : vs_) {\n            used_[v] = true;\n        }\n   \
    \     return stack.back();\n    }\n\n    void clear() {\n        for (V v : vs_)\
    \ {\n            T_[v].clear();\n            used_[v] = false;\n            dist_[v]\
    \ = 0u;\n        }\n        vs_.clear();\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"./LowestCommonAncestor.hpp\"\n\n#include <algorithm>\n\
    \nnamespace zawa {\n\ntemplate <class V>\nclass AuxiliaryTree : public LowestCommonAncestor<V>\
    \ {\npublic:\n    using Super = LowestCommonAncestor<V>;\n\n    AuxiliaryTree()\
    \ = default;\n    AuxiliaryTree(const std::vector<std::vector<V>>& T, V r = 0u)\
    \ \n        : Super{ T, r }, T_(T.size()), dist_(T.size()), used_(T.size()) {}\n\
    \n    V construct(const std::vector<V>& vs) {\n        assert(vs.size());\n  \
    \      clear();\n        vs_ = vs;\n        return build();\n    }\n\n    const\
    \ std::vector<V>& operator[](V v) const {\n        assert(Super::verify(v));\n\
    \        return T_[v];\n    }\n\n    inline bool contains(V v) const {\n     \
    \   assert(Super::verify(v));\n        return used_[v];\n    }\n\n    inline u32\
    \ parentEdgeLength(V v) const {\n        assert(contains(v));\n        return\
    \ dist_[v];\n    }\n\n    std::vector<V> current() const {\n        return vs_;\n\
    \    }\n\nprivate:\n    std::vector<std::vector<V>> T_{}; \n    std::vector<V>\
    \ vs_{};\n    std::vector<u32> dist_{};\n    std::vector<bool> used_{};\n\n  \
    \  void addEdge(V p, V v) {\n        assert(Super::depth(p) < Super::depth(v));\n\
    \        T_[p].push_back(v);\n        T_[v].push_back(p);\n        dist_[v] =\
    \ Super::depth(v) - Super::depth(p);\n    }\n\n    V build() {\n        std::sort(vs_.begin(),\
    \ vs_.end(), [&](V u, V v) -> bool {\n                return Super::left(u) <\
    \ Super::left(v);\n                });\n        vs_.erase(std::unique(vs_.begin(),\
    \ vs_.end()), vs_.end());\n        usize k{vs_.size()};\n        std::vector<V>\
    \ stack;\n        stack.reserve(2u * vs_.size());\n        stack.emplace_back(vs_[0]);\n\
    \        for (usize i{} ; i + 1 < k ; i++) {\n            if (!Super::isAncestor(vs_[i],\
    \ vs_[i + 1])) {\n                V w{Super::lca(vs_[i], vs_[i + 1])};\n     \
    \           V l{stack.back()};\n                stack.pop_back();\n          \
    \      while (stack.size() and LowestCommonAncestor<V>::depth(w) < LowestCommonAncestor<V>::depth(stack.back()))\
    \ {\n                    addEdge(stack.back(), l);\n                    l = stack.back();\n\
    \                    stack.pop_back();\n                }\n                if\
    \ (stack.empty() or stack.back() != w) {\n                    stack.emplace_back(w);\n\
    \                    vs_.emplace_back(w);\n                }\n               \
    \ addEdge(w, l);\n            }\n            stack.emplace_back(vs_[i + 1]);\n\
    \        }\n        while (stack.size() > 1u) {\n            V l{stack.back()};\n\
    \            stack.pop_back();\n            addEdge(stack.back(), l);\n      \
    \  }\n        for (V v : vs_) {\n            used_[v] = true;\n        }\n   \
    \     return stack.back();\n    }\n\n    void clear() {\n        for (V v : vs_)\
    \ {\n            T_[v].clear();\n            used_[v] = false;\n            dist_[v]\
    \ = 0u;\n        }\n        vs_.clear();\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Graph/Tree/LowestCommonAncestor.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/ChminMonoid.hpp
  - Src/DataStructure/SparseTable/SparseTable.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/AuxiliaryTree.hpp
  requiredBy: []
  timestamp: '2024-12-07 19:29:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Manual/typical90_ai.test.cpp
  - Test/AtCoder/abc340_g.test.cpp
  - Test/AtCoder/abc359_g.test.cpp
documentation_of: Src/Graph/Tree/AuxiliaryTree.hpp
layout: document
title: "Auxiliary Tree (\u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\u306E\
  \u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\u6728\u3092\
  \u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\u6728)"
---

## 概要

無気力。実装例を見てくれ。

## ライブラリの使い方
