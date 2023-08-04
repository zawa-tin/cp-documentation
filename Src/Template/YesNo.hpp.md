---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc295_a.test.cpp
    title: Test/AtCoder/abc295_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Template/YesNo.hpp\"\n\n#include <string>\n\nnamespace\
    \ zawa {\n\nnamespace internal {\n\nstd::string yes{\"Yes\"};\nstd::string no{\"\
    No\"};\n\n} // namespace internal\n\nvoid YesNo(bool answer) {\n    std::cout\
    \ << (answer ? internal::yes : internal::no) << std::endl;\n}\n\nvoid SetYes(const\
    \ std::string& yes) {\n    internal::yes = yes;\n}\n\nvoid SetNo(const std::string&\
    \ no) {\n    internal::no = no;\n}\n\nvoid SetAtCoderYesNo() {\n    SetYes(\"\
    Yes\");\n    SetNo(\"No\");\n}\n\nvoid SetCodeforcesYesNo() {\n    SetYes(\"YES\"\
    );\n    SetNo(\"NO\");\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <string>\n\nnamespace zawa {\n\nnamespace internal\
    \ {\n\nstd::string yes{\"Yes\"};\nstd::string no{\"No\"};\n\n} // namespace internal\n\
    \nvoid YesNo(bool answer) {\n    std::cout << (answer ? internal::yes : internal::no)\
    \ << std::endl;\n}\n\nvoid SetYes(const std::string& yes) {\n    internal::yes\
    \ = yes;\n}\n\nvoid SetNo(const std::string& no) {\n    internal::no = no;\n}\n\
    \nvoid SetAtCoderYesNo() {\n    SetYes(\"Yes\");\n    SetNo(\"No\");\n}\n\nvoid\
    \ SetCodeforcesYesNo() {\n    SetYes(\"YES\");\n    SetNo(\"NO\");\n}\n\n} //\
    \ namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Template/YesNo.hpp
  requiredBy: []
  timestamp: '2023-08-05 06:28:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc295_a.test.cpp
documentation_of: Src/Template/YesNo.hpp
layout: document
title: "Yes\u304BNo\u3092\u51FA\u529B\u3059\u308B"
---

## 概要

真理値を受け取り、その真偽によって予め設定した文字列を出力します。


## ライブラリの使い方

#### YesNo

```cpp
void YesNo(bool answer)
```

`answer`が`true`なら`yes`に設定された文字列を、`false`なら`no`に設定された文字列を出力します。

<br />

#### SetYes

```cpp
void SetYes(const std::string& yes)
```

`yes`の文字列を設定します。

<br />

#### SetNo

```cpp
void SetNo(const std::string& no)
```

`no`の文字列を設定します。

<br />

#### SetAtCoderYesNo

```cpp
void SetAtCoderYesNo()
```

`yes`を`Yes`に、`no`を`No`に設定します。

<br />

#### SetCodeforcesYesNo

```cpp
void SetCodeforcesYesNo()
```

`yes`を`YES`に、`no`を`NO`に設定します。
