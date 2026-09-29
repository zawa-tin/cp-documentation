---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc191_d.test.cpp
    title: Test/AtCoder/abc191_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc236_e.test.cpp
    title: Test/AtCoder/abc236_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "Src/Template/FloatingNumberAlias.hpp"


    namespace zawa {


    using ld = long double;


    } // namespace zawa

    '
  code: '#pragma once


    namespace zawa {


    using ld = long double;


    } // namespace zawa

    '
  dependsOn: []
  isVerificationFile: false
  path: Src/Template/FloatingNumberAlias.hpp
  requiredBy: []
  timestamp: '2023-08-11 13:12:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc191_d.test.cpp
  - Test/AtCoder/abc236_e.test.cpp
documentation_of: Src/Template/FloatingNumberAlias.hpp
layout: document
title: "\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
---

## 概要

浮動小数点型の型名のエイリアスを提供します。


## ライブラリの使い方

#### ld

```cpp
using ld = long double;
```

`long double`型は`zawa::`下では`ld`という名前で使用可能です。
