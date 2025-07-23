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
    path: Src/DataStructure/SegmentTree/SegmentTree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    path: Test/AtCoder/abl_e.test.cpp
    title: Test/AtCoder/abl_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_set_range_composite.test.cpp
    title: Test/LC/range_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp\"\
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
    \n} // namespace\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
    \n\n#line 5 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n#include <functional>\n#include <type_traits>\n#include <ostream>\n\
    \nnamespace zawa {\n\ntemplate <concepts::Monoid Monoid>\nclass SegmentTree {\n\
    public:\n\n    using VM = Monoid;\n\n    using V = typename VM::Element;\n\n \
    \   using OM = Monoid;\n\n    using O = typename OM::Element;\n\n    SegmentTree()\
    \ = default;\n\n    explicit SegmentTree(usize n) : m_n{ n }, m_dat(n << 1, VM::identity())\
    \ {}\n\n    explicit SegmentTree(const std::vector<V>& dat) : m_n{ dat.size()\
    \ }, m_dat(dat.size() << 1, VM::identity()) {\n        for (usize i{} ; i < m_n\
    \ ; i++) {\n            m_dat[i + m_n] = dat[i];\n        }\n        for (usize\
    \ i{m_n} ; i-- ; i) {\n            m_dat[i] = VM::operation(m_dat[left(i)], m_dat[right(i)]);\n\
    \        }\n    }\n\n    [[nodiscard]] inline usize size() const noexcept {\n\
    \        return m_n;\n    }\n\n    [[nodiscard]] V get(usize i) const {\n    \
    \    assert(i < size());\n        return m_dat[i + m_n];\n    }\n\n    [[nodiscard]]\
    \ V operator[](usize i) const {\n        assert(i < size());\n        return m_dat[i\
    \ + m_n];\n    }\n\n    void operation(usize i, const O& value) {\n        assert(i\
    \ < size());\n        i += size();\n        m_dat[i] = OM::operation(m_dat[i],\
    \ value);\n        while (i = parent(i), i) {\n            m_dat[i] = VM::operation(m_dat[left(i)],\
    \ m_dat[right(i)]);\n        }\n    }\n\n    void assign(usize i, const V& value)\
    \ {\n        assert(i < size());\n        i += size();\n        m_dat[i] = value;\n\
    \        while (i = parent(i), i) {\n            m_dat[i] = VM::operation(m_dat[left(i)],\
    \ m_dat[right(i)]);\n        }\n    }\n\n    [[nodiscard]] V product(u32 l, u32\
    \ r) const {\n        assert(l <= r and r <= size());\n        V L{ VM::identity()\
    \ }, R{ VM::identity() };\n        for (l += size(), r += size() ; l < r ; l =\
    \ parent(l), r = parent(r)) {\n            if (l & 1) {\n                L = VM::operation(L,\
    \ m_dat[l++]);\n            }\n            if (r & 1) {\n                R = VM::operation(m_dat[--r],\
    \ R);\n            }\n        }\n        return VM::operation(L, R);\n    }\n\n\
    \    template <class Function>\n    [[nodiscard]] usize maxRight(usize l, const\
    \ Function& f) {\n        assert(l < size());\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(V)>>, \"maxRight's argument f must be function bool(T)\"\
    );\n        assert(f(VM::identity()));\n        usize res{l}, width{1};\n    \
    \    V prod{ VM::identity() };\n        // \u73FE\u5728\u306E\u898B\u3066\u3044\
    \u308B\u9802\u70B9\u306E\u5E45\u3092width\u3067\u6301\u3064\n        // \u5883\
    \u754C\u304C\u3042\u308B\u9802\u70B9\u3092\u542B\u3080\u90E8\u5206\u6728\u306E\
    \u6839\u3092\u63A2\u3059\n        // (\u6298\u308A\u8FD4\u3059\u6642\u306F\u5FC5\
    \u8981\u4EE5\u4E0A\u306E\u5E45\u3092\u6301\u3064\u6839\u306B\u306A\u308B\u304C\
    \u3001width\u3092\u6301\u3063\u3066\u3044\u308B\u306E\u3067\u30AA\u30FC\u30D0\u30FC\
    \u3057\u306A\u3044)\n        for (l += size() ; res + width <= size() ; l = parent(l),\
    \ width <<= 1) if (l & 1) {\n            if (not f(VM::operation(prod, m_dat[l])))\
    \ break; \n            res += width;\n            prod = VM::operation(prod, m_dat[l++]);\n\
    \        }\n        // \u6839\u304B\u3089\u4E0B\u3063\u3066\u3001\u5883\u754C\u3092\
    \u767A\u898B\u3059\u308B\n        while (l = left(l), width >>= 1) {\n       \
    \     if (res + width <= size() and f(VM::operation(prod, m_dat[l]))) {\n    \
    \            res += width;\n                prod = VM::operation(prod, m_dat[l++]);\n\
    \            } \n        }\n        return res;\n    }\n\n    template <class\
    \ Function>\n    [[nodiscard]] usize minLeft(usize r, const Function& f) const\
    \ {\n        assert(r <= size());\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(V)>>, \"minLeft's argument f must be function bool(T)\");\n\
    \        assert(f(VM::identity()));\n        usize res{r}, width{1};\n       \
    \ V prod{ VM::identity() };\n        for (r += size() ; res >= width ; r = parent(r),\
    \ width <<= 1) if (r & 1) {\n            if (not f(VM::operation(m_dat[r - 1],\
    \ prod))) break;\n            res -= width;\n            prod = VM::operation(prod,\
    \ m_dat[--r]);\n        }\n        while (r = left(r), width >>= 1) {\n      \
    \      if (res >= width and f(VM::operation(m_dat[r - 1], prod))) {\n        \
    \        res -= width;\n                prod = VM::operation(m_dat[--r], prod);\n\
    \            }\n        }\n        return res;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const SegmentTree& st) {\n        for (usize i{1}\
    \ ; i < 2 * st.size() ; i++) {\n            os << st.m_dat[i] << (i + 1 == 2 *\
    \ st.size() ? \"\" : \" \");\n        }\n        return os;\n    }\n\nprivate:\n\
    \n    constexpr u32 left(u32 v) const {\n        return v << 1;\n    }\n\n   \
    \ constexpr u32 right(u32 v) const {\n        return v << 1 | 1;\n    }\n\n  \
    \  constexpr u32 parent(u32 v) const {\n        return v >> 1;\n    }\n\n    usize\
    \ m_n;\n\n    std::vector<V> m_dat;\n};\n\n} // namespace zawa\n#line 6 \"Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp\"\
    \n\n#line 9 \"Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp\"\n#include\
    \ <set>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T, class\
    \ U>\nconcept Powerable = requires {\n    typename T::Element;\n    { T::power(std::declval<typename\
    \ T::Element>(), std::declval<U>()) }\n        -> std::same_as<typename T::Element>;\n\
    };\n\ntemplate <class T>\nconcept EqualCompare = requires(T a, T b) {\n    { a\
    \ == b } -> std::convertible_to<bool>;\n};\n\ntemplate <class T>\nconcept FastPowerableMonoid\
    \ = Monoid<T> and Powerable<T, u64>;\n\n} // namespace concepts\n\ntemplate <concepts::Monoid\
    \ Monoid>\nclass AssignmentSegmentTree {\npublic:\n\n    using VM = Monoid;\n\n\
    \    using V = typename VM::Element;\n\n    AssignmentSegmentTree() = default;\n\
    \n    explicit AssignmentSegmentTree(usize n) : m_seg{n}, m_dat(n, VM::identity()),\
    \ m_ls{} {\n        m_dat.shrink_to_fit();\n        assert(n);\n        m_ls.insert(0u);\n\
    \        m_ls.insert(n);\n    }\n\n    explicit AssignmentSegmentTree(std::vector<V>\
    \ dat) : m_seg{}, m_dat{dat}, m_ls{} {\n        // dat: \u533A\u9593\u306E\u5DE6\
    \u7AEFl\u306Ba_{l}^{r-l}, \u305D\u308C\u4EE5\u5916\u306Ei\u306Fidentity()\u306B\
    \u3059\u308B -> \u30BB\u30B0\u6728\u306B\u3053\u308C\u3092\u306E\u305B\u308B\n\
    \        // m_dat: \u533A\u9593\u306E\u5DE6\u7AEFl\u306Ba_{l}, \u305D\u308C\u4EE5\
    \u5916\u306Ei\u306Fidentity()\u306B\u3059\u308B\n        m_dat.shrink_to_fit();\n\
    \        if constexpr (concepts::EqualCompare<V>) {\n            for (usize i{},\
    \ j{} ; i < m_dat.size() ; ) {\n                while (j < dat.size() and dat[i]\
    \ == dat[j]) j++;\n                m_ls.insert(i);\n                dat[i] = power(m_dat[i],\
    \ j - i);\n                for ( ; ++i < j ; dat[i] = m_dat[i] = VM::identity())\
    \ ;\n            }\n        }\n        else {\n            for (usize i{} ; i\
    \ < m_dat.size() ; i++) m_ls.insert(i);\n        }\n        m_ls.insert(dat.size());\n\
    \        m_seg = decltype(m_seg){dat};\n    }\n\n    [[nodiscard]] inline usize\
    \ size() const noexcept {\n        return m_dat.size();\n    }\n\n    [[nodiscard]]\
    \ V product(usize l, usize r) const {\n        assert(l <= r and r <= size());\n\
    \        if (l == r) return VM::identity();\n        const auto second_l = m_ls.upper_bound(l);\n\
    \        const auto first_l = std::prev(second_l);\n        if (second_l != m_ls.end()\
    \ and r <= *second_l) { // \u4E00\u3064\u306E\u533A\u9593\u306B\u542B\u307E\u308C\
    \u3066\u3044\u308B\n            return power(m_dat[*first_l], r - l);\n      \
    \  }\n        const auto last_l = std::prev(m_ls.upper_bound(r));\n        V res\
    \ = VM::operation(\n                power(m_dat[*first_l], *second_l - l),\n \
    \               m_seg.product(*second_l, *last_l)\n                );\n      \
    \  if (r == *last_l) return res;\n        return VM::operation(res, power(m_dat[*last_l],\
    \ r - *last_l));\n    }\n\n    void assign(usize l, usize r, V v) {\n        assert(l\
    \ <= r and r <= m_dat.size());\n        if (l == r) return;\n        // assert(*it_l\
    \ < n);\n        auto it_l = std::prev(m_ls.upper_bound(l)), it_r = std::prev(m_ls.upper_bound(r));\
    \ \n        if (*it_l < l) m_seg.assign(*it_l, power(m_dat[*it_l], l - *it_l));\n\
    \        m_seg.assign(l, power(v, r - l));\n        if (*it_r < r and r < m_dat.size())\
    \ {\n            m_dat[r] = m_dat[*it_r];\n            m_seg.assign(r, power(m_dat[r],\
    \ *std::next(it_r) - r));\n            m_ls.insert(r);\n        }\n        m_dat[l]\
    \ = v;\n        for (it_l++ ; *it_l < r ; it_l = m_ls.erase(it_l)) {\n       \
    \     m_seg.assign(*it_l, VM::identity());\n            m_dat[*it_l] = VM::identity();\n\
    \        }\n        m_ls.insert(l);\n    }\n\nprivate:\n\n    SegmentTree<VM>\
    \ m_seg;\n\n    std::vector<V> m_dat;\n\n    std::set<usize> m_ls; \n\n    static\
    \ V power(V v, u32 p) requires concepts::FastPowerableMonoid<VM> {\n        return\
    \ VM::power(v, p);\n    }\n\n    static V power(V v, u32 p) {\n        V res{VM::identity()};\n\
    \        while (p) {\n            if (p & 1) res = VM::operation(res, v);\n  \
    \          v = VM::operation(v, v);\n            p >>= 1; \n        }\n      \
    \  return res;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Monoid/MonoidConcept.hpp\"\
    \n#include \"./SegmentTree.hpp\"\n\n#include <cassert>\n#include <vector>\n#include\
    \ <set>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T, class\
    \ U>\nconcept Powerable = requires {\n    typename T::Element;\n    { T::power(std::declval<typename\
    \ T::Element>(), std::declval<U>()) }\n        -> std::same_as<typename T::Element>;\n\
    };\n\ntemplate <class T>\nconcept EqualCompare = requires(T a, T b) {\n    { a\
    \ == b } -> std::convertible_to<bool>;\n};\n\ntemplate <class T>\nconcept FastPowerableMonoid\
    \ = Monoid<T> and Powerable<T, u64>;\n\n} // namespace concepts\n\ntemplate <concepts::Monoid\
    \ Monoid>\nclass AssignmentSegmentTree {\npublic:\n\n    using VM = Monoid;\n\n\
    \    using V = typename VM::Element;\n\n    AssignmentSegmentTree() = default;\n\
    \n    explicit AssignmentSegmentTree(usize n) : m_seg{n}, m_dat(n, VM::identity()),\
    \ m_ls{} {\n        m_dat.shrink_to_fit();\n        assert(n);\n        m_ls.insert(0u);\n\
    \        m_ls.insert(n);\n    }\n\n    explicit AssignmentSegmentTree(std::vector<V>\
    \ dat) : m_seg{}, m_dat{dat}, m_ls{} {\n        // dat: \u533A\u9593\u306E\u5DE6\
    \u7AEFl\u306Ba_{l}^{r-l}, \u305D\u308C\u4EE5\u5916\u306Ei\u306Fidentity()\u306B\
    \u3059\u308B -> \u30BB\u30B0\u6728\u306B\u3053\u308C\u3092\u306E\u305B\u308B\n\
    \        // m_dat: \u533A\u9593\u306E\u5DE6\u7AEFl\u306Ba_{l}, \u305D\u308C\u4EE5\
    \u5916\u306Ei\u306Fidentity()\u306B\u3059\u308B\n        m_dat.shrink_to_fit();\n\
    \        if constexpr (concepts::EqualCompare<V>) {\n            for (usize i{},\
    \ j{} ; i < m_dat.size() ; ) {\n                while (j < dat.size() and dat[i]\
    \ == dat[j]) j++;\n                m_ls.insert(i);\n                dat[i] = power(m_dat[i],\
    \ j - i);\n                for ( ; ++i < j ; dat[i] = m_dat[i] = VM::identity())\
    \ ;\n            }\n        }\n        else {\n            for (usize i{} ; i\
    \ < m_dat.size() ; i++) m_ls.insert(i);\n        }\n        m_ls.insert(dat.size());\n\
    \        m_seg = decltype(m_seg){dat};\n    }\n\n    [[nodiscard]] inline usize\
    \ size() const noexcept {\n        return m_dat.size();\n    }\n\n    [[nodiscard]]\
    \ V product(usize l, usize r) const {\n        assert(l <= r and r <= size());\n\
    \        if (l == r) return VM::identity();\n        const auto second_l = m_ls.upper_bound(l);\n\
    \        const auto first_l = std::prev(second_l);\n        if (second_l != m_ls.end()\
    \ and r <= *second_l) { // \u4E00\u3064\u306E\u533A\u9593\u306B\u542B\u307E\u308C\
    \u3066\u3044\u308B\n            return power(m_dat[*first_l], r - l);\n      \
    \  }\n        const auto last_l = std::prev(m_ls.upper_bound(r));\n        V res\
    \ = VM::operation(\n                power(m_dat[*first_l], *second_l - l),\n \
    \               m_seg.product(*second_l, *last_l)\n                );\n      \
    \  if (r == *last_l) return res;\n        return VM::operation(res, power(m_dat[*last_l],\
    \ r - *last_l));\n    }\n\n    void assign(usize l, usize r, V v) {\n        assert(l\
    \ <= r and r <= m_dat.size());\n        if (l == r) return;\n        // assert(*it_l\
    \ < n);\n        auto it_l = std::prev(m_ls.upper_bound(l)), it_r = std::prev(m_ls.upper_bound(r));\
    \ \n        if (*it_l < l) m_seg.assign(*it_l, power(m_dat[*it_l], l - *it_l));\n\
    \        m_seg.assign(l, power(v, r - l));\n        if (*it_r < r and r < m_dat.size())\
    \ {\n            m_dat[r] = m_dat[*it_r];\n            m_seg.assign(r, power(m_dat[r],\
    \ *std::next(it_r) - r));\n            m_ls.insert(r);\n        }\n        m_dat[l]\
    \ = v;\n        for (it_l++ ; *it_l < r ; it_l = m_ls.erase(it_l)) {\n       \
    \     m_seg.assign(*it_l, VM::identity());\n            m_dat[*it_l] = VM::identity();\n\
    \        }\n        m_ls.insert(l);\n    }\n\nprivate:\n\n    SegmentTree<VM>\
    \ m_seg;\n\n    std::vector<V> m_dat;\n\n    std::set<usize> m_ls; \n\n    static\
    \ V power(V v, u32 p) requires concepts::FastPowerableMonoid<VM> {\n        return\
    \ VM::power(v, p);\n    }\n\n    static V power(V v, u32 p) {\n        V res{VM::identity()};\n\
    \        while (p) {\n            if (p & 1) res = VM::operation(res, v);\n  \
    \          v = VM::operation(v, v);\n            p >>= 1; \n        }\n      \
    \  return res;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/DataStructure/SegmentTree/SegmentTree.hpp
  isVerificationFile: false
  path: Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp
  requiredBy: []
  timestamp: '2025-06-24 15:48:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/range_set_range_composite.test.cpp
  - Test/AtCoder/abc237_g.test.cpp
  - Test/AtCoder/abl_e.test.cpp
  - Test/AOJ/DSL_2_I.test.cpp
  - Test/AOJ/DSL_2_F.test.cpp
documentation_of: Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp
layout: document
title: Assignment Segment Tree
---

## 概要

区間**代入**区間総積に特化したセグ木。特に、 $x^{p}$ が効率的に計算できない (二分累乗法を使って $\Theta(\log p)$ 回演算をする必要がある)場合は遅延セグ木よりもオーダーレベルで高速化する。

$x^{p}$ が効率的に計算できる場合(例: 加法 $xp$ なので、 $O(1)$ )でも、遅延セグ木じゃなくて普通のセグ木を使っている分定数倍が良い...気がする。

## ライブラリの使い方

#### テンプレート引数要件、Monoid

```
template <Concept::Monoid Monoid>
```

普通のセグ木と同じものを使えば、コンパイルが通って問題なく使える。

`Monoid::Element power(M::Element x, u64 p)`というstaticメンバを定義すると、定数倍や場合によっては計算量が改善する実装に分岐する。中身は $x$ を`operation`で $p$ 乗した値を返すようにする。

`power`が無い場合は二分累乗法によって計算する。

**雛形**

```
struct M {
    using Element = ;
    static Element identity() {
    }
    static Element operation(Element l, Element r) {
    }
    static Element power(Element v, u64 exp) {
    }
};
```

#### コンストラクタ

```cpp
AssignmentSegmentTree()  // (1)
AssignmentSegmentTree(usize n) // (2)
AssignmentSegmentTree(std::vector<V> dat) // (3)
```

(2) 長さ $n$ 、各要素が単位元列で初期化する。

(3) 列`dat`で初期化する。`V`とは`M::Element`のことである。`V`に`operator==`が定義されていると、若干定数倍が良い(多分)実装に分岐する。この分岐は、同じ値が多く連なっているような列は特に嬉しい。 [ABC237](https://atcoder.jp/contests/abc237/tasks/abc237_g) についてはコンストラクタの計算量が $O(N)$ に改善する。実際40msくらい早くなった。

**計算量**

(2): $O(N)$

(3): $O(N\log N)$ 

#### size

```cpp
inline usize size() const noexcept
```

列の長さを返す。 $O(1)$

#### product

```
V product(usize l, usize r) const;
```

$l$ 番目から $r - 1$ 番目までの総積を返す。

**計算量:**  $O(\log N)$

#### assign

```
V assign(usize l, usize r, V v)
```

$l$ 番目から $r - 1$ 番目の要素を $v$ にする。

**計算量**

`assign`を合計 $Q$ 回呼んだとすると

- $O(Q\log N)$
- 加えて`M::power`が $O(Q)$ 回呼ばれる。定義されていないときは、 `M::operation`が $O(Q\log N)$ 回呼ばれる。

## 参考

- [\[Library Checker\] Range Set Range Composite](https://maspypy.com/library-checker-range-set-range-composite)
