---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_A.test.cpp
    title: Test/AOJ/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_F.test.cpp
    title: Test/AOJ/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/staticrmq.test.cpp
    title: Test/LC/staticrmq.test.cpp
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
    \ {\npublic:\n    using Element = T;\n    // CHECK!!!\n    static constexpr Element\
    \ identity() noexcept {\n        return std::numeric_limits<Element>::max();\n\
    \    }\n    static constexpr Element operation(Element a, Element b) noexcept\
    \ {\n        return std::min(a, b);\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <limits>\n#include <algorithm>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass MinMonoid {\npublic:\n    using Element = T;\n\
    \    // CHECK!!!\n    static constexpr Element identity() noexcept {\n       \
    \ return std::numeric_limits<Element>::max();\n    }\n    static constexpr Element\
    \ operation(Element a, Element b) noexcept {\n        return std::min(a, b);\n\
    \    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Monoid/MinMonoid.hpp
  requiredBy: []
  timestamp: '2023-11-01 12:01:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/DSL_2_A.test.cpp
  - Test/AOJ/DSL_2_F.test.cpp
  - Test/Manual/agc005_b.test.cpp
  - Test/LC/staticrmq.test.cpp
documentation_of: Src/Algebra/Monoid/MinMonoid.hpp
layout: document
title: "min\u6F14\u7B97\u30E2\u30CE\u30A4\u30C9"
---

# 概要

初期値(`identity()`)に値を加算してオーバーフローしないかよく注意すること

(bundleでの自動展開に頼らず、コピペして`identity()`を毎回適したものに変更する運用が良い)
