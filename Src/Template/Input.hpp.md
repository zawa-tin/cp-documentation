---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/ArrayIO.hpp
    title: "std::array\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/PairIO.hpp
    title: "std::pair\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Template/VectorIO.hpp
    title: "std::vector\u306E\u5165\u51FA\u529B"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc236_e.test.cpp
    title: Test/AtCoder/abc236_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc293_b.test.cpp
    title: Test/AtCoder/abc293_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc295_a.test.cpp
    title: Test/AtCoder/abc295_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/many_aplusb.test.cpp
    title: Test/LC/many_aplusb.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Template/Input.hpp\"\n\n#line 2 \"Src/Template/ArrayIO.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Template/ArrayIO.hpp\"\
    \n\n#include <iostream>\n#include <array>\n\nnamespace zawa {\n\ntemplate <class\
    \ T, usize N>\nstd::istream &operator>>(std::istream& is, std::array<T, N>& A)\
    \ {\n    for (T& a : A) {\n        is >> a;\n    }\n    return is;\n}\n\ntemplate\
    \ <class T, usize N>\nstd::ostream &operator<<(std::ostream& os, const std::array<T,\
    \ N>& A) {\n    for (u32 i{} ; i < A.size() ; i++) {\n        os << A[i] << (i\
    \ + 1 == A.size() ? \"\" : \" \");\n    }\n    return os;\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Template/VectorIO.hpp\"\n\n#line 4 \"Src/Template/VectorIO.hpp\"\
    \n\n#line 6 \"Src/Template/VectorIO.hpp\"\n#include <vector>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nstd::istream &operator>>(std::istream& is, std::vector<T>&\
    \ A) {\n    for (T& a : A) {\n        is >> a;\n    }\n    return is;\n}\n\ntemplate\
    \ <class T>\nstd::ostream &operator<<(std::ostream& os, const std::vector<T>&\
    \ A) {\n    for (u32 i{} ; i < A.size() ; i++) {\n        os << A[i] << (i + 1\
    \ == A.size() ? \"\" : \" \");\n    }\n    return os;\n}\n\n} // namespace zawa\n\
    #line 2 \"Src/Template/PairIO.hpp\"\n\n#line 4 \"Src/Template/PairIO.hpp\"\n\n\
    #line 6 \"Src/Template/PairIO.hpp\"\n#include <utility>\n\nnamespace zawa {\n\n\
    template <class T1, class T2>\nstd::istream &operator>>(std::istream& is, std::pair<T1,\
    \ T2>& P) {\n    is >> P.first >> P.second;\n    return is;\n}\n\ntemplate <class\
    \ T1, class T2>\nstd::ostream &operator<<(std::ostream& os, const std::pair<T1,\
    \ T2>& P) {\n    os << '(' << P.first << ',' << P.second << ')';\n    return os;\n\
    }\n\n} // namespace zawa\n#line 6 \"Src/Template/Input.hpp\"\n\n#line 8 \"Src/Template/Input.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T>\nvoid input(T& value) {\n    std::cin\
    \ >> value;\n}\n\ntemplate <class Head, class... Tail>\nvoid input(Head& head,\
    \ Tail&... tail) {\n    input(head);\n    input(tail...);\n}\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include \"./ArrayIO.hpp\"\n#include \"./VectorIO.hpp\"\n\
    #include \"./PairIO.hpp\"\n\n#include <iostream>\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nvoid input(T& value) {\n    std::cin >> value;\n}\n\ntemplate <class\
    \ Head, class... Tail>\nvoid input(Head& head, Tail&... tail) {\n    input(head);\n\
    \    input(tail...);\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/ArrayIO.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Template/VectorIO.hpp
  - Src/Template/PairIO.hpp
  isVerificationFile: false
  path: Src/Template/Input.hpp
  requiredBy: []
  timestamp: '2023-08-08 12:55:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/many_aplusb.test.cpp
  - Test/AtCoder/abc295_a.test.cpp
  - Test/AtCoder/abc236_e.test.cpp
  - Test/AtCoder/abc293_b.test.cpp
documentation_of: Src/Template/Input.hpp
layout: document
title: "\u6A19\u6E96\u5165\u529B"
---

## 概要

標準入力を扱います。

## ライブラリの使い方

```cpp
void input(T& value)
```

```cpp
void input(Head& head, Tail&... tail)
```

標準入力から受け取った値を順に引数の変数に保管します。
- `std::array`、`std::vector`、`std::pair`の標準入力にも対応しています。
