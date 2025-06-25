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
    path: Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp
    title: "Dual Segment Tree (\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9)"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/DualSegmentTree.hpp
    title: "Dual Segment Tree (\u975E\u53EF\u63DB\u5BFE\u5FDC)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
  bundledCode: "#line 1 \"Test/AOJ/DSL_2_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n\n#line 2 \"Src/DataStructure/SegmentTree/DualSegmentTree.hpp\"\n\n#line 2 \"\
    Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line\
    \ 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\n\
    namespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
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
    \ zawa\n#line 4 \"Src/DataStructure/SegmentTree/DualSegmentTree.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <concepts::Monoid Monoid>\nclass DualSegmentTree : public\
    \ CommutativeDualSegmentTree<Monoid> {\nprivate:\n\n    using Base = CommutativeDualSegmentTree<Monoid>;\n\
    \    \npublic:\n\n    using OM = Monoid;\n\n    using O = typename OM::Element;\n\
    \n    using VM = Monoid;\n\n    using V = typename VM::Element;\n\n    DualSegmentTree()\
    \ : Base() {}\n\n    explicit DualSegmentTree(usize n) : Base{n} {}\n\n    explicit\
    \ DualSegmentTree(const std::vector<O>& dat) : Base{dat} {}\n\n    template <class\
    \ InputIterator>\n    DualSegmentTree(InputIterator first, InputIterator last)\
    \ : Base(first, last) {}\n    \n    void operation(usize l, usize r, const O&\
    \ o) override {\n        Base::push(l);\n        if (l < r) Base::push(r - 1);\n\
    \        Base::operation(l, r, o);\n    } \n\n    void operation(usize i, const\
    \ O& o) override {\n        Base::push(i);\n        Base::operation(i, o);\n \
    \   }\n\n    V operator[](usize i) override {\n        Base::push(i);\n      \
    \  return Base::operator[](i);\n    }\n};\n\n} // namespace zawa\n#line 4 \"Test/AOJ/DSL_2_D.test.cpp\"\
    \n\n#line 6 \"Test/AOJ/DSL_2_D.test.cpp\"\n#include <iostream>\n#line 8 \"Test/AOJ/DSL_2_D.test.cpp\"\
    \n\nusing namespace zawa;\n\nstruct M {\n    using Element = int;\n    static\
    \ int identity() {\n        return -1;\n    }\n    static int operation(int a,\
    \ int b) {\n        return (b == identity() ? a : b);\n    }\n};\n\nint main()\
    \ {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, q; std::cin >> n >> q;\n    DualSegmentTree<M> seg(std::vector<int>(n,\
    \ (1LL << 31) - 1));\n    while (q--) {\n        int t; std::cin >> t;\n     \
    \   if (t == 0) {\n            int l, r, x; std::cin >> l >> r >> x;\n       \
    \     seg.operation(l, r + 1, x);\n        }\n        else if (t == 1) {\n   \
    \         int i; std::cin >> i;\n            std::cout << seg[i] << '\\n';\n \
    \       }\n        else {\n            assert(false);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n\n#include \"../../Src/DataStructure/SegmentTree/DualSegmentTree.hpp\"\n\n#include\
    \ <cassert>\n#include <iostream>\n#include <vector>\n\nusing namespace zawa;\n\
    \nstruct M {\n    using Element = int;\n    static int identity() {\n        return\
    \ -1;\n    }\n    static int operation(int a, int b) {\n        return (b == identity()\
    \ ? a : b);\n    }\n};\n\nint main() {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, q; std::cin >> n >> q;\n  \
    \  DualSegmentTree<M> seg(std::vector<int>(n, (1LL << 31) - 1));\n    while (q--)\
    \ {\n        int t; std::cin >> t;\n        if (t == 0) {\n            int l,\
    \ r, x; std::cin >> l >> r >> x;\n            seg.operation(l, r + 1, x);\n  \
    \      }\n        else if (t == 1) {\n            int i; std::cin >> i;\n    \
    \        std::cout << seg[i] << '\\n';\n        }\n        else {\n          \
    \  assert(false);\n        }\n    }\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/DualSegmentTree.hpp
  - Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/AOJ/DSL_2_D.test.cpp
  requiredBy: []
  timestamp: '2025-06-24 16:23:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/DSL_2_D.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/DSL_2_D.test.cpp
- /verify/Test/AOJ/DSL_2_D.test.cpp.html
title: Test/AOJ/DSL_2_D.test.cpp
---
