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
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc340_e.test.cpp
    title: Test/AtCoder/abc340_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc389_f.test.cpp
    title: Test/AtCoder/abc389_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc088_e.test.cpp
    title: Test/AtCoder/arc088_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\n\n\
    #line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#include <concepts>\n\n\
    namespace zawa {\n\nnamespace Concept {\n\ntemplate <class T>\nconcept Monoid\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n    { T::operation(std::declval<typename T::Element>(), std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\n} // namespace\n\
    \n} // namespace zawa\n#line 4 \"Src/Algebra/Group/GroupConcept.hpp\"\n\nnamespace\
    \ zawa {\n\nnamespace Concept {\n\ntemplate <class T>\nconcept Inversible = requires\
    \ {\n    typename T::Element;\n    { T::inverse(std::declval<typename T::Element>())\
    \ } -> std::same_as<typename T::Element>;\n};\n\ntemplate <class T>\nconcept Group\
    \ = Monoid<T> and Inversible<T>;\n\n} // namespace Concept\n\n} // namespace zawa\n\
    #line 5 \"Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\n\n#include <bit>\n\
    #include <cassert>\n#include <iterator>\n#include <optional>\n#include <vector>\n\
    \nnamespace zawa {\n\nnamespace Concept {\n\ntemplate <class F, class V>\nconcept\
    \ Predicate = requires {\n    { std::declval<F>()(std::declval<V>()) } -> std::same_as<bool>;\
    \ \n};\n\n} // namespace Concept\n\ntemplate <Concept::Group G>\nclass DualFenwickTree\
    \ {\npublic:\n\n    using V = typename G::Element;\n\n    constexpr static u32\
    \ Log2(usize n) noexcept {\n        return static_cast<u32>(\n               \
    \     std::bit_width(n) - (std::has_single_bit(n) ? 1 : 0)\n                );\n\
    \    }\n\n    DualFenwickTree() = default;\n\n    DualFenwickTree(usize n) : n_{n},\
    \ lg_{Log2(n)}, dat_(n+1, G::identity()) {\n        assert(n);\n    }\n\n    DualFenwickTree(const\
    \ std::vector<V>& d) : n_{d.size()}, lg_{Log2(n_)}, dat_(d.size() + 1, G::identity())\
    \ {\n        assert(d.size());\n        add(0, d[0]);\n        for (usize i =\
    \ 1 ; i < d.size() ; i++) add(i, G::operation(G::inverse(d[i - 1]), d[i]));\n\
    \    }\n\n    template <std::input_iterator It>\n    DualFenwickTree(It first,\
    \ It last) \n    : n_{static_cast<usize>(std::distance(first, last))}, lg_{Log2(n_)},\
    \ dat_(n_ + 1, G::identity()) {\n        assert(first != last);\n        V pv\
    \ = static_cast<V>(*first);\n        add(0, pv);\n        for (usize i = 1 ; i\
    \ < n_ ; i++) {\n            first++;\n            V v = static_cast<V>(*first);\n\
    \            add(i, G::operation(G::inverse(pv), v));\n            pv = v;\n \
    \       } \n    }\n\n    inline usize size() const noexcept {\n        return\
    \ n_;\n    }\n\n    void operation(usize l, usize r, const V& v) {\n        assert(l\
    \ <= r and r <= size());\n        if (l < r) {\n            add(l, v);\n     \
    \       if (r < size()) add(r, G::inverse(v));\n        }\n    }\n\n    void operation(usize\
    \ i, const V& v) {\n        assert(i < size());\n        operation(i, i + 1, v);\n\
    \    }\n\n    V operator[](i32 i) const {\n        assert(0 <= i and i < (i32)size());\n\
    \        V res = G::identity();\n        for (i++ ; i ; i -= lsb(i)) res = G::operation(dat_[i],\
    \ res);\n        return res;\n    }\n\n    void set(usize i, V v) {\n        assert(0\
    \ <= i and i < size());\n        v = G::operation(G::inverse((*this)[i]), v);\n\
    \        operation(i, v);\n    }\n\n    template <class F>\n    requires Concept::Predicate<F,\
    \ V>\n    std::optional<usize> maxRight(usize l, F f) {\n        assert(l < size());\n\
    \        V sum = l ? (*this)[l - 1] : G::identity();\n        usize r = 0;\n \
    \       for (u32 w = lg_ ; w <= lg_ ; w--) {\n            usize next = r | (1u\
    \ << w);\n            if (next >= dat_.size()) continue;\n            V nsum =\
    \ G::operation(sum, dat_[next]);\n            if (f(nsum)) {\n               \
    \ sum = std::move(nsum);\n                r = std::move(next);\n            }\n\
    \        }\n        assert(l <= r);\n        return r == size() and f(sum) ? std::nullopt\
    \ : std::optional{r};\n    }\n\n    // \u5B9F\u88C5\u304C\u5408\u3044\u307E\u305B\
    \u3093\u3002\u982D\u304C\u60AA\u3044\u306E\u3067\n    // template <class F>\n\
    \    // requires Concept::Predicate<F, V>\n    // std::optional<usize> minLeft(usize\
    \ r, F f) const {\n    //     assert(r <= n_);\n    //     V sum = G::identity();\n\
    \    //     usize l = 0;\n    //     for (u32 w = lg_ ; w <= lg_ ; w--) {\n  \
    \  //         u32 next = l | (1u << w);\n    //         if (next >= r) continue;\n\
    \    //         V nsum = G::operation(dat_[next], sum);\n    //         if (!f(nsum))\
    \ {\n    //             sum = std::move(nsum);\n    //             l = std::move(next);\n\
    \    //         }\n    //     }\n    //     assert(l <= r);\n    //     if (l\
    \ + 1 == r and !f(sum)) return r;\n    //     return l == 0u and f(sum) ? std::nullopt\
    \ : std::optional{l};\n    // }\n\nprivate:\n\n    usize n_;\n\n    u32 lg_;\n\
    \n    std::vector<V> dat_;\n\n    constexpr i32 lsb(i32 x) const noexcept {\n\
    \        return x & -x;\n    }\n\n    void add(i32 i, const V& v) {\n        for\
    \ (i++ ; i <= (i32)size() ; i += lsb(i)) dat_[i] = G::operation(dat_[i], v);\n\
    \    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Group/GroupConcept.hpp\"\
    \n\n#include <bit>\n#include <cassert>\n#include <iterator>\n#include <optional>\n\
    #include <vector>\n\nnamespace zawa {\n\nnamespace Concept {\n\ntemplate <class\
    \ F, class V>\nconcept Predicate = requires {\n    { std::declval<F>()(std::declval<V>())\
    \ } -> std::same_as<bool>; \n};\n\n} // namespace Concept\n\ntemplate <Concept::Group\
    \ G>\nclass DualFenwickTree {\npublic:\n\n    using V = typename G::Element;\n\
    \n    constexpr static u32 Log2(usize n) noexcept {\n        return static_cast<u32>(\n\
    \                    std::bit_width(n) - (std::has_single_bit(n) ? 1 : 0)\n  \
    \              );\n    }\n\n    DualFenwickTree() = default;\n\n    DualFenwickTree(usize\
    \ n) : n_{n}, lg_{Log2(n)}, dat_(n+1, G::identity()) {\n        assert(n);\n \
    \   }\n\n    DualFenwickTree(const std::vector<V>& d) : n_{d.size()}, lg_{Log2(n_)},\
    \ dat_(d.size() + 1, G::identity()) {\n        assert(d.size());\n        add(0,\
    \ d[0]);\n        for (usize i = 1 ; i < d.size() ; i++) add(i, G::operation(G::inverse(d[i\
    \ - 1]), d[i]));\n    }\n\n    template <std::input_iterator It>\n    DualFenwickTree(It\
    \ first, It last) \n    : n_{static_cast<usize>(std::distance(first, last))},\
    \ lg_{Log2(n_)}, dat_(n_ + 1, G::identity()) {\n        assert(first != last);\n\
    \        V pv = static_cast<V>(*first);\n        add(0, pv);\n        for (usize\
    \ i = 1 ; i < n_ ; i++) {\n            first++;\n            V v = static_cast<V>(*first);\n\
    \            add(i, G::operation(G::inverse(pv), v));\n            pv = v;\n \
    \       } \n    }\n\n    inline usize size() const noexcept {\n        return\
    \ n_;\n    }\n\n    void operation(usize l, usize r, const V& v) {\n        assert(l\
    \ <= r and r <= size());\n        if (l < r) {\n            add(l, v);\n     \
    \       if (r < size()) add(r, G::inverse(v));\n        }\n    }\n\n    void operation(usize\
    \ i, const V& v) {\n        assert(i < size());\n        operation(i, i + 1, v);\n\
    \    }\n\n    V operator[](i32 i) const {\n        assert(0 <= i and i < (i32)size());\n\
    \        V res = G::identity();\n        for (i++ ; i ; i -= lsb(i)) res = G::operation(dat_[i],\
    \ res);\n        return res;\n    }\n\n    void set(usize i, V v) {\n        assert(0\
    \ <= i and i < size());\n        v = G::operation(G::inverse((*this)[i]), v);\n\
    \        operation(i, v);\n    }\n\n    template <class F>\n    requires Concept::Predicate<F,\
    \ V>\n    std::optional<usize> maxRight(usize l, F f) {\n        assert(l < size());\n\
    \        V sum = l ? (*this)[l - 1] : G::identity();\n        usize r = 0;\n \
    \       for (u32 w = lg_ ; w <= lg_ ; w--) {\n            usize next = r | (1u\
    \ << w);\n            if (next >= dat_.size()) continue;\n            V nsum =\
    \ G::operation(sum, dat_[next]);\n            if (f(nsum)) {\n               \
    \ sum = std::move(nsum);\n                r = std::move(next);\n            }\n\
    \        }\n        assert(l <= r);\n        return r == size() and f(sum) ? std::nullopt\
    \ : std::optional{r};\n    }\n\n    // \u5B9F\u88C5\u304C\u5408\u3044\u307E\u305B\
    \u3093\u3002\u982D\u304C\u60AA\u3044\u306E\u3067\n    // template <class F>\n\
    \    // requires Concept::Predicate<F, V>\n    // std::optional<usize> minLeft(usize\
    \ r, F f) const {\n    //     assert(r <= n_);\n    //     V sum = G::identity();\n\
    \    //     usize l = 0;\n    //     for (u32 w = lg_ ; w <= lg_ ; w--) {\n  \
    \  //         u32 next = l | (1u << w);\n    //         if (next >= r) continue;\n\
    \    //         V nsum = G::operation(dat_[next], sum);\n    //         if (!f(nsum))\
    \ {\n    //             sum = std::move(nsum);\n    //             l = std::move(next);\n\
    \    //         }\n    //     }\n    //     assert(l <= r);\n    //     if (l\
    \ + 1 == r and !f(sum)) return r;\n    //     return l == 0u and f(sum) ? std::nullopt\
    \ : std::optional{l};\n    // }\n\nprivate:\n\n    usize n_;\n\n    u32 lg_;\n\
    \n    std::vector<V> dat_;\n\n    constexpr i32 lsb(i32 x) const noexcept {\n\
    \        return x & -x;\n    }\n\n    void add(i32 i, const V& v) {\n        for\
    \ (i++ ; i <= (i32)size() ; i += lsb(i)) dat_[i] = G::operation(dat_[i], v);\n\
    \    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  isVerificationFile: false
  path: Src/DataStructure/FenwickTree/DualFenwickTree.hpp
  requiredBy: []
  timestamp: '2025-03-03 23:11:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc389_f.test.cpp
  - Test/AtCoder/arc088_e.test.cpp
  - Test/AtCoder/abc340_e.test.cpp
documentation_of: Src/DataStructure/FenwickTree/DualFenwickTree.hpp
layout: document
title: Dual Fenwick Tree
---

## 概要

可換群 $G = (S, \circ)$ 上で列上の区間加算、一点取得クエリに答えることができるデータ構造です。

- 以後、管理する列を $A$ とします。

## ライブラリの使い方

#### テンプレート引数

```cpp
template <Concept::Group G>
```

いつもの。雛形は以下から

```cpp
class G {
public:
    using Element = ;
    static T identity() noexcept {
    }
    static T operation(const T& l, const T& r) noexcept {
    }
    static T inverse(const T& v) noexcept {
    }
};
```

以下、`G::Element`を`V`と略す。

<br />

#### コンストラクタ

```cpp
(1) FenwickTree()
(2) FenwickTree(usize n)
(3) FenwickTree(const std::vector<V>& d)
(4) FenwickTree<std::input_iterator It>(It first, It last)
```

(2) $A$ を長さ $n$ で各要素が `Group::identity` である列で初期化します

**計算量**: $O(n)$

(3) $A$ を `d` で初期化します

**計算量**: `d`の長さを $n$ として $O(n\log n)$

(4) $A$ をiterator範囲[first, last)で初期化します。

**計算量**: `std::distance(first, last)`を $n$ として $O(n\log n)$


<br />

#### get, operator[]

```cpp
V operator[](usize i) const
```

$A_i$ を返します。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: $O(\log n)$

<br/>

#### size

```cpp
usize size() const noexcept
```

$A$ の要素数を返します。

**計算量**: 定数時間

<br />

#### operation

```cpp
void operation(usize i, const Value& v) (1)
void operation(usize l, usize r, const Value& v) (2)
```

(1) $A_i$ を $A_i \circ v$ に置き換えます。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: $O(\log n)$

(2) $A_{l}, A_{l+1}, \dots, A_{r - 1}$ にそれぞれ $v$ を加算する。

**制約**: $0\ \le\ l\ \le r\ \le n$

**計算量**: $O(\log n)$

<br />

#### set

```cpp
void set(usize i, const Value& v)
```
$A_i$ を $v$ を置き換えます。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: $O(\log n)$

#### maxRight

```cpp
template <class F>
requires Concept::Predicate<F, V>
std::optional<usize> maxRight(usize l, F f) const
```

ある$l$ 以上の整数 $m$ が存在して、 $l$ 以上 $m$ 未満の整数 $i$ について $\displaystyle f(A_{j}) = \text{true}$ かつ $m$ 以上の整数 $i$ について $f(A_{j}) = \text{false}$ であることを仮定します。

そのような状況で、 $m$ を発見して返します。

ただし、 $f(\displaystyle \prod_{i = l}^{n - 1} A_{i}) = \text{true}$ の時は `std::nullopt` を返します。

**制約**

- $0\ \le\ l\ <\ n$
- `f` は`V`型の変数`v`に対して`f(v)`と関数呼び出し可能であり、その返り値が`bool`型である。
- `f`は上記の仮定を満たす

**計算量**: $O(\log n)$

<br />
