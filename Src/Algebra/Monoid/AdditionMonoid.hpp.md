---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_E.test.cpp
    title: Test/AOJ/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc292_h.test.cpp
    title: Test/AtCoder/abc292_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_affine_range_sum.test.cpp
    title: Test/LC/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/AdditionMonoid.hpp\"\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nstruct AdditionMonoid {\n    using Element = T;\n \
    \   static T identity() noexcept {\n        return T{};\n    }\n    static T operation(const\
    \ T& a, const T& b) noexcept {\n        return a + b;\n    }\n};\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class T>\nstruct AdditionMonoid\
    \ {\n    using Element = T;\n    static T identity() noexcept {\n        return\
    \ T{};\n    }\n    static T operation(const T& a, const T& b) noexcept {\n   \
    \     return a + b;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Monoid/AdditionMonoid.hpp
  requiredBy: []
  timestamp: '2023-10-01 23:08:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc292_h.test.cpp
  - Test/LC/range_affine_range_sum.test.cpp
  - Test/AOJ/DSL_2_E.test.cpp
documentation_of: Src/Algebra/Monoid/AdditionMonoid.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Monoid/AdditionMonoid.hpp
- /library/Src/Algebra/Monoid/AdditionMonoid.hpp.html
title: Src/Algebra/Monoid/AdditionMonoid.hpp
---
