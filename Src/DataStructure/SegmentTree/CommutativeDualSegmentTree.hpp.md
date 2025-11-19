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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
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
    };\n\n} // namespace concepts\n\n} // namespace zawa\n#line 6 \"Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp\"\
    \n\n#include <bit>\n#include <cassert>\n#include <vector>\n#include <iterator>\n\
    #include <ostream>\n\nnamespace zawa {\n\ntemplate <concepts::Monoid Monoid>\n\
    class CommutativeDualSegmentTree {\npublic:\n\n    using VM = Monoid;\n\n    using\
    \ V = typename VM::Element;\n\n    CommutativeDualSegmentTree() = default;\n\n\
    \    explicit CommutativeDualSegmentTree(usize n) \n        : m_n{ n }, m_dat((n\
    \ << 1), VM::identity()) {}\n\n    explicit CommutativeDualSegmentTree(const std::vector<V>&\
    \ dat) \n        : m_n{ dat.size() }, m_dat((m_n << 1), VM::identity()) {\n  \
    \      initDat(dat.begin(), dat.end());\n    }\n\n    template <class InputIterator>\n\
    \    CommutativeDualSegmentTree(InputIterator first, InputIterator last)\n   \
    \     : m_n{ static_cast<usize>(std::distance(first, last)) }, m_dat((m_n << 1),\
    \ VM::identity()) {\n        initDat(first, last);\n    }\n\n    [[nodiscard]]\
    \ inline usize size() const noexcept {\n        return m_n;\n    }\n\n    template\
    \ <class O>\n    requires concepts::Acted<Monoid, O>\n    void operation(usize\
    \ l, usize r, const O& v) {\n        assert(l <= r and r <= size());\n       \
    \ for (l += size(), r += size() ; l < r ; l = parent(l), r = parent(r)) {\n  \
    \          if (l & 1) {\n                m_dat[l] = VM::acted(m_dat[l], v);\n\
    \                l++;\n            }\n            if (r & 1) {\n             \
    \   r--;\n                m_dat[r] = VM::acted(m_dat[r], v);\n            }\n\
    \        }\n    }\n\n    template <class O>\n    requires concepts::Acted<Monoid,\
    \ O>\n    void operation(usize i, const O& o) {\n        assert(i < size());\n\
    \        m_dat[i + size()] = VM::acted(m_dat[i + size()], o);\n    }\n\n    void\
    \ assign(usize i, const V& v) {\n        assert(i < size());\n        push(i);\n\
    \        m_dat[i + size()] = v;\n    }\n\n    [[nodiscard]] virtual V operator[](usize\
    \ i) {\n        assert(i < size());\n        V res{ VM::identity() };\n      \
    \  for (i += size() ; i ; i = parent(i))\n            res = VM::operation(res,\
    \ m_dat[i]);\n        return res;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const CommutativeDualSegmentTree seg) {\n        usize size{ seg.m_dat.size()\
    \ };\n        for (usize i{1} ; i < size ; i++) {\n            os << seg.m_dat[i]\
    \ << (i + 1 == size ? \"\" : \" \");\n        }\n        return os;\n    }\n\n\
    protected:\n\n    static constexpr usize parent(usize v) noexcept {\n        return\
    \ v >> 1;\n    }\n\n    static constexpr usize left(usize v) noexcept {\n    \
    \    return v << 1;\n    }\n\n    static constexpr usize right(usize v) noexcept\
    \ {\n        return v << 1 | 1;\n    }\n\n    usize m_n;\n\n    std::vector<V>\
    \ m_dat;\n\n    template <class InputIterator>\n    inline void initDat(InputIterator\
    \ first, InputIterator last) {\n        for (auto it{ first } ; it != last ; it++)\
    \ {\n            m_dat[size() + std::distance(first, it)] = *it;\n        }\n\
    \    }\n\n    void push(usize i) {\n        assert(i < size());\n        i +=\
    \ size();\n        usize height{ 64u - std::countl_zero(i) };\n        for (usize\
    \ h{ height } ; --h ; ) {\n            usize v{ i >> h };\n            m_dat[left(v)]\
    \ = VM::operation(m_dat[left(v)], m_dat[v]);\n            m_dat[right(v)] = VM::operation(m_dat[right(v)],\
    \ m_dat[v]);\n            m_dat[v] = VM::identity();\n        }\n    }\n\n};\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Monoid/MonoidConcept.hpp\"\
    \n#include \"../../Algebra/Action/ActionConcept.hpp\"\n\n#include <bit>\n#include\
    \ <cassert>\n#include <vector>\n#include <iterator>\n#include <ostream>\n\nnamespace\
    \ zawa {\n\ntemplate <concepts::Monoid Monoid>\nclass CommutativeDualSegmentTree\
    \ {\npublic:\n\n    using VM = Monoid;\n\n    using V = typename VM::Element;\n\
    \n    CommutativeDualSegmentTree() = default;\n\n    explicit CommutativeDualSegmentTree(usize\
    \ n) \n        : m_n{ n }, m_dat((n << 1), VM::identity()) {}\n\n    explicit\
    \ CommutativeDualSegmentTree(const std::vector<V>& dat) \n        : m_n{ dat.size()\
    \ }, m_dat((m_n << 1), VM::identity()) {\n        initDat(dat.begin(), dat.end());\n\
    \    }\n\n    template <class InputIterator>\n    CommutativeDualSegmentTree(InputIterator\
    \ first, InputIterator last)\n        : m_n{ static_cast<usize>(std::distance(first,\
    \ last)) }, m_dat((m_n << 1), VM::identity()) {\n        initDat(first, last);\n\
    \    }\n\n    [[nodiscard]] inline usize size() const noexcept {\n        return\
    \ m_n;\n    }\n\n    template <class O>\n    requires concepts::Acted<Monoid,\
    \ O>\n    void operation(usize l, usize r, const O& v) {\n        assert(l <=\
    \ r and r <= size());\n        for (l += size(), r += size() ; l < r ; l = parent(l),\
    \ r = parent(r)) {\n            if (l & 1) {\n                m_dat[l] = VM::acted(m_dat[l],\
    \ v);\n                l++;\n            }\n            if (r & 1) {\n       \
    \         r--;\n                m_dat[r] = VM::acted(m_dat[r], v);\n         \
    \   }\n        }\n    }\n\n    template <class O>\n    requires concepts::Acted<Monoid,\
    \ O>\n    void operation(usize i, const O& o) {\n        assert(i < size());\n\
    \        m_dat[i + size()] = VM::acted(m_dat[i + size()], o);\n    }\n\n    void\
    \ assign(usize i, const V& v) {\n        assert(i < size());\n        push(i);\n\
    \        m_dat[i + size()] = v;\n    }\n\n    [[nodiscard]] virtual V operator[](usize\
    \ i) {\n        assert(i < size());\n        V res{ VM::identity() };\n      \
    \  for (i += size() ; i ; i = parent(i))\n            res = VM::operation(res,\
    \ m_dat[i]);\n        return res;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const CommutativeDualSegmentTree seg) {\n        usize size{ seg.m_dat.size()\
    \ };\n        for (usize i{1} ; i < size ; i++) {\n            os << seg.m_dat[i]\
    \ << (i + 1 == size ? \"\" : \" \");\n        }\n        return os;\n    }\n\n\
    protected:\n\n    static constexpr usize parent(usize v) noexcept {\n        return\
    \ v >> 1;\n    }\n\n    static constexpr usize left(usize v) noexcept {\n    \
    \    return v << 1;\n    }\n\n    static constexpr usize right(usize v) noexcept\
    \ {\n        return v << 1 | 1;\n    }\n\n    usize m_n;\n\n    std::vector<V>\
    \ m_dat;\n\n    template <class InputIterator>\n    inline void initDat(InputIterator\
    \ first, InputIterator last) {\n        for (auto it{ first } ; it != last ; it++)\
    \ {\n            m_dat[size() + std::distance(first, it)] = *it;\n        }\n\
    \    }\n\n    void push(usize i) {\n        assert(i < size());\n        i +=\
    \ size();\n        usize height{ 64u - std::countl_zero(i) };\n        for (usize\
    \ h{ height } ; --h ; ) {\n            usize v{ i >> h };\n            m_dat[left(v)]\
    \ = VM::operation(m_dat[left(v)], m_dat[v]);\n            m_dat[right(v)] = VM::operation(m_dat[right(v)],\
    \ m_dat[v]);\n            m_dat[v] = VM::identity();\n        }\n    }\n\n};\n\
    \n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Action/ActionConcept.hpp
  isVerificationFile: false
  path: Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp
  requiredBy: []
  timestamp: '2025-11-20 00:22:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp
layout: document
title: "Dual Segment Tree (\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9)"
---

ドキュメントを書く気力が行方不明！

[テンプレート引数](https://zawa-tin.github.io/cp-documentation/Docs/Appendix/Monoid.html)

```cpp
struct M {
    using Element = ;
    static Element identity() {
    }
    static Element operation(Element L, Element R) {
    }
    static Element acted(Element x, O o) {
    }
};
```

`using O = Monoid::Element`

`operation(u32 l, u32 r, const O& v)` 半開区間 $[l, r)$ に $v$ を作用
- $O(\log n)$

`operation(u32 i, const O& v)` 
- $O(\log n)$
- 未verify

`assign(u32 i, const O& v)` $i$ 番目の要素に $v$ を「代入」
- $O(\log n)$
- 未verify

`Operator operator[](u32 i)`
- $i$ 番目の要素を取得
- $O(\log n)$
