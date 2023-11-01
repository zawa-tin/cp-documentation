---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc288_e.test.cpp
    title: ABC288-E Wish List
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/MaxMonoid.hpp\"\n\n#include <limits>\n\
    #include <algorithm>\n\nnamespace zawa {\n\ntemplate <class T>\nclass MaxMonoid\
    \ {\npublic:\n    using Element = T;\n    // CHECK!!!\n    static constexpr Element\
    \ identity() noexcept {\n        return std::numeric_limits<Element>::min();\n\
    \    }\n    static constexpr Element operation(Element a, Element b) noexcept\
    \ {\n        return std::max(a, b);\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <limits>\n#include <algorithm>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass MaxMonoid {\npublic:\n    using Element = T;\n\
    \    // CHECK!!!\n    static constexpr Element identity() noexcept {\n       \
    \ return std::numeric_limits<Element>::min();\n    }\n    static constexpr Element\
    \ operation(Element a, Element b) noexcept {\n        return std::max(a, b);\n\
    \    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Monoid/MaxMonoid.hpp
  requiredBy: []
  timestamp: '2023-11-01 12:01:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc288_e.test.cpp
documentation_of: Src/Algebra/Monoid/MaxMonoid.hpp
layout: document
title: "max\u6F14\u7B97\u30E2\u30CE\u30A4\u30C9"
---

# 概要

初期値(`identity()`)に値を加算してオーバーフローしないかよく注意すること

(bundleでの自動展開に頼らず、コピペして`identity()`を毎回適したものに変更する運用が良い)
