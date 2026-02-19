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
    path: Test/AOJ/2426.test.cpp
    title: Test/AOJ/2426.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc434_d.test.cpp
    title: Test/AtCoder/abc434_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/PrefixSum/PrefixSum2D.hpp\"\n\n#line 2\
    \ \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\n\
    namespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
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
    \n} // namespace zawa\n#line 5 \"Src/DataStructure/PrefixSum/PrefixSum2D.hpp\"\
    \n\n#include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace zawa\
    \ {\n\nnamespace internal {\n\ntemplate <concepts::Group G>\nclass StaticRectSumSolver\
    \ {\npublic:\n    \n    using T = typename G::Element;\n\n    using const_iterator\
    \ = typename std::vector<std::vector<T>>::const_iterator;\n\n    explicit StaticRectSumSolver(const\
    \ std::vector<std::vector<T>>& a) : m_H{a.size()}, m_W{a.empty() ? 0u : a[0].size()},\
    \ m_sum(m_H + 1, std::vector<T>(m_W + 1, G::identity())) {\n        for (usize\
    \ i = 0 ; i < m_H ; i++)\n            for (usize j = 0 ; j < m_W ; j++)\n    \
    \            m_sum[i + 1][j + 1] = G::operation(\n                        G::operation(m_sum[i\
    \ + 1][j], m_sum[i][j + 1]), \n                        G::operation(G::inverse(m_sum[i][j]),\
    \ a[i][j])\n                        );\n    }\n\n    explicit StaticRectSumSolver(std::vector<std::vector<T>>&&\
    \ a) : m_H{a.size()}, m_W{a.empty() ? 0u : a[0].size()}, m_sum{std::move(a)} {\n\
    \        for (usize i = 0 ; i < m_H ; i++)\n            m_sum[i].push_back(G::identity());\n\
    \        m_sum.push_back(std::vector<T>(m_W + 1, G::identity()));\n        for\
    \ (usize i = 0 ; i <= m_H ; i++)\n            for (usize j = m_W ; j-- ; )\n \
    \               m_sum[i][j] = G::operation(m_sum[i][j], m_sum[i][j + 1]);\n  \
    \      for (usize i = m_H ; i-- ; )\n            for (usize j = 0 ; j <= m_W ;\
    \ j++)\n                m_sum[i][j] = G::operation(m_sum[i][j], m_sum[i + 1][j]);\n\
    \    }\n\n    inline usize height() const {\n        return m_H;\n    }\n\n  \
    \  inline usize width() const {\n        return m_W;\n    }\n\n    // [l, r) x\
    \ [d, u)\n    T product(usize l, usize d, usize r, usize u) const {\n        assert((l\
    \ <= r and r <= height()) and \"invalid i range: StaticRectSumSolver::product\"\
    );\n        assert((d <= u and u <= width()) and \"invalid j range: StaticRectSumSolver::product\"\
    );\n        return G::operation(\n                G::operation(m_sum[r][u], m_sum[l][d]),\n\
    \                G::inverse(G::operation(m_sum[r][d], m_sum[l][u]))\n        \
    \        );\n    }\n\n    const std::vector<T>& operator[](usize i) const {\n\
    \        assert(i <= height() and \"invalid access m_sum[i]: StaticRectSumSolver::operator[]\"\
    );\n        return m_sum[i];\n    }\n\n    const_iterator begin() const {\n  \
    \      return m_sum.begin();\n    }\n    \n    const_iterator end() const {\n\
    \        return m_sum.end();\n    }\n\nprivate:\n\n    usize m_H, m_W;\n\n   \
    \ std::vector<std::vector<T>> m_sum;\n};\n\n} // namespace internal\n\ntemplate\
    \ <concepts::Group G>\nclass Ruisekiwa2D {\npublic:\n    \n    using T = typename\
    \ G::Element;\n\n    Ruisekiwa2D(usize H, usize W) : m_H{H}, m_W{W}, m_a(H, std::vector<T>(W,\
    \ G::identity())) {}\n\n    explicit Ruisekiwa2D(std::vector<std::vector<T>>&&\
    \ a) : m_H{a.size()}, m_W{a.empty() ? 0u : a[0].size()}, m_a{std::move(a)} {}\n\
    \n    explicit Ruisekiwa2D(const std::vector<std::vector<T>>& a) : m_H{a.size()},\
    \ m_W{a.empty() ? 0u : a[0].size()}, m_a{a} {}\n\n    inline usize height() const\
    \ {\n        return m_H;\n    }\n\n    inline usize width() const {\n        return\
    \ m_W;\n    }\n\n    void operation(usize i, usize j, T v) {\n        assert((i\
    \ < height() and j < width()) and \"invalid range: Ruisekiwa2D::operation\");\n\
    \        assert(m_moved == false and \"already destructed: Ruisekiwa2D::operation\"\
    );\n        m_a[i][j] = G::operation(m_a[i][j], v);\n    }\n\n    const std::vector<T>&\
    \ operator[](const usize i) const {\n        assert(i < height() and \"invalid\
    \ range: Ruisekiwa2D::operator[]\");\n        assert(m_moved == false and \"already\
    \ destructed: Ruisekiwa2D::operator[]\");\n        return m_a[i];\n    }\n\n \
    \   internal::StaticRectSumSolver<G> build() const {\n        assert(m_moved ==\
    \ false and \"already destructed: Ruisekiwa2D::build\");\n        return internal::StaticRectSumSolver<G>{m_a};\n\
    \    }\n\n    internal::StaticRectSumSolver<G> inplaceBuild() {\n        assert(m_moved\
    \ == false and \"already destructed: Ruisekiwa2D::build\");\n        m_moved =\
    \ true;\n        return internal::StaticRectSumSolver<G>{std::move(m_a)};\n  \
    \  }\n\nprivate:\n\n    usize m_H = 0, m_W = 0;\n\n    std::vector<std::vector<T>>\
    \ m_a;\n\n    bool m_moved = false;\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Group/GroupConcept.hpp\"\
    \n\n#include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace zawa\
    \ {\n\nnamespace internal {\n\ntemplate <concepts::Group G>\nclass StaticRectSumSolver\
    \ {\npublic:\n    \n    using T = typename G::Element;\n\n    using const_iterator\
    \ = typename std::vector<std::vector<T>>::const_iterator;\n\n    explicit StaticRectSumSolver(const\
    \ std::vector<std::vector<T>>& a) : m_H{a.size()}, m_W{a.empty() ? 0u : a[0].size()},\
    \ m_sum(m_H + 1, std::vector<T>(m_W + 1, G::identity())) {\n        for (usize\
    \ i = 0 ; i < m_H ; i++)\n            for (usize j = 0 ; j < m_W ; j++)\n    \
    \            m_sum[i + 1][j + 1] = G::operation(\n                        G::operation(m_sum[i\
    \ + 1][j], m_sum[i][j + 1]), \n                        G::operation(G::inverse(m_sum[i][j]),\
    \ a[i][j])\n                        );\n    }\n\n    explicit StaticRectSumSolver(std::vector<std::vector<T>>&&\
    \ a) : m_H{a.size()}, m_W{a.empty() ? 0u : a[0].size()}, m_sum{std::move(a)} {\n\
    \        for (usize i = 0 ; i < m_H ; i++)\n            m_sum[i].push_back(G::identity());\n\
    \        m_sum.push_back(std::vector<T>(m_W + 1, G::identity()));\n        for\
    \ (usize i = 0 ; i <= m_H ; i++)\n            for (usize j = m_W ; j-- ; )\n \
    \               m_sum[i][j] = G::operation(m_sum[i][j], m_sum[i][j + 1]);\n  \
    \      for (usize i = m_H ; i-- ; )\n            for (usize j = 0 ; j <= m_W ;\
    \ j++)\n                m_sum[i][j] = G::operation(m_sum[i][j], m_sum[i + 1][j]);\n\
    \    }\n\n    inline usize height() const {\n        return m_H;\n    }\n\n  \
    \  inline usize width() const {\n        return m_W;\n    }\n\n    // [l, r) x\
    \ [d, u)\n    T product(usize l, usize d, usize r, usize u) const {\n        assert((l\
    \ <= r and r <= height()) and \"invalid i range: StaticRectSumSolver::product\"\
    );\n        assert((d <= u and u <= width()) and \"invalid j range: StaticRectSumSolver::product\"\
    );\n        return G::operation(\n                G::operation(m_sum[r][u], m_sum[l][d]),\n\
    \                G::inverse(G::operation(m_sum[r][d], m_sum[l][u]))\n        \
    \        );\n    }\n\n    const std::vector<T>& operator[](usize i) const {\n\
    \        assert(i <= height() and \"invalid access m_sum[i]: StaticRectSumSolver::operator[]\"\
    );\n        return m_sum[i];\n    }\n\n    const_iterator begin() const {\n  \
    \      return m_sum.begin();\n    }\n    \n    const_iterator end() const {\n\
    \        return m_sum.end();\n    }\n\nprivate:\n\n    usize m_H, m_W;\n\n   \
    \ std::vector<std::vector<T>> m_sum;\n};\n\n} // namespace internal\n\ntemplate\
    \ <concepts::Group G>\nclass Ruisekiwa2D {\npublic:\n    \n    using T = typename\
    \ G::Element;\n\n    Ruisekiwa2D(usize H, usize W) : m_H{H}, m_W{W}, m_a(H, std::vector<T>(W,\
    \ G::identity())) {}\n\n    explicit Ruisekiwa2D(std::vector<std::vector<T>>&&\
    \ a) : m_H{a.size()}, m_W{a.empty() ? 0u : a[0].size()}, m_a{std::move(a)} {}\n\
    \n    explicit Ruisekiwa2D(const std::vector<std::vector<T>>& a) : m_H{a.size()},\
    \ m_W{a.empty() ? 0u : a[0].size()}, m_a{a} {}\n\n    inline usize height() const\
    \ {\n        return m_H;\n    }\n\n    inline usize width() const {\n        return\
    \ m_W;\n    }\n\n    void operation(usize i, usize j, T v) {\n        assert((i\
    \ < height() and j < width()) and \"invalid range: Ruisekiwa2D::operation\");\n\
    \        assert(m_moved == false and \"already destructed: Ruisekiwa2D::operation\"\
    );\n        m_a[i][j] = G::operation(m_a[i][j], v);\n    }\n\n    const std::vector<T>&\
    \ operator[](const usize i) const {\n        assert(i < height() and \"invalid\
    \ range: Ruisekiwa2D::operator[]\");\n        assert(m_moved == false and \"already\
    \ destructed: Ruisekiwa2D::operator[]\");\n        return m_a[i];\n    }\n\n \
    \   internal::StaticRectSumSolver<G> build() const {\n        assert(m_moved ==\
    \ false and \"already destructed: Ruisekiwa2D::build\");\n        return internal::StaticRectSumSolver<G>{m_a};\n\
    \    }\n\n    internal::StaticRectSumSolver<G> inplaceBuild() {\n        assert(m_moved\
    \ == false and \"already destructed: Ruisekiwa2D::build\");\n        m_moved =\
    \ true;\n        return internal::StaticRectSumSolver<G>{std::move(m_a)};\n  \
    \  }\n\nprivate:\n\n    usize m_H = 0, m_W = 0;\n\n    std::vector<std::vector<T>>\
    \ m_a;\n\n    bool m_moved = false;\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: false
  path: Src/DataStructure/PrefixSum/PrefixSum2D.hpp
  requiredBy: []
  timestamp: '2025-12-23 18:04:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/2426.test.cpp
  - Test/AtCoder/abc434_d.test.cpp
documentation_of: Src/DataStructure/PrefixSum/PrefixSum2D.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/PrefixSum/PrefixSum2D.hpp
- /library/Src/DataStructure/PrefixSum/PrefixSum2D.hpp.html
title: Src/DataStructure/PrefixSum/PrefixSum2D.hpp
---
