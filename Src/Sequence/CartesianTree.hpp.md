---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DPL_3_C.test.cpp
    title: Test/AOJ/DPL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/cartesian_tree.test.cpp
    title: Test/LC/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/CartesianTree.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/CartesianTree.hpp\"\n\n#include\
    \ <concepts>\n#include <cassert>\n#include <type_traits>\n#include <vector>\n\n\
    namespace zawa {\n\ntemplate <class T>\nclass CartesianTree {\npublic:\n\n   \
    \ static constexpr usize Invalid{static_cast<usize>(-1)};\n\n    struct Node {\n\
    \        usize left{Invalid}, right{Invalid}, par{Invalid}, idx{Invalid};\n  \
    \      T value{};\n        std::vector<usize> childs() const noexcept {\n    \
    \        std::vector<usize> res;\n            res.reserve(2);\n            if\
    \ (left != Invalid) res.push_back(left);\n            if (right != Invalid) res.push_back(right);\n\
    \            return res;\n        }\n        usize countChilds() const noexcept\
    \ {\n            return (left != Invalid) + (right != Invalid);\n        }\n \
    \   };\n\n    CartesianTree() = default;\n\n    template <class F>\n    requires\
    \ std::strict_weak_order<F, T, T>\n    CartesianTree(const std::vector<T>& A,\
    \ F comp) \n        : m_size{A.size()}, m_nodes(A.size()) {\n\n        std::vector<usize>\
    \ stack(A.size());\n        usize top{};\n        for (usize i{} ; i < size()\
    \ ; i++) {\n            if (top and comp(A[i], A[stack[top - 1]])) {\n       \
    \         while (top and comp(A[i], A[stack[top - 1]])) top--;\n             \
    \   m_nodes[i].left = stack[top];\n                m_nodes[stack[top]].par = i;\n\
    \            }\n            if (top) {\n                m_nodes[i].par = stack[top\
    \ - 1];\n                m_nodes[stack[top - 1]].right = i;\n            }\n \
    \           else {\n                m_root = i;\n            }\n            m_nodes[i].value\
    \ = A[i];\n            m_nodes[i].idx = i;\n            stack[top++] = i;\n  \
    \      }\n    }\n\n    inline usize size() const noexcept {\n        return m_size;\n\
    \    }\n\n    inline usize root() const noexcept {\n        return m_root;\n \
    \   }\n\n    inline T value(usize i) const noexcept {\n        assert(i < size());\n\
    \        return m_nodes[i].value;\n    }\n\n    inline usize parent(usize i) const\
    \ noexcept {\n        assert(i < size());\n        return m_nodes[i].par;\n  \
    \  }\n\n    inline usize left(usize i) const noexcept {\n        assert(i < size());\n\
    \        return m_nodes[i].left;\n    }\n\n    inline usize right(usize i) const\
    \ noexcept {\n        assert(i < size());\n        return m_nodes[i].right;\n\
    \    }\n\n    template <class F>\n    void treeDP(F func) {\n        static_assert(std::is_invocable_v<F,\
    \ const Node&>, \"F must be invocable f(const Node&)\");\n        dfs(m_root,\
    \ func);\n    }\n\nprivate:\n\n    template <class F>\n    void dfs(usize v, F\
    \ func) {\n        if (m_nodes[v].left != Invalid) dfs(m_nodes[v].left, func);\n\
    \        if (m_nodes[v].right != Invalid) dfs(m_nodes[v].right, func);\n     \
    \   func(m_nodes[v]);\n    }\n\n    usize m_size{}, m_root{Invalid};\n    std::vector<Node>\
    \ m_nodes;\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <concepts>\n\
    #include <cassert>\n#include <type_traits>\n#include <vector>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass CartesianTree {\npublic:\n\n    static constexpr\
    \ usize Invalid{static_cast<usize>(-1)};\n\n    struct Node {\n        usize left{Invalid},\
    \ right{Invalid}, par{Invalid}, idx{Invalid};\n        T value{};\n        std::vector<usize>\
    \ childs() const noexcept {\n            std::vector<usize> res;\n           \
    \ res.reserve(2);\n            if (left != Invalid) res.push_back(left);\n   \
    \         if (right != Invalid) res.push_back(right);\n            return res;\n\
    \        }\n        usize countChilds() const noexcept {\n            return (left\
    \ != Invalid) + (right != Invalid);\n        }\n    };\n\n    CartesianTree()\
    \ = default;\n\n    template <class F>\n    requires std::strict_weak_order<F,\
    \ T, T>\n    CartesianTree(const std::vector<T>& A, F comp) \n        : m_size{A.size()},\
    \ m_nodes(A.size()) {\n\n        std::vector<usize> stack(A.size());\n       \
    \ usize top{};\n        for (usize i{} ; i < size() ; i++) {\n            if (top\
    \ and comp(A[i], A[stack[top - 1]])) {\n                while (top and comp(A[i],\
    \ A[stack[top - 1]])) top--;\n                m_nodes[i].left = stack[top];\n\
    \                m_nodes[stack[top]].par = i;\n            }\n            if (top)\
    \ {\n                m_nodes[i].par = stack[top - 1];\n                m_nodes[stack[top\
    \ - 1]].right = i;\n            }\n            else {\n                m_root\
    \ = i;\n            }\n            m_nodes[i].value = A[i];\n            m_nodes[i].idx\
    \ = i;\n            stack[top++] = i;\n        }\n    }\n\n    inline usize size()\
    \ const noexcept {\n        return m_size;\n    }\n\n    inline usize root() const\
    \ noexcept {\n        return m_root;\n    }\n\n    inline T value(usize i) const\
    \ noexcept {\n        assert(i < size());\n        return m_nodes[i].value;\n\
    \    }\n\n    inline usize parent(usize i) const noexcept {\n        assert(i\
    \ < size());\n        return m_nodes[i].par;\n    }\n\n    inline usize left(usize\
    \ i) const noexcept {\n        assert(i < size());\n        return m_nodes[i].left;\n\
    \    }\n\n    inline usize right(usize i) const noexcept {\n        assert(i <\
    \ size());\n        return m_nodes[i].right;\n    }\n\n    template <class F>\n\
    \    void treeDP(F func) {\n        static_assert(std::is_invocable_v<F, const\
    \ Node&>, \"F must be invocable f(const Node&)\");\n        dfs(m_root, func);\n\
    \    }\n\nprivate:\n\n    template <class F>\n    void dfs(usize v, F func) {\n\
    \        if (m_nodes[v].left != Invalid) dfs(m_nodes[v].left, func);\n       \
    \ if (m_nodes[v].right != Invalid) dfs(m_nodes[v].right, func);\n        func(m_nodes[v]);\n\
    \    }\n\n    usize m_size{}, m_root{Invalid};\n    std::vector<Node> m_nodes;\n\
    };\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/CartesianTree.hpp
  requiredBy: []
  timestamp: '2024-11-14 17:39:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/cartesian_tree.test.cpp
  - Test/AOJ/DPL_3_C.test.cpp
documentation_of: Src/Sequence/CartesianTree.hpp
layout: document
title: Cartesian Tree
---

## 概要

数列に対して「最大値/最小値を境界に高々２つの区間に分ける」という操作の過程を木で表したものを構築する。

最大値・最小値で分ける分割統治と相性が良い。

## ライブラリの使い方

```cpp
template <class F>
requires std::strict_weak_order<F, T, T>
CartesianTree(const std::vector<T>& A, F comp)
```

`comp`は`T`に関する狭義の弱順序、$comp :T\times T\rightarrow \text{bool}$ である必要がある。
