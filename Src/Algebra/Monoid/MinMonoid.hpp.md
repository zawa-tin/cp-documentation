---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_A.test.cpp
    title: Test/AOJ/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/agc005_b.test.cpp
    title: Test/Manual/agc005_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/MinMonoid.hpp\"\n\n#include <limits>\n\
    #include <algorithm>\n\nnamespace zawa {\n\ntemplate <class T>\nclass MinMonoid\
    \ {\npublic:\n    using Element = T;\n    static constexpr T identity() noexcept\
    \ {\n        return std::numeric_limits<T>::max();\n    }\n    static constexpr\
    \ T operation(T a, T b) noexcept {\n        return std::min(a, b);\n    }\n};\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include <limits>\n#include <algorithm>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass MinMonoid {\npublic:\n    using Element = T;\n\
    \    static constexpr T identity() noexcept {\n        return std::numeric_limits<T>::max();\n\
    \    }\n    static constexpr T operation(T a, T b) noexcept {\n        return\
    \ std::min(a, b);\n    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Monoid/MinMonoid.hpp
  requiredBy: []
  timestamp: '2023-09-26 08:39:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/DSL_2_A.test.cpp
  - Test/Manual/agc005_b.test.cpp
documentation_of: Src/Algebra/Monoid/MinMonoid.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Monoid/MinMonoid.hpp
- /library/Src/Algebra/Monoid/MinMonoid.hpp.html
title: Src/Algebra/Monoid/MinMonoid.hpp
---
