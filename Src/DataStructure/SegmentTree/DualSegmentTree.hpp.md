---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Action/ActionConcept.hpp
    title: Src/Algebra/Action/ActionConcept.hpp
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
    path: Test/AtCoder/abc332_f.test.cpp
    title: "ABC332-F Random Update Query (a <- ap + q\u306E\u51E6\u7406)"
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc457_f.test.cpp
    title: Test/AtCoder/abc457_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/pakencamp_2025_day1_l.test.cpp
    title: Test/AtCoder/pakencamp_2025_day1_l.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_affine_point_get.test.cpp
    title: Test/LC/range_affine_point_get.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/SegmentTree/DualSegmentTree.hpp\"\n\n\
    #line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Action/ActionConcept.hpp\"\
    \n\n#line 4 \"Src/Algebra/Action/ActionConcept.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class G, class X>\nconcept Action = requires {\n   \
    \ typename G::Element;\n    { G::action(std::declval<typename G::Element>(), std::declval<X>())\
    \ } -> std::same_as<X>;\n};\n\n// Is appropriate name X-set?\ntemplate <class\
    \ G, class X>\nconcept Acted = requires {\n    typename G::Element;\n    { G::acted(std::declval<typename\
    \ G::Element>(), std::declval<X>()) } -> std::same_as<typename G::Element>;\n\
    };\n\n} // namespace concepts\n\n} // namespace zawa\n#line 6 \"Src/DataStructure/SegmentTree/DualSegmentTree.hpp\"\
    \n\n#include <bit>\n#include <cassert>\n#line 10 \"Src/DataStructure/SegmentTree/DualSegmentTree.hpp\"\
    \n#include <vector>\n\nnamespace zawa {\n\ntemplate <class M,class T,bool Commutative\
    \ = false>\nrequires concepts::Monoid<M> and concepts::Action<M,T>\nclass DualSegmentTree\
    \ {\npublic:\n\n    using O = M::Element;\n\n    DualSegmentTree() = default;\n\
    \n    explicit DualSegmentTree(usize n) : m_n{n}, m_a(n), m_seg(n<<1,M::identity())\
    \ {}\n\n    explicit DualSegmentTree(usize n,T init) : m_n{n}, m_a(n,init), m_seg(n<<1,M::identity())\
    \ {}\n\n    explicit DualSegmentTree(std::vector<T> a) : m_n{a.size()}, m_a{std::move(a)},\
    \ m_seg(m_n<<1,M::identity()) {}\n\n    inline usize size() const {\n        return\
    \ m_n;\n    }\n\n    void operation(usize l,usize r,O o) {\n        assert(l <=\
    \ r and r <= size());\n        if constexpr (!Commutative) {\n            push(l);\n\
    \            if (l < r)\n                push(r-1);\n        }\n        for (l\
    \ += size(), r += size() ; l < r ; l >>= 1, r >>= 1) {\n            if (l & 1)\
    \ {\n                m_seg[l] = M::operation(m_seg[l],o);\n                l++;\n\
    \            }\n            if (r & 1) {\n                r--;\n             \
    \   m_seg[r] = M::operation(m_seg[r],o);\n            }\n        }\n    }\n\n\
    \    void operation(usize i,O o) {\n        assert(i < size());\n        if constexpr\
    \ (!Commutative)\n            push(i);\n        m_seg[i+size()] = std::move(o);\n\
    \    }\n\n    T get(usize i) const {\n        assert(i < size());\n        O prod\
    \ = M::identity();\n        for (usize v = i+size() ; v ; v >>= 1)\n         \
    \   prod = M::operation(prod,m_seg[v]);\n        return M::action(prod,m_a[i]);\n\
    \    }\n\n    T operator[](usize i) const {\n        assert(i < size());\n   \
    \     return get(i);\n    }\n\n    void assignOperator(usize i,O o) {\n      \
    \  assert(i < size());\n        push(i);\n        m_seg[i+size()] = std::move(o);\n\
    \    }\n\n    void assign(usize i,T x) {\n        assert(i < size());\n      \
    \  assignOperator(i,M::identity());\n        m_a[i] = std::move(x);\n    }\n\n\
    \    std::vector<T> container() const {\n        std::vector<T> res(size());\n\
    \        for (usize i = 0 ; i < size() ; i++)\n            res[i] = get(i);\n\
    \        return res;\n    }\n\nprivate:\n\n    void push(usize i) {\n        assert(i\
    \ < size());\n        i += size();\n        for (usize j = std::bit_width(i) ;\
    \ --j ; ) {\n            usize v = i >> j;\n            m_seg[v<<1|0] = M::operation(m_seg[v<<1|0],m_seg[v]);\n\
    \            m_seg[v<<1|1] = M::operation(m_seg[v<<1|1],m_seg[v]);\n         \
    \   m_seg[v] = M::identity();\n        }\n    }\n\n    usize m_n;\n\n    std::vector<T>\
    \ m_a;\n\n    std::vector<O> m_seg;\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Monoid/MonoidConcept.hpp\"\
    \n#include \"../../Algebra/Action/ActionConcept.hpp\"\n\n#include <bit>\n#include\
    \ <cassert>\n#include <concepts>\n#include <vector>\n\nnamespace zawa {\n\ntemplate\
    \ <class M,class T,bool Commutative = false>\nrequires concepts::Monoid<M> and\
    \ concepts::Action<M,T>\nclass DualSegmentTree {\npublic:\n\n    using O = M::Element;\n\
    \n    DualSegmentTree() = default;\n\n    explicit DualSegmentTree(usize n) :\
    \ m_n{n}, m_a(n), m_seg(n<<1,M::identity()) {}\n\n    explicit DualSegmentTree(usize\
    \ n,T init) : m_n{n}, m_a(n,init), m_seg(n<<1,M::identity()) {}\n\n    explicit\
    \ DualSegmentTree(std::vector<T> a) : m_n{a.size()}, m_a{std::move(a)}, m_seg(m_n<<1,M::identity())\
    \ {}\n\n    inline usize size() const {\n        return m_n;\n    }\n\n    void\
    \ operation(usize l,usize r,O o) {\n        assert(l <= r and r <= size());\n\
    \        if constexpr (!Commutative) {\n            push(l);\n            if (l\
    \ < r)\n                push(r-1);\n        }\n        for (l += size(), r +=\
    \ size() ; l < r ; l >>= 1, r >>= 1) {\n            if (l & 1) {\n           \
    \     m_seg[l] = M::operation(m_seg[l],o);\n                l++;\n           \
    \ }\n            if (r & 1) {\n                r--;\n                m_seg[r]\
    \ = M::operation(m_seg[r],o);\n            }\n        }\n    }\n\n    void operation(usize\
    \ i,O o) {\n        assert(i < size());\n        if constexpr (!Commutative)\n\
    \            push(i);\n        m_seg[i+size()] = std::move(o);\n    }\n\n    T\
    \ get(usize i) const {\n        assert(i < size());\n        O prod = M::identity();\n\
    \        for (usize v = i+size() ; v ; v >>= 1)\n            prod = M::operation(prod,m_seg[v]);\n\
    \        return M::action(prod,m_a[i]);\n    }\n\n    T operator[](usize i) const\
    \ {\n        assert(i < size());\n        return get(i);\n    }\n\n    void assignOperator(usize\
    \ i,O o) {\n        assert(i < size());\n        push(i);\n        m_seg[i+size()]\
    \ = std::move(o);\n    }\n\n    void assign(usize i,T x) {\n        assert(i <\
    \ size());\n        assignOperator(i,M::identity());\n        m_a[i] = std::move(x);\n\
    \    }\n\n    std::vector<T> container() const {\n        std::vector<T> res(size());\n\
    \        for (usize i = 0 ; i < size() ; i++)\n            res[i] = get(i);\n\
    \        return res;\n    }\n\nprivate:\n\n    void push(usize i) {\n        assert(i\
    \ < size());\n        i += size();\n        for (usize j = std::bit_width(i) ;\
    \ --j ; ) {\n            usize v = i >> j;\n            m_seg[v<<1|0] = M::operation(m_seg[v<<1|0],m_seg[v]);\n\
    \            m_seg[v<<1|1] = M::operation(m_seg[v<<1|1],m_seg[v]);\n         \
    \   m_seg[v] = M::identity();\n        }\n    }\n\n    usize m_n;\n\n    std::vector<T>\
    \ m_a;\n\n    std::vector<O> m_seg;\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Action/ActionConcept.hpp
  isVerificationFile: false
  path: Src/DataStructure/SegmentTree/DualSegmentTree.hpp
  requiredBy: []
  timestamp: '2026-05-10 03:33:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc332_f.test.cpp
  - Test/AtCoder/abc457_f.test.cpp
  - Test/AtCoder/pakencamp_2025_day1_l.test.cpp
  - Test/LC/range_affine_point_get.test.cpp
documentation_of: Src/DataStructure/SegmentTree/DualSegmentTree.hpp
layout: document
title: "Dual Segment Tree (\u975E\u53EF\u63DB\u5BFE\u5FDC)"
---

## ライブラリの使い方

#### テンプレート

```cpp
template <class M,class T,bool Commutative = false>
requires concepts::Monoid<M> and concepts::Action<M,T>
```

雛形

```cpp
struct M {
    using Element = ;
    static Element identity() {
    }
    static Element operation(Element L,Element R) {
    }
    static Element action(Element o,T x) {
    }
};
struct M : public HogeFuga {
    static Element action(HogeFuga::Element o,T x) {
    }
}
```

`action`が`operation`とまったく同じ場合、`Src/Algebra/Monoid/MonoidAction.hpp`内の`AddSelfAction`を用いることができる。

#### コンストラクタ


```
DualSegmentTree() = default;
explicit DualSegmentTree(usize n);
explicit DualSegmentTree(usize n,T init);
explicit DualSegmentTree(std::vector<T> a);
```

作用する値は全部単位元で初期化される

#### メンバ

```cpp
void operation(usize l,usize r,O o)
void operation(usize i,O o)
T get(usize i) const
T operator[](usize i) const
void assign(usize i,T x)
void assignOperator(usize i,O o)
std::vector<T> container() const
```

`operation`は $a_{i}$ に`o`を作用させる

`assignOperator`は $a_{i}$ にこれまでの作用を全てリセットし、`o`を作用させる。

- あまりこのメンバを使う機会はなさそう。`assign(i,get(i))`とすると事足りるケースが殆どだと思う。pakenのverifyで無理やり使った(本来`DualFenwickTree`で事足りる)

`assign`は $a_{i}$ を完全に`x`に変更する。 $a_{i}$ に対する溜まっている作用はリセットさせる。

- この操作は作用には該当しない。なのでこのあと`assignOperator`すると得られるのは`x`に`o`を作用させた値である

## 更新履歴

- 2026/05/10: 全部書き直した。設計変更
