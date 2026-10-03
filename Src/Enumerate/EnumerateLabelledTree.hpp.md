---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Heap/BinaryHeap.hpp
    title: "Binary Heap (\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC)"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Enumerate/EnumerateLabelledTree.hpp\"\n\n#line 2 \"\
    Src/DataStructure/Heap/BinaryHeap.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/DataStructure/Heap/BinaryHeap.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <concepts>\n#include <utility>\n#include\
    \ <vector>\n#include <functional>\n\nnamespace zawa {\n\ntemplate <class T, class\
    \ Comp = std::less<T>>\nrequires std::strict_weak_order<Comp, const T&, const\
    \ T&>\nclass BinaryHeap {\nprivate:\n\n    Comp m_comp;\n\n    std::vector<T>\
    \ m_dat;\n\npublic:\n\n    inline usize size() const {\n        return m_dat.size()\
    \ - 1;\n    }\n\n    inline bool empty() const {\n        return m_dat.size()\
    \ == 1;\n    }\n\n    inline const Comp& comp() const {\n        return m_comp;\n\
    \    }\n\n    using const_iterator = typename decltype(m_dat)::const_iterator;\n\
    \n    const_iterator begin() const {\n        return m_dat.begin() + 1;\n    }\n\
    \n    const_iterator end() const {\n        return m_dat.end();\n    }\n\n   \
    \ BinaryHeap(Comp comp = {}) \n        : m_comp{comp}, m_dat(1) {}\n\n    template\
    \ <std::forward_iterator It>\n    requires std::same_as<std::iter_value_t<It>,\
    \ T>\n    BinaryHeap(It first, It last, Comp comp = {}) \n        : m_comp{comp},\
    \ m_dat(1) {\n        m_dat.insert(m_dat.end(), first, last);\n        build();\n\
    \    }\n\n    BinaryHeap(std::vector<T>&& a, Comp comp = {}) \n        : m_comp{comp},\
    \ m_dat(a.size() + 1) {\n        std::ranges::copy(std::make_move_iterator(a.begin()),\
    \ std::make_move_iterator(a.end()), m_dat.begin() + 1);\n        build();\n  \
    \  }\n\n    BinaryHeap(const std::vector<T>& a, Comp comp = {}) \n        : m_comp{comp},\
    \ m_dat(a.size() + 1) {\n        std::ranges::copy(a.begin(), a.end(), m_dat.begin()\
    \ + 1);\n        build();\n    }\n\n    const T& top() const {\n        assert(size()\
    \ and \"HeapUnderFlow\");\n        return m_dat[1];\n    }\n\n    void push(T&&\
    \ v) {\n        m_dat.push_back(std::move(v));\n        upHeap(size());\n    }\n\
    \n    void push(const T& v) {\n        m_dat.push_back(v);\n        upHeap(size());\n\
    \    }\n\n    void pop() {\n        assert(size() and \"HeapUnderFlow\");\n  \
    \      if (size() > 1)\n            std::swap(m_dat[1], m_dat.back());\n     \
    \   m_dat.pop_back();\n        if (size() > 1)\n            downHeap(1, size());\n\
    \    }\n\nprivate:\n\n    void build() {\n        const usize n = size();\n  \
    \      for (usize i = (n >> 1) ; i ; i--) \n            downHeap(i, n);\n    }\n\
    \n    void upHeap(usize i) {\n        while (i >> 1 and m_comp(m_dat[i], m_dat[i\
    \ >> 1])) {\n            std::swap(m_dat[i], m_dat[i >> 1]);\n            i >>=\
    \ 1;\n        }\n    }\n\n    void downHeap(usize i, usize n) {\n        while\
    \ ((i << 1) <= n) {\n            usize j = i << 1;\n            if (j + 1 <= n\
    \ and m_comp(m_dat[j + 1], m_dat[j]))\n                j++;\n            if (!m_comp(m_dat[j],\
    \ m_dat[i]))\n                break;\n            std::swap(m_dat[i], m_dat[j]);\n\
    \            i = j;\n        }\n    }\n};\n\n} // namespace zawa\n#line 4 \"Src/Enumerate/EnumerateLabelledTree.hpp\"\
    \n\n#line 6 \"Src/Enumerate/EnumerateLabelledTree.hpp\"\n#include <iterator>\n\
    #line 9 \"Src/Enumerate/EnumerateLabelledTree.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ enumerate {\n\ntemplate <class T>\nclass LabelledTree {\npublic:\n\n    using\
    \ Tree = std::vector<std::pair<T,T>>;\n\n    explicit LabelledTree(T n) : m_n(n)\
    \ {\n        assert(n >= 0);\n    }\n\n    class Iterator {\n    public:\n\n \
    \       using iterator_concept = std::input_iterator_tag;\n\n        using value_type\
    \ = Tree;\n\n        using difference_type = std::ptrdiff_t;\n\n        Iterator()\
    \ = default;\n\n        explicit Iterator(T n) : m_n(n),m_code(n >= 2 ? n - 2\
    \ : 0),m_fin(n == 0) {\n            assert(n >= 0);\n        }\n\n        Tree\
    \ operator*() const {\n            if (m_n == 1) \n                return {};\n\
    \            std::vector<T> deg(m_n,1);\n            for (T v : m_code)\n    \
    \            deg[v]++;\n            BinaryHeap<T> que;\n            for (T v =\
    \ 0; v < m_n; v++)\n                if (deg[v] == 1)\n                    que.push(v);\n\
    \            Tree edges;\n            edges.reserve(m_n - 1);\n            for\
    \ (T v : m_code) {\n                T u = que.top();\n                que.pop();\n\
    \                edges.emplace_back(u,v);\n                deg[u]--;\n       \
    \         if (--deg[v] == 1)\n                    que.push(v);\n            }\n\
    \            T u = que.top();\n            que.pop();\n            T v = que.top();\n\
    \            edges.emplace_back(u,v);\n            return edges;\n        }\n\n\
    \        Iterator& operator++() {\n            for (T i = static_cast<T>(std::ssize(m_code))\
    \ ; i-- ; ) {\n                if (++m_code[i] < m_n)\n                    return\
    \ *this;\n                m_code[i] = 0;\n            }\n            m_fin = true;\n\
    \            return *this;\n        }\n\n        void operator++(int) {\n    \
    \        ++*this;\n        }\n\n        friend bool operator==(const Iterator&\
    \ it,std::default_sentinel_t) {\n            return it.m_fin;\n        }\n\n \
    \   private:\n\n        T m_n = 0;\n\n        std::vector<T> m_code;\n\n     \
    \   bool m_fin = true;\n\n    };\n\n    Iterator begin() const {\n        return\
    \ Iterator(m_n);\n    }\n\n    std::default_sentinel_t end() const {\n       \
    \ return {};\n    }\n\nprivate:\n\n    T m_n;\n};\n\n} // namespace enumerate\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../DataStructure/Heap/BinaryHeap.hpp\"\n\n#include\
    \ <concepts>\n#include <iterator>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ zawa {\n\nnamespace enumerate {\n\ntemplate <class T>\nclass LabelledTree {\n\
    public:\n\n    using Tree = std::vector<std::pair<T,T>>;\n\n    explicit LabelledTree(T\
    \ n) : m_n(n) {\n        assert(n >= 0);\n    }\n\n    class Iterator {\n    public:\n\
    \n        using iterator_concept = std::input_iterator_tag;\n\n        using value_type\
    \ = Tree;\n\n        using difference_type = std::ptrdiff_t;\n\n        Iterator()\
    \ = default;\n\n        explicit Iterator(T n) : m_n(n),m_code(n >= 2 ? n - 2\
    \ : 0),m_fin(n == 0) {\n            assert(n >= 0);\n        }\n\n        Tree\
    \ operator*() const {\n            if (m_n == 1) \n                return {};\n\
    \            std::vector<T> deg(m_n,1);\n            for (T v : m_code)\n    \
    \            deg[v]++;\n            BinaryHeap<T> que;\n            for (T v =\
    \ 0; v < m_n; v++)\n                if (deg[v] == 1)\n                    que.push(v);\n\
    \            Tree edges;\n            edges.reserve(m_n - 1);\n            for\
    \ (T v : m_code) {\n                T u = que.top();\n                que.pop();\n\
    \                edges.emplace_back(u,v);\n                deg[u]--;\n       \
    \         if (--deg[v] == 1)\n                    que.push(v);\n            }\n\
    \            T u = que.top();\n            que.pop();\n            T v = que.top();\n\
    \            edges.emplace_back(u,v);\n            return edges;\n        }\n\n\
    \        Iterator& operator++() {\n            for (T i = static_cast<T>(std::ssize(m_code))\
    \ ; i-- ; ) {\n                if (++m_code[i] < m_n)\n                    return\
    \ *this;\n                m_code[i] = 0;\n            }\n            m_fin = true;\n\
    \            return *this;\n        }\n\n        void operator++(int) {\n    \
    \        ++*this;\n        }\n\n        friend bool operator==(const Iterator&\
    \ it,std::default_sentinel_t) {\n            return it.m_fin;\n        }\n\n \
    \   private:\n\n        T m_n = 0;\n\n        std::vector<T> m_code;\n\n     \
    \   bool m_fin = true;\n\n    };\n\n    Iterator begin() const {\n        return\
    \ Iterator(m_n);\n    }\n\n    std::default_sentinel_t end() const {\n       \
    \ return {};\n    }\n\nprivate:\n\n    T m_n;\n};\n\n} // namespace enumerate\n\
    \n} // namespace zawa\n"
  dependsOn:
  - Src/DataStructure/Heap/BinaryHeap.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Enumerate/EnumerateLabelledTree.hpp
  requiredBy: []
  timestamp: '2026-10-04 00:00:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Src/Enumerate/EnumerateLabelledTree.hpp
layout: document
redirect_from:
- /library/Src/Enumerate/EnumerateLabelledTree.hpp
- /library/Src/Enumerate/EnumerateLabelledTree.hpp.html
title: Src/Enumerate/EnumerateLabelledTree.hpp
---
