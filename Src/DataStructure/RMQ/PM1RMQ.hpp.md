---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/AuxiliaryTree.hpp
    title: "Auxiliary Tree (\u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\
      \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\
      \u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\
      \u6728)"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/ContourAggregation.hpp
    title: "\u6728\u4E0A\u306E\u7B49\u9AD8\u7DDA\u30AF\u30A8\u30EA"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc340_g.test.cpp
    title: Test/AtCoder/abc340_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc359_g.test.cpp
    title: ABC359-G Sum of Tree Distance
  - icon: ':heavy_check_mark:'
    path: Test/LC/lca/LowestCommonAncestor.test.cpp
    title: Test/LC/lca/LowestCommonAncestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_add_range_contour_sum_on_tree.test.cpp
    title: Test/LC/vertex_add_range_contour_sum_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_get_range_contour_add_on_tree.test.cpp
    title: Test/LC/vertex_get_range_contour_add_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/typical90_ai.test.cpp
    title: Test/Manual/typical90_ai.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/My/DataStructure/RMQ/PM1RMQ.test.cpp
    title: Test/My/DataStructure/RMQ/PM1RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/My/Graph/Tree/LowestCommonAncestor.test.cpp
    title: Test/My/Graph/Tree/LowestCommonAncestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bit>\n#include <cassert>\n#include\
    \ <concepts>\n#include <utility>\n#include <vector>\n\n\nnamespace zawa {\n\n\
    template <std::totally_ordered T>\nclass PM1RMQ {\nprivate:\n\n    static constexpr\
    \ usize B = 8;\n\n    static constexpr usize BMASK = 7;\n\n    static constexpr\
    \ usize LOGB = 3;\n\n    static constexpr usize TRI = B*(B+1)/2;\n\npublic:\n\n\
    \    PM1RMQ() = default;\n\n    PM1RMQ(std::vector<T> a) \n        : m_n{a.size()},\
    \ m_inner{(a.size()+B-1)>>LOGB},\n        m_a{std::move(a)}, m_look(innerSize()),\
    \ m_table(), m_spt(std::bit_width(innerSize()))\n    {\n        std::vector<u32>\
    \ minIndex(innerSize());\n        std::vector<bool> registered(1u << (B-1));\n\
    \        for (usize i = 0,idx = 0 ; i < size() ; idx++) {\n            minIndex[idx]\
    \ = i;\n            for (u8 j = 1 ; ++i < size() and j < (u8)B ; j++) {\n    \
    \            if (m_a[i] < m_a[minIndex[idx]])\n                    minIndex[idx]\
    \ = i;\n                if (m_a[i] == m_a[i-1]+1)\n                    ;\n   \
    \             else if (m_a[i] == m_a[i-1]-1)\n                    m_look[idx]\
    \ |= u8{1} << (j-1);\n                else\n                    assert(!\"init\
    \ table does not satisfy |a_i-a_{i+1}| = 1\");\n            }\n            if\
    \ (!registered[m_look[idx]]) {\n                registered[m_look[idx]] = 1;\n\
    \                registerTable(m_look[idx]);\n            }\n        }\n     \
    \   m_spt[0] = std::move(minIndex);\n        for (usize i = 1,len = 2 ; i < m_spt.size()\
    \ ; i++,len <<= 1) {\n            m_spt[i].resize(innerSize()-len+1);\n      \
    \      for (usize j = 0 ; j < m_spt[i].size() ; j++) {\n                u32 l\
    \ = m_spt[i-1][j], r = m_spt[i-1][j+(len>>1)];\n                m_spt[i][j] =\
    \ m_a[r] < m_a[l] ? r : l;\n            }\n        }\n    }\n\n    inline usize\
    \ size() const {\n        return m_n;\n    }\n\n    // return leftmost index of\
    \ min{a[l],a[l+1],...,a[r-1]} (min of argmin)\n    // empty is not allowed\n \
    \   usize min(usize l,usize r) const {\n        assert(l < r and r <= size());\n\
    \        usize L = l>>LOGB, R = (r-1)>>LOGB;\n        if (L == R)\n          \
    \  return accessTable(L,l&BMASK,r-(L<<LOGB));\n        u32 res = accessTable(L,l&BMASK,B);\n\
    \        L++;\n        if (L < R) {\n            u32 pd = sptMin(L,R);\n     \
    \       if (m_a[pd] < m_a[res])\n                res = pd;\n        }\n      \
    \  u32 rv = accessTable(R,0u,r-(R<<LOGB));\n        if (m_a[rv] < m_a[res])\n\
    \            res = rv;\n        return static_cast<usize>(res);\n    }\n\n   \
    \ usize operator()(usize l,usize r) const {\n        return min(l,r);\n    }\n\
    \nprivate:\n\n    usize m_n,m_inner;\n\n    std::vector<T> m_a;\n\n    // 0..+1,1..-1\n\
    \    std::vector<u8> m_look;\n\n    std::array<u8,(1u << (B-1))*TRI> m_table;\n\
    \n    std::vector<std::vector<u32>> m_spt;\n\n    inline usize innerSize() const\
    \ {\n        return m_inner;\n    }\n\n    usize encode(usize l,usize r) const\
    \ {\n        // assert(l < r and r <= B);\n        static constexpr std::array<uint32_t,8>\
    \ Row{0,8,15,21,26,30,33,35};\n        return Row[l]+(r-l-1);\n    }\n\n    void\
    \ registerTable(usize info) {\n        const usize offset = TRI*info;\n      \
    \  std::vector<usize> val(B);\n        val[0] = B;\n        for (usize i = 0 ;\
    \ i + 1 < B ; i++) {\n            val[i+1] = val[i];\n            if (info & (1u\
    \ << i))\n                val[i+1]--;\n            else\n                val[i+1]++;\n\
    \        }\n        for (u8 l = 0 ; l < B ; l++) {\n            u8 mn = l;\n \
    \           for (u8 r = l ; r < B ; r++) {\n                if (val[mn] > val[r])\n\
    \                    mn = r;\n                m_table[offset+encode(l,r+1)] =\
    \ mn;\n            }\n        }\n    }\n\n    usize accessTable(usize idx,usize\
    \ l,usize r) const {\n        return (idx<<LOGB) + m_table[m_look[idx]*TRI+encode(l,r)];\n\
    \    }\n\n    u32 sptMin(usize l,usize r) const {\n        usize dep = std::bit_width(r-l)-1,\
    \ i = m_spt[dep][l], j = m_spt[dep][r-(1u<<dep)];\n        return m_a[j] < m_a[i]\
    \ ? j : i;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <array>\n#include <bit>\n#include <cassert>\n#include <concepts>\n#include\
    \ <utility>\n#include <vector>\n\n\nnamespace zawa {\n\ntemplate <std::totally_ordered\
    \ T>\nclass PM1RMQ {\nprivate:\n\n    static constexpr usize B = 8;\n\n    static\
    \ constexpr usize BMASK = 7;\n\n    static constexpr usize LOGB = 3;\n\n    static\
    \ constexpr usize TRI = B*(B+1)/2;\n\npublic:\n\n    PM1RMQ() = default;\n\n \
    \   PM1RMQ(std::vector<T> a) \n        : m_n{a.size()}, m_inner{(a.size()+B-1)>>LOGB},\n\
    \        m_a{std::move(a)}, m_look(innerSize()), m_table(), m_spt(std::bit_width(innerSize()))\n\
    \    {\n        std::vector<u32> minIndex(innerSize());\n        std::vector<bool>\
    \ registered(1u << (B-1));\n        for (usize i = 0,idx = 0 ; i < size() ; idx++)\
    \ {\n            minIndex[idx] = i;\n            for (u8 j = 1 ; ++i < size()\
    \ and j < (u8)B ; j++) {\n                if (m_a[i] < m_a[minIndex[idx]])\n \
    \                   minIndex[idx] = i;\n                if (m_a[i] == m_a[i-1]+1)\n\
    \                    ;\n                else if (m_a[i] == m_a[i-1]-1)\n     \
    \               m_look[idx] |= u8{1} << (j-1);\n                else\n       \
    \             assert(!\"init table does not satisfy |a_i-a_{i+1}| = 1\");\n  \
    \          }\n            if (!registered[m_look[idx]]) {\n                registered[m_look[idx]]\
    \ = 1;\n                registerTable(m_look[idx]);\n            }\n        }\n\
    \        m_spt[0] = std::move(minIndex);\n        for (usize i = 1,len = 2 ; i\
    \ < m_spt.size() ; i++,len <<= 1) {\n            m_spt[i].resize(innerSize()-len+1);\n\
    \            for (usize j = 0 ; j < m_spt[i].size() ; j++) {\n               \
    \ u32 l = m_spt[i-1][j], r = m_spt[i-1][j+(len>>1)];\n                m_spt[i][j]\
    \ = m_a[r] < m_a[l] ? r : l;\n            }\n        }\n    }\n\n    inline usize\
    \ size() const {\n        return m_n;\n    }\n\n    // return leftmost index of\
    \ min{a[l],a[l+1],...,a[r-1]} (min of argmin)\n    // empty is not allowed\n \
    \   usize min(usize l,usize r) const {\n        assert(l < r and r <= size());\n\
    \        usize L = l>>LOGB, R = (r-1)>>LOGB;\n        if (L == R)\n          \
    \  return accessTable(L,l&BMASK,r-(L<<LOGB));\n        u32 res = accessTable(L,l&BMASK,B);\n\
    \        L++;\n        if (L < R) {\n            u32 pd = sptMin(L,R);\n     \
    \       if (m_a[pd] < m_a[res])\n                res = pd;\n        }\n      \
    \  u32 rv = accessTable(R,0u,r-(R<<LOGB));\n        if (m_a[rv] < m_a[res])\n\
    \            res = rv;\n        return static_cast<usize>(res);\n    }\n\n   \
    \ usize operator()(usize l,usize r) const {\n        return min(l,r);\n    }\n\
    \nprivate:\n\n    usize m_n,m_inner;\n\n    std::vector<T> m_a;\n\n    // 0..+1,1..-1\n\
    \    std::vector<u8> m_look;\n\n    std::array<u8,(1u << (B-1))*TRI> m_table;\n\
    \n    std::vector<std::vector<u32>> m_spt;\n\n    inline usize innerSize() const\
    \ {\n        return m_inner;\n    }\n\n    usize encode(usize l,usize r) const\
    \ {\n        // assert(l < r and r <= B);\n        static constexpr std::array<uint32_t,8>\
    \ Row{0,8,15,21,26,30,33,35};\n        return Row[l]+(r-l-1);\n    }\n\n    void\
    \ registerTable(usize info) {\n        const usize offset = TRI*info;\n      \
    \  std::vector<usize> val(B);\n        val[0] = B;\n        for (usize i = 0 ;\
    \ i + 1 < B ; i++) {\n            val[i+1] = val[i];\n            if (info & (1u\
    \ << i))\n                val[i+1]--;\n            else\n                val[i+1]++;\n\
    \        }\n        for (u8 l = 0 ; l < B ; l++) {\n            u8 mn = l;\n \
    \           for (u8 r = l ; r < B ; r++) {\n                if (val[mn] > val[r])\n\
    \                    mn = r;\n                m_table[offset+encode(l,r+1)] =\
    \ mn;\n            }\n        }\n    }\n\n    usize accessTable(usize idx,usize\
    \ l,usize r) const {\n        return (idx<<LOGB) + m_table[m_look[idx]*TRI+encode(l,r)];\n\
    \    }\n\n    u32 sptMin(usize l,usize r) const {\n        usize dep = std::bit_width(r-l)-1,\
    \ i = m_spt[dep][l], j = m_spt[dep][r-(1u<<dep)];\n        return m_a[j] < m_a[i]\
    \ ? j : i;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/RMQ/PM1RMQ.hpp
  requiredBy:
  - Src/Graph/Tree/LowestCommonAncestor.hpp
  - Src/Graph/Tree/AuxiliaryTree.hpp
  - Src/Graph/Tree/ContourAggregation.hpp
  timestamp: '2026-04-20 16:41:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/lca/LowestCommonAncestor.test.cpp
  - Test/LC/vertex_get_range_contour_add_on_tree.test.cpp
  - Test/LC/vertex_add_range_contour_sum_on_tree.test.cpp
  - Test/Manual/typical90_ai.test.cpp
  - Test/AtCoder/abc340_g.test.cpp
  - Test/AtCoder/abc359_g.test.cpp
  - Test/My/DataStructure/RMQ/PM1RMQ.test.cpp
  - Test/My/Graph/Tree/LowestCommonAncestor.test.cpp
documentation_of: Src/DataStructure/RMQ/PM1RMQ.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/RMQ/PM1RMQ.hpp
- /library/Src/DataStructure/RMQ/PM1RMQ.hpp.html
title: Src/DataStructure/RMQ/PM1RMQ.hpp
---
