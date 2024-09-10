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
    path: Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp
    title: "Dual Segment Tree (\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9)"
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
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
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace Concept {\n\ntemplate\
    \ <class T>\nconcept Monoid = requires {\n    typename T::Element;\n    { T::identity()\
    \ } -> std::same_as<typename T::Element>;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp\"\
    \n\n#include <vector>\n#include <iterator>\n#include <ostream>\n#include <cassert>\n\
    \nnamespace zawa {\n\ntemplate <Concept::Monoid Monoid>\nclass CommutativeDualSegmentTree\
    \ {\npublic:\n    using Operator = typename Monoid::Element;\nprotected:\n\n \
    \   static constexpr u32 parent(u32 v) noexcept {\n        return v >> 1;\n  \
    \  }\n    static constexpr u32 left(u32 v) noexcept {\n        return v << 1;\n\
    \    }\n    static constexpr u32 right(u32 v) noexcept {\n        return v <<\
    \ 1 | 1;\n    }\n\n    usize n_;\n    std::vector<Operator> dat_;\n\n    template\
    \ <class InputIterator>\n    inline void initDat(InputIterator first, InputIterator\
    \ last) {\n        for (auto it{ first } ; it != last ; it++) {\n            dat_[n_\
    \ + std::distance(first, it)] = *it;\n        }\n    }\n\n    void push(u32 i)\
    \ {\n        assert(i < n_);\n        i += n_;\n        u32 height{ 32u - __builtin_clz(i)\
    \ };\n        for (u32 h{ height } ; --h ; ) {\n            u32 v{ i >> h };\n\
    \            dat_[left(v)] = Monoid::operation(dat_[left(v)], dat_[v]);\n    \
    \        dat_[right(v)] = Monoid::operation(dat_[right(v)], dat_[v]);\n      \
    \      dat_[v] = Monoid::identity();\n        }\n    }\n\npublic:\n    CommutativeDualSegmentTree()\
    \ = default;\n    CommutativeDualSegmentTree(usize n) \n        : n_{ n }, dat_((n\
    \ << 1), Monoid::identity()) {}\n    CommutativeDualSegmentTree(const std::vector<Operator>&\
    \ dat) \n        : n_{ dat.size() }, dat_((n_ << 1), Monoid::identity()) {\n \
    \       initDat(dat.begin(), dat.end());\n    }\n    template <class InputIterator>\n\
    \    CommutativeDualSegmentTree(InputIterator first, InputIterator last)\n   \
    \     : n_{ static_cast<usize>(std::distance(first, last)) }, dat_((n_ << 1),\
    \ Monoid::identity()) {\n        initDat(first, last);\n    }\n\n    virtual void\
    \ operation(u32 l, u32 r, const Operator& v) {\n        assert(l <= r and r <=\
    \ n_);\n        for (l += n_, r += n_ ; l < r ; l = parent(l), r = parent(r))\
    \ {\n            if (l & 1) {\n                dat_[l] = Monoid::operation(dat_[l],\
    \ v);\n                l++;\n            }\n            if (r & 1) {\n       \
    \         r--;\n                dat_[r] = Monoid::operation(dat_[r], v);\n   \
    \         }\n        }\n    }\n\n    void set(u32 i, const Operator& v) {\n  \
    \      assert(i < n_);\n        push(i);\n        dat_[i + n_] = v;\n    }\n\n\
    \    virtual Operator operator[](u32 i) {\n        assert(i < n_);\n        Operator\
    \ res{ Monoid::identity() };\n        for (i += n_ ; i ; i = parent(i)) {\n  \
    \          res = Monoid::operation(res, dat_[i]);\n        }\n        return res;\n\
    \    }\n\n    friend std::ostream& operator<<(std::ostream& os, const CommutativeDualSegmentTree\
    \ seg) {\n        usize size{ seg.dat_.size() };\n        for (u32 i{1} ; i <\
    \ size ; i++) {\n            os << seg.dat_[i] << (i + 1 == size ? \"\" : \" \"\
    );\n        }\n        return os;\n    }\n};\n\n} // namespace zawa\n#line 2 \"\
    Src/Template/IOSetting.hpp\"\n\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include\
    \ <iostream>\n#include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n \
    \   std::cin.tie(nullptr)->sync_with_stdio(false);\n}\n\nvoid SetPrecision(u32\
    \ dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Algebra/Monoid/AdditionMonoid.hpp\"\n\nnamespace zawa {\n\
    \ntemplate <class T>\nstruct AdditionMonoid {\n    using Element = T;\n    static\
    \ T identity() noexcept {\n        return T{};\n    }\n    static T operation(const\
    \ T& a, const T& b) noexcept {\n        return a + b;\n    }\n};\n\n} // namespace\
    \ zawa\n#line 6 \"Test/AOJ/DSL_2_E.test.cpp\"\n\n#line 8 \"Test/AOJ/DSL_2_E.test.cpp\"\
    \n\nint main() {\n    using namespace zawa;\n    SetFastIO();\n    int n, q; std::cin\
    \ >> n >> q;\n    CommutativeDualSegmentTree<AdditionMonoid<int>> seg(n);\n  \
    \  for (int _{} ; _ < q ; _++) {\n        int com; std::cin >> com;\n        if\
    \ (com == 0) {\n            int s, t, x; std::cin >> s >> t >> x;\n          \
    \  s--;\n            seg.operation(s, t, x);\n        }\n        else if (com\
    \ == 1) {\n            int i; std::cin >> i;\n            i--;\n            std::cout\
    \ << seg[i] << '\\n';\n        }\n        else {\n            assert(false);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
    \n\n#include \"../../Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp\"\
    \n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Algebra/Monoid/AdditionMonoid.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n    using namespace zawa;\n    SetFastIO();\n\
    \    int n, q; std::cin >> n >> q;\n    CommutativeDualSegmentTree<AdditionMonoid<int>>\
    \ seg(n);\n    for (int _{} ; _ < q ; _++) {\n        int com; std::cin >> com;\n\
    \        if (com == 0) {\n            int s, t, x; std::cin >> s >> t >> x;\n\
    \            s--;\n            seg.operation(s, t, x);\n        }\n        else\
    \ if (com == 1) {\n            int i; std::cin >> i;\n            i--;\n     \
    \       std::cout << seg[i] << '\\n';\n        }\n        else {\n           \
    \ assert(false);\n        }\n    }\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Template/IOSetting.hpp
  - Src/Algebra/Monoid/AdditionMonoid.hpp
  isVerificationFile: true
  path: Test/AOJ/DSL_2_E.test.cpp
  requiredBy: []
  timestamp: '2024-09-10 19:45:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/DSL_2_E.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/DSL_2_E.test.cpp
- /verify/Test/AOJ/DSL_2_E.test.cpp.html
title: Test/AOJ/DSL_2_E.test.cpp
---
