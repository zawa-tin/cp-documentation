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
    path: Src/DataStructure/FenwickTree/FenwickTree.hpp
    title: Fenwick Tree
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"Test/AOJ/DSL_2_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n \
    \   using Element = T;\n    static constexpr T identity() noexcept {\n       \
    \ return T{};\n    }\n    static constexpr T operation(const T& l, const T& r)\
    \ noexcept {\n        return l + r;\n    }\n    static constexpr T inverse(const\
    \ T& v) noexcept {\n        return -v;\n    }\n};\n\n} // namespace zawa\n#line\
    \ 2 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\
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
    \n} // namespace zawa\n#line 5 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n#include <ostream>\n#include <functional>\n\
    #include <type_traits>\n\nnamespace zawa {\n\ntemplate <concepts::Group Group>\n\
    class FenwickTree {\npublic:\n\n    using VM = Group;\n    \n    using V = typename\
    \ VM::Element;\n\n    FenwickTree() = default;\n\n    explicit FenwickTree(usize\
    \ n) : m_n{ n }, m_bitwidth{ std::__lg(n) + 1 }, m_a(n), m_dat(n + 1, VM::identity())\
    \ {\n        m_dat.shrink_to_fit();\n        m_a.shrink_to_fit();\n    }\n\n \
    \   explicit FenwickTree(const std::vector<V>& a) : m_n{ a.size() }, m_bitwidth{\
    \ std::__lg(a.size()) + 1 }, m_a(a), m_dat(a.size() + 1, VM::identity()) {\n \
    \       m_dat.shrink_to_fit();  \n        m_a.shrink_to_fit();\n        for (i32\
    \ i{} ; i < static_cast<i32>(m_n) ; i++) {\n            addDat(i, a[i]);\n   \
    \     }\n    }\n\n    inline usize size() const noexcept {\n        return m_n;\n\
    \    }\n\n    // return a[i]\n    const V& get(usize i) const noexcept {\n   \
    \     assert(i < size());\n        return m_a[i];\n    }\n\n    // return a[i]\n\
    \    const V& operator[](usize i) const noexcept {\n        assert(i < size());\n\
    \        return m_a[i];\n    }\n\n    // a[i] <- a[i] + v\n    void operation(usize\
    \ i, const V& v) {\n        assert(i < size());\n        addDat(i, v);\n     \
    \   m_a[i] = VM::operation(m_a[i], v);\n    }\n\n    // a[i] <- v\n    void assign(usize\
    \ i, const V& v) {\n        assert(i < size());\n        addDat(i, VM::operation(VM::inverse(m_a[i]),\
    \ v));\n        m_a[i] = v;\n    }\n\n    // return a[0] + a[1] + ... + a[r -\
    \ 1]\n    V prefixProduct(usize r) const {\n        assert(r <= size());\n   \
    \     return product(r);\n    }\n\n    // return a[l] + a[l + 1] ... + a[r - 1]\n\
    \    V product(usize l, usize r) const {\n        assert(l <= r and r <= size());\n\
    \        return VM::operation(VM::inverse(product(l)), product(r));\n    }\n\n\
    \    template <class Function>\n    usize maxRight(usize l, const Function& f)\
    \ const {\n        static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>,\
    \ \"maxRight's argument f must be function bool(T)\");\n        assert(l < size());\n\
    \        V sum{ VM::inverse(product(l)) }; \n        usize r{};\n        for (usize\
    \ bit{ m_bitwidth } ; bit ; ) {\n            bit--;\n            usize nxt{ r\
    \ | (1u << bit) };\n            if (nxt < m_dat.size() and f(VM::operation(sum,\
    \ m_dat[nxt]))) {\n                sum = VM::operation(sum, m_dat[nxt]);\n   \
    \             r = std::move(nxt);\n            }\n        }\n        assert(l\
    \ <= r);\n        return r;\n    }\n\n    template <class Function>\n    usize\
    \ minLeft(usize r, const Function& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(V)>>, \"minLeft's argument f must be function bool(T)\");\n\
    \        assert(r <= size());\n        V sum{ product(r) };\n        usize l{};\n\
    \        for (usize bit{ m_bitwidth } ; bit ; ) {\n            bit--;\n      \
    \      usize nxt{ l | (1u << bit) };\n            if (nxt <= r and not f(VM::operation(VM::inverse(m_dat[nxt]),\
    \ sum))) {\n                sum = VM::operation(VM::inverse(m_dat[nxt]), sum);\n\
    \                l = std::move(nxt);\n            }\n        }\n        assert(l\
    \ <= r);\n        return l;\n    }\n\n    // debug print\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const FenwickTree& ft) {\n        for (usize i{}\
    \ ; i <= ft.size() ; i++) {\n            os << ft.prefixProduct(i) << (i == ft.size()\
    \ ? \"\" : \" \");\n        }\n        return os;\n    }\n\nprivate:\n\n    usize\
    \ m_n{};\n\n    usize m_bitwidth{};\n\n    std::vector<V> m_a, m_dat;\n\n    constexpr\
    \ i32 lsb(i32 x) const noexcept {\n        return x & -x;\n    }\n    \n    //\
    \ a[i] <- a[i] + v\n    void addDat(i32 i, const V& v) {\n        assert(0 <=\
    \ i and i < static_cast<i32>(m_n));\n        for ( i++ ; i < static_cast<i32>(m_dat.size())\
    \ ; i += lsb(i)) {\n            m_dat[i] = VM::operation(m_dat[i], v);\n     \
    \   }\n    }\n\n    // return a[0] + a[1] + .. + a[i - 1]\n    V product(i32 i)\
    \ const {\n        assert(0 <= i and i <= static_cast<i32>(m_n));\n        V res{\
    \ VM::identity() };\n        for ( ; i > 0 ; i -= lsb(i)) {\n            res =\
    \ VM::operation(res, m_dat[i]);\n        }\n        return res;\n    }\n\n};\n\
    \n} // namespace zawa\n#line 6 \"Test/AOJ/DSL_2_B.test.cpp\"\n\n#include <iostream>\n\
    #line 10 \"Test/AOJ/DSL_2_B.test.cpp\"\n\nusing namespace zawa;\n\nint main()\
    \ {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    usize n, q; std::cin >> n >> q;\n    FenwickTree<AdditiveGroup<i32>> ft(n);\
    \ \n    for (u32 _{} ; _ < q ; _++) {\n        u32 t; std::cin >> t;\n       \
    \ if (t == 0) {\n            u32 i, x; std::cin >> i >> x;\n            ft.operation(i\
    \ - 1, x);\n        }\n        else if (t == 1) {\n            u32 s, t; std::cin\
    \ >> s >> t;\n            std::cout << ft.product(s - 1, t) << '\\n';\n      \
    \  }\n        else {\n            assert(!\"input fail\");\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n#include \"../../Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include <cassert>\n\nusing namespace zawa;\n\
    \nint main() {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    usize n, q; std::cin >> n >> q;\n    FenwickTree<AdditiveGroup<i32>> ft(n);\
    \ \n    for (u32 _{} ; _ < q ; _++) {\n        u32 t; std::cin >> t;\n       \
    \ if (t == 0) {\n            u32 i, x; std::cin >> i >> x;\n            ft.operation(i\
    \ - 1, x);\n        }\n        else if (t == 1) {\n            u32 s, t; std::cin\
    \ >> s >> t;\n            std::cout << ft.product(s - 1, t) << '\\n';\n      \
    \  }\n        else {\n            assert(!\"input fail\");\n        }\n    }\n\
    }\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/AOJ/DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2025-06-24 20:48:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/DSL_2_B.test.cpp
- /verify/Test/AOJ/DSL_2_B.test.cpp.html
title: Test/AOJ/DSL_2_B.test.cpp
---
