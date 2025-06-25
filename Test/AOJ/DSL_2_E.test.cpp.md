---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/AdditionMonoid.hpp
    title: Src/Algebra/Monoid/AdditionMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp
    title: "Dual Segment Tree (\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9)"
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
    \n\n#line 2 \"Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp\"\n\
    \n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
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
    \n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp\"\
    \n\n#include <bit>\n#include <cassert>\n#include <vector>\n#include <iterator>\n\
    #include <ostream>\n\nnamespace zawa {\n\ntemplate <concepts::Monoid Monoid>\n\
    class CommutativeDualSegmentTree {\npublic:\n\n    using OM = Monoid;\n\n    using\
    \ O = typename OM::Element;\n\n    using VM = Monoid;\n\n    using V = typename\
    \ VM::Element;\n\n    CommutativeDualSegmentTree() = default;\n\n    explicit\
    \ CommutativeDualSegmentTree(usize n) \n        : m_n{ n }, m_dat((n << 1), VM::identity())\
    \ {}\n\n    explicit CommutativeDualSegmentTree(const std::vector<O>& dat) \n\
    \        : m_n{ dat.size() }, m_dat((m_n << 1), VM::identity()) {\n        initDat(dat.begin(),\
    \ dat.end());\n    }\n\n    template <class InputIterator>\n    CommutativeDualSegmentTree(InputIterator\
    \ first, InputIterator last)\n        : m_n{ static_cast<usize>(std::distance(first,\
    \ last)) }, m_dat((m_n << 1), OM::identity()) {\n        initDat(first, last);\n\
    \    }\n\n    [[nodiscard]] inline usize size() const noexcept {\n        return\
    \ m_n;\n    }\n\n    virtual void operation(usize l, usize r, const O& v) {\n\
    \        assert(l <= r and r <= size());\n        for (l += size(), r += size()\
    \ ; l < r ; l = parent(l), r = parent(r)) {\n            if (l & 1) {\n      \
    \          m_dat[l] = OM::operation(m_dat[l], v);\n                l++;\n    \
    \        }\n            if (r & 1) {\n                r--;\n                m_dat[r]\
    \ = OM::operation(m_dat[r], v);\n            }\n        }\n    }\n\n    // \u672A\
    verify\n    virtual void operation(usize i, const O& o) {\n        assert(i <\
    \ size());\n        m_dat[i + size()] = OM::operation(m_dat[i + size()], o);\n\
    \    }\n\n    void assign(usize i, const V& v) {\n        assert(i < size());\n\
    \        push(i);\n        m_dat[i + size()] = v;\n    }\n\n    [[nodiscard]]\
    \ virtual V operator[](usize i) {\n        assert(i < size());\n        V res{\
    \ VM::identity() };\n        for (i += size() ; i ; i = parent(i)) {\n       \
    \     res = VM::operation(res, m_dat[i]);\n        }\n        return res;\n  \
    \  }\n\n    friend std::ostream& operator<<(std::ostream& os, const CommutativeDualSegmentTree\
    \ seg) {\n        usize size{ seg.m_dat.size() };\n        for (usize i{1} ; i\
    \ < size ; i++) {\n            os << seg.m_dat[i] << (i + 1 == size ? \"\" : \"\
    \ \");\n        }\n        return os;\n    }\n\nprotected:\n\n    static constexpr\
    \ usize parent(usize v) noexcept {\n        return v >> 1;\n    }\n\n    static\
    \ constexpr usize left(usize v) noexcept {\n        return v << 1;\n    }\n\n\
    \    static constexpr usize right(usize v) noexcept {\n        return v << 1 |\
    \ 1;\n    }\n\n    usize m_n;\n\n    std::vector<V> m_dat;\n\n    template <class\
    \ InputIterator>\n    inline void initDat(InputIterator first, InputIterator last)\
    \ {\n        for (auto it{ first } ; it != last ; it++) {\n            m_dat[size()\
    \ + std::distance(first, it)] = *it;\n        }\n    }\n\n    void push(usize\
    \ i) {\n        assert(i < size());\n        i += size();\n        usize height{\
    \ 64u - std::countl_zero(i) };\n        for (usize h{ height } ; --h ; ) {\n \
    \           usize v{ i >> h };\n            m_dat[left(v)] = OM::operation(m_dat[left(v)],\
    \ m_dat[v]);\n            m_dat[right(v)] = OM::operation(m_dat[right(v)], m_dat[v]);\n\
    \            m_dat[v] = OM::identity();\n        }\n    }\n\n};\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Algebra/Monoid/AdditionMonoid.hpp\"\n\nnamespace zawa {\n\
    \ntemplate <class T>\nstruct AdditionMonoid {\n    using Element = T;\n    static\
    \ T identity() noexcept {\n        return T{};\n    }\n    static T operation(const\
    \ T& a, const T& b) noexcept {\n        return a + b;\n    }\n};\n\n} // namespace\
    \ zawa\n#line 5 \"Test/AOJ/DSL_2_E.test.cpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    using namespace zawa;\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, q; std::cin >> n >> q;\n  \
    \  CommutativeDualSegmentTree<AdditionMonoid<int>> seg(n);\n    for (int _{} ;\
    \ _ < q ; _++) {\n        int com; std::cin >> com;\n        if (com == 0) {\n\
    \            int s, t, x; std::cin >> s >> t >> x;\n            s--;\n       \
    \     seg.operation(s, t, x);\n        }\n        else if (com == 1) {\n     \
    \       int i; std::cin >> i;\n            i--;\n            std::cout << seg[i]\
    \ << '\\n';\n        }\n        else {\n            assert(false);\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
    \n\n#include \"../../Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp\"\
    \n#include \"../../Src/Algebra/Monoid/AdditionMonoid.hpp\"\n\n#include <iostream>\n\
    \nint main() {\n    using namespace zawa;\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, q; std::cin >> n >> q;\n  \
    \  CommutativeDualSegmentTree<AdditionMonoid<int>> seg(n);\n    for (int _{} ;\
    \ _ < q ; _++) {\n        int com; std::cin >> com;\n        if (com == 0) {\n\
    \            int s, t, x; std::cin >> s >> t >> x;\n            s--;\n       \
    \     seg.operation(s, t, x);\n        }\n        else if (com == 1) {\n     \
    \       int i; std::cin >> i;\n            i--;\n            std::cout << seg[i]\
    \ << '\\n';\n        }\n        else {\n            assert(false);\n        }\n\
    \    }\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Monoid/AdditionMonoid.hpp
  isVerificationFile: true
  path: Test/AOJ/DSL_2_E.test.cpp
  requiredBy: []
  timestamp: '2025-06-24 16:23:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/DSL_2_E.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/DSL_2_E.test.cpp
- /verify/Test/AOJ/DSL_2_E.test.cpp.html
title: Test/AOJ/DSL_2_E.test.cpp
---
