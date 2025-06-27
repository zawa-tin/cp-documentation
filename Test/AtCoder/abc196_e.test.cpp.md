---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/ClampAddMonoid.hpp
    title: Src/Algebra/Monoid/ClampAddMonoid.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc196/submissions/67097963
    - https://atcoder.jp/contests/abc196/tasks/abc196_e
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc196_e.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc196/tasks/abc196_e\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 196 E - Filters\n * https://atcoder.jp/contests/abc196/submissions/67097963\n\
    \ */\n\n#line 2 \"Src/Algebra/Monoid/ClampAddMonoid.hpp\"\n\n#include <algorithm>\n\
    #include <concepts>\n#include <utility>\n#include <optional>\n\nnamespace zawa\
    \ {\n\ntemplate <std::totally_ordered T, T INF>\nstruct ClampAdd {\n\n    static_assert(INF\
    \ >= T{0}, \"ClampAdd<T, INF>'s INF must be non negative\");\n\n    T low = -INF,\
    \ high = INF, plus = 0;\n\n    ClampAdd() = default; \n\n    ClampAdd(T l, T h,\
    \ T p) : low{l}, high{h}, plus{p} {}\n\n    static ClampAdd<T, INF> chmin(T x)\
    \ {\n        return {-INF, x, T{0}};\n    }\n\n    static ClampAdd<T, INF> chmax(T\
    \ x) {\n        return {x, INF, T{0}};\n    }\n\n    static ClampAdd<T, INF> add(T\
    \ x) {\n        return {-INF, INF, x};\n    }\n\n    T operator()(T x) const {\n\
    \        return std::clamp(x, low, high) + plus;\n    }\n};\n\n// ref: https://rsm9.hatenablog.com/entry/2021/02/01/220408\n\
    template <std::totally_ordered T, T INF>\nstruct ClampAddMonoid {\n\n    using\
    \ Element = ClampAdd<T, INF>;\n\n    static Element identity() {\n        return\
    \ Element{};\n    }\n\n    static Element operation(const Element& L, const Element&\
    \ R) {\n        T low   = std::max(std::min(L.low + L.plus, R.high),  R.low) -\
    \ L.plus;\n        T high  = std::min(std::max(L.high + L.plus, R.low), R.high)\
    \ - L.plus;\n        T plus  = L.plus + R.plus;\n        return Element{low, high,\
    \ plus};\n    }\n\n};\n\n} // namespace zawa\n#line 10 \"Test/AtCoder/abc196_e.test.cpp\"\
    \nusing namespace zawa;\n\n#include <cassert>\n#include <iostream>\n\nint main()\
    \ {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int N;\n    std::cin >> N;\n    using\
    \ M = ClampAddMonoid<long long, (long long)1e18>;\n    using D = typename M::Element;\n\
    \    D f = M::identity();\n    while (N--) {\n        int a, t;\n        std::cin\
    \ >> a >> t;\n        if (t == 1) f = M::operation(f, D::add(a));\n        else\
    \ if (t == 2) f = M::operation(f, D::chmax(a));\n        else if (t == 3) f =\
    \ M::operation(f, D::chmin(a));\n        else assert(false);\n    }\n    int Q;\n\
    \    std::cin >> Q;\n    while (Q--) {\n        int x;\n        std::cin >> x;\n\
    \        std::cout << f(x) << '\\n';\n    }\n#else\n    std::cout << \"Hello World\\\
    n\";\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc196/tasks/abc196_e\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 196 E - Filters\n * https://atcoder.jp/contests/abc196/submissions/67097963\n\
    \ */\n\n#include \"../../Src/Algebra/Monoid/ClampAddMonoid.hpp\"\nusing namespace\
    \ zawa;\n\n#include <cassert>\n#include <iostream>\n\nint main() {\n#ifdef ATCODER\n\
    \    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int N;\n    std::cin >> N;\n    using M = ClampAddMonoid<long long, (long\
    \ long)1e18>;\n    using D = typename M::Element;\n    D f = M::identity();\n\
    \    while (N--) {\n        int a, t;\n        std::cin >> a >> t;\n        if\
    \ (t == 1) f = M::operation(f, D::add(a));\n        else if (t == 2) f = M::operation(f,\
    \ D::chmax(a));\n        else if (t == 3) f = M::operation(f, D::chmin(a));\n\
    \        else assert(false);\n    }\n    int Q;\n    std::cin >> Q;\n    while\
    \ (Q--) {\n        int x;\n        std::cin >> x;\n        std::cout << f(x) <<\
    \ '\\n';\n    }\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Algebra/Monoid/ClampAddMonoid.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc196_e.test.cpp
  requiredBy: []
  timestamp: '2025-06-27 19:09:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc196_e.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc196_e.test.cpp
- /verify/Test/AtCoder/abc196_e.test.cpp.html
title: Test/AtCoder/abc196_e.test.cpp
---
