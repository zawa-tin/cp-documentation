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
    path: Test/LC/staticrmq/DisjointSparseTable.test.cpp
    title: Test/LC/staticrmq/DisjointSparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/SparseTable/DisjointSparseTable.hpp\"\n\
    \n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace Concept {\n\ntemplate\
    \ <class T>\nconcept Monoid = requires {\n    typename T::Element;\n    { T::identity()\
    \ } -> std::same_as<typename T::Element>;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SparseTable/DisjointSparseTable.hpp\"\
    \n\n#include <bit>\n#include <cassert>\n#line 9 \"Src/DataStructure/SparseTable/DisjointSparseTable.hpp\"\
    \n#include <vector>\n\nnamespace zawa {\n\ntemplate <Concept::Monoid M>\nclass\
    \ DisjointSparseTable {\npublic:\n\n    using V = typename M::Element;\n\n   \
    \ constexpr usize height(usize n) const {\n        return std::max(usize{1}, std::bit_width(n)\
    \ - (usize)std::has_single_bit(n));\n    }\n\n    constexpr usize msb(usize n)\
    \ const {\n        assert(n);\n        return std::bit_width(n) - 1;\n    }\n\n\
    \    DisjointSparseTable(std::vector<V>&& A) : m_table(height(A.size())) {\n \
    \       assert(A.size());\n        for (usize i = 1, w = 2 ; i < m_table.size()\
    \ ; i++, w <<= 1) {\n            m_table[i].resize(A.size());\n            for\
    \ (usize j = 0, idx = 0 ; j < A.size() ; j += w, idx++) {\n                V prod\
    \ = M::identity();\n                if (idx & 1) { // ->\n                   \
    \ usize m = std::min(A.size() - j, w);\n                    for (usize k = 0 ;\
    \ k < m ; k++) {\n                        prod = M::operation(prod, A[j + k]);\n\
    \                        m_table[i][j + k] = prod;\n                    }\n  \
    \              }\n                else { // <-\n                    usize m =\
    \ std::min(A.size(), j + w);\n                    for (usize k = m ; k-- > j ;\
    \ ) {\n                        prod = M::operation(A[k], prod);\n            \
    \            m_table[i][k] = prod;\n                    }\n                }\n\
    \            }\n        }\n        m_table[0] = std::move(A);\n    }\n\n    DisjointSparseTable(const\
    \ std::vector<V>& A) : DisjointSparseTable(std::vector<V>{A}) {}\n\n    template\
    \ <std::input_iterator It>\n    DisjointSparseTable(It first, It last) : DisjointSparseTable(std::vector(first,\
    \ last)) {}\n\n    V product(usize l, usize r) const {\n        assert(l <= r\
    \ and r <= m_table[0].size());\n        if (l == r) return M::identity();\n  \
    \      if (l + 1 == r) return m_table[0][l];\n        usize y = msb(l xor --r);\n\
    \        return M::operation(m_table[y][l], m_table[y][r]);\n    }\n\nprivate:\n\
    \n    std::vector<std::vector<V>> m_table;\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#include <bit>\n#include <cassert>\n#include <concepts>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <Concept::Monoid M>\nclass DisjointSparseTable\
    \ {\npublic:\n\n    using V = typename M::Element;\n\n    constexpr usize height(usize\
    \ n) const {\n        return std::max(usize{1}, std::bit_width(n) - (usize)std::has_single_bit(n));\n\
    \    }\n\n    constexpr usize msb(usize n) const {\n        assert(n);\n     \
    \   return std::bit_width(n) - 1;\n    }\n\n    DisjointSparseTable(std::vector<V>&&\
    \ A) : m_table(height(A.size())) {\n        assert(A.size());\n        for (usize\
    \ i = 1, w = 2 ; i < m_table.size() ; i++, w <<= 1) {\n            m_table[i].resize(A.size());\n\
    \            for (usize j = 0, idx = 0 ; j < A.size() ; j += w, idx++) {\n   \
    \             V prod = M::identity();\n                if (idx & 1) { // ->\n\
    \                    usize m = std::min(A.size() - j, w);\n                  \
    \  for (usize k = 0 ; k < m ; k++) {\n                        prod = M::operation(prod,\
    \ A[j + k]);\n                        m_table[i][j + k] = prod;\n            \
    \        }\n                }\n                else { // <-\n                \
    \    usize m = std::min(A.size(), j + w);\n                    for (usize k =\
    \ m ; k-- > j ; ) {\n                        prod = M::operation(A[k], prod);\n\
    \                        m_table[i][k] = prod;\n                    }\n      \
    \          }\n            }\n        }\n        m_table[0] = std::move(A);\n \
    \   }\n\n    DisjointSparseTable(const std::vector<V>& A) : DisjointSparseTable(std::vector<V>{A})\
    \ {}\n\n    template <std::input_iterator It>\n    DisjointSparseTable(It first,\
    \ It last) : DisjointSparseTable(std::vector(first, last)) {}\n\n    V product(usize\
    \ l, usize r) const {\n        assert(l <= r and r <= m_table[0].size());\n  \
    \      if (l == r) return M::identity();\n        if (l + 1 == r) return m_table[0][l];\n\
    \        usize y = msb(l xor --r);\n        return M::operation(m_table[y][l],\
    \ m_table[y][r]);\n    }\n\nprivate:\n\n    std::vector<std::vector<V>> m_table;\n\
    };\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  isVerificationFile: false
  path: Src/DataStructure/SparseTable/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '2025-04-15 14:25:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/staticrmq/DisjointSparseTable.test.cpp
documentation_of: Src/DataStructure/SparseTable/DisjointSparseTable.hpp
layout: document
title: Disjoint Sparse Table
---

```cpp
struct M {
    using Element = ;
    static Element identity() {

    }
    static Element operation(Element L, Element R) {

    }
};
```
