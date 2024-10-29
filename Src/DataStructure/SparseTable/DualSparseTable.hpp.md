---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2559.test.cpp
    title: Test/AOJ/2559.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/SparseTable/DualSparseTable.hpp\"\n\n\
    #line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace Concept {\n\ntemplate\
    \ <class T>\nconcept Monoid = requires {\n    typename T::Element;\n    { T::identity()\
    \ } -> std::same_as<typename T::Element>;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SparseTable/DualSparseTable.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n\nnamespace zawa {\n\ntemplate <Concept::Monoid\
    \ S>\nclass DualSparseTable {\npublic:\n    using Value = typename S::Element;\n\
    \n    DualSparseTable() = default;\n    \n    DualSparseTable(const std::vector<Value>&\
    \ A)\n        : n_{A.size()}, L_(A.size() + 1), dat_{} {\n        \n        assert(A.size());\n\
    \        for (u32 i{1} ; i < L_.size() ; i++) {\n            L_[i] = L_[i - 1]\
    \ + (i >> (L_[i - 1] + 1));\n        }\n        dat_ = std::vector(L_.back() +\
    \ 1, std::vector(A.size(), S::identity()));\n        dat_[0] = A;\n    }\n\n \
    \   void operation(u32 L, u32 R, const Value& v) {\n        assert(L <= R and\
    \ R <= size());\n        if (L == R) {\n            return;\n        }\n     \
    \   else if (L + 1 == R) {\n            dat_[0][L] = S::operation(dat_[0][L],\
    \ v);\n        }\n        else {\n            u32 now{L_[R - L]};\n          \
    \  dat_[now][L] = S::operation(dat_[now][L], v);\n            dat_[now][R - (1\
    \ << now)] = S::operation(dat_[now][R - (1 << now)], v);\n        }\n    }\n\n\
    \    constexpr usize size() const {\n        return n_;\n    }\n\n    std::vector<Value>\
    \ build() {\n        assert(dat_.size() >= 2u);\n        for (u32 i{static_cast<u32>(dat_.size())\
    \ - 2u} ; i + 1 < dat_.size() ; i--) {\n            for (u32 j{} ; j + (1 << i)\
    \ < size() ; j++) {\n                dat_[i][j] = S::operation(dat_[i][j], dat_[i\
    \ + 1][j]);\n                dat_[i][j + (1 << i)] = S::operation(dat_[i][j +\
    \ (1 << i)], dat_[i + 1][j]);\n            }\n        }\n        return dat_[0];\n\
    \    }\n\nprivate:\n    \n    usize n_{};\n    std::vector<u32> L_;\n    std::vector<std::vector<Value>>\
    \ dat_{};\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n\nnamespace zawa {\n\ntemplate <Concept::Monoid\
    \ S>\nclass DualSparseTable {\npublic:\n    using Value = typename S::Element;\n\
    \n    DualSparseTable() = default;\n    \n    DualSparseTable(const std::vector<Value>&\
    \ A)\n        : n_{A.size()}, L_(A.size() + 1), dat_{} {\n        \n        assert(A.size());\n\
    \        for (u32 i{1} ; i < L_.size() ; i++) {\n            L_[i] = L_[i - 1]\
    \ + (i >> (L_[i - 1] + 1));\n        }\n        dat_ = std::vector(L_.back() +\
    \ 1, std::vector(A.size(), S::identity()));\n        dat_[0] = A;\n    }\n\n \
    \   void operation(u32 L, u32 R, const Value& v) {\n        assert(L <= R and\
    \ R <= size());\n        if (L == R) {\n            return;\n        }\n     \
    \   else if (L + 1 == R) {\n            dat_[0][L] = S::operation(dat_[0][L],\
    \ v);\n        }\n        else {\n            u32 now{L_[R - L]};\n          \
    \  dat_[now][L] = S::operation(dat_[now][L], v);\n            dat_[now][R - (1\
    \ << now)] = S::operation(dat_[now][R - (1 << now)], v);\n        }\n    }\n\n\
    \    constexpr usize size() const {\n        return n_;\n    }\n\n    std::vector<Value>\
    \ build() {\n        assert(dat_.size() >= 2u);\n        for (u32 i{static_cast<u32>(dat_.size())\
    \ - 2u} ; i + 1 < dat_.size() ; i--) {\n            for (u32 j{} ; j + (1 << i)\
    \ < size() ; j++) {\n                dat_[i][j] = S::operation(dat_[i][j], dat_[i\
    \ + 1][j]);\n                dat_[i][j + (1 << i)] = S::operation(dat_[i][j +\
    \ (1 << i)], dat_[i + 1][j]);\n            }\n        }\n        return dat_[0];\n\
    \    }\n\nprivate:\n    \n    usize n_{};\n    std::vector<u32> L_;\n    std::vector<std::vector<Value>>\
    \ dat_{};\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  isVerificationFile: false
  path: Src/DataStructure/SparseTable/DualSparseTable.hpp
  requiredBy: []
  timestamp: '2024-10-29 23:39:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/2559.test.cpp
documentation_of: Src/DataStructure/SparseTable/DualSparseTable.hpp
layout: document
title: Dual Sparse Table
---

区間更新が何回か来た後、取得クエリがあるようなやつに使える。当然だが、スパーステーブルなので等冪則が成り立つ演算でないと壊れる。

vectorで初期化、operation(l, r, v)で区間更新, buildで全要素取得。

初期化, buildが $O(n\log n)$ 、operationが $O(1)$
