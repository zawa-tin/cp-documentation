---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc308_g.test.cpp
    title: Test/AtCoder/abc308_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF956-F.test.cpp
    title: Test/CF/CF956-F.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/Other/SortedAdjacentProduct.hpp\"\n\n\
    #include <cassert>\n#include <iterator>\n#include <set>\n#include <utility>\n\n\
    #line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 9 \"Src/DataStructure/Other/SortedAdjacentProduct.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class S>\nclass SortedAdjacentProduct {\npublic:\n\
    \    using V = typename S::Element;\n    using Iterator = typename std::multiset<V>::const_iterator;\n\
    \n    SortedAdjacentProduct() = default;\n\n    SortedAdjacentProduct(const SortedAdjacentProduct<S>&\
    \ sap) \n        : set_{sap.set_}, adj_{sap.adj_} {}\n\n    SortedAdjacentProduct(SortedAdjacentProduct<S>&&\
    \ sap)\n        : set_{std::move(sap.set_)}, adj_{std::move(sap.adj_)} {}\n\n\
    \    inline usize size() const noexcept {\n        return set_.size();\n    }\n\
    \n    inline bool empty() const noexcept {\n        return set_.empty();\n   \
    \ }\n\n    const std::multiset<V>& set() const noexcept {\n        return set_;\n\
    \    }\n\n    const std::multiset<V>& adjacents() const noexcept {\n        return\
    \ adj_;\n    }\n\n    V min() const noexcept {\n        assert(size() >= usize{2});\n\
    \        return *adj_.cbegin();\n    }\n\n    V max() const noexcept {\n     \
    \   assert(size() >= usize(2));\n        return *adj_.crbegin();\n    }\n\n  \
    \  void insert(const V& v) {\n        Iterator it{set_.lower_bound(v)};\n    \
    \    if (it != set_.end() and it != set_.begin()) {\n            V val{S::operation(*std::prev(it),\
    \ *it)};\n            assert(eraseAdj(val));\n        }\n        if (it != set_.end())\
    \ {\n            adj_.insert(S::operation(v, *it));\n        }\n        if (it\
    \ != set_.begin()) {\n            adj_.insert(S::operation(*std::prev(it), v));\n\
    \        }\n        set_.insert(v);\n    }\n\n    void erase(const V& v) {\n \
    \       auto it{set_.lower_bound(v)};\n        assert(it != set_.end() and *it\
    \ == v);\n        if (it != set_.begin()) {\n            V val{S::operation(*std::prev(it),\
    \ *it)};\n            assert(eraseAdj(val));\n        }\n        if (std::next(it)\
    \ != set_.end()) {\n            V val{S::operation(*it, *std::next(it))};\n  \
    \          assert(eraseAdj(val));\n        }\n        if (it != set_.begin() and\
    \ std::next(it) != set_.end()) {\n            V val{S::operation(*std::prev(it),\
    \ *std::next(it))};\n            adj_.insert(val);\n        }\n        set_.erase(it);\n\
    \    }\n\n    bool contains(const V& v) {\n        return set_.find(v) != set_.end();\n\
    \    }\n\nprivate:\n    std::multiset<V> set_, adj_;\n\n    bool eraseAdj(const\
    \ V& v) {\n        auto it{adj_.find(v)};\n        bool res{it != adj_.end()};\n\
    \        if (res) adj_.erase(it);\n        return res;\n    }\n};\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include <cassert>\n#include <iterator>\n#include <set>\n\
    #include <utility>\n\n#include \"../../Template/TypeAlias.hpp\"\n\nnamespace zawa\
    \ {\n\ntemplate <class S>\nclass SortedAdjacentProduct {\npublic:\n    using V\
    \ = typename S::Element;\n    using Iterator = typename std::multiset<V>::const_iterator;\n\
    \n    SortedAdjacentProduct() = default;\n\n    SortedAdjacentProduct(const SortedAdjacentProduct<S>&\
    \ sap) \n        : set_{sap.set_}, adj_{sap.adj_} {}\n\n    SortedAdjacentProduct(SortedAdjacentProduct<S>&&\
    \ sap)\n        : set_{std::move(sap.set_)}, adj_{std::move(sap.adj_)} {}\n\n\
    \    inline usize size() const noexcept {\n        return set_.size();\n    }\n\
    \n    inline bool empty() const noexcept {\n        return set_.empty();\n   \
    \ }\n\n    const std::multiset<V>& set() const noexcept {\n        return set_;\n\
    \    }\n\n    const std::multiset<V>& adjacents() const noexcept {\n        return\
    \ adj_;\n    }\n\n    V min() const noexcept {\n        assert(size() >= usize{2});\n\
    \        return *adj_.cbegin();\n    }\n\n    V max() const noexcept {\n     \
    \   assert(size() >= usize(2));\n        return *adj_.crbegin();\n    }\n\n  \
    \  void insert(const V& v) {\n        Iterator it{set_.lower_bound(v)};\n    \
    \    if (it != set_.end() and it != set_.begin()) {\n            V val{S::operation(*std::prev(it),\
    \ *it)};\n            assert(eraseAdj(val));\n        }\n        if (it != set_.end())\
    \ {\n            adj_.insert(S::operation(v, *it));\n        }\n        if (it\
    \ != set_.begin()) {\n            adj_.insert(S::operation(*std::prev(it), v));\n\
    \        }\n        set_.insert(v);\n    }\n\n    void erase(const V& v) {\n \
    \       auto it{set_.lower_bound(v)};\n        assert(it != set_.end() and *it\
    \ == v);\n        if (it != set_.begin()) {\n            V val{S::operation(*std::prev(it),\
    \ *it)};\n            assert(eraseAdj(val));\n        }\n        if (std::next(it)\
    \ != set_.end()) {\n            V val{S::operation(*it, *std::next(it))};\n  \
    \          assert(eraseAdj(val));\n        }\n        if (it != set_.begin() and\
    \ std::next(it) != set_.end()) {\n            V val{S::operation(*std::prev(it),\
    \ *std::next(it))};\n            adj_.insert(val);\n        }\n        set_.erase(it);\n\
    \    }\n\n    bool contains(const V& v) {\n        return set_.find(v) != set_.end();\n\
    \    }\n\nprivate:\n    std::multiset<V> set_, adj_;\n\n    bool eraseAdj(const\
    \ V& v) {\n        auto it{adj_.find(v)};\n        bool res{it != adj_.end()};\n\
    \        if (res) adj_.erase(it);\n        return res;\n    }\n};\n\n} // namespace\
    \ zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/Other/SortedAdjacentProduct.hpp
  requiredBy: []
  timestamp: '2024-07-27 05:40:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc308_g.test.cpp
  - Test/CF/CF956-F.test.cpp
documentation_of: Src/DataStructure/Other/SortedAdjacentProduct.hpp
layout: document
title: "\u30BD\u30FC\u30C8\u5217\u306E\u96A3\u63A5\u4E8C\u9805\u9593\u306E\u7A4D\u3092\
  \u7BA1\u7406\u3059\u308B"
---

## 概要

多重集合$S$がある。はじめ$S$は空である。$S$に対して以下のクエリを処理できる。

- $S$に要素$x$を挿入する。
- $S$中の$x$を一つ削除する。$x\in S$が必要である。
- $S$の各要素を昇順に並べた列を$A = (A_1, A_2, \dots, A_K)$とする。$f(A_{1}, A_{2}), f(A_{2}, A_{3}), \dots, f(A_{K - 1}, A_{K})$を管理する。

現状$f$としてxorを使う場合がプロコンで出題されている。
- $\min A_{i} \oplus A_{i + 1} = \min_{u\in S, v\in S} u\oplus v$が成り立つから
