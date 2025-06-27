---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc196_e.test.cpp
    title: Test/AtCoder/abc196_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://rsm9.hatenablog.com/entry/2021/02/01/220408
  bundledCode: "#line 2 \"Src/Algebra/Monoid/ClampAddMonoid.hpp\"\n\n#include <algorithm>\n\
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
    \ plus};\n    }\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <concepts>\n#include <utility>\n\
    #include <optional>\n\nnamespace zawa {\n\ntemplate <std::totally_ordered T, T\
    \ INF>\nstruct ClampAdd {\n\n    static_assert(INF >= T{0}, \"ClampAdd<T, INF>'s\
    \ INF must be non negative\");\n\n    T low = -INF, high = INF, plus = 0;\n\n\
    \    ClampAdd() = default; \n\n    ClampAdd(T l, T h, T p) : low{l}, high{h},\
    \ plus{p} {}\n\n    static ClampAdd<T, INF> chmin(T x) {\n        return {-INF,\
    \ x, T{0}};\n    }\n\n    static ClampAdd<T, INF> chmax(T x) {\n        return\
    \ {x, INF, T{0}};\n    }\n\n    static ClampAdd<T, INF> add(T x) {\n        return\
    \ {-INF, INF, x};\n    }\n\n    T operator()(T x) const {\n        return std::clamp(x,\
    \ low, high) + plus;\n    }\n};\n\n// ref: https://rsm9.hatenablog.com/entry/2021/02/01/220408\n\
    template <std::totally_ordered T, T INF>\nstruct ClampAddMonoid {\n\n    using\
    \ Element = ClampAdd<T, INF>;\n\n    static Element identity() {\n        return\
    \ Element{};\n    }\n\n    static Element operation(const Element& L, const Element&\
    \ R) {\n        T low   = std::max(std::min(L.low + L.plus, R.high),  R.low) -\
    \ L.plus;\n        T high  = std::min(std::max(L.high + L.plus, R.low), R.high)\
    \ - L.plus;\n        T plus  = L.plus + R.plus;\n        return Element{low, high,\
    \ plus};\n    }\n\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Monoid/ClampAddMonoid.hpp
  requiredBy: []
  timestamp: '2025-06-27 19:09:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc196_e.test.cpp
documentation_of: Src/Algebra/Monoid/ClampAddMonoid.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Monoid/ClampAddMonoid.hpp
- /library/Src/Algebra/Monoid/ClampAddMonoid.hpp.html
title: Src/Algebra/Monoid/ClampAddMonoid.hpp
---
