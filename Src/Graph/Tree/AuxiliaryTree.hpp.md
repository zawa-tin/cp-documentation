---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RMQ/PM1RMQ.hpp
    title: Src/DataStructure/RMQ/PM1RMQ.hpp
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
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\
    \n\n#line 4 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\n\n#include <algorithm>\n#include\
    \ <array>\n#include <bit>\n#include <cassert>\n#include <concepts>\n#include <utility>\n\
    #include <vector>\n\n\nnamespace zawa {\n\ntemplate <std::totally_ordered T>\n\
    class PM1RMQ {\nprivate:\n\n    static constexpr usize B = 8;\n\n    static constexpr\
    \ usize BMASK = 7;\n\n    static constexpr usize LOGB = 3;\n\n    static constexpr\
    \ usize TRI = B*(B+1)/2;\n\npublic:\n\n    PM1RMQ() = default;\n\n    PM1RMQ(std::vector<T>\
    \ a) \n        : m_n{a.size()}, m_inner{(a.size()+B-1)>>LOGB},\n        m_a{std::move(a)},\
    \ m_look(innerSize()), m_table(), m_spt(std::bit_width(innerSize()))\n    {\n\
    \        std::vector<u32> minIndex(innerSize());\n        std::vector<bool> registered(1u\
    \ << (B-1));\n        for (usize i = 0,idx = 0 ; i < size() ; idx++) {\n     \
    \       minIndex[idx] = i;\n            for (u8 j = 1 ; ++i < size() and j < (u8)B\
    \ ; j++) {\n                if (m_a[i] < m_a[minIndex[idx]])\n               \
    \     minIndex[idx] = i;\n                if (m_a[i] == m_a[i-1]+1)\n        \
    \            ;\n                else if (m_a[i] == m_a[i-1]-1)\n             \
    \       m_look[idx] |= u8{1} << (j-1);\n                else\n               \
    \     assert(!\"init table does not satisfy |a_i-a_{i+1}| = 1\");\n          \
    \  }\n            if (!registered[m_look[idx]]) {\n                registered[m_look[idx]]\
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
    \ ? j : i;\n    }\n};\n\n} // namespace zawa\n#line 5 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\
    \n\n#line 9 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\n\nnamespace zawa {\n\n\
    template <class V>\nclass LowestCommonAncestor {\npublic:\n\n    LowestCommonAncestor()\
    \ = default;\n\n    LowestCommonAncestor(const std::vector<std::vector<V>>& g,V\
    \ r = 0) \n        : m_n{g.size()}, m_inv{}, m_left(size()), m_right(size()),\
    \ m_dep(size())\n    {\n        std::vector<u32> ord;\n        ord.reserve(2*size());\n\
    \        m_inv.reserve(2*size());\n        auto dfs = [&](auto dfs,V v,V p,u32\
    \ d) -> void {\n            m_left[v] = ord.size();\n            ord.push_back(d);\n\
    \            m_inv.push_back(v);\n            m_dep[v] = d;\n            for (V\
    \ x : g[v])\n                if (x != p) {\n                    dfs(dfs,x,v,d+1);\n\
    \                    ord.push_back(d);\n                    m_inv.push_back(v);\n\
    \                }\n            m_right[v] = ord.size();\n        };\n       \
    \ dfs(dfs,r,static_cast<V>(-1),0);\n        m_rmq = PM1RMQ{std::move(ord)};\n\
    \    }\n\n    V lca(V u,V v) const {\n        assert(verify(u));\n        assert(verify(v));\n\
    \        if (u == v)\n            return u;\n        if (m_left[u] > m_left[v])\n\
    \            std::swap(u,v);\n        return m_inv[m_rmq.min(m_left[u],m_right[v])];\n\
    \    }\n\n    V operator()(V u,V v) const {\n        return lca(u,v);\n    }\n\
    \n    inline usize depth(V v) const {\n        assert(verify(v));\n        return\
    \ m_dep[v];\n    }\n\n    usize distance(V u,V v) const {\n        assert(verify(u));\n\
    \        assert(verify(v));\n        return m_dep[u] + m_dep[v] - 2*m_dep[lca(u,v)];\n\
    \    }\n\n    bool isAncestor(V p,V v) const {\n        assert(verify(p));\n \
    \       assert(verify(v));\n        return m_left[p] <= m_left[v] and m_right[v]\
    \ <= m_right[p];\n    }\n\n    std::pair<usize,usize> subtreeRange(V v) const\
    \ {\n        assert(verify(v));\n        return {m_left[v],m_right[v]};\n    }\n\
    \nprotected:\n\n    inline usize size() const {\n        return m_n;\n    }\n\n\
    \    inline bool verify(V v) const {\n        return static_cast<usize>(v) < size();\n\
    \    }\n\n    inline usize left(V v) const {\n        assert(verify(v));\n   \
    \     return m_left[v];\n    }\n\n    inline usize right(V v) const {\n      \
    \  assert(verify(v));\n        return m_right[v];\n    }\n\nprivate:\n\n    usize\
    \ m_n;\n    \n    std::vector<usize> m_inv,m_left,m_right,m_dep;\n\n    PM1RMQ<u32>\
    \ m_rmq;\n};\n\n} // namespace zawa\n#line 4 \"Src/Graph/Tree/AuxiliaryTree.hpp\"\
    \n\n#line 6 \"Src/Graph/Tree/AuxiliaryTree.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class V>\nclass AuxiliaryTree : public LowestCommonAncestor<V> {\npublic:\n\
    \    using Super = LowestCommonAncestor<V>;\n\n    AuxiliaryTree() = default;\n\
    \    AuxiliaryTree(const std::vector<std::vector<V>>& T, V r = 0u) \n        :\
    \ Super{ T, r }, T_(T.size()), dist_(T.size()), used_(T.size()) {}\n\n    V construct(const\
    \ std::vector<V>& vs) {\n        assert(vs.size());\n        clear();\n      \
    \  vs_ = vs;\n        return build();\n    }\n\n    const std::vector<V>& operator[](V\
    \ v) const {\n        assert(Super::verify(v));\n        return T_[v];\n    }\n\
    \n    inline bool contains(V v) const {\n        assert(Super::verify(v));\n \
    \       return used_[v];\n    }\n\n    inline u32 parentEdgeLength(V v) const\
    \ {\n        assert(contains(v));\n        return dist_[v];\n    }\n\n    std::vector<V>\
    \ current() const {\n        return vs_;\n    }\n\nprivate:\n    std::vector<std::vector<V>>\
    \ T_{}; \n    std::vector<V> vs_{};\n    std::vector<u32> dist_{};\n    std::vector<bool>\
    \ used_{};\n\n    void addEdge(V p, V v) {\n        assert(Super::depth(p) < Super::depth(v));\n\
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
  - Src/DataStructure/RMQ/PM1RMQ.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/AuxiliaryTree.hpp
  requiredBy: []
  timestamp: '2026-04-20 16:41:41+09:00'
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
