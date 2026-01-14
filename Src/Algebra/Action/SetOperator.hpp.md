---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Heap/PartitionedProducts.hpp
    title: "\u8981\u7D20\u6607\u9806 $K$ \u500B\u3001\u964D\u9806 $N - K$ \u500B\u306E\
      \u7DCF\u7A4D\u3092\u7BA1\u7406"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc306_e.test.cpp
    title: Test/AtCoder/abc306_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc440_f.test.cpp
    title: Test/AtCoder/abc440_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc196_a.test.cpp
    title: Test/AtCoder/arc196_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Action/SetOperator.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class S, class T>\nconcept\
    \ SetOperator = requires {\n    typename S::Element;\n    { S::identity() } ->\
    \ std::same_as<typename S::Element>;\n    { S::add(std::declval<typename S::Element&>(),\
    \ std::declval<T>()) } -> std::same_as<void>;\n    { S::remove(std::declval<typename\
    \ S::Element&>(), std::declval<T>()) } -> std::same_as<void>;\n};\n\n} // namespace\
    \ concepts\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts\
    \ {\n\ntemplate <class S, class T>\nconcept SetOperator = requires {\n    typename\
    \ S::Element;\n    { S::identity() } -> std::same_as<typename S::Element>;\n \
    \   { S::add(std::declval<typename S::Element&>(), std::declval<T>()) } -> std::same_as<void>;\n\
    \    { S::remove(std::declval<typename S::Element&>(), std::declval<T>()) } ->\
    \ std::same_as<void>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Action/SetOperator.hpp
  requiredBy:
  - Src/DataStructure/Heap/PartitionedProducts.hpp
  timestamp: '2026-01-14 16:33:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/arc196_a.test.cpp
  - Test/AtCoder/abc306_e.test.cpp
  - Test/AtCoder/abc440_f.test.cpp
documentation_of: Src/Algebra/Action/SetOperator.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Action/SetOperator.hpp
- /library/Src/Algebra/Action/SetOperator.hpp.html
title: Src/Algebra/Action/SetOperator.hpp
---
