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
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp
    title: Assignment Segment Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp
    title: Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/0478.test.cpp
    title: Test/AOJ/0478.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2450.test.cpp
    title: Test/AOJ/2450.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/3111.test.cpp
    title: Test/AOJ/3111.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_A.test.cpp
    title: Test/AOJ/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_D.test.cpp
    title: Test/AOJ/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_F.test.cpp
    title: Test/AOJ/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_I.test.cpp
    title: Test/AOJ/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc237_g.test.cpp
    title: Test/AtCoder/abc237_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc292_h.test.cpp
    title: Test/AtCoder/abc292_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc331_f.test.cpp
    title: Test/AtCoder/abc331_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc417_f.test.cpp
    title: Test/AtCoder/abc417_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abl_e.test.cpp
    title: Test/AtCoder/abl_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/agc005_b.test.cpp
    title: Test/AtCoder/agc005_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/tdpc_target.test.cpp
    title: Test/AtCoder/tdpc_target.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_rectangle_sum/OfflineSegmentTree2D.test.cpp
    title: Test/LC/point_add_rectangle_sum/OfflineSegmentTree2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_set_range_composite.test.cpp
    title: Test/LC/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_set_range_composite.test.cpp
    title: Test/LC/range_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/aoj3326.test.cpp
    title: Test/Manual/aoj3326.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/3189.test.cpp
    title: Test/yukicoder/3189.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\n\n#line\
    \ 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
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
    \n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n#include <functional>\n#include <type_traits>\n\
    #include <ostream>\n\nnamespace zawa {\n\ntemplate <concepts::Monoid Monoid>\n\
    class SegmentTree {\npublic:\n\n    using VM = Monoid;\n\n    using V = typename\
    \ VM::Element;\n\n    using OM = Monoid;\n\n    using O = typename OM::Element;\n\
    \n    SegmentTree() = default;\n\n    explicit SegmentTree(usize n) : m_n{ n },\
    \ m_dat(n << 1, VM::identity()) {}\n\n    explicit SegmentTree(const std::vector<V>&\
    \ dat) : m_n{ dat.size() }, m_dat(dat.size() << 1, VM::identity()) {\n       \
    \ for (usize i{} ; i < m_n ; i++) {\n            m_dat[i + m_n] = dat[i];\n  \
    \      }\n        for (usize i{m_n} ; i-- ; ) {\n            m_dat[i] = VM::operation(m_dat[left(i)],\
    \ m_dat[right(i)]);\n        }\n    }\n\n    [[nodiscard]] inline usize size()\
    \ const noexcept {\n        return m_n;\n    }\n\n    [[nodiscard]] V get(usize\
    \ i) const {\n        assert(i < size());\n        return m_dat[i + m_n];\n  \
    \  }\n\n    [[nodiscard]] V operator[](usize i) const {\n        assert(i < size());\n\
    \        return m_dat[i + m_n];\n    }\n\n    void operation(usize i, const O&\
    \ value) {\n        assert(i < size());\n        i += size();\n        m_dat[i]\
    \ = OM::operation(m_dat[i], value);\n        while (i = parent(i), i) {\n    \
    \        m_dat[i] = VM::operation(m_dat[left(i)], m_dat[right(i)]);\n        }\n\
    \    }\n\n    void assign(usize i, const V& value) {\n        assert(i < size());\n\
    \        i += size();\n        m_dat[i] = value;\n        while (i = parent(i),\
    \ i) {\n            m_dat[i] = VM::operation(m_dat[left(i)], m_dat[right(i)]);\n\
    \        }\n    }\n\n    [[nodiscard]] V product(u32 l, u32 r) const {\n     \
    \   assert(l <= r and r <= size());\n        V L{ VM::identity() }, R{ VM::identity()\
    \ };\n        for (l += size(), r += size() ; l < r ; l = parent(l), r = parent(r))\
    \ {\n            if (l & 1) {\n                L = VM::operation(L, m_dat[l++]);\n\
    \            }\n            if (r & 1) {\n                R = VM::operation(m_dat[--r],\
    \ R);\n            }\n        }\n        return VM::operation(L, R);\n    }\n\n\
    \    template <class F>\n    requires std::predicate<F, V>\n    [[nodiscard]]\
    \ usize maxRight(usize l, const F& f) {\n        assert(l < size());\n       \
    \ static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>, \"\
    maxRight's argument f must be function bool(T)\");\n        assert(f(VM::identity()));\n\
    \        usize res{l}, width{1};\n        V prod{ VM::identity() };\n        for\
    \ (l += size() ; res + width <= size() ; l = parent(l), width <<= 1) if (l & 1)\
    \ {\n            if (not f(VM::operation(prod, m_dat[l]))) break; \n         \
    \   res += width;\n            prod = VM::operation(prod, m_dat[l++]);\n     \
    \   }\n        while (l = left(l), width >>= 1) {\n            if (res + width\
    \ <= size() and f(VM::operation(prod, m_dat[l]))) {\n                res += width;\n\
    \                prod = VM::operation(prod, m_dat[l++]);\n            } \n   \
    \     }\n        return res;\n    }\n\n    template <class F>\n    requires std::predicate<F,\
    \ V>\n    [[nodiscard]] usize minLeft(usize r, const F& f) const {\n        assert(r\
    \ <= size());\n        static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>,\
    \ \"minLeft's argument f must be function bool(T)\");\n        assert(f(VM::identity()));\n\
    \        usize res{r}, width{1};\n        V prod{ VM::identity() };\n        for\
    \ (r += size() ; res >= width ; r = parent(r), width <<= 1) if (r & 1) {\n   \
    \         if (not f(VM::operation(m_dat[r - 1], prod))) break;\n            res\
    \ -= width;\n            prod = VM::operation(prod, m_dat[--r]);\n        }\n\
    \        while (r = left(r), width >>= 1) {\n            if (res >= width and\
    \ f(VM::operation(m_dat[r - 1], prod))) {\n                res -= width;\n   \
    \             prod = VM::operation(m_dat[--r], prod);\n            }\n       \
    \ }\n        return res;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const SegmentTree& st) {\n        for (usize i{1} ; i < 2 * st.size() ;\
    \ i++) {\n            os << st.m_dat[i] << (i + 1 == 2 * st.size() ? \"\" : \"\
    \ \");\n        }\n        return os;\n    }\n\nprivate:\n\n    constexpr u32\
    \ left(u32 v) const {\n        return v << 1;\n    }\n\n    constexpr u32 right(u32\
    \ v) const {\n        return v << 1 | 1;\n    }\n\n    constexpr u32 parent(u32\
    \ v) const {\n        return v >> 1;\n    }\n\n    usize m_n;\n\n    std::vector<V>\
    \ m_dat;\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n#include <functional>\n#include <type_traits>\n\
    #include <ostream>\n\nnamespace zawa {\n\ntemplate <concepts::Monoid Monoid>\n\
    class SegmentTree {\npublic:\n\n    using VM = Monoid;\n\n    using V = typename\
    \ VM::Element;\n\n    using OM = Monoid;\n\n    using O = typename OM::Element;\n\
    \n    SegmentTree() = default;\n\n    explicit SegmentTree(usize n) : m_n{ n },\
    \ m_dat(n << 1, VM::identity()) {}\n\n    explicit SegmentTree(const std::vector<V>&\
    \ dat) : m_n{ dat.size() }, m_dat(dat.size() << 1, VM::identity()) {\n       \
    \ for (usize i{} ; i < m_n ; i++) {\n            m_dat[i + m_n] = dat[i];\n  \
    \      }\n        for (usize i{m_n} ; i-- ; ) {\n            m_dat[i] = VM::operation(m_dat[left(i)],\
    \ m_dat[right(i)]);\n        }\n    }\n\n    [[nodiscard]] inline usize size()\
    \ const noexcept {\n        return m_n;\n    }\n\n    [[nodiscard]] V get(usize\
    \ i) const {\n        assert(i < size());\n        return m_dat[i + m_n];\n  \
    \  }\n\n    [[nodiscard]] V operator[](usize i) const {\n        assert(i < size());\n\
    \        return m_dat[i + m_n];\n    }\n\n    void operation(usize i, const O&\
    \ value) {\n        assert(i < size());\n        i += size();\n        m_dat[i]\
    \ = OM::operation(m_dat[i], value);\n        while (i = parent(i), i) {\n    \
    \        m_dat[i] = VM::operation(m_dat[left(i)], m_dat[right(i)]);\n        }\n\
    \    }\n\n    void assign(usize i, const V& value) {\n        assert(i < size());\n\
    \        i += size();\n        m_dat[i] = value;\n        while (i = parent(i),\
    \ i) {\n            m_dat[i] = VM::operation(m_dat[left(i)], m_dat[right(i)]);\n\
    \        }\n    }\n\n    [[nodiscard]] V product(u32 l, u32 r) const {\n     \
    \   assert(l <= r and r <= size());\n        V L{ VM::identity() }, R{ VM::identity()\
    \ };\n        for (l += size(), r += size() ; l < r ; l = parent(l), r = parent(r))\
    \ {\n            if (l & 1) {\n                L = VM::operation(L, m_dat[l++]);\n\
    \            }\n            if (r & 1) {\n                R = VM::operation(m_dat[--r],\
    \ R);\n            }\n        }\n        return VM::operation(L, R);\n    }\n\n\
    \    template <class F>\n    requires std::predicate<F, V>\n    [[nodiscard]]\
    \ usize maxRight(usize l, const F& f) {\n        assert(l < size());\n       \
    \ static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>, \"\
    maxRight's argument f must be function bool(T)\");\n        assert(f(VM::identity()));\n\
    \        usize res{l}, width{1};\n        V prod{ VM::identity() };\n        for\
    \ (l += size() ; res + width <= size() ; l = parent(l), width <<= 1) if (l & 1)\
    \ {\n            if (not f(VM::operation(prod, m_dat[l]))) break; \n         \
    \   res += width;\n            prod = VM::operation(prod, m_dat[l++]);\n     \
    \   }\n        while (l = left(l), width >>= 1) {\n            if (res + width\
    \ <= size() and f(VM::operation(prod, m_dat[l]))) {\n                res += width;\n\
    \                prod = VM::operation(prod, m_dat[l++]);\n            } \n   \
    \     }\n        return res;\n    }\n\n    template <class F>\n    requires std::predicate<F,\
    \ V>\n    [[nodiscard]] usize minLeft(usize r, const F& f) const {\n        assert(r\
    \ <= size());\n        static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>,\
    \ \"minLeft's argument f must be function bool(T)\");\n        assert(f(VM::identity()));\n\
    \        usize res{r}, width{1};\n        V prod{ VM::identity() };\n        for\
    \ (r += size() ; res >= width ; r = parent(r), width <<= 1) if (r & 1) {\n   \
    \         if (not f(VM::operation(m_dat[r - 1], prod))) break;\n            res\
    \ -= width;\n            prod = VM::operation(prod, m_dat[--r]);\n        }\n\
    \        while (r = left(r), width >>= 1) {\n            if (res >= width and\
    \ f(VM::operation(m_dat[r - 1], prod))) {\n                res -= width;\n   \
    \             prod = VM::operation(m_dat[--r], prod);\n            }\n       \
    \ }\n        return res;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const SegmentTree& st) {\n        for (usize i{1} ; i < 2 * st.size() ;\
    \ i++) {\n            os << st.m_dat[i] << (i + 1 == 2 * st.size() ? \"\" : \"\
    \ \");\n        }\n        return os;\n    }\n\nprivate:\n\n    constexpr u32\
    \ left(u32 v) const {\n        return v << 1;\n    }\n\n    constexpr u32 right(u32\
    \ v) const {\n        return v << 1 | 1;\n    }\n\n    constexpr u32 parent(u32\
    \ v) const {\n        return v >> 1;\n    }\n\n    usize m_n;\n\n    std::vector<V>\
    \ m_dat;\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: false
  path: Src/DataStructure/SegmentTree/SegmentTree.hpp
  requiredBy:
  - Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp
  - Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp
  timestamp: '2025-10-17 20:47:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/point_add_rectangle_sum/OfflineSegmentTree2D.test.cpp
  - Test/LC/range_set_range_composite.test.cpp
  - Test/LC/point_set_range_composite.test.cpp
  - Test/yukicoder/3189.test.cpp
  - Test/AOJ/DSL_2_A.test.cpp
  - Test/AOJ/DSL_2_I.test.cpp
  - Test/AOJ/0478.test.cpp
  - Test/AOJ/2450.test.cpp
  - Test/AOJ/DSL_2_D.test.cpp
  - Test/AOJ/DSL_2_F.test.cpp
  - Test/AOJ/3111.test.cpp
  - Test/AtCoder/abl_e.test.cpp
  - Test/AtCoder/abc331_f.test.cpp
  - Test/AtCoder/abc237_g.test.cpp
  - Test/AtCoder/agc005_b.test.cpp
  - Test/AtCoder/abc292_h.test.cpp
  - Test/AtCoder/tdpc_target.test.cpp
  - Test/AtCoder/abc417_f.test.cpp
  - Test/Manual/aoj3326.test.cpp
documentation_of: Src/DataStructure/SegmentTree/SegmentTree.hpp
layout: document
title: Segment Tree
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
};
```

`get` 0-indexed

`operator[]` 0-indexed

`assign` 1点更新(代入) 0-indexed

`operation` 1点更新

`product`: 半開区間

`maxRight`

`minLeft`: 引数`r`は探索範囲に含まない
