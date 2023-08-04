---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/GRL_1_A.test.cpp
    title: Test/AOJ/GRL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Template/Chmin.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T1, class T2>\nbool Chmin(T1& fr, const T2& bk) {\n    return fr > bk\
    \ and (fr = bk, true);\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class T1, class T2>\nbool Chmin(T1&\
    \ fr, const T2& bk) {\n    return fr > bk and (fr = bk, true);\n}\n\n} // namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Template/Chmin.hpp
  requiredBy: []
  timestamp: '2023-08-04 19:12:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/GRL_1_A.test.cpp
documentation_of: Src/Template/Chmin.hpp
layout: document
title: Chmin
---

```cpp
template <class T1, class T2>
bool Chmin(T1& fr, const T2& bk)
```

`bk`が`fr`よりも真に小さい時、`fr`に`bk`を代入して`true`を返す。そうで無い時、`false`を返す。
