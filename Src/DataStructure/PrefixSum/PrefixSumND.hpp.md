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
    path: Test/AOJ/4077.test.cpp
    title: Test/AOJ/4077.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc465_f.test.cpp
    title: Test/AtCoder/abc465_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/PrefixSum/PrefixSumND.hpp\"\n\n#line 2\
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
    \n} // namespace zawa\n#line 5 \"Src/DataStructure/PrefixSum/PrefixSumND.hpp\"\
    \n\n#include <array>\n#include <bit>\n#include <cassert>\n#line 10 \"Src/DataStructure/PrefixSum/PrefixSumND.hpp\"\
    \n#include <utility>\n#include <vector>\n\nnamespace zawa {\n\nnamespace internal\
    \ {\n\ntemplate <concepts::Group G,usize N>\nclass StaticHypercubeSumSolver {\n\
    public:\n\n    using T = typename G::Element;\n\n    StaticHypercubeSumSolver(std::array<usize,N>\
    \ sz,std::array<usize,N+1> prod,std::vector<T> a)\n        : m_size{sz}, m_prod{prod},\
    \ m_sum{std::move(a)} {\n        for (usize axis = 0 ; axis < N ; axis++)\n  \
    \          for (usize i = 0 ; i < prod[N] ; i++)\n                if (i/m_prod[axis]%m_size[axis])\n\
    \                    m_sum[i] = G::operation(m_sum[i],m_sum[i-m_prod[axis]]);\n\
    \    }\n\n    template <std::integral IDX>\n    T product(const std::array<std::pair<IDX,IDX>,N>&\
    \ lr) const {\n        for (usize i = 0 ; i < N ; i++) {\n            assert(static_cast<IDX>(0)\
    \ <= lr[i].first and lr[i].first <= static_cast<IDX>(m_size[i]));\n          \
    \  assert(static_cast<IDX>(0) <= lr[i].second and lr[i].second <= static_cast<IDX>(m_size[i]));\n\
    \            assert(lr[i].first <= lr[i].second);\n        }\n        T res =\
    \ G::identity();\n        auto dfs = [&](auto dfs,usize axis,usize idx,bool sign)\
    \ -> void {\n            if (axis == N) {\n                if (sign)\n       \
    \             res = G::operation(res,G::inverse(m_sum[idx]));\n              \
    \  else\n                    res = G::operation(res,m_sum[idx]);\n           \
    \     return;\n            }\n            if (lr[axis].second)\n             \
    \   dfs(dfs,axis+1,idx+m_prod[axis]*(lr[axis].second-1),sign);\n            if\
    \ (lr[axis].first)\n                dfs(dfs,axis+1,idx+m_prod[axis]*(lr[axis].first-1),!sign);\n\
    \        };\n        dfs(dfs,0,0,0);\n        return res;\n    }\n\n    template\
    \ <std::integral IDX>\n    T product(const std::array<IDX,N>& l,const std::array<IDX,N>&\
    \ r) const {\n        std::array<std::pair<IDX,IDX>,N> lr;\n        for (usize\
    \ i = 0 ; i < N ; i++)\n            lr[i] = {l[i],r[i]};\n        return product(lr);\n\
    \    }\n\nprivate:\n\n    std::array<usize,N> m_size;\n\n    std::array<usize,N+1>\
    \ m_prod;\n\n    std::vector<T> m_sum;\n\n};\n\n} // namespace internal\n\ntemplate\
    \ <concepts::Group G,usize N>\nclass RuisekiwaND {\npublic:\n\n    using T = typename\
    \ G::Element;\n\n    template <std::integral IDX>\n    RuisekiwaND(std::array<IDX,N>\
    \ sz) {\n        m_prod[0] = 1;\n        for (usize i = 0 ; i < N ; i++) {\n \
    \           m_size[i] = static_cast<usize>(sz[i]);\n            m_prod[i+1] =\
    \ m_prod[i]*m_size[i];\n        }\n        m_a.resize(m_prod[N],G::identity());\n\
    \    }\n\n    template <std::integral IDX>\n    void operation(const std::array<IDX,N>&\
    \ p,const T& v) {\n        usize idx = 0;\n        for (usize i = 0 ; i < N ;\
    \ i++) {\n            assert(static_cast<IDX>(0) <= p[i] and p[i] < static_cast<IDX>(m_size[i]));\n\
    \            idx += m_prod[i]*p[i];\n        }\n        m_a[idx] = G::operation(m_a[idx],v);\n\
    \    }\n\n    template <std::integral IDX>\n    void assign(const std::array<IDX,N>&\
    \ p,T v) {\n        usize idx = 0;\n        for (usize i = 0 ; i < N ; i++) {\n\
    \            assert(static_cast<IDX>(0) <= p[i] and p[i] < static_cast<IDX>(m_size[i]));\n\
    \            idx += m_prod[i]*p[i];\n        }\n        m_a[idx] = std::move(v);\n\
    \    }\n\n    template <std::integral IDX>\n    const T& get(const std::array<IDX,N>&\
    \ p) const {\n        assert(m_flag == false or !\"RuisekiwaND::get: data is already\
    \ moved\");\n        usize idx = 0;\n        for (usize i = 0 ; i < N ; i++) {\n\
    \            assert(static_cast<IDX>(0) <= p[i] and p[i] < static_cast<IDX>(m_size[i]));\n\
    \            idx += m_prod[i]*p[i];\n        }\n        return m_a[idx];\n   \
    \ }\n\n    internal::StaticHypercubeSumSolver<G,N> build() const {\n        assert(m_flag\
    \ == false or !\"RuisekiwaND::build: data is already moved\");\n        return\
    \ internal::StaticHypercubeSumSolver<G,N>(m_size,m_prod,m_a);\n    }\n\n    internal::StaticHypercubeSumSolver<G,N>\
    \ inplaceBuild() {\n        assert(m_flag == false or !\"RuisekiwaND::inplaceBuild:\
    \ data is already moved\");\n        m_flag = true;\n        return internal::StaticHypercubeSumSolver<G,N>(m_size,m_prod,std::move(m_a));\n\
    \    }\n\nprivate:\n\n    std::array<usize,N> m_size;\n\n    std::array<usize,N+1>\
    \ m_prod;\n\n    std::vector<T> m_a;\n\n    bool m_flag = false;\n\n};\n\n} //\
    \ namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Group/GroupConcept.hpp\"\
    \n\n#include <array>\n#include <bit>\n#include <cassert>\n#include <concepts>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\nnamespace internal\
    \ {\n\ntemplate <concepts::Group G,usize N>\nclass StaticHypercubeSumSolver {\n\
    public:\n\n    using T = typename G::Element;\n\n    StaticHypercubeSumSolver(std::array<usize,N>\
    \ sz,std::array<usize,N+1> prod,std::vector<T> a)\n        : m_size{sz}, m_prod{prod},\
    \ m_sum{std::move(a)} {\n        for (usize axis = 0 ; axis < N ; axis++)\n  \
    \          for (usize i = 0 ; i < prod[N] ; i++)\n                if (i/m_prod[axis]%m_size[axis])\n\
    \                    m_sum[i] = G::operation(m_sum[i],m_sum[i-m_prod[axis]]);\n\
    \    }\n\n    template <std::integral IDX>\n    T product(const std::array<std::pair<IDX,IDX>,N>&\
    \ lr) const {\n        for (usize i = 0 ; i < N ; i++) {\n            assert(static_cast<IDX>(0)\
    \ <= lr[i].first and lr[i].first <= static_cast<IDX>(m_size[i]));\n          \
    \  assert(static_cast<IDX>(0) <= lr[i].second and lr[i].second <= static_cast<IDX>(m_size[i]));\n\
    \            assert(lr[i].first <= lr[i].second);\n        }\n        T res =\
    \ G::identity();\n        auto dfs = [&](auto dfs,usize axis,usize idx,bool sign)\
    \ -> void {\n            if (axis == N) {\n                if (sign)\n       \
    \             res = G::operation(res,G::inverse(m_sum[idx]));\n              \
    \  else\n                    res = G::operation(res,m_sum[idx]);\n           \
    \     return;\n            }\n            if (lr[axis].second)\n             \
    \   dfs(dfs,axis+1,idx+m_prod[axis]*(lr[axis].second-1),sign);\n            if\
    \ (lr[axis].first)\n                dfs(dfs,axis+1,idx+m_prod[axis]*(lr[axis].first-1),!sign);\n\
    \        };\n        dfs(dfs,0,0,0);\n        return res;\n    }\n\n    template\
    \ <std::integral IDX>\n    T product(const std::array<IDX,N>& l,const std::array<IDX,N>&\
    \ r) const {\n        std::array<std::pair<IDX,IDX>,N> lr;\n        for (usize\
    \ i = 0 ; i < N ; i++)\n            lr[i] = {l[i],r[i]};\n        return product(lr);\n\
    \    }\n\nprivate:\n\n    std::array<usize,N> m_size;\n\n    std::array<usize,N+1>\
    \ m_prod;\n\n    std::vector<T> m_sum;\n\n};\n\n} // namespace internal\n\ntemplate\
    \ <concepts::Group G,usize N>\nclass RuisekiwaND {\npublic:\n\n    using T = typename\
    \ G::Element;\n\n    template <std::integral IDX>\n    RuisekiwaND(std::array<IDX,N>\
    \ sz) {\n        m_prod[0] = 1;\n        for (usize i = 0 ; i < N ; i++) {\n \
    \           m_size[i] = static_cast<usize>(sz[i]);\n            m_prod[i+1] =\
    \ m_prod[i]*m_size[i];\n        }\n        m_a.resize(m_prod[N],G::identity());\n\
    \    }\n\n    template <std::integral IDX>\n    void operation(const std::array<IDX,N>&\
    \ p,const T& v) {\n        usize idx = 0;\n        for (usize i = 0 ; i < N ;\
    \ i++) {\n            assert(static_cast<IDX>(0) <= p[i] and p[i] < static_cast<IDX>(m_size[i]));\n\
    \            idx += m_prod[i]*p[i];\n        }\n        m_a[idx] = G::operation(m_a[idx],v);\n\
    \    }\n\n    template <std::integral IDX>\n    void assign(const std::array<IDX,N>&\
    \ p,T v) {\n        usize idx = 0;\n        for (usize i = 0 ; i < N ; i++) {\n\
    \            assert(static_cast<IDX>(0) <= p[i] and p[i] < static_cast<IDX>(m_size[i]));\n\
    \            idx += m_prod[i]*p[i];\n        }\n        m_a[idx] = std::move(v);\n\
    \    }\n\n    template <std::integral IDX>\n    const T& get(const std::array<IDX,N>&\
    \ p) const {\n        assert(m_flag == false or !\"RuisekiwaND::get: data is already\
    \ moved\");\n        usize idx = 0;\n        for (usize i = 0 ; i < N ; i++) {\n\
    \            assert(static_cast<IDX>(0) <= p[i] and p[i] < static_cast<IDX>(m_size[i]));\n\
    \            idx += m_prod[i]*p[i];\n        }\n        return m_a[idx];\n   \
    \ }\n\n    internal::StaticHypercubeSumSolver<G,N> build() const {\n        assert(m_flag\
    \ == false or !\"RuisekiwaND::build: data is already moved\");\n        return\
    \ internal::StaticHypercubeSumSolver<G,N>(m_size,m_prod,m_a);\n    }\n\n    internal::StaticHypercubeSumSolver<G,N>\
    \ inplaceBuild() {\n        assert(m_flag == false or !\"RuisekiwaND::inplaceBuild:\
    \ data is already moved\");\n        m_flag = true;\n        return internal::StaticHypercubeSumSolver<G,N>(m_size,m_prod,std::move(m_a));\n\
    \    }\n\nprivate:\n\n    std::array<usize,N> m_size;\n\n    std::array<usize,N+1>\
    \ m_prod;\n\n    std::vector<T> m_a;\n\n    bool m_flag = false;\n\n};\n\n} //\
    \ namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: false
  path: Src/DataStructure/PrefixSum/PrefixSumND.hpp
  requiredBy: []
  timestamp: '2026-07-08 14:06:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc465_f.test.cpp
  - Test/AOJ/4077.test.cpp
documentation_of: Src/DataStructure/PrefixSum/PrefixSumND.hpp
layout: document
title: "$N$ \u6B21\u5143\u7D2F\u7A4D\u548C"
---

## 概要

このライブラリ本当にいるのか？

6次元累積和の問題に6次元Fenwick Treeをやってしまう(2敗)のを防ぐことができるかも。

$N$ が動的のときは、最大次数をテンプレートに与えて、参照しない軸の大きさを $1$ にする。

計算量は、構築に $O(N\prod H_{i})$ 、クエリに $O(2^N)$

- クエリの計算量dfsで頑張ることで、 $N$ を一個落とした。
