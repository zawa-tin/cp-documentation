---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Template/Chmax.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T1, class T2>\nbool Chmax(T1& fr, const T2& bk) {\n    return fr < bk\
    \ and (fr = bk, true);\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class T1, class T2>\nbool Chmax(T1&\
    \ fr, const T2& bk) {\n    return fr < bk and (fr = bk, true);\n}\n\n} // namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Template/Chmax.hpp
  requiredBy: []
  timestamp: '2023-08-04 19:12:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Src/Template/Chmax.hpp
layout: document
title: Chmax
---

```cpp
template <class T1, class T2>
bool Chmax(T1& fr, const T2& bk)
```

`bk`が`fr`よりも真に大きい時、`fr`に`bk`を代入して`true`を返す。そうで無い時、`false`を返す。
