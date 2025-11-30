---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/GroupConcept.hpp
    title: Src/Algebra/Group/GroupConcept.hpp
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
    path: Test/AtCoder/abc434_d.test.cpp
    title: Test/AtCoder/abc434_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/PrefixSum/Imos2D.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\n\n#line\
    \ 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Inversible\
    \ = requires {\n    typename T::Element;\n    { T::inverse(std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\ntemplate <class\
    \ T>\nconcept Group = Monoid<T> and Inversible<T>;\n\n} // namespace Concept\n\
    \n} // namespace zawa\n#line 5 \"Src/DataStructure/PrefixSum/Imos2D.hpp\"\n\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace zawa {\n\
    \nnamespace internal {\n\ntemplate <concepts::Group G>\nclass StaticRectAddSolver\
    \ {\npublic:\n    \n    using T = typename G::Element;\n\n    explicit StaticRectAddSolver(const\
    \ std::vector<std::vector<T>>& imos) : m_H{imos.size() - 1}, m_W{imos[0].size()\
    \ - 1}, m_a(imos) {\n        for (usize i = 0 ; i < m_H ; i++)\n            for\
    \ (usize j = 1 ; j <= m_W ; j++)\n                m_a[i][j] = G::operation(m_a[i][j],\
    \ m_a[i][j - 1]);\n        for (usize i = 1 ; i <= m_H ; i++)\n            for\
    \ (usize j = 0 ; j < m_W ; j++)\n                m_a[i][j] = G::operation(m_a[i][j],\
    \ m_a[i - 1][j]);\n    }\n\n    inline usize height() const {\n        return\
    \ m_H;\n    }\n\n    inline usize width() const {\n        return m_W;\n    }\n\
    \n    const std::vector<T>& operator[](usize i) const {\n        assert(i < height()\
    \ and \"invalid access m_sum[i]: StaticRectSumSolver::operator[]\");\n       \
    \ return m_a[i];\n    }\n\nprivate:\n\n    usize m_H, m_W;\n\n    std::vector<std::vector<T>>\
    \ m_a;\n};\n\n} // namespace internal\n\ntemplate <concepts::Group G>\nclass Imos2D\
    \ {\npublic:\n    \n    using T = typename G::Element;\n\n    Imos2D(usize H,\
    \ usize W) : m_H{H}, m_W{W}, m_imos(H + 1, std::vector<T>(W + 1, G::identity()))\
    \ {}\n\n    inline usize height() const {\n        return m_H;\n    }\n\n    inline\
    \ usize width() const {\n        return m_W;\n    }\n\n    // [l, r) x [d, u)\n\
    \    void operation(usize l, usize d, usize r, usize u, T v) {\n        assert((l\
    \ <= r and r <= height()) and \"invalid i range: Imos2D::add\");\n        assert((d\
    \ <= u and u <= width()) and \"invalid j range: Imos2D::add\");\n        T inv\
    \ = G::inverse(v);\n        m_imos[l][d] = G::operation(m_imos[l][d], v);\n  \
    \      m_imos[l][u] = G::operation(m_imos[l][u], inv);\n        m_imos[r][d] =\
    \ G::operation(m_imos[r][d], inv);\n        m_imos[r][u] = G::operation(m_imos[r][u],\
    \ v);\n    }\n\n    const std::vector<T>& operator[](const usize i) const {\n\
    \        assert(i < height() and \"invalid range: Imos2D::operator[]\");\n   \
    \     return m_imos[i];\n    }\n\n    internal::StaticRectAddSolver<G> build()\
    \ const {\n        return internal::StaticRectAddSolver<G>{m_imos};\n    }\n\n\
    private:\n\n    usize m_H = 0, m_W = 0;\n\n    std::vector<std::vector<T>> m_imos;\n\
    };\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Group/GroupConcept.hpp\"\
    \n\n#include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace zawa\
    \ {\n\nnamespace internal {\n\ntemplate <concepts::Group G>\nclass StaticRectAddSolver\
    \ {\npublic:\n    \n    using T = typename G::Element;\n\n    explicit StaticRectAddSolver(const\
    \ std::vector<std::vector<T>>& imos) : m_H{imos.size() - 1}, m_W{imos[0].size()\
    \ - 1}, m_a(imos) {\n        for (usize i = 0 ; i < m_H ; i++)\n            for\
    \ (usize j = 1 ; j <= m_W ; j++)\n                m_a[i][j] = G::operation(m_a[i][j],\
    \ m_a[i][j - 1]);\n        for (usize i = 1 ; i <= m_H ; i++)\n            for\
    \ (usize j = 0 ; j < m_W ; j++)\n                m_a[i][j] = G::operation(m_a[i][j],\
    \ m_a[i - 1][j]);\n    }\n\n    inline usize height() const {\n        return\
    \ m_H;\n    }\n\n    inline usize width() const {\n        return m_W;\n    }\n\
    \n    const std::vector<T>& operator[](usize i) const {\n        assert(i < height()\
    \ and \"invalid access m_sum[i]: StaticRectSumSolver::operator[]\");\n       \
    \ return m_a[i];\n    }\n\nprivate:\n\n    usize m_H, m_W;\n\n    std::vector<std::vector<T>>\
    \ m_a;\n};\n\n} // namespace internal\n\ntemplate <concepts::Group G>\nclass Imos2D\
    \ {\npublic:\n    \n    using T = typename G::Element;\n\n    Imos2D(usize H,\
    \ usize W) : m_H{H}, m_W{W}, m_imos(H + 1, std::vector<T>(W + 1, G::identity()))\
    \ {}\n\n    inline usize height() const {\n        return m_H;\n    }\n\n    inline\
    \ usize width() const {\n        return m_W;\n    }\n\n    // [l, r) x [d, u)\n\
    \    void operation(usize l, usize d, usize r, usize u, T v) {\n        assert((l\
    \ <= r and r <= height()) and \"invalid i range: Imos2D::add\");\n        assert((d\
    \ <= u and u <= width()) and \"invalid j range: Imos2D::add\");\n        T inv\
    \ = G::inverse(v);\n        m_imos[l][d] = G::operation(m_imos[l][d], v);\n  \
    \      m_imos[l][u] = G::operation(m_imos[l][u], inv);\n        m_imos[r][d] =\
    \ G::operation(m_imos[r][d], inv);\n        m_imos[r][u] = G::operation(m_imos[r][u],\
    \ v);\n    }\n\n    const std::vector<T>& operator[](const usize i) const {\n\
    \        assert(i < height() and \"invalid range: Imos2D::operator[]\");\n   \
    \     return m_imos[i];\n    }\n\n    internal::StaticRectAddSolver<G> build()\
    \ const {\n        return internal::StaticRectAddSolver<G>{m_imos};\n    }\n\n\
    private:\n\n    usize m_H = 0, m_W = 0;\n\n    std::vector<std::vector<T>> m_imos;\n\
    };\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: false
  path: Src/DataStructure/PrefixSum/Imos2D.hpp
  requiredBy: []
  timestamp: '2025-11-30 18:03:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc434_d.test.cpp
documentation_of: Src/DataStructure/PrefixSum/Imos2D.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/PrefixSum/Imos2D.hpp
- /library/Src/DataStructure/PrefixSum/Imos2D.hpp.html
title: Src/DataStructure/PrefixSum/Imos2D.hpp
---
