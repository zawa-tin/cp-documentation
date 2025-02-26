---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Number/EnumerateQuotients.hpp
    title: "\u5546\u5217\u6319"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2957.test.cpp
    title: AOJ2957 MOD Rush
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc132_f.test.cpp
    title: ABC132-F Small Products
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc191_d.test.cpp
    title: Test/AtCoder/abc191_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc230_e.test.cpp
    title: Test/AtCoder/abc230_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/enumerate_quotients.test.cpp
    title: Test/LC/enumerate_quotients.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/My/Number/EnumerateQuotients/ceilBuild.test.cpp
    title: Test/My/Number/EnumerateQuotients/ceilBuild.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Number/IntegerDivision.hpp\"\n\n#include <type_traits>\n\
    #include <cassert>\n\nnamespace zawa {\n\ntemplate <class T>\nconstexpr T DivFloor(T\
    \ a, T b) {\n    static_assert(std::is_integral_v<T>, \"DivFloor argument must\
    \ be Integer\");\n    assert(b != T{});\n    if constexpr (std::is_unsigned_v<T>)\
    \ {\n        return a / b;\n    }\n    else {\n        if (b < 0) {\n        \
    \    a *= -1;\n            b *= -1;\n        }\n        return (a >= 0 ? a / b\
    \ : (a - b + 1) / b);\n    }\n}\n\ntemplate <class T>\nconstexpr T DivCeil(T a,\
    \ T b) {\n    static_assert(std::is_integral_v<T>, \"DivCeil argument must be\
    \ Integer\");\n    assert(b != T{});\n    if constexpr (std::is_unsigned_v<T>)\
    \ {\n        return (a + b - 1) / b;\n    }\n    else {\n        if (b < 0) {\n\
    \            a *= -1;\n            b *= -1;\n        }\n        return (a >= 0\
    \ ? (a + b - 1) / b : a / b);\n    }\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <type_traits>\n#include <cassert>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nconstexpr T DivFloor(T a, T b) {\n    static_assert(std::is_integral_v<T>,\
    \ \"DivFloor argument must be Integer\");\n    assert(b != T{});\n    if constexpr\
    \ (std::is_unsigned_v<T>) {\n        return a / b;\n    }\n    else {\n      \
    \  if (b < 0) {\n            a *= -1;\n            b *= -1;\n        }\n     \
    \   return (a >= 0 ? a / b : (a - b + 1) / b);\n    }\n}\n\ntemplate <class T>\n\
    constexpr T DivCeil(T a, T b) {\n    static_assert(std::is_integral_v<T>, \"DivCeil\
    \ argument must be Integer\");\n    assert(b != T{});\n    if constexpr (std::is_unsigned_v<T>)\
    \ {\n        return (a + b - 1) / b;\n    }\n    else {\n        if (b < 0) {\n\
    \            a *= -1;\n            b *= -1;\n        }\n        return (a >= 0\
    \ ? (a + b - 1) / b : a / b);\n    }\n}\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Number/IntegerDivision.hpp
  requiredBy:
  - Src/Number/EnumerateQuotients.hpp
  timestamp: '2023-08-11 15:55:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/My/Number/EnumerateQuotients/ceilBuild.test.cpp
  - Test/AOJ/2957.test.cpp
  - Test/LC/enumerate_quotients.test.cpp
  - Test/AtCoder/abc230_e.test.cpp
  - Test/AtCoder/abc132_f.test.cpp
  - Test/AtCoder/abc191_d.test.cpp
documentation_of: Src/Number/IntegerDivision.hpp
layout: document
title: "\u6574\u6570\u540C\u58EB\u306E\u5207\u308A\u6368\u3066/\u5207\u308A\u4E0A\u3052\
  \u9664\u7B97"
---

## 概要

整数同士の除算を行い、その結果に床関数や天井関数を適用したものを返す。

## ライブラリの使い方

#### DivFloor

```cpp
template <class T>
constexpr T DivFloor(T a, T b) 
```

$\lfloor \frac{a}{b} \rfloor$ を計算する。

**制約**

- `T`は整数型であること
- $b \ne 0$

<br />

#### DivCeil

```cpp
template <class T>
constexpr T DivCeil(T a, T b)
```

$\lceil \frac{a}{b} \rceil$ を計算する。

**制約**

- `T`は整数型であること
- $b \ne 0$
