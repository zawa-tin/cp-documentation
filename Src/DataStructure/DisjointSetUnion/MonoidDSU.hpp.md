---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
    title: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc451_f.test.cpp
    title: Test/AtCoder/abc451_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/DisjointSetUnion/MonoidDSU.hpp\"\n\n#line\
    \ 2 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n#include <vector>\n\
    #include <concepts>\n\nnamespace zawa {\n\nclass DisjointSetUnion {\npublic:\n\
    \    DisjointSetUnion() = default;\n\n    DisjointSetUnion(usize n) : n_{n}, comps_{n},\
    \ data_(n, -1) {\n        data_.shrink_to_fit();\n    }\n    \n    u32 leader(u32\
    \ v) {\n        return data_[v] < 0 ? v : static_cast<u32>(data_[v] = leader(data_[v]));\n\
    \    }\n\n    bool same(u32 u, u32 v) {\n        return leader(u) == leader(v);\n\
    \    }\n\n    bool merge(u32 u, u32 v) {\n        assert(u < n_);\n        assert(v\
    \ < n_);\n        u = leader(u);\n        v = leader(v);\n        if (u == v)\
    \ return false;\n        comps_--;\n        if (data_[u] > data_[v]) std::swap(u,\
    \ v);\n        data_[u] += data_[v];\n        data_[v] = u;\n        return true;\n\
    \    }\n\n    inline usize size() const noexcept {\n        return n_;\n    }\n\
    \n    usize size(u32 v) {\n        assert(v < n_);\n        return static_cast<usize>(-data_[leader(v)]);\n\
    \    }\n\n    inline usize components() const noexcept {\n        return comps_;\n\
    \    }\n\n    template <class T = usize>\n    std::vector<std::vector<T>> enumerate()\
    \ requires std::convertible_to<usize, T> {\n        std::vector<std::vector<T>>\
    \ res(n_);\n        for (usize v{} ; v < n_ ; v++) {\n            res[leader(v)].push_back(static_cast<T>(v));\n\
    \        }\n        std::erase_if(res, [](const auto& arr) -> bool { return arr.empty();\
    \ });\n        return res;\n    }\n\nprivate:\n    usize n_{}, comps_{};\n   \
    \ std::vector<i32> data_;\n};\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#line 4 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/DisjointSetUnion/MonoidDSU.hpp\"\
    \n\n#line 7 \"Src/DataStructure/DisjointSetUnion/MonoidDSU.hpp\"\n\nnamespace\
    \ zawa {\n\n// \u53EF\u63DB\u3058\u3083\u306A\u3044\u3068\u30C0\u30E1\u3060\u3088\
    \ntemplate <concepts::Monoid M>\nclass MonoidDSU {\npublic:\n\n    MonoidDSU()\
    \ = default;\n\n    MonoidDSU(usize n) : m_dsu{n}, m_prod(n,M::identity()) {}\n\
    \n    MonoidDSU(std::vector<typename M::Element> A) : m_dsu{A.size()}, m_prod{std::move(A)}\
    \ {}\n\n    u32 leader(usize v) {\n        return m_dsu.leader(v);\n    }\n\n\
    \    bool same(usize u,usize v) {\n        return m_dsu.same(u,v);\n    }\n\n\
    \    bool merge(usize u,usize v) {\n        u = leader(u);\n        v = leader(v);\n\
    \        if (u == v)\n            return false;\n        m_dsu.merge(u,v);\n \
    \       m_prod[leader(u)] = M::operation(m_prod[u],m_prod[v]);\n        return\
    \ true;\n    }\n\n    inline usize size() const noexcept {\n        return m_dsu.size();\n\
    \    }\n\n    inline usize components() const noexcept {\n        return m_dsu.components();\n\
    \    }\n\n    template <class T>\n    std::vector<std::vector<T>> enumerate()\
    \ requires std::convertible_to<usize,T> {\n        return m_dsu.enumerate();\n\
    \    }\n\n    const M::Element& operator[](usize i) {\n        assert(i < size());\n\
    \        return m_prod[leader(i)];\n    }\n\nprivate:\n\n    DisjointSetUnion\
    \ m_dsu;\n\n    std::vector<typename M::Element> m_prod;\n\n};\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include \"./DisjointSetUnion.hpp\"\n#include \"../../Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#include <vector>\n\nnamespace zawa {\n\n// \u53EF\u63DB\u3058\u3083\u306A\
    \u3044\u3068\u30C0\u30E1\u3060\u3088\ntemplate <concepts::Monoid M>\nclass MonoidDSU\
    \ {\npublic:\n\n    MonoidDSU() = default;\n\n    MonoidDSU(usize n) : m_dsu{n},\
    \ m_prod(n,M::identity()) {}\n\n    MonoidDSU(std::vector<typename M::Element>\
    \ A) : m_dsu{A.size()}, m_prod{std::move(A)} {}\n\n    u32 leader(usize v) {\n\
    \        return m_dsu.leader(v);\n    }\n\n    bool same(usize u,usize v) {\n\
    \        return m_dsu.same(u,v);\n    }\n\n    bool merge(usize u,usize v) {\n\
    \        u = leader(u);\n        v = leader(v);\n        if (u == v)\n       \
    \     return false;\n        m_dsu.merge(u,v);\n        m_prod[leader(u)] = M::operation(m_prod[u],m_prod[v]);\n\
    \        return true;\n    }\n\n    inline usize size() const noexcept {\n   \
    \     return m_dsu.size();\n    }\n\n    inline usize components() const noexcept\
    \ {\n        return m_dsu.components();\n    }\n\n    template <class T>\n   \
    \ std::vector<std::vector<T>> enumerate() requires std::convertible_to<usize,T>\
    \ {\n        return m_dsu.enumerate();\n    }\n\n    const M::Element& operator[](usize\
    \ i) {\n        assert(i < size());\n        return m_prod[leader(i)];\n    }\n\
    \nprivate:\n\n    DisjointSetUnion m_dsu;\n\n    std::vector<typename M::Element>\
    \ m_prod;\n\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: false
  path: Src/DataStructure/DisjointSetUnion/MonoidDSU.hpp
  requiredBy: []
  timestamp: '2026-04-10 14:03:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc451_f.test.cpp
documentation_of: Src/DataStructure/DisjointSetUnion/MonoidDSU.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/DisjointSetUnion/MonoidDSU.hpp
- /library/Src/DataStructure/DisjointSetUnion/MonoidDSU.hpp.html
title: Src/DataStructure/DisjointSetUnion/MonoidDSU.hpp
---
