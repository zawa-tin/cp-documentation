---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Action/ActionConcept.hpp
    title: Src/Algebra/Action/ActionConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
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
    \n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Action/ActionConcept.hpp\"\
    \n\n#line 4 \"Src/Algebra/Action/ActionConcept.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class G, class X>\nconcept Action = requires {\n   \
    \ typename G::Element;\n    { G::action(std::declval<typename G::Element>(), std::declval<X>())\
    \ } -> std::same_as<X>;\n};\n\n// Is appropriate name X-set?\ntemplate <class\
    \ G, class X>\nconcept Acted = requires {\n    typename G::Element;\n    { G::acted(std::declval<typename\
    \ G::Element>(), std::declval<X>()) } -> std::same_as<typename G::Element>;\n\
    };\n\n} // namespace concepts\n\n} // namespace zawa\n#line 6 \"Src/DataStructure/SparseTable/DisjointSparseTable.hpp\"\
    \n\n#include <bit>\n#include <cassert>\n#line 10 \"Src/DataStructure/SparseTable/DisjointSparseTable.hpp\"\
    \n#include <vector>\n\nnamespace zawa {\n\ntemplate <concepts::Monoid M>\nclass\
    \ DisjointSparseTable {\npublic:\n\n    using V = typename M::Element;\n\n   \
    \ constexpr usize height(usize n) const {\n        return std::max(usize{1}, std::bit_width(n)\
    \ - (usize)std::has_single_bit(n));\n    }\n\n    constexpr usize msb(usize n)\
    \ const {\n        assert(n);\n        return std::bit_width(n) - 1;\n    }\n\n\
    \    template <class S>\n    requires std::same_as<V, S> or concepts::Acted<V,\
    \ S>\n    DisjointSparseTable(const std::vector<S>& A) : m_table(height(A.size()))\
    \ {\n        assert(A.size());\n        for (usize i = 1, w = 2 ; i < m_table.size()\
    \ ; i++, w <<= 1) {\n            m_table[i].resize(A.size());\n            for\
    \ (usize j = 0, idx = 0 ; j < A.size() ; j += w, idx++) {\n                V prod\
    \ = M::identity();\n                if (idx & 1) { // ->\n                   \
    \ usize m = std::min(A.size() - j, w);\n                    for (usize k = 0 ;\
    \ k < m ; k++) {\n                        if constexpr (std::same_as<V, S>)\n\
    \                            prod = M::operation(prod, A[j + k]);\n          \
    \              else\n                            prod = M::acted(prod, A[j + k]);\n\
    \                        m_table[i][j + k] = prod;\n                    }\n  \
    \              }\n                else { // <-\n                    usize m =\
    \ std::min(A.size(), j + w);\n                    for (usize k = m ; k-- > j ;\
    \ ) {\n                        if constexpr (std::same_as<V, S>)\n           \
    \                 prod = M::operation(A[k], prod);\n                        else\n\
    \                            prod = M::acted(prod, A[k]);\n                  \
    \      m_table[i][k] = prod;\n                    }\n                }\n     \
    \       }\n        }\n        m_table[0].resize(A.size());\n        for (usize\
    \ i = 0 ; i < A.size() ; i++) {\n            if constexpr (std::same_as<V, S>)\n\
    \                m_table[0][i] = A[i];\n            else\n                m_table[0][i]\
    \ = M::acted(M::identity(), A[i]);\n        }\n    }\n\n    template <std::input_iterator\
    \ It>\n    DisjointSparseTable(It first, It last) : DisjointSparseTable(std::vector(first,\
    \ last)) {}\n\n    V product(usize l, usize r) const {\n        assert(l <= r\
    \ and r <= m_table[0].size());\n        if (l == r) return M::identity();\n  \
    \      if (l + 1 == r) return m_table[0][l];\n        usize y = msb(l xor --r);\n\
    \        return M::operation(m_table[y][l], m_table[y][r]);\n    }\n\nprivate:\n\
    \n    std::vector<std::vector<V>> m_table;\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Monoid/MonoidConcept.hpp\"\
    \n#include \"../../Algebra/Action/ActionConcept.hpp\"\n\n#include <bit>\n#include\
    \ <cassert>\n#include <concepts>\n#include <vector>\n\nnamespace zawa {\n\ntemplate\
    \ <concepts::Monoid M>\nclass DisjointSparseTable {\npublic:\n\n    using V =\
    \ typename M::Element;\n\n    constexpr usize height(usize n) const {\n      \
    \  return std::max(usize{1}, std::bit_width(n) - (usize)std::has_single_bit(n));\n\
    \    }\n\n    constexpr usize msb(usize n) const {\n        assert(n);\n     \
    \   return std::bit_width(n) - 1;\n    }\n\n    template <class S>\n    requires\
    \ std::same_as<V, S> or concepts::Acted<V, S>\n    DisjointSparseTable(const std::vector<S>&\
    \ A) : m_table(height(A.size())) {\n        assert(A.size());\n        for (usize\
    \ i = 1, w = 2 ; i < m_table.size() ; i++, w <<= 1) {\n            m_table[i].resize(A.size());\n\
    \            for (usize j = 0, idx = 0 ; j < A.size() ; j += w, idx++) {\n   \
    \             V prod = M::identity();\n                if (idx & 1) { // ->\n\
    \                    usize m = std::min(A.size() - j, w);\n                  \
    \  for (usize k = 0 ; k < m ; k++) {\n                        if constexpr (std::same_as<V,\
    \ S>)\n                            prod = M::operation(prod, A[j + k]);\n    \
    \                    else\n                            prod = M::acted(prod, A[j\
    \ + k]);\n                        m_table[i][j + k] = prod;\n                \
    \    }\n                }\n                else { // <-\n                    usize\
    \ m = std::min(A.size(), j + w);\n                    for (usize k = m ; k-- >\
    \ j ; ) {\n                        if constexpr (std::same_as<V, S>)\n       \
    \                     prod = M::operation(A[k], prod);\n                     \
    \   else\n                            prod = M::acted(prod, A[k]);\n         \
    \               m_table[i][k] = prod;\n                    }\n               \
    \ }\n            }\n        }\n        m_table[0].resize(A.size());\n        for\
    \ (usize i = 0 ; i < A.size() ; i++) {\n            if constexpr (std::same_as<V,\
    \ S>)\n                m_table[0][i] = A[i];\n            else\n             \
    \   m_table[0][i] = M::acted(M::identity(), A[i]);\n        }\n    }\n\n    template\
    \ <std::input_iterator It>\n    DisjointSparseTable(It first, It last) : DisjointSparseTable(std::vector(first,\
    \ last)) {}\n\n    V product(usize l, usize r) const {\n        assert(l <= r\
    \ and r <= m_table[0].size());\n        if (l == r) return M::identity();\n  \
    \      if (l + 1 == r) return m_table[0][l];\n        usize y = msb(l xor --r);\n\
    \        return M::operation(m_table[y][l], m_table[y][r]);\n    }\n\nprivate:\n\
    \n    std::vector<std::vector<V>> m_table;\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Action/ActionConcept.hpp
  isVerificationFile: false
  path: Src/DataStructure/SparseTable/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '2025-08-21 03:53:28+09:00'
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
    // コンストラクタの引数のvector<S>のSがElementと異なる場合必要
    // static Element acted(Element L, S e) {
    // }
};
```

## 参考

- [Disjoint Sparse Tableとセグ木に関するポエム](https://noshi91.hatenablog.com/entry/2018/05/08/183946)
- [分割統治による静的列の区間積クエリ](https://maspypy.com/%E5%88%86%E5%89%B2%E7%B5%B1%E6%B2%BB%E3%81%AB%E3%82%88%E3%82%8B%E9%9D%99%E7%9A%84%E5%88%97%E3%81%AE%E5%8C%BA%E9%96%93%E7%A9%8D%E3%82%AF%E3%82%A8%E3%83%AA)

## 変更履歴

2025/8/21:作用の考え方を取り入れた実装方針に変更。ドキュメントに参考を追加 
