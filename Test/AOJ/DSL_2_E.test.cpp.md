---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/GroupConcept.hpp
    title: Src/Algebra/Group/GroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/DualFenwickTree.hpp
    title: Dual Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
  bundledCode: "#line 1 \"Test/AOJ/DSL_2_E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
    \n\n#line 2 \"Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Inversible\
    \ = requires {\n    typename T::Element;\n    { T::inverse(std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\ntemplate <class\
    \ T>\nconcept Group = Monoid<T> and Inversible<T>;\n\n} // namespace Concept\n\
    \n} // namespace zawa\n#line 5 \"Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\
    \n\n#include <bit>\n#include <cassert>\n#line 9 \"Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\
    \n#include <iterator>\n#include <optional>\n#include <vector>\n\nnamespace zawa\
    \ {\n\nnamespace concepts {\n\ntemplate <class F, class V>\nconcept Predicate\
    \ = requires {\n    { std::declval<F>()(std::declval<V>()) } -> std::same_as<bool>;\
    \ \n};\n\n} // namespace Concept\n\ntemplate <concepts::Group G>\nclass DualFenwickTree\
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
    \        operation(i, v);\n    }\n\n    template <class F>\n    std::optional<usize>\
    \ maxRight(usize l, F f) const requires concepts::Predicate<F, V> {\n        assert(l\
    \ < size());\n        V sum = l ? (*this)[l - 1] : G::identity();\n        usize\
    \ r = 0;\n        for (u32 w = lg_ ; w <= lg_ ; w--) {\n            usize next\
    \ = r | (1u << w);\n            if (next >= dat_.size()) continue;\n         \
    \   V nsum = G::operation(sum, dat_[next]);\n            if (f(nsum)) {\n    \
    \            sum = std::move(nsum);\n                r = std::move(next);\n  \
    \          }\n        }\n        assert(l <= r);\n        return r == size() and\
    \ f(sum) ? std::nullopt : std::optional{r};\n    }\n\n    // \u5B9F\u88C5\u304C\
    \u5408\u3044\u307E\u305B\u3093\u3002\u982D\u304C\u60AA\u3044\u306E\u3067\n   \
    \ // template <class F>\n    // requires Concept::Predicate<F, V>\n    // std::optional<usize>\
    \ minLeft(usize r, F f) const {\n    //     assert(r <= n_);\n    //     V sum\
    \ = G::identity();\n    //     usize l = 0;\n    //     for (u32 w = lg_ ; w <=\
    \ lg_ ; w--) {\n    //         u32 next = l | (1u << w);\n    //         if (next\
    \ >= r) continue;\n    //         V nsum = G::operation(dat_[next], sum);\n  \
    \  //         if (!f(nsum)) {\n    //             sum = std::move(nsum);\n   \
    \ //             l = std::move(next);\n    //         }\n    //     }\n    //\
    \     assert(l <= r);\n    //     if (l + 1 == r and !f(sum)) return r;\n    //\
    \     return l == 0u and f(sum) ? std::nullopt : std::optional{l};\n    // }\n\
    \nprivate:\n\n    usize n_;\n\n    u32 lg_;\n\n    std::vector<V> dat_;\n\n  \
    \  constexpr i32 lsb(i32 x) const noexcept {\n        return x & -x;\n    }\n\n\
    \    void add(i32 i, const V& v) {\n        for (i++ ; i <= (i32)size() ; i +=\
    \ lsb(i)) dat_[i] = G::operation(dat_[i], v);\n    }\n};\n\n} // namespace zawa\n\
    #line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nclass AdditiveGroup {\npublic:\n    using Element = T;\n    static\
    \ constexpr T identity() noexcept {\n        return T{};\n    }\n    static constexpr\
    \ T operation(const T& l, const T& r) noexcept {\n        return l + r;\n    }\n\
    \    static constexpr T inverse(const T& v) noexcept {\n        return -v;\n \
    \   }\n};\n\n} // namespace zawa\n#line 5 \"Test/AOJ/DSL_2_E.test.cpp\"\n\n#include\
    \ <iostream>\n\nint main() {\n    using namespace zawa;\n    std::cin.tie(nullptr);\n\
    \    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int n,\
    \ q; std::cin >> n >> q;\n    DualFenwickTree<AdditiveGroup<int>> seg(n);\n  \
    \  for (int _{} ; _ < q ; _++) {\n        int com; std::cin >> com;\n        if\
    \ (com == 0) {\n            int s, t, x; std::cin >> s >> t >> x;\n          \
    \  s--;\n            seg.operation(s, t, x);\n        }\n        else if (com\
    \ == 1) {\n            int i; std::cin >> i;\n            i--;\n            std::cout\
    \ << seg[i] << '\\n';\n        }\n        else {\n            assert(false);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
    \n\n#include \"../../Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\n#include\
    \ \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\n\n#include <iostream>\n\nint\
    \ main() {\n    using namespace zawa;\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, q; std::cin >> n >> q;\n  \
    \  DualFenwickTree<AdditiveGroup<int>> seg(n);\n    for (int _{} ; _ < q ; _++)\
    \ {\n        int com; std::cin >> com;\n        if (com == 0) {\n            int\
    \ s, t, x; std::cin >> s >> t >> x;\n            s--;\n            seg.operation(s,\
    \ t, x);\n        }\n        else if (com == 1) {\n            int i; std::cin\
    \ >> i;\n            i--;\n            std::cout << seg[i] << '\\n';\n       \
    \ }\n        else {\n            assert(false);\n        }\n    }\n}\n"
  dependsOn:
  - Src/DataStructure/FenwickTree/DualFenwickTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  isVerificationFile: true
  path: Test/AOJ/DSL_2_E.test.cpp
  requiredBy: []
  timestamp: '2025-11-19 23:57:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/DSL_2_E.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/DSL_2_E.test.cpp
- /verify/Test/AOJ/DSL_2_E.test.cpp.html
title: Test/AOJ/DSL_2_E.test.cpp
---
