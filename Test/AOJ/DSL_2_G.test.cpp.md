---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/CartesianProductGroup.hpp
    title: Src/Algebra/Group/CartesianProductGroup.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/GroupConcept.hpp
    title: Src/Algebra/Group/GroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/PowerableConcept.hpp
    title: Src/Algebra/PowerableConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/FenwickTree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/LazyFenwickTree.hpp
    title: Lazy Fenwick Tree
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
  bundledCode: "#line 1 \"Test/AOJ/DSL_2_G.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#line 2 \"Src/DataStructure/FenwickTree/LazyFenwickTree.hpp\"\n\n#line 2 \"\
    Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\n\n#line\
    \ 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
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
    #include <type_traits>\n\nnamespace zawa {\n\ntemplate <concepts::Monoid Monoid>\n\
    class FenwickTree {\npublic:\n\n    using VM = Monoid;\n    \n    using V = typename\
    \ VM::Element;\n\n    FenwickTree() = default;\n\n    explicit FenwickTree(usize\
    \ n) : m_n{ n }, m_bitwidth{ std::__lg(n) + 1 }, m_a(n, VM::identity()), m_dat(n\
    \ + 1, VM::identity()) {\n        m_dat.shrink_to_fit();\n        m_a.shrink_to_fit();\n\
    \    }\n\n    explicit FenwickTree(const std::vector<V>& a) : m_n{ a.size() },\
    \ m_bitwidth{ std::__lg(a.size()) + 1 }, m_a(a), m_dat(a.size() + 1, VM::identity())\
    \ {\n        m_dat.shrink_to_fit();  \n        m_a.shrink_to_fit();\n        for\
    \ (i32 i{} ; i < static_cast<i32>(m_n) ; i++) {\n            addDat(i, a[i]);\n\
    \        }\n    }\n\n    inline usize size() const noexcept {\n        return\
    \ m_n;\n    }\n\n    // return a[i]\n    const V& get(usize i) const noexcept\
    \ {\n        assert(i < size());\n        return m_a[i];\n    }\n\n    // return\
    \ a[i]\n    const V& operator[](usize i) const noexcept {\n        assert(i <\
    \ size());\n        return m_a[i];\n    }\n\n    // a[i] <- a[i] + v\n    void\
    \ operation(usize i, const V& v) {\n        assert(i < size());\n        addDat(i,\
    \ v);\n        m_a[i] = VM::operation(m_a[i], v);\n    }\n\n    // a[i] <- v\n\
    \    void assign(usize i, const V& v) requires concepts::Inversible<Monoid> {\n\
    \        assert(i < size());\n        addDat(i, VM::operation(VM::inverse(m_a[i]),\
    \ v));\n        m_a[i] = v;\n    }\n\n    // return a[0] + a[1] + ... + a[r -\
    \ 1]\n    V prefixProduct(usize r) const {\n        assert(r <= size());\n   \
    \     return product(r);\n    }\n\n    // return a[l] + a[l + 1] ... + a[r - 1]\n\
    \    V product(usize l, usize r) const requires concepts::Inversible<Monoid> {\n\
    \        assert(l <= r and r <= size());\n        return VM::operation(VM::inverse(product(l)),\
    \ product(r));\n    }\n\n    template <class Function>\n    usize maxRight(usize\
    \ l, const Function& f) const requires concepts::Inversible<Monoid> {\n      \
    \  static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>, \"\
    maxRight's argument f must be function bool(T)\");\n        assert(l <= size());\n\
    \        assert(f(VM::identity()));\n        V sum{ VM::inverse(product(l)) };\
    \ \n        usize r{};\n        for (usize bit{ m_bitwidth } ; bit ; ) {\n   \
    \         bit--;\n            usize nxt{ r | (1u << bit) };\n            if (nxt\
    \ < m_dat.size() and (nxt <= l or f(VM::operation(sum, m_dat[nxt])))) {\n    \
    \            sum = VM::operation(sum, m_dat[nxt]);\n                r = std::move(nxt);\n\
    \            }\n        }\n        assert(l <= r);\n        return r;\n    }\n\
    \n    template <class Function>\n    usize minLeft(usize r, const Function& f)\
    \ const requires concepts::Inversible<Monoid> {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(V)>>, \"minLeft's argument f must be function bool(T)\");\n\
    \        assert(r <= size());\n        assert(f(VM::identity()));\n        V sum{\
    \ product(r) };\n        usize l{};\n        for (usize bit{ m_bitwidth } ; bit\
    \ ; ) {\n            bit--;\n            usize nxt{ l | (1u << bit) };\n     \
    \       if (nxt <= r and not f(VM::operation(VM::inverse(m_dat[nxt]), sum))) {\n\
    \                sum = VM::operation(VM::inverse(m_dat[nxt]), sum);\n        \
    \        l = std::move(nxt);\n            }\n        }\n        assert(l <= r);\n\
    \        return l;\n    }\n\n    // debug print\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const FenwickTree& ft) {\n        for (usize i{} ; i <= ft.size() ; i++)\
    \ {\n            os << ft.prefixProduct(i) << (i == ft.size() ? \"\" : \" \");\n\
    \        }\n        return os;\n    }\n\nprivate:\n\n    usize m_n{};\n\n    usize\
    \ m_bitwidth{};\n\n    std::vector<V> m_a, m_dat;\n\n    constexpr i32 lsb(i32\
    \ x) const noexcept {\n        return x & -x;\n    }\n    \n    // a[i] <- a[i]\
    \ + v\n    void addDat(i32 i, const V& v) {\n        assert(0 <= i and i < static_cast<i32>(m_n));\n\
    \        for ( i++ ; i < static_cast<i32>(m_dat.size()) ; i += lsb(i)) {\n   \
    \         m_dat[i] = VM::operation(m_dat[i], v);\n        }\n    }\n\n    // return\
    \ a[0] + a[1] + .. + a[i - 1]\n    V product(i32 i) const {\n        assert(0\
    \ <= i and i <= static_cast<i32>(m_n));\n        V res{ VM::identity() };\n  \
    \      for ( ; i > 0 ; i -= lsb(i)) {\n            res = VM::operation(res, m_dat[i]);\n\
    \        }\n        return res;\n    }\n\n};\n\n} // namespace zawa\n#line 2 \"\
    Src/Algebra/PowerableConcept.hpp\"\n\n#line 4 \"Src/Algebra/PowerableConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T,class U>\nconcept\
    \ Powerable = requires {\n    typename T::Element;\n    { T::power(std::declval<typename\
    \ T::Element>(), std::declval<U>()) }\n        -> std::same_as<typename T::Element>;\n\
    };\n\n} // namespace concepts\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/CartesianProductGroup.hpp\"\
    \n\n#line 5 \"Src/Algebra/Group/CartesianProductGroup.hpp\"\n\n#include <utility>\n\
    \nnamespace zawa {\n\ntemplate <concepts::Group G>\nclass CartesianProductGroup\
    \ {\npublic:\n\n    using Element = std::pair<typename G::Element,typename G::Element>;\n\
    \n    static Element identity() {\n        return {G::identity(),G::identity()};\n\
    \    }\n\n    static Element operation(const Element& l,const Element& r) {\n\
    \        return {G::operation(l.first,r.first),G::operation(l.second,r.second)};\n\
    \    }\n\n    static Element inverse(const Element& v) {\n        return {G::inverse(v.first),G::inverse(v.second)};\n\
    \    }\n\n    template <class U>\n    static Element power(const Element& v,U\
    \ exp) requires concepts::Powerable<G,U> {\n        return {G::power(v.first,exp),G::power(v.second,exp)};\n\
    \    }\n};\n\n} // namespace zawa\n#line 6 \"Src/DataStructure/FenwickTree/LazyFenwickTree.hpp\"\
    \n\n#line 8 \"Src/DataStructure/FenwickTree/LazyFenwickTree.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <concepts::Group G>\nclass LazyFenwickTree {\npublic:\n\n\
    \    using T = typename G::Element;\n\n    explicit LazyFenwickTree(usize n) :\
    \ m_n{n}, m_fen{n} {}\n\n    explicit LazyFenwickTree(const std::vector<T>& a)\
    \ : m_n{a.size()}, m_fen{a.size()} {\n        for (usize i = 0 ; i < size() ;\
    \ i++)\n            operation(i,a[i]);\n    }\n\n    inline usize size() const\
    \ {\n        return m_n;\n    }\n\n    void operation(usize l,usize r,T v) {\n\
    \        assert(l <= r and r <= size());\n        if (l < r) {\n            m_fen.operation(l,{G::inverse(power(v,l)),v});\n\
    \            if (r < size())\n                m_fen.operation(r,{power(v,r),G::inverse(v)});\n\
    \        }\n    }\n\n    T prefixProduct(usize r) const {\n        assert(r <=\
    \ size());\n        auto [a,b] = m_fen.prefixProduct(r);\n        return G::operation(a,power(b,r));\n\
    \    }\n\n    T product(usize l,usize r) const {\n        assert(l <= r and r\
    \ <= size());\n        return G::operation(G::inverse(prefixProduct(l)),prefixProduct(r));\n\
    \    }\n    \n    void operation(usize i,T v) {\n        assert(i < size());\n\
    \        operation(i,i+1,v);\n    }\n\n    T get(usize i) const {\n        assert(i\
    \ < size());\n        return product(i,i+1);\n    }\n\n    T operator[](usize\
    \ i) const {\n        return get(i);\n    }\n\n    void assign(usize i,T v) {\n\
    \        assert(i < size());\n        operation(i,G::operation(G::inverse(get(i)),v));\n\
    \    }\n\n    std::vector<T> container() const {\n        std::vector<T> res(size());\n\
    \        for (usize i = 0 ; i < size() ; i++)\n            res[i] = get(i);\n\
    \        return res;\n    }\n\nprivate:\n\n    usize m_n;\n\n    FenwickTree<CartesianProductGroup<G>>\
    \ m_fen;\n\n    static T power(T v,usize exp) requires concepts::Powerable<G,usize>\
    \ {\n        return G::power(v,exp);\n    }\n\n    static T power(T v,usize exp)\
    \ {\n        T res = G::identity();\n        while (exp) {\n            if (exp\
    \ & 1)\n                res = G::operation(res,v);\n            v = G::operation(v,v);\n\
    \            exp >>= 1;\n        }\n        return res;\n    }\n};\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace zawa {\n\n\
    template <class T>\nclass AdditiveGroup {\npublic:\n    using Element = T;\n \
    \   static constexpr T identity() noexcept {\n        return T{};\n    }\n   \
    \ static constexpr T operation(T l,T r) noexcept {\n        return l + r;\n  \
    \  }\n    static constexpr T inverse(T v) noexcept {\n        return -v;\n   \
    \ }\n    template <class U>\n    static constexpr T power(T v,U exp) noexcept\
    \ {\n        return v * static_cast<T>(exp);\n    }\n};\n\n} // namespace zawa\n\
    #line 5 \"Test/AOJ/DSL_2_G.test.cpp\"\nusing namespace zawa;\n\n#include <iostream>\n\
    using namespace std;\n\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N,Q;\n    cin >> N >> Q;\n    LazyFenwickTree<AdditiveGroup<long long>>\
    \ fen(N);\n    while (Q--) {\n        int type,l,r;\n        cin >> type >> l\
    \ >> r;\n        l--;\n        if (type == 0) {\n            int x;\n        \
    \    cin >> x;\n            fen.operation(l,r,x);\n        }\n        else if\
    \ (type == 1)\n            cout << fen.product(l,r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#include \"../../Src/DataStructure/FenwickTree/LazyFenwickTree.hpp\"\n#include\
    \ \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\nusing namespace zawa;\n\n#include\
    \ <iostream>\nusing namespace std;\n\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int N,Q;\n    cin >> N >> Q;\n    LazyFenwickTree<AdditiveGroup<long\
    \ long>> fen(N);\n    while (Q--) {\n        int type,l,r;\n        cin >> type\
    \ >> l >> r;\n        l--;\n        if (type == 0) {\n            int x;\n   \
    \         cin >> x;\n            fen.operation(l,r,x);\n        }\n        else\
    \ if (type == 1)\n            cout << fen.product(l,r) << '\\n';\n    }\n}\n"
  dependsOn:
  - Src/DataStructure/FenwickTree/LazyFenwickTree.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/PowerableConcept.hpp
  - Src/Algebra/Group/CartesianProductGroup.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  isVerificationFile: true
  path: Test/AOJ/DSL_2_G.test.cpp
  requiredBy: []
  timestamp: '2026-05-04 14:21:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/DSL_2_G.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/DSL_2_G.test.cpp
- /verify/Test/AOJ/DSL_2_G.test.cpp.html
title: Test/AOJ/DSL_2_G.test.cpp
---
