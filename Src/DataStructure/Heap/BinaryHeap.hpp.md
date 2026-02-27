---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Heap/EraseablePriorityQueue.hpp
    title: Src/DataStructure/Heap/EraseablePriorityQueue.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Heap/PartitionedProducts.hpp
    title: "\u8981\u7D20\u6607\u9806 $K$ \u500B\u3001\u964D\u9806 $N - K$ \u500B\u306E\
      \u7DCF\u7A4D\u3092\u7BA1\u7406"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/ContourAggregation.hpp
    title: "\u6728\u4E0A\u306E\u7B49\u9AD8\u7DDA\u30AF\u30A8\u30EA"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc306_e.test.cpp
    title: Test/AtCoder/abc306_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc440_f.test.cpp
    title: Test/AtCoder/abc440_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc196_a.test.cpp
    title: Test/AtCoder/arc196_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_add_range_contour_sum_on_tree.test.cpp
    title: Test/LC/vertex_add_range_contour_sum_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_get_range_contour_add_on_tree.test.cpp
    title: Test/LC/vertex_get_range_contour_add_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/My/DataStructure/Heap/BinaryHeap.test.cpp
    title: Test/My/DataStructure/Heap/BinaryHeap.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/My/DataStructure/Heap/BinaryHeapCompVector.test.cpp
    title: Test/My/DataStructure/Heap/BinaryHeapCompVector.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/Heap/BinaryHeap.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
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
    \            i = j;\n        }\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <concepts>\n#include <utility>\n#include <vector>\n\
    #include <functional>\n\nnamespace zawa {\n\ntemplate <class T, class Comp = std::less<T>>\n\
    requires std::strict_weak_order<Comp, const T&, const T&>\nclass BinaryHeap {\n\
    private:\n\n    Comp m_comp;\n\n    std::vector<T> m_dat;\n\npublic:\n\n    inline\
    \ usize size() const {\n        return m_dat.size() - 1;\n    }\n\n    inline\
    \ bool empty() const {\n        return m_dat.size() == 1;\n    }\n\n    inline\
    \ const Comp& comp() const {\n        return m_comp;\n    }\n\n    using const_iterator\
    \ = typename decltype(m_dat)::const_iterator;\n\n    const_iterator begin() const\
    \ {\n        return m_dat.begin() + 1;\n    }\n\n    const_iterator end() const\
    \ {\n        return m_dat.end();\n    }\n\n    BinaryHeap(Comp comp = {}) \n \
    \       : m_comp{comp}, m_dat(1) {}\n\n    template <std::forward_iterator It>\n\
    \    requires std::same_as<std::iter_value_t<It>, T>\n    BinaryHeap(It first,\
    \ It last, Comp comp = {}) \n        : m_comp{comp}, m_dat(1) {\n        m_dat.insert(m_dat.end(),\
    \ first, last);\n        build();\n    }\n\n    BinaryHeap(std::vector<T>&& a,\
    \ Comp comp = {}) \n        : m_comp{comp}, m_dat(a.size() + 1) {\n        std::ranges::copy(std::make_move_iterator(a.begin()),\
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
    \            i = j;\n        }\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/Heap/BinaryHeap.hpp
  requiredBy:
  - Src/Graph/Tree/ContourAggregation.hpp
  - Src/DataStructure/Heap/EraseablePriorityQueue.hpp
  - Src/DataStructure/Heap/PartitionedProducts.hpp
  timestamp: '2026-01-14 16:33:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/vertex_add_range_contour_sum_on_tree.test.cpp
  - Test/LC/vertex_get_range_contour_add_on_tree.test.cpp
  - Test/My/DataStructure/Heap/BinaryHeap.test.cpp
  - Test/My/DataStructure/Heap/BinaryHeapCompVector.test.cpp
  - Test/AtCoder/arc196_a.test.cpp
  - Test/AtCoder/abc306_e.test.cpp
  - Test/AtCoder/abc440_f.test.cpp
documentation_of: Src/DataStructure/Heap/BinaryHeap.hpp
layout: document
title: "Binary Heap (\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC)"
---

## ライブラリの使い方

要素`a`に対して、`comp(a, b)`が`true`になる方が強いという優先度を設けたPriority Queue。`std::priority_queue`とは逆向きの優先度付けをしているが、こちらの方が直感的に自然だと思う。

### テンプレート

```cpp
template <class T, class Comp = std::less<T>>
requires std::strict_weak_order<Comp, const T&, const T&>
```

デフォルトでは最小値を`top`に持ってくるようになる

### コンストラクタ

```cpp
BinaryHeap(Comp comp = {}) // (1)

template <std::forward_iterator It>
requires std::same_as<std::iter_value_t<It>, T>
BinaryHeap(It first, It last, Comp comp = {}) // (2)

BinaryHeap(std::vector<T>&& a, Comp comp = {})  // (3)

BinaryHeap(const std::vector<T>& a, Comp comp = {}) // (4)
```

(1): 空で初期化 $O(1)$

(2), (3), (4): ヒープを構築する。 $O(N)$
- 空から一個ずつ挿入するより計算量が良いことに注意。まぁ実測はあまり変わらなかったんだけど...

### メンバ

```cpp
inline usize size() const;
inline bool empty() const;
const_iterator begin() const;
const_iterator end() const;
const T& top() const;
void push(T&&);
void push(const T&);
void pop();
```

`std::priority_queue`と同じ。`begin(), end()`が提供されているので、`cout << std::vector(que.begin(), que.end()) << endl;`みたいなこともできる。
- また、空のキューに対する`top, pop`は`assert`で落ちるようになっている。
